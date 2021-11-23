#include "zasm/encoder.hpp"
#include "encoder.context.hpp"

#include <optional>
#include <zydis/Encoder.h>

namespace zasm
{
    static std::optional<int64_t> getLabelAddress(EncoderContext* ctx, Label::Id id)
    {
        if (ctx == nullptr)
            return std::nullopt;

        const auto labelIdx = static_cast<size_t>(id);
        if (labelIdx >= ctx->labelLinks.size())
        {
            ctx->labelLinks.resize(labelIdx + 1);
        }

        const auto& entry = ctx->labelLinks[labelIdx];
        if (entry.boundOffset == -1)
        {
            return std::nullopt;
        }

        const auto labelVA = ctx->baseVA + entry.boundOffset;
        if(ctx->va < labelVA)
            return labelVA - ctx->drift;

        return labelVA;
    }

    struct InstructionHints
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

    std::optional<InstructionHints> getInstructionHints(ZydisMnemonic mnemonic)
    {
        switch (mnemonic)
        {
            case ZYDIS_MNEMONIC_JMP:
                return InstructionHints{ true, 2, 5 };
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
                return InstructionHints{ true, 2, 6 };
            case ZYDIS_MNEMONIC_LOOP:
            case ZYDIS_MNEMONIC_LOOPE:
            case ZYDIS_MNEMONIC_LOOPNE:
                return InstructionHints{ true, 2, -1 };
            case ZYDIS_MNEMONIC_CALL:
                return InstructionHints{ true, -1, 5 };
        }
        return std::nullopt;
    }

    static ZydisEncodableBranchType getBranchTypeNear32(ZydisEncoderRequest& req)
    {
        if (req.machine_mode == ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64)
            return ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NEAR64;
        else
            return ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NEAR32;
    }

    static ZydisEncodableBranchType getBranchEncodeType(
        ZydisEncoderRequest& req, const InstructionHints& hint, int64_t va, int64_t target, int32_t instrSize)
    {
        constexpr auto rangeRel8 = std::numeric_limits<int8_t>::max();
        constexpr auto rangeRel32 = std::numeric_limits<int32_t>::max();

        if (instrSize != 0)
        {
            const auto rel = target - (va + instrSize);
            if (hint.canEncodeRel8())
            {
                if (rel >= -rangeRel8 && rel <= rangeRel8)
                {
                    return ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_SHORT;
                }
            }
            if (hint.canEncodeRel32())
            {
                if (rel > -rangeRel32 && rel < rangeRel32)
                {
                    return getBranchTypeNear32(req);
                }
            }
        }
        else
        {
            // Check if it would fit short (rel8).
            if (hint.canEncodeRel8())
            {
                const auto rel = target - (va + hint.encodeSizeRel8);
                if (rel >= -rangeRel8 && rel <= rangeRel8)
                {
                    return ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_SHORT;
                }
            }

            // TODO: 16 bit.
            {
            }

            if (hint.canEncodeRel32())
            {
                const auto rel = target - (va + hint.encodeSizeRel32);
                if (rel > -rangeRel32 && rel < rangeRel32)
                {
                    return getBranchTypeNear32(req);
                }
            }
        }

        return ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NONE;
    }

    static int64_t getRelativeAddress(
        ZydisEncoderRequest& req, const InstructionHints& hint, ZydisEncodableBranchType branchType, int64_t va,
        int64_t target, int32_t instrSize)
    {
        if (instrSize != 0)
        {
            if (branchType == ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_SHORT)
            {
                return target - (va + instrSize);
            }
            else if (
                branchType == ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NEAR32
                || branchType == ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NEAR64)
            {
                return target - (va + instrSize);
            }
        }
        else
        {
            if (branchType == ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_SHORT)
            {
                return target - (va + hint.encodeSizeRel8);
            }
            else if (
                branchType == ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NEAR32
                || branchType == ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NEAR64)
            {
                return target - (va + hint.encodeSizeRel32);
            }
        }
        assert(false);
        return 0;
    }

    static ZydisInstructionAttributes getPrefixes(Instruction::Prefix prefixes)
    {
        // FIXME
        return {};
    }

    static ZydisEncoderOperand getOperand(size_t index, ZydisEncoderRequest&, EncoderContext* ctx, const operands::Reg& op)
    {
        ZydisEncoderOperand res{};
        res.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER;
        res.reg.value = op.id();
        return res;
    }

