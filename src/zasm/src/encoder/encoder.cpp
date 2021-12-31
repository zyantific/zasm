#include "zasm/encoder/encoder.hpp"

#include "encoder.context.hpp"

#include <Zydis/Decoder.h>
#include <Zydis/Encoder.h>
#include <limits>
#include <optional>

namespace zasm
{
    struct EncoderState
    {
        EncoderContext* ctx{};
        ZydisEncoderRequest req{};
        size_t operandIndex{};
        size_t relocatableOperand{};
    };

    static constexpr int32_t kTemporaryRel32Value = 0x123456;

    static EncoderContext::LabelLink& getOrCreateLabelLink(EncoderContext* ctx, Label::Id id)
    {
        const auto labelIdx = static_cast<size_t>(id);
        if (labelIdx >= ctx->labelLinks.size())
        {
            ctx->labelLinks.resize(labelIdx + 1);

            auto& entry = ctx->labelLinks[labelIdx];
            entry.id = id;

            return entry;
        }
        return ctx->labelLinks[labelIdx];
    }

    static std::optional<int64_t> getLabelAddress(EncoderContext* ctx, Label::Id id)
    {
        if (ctx == nullptr)
            return std::nullopt;

        const auto& entry = getOrCreateLabelLink(ctx, id);
        if (entry.boundVA == -1)
        {
            return std::nullopt;
        }

        return entry.boundVA;
    }

    struct EncodeVariantsInfo
    {
        bool isControlFlow{};
        int8_t encodeSizeRel8{ -1 };
        int8_t encodeSizeRel32{ -1 };

        bool canEncodeRel8() const noexcept
        {
            return encodeSizeRel8 != -1;
        }

        bool canEncodeRel32() const noexcept
        {
            return encodeSizeRel32 != -1;
        }
    };

    static EncodeVariantsInfo getEncodeVariantInfo(ZydisMnemonic mnemonic)
    {
        switch (mnemonic)
        {
            case ZYDIS_MNEMONIC_JMP:
                return EncodeVariantsInfo{ true, 2, 5 };
            case ZYDIS_MNEMONIC_JB:
            case ZYDIS_MNEMONIC_JBE:
            case ZYDIS_MNEMONIC_JCXZ:
            case ZYDIS_MNEMONIC_JECXZ:
            case ZYDIS_MNEMONIC_JKNZD:
            case ZYDIS_MNEMONIC_JKZD:
            case ZYDIS_MNEMONIC_JL:
            case ZYDIS_MNEMONIC_JLE:
            case ZYDIS_MNEMONIC_JNB:
            case ZYDIS_MNEMONIC_JNBE:
            case ZYDIS_MNEMONIC_JNL:
            case ZYDIS_MNEMONIC_JNLE:
            case ZYDIS_MNEMONIC_JNO:
            case ZYDIS_MNEMONIC_JNP:
            case ZYDIS_MNEMONIC_JNS:
            case ZYDIS_MNEMONIC_JNZ:
            case ZYDIS_MNEMONIC_JO:
            case ZYDIS_MNEMONIC_JP:
            case ZYDIS_MNEMONIC_JRCXZ:
            case ZYDIS_MNEMONIC_JS:
            case ZYDIS_MNEMONIC_JZ:
                return EncodeVariantsInfo{ true, 2, 6 };
            case ZYDIS_MNEMONIC_LOOP:
            case ZYDIS_MNEMONIC_LOOPE:
            case ZYDIS_MNEMONIC_LOOPNE:
                return EncodeVariantsInfo{ true, 2, -1 };
            case ZYDIS_MNEMONIC_CALL:
                return EncodeVariantsInfo{ true, -1, 5 };
        }
        return EncodeVariantsInfo{ false, -1, -1 };
    }

    static int64_t getRelativeAddress(int64_t va, int64_t target, int32_t instrSize) noexcept
    {
        return target - (va + instrSize);
    }

