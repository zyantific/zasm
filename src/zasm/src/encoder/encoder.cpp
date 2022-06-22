#include "zasm/encoder/encoder.hpp"

#include "../program/program.state.hpp"
#include "encoder.context.hpp"

#include <Zydis/Decoder.h>
#include <Zydis/Encoder.h>
#include <limits>
#include <optional>

namespace zasm
{
    // Ensure size is correct.
    static_assert(std::tuple_size_v<EncoderOperands> == ZYDIS_ENCODER_MAX_OPERANDS);

    struct EncoderState
    {
        EncoderContext* ctx{};
        ZydisEncoderRequest req{};
        size_t operandIndex{};
        RelocationType relocKind{};
        RelocationData relocData{};
        Label::Id relocLabel{ Label::Id::Invalid };
    };

    // NOTE: This value has to be at least larger than 0xFFFF to be used with imm32/rel32 displacement.
    static constexpr int32_t kTemporaryRel32Value = 0x123456;
    static constexpr int32_t kHintRequiresSize = -1;

    struct EncodeVariantsInfo
    {
        bool isControlFlow{};
        int8_t encodeSizeRel8{ -1 };
        int8_t encodeSizeRel32{ -1 };

        constexpr bool canEncodeRel8() const noexcept
        {
            return encodeSizeRel8 != -1;
        }

        constexpr bool canEncodeRel32() const noexcept
        {
            return encodeSizeRel32 != -1;
        }
    };