    static ZydisEncoderOperand getOperand(
        size_t index, ZydisEncoderRequest& req, EncoderContext* ctx, const operands::Label& op)
    {
        ZydisEncoderOperand res{};

        auto desiredBranchType = ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NONE;

        // Initially a temporary placeholder.
        int64_t immValue = 0x123456;

        auto labelVA = getLabelAddress(ctx, op.getId());
        if (index == 0)
        {
            const auto instrHints = getInstructionHints(req.mnemonic);
            if (instrHints.has_value() && instrHints->isControlFlow)
            {
                if (req.machine_mode == ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64)
                    desiredBranchType = ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NEAR64;
                else
                    desiredBranchType = ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NEAR32;

                if (labelVA.has_value())
                {
                    auto instrSize = ctx->instrSize;
                    if (instrSize == 0)
                    {
                        // Causes to re-encode again with instruction size available.
                        ctx->instrSize = -1;
                    }
                    desiredBranchType = getBranchEncodeType(req, *instrHints, ctx->va, *labelVA, instrSize);
                    immValue = getRelativeAddress(req, *instrHints, desiredBranchType, ctx->va, *labelVA, instrSize);
                }
            }
        }
        else
        {
            if (labelVA.has_value())
            {
                immValue = *labelVA;
            }
        }

        if (desiredBranchType != ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NONE)
        {
            req.branch_type = desiredBranchType;
        }

        res.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_IMMEDIATE;
        res.imm.s = immValue;

        return res;
    }

    static ZydisEncoderOperand getOperand(size_t index, ZydisEncoderRequest& req, EncoderContext* ctx, const operands::Mem& op)
    {
        ZydisEncoderOperand res{};
        res.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_MEMORY;
        res.mem.base = op.getBase().id();
        res.mem.index = op.getIndex().id();
        res.mem.scale = op.getScale();
        res.mem.size = op.getByteSize();

        int64_t displacement = op.getDisplacement();

        const auto instrSize = ctx ? ctx->instrSize : 0;
        const auto va = ctx ? ctx->va : 0;
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
        switch (op.getSegment().id())
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

    static ZydisEncoderOperand getOperand(size_t index, ZydisEncoderRequest& req, EncoderContext* ctx, const operands::Imm& op)
    {
        ZydisEncoderOperand res{};

        auto desiredBranchType = ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NONE;
        int64_t immValue = op.value<int64_t>();

        if (index == 0)
        {
            const auto instrHints = getInstructionHints(req.mnemonic);
            if (instrHints.has_value() && instrHints->isControlFlow)
            {
                if (req.machine_mode == ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64)
                    desiredBranchType = ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NEAR64;
                else
                    desiredBranchType = ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NEAR32;

                if (instrHints.has_value() && ctx != nullptr)
                {
                    auto instrSize = ctx->instrSize;
                    if (instrSize == 0)
                    {
                        // Causes to re-encode again with instruction size available.
                        ctx->instrSize = -1;
                    }
                    desiredBranchType = getBranchEncodeType(req, *instrHints, ctx->va, immValue, instrSize);
                    immValue = getRelativeAddress(req, *instrHints, desiredBranchType, ctx->va, immValue, instrSize);
                }
                else
                {
                    immValue = 0x12345;
                }
            }
        }

        if (desiredBranchType != ZydisEncodableBranchType::ZYDIS_ENCODABLE_BRANCH_TYPE_NONE)
        {
            req.branch_type = desiredBranchType;
        }

        res.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_IMMEDIATE;
        res.imm.s = immValue;

        return res;
    }

    static ZydisEncoderOperand getOperand(size_t index, ZydisEncoderRequest&, EncoderContext* ctx, const operands::None& op)
    {
        ZydisEncoderOperand res{};
        res.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_UNUSED;
        return res;
    }

    static ZydisEncoderOperand getOperand(size_t index, ZydisEncoderRequest& req, EncoderContext* ctx, const Operand& op)
    {
        return std::visit([&](auto&& op) { return getOperand(index, req, ctx, op); }, op);
    }

    static Error encode_(
        EncoderBuffer& buf, EncoderContext* ctx, ZydisMachineMode mode, Instruction::Prefix prefixes, ZydisMnemonic id,
        const Instruction::Operands& operands)
    {
        ZydisEncoderRequest req{};
        req.machine_mode = mode;
        req.mnemonic = id;
        req.prefixes = getPrefixes(prefixes);

        for (size_t i = 0; i < operands.size(); i++)
        {
            req.operands[i] = getOperand(i, req, ctx, operands[i]);
            if (req.operands[i].type == ZydisOperandType::ZYDIS_OPERAND_TYPE_UNUSED)
                break;
            req.operand_count++;
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
        EncoderBuffer& buf, ZydisMachineMode mode, Instruction::Prefix prefixes, ZydisMnemonic id,
        const Instruction::Operands& operands)
    {
        return encode_(buf, nullptr, mode, prefixes, id, operands);
    }

    static Error encodeFull(
        EncoderBuffer& buf, EncoderContext& ctx, ZydisMachineMode mode, Instruction::Prefix prefixes, ZydisMnemonic id,
        const Instruction::Operands& operands)
    {
        static int ctr = 0;
        ctr++;

        // For correct support on instructions with relative encoding we require the instruction size.
        ctx.instrSize = 0;
        auto res = encode_(buf, &ctx, mode, prefixes, id, operands);
        if (res != Error::None)
        {
            return res;
        }

        // If this is set to -1 it hints that it wants the size, need to re-encode.
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

        return encodeFull(buf, ctx, mode, instr.getPrefixes(), instr.getId(), ops);
    }

} // namespace zasm