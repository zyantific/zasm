#include "zasm/decoder.hpp"

#include "zasm/instruction.hpp"
#include "zasm/operand.hpp"

#include <Zydis/Decoder.h>

namespace zasm
{
    static Operand getOperand(const ZydisDecodedInstruction& instr, const ZydisDecodedOperand& srcOp, uint64_t va)
    {
        if (srcOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_UNUSED)
        {
            return operands::None{};
        }
        else if (srcOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER)
        {
            return operands::Reg{ srcOp.reg.value };
        }
        else if (srcOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_MEMORY)
        {
            return operands::Mem{ toBitSize(srcOp.size),
                                  operands::Seg{ srcOp.mem.segment },
                                  operands::Reg{ srcOp.mem.base },
                                  operands::Reg{ srcOp.mem.index },
                                  srcOp.mem.scale,
                                  srcOp.mem.disp.value };
        }
        else if (srcOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_IMMEDIATE)
        {
            auto& imm = srcOp.imm;
            if (imm.is_relative)
            {
                uint64_t val;
                ZydisCalcAbsoluteAddress(&instr, &srcOp, va, &val);
                return operands::Imm{ val };
            }
            else if (imm.is_signed)
            {
                return operands::Imm{ imm.value.s };
            }
            else
            {
                return operands::Imm{ imm.value.u };
            }
        }
        return operands::None{};
    }

    DecoderResult decode(ZydisMachineMode mode, const void* data, const size_t len, uint64_t va)
    {
        ZydisDecoder decoder;

        ZyanStatus status{};
        switch (mode)
        {
            case ZYDIS_MACHINE_MODE_LONG_64:
                status = ZydisDecoderInit(&decoder, mode, ZydisStackWidth::ZYDIS_STACK_WIDTH_64);
                break;
            case ZYDIS_MACHINE_MODE_LONG_COMPAT_32:
            case ZYDIS_MACHINE_MODE_LEGACY_32:
                status = ZydisDecoderInit(&decoder, mode, ZydisStackWidth::ZYDIS_STACK_WIDTH_32);
                break;
            case ZYDIS_MACHINE_MODE_LONG_COMPAT_16:
            case ZYDIS_MACHINE_MODE_LEGACY_16:
            case ZYDIS_MACHINE_MODE_REAL_16:
                status = ZydisDecoderInit(&decoder, mode, ZydisStackWidth::ZYDIS_STACK_WIDTH_16);
                break;
            default:
                break;
        }

        if (status != ZYAN_STATUS_SUCCESS)
        {
            // TODO: Translate proper error.
            return xstd::make_unexpected(Error::InvalidOperation);
        }

        ZydisDecodedInstruction instr{};
        ZydisDecodedOperand instrOps[ZYDIS_MAX_OPERAND_COUNT]{};
        status = ZydisDecoderDecodeFull(&decoder, data, len, &instr, instrOps, std::size(instrOps), 0);
        if (status != ZYAN_STATUS_SUCCESS)
        {
            // TODO: Translate proper error.
            return xstd::make_unexpected(Error::InvalidOperation);
        }

        Instruction::Prefix prefixes{};
        // FIXME: Handle me.

        Instruction::Flags flags{};
        if (instr.cpu_flags != nullptr)
        {
            flags.read = instr.cpu_flags->tested;
            flags.write = instr.cpu_flags->modified | instr.cpu_flags->set_0 | instr.cpu_flags->set_1;
            flags.undefined = instr.cpu_flags->undefined;
        }

        Instruction::Operands ops{};
        Instruction::Visibility vis{};
        Instruction::Access access{};
        for (auto i = 0; i < instr.operand_count; ++i)
        {
            const auto& op = instrOps[i];
            ops[i] = getOperand(instr, op, va);
            access[i] = op.actions;
            vis[i] = static_cast<OperandVisibility>(op.visibility);
        }

        return Instruction(prefixes, instr.mnemonic, ops, access, vis, flags, instr.length);
    }

} // namespace zasm