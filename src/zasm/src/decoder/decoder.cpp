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

    static constexpr bool isRipRelative(const ZydisDecodedOperandMem& mem)
    {
        return mem.base == ZYDIS_REGISTER_RIP || mem.base == ZYDIS_REGISTER_EIP || mem.base == ZYDIS_REGISTER_IP;
    }

    static Operand getOperand(
        const ZydisDecodedInstruction& instr, const ZydisDecodedOperand& srcOp, std::uint64_t address) noexcept
    {
        if (srcOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_UNUSED)
        {
            return Operand::None{};
        }
        if (srcOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER)
        {
            return Reg{ static_cast<Reg::Id>(srcOp.reg.value) };
        }
        if (srcOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_MEMORY)
        {
            auto baseReg = getReg(srcOp.mem.base);
            auto disp = srcOp.mem.disp.value;
            if (isRipRelative(srcOp.mem))
            {
                // Keep RIP as a hint to make this relative.
                disp += instr.length + address;
            }
            return Mem{ toBitSize(srcOp.size),   getReg(srcOp.mem.segment), baseReg,
                        getReg(srcOp.mem.index), srcOp.mem.scale,           disp };
        }
        if (srcOp.type == ZydisOperandType::ZYDIS_OPERAND_TYPE_IMMEDIATE)
        {
            const auto& imm = srcOp.imm;
            if (imm.is_relative != 0)
            {
                std::uint64_t val{};
                ZydisCalcAbsoluteAddress(&instr, &srcOp, address, &val);
                return Imm{ val };
            }
            if (imm.is_signed != 0)
            {
                return Imm{ imm.value.s };
            }

            return Imm{ imm.value.u };
        }
        return Operand::None{};
    }

    static constexpr bool hasAttrib(ZydisInstructionAttributes attribs, ZydisInstructionAttributes test) noexcept
    {
        return (attribs & test) != 0;
    }

    static constexpr Instruction::Attribs getAttribs(ZydisInstructionAttributes attribs) noexcept
    {
        Instruction::Attribs res{};
        const auto translateAttrib = [&](ZydisInstructionAttributes test, x86::Attribs newAttrib) {
            if (!hasAttrib(attribs, test))
            {
                return;
            }
            res = static_cast<Instruction::Attribs>(static_cast<std::uint32_t>(res) | static_cast<std::uint32_t>(newAttrib));
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

    static constexpr Instruction::Category getCategory(ZydisInstructionCategory category) noexcept
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

    static constexpr Operand::Visibility translateOperandVisibility(ZydisOperandVisibility vis)
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

    static constexpr Operand::Access translateOperandAccess(ZydisOperandActions action)
    {
        Operand::Access res{};
        if ((action & ZYDIS_OPERAND_ACTION_READ) != 0)
        {
            res = res | Operand::Access::Read;
        }
        if ((action & ZYDIS_OPERAND_ACTION_WRITE) != 0)
        {
            res = res | Operand::Access::Write;
        }
        if ((action & ZYDIS_OPERAND_ACTION_CONDREAD) != 0)
        {
            res = res | Operand::Access::CondRead;
        }
        if ((action & ZYDIS_OPERAND_ACTION_CONDWRITE) != 0)
        {
            res = res | Operand::Access::CondWrite;
        }
        return res;
    }

    Decoder::Result Decoder::decode(const void* data, const std::size_t len, std::uint64_t address) noexcept
    {
        if (_status != Error::None)
        {
            return zasm::makeUnexpected(_status);
        }

        ZydisDecodedInstruction instr;
        std::array<ZydisDecodedOperand, ZYDIS_MAX_OPERAND_COUNT> instrOps{};

        ZyanStatus status = ZydisDecoderDecodeFull(&_decoder, data, len, &instr, instrOps.data());
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

        for (int i = 0; i < instr.operand_count; ++i)
        {
            // NOLINTNEXTLINE
            const auto& op = instrOps[i];

            ops[i] = getOperand(instr, op, address);

            access.set(i, translateOperandAccess(op.actions));
            vis.set(i, translateOperandVisibility(op.visibility));
        }

        const auto attribs = getAttribs(instr.attributes);
        const auto category = getCategory(instr.meta.category);

        return Instruction(
            attribs, static_cast<Instruction::Mnemonic>(instr.mnemonic), instr.operand_count, ops, access, vis, flags, category,
            instr.length);
    }

} // namespace zasm