    static bool hasAttrib(Instruction::Attribs attribs, Instruction::Attribs other) noexcept
    {
        return (attribs & other) != Instruction::Attribs::None;
    }

    static ZydisInstructionAttributes getAttribs(Instruction::Attribs attribs) noexcept
    {
        ZydisInstructionAttributes res{};

        const auto translateAttrib = [&](Instruction::Attribs other, ZydisInstructionAttributes newAttrib) {
            if (hasAttrib(attribs, other))
            {
                res |= newAttrib;
            }
        };

        translateAttrib(Instruction::Attribs::Lock, ZYDIS_ATTRIB_HAS_LOCK);
        translateAttrib(Instruction::Attribs::Rep, ZYDIS_ATTRIB_HAS_REP);
        translateAttrib(Instruction::Attribs::Repe, ZYDIS_ATTRIB_HAS_REPE);
        translateAttrib(Instruction::Attribs::Repne, ZYDIS_ATTRIB_HAS_REPNE);
        translateAttrib(Instruction::Attribs::Bnd, ZYDIS_ATTRIB_HAS_BND);
        translateAttrib(Instruction::Attribs::Xacquire, ZYDIS_ATTRIB_HAS_XACQUIRE);
        translateAttrib(Instruction::Attribs::Xrelease, ZYDIS_ATTRIB_HAS_XRELEASE);

        return res;
    }

    static std::pair<int64_t, ZydisBranchType> processRelAddress(
        const EncodeVariantsInfo& info, int64_t va, int64_t targetAddress)
    {
        int64_t res{};
        auto desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE;

        if (info.canEncodeRel8())
        {
            auto rel = getRelativeAddress(va, targetAddress, info.encodeSizeRel8);
            if (std::abs(rel) <= std::numeric_limits<int8_t>::max())
            {
                res = rel;
                desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_SHORT;
            }
        }

        if (desiredBranchType == ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE && info.canEncodeRel32())
        {
            auto rel = getRelativeAddress(va, targetAddress, info.encodeSizeRel32);
            if (std::abs(rel) <= std::numeric_limits<int32_t>::max())
            {
                res = rel;
                desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NEAR;
            }
        }

        assert(desiredBranchType != ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE);

        return { res, desiredBranchType };
    }

    static Error buildOperand(ZydisEncoderOperand& dst, EncoderState&, const operands::Reg& op) noexcept
    {
        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER;
        dst.reg.value = op.getId();

        return Error::None;
    }

    static Error buildOperand(ZydisEncoderOperand& dst, EncoderState& state, const operands::Label& op) noexcept
    {
        auto* ctx = state.ctx;
        auto desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE;

        // Initially a temporary placeholder. Make sure this is within rel32 if a
        // context is provided.
        int64_t immValue = ctx != nullptr ? ctx->va + kTemporaryRel32Value : kTemporaryRel32Value;

        auto labelVA = getLabelAddress(ctx, op.getId());

        // Check if this operand is used as the control flow target.
        const auto encodeInfo = getEncodeVariantInfo(state.req.mnemonic);
        if (state.operandIndex == 0 && encodeInfo.isControlFlow)
        {
            auto targetAddress = labelVA.has_value() ? *labelVA : immValue;

            auto [addrRel, branchType] = processRelAddress(encodeInfo, ctx ? ctx->va : 0, targetAddress);

            immValue = addrRel;
            desiredBranchType = branchType;

            assert(desiredBranchType != ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE);
        }
        else
        {
            if (labelVA.has_value())
            {
                immValue = *labelVA;
            }
        }

        if (desiredBranchType != ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE)
        {
            state.req.branch_type = desiredBranchType;
        }

        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_IMMEDIATE;
        dst.imm.s = immValue;

        return Error::None;
    }