    static constexpr auto buildEncodeVariantTable() noexcept
    {
        std::array<EncodeVariantsInfo, ZydisMnemonic::ZYDIS_MNEMONIC_MAX_VALUE> data{};

        // Control-flow specific data.
        data[ZYDIS_MNEMONIC_JMP] = EncodeVariantsInfo{ true, 2, 5 };

        data[ZYDIS_MNEMONIC_JB] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JBE] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JCXZ] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JECXZ] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JKNZD] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JKZD] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JL] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JLE] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JNB] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JNBE] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JNL] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JNLE] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JNO] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JNP] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JNS] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JNZ] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JO] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JP] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JRCXZ] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JS] = EncodeVariantsInfo{ true, 2, 6 };
        data[ZYDIS_MNEMONIC_JZ] = EncodeVariantsInfo{ true, 2, 6 };

        data[ZYDIS_MNEMONIC_LOOP] = EncodeVariantsInfo{ true, 2, -1 };
        data[ZYDIS_MNEMONIC_LOOPE] = EncodeVariantsInfo{ true, 2, -1 };
        data[ZYDIS_MNEMONIC_LOOPNE] = EncodeVariantsInfo{ true, 2, -1 };

        data[ZYDIS_MNEMONIC_CALL] = EncodeVariantsInfo{ true, -1, 5 };

        return data;
    }

    static constexpr auto encoderVariantData = buildEncodeVariantTable();

    static const EncodeVariantsInfo& getEncodeVariantInfo(ZydisMnemonic mnemonic) noexcept
    {
        return encoderVariantData[mnemonic];
    }

    static bool isLabelExternal(detail::ProgramState* state, Label::Id id)
    {
        size_t idx = static_cast<size_t>(id);
        if (idx >= state->labels.size())
            return false;

        auto& data = state->labels[idx];
        if ((data.flags & detail::LabelFlags::External) != detail::LabelFlags::None)
        {
            return true;
        }

        return false;
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

        const auto translateAttrib = [&res, &attribs](Instruction::Attribs other, ZydisInstructionAttributes newAttrib) {
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

    static Error buildOperand_(ZydisEncoderOperand& dst, EncoderState&, const operands::Reg& op) noexcept
    {
        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER;
        dst.reg.value = op.getId();

        return Error::None;
    }

    static Error buildOperand_(ZydisEncoderOperand& dst, EncoderState& state, const operands::Label& op) noexcept
    {
        auto* ctx = state.ctx;
        auto desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE;

        // Initially a temporary placeholder. Make sure this is within rel32 if a
        // context is provided.
        int64_t immValue = ctx != nullptr ? ctx->va + kTemporaryRel32Value : kTemporaryRel32Value;

        std::optional<int64_t> labelVA;
        if (ctx != nullptr && !isLabelExternal(ctx->program, op.getId()))
        {
            labelVA = ctx != nullptr ? ctx->getLabelAddress(op.getId()) : std::nullopt;
            if (!labelVA.has_value() && ctx != nullptr)
            {
                ctx->needsExtraPass = true;
            }
        }

        // Check if this operand is used as the control flow target.
        const auto& encodeInfo = getEncodeVariantInfo(state.req.mnemonic);
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

            // Mark relocatable, only mov is allowed to have a label.
            if (state.req.mnemonic == ZYDIS_MNEMONIC_MOV)
            {
                if (state.req.operands[0].type == ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER)
                {
                    state.relocKind = RelocationType::Abs;
                    state.relocData = RelocationData::Immediate;
                    state.relocLabel = op.getId();
                }
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

    static Error buildOperand_(ZydisEncoderOperand& dst, EncoderState& state, const operands::Imm& op) noexcept
    {
        auto* ctx = state.ctx;

        auto desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE;
        int64_t immValue = op.value<int64_t>();

        // Check if this operand is used as the control flow target.
        const auto& encodeInfo = getEncodeVariantInfo(state.req.mnemonic);
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

    static Error buildOperand_(ZydisEncoderOperand& dst, EncoderState& state, const operands::Mem& op) noexcept
    {
        auto* ctx = state.ctx;

        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_MEMORY;
        dst.mem.base = op.getBase().getId();
        dst.mem.index = op.getIndex().getId();
        dst.mem.scale = op.getScale();
        dst.mem.size = static_cast<uint16_t>(op.getByteSize());

        int64_t displacement = op.getDisplacement();

        const auto va = ctx ? ctx->va : 0;

        bool usingLabel = false;
        bool externalLabel = false;

        if (auto labelId = op.getLabelId(); labelId != Label::Id::Invalid)
        {
            if (ctx != nullptr)
            {
                auto labelVA = ctx->getLabelAddress(labelId);
                if (labelVA.has_value())
                {
                    displacement += *labelVA;
                }
                else
                {
                    displacement += kTemporaryRel32Value;
                    ctx->needsExtraPass = true;
                }
                externalLabel = isLabelExternal(ctx->program, labelId);
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

        if (dst.mem.base == ZYDIS_REGISTER_NONE && dst.mem.index == ZYDIS_REGISTER_NONE)
        {
            // Memory ABS, mark relocatable.
            state.relocKind = RelocationType::Abs;
            state.relocData = RelocationData::Memory;
        }
        else if (dst.mem.base == ZydisRegister::ZYDIS_REGISTER_RIP)
        {
            // We require the exact instruction size to encode this correctly.
            const auto instrSize = ctx ? ctx->instrSize : 0;
            if (ctx && instrSize == 0)
            {
                // Causes to re-encode again with instruction size available.
                ctx->instrSize = kHintRequiresSize;
            }

            displacement = displacement - (va + instrSize);

            if (ctx != nullptr && usingLabel && isLabelExternal(ctx->program, op.getLabelId()))
            {
                state.relocKind = RelocationType::Rel32;
                state.relocData = RelocationData::Memory;
                state.relocLabel = op.getLabelId();
            }
        }

        dst.mem.displacement = displacement;

        // Handling segment
        const auto segmentId = op.getSegment().getId();
        if (segmentId == ZYDIS_REGISTER_GS)
            state.req.prefixes |= ZYDIS_ATTRIB_HAS_SEGMENT_GS;
        else if (segmentId == ZYDIS_REGISTER_FS)
            state.req.prefixes |= ZYDIS_ATTRIB_HAS_SEGMENT_FS;

        return Error::None;
    }

    static Error buildOperand_(ZydisEncoderOperand& dst, EncoderState&, const operands::None&) noexcept
    {
        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_UNUSED;
        return Error::None;
    }

    static Error buildOperand(ZydisEncoderOperand& dst, EncoderState& state, const Operand& op) noexcept
    {
        return op.visit([&dst, &state](auto&& op2) { return buildOperand_(dst, state, op2); });
    }

    static void fixupIs4Operands(ZydisEncoderRequest& req) noexcept
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
                return;
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
    }

    static Error encode_(
        EncoderResult& res, EncoderContext* ctx, ZydisMachineMode mode, Instruction::Attribs attribs, ZydisMnemonic id,
        size_t numOps, const Operand* operands) noexcept
    {
        res.length = 0;

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

        const auto numOperands = std::min<size_t>(ZYDIS_ENCODER_MAX_OPERANDS, numOps);
        for (state.operandIndex = 0; state.operandIndex < numOperands; ++state.operandIndex)
        {
            auto& dstOp = req.operands[state.operandIndex];
            const auto& srcOp = operands[state.operandIndex];
            if (auto opStatus = buildOperand(dstOp, state, srcOp); opStatus != Error::None)
            {
                return opStatus;
            }
            req.operand_count++;
        }

        fixupIs4Operands(req);

        size_t bufLen = res.data.size();
        switch (auto status = ZydisEncoderEncodeInstruction(&req, res.data.data(), &bufLen); status)
        {
            case ZYAN_STATUS_SUCCESS:
                break;
            case ZYDIS_STATUS_IMPOSSIBLE_INSTRUCTION:
            default:
                return Error::ImpossibleInstruction;
        }

        res.length = static_cast<uint8_t>(bufLen);
        res.relocKind = state.relocKind;
        res.relocData = state.relocData;
        res.relocLabel = state.relocLabel;

        return Error::None;
    }

    Error encodeEstimated(
        EncoderResult& res, ZydisMachineMode mode, Instruction::Attribs attribs, ZydisMnemonic id, size_t numOps,
        const EncoderOperands& operands) noexcept
    {
        return encode_(res, nullptr, mode, attribs, id, numOps, operands.data());
    }

    static Error encodeFull_(
        EncoderResult& res, EncoderContext& ctx, ZydisMachineMode mode, Instruction::Attribs prefixes, ZydisMnemonic id,
        size_t numOps, const Operand* operands) noexcept
    {
        // encode_ will set this to kHintRequiresSize in case a length is required for correct encoding.
        ctx.instrSize = 0;

        if (auto encodeError = encode_(res, &ctx, mode, prefixes, id, numOps, operands); encodeError != Error::None)
        {
            return encodeError;
        }

        while (ctx.instrSize == kHintRequiresSize)
        {
            // Encode with now known size, instruction size can change again in this call.
            ctx.instrSize = res.length;
            if (auto encodeError = encode_(res, &ctx, mode, prefixes, id, numOps, operands); encodeError != Error::None)
            {
                return encodeError;
            }

            // If the instruction size does not match what we previously specified
            // we need to re-encode it with the now known size, this can happen near
            // the limits of rel8/32 but is unlikely.
            if (res.length != ctx.instrSize)
            {
                ctx.instrSize = kHintRequiresSize;
            }
        }

        return Error::None;
    }

    Error encodeFull(EncoderResult& buf, EncoderContext& ctx, ZydisMachineMode mode, const Instruction& instr) noexcept
    {
        const auto& operands = instr.getOperands();
        const auto& vis = instr.getOperandsVisibility();
        const auto countOpInputs = std::min<size_t>(ZYDIS_ENCODER_MAX_OPERANDS, instr.getOperandCount());

        size_t explicitOps = 0;
        for (size_t i = 0; i < countOpInputs; ++i)
        {
            if (vis[i] == Operand::Visibility::Hidden)
                break;

            auto& op = operands[i];
            if (op.holds<operands::None>())
                break;

            explicitOps++;
        }

        return encodeFull_(buf, ctx, mode, instr.getAttribs(), instr.getId(), explicitOps, operands.data());
    }

} // namespace zasm