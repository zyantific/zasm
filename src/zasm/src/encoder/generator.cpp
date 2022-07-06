#include "generator.hpp"

#include <Zydis/Zydis.h>
#include <zasm/x86/instruction.hpp>

namespace zasm
{
    // FIXME: Duplicate code, move this somewhere.
    static bool isImmediateControlFlow(Instruction::Mnemonic mnemonic) noexcept
    {
        switch (static_cast<x86::Mnemonic>(mnemonic))
        {
            case x86::Mnemonic::Call:
            case x86::Mnemonic::Jb:
            case x86::Mnemonic::Jbe:
            case x86::Mnemonic::Jcxz:
            case x86::Mnemonic::Jecxz:
            case x86::Mnemonic::Jknzd:
            case x86::Mnemonic::Jkzd:
            case x86::Mnemonic::Jl:
            case x86::Mnemonic::Jle:
            case x86::Mnemonic::Jmp:
            case x86::Mnemonic::Jnb:
            case x86::Mnemonic::Jnbe:
            case x86::Mnemonic::Jnl:
            case x86::Mnemonic::Jnle:
            case x86::Mnemonic::Jno:
            case x86::Mnemonic::Jnp:
            case x86::Mnemonic::Jns:
            case x86::Mnemonic::Jnz:
            case x86::Mnemonic::Jo:
            case x86::Mnemonic::Jp:
            case x86::Mnemonic::Jrcxz:
            case x86::Mnemonic::Js:
            case x86::Mnemonic::Jz:
            case x86::Mnemonic::Loop:
            case x86::Mnemonic::Loope:
            case x86::Mnemonic::Loopne:
                return true;
            default:
                break;
        }
        return false;
    }

    InstrGenerator::InstrGenerator(MachineMode mode) noexcept
        : _decoder(mode)
        , _mode(mode)
    {
    }

    InstrGenerator::Result InstrGenerator::generate(
        Instruction::Attribs attribs, Instruction::Mnemonic id, size_t numOps, EncoderOperands&& operands) noexcept
    {
        EncoderResult buf{};

        auto encodeResult = encodeEstimated(
            buf, _mode, static_cast<zasm::Instruction::Attribs>(attribs), static_cast<zasm::Instruction::Mnemonic>(id), numOps,
            operands);
        if (encodeResult != Error::None)
        {
            return zasm::makeUnexpected(encodeResult);
        }

        auto decodeResult = _decoder.decode(buf.data.data(), buf.length, 0);
        if (!decodeResult)
        {
            return zasm::makeUnexpected(decodeResult.error());
        }

        // Exchange back certain operands.
        const auto& decodedInstr = *decodeResult;

        auto newOps = decodedInstr.getOperands();
        const auto opCount = decodedInstr.getOperandCount();
        const auto& vis = decodedInstr.getOperandsVisibility();
        for (size_t i = 0; i < opCount; i++)
        {
            if (vis.get(i) == Operand::Visibility::Hidden)
                continue;

            const auto& opSrc = operands[i];
            if (opSrc.holds<Label>())
            {
                newOps[i] = opSrc;
            }
            else if (const auto* opMem = opSrc.getIf<Mem>(); opMem != nullptr)
            {
                // FIXME: Handle labels in memory operands.
                auto& decodedMemOp = newOps[i].get<Mem>();

                if (opMem->hasLabel())
                {
                    newOps[i] = Mem(
                        opMem->getBitSize(), decodedMemOp.getSegment(), opMem->getLabel(), opMem->getBase(), opMem->getIndex(),
                        opMem->getScale(), opMem->getDisplacement());
                }
            }
            if (opSrc.holds<Imm>())
            {
                const auto id = decodedInstr.getMnemonic();
                if (i == 0 && isImmediateControlFlow(id))
                {
                    newOps[i] = opSrc;
                }
            }
        }

        return zasm::Instruction(
            decodedInstr.getAttribs(), decodedInstr.getMnemonic(), opCount, newOps, decodedInstr.getAccess(), vis,
            decodedInstr.getCPUFlags(), decodedInstr.getCategory(), decodedInstr.getLength());
    }

} // namespace zasm