    static Error buildOperand(ZydisEncoderOperand& dst, EncoderState& state, const operands::Imm& op) noexcept
    {
        auto* ctx = state.ctx;

        auto desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE;
        int64_t immValue = op.value<int64_t>();

        // Check if this operand is used as the control flow target.
        const auto encodeInfo = getEncodeVariantInfo(state.req.mnemonic);
        if (state.operandIndex == 0 && encodeInfo.isControlFlow)
        {
            const auto targetAddress = immValue;
            auto [addrRel, branchType] = processRelAddress(encodeInfo, ctx ? ctx->va : 0, targetAddress);

            immValue = addrRel;
            desiredBranchType = branchType;
        }

        if (desiredBranchType != ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE)
        {
            state.req.branch_type = desiredBranchType;
        }

        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_IMMEDIATE;
        dst.imm.s = immValue;

        return Error::None;
    }

    static Error buildOperand(ZydisEncoderOperand& dst, EncoderState& state, const operands::Mem& op) noexcept
    {
        auto* ctx = state.ctx;

        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_MEMORY;
        dst.mem.base = op.getBase().getId();
        dst.mem.index = op.getIndex().getId();
        dst.mem.scale = op.getScale();
        dst.mem.size = static_cast<uint16_t>(op.getByteSize());

        int64_t displacement = op.getDisplacement();

        const auto instrSize = ctx ? ctx->instrSize : 0;
        const auto va = ctx ? ctx->va : 0;

        // We require the exact instruction size to encode this correctly.
        if (ctx && instrSize == 0)
        {
            // Causes to re-encode again with instruction size available.
            ctx->instrSize = -1;
        }

        bool usingLabel = false;
        if (auto labelId = op.getLabelId(); labelId != Label::Id::Invalid && ctx != nullptr)
        {
            auto labelVA = getLabelAddress(ctx, labelId);
            if (labelVA.has_value())
            {
                displacement += *labelVA;
            }
            else
            {
                displacement += kTemporaryRel32Value;
            }
            usingLabel = true;
        }

        // For 64 bit we default to rip rel.
        if (state.req.machine_mode == ZYDIS_MACHINE_MODE_LONG_64)
        {
            if (dst.mem.base == ZYDIS_REGISTER_NONE && dst.mem.index == ZYDIS_REGISTER_NONE && usingLabel)
            {
                // Turn into rip-rel.
                dst.mem.base = ZYDIS_REGISTER_RIP;
            }
        }

        bool reloctable = false;
        if (dst.mem.base == ZYDIS_REGISTER_NONE && dst.mem.index == ZYDIS_REGISTER_NONE)
        {
            // Memory ABS
            reloctable = true;
        }

        if (dst.mem.base == ZydisRegister::ZYDIS_REGISTER_RIP)
        {
            displacement = displacement - (va + instrSize);
        }

        dst.mem.displacement = displacement;

        // Handling segment
        switch (op.getSegment().getId())
        {
            case ZYDIS_REGISTER_GS:
                state.req.prefixes |= ZYDIS_ATTRIB_HAS_SEGMENT_GS;
                break;
            case ZYDIS_REGISTER_FS:
                state.req.prefixes |= ZYDIS_ATTRIB_HAS_SEGMENT_FS;
                break;
        }

        return Error::None;
    }

    static Error buildOperand(ZydisEncoderOperand& dst, EncoderState&, const operands::None&) noexcept
    {
        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_UNUSED;
        return Error::None;
    }

    static Error buildOperand(ZydisEncoderOperand& dst, EncoderState& state, const Operand& op) noexcept
    {
        if (auto* opNone = op.tryAs<operands::None>(); opNone != nullptr)
        {
            return buildOperand(dst, state, *opNone);
        }
        else if (auto* opReg = op.tryAs<operands::Reg>(); opReg != nullptr)
        {
            return buildOperand(dst, state, *opReg);
        }
        else if (auto* opMem = op.tryAs<operands::Mem>(); opMem != nullptr)
        {
            return buildOperand(dst, state, *opMem);
        }
        else if (auto* opImm = op.tryAs<operands::Imm>(); opImm != nullptr)
        {
            return buildOperand(dst, state, *opImm);
        }
        else if (auto* opLabel = op.tryAs<operands::Label>(); opLabel != nullptr)
        {
            return buildOperand(dst, state, *opLabel);
        }
        assert(false);
        return Error::InvalidOperation;
    }

