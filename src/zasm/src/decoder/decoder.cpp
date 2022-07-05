#include "zasm/decoder/decoder.hpp"

#include "zasm/program/instruction.hpp"
#include "zasm/program/operand.hpp"
#include "zasm/x86/instruction.hpp"

#include <Zydis/Decoder.h>

namespace zasm
{
    static constexpr Reg getReg(ZydisRegister reg)
    {
        return Reg{ static_cast<Reg::Id>(reg) };
    }

    static Operand getOperand(const ZydisDecodedInstruction& instr, const ZydisDecodedOperand& srcOp, uint64_t va) noexcept
    {
        if (srcOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_UNUSED)
        {
            return Operand::None{};
        }
        else if (srcOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER)
        {
            return Reg{ static_cast<Reg::Id>(srcOp.reg.value) };
        }
        else if (srcOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_MEMORY)
        {
            return Mem{ toBitSize(srcOp.size),   getReg(srcOp.mem.segment), getReg(srcOp.mem.base),
                        getReg(srcOp.mem.index), srcOp.mem.scale,           srcOp.mem.disp.value };
        }
        else if (srcOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_IMMEDIATE)
        {
            auto& imm = srcOp.imm;
            if (imm.is_relative)
            {
                uint64_t val;
                ZydisCalcAbsoluteAddress(&instr, &srcOp, va, &val);
                return Imm{ val };
            }
            else if (imm.is_signed)
            {
                return Imm{ imm.value.s };
            }
            else
            {
                return Imm{ imm.value.u };
            }
        }
        return Operand::None{};
    }

    static bool hasAttrib(ZydisInstructionAttributes attribs, ZydisInstructionAttributes b)
    {
        if (attribs & b)
            return true;
        return false;
    }

    static Instruction::Attribs getAttribs(ZydisInstructionAttributes attribs)
    {
        Instruction::Attribs res{};
        const auto translateAttrib = [&](ZydisInstructionAttributes a, x86::Attribs b) {
            if (!hasAttrib(attribs, a))
                return;

            res = static_cast<Instruction::Attribs>(static_cast<uint32_t>(res) | static_cast<uint32_t>(b));
        };
        translateAttrib(ZYDIS_ATTRIB_HAS_LOCK, x86::Attribs::Lock);
        translateAttrib(ZYDIS_ATTRIB_HAS_REP, x86::Attribs::Rep);
        translateAttrib(ZYDIS_ATTRIB_HAS_REPE, x86::Attribs::Repe);
        translateAttrib(ZYDIS_ATTRIB_HAS_REPNE, x86::Attribs::Repne);
        translateAttrib(ZYDIS_ATTRIB_HAS_BND, x86::Attribs::Bnd);
        translateAttrib(ZYDIS_ATTRIB_HAS_XACQUIRE, x86::Attribs::Xacquire);
        translateAttrib(ZYDIS_ATTRIB_HAS_XRELEASE, x86::Attribs::Xrelease);
        translateAttrib(ZYDIS_ATTRIB_HAS_OPERANDSIZE, x86::Attribs::OperandSize16);
        return res;
    }

    static Instruction::Category getCategory(ZydisInstructionCategory category)
    {
        return static_cast<Instruction::Category>(category);
    }

    Decoder::Decoder(MachineMode mode) noexcept
    {
        ZyanStatus status{};
        switch (mode)
        {
            case MachineMode::AMD64:
                status = ZydisDecoderInit(&_decoder, ZYDIS_MACHINE_MODE_LONG_64, ZydisStackWidth::ZYDIS_STACK_WIDTH_64);
                break;
            case MachineMode::I386:
                status = ZydisDecoderInit(&_decoder, ZYDIS_MACHINE_MODE_LONG_COMPAT_32, ZydisStackWidth::ZYDIS_STACK_WIDTH_32);
                break;
            default:
                break;
        }

        if (status != ZYAN_STATUS_SUCCESS)
        {
            // TODO: Translate proper error.
            _status = Error::NotInitialized;
        }
    }

    static Operand::Visibility translateOperandVisibility(ZydisOperandVisibility vis)
    {
        switch (vis)
        {
            case ZYDIS_OPERAND_VISIBILITY_INVALID:
                return Operand::Visibility::Invalid;
            case ZYDIS_OPERAND_VISIBILITY_EXPLICIT:
                return Operand::Visibility::Explicit;
            case ZYDIS_OPERAND_VISIBILITY_IMPLICIT:
                return Operand::Visibility::Implicit;
            case ZYDIS_OPERAND_VISIBILITY_HIDDEN:
                return Operand::Visibility::Hidden;
            default:
                break;
        }
        return Operand::Visibility::Invalid;
    }

    static Operand::Access translateOperandAccess(ZydisOperandActions action)
    {
        Operand::Access res{};
        if (action & ZYDIS_OPERAND_ACTION_READ)
            res = res | Operand::Access::Read;
        if (action & ZYDIS_OPERAND_ACTION_WRITE)
            res = res | Operand::Access::Write;
        if (action & ZYDIS_OPERAND_ACTION_CONDREAD)
            res = res | Operand::Access::CondRead;
        if (action & ZYDIS_OPERAND_ACTION_CONDWRITE)
            res = res | Operand::Access::CondWrite;
        return res;
    }

    Decoder::Result Decoder::decode(const void* data, const size_t len, uint64_t va) noexcept
    {
        if (_status != Error::None)
        {
            return zasm::makeUnexpected(_status);
        }

        ZydisDecodedInstruction instr;
        ZydisDecodedOperand instrOps[ZYDIS_MAX_OPERAND_COUNT];

        ZyanStatus status = ZydisDecoderDecodeFull(
            &_decoder, data, len, &instr, instrOps, static_cast<ZyanU8>(std::size(instrOps)), 0);
        if (status != ZYAN_STATUS_SUCCESS)
        {
            // TODO: Translate proper error.
            return zasm::makeUnexpected(Error::InvalidOperation);
        }

        Instruction::CPUFlags flags{};
        if (instr.cpu_flags != nullptr)
        {
            flags.read = instr.cpu_flags->tested;
            flags.write = instr.cpu_flags->modified | instr.cpu_flags->set_0 | instr.cpu_flags->set_1;
            flags.undefined = instr.cpu_flags->undefined;
        }

        Instruction::Operands ops;
        Instruction::OperandsVisibility vis;
        Instruction::OperandsAccess access;

        for (auto i = 0; i < instr.operand_count; ++i)
        {
            const auto& op = instrOps[i];

            ops[i] = getOperand(instr, op, va);

            access[i] = translateOperandAccess(op.actions);
            vis[i] = translateOperandVisibility(op.visibility);
        }

        const auto attribs = getAttribs(instr.attributes);
        const auto category = getCategory(instr.meta.category);

        return Instruction(
            attribs, static_cast<Instruction::Mnemonic>(instr.mnemonic), instr.operand_count, ops, access, vis, flags, category,
            instr.length);
    }

} // namespace zasm
