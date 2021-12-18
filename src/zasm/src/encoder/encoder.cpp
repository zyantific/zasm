#include "zasm/encoder/encoder.hpp"

#include "encoder.context.hpp"

#include <optional>
#include <zydis/Encoder.h>

namespace zasm
{
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
        if (entry.boundOffset == -1)
        {
            return std::nullopt;
        }

        return ctx->baseVA + entry.boundOffset;
    }

    struct EncodeVariantsInfo
    {
        bool isControlFlow{};
        int32_t encodeSizeRel8{ -1 };
        int32_t encodeSizeRel32{ -1 };

        bool canEncodeRel8() const
        {
            return encodeSizeRel8 != -1;
        }

        bool canEncodeRel32() const
        {
            return encodeSizeRel32 != -1;
        }
    };

    std::optional<EncodeVariantsInfo> getEncodeVariantInfo(ZydisMnemonic mnemonic)
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
        return std::nullopt;
    }

    static int64_t getRelativeAddress(int64_t va, int64_t target, int32_t instrSize)
    {
        return target - (va + instrSize);
    }

    static bool hasAttrib(Instruction::Attribs attribs, Instruction::Attribs p)
    {
        using T = std::underlying_type_t<Instruction::Attribs>;
        if (static_cast<T>(attribs) & static_cast<T>(p))
        {
            return true;
        }
        return false;
    }

    static ZydisInstructionAttributes getAttribs(Instruction::Attribs prefixes)
    {
        ZydisInstructionAttributes res{};

        const auto translateAttrib = [&](Instruction::Attribs p, ZydisInstructionAttributes a)
        {
            if (hasAttrib(prefixes, p))
            {
                res |= a;
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

    static ZydisEncoderOperand getOperand(
        const size_t index, ZydisEncoderRequest& req, EncoderContext* ctx, const operands::Reg& op)
    {
        ZydisEncoderOperand res{};
        res.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER;
        res.reg.value = op.getId();

        return res;
    }

    static std::pair<int64_t, ZydisBranchType> processRelAddress(
        ZydisEncoderRequest& req, const EncodeVariantsInfo& info, int64_t va, int64_t targetAddress)
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

    static ZydisEncoderOperand getOperand(
        const size_t index, ZydisEncoderRequest& req, EncoderContext* ctx, const operands::Label& op)
    {
        ZydisEncoderOperand res{};

        auto desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE;

        // Initially a temporary placeholder. Make sure this is within rel32 if a
        // context is provided.
        int64_t immValue = ctx ? ctx->va + 0x123456 : 0x123456;

        auto labelVA = getLabelAddress(ctx, op.getId());

        // Check if this operand is used as the control flow target.
        const auto encodeInfo = getEncodeVariantInfo(req.mnemonic);
        if (index == 0 && encodeInfo.has_value() && encodeInfo->isControlFlow)
        {
            auto targetAddress = labelVA.has_value() ? *labelVA : immValue;

            auto [addrRel, branchType] = processRelAddress(req, *encodeInfo, ctx ? ctx->va : 0, targetAddress);

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
            req.branch_type = desiredBranchType;
        }

        res.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_IMMEDIATE;
        res.imm.s = immValue;

        return res;
    }

    static ZydisEncoderOperand getOperand(
        const size_t index, ZydisEncoderRequest& req, EncoderContext* ctx, const operands::Imm& op)
    {
        ZydisEncoderOperand res{};

        auto desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE;
        int64_t immValue = op.value<int64_t>();

        // Check if this operand is used as the control flow target.
        const auto encodeInfo = getEncodeVariantInfo(req.mnemonic);
        if (index == 0 && encodeInfo.has_value() && encodeInfo->isControlFlow)
        {
            const auto targetAddress = immValue;
            auto [addrRel, branchType] = processRelAddress(req, *encodeInfo, ctx ? ctx->va : 0, targetAddress);

            immValue = addrRel;
            desiredBranchType = branchType;
        }

        if (desiredBranchType != ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE)
        {
            req.branch_type = desiredBranchType;
        }

        res.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_IMMEDIATE;
        res.imm.s = immValue;

        return res;
    }

    static ZydisEncoderOperand getOperand(
        const size_t index, ZydisEncoderRequest& req, EncoderContext* ctx, const operands::Mem& op)
    {
        ZydisEncoderOperand res{};
        res.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_MEMORY;
        res.mem.base = op.getBase().getId();
        res.mem.index = op.getIndex().getId();
        res.mem.scale = op.getScale();
        res.mem.size = op.getByteSize();

        int64_t displacement = op.getDisplacement();

        const auto instrSize = ctx ? ctx->instrSize : 0;
        const auto va = ctx ? ctx->va : 0;

        // We require the exact instruction size to encode this correctly.
        if (ctx && instrSize == 0)
        {
            // Causes to re-encode again with instruction size available.
            ctx->instrSize = -1;
        }

        if (auto labelId = op.getLabelId(); labelId != Label::Id::Invalid && ctx != nullptr)
        {
            auto labelVA = getLabelAddress(ctx, labelId);
            if (labelVA.has_value())
            {
                displacement += *labelVA;
            }
        }

        // FIXME: This only works for 64 bit.
        if (res.mem.base == ZydisRegister::ZYDIS_REGISTER_RIP)
        {
            displacement = displacement - (va + instrSize);
        }

        res.mem.displacement = displacement;

        // Handling segment
        switch (op.getSegment().getId())
        {
            case ZYDIS_REGISTER_GS:
                req.prefixes |= ZYDIS_ATTRIB_HAS_SEGMENT_GS;
                break;
            case ZYDIS_REGISTER_FS:
                req.prefixes |= ZYDIS_ATTRIB_HAS_SEGMENT_FS;
                break;
        }

        return res;
    }

    static ZydisEncoderOperand getOperand(
        const size_t index, ZydisEncoderRequest&, EncoderContext* ctx, const operands::None& op)
    {
        ZydisEncoderOperand res{};
        res.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_UNUSED;
        return res;
    }

    static ZydisEncoderOperand getOperand(const size_t index, ZydisEncoderRequest& req, EncoderContext* ctx, const Operand& op)
    {
        return std::visit([&](auto&& op) { return getOperand(index, req, ctx, op); }, op);
    }

    static Error fixupIs4Operands(ZydisEncoderRequest& req)
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
        const Instruction::Operands& operands)
    {
        ZydisEncoderRequest req{};
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
            req.operands[i] = getOperand(i, req, ctx, operands[i]);
            if (req.operands[i].type == ZydisOperandType::ZYDIS_OPERAND_TYPE_UNUSED)
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
        const Instruction::Operands& operands)
    {
        return encode_(buf, nullptr, mode, attribs, id, operands);
    }

    static Error encodeFull(
        EncoderBuffer& buf, EncoderContext& ctx, ZydisMachineMode mode, Instruction::Attribs prefixes, ZydisMnemonic id,
        const Instruction::Operands& operands)
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

    Error encodeFull(EncoderBuffer& buf, EncoderContext& ctx, ZydisMachineMode mode, const Instruction& instr)
    {
        Instruction::Operands ops{};

        const auto& operands = instr.getOperands();
        const auto& vis = instr.getVisibility();

        for (size_t i = 0; i < operands.size(); i++)
        {
            if (vis[i] == OperandVisibility::Hidden)
                continue;

            auto& op = operands[i];
            if (std::holds_alternative<operands::None>(op))
                break;

            ops[i] = operands[i];
        }

        return encodeFull(buf, ctx, mode, instr.getAttribs(), instr.getId(), ops);
    }

} // namespace zasm