    static Error fixupIs4Operands(ZydisEncoderRequest& req) noexcept
    {
        switch (req.mnemonic)
        {
            case ZYDIS_MNEMONIC_VBLENDVPD:
            case ZYDIS_MNEMONIC_VBLENDVPS:
            case ZYDIS_MNEMONIC_VFMADDPD:
            case ZYDIS_MNEMONIC_VFMADDPS:
            case ZYDIS_MNEMONIC_VFMADDSD:
            case ZYDIS_MNEMONIC_VFMADDSS:
            case ZYDIS_MNEMONIC_VFMADDSUBPD:
            case ZYDIS_MNEMONIC_VFMADDSUBPS:
            case ZYDIS_MNEMONIC_VFMSUBADDPD:
            case ZYDIS_MNEMONIC_VFMSUBADDPS:
            case ZYDIS_MNEMONIC_VFMSUBPD:
            case ZYDIS_MNEMONIC_VFMSUBPS:
            case ZYDIS_MNEMONIC_VFMSUBSD:
            case ZYDIS_MNEMONIC_VFMSUBSS:
            case ZYDIS_MNEMONIC_VFNMADDPD:
            case ZYDIS_MNEMONIC_VFNMADDPS:
            case ZYDIS_MNEMONIC_VFNMADDSD:
            case ZYDIS_MNEMONIC_VFNMADDSS:
            case ZYDIS_MNEMONIC_VFNMSUBPD:
            case ZYDIS_MNEMONIC_VPMACSSDD:
            case ZYDIS_MNEMONIC_VPMACSSDQH:
            case ZYDIS_MNEMONIC_VFNMSUBPS:
            case ZYDIS_MNEMONIC_VFNMSUBSD:
            case ZYDIS_MNEMONIC_VFNMSUBSS:
            case ZYDIS_MNEMONIC_VPBLENDVB:
            case ZYDIS_MNEMONIC_VPCMOV:
            case ZYDIS_MNEMONIC_VPERMIL2PD:
            case ZYDIS_MNEMONIC_VPERMIL2PS:
            case ZYDIS_MNEMONIC_VPMACSDD:
            case ZYDIS_MNEMONIC_VPMACSDQH:
            case ZYDIS_MNEMONIC_VPMACSDQL:
            case ZYDIS_MNEMONIC_VPMACSSDQL:
            case ZYDIS_MNEMONIC_VPMACSSWW:
            case ZYDIS_MNEMONIC_VPMACSSWD:
            case ZYDIS_MNEMONIC_VPMACSWD:
            case ZYDIS_MNEMONIC_VPMACSWW:
            case ZYDIS_MNEMONIC_VPMADCSSWD:
            case ZYDIS_MNEMONIC_VPMADCSWD:
            case ZYDIS_MNEMONIC_VPPERM:
                break;
            default:
                return Error::None;
        }

        if (req.operands[2].type == ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER
            && req.operands[3].type == ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER)
        {
            req.operands[3].reg.is4 = true;
        }
        else if (
            req.operands[2].type == ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER
            && req.operands[3].type == ZydisOperandType::ZYDIS_OPERAND_TYPE_MEMORY)
        {
            req.operands[2].reg.is4 = true;
        }
        else if (
            req.operands[2].type == ZydisOperandType::ZYDIS_OPERAND_TYPE_MEMORY
            && req.operands[3].type == ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER)
        {
            req.operands[3].reg.is4 = true;
        }

        return Error::None;
    }

    static Error encode_(
        EncoderBuffer& buf, EncoderContext* ctx, ZydisMachineMode mode, Instruction::Attribs attribs, ZydisMnemonic id,
        const Instruction::Operands& operands) noexcept
    {
        EncoderState state{};
        state.ctx = ctx;

        ZydisEncoderRequest& req = state.req;
        req.machine_mode = mode;
        req.mnemonic = id;
        req.prefixes = getAttribs(attribs);

        if (hasAttrib(attribs, Instruction::Attribs::OperandSize8))
        {
            req.operand_size_hint = ZydisOperandSizeHint::ZYDIS_OPERAND_SIZE_HINT_8;
        }
        else if (hasAttrib(attribs, Instruction::Attribs::OperandSize16))
        {
            req.operand_size_hint = ZydisOperandSizeHint::ZYDIS_OPERAND_SIZE_HINT_16;
        }
        else if (hasAttrib(attribs, Instruction::Attribs::OperandSize32))
        {
            req.operand_size_hint = ZydisOperandSizeHint::ZYDIS_OPERAND_SIZE_HINT_32;
        }
        else if (hasAttrib(attribs, Instruction::Attribs::OperandSize64))
        {
            req.operand_size_hint = ZydisOperandSizeHint::ZYDIS_OPERAND_SIZE_HINT_64;
        }

        const auto numOperands = std::min<size_t>(ZYDIS_ENCODER_MAX_OPERANDS, operands.size());
        for (size_t i = 0; i < numOperands; i++)
        {
            state.operandIndex = i;

            auto& dstOp = req.operands[i];
            if (auto opStatus = buildOperand(dstOp, state, operands[i]); opStatus != Error::None)
            {
                return opStatus;
            }
            if (dstOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_UNUSED)
                break;
            req.operand_count++;
        }

        if (auto status = fixupIs4Operands(req); status != Error::None)
        {
            return status;
        }

        buf.length = 0;
        size_t bufLen = buf.data.size();
        if (auto status = ZydisEncoderEncodeInstruction(&req, buf.data.data(), &bufLen); status != ZYAN_STATUS_SUCCESS)
        {
            switch (status)
            {
                case ZYDIS_STATUS_IMPOSSIBLE_INSTRUCTION:
                default:
                    return Error::ImpossibleInstruction;
            }
        }

        buf.length = static_cast<uint8_t>(bufLen);

        return Error::None;
    }

    Error encodeEstimated(
        EncoderBuffer& buf, ZydisMachineMode mode, Instruction::Attribs attribs, ZydisMnemonic id,
        const Instruction::Operands& operands) noexcept
    {
        return encode_(buf, nullptr, mode, attribs, id, operands);
    }

    static Error encodeFull_(
        EncoderBuffer& buf, EncoderContext& ctx, ZydisMachineMode mode, Instruction::Attribs prefixes, ZydisMnemonic id,
        const Instruction::Operands& operands) noexcept
    {
        // For correct support on instructions with relative encoding we require the instruction size.
        ctx.instrSize = 0;
        auto res = encode_(buf, &ctx, mode, prefixes, id, operands);
        if (res != Error::None)
        {
            return res;
        }

        // If this is set to -1 it hints that it wants the size, this means
        // it encoded temporary values to get the correct size first.
        if (ctx.instrSize == -1)
        {
            // Encode with now known size.
            ctx.instrSize = buf.length;
            res = encode_(buf, &ctx, mode, prefixes, id, operands);
            if (res != Error::None)
            {
                return res;
            }
        }

        return res;
    }

    Error encodeFull(EncoderBuffer& buf, EncoderContext& ctx, ZydisMachineMode mode, const Instruction& instr) noexcept
    {
        Instruction::Operands ops{};

        const auto& operands = instr.getOperands();
        const auto& vis = instr.getVisibility();

        for (size_t i = 0; i < operands.size(); i++)
        {
            if (vis[i] == OperandVisibility::Hidden)
                continue;

            auto& op = operands[i];
            if (op.is<operands::None>())
                break;

            ops[i] = operands[i];
        }

        return encodeFull_(buf, ctx, mode, instr.getAttribs(), instr.getId(), ops);
    }

} // namespace zasm