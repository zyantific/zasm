#include "generator.hpp"

namespace zasm
{
    // FIXME: Duplicate code, move this somewhere.
    static bool isImmediateControlFlow(ZydisMnemonic mnemonic)
    {
        switch (mnemonic)
        {
            case ZYDIS_MNEMONIC_CALL:
            case ZYDIS_MNEMONIC_JB:
            case ZYDIS_MNEMONIC_JBE:
            case ZYDIS_MNEMONIC_JCXZ:
            case ZYDIS_MNEMONIC_JECXZ:
            case ZYDIS_MNEMONIC_JKNZD:
            case ZYDIS_MNEMONIC_JKZD:
            case ZYDIS_MNEMONIC_JL:
            case ZYDIS_MNEMONIC_JLE:
            case ZYDIS_MNEMONIC_JMP:
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
            case ZYDIS_MNEMONIC_LOOP:
            case ZYDIS_MNEMONIC_LOOPE:
            case ZYDIS_MNEMONIC_LOOPNE:
                return true;
        }
        return false;
    }

    // Generates an instruction without context.
    // This is primarily used by the assembler to obtain all relevant meta data.
    // Some operands will encode temporary values and switched back after decoding.
    GeneratorResult generator(
        ZydisMachineMode mode, Instruction::Attribs attribs, ZydisMnemonic mnemonic, const Instruction::Operands& operands)
    {
        EncoderBuffer buf{};

        auto encodeResult = encodeEstimated(buf, mode, attribs, mnemonic, operands);
        if (encodeResult != Error::None)
        {
            return zasm::makeUnexpected(encodeResult);
        }

        auto decodeResult = decode(mode, buf.data.data(), buf.length, 0);
        if (!decodeResult)
        {
            return zasm::makeUnexpected(decodeResult.error());
        }

        // Exchange back certain operands.
        const auto& decodedInstr = *decodeResult;

        auto newOps = decodedInstr.getOperands();
        const auto& vis = decodedInstr.getVisibility();
        for (size_t i = 0; i < operands.size(); i++)
        {
            if (vis[i] != OperandVisibility::Explicit)
                continue;

            const auto& opSrc = operands[i];
            if (std::holds_alternative<operands::Label>(opSrc))
            {
                newOps[i] = opSrc;
            }
            else if (const auto* opMem = std::get_if<operands::Mem>(&opSrc); opMem != nullptr)
            {
                // FIXME: Handle labels in memory operands.
                if (opMem->hasLabel())
                {
                    newOps[i] = opSrc;
                }
            }
            if (std::holds_alternative<operands::Imm>(opSrc))
            {
                if (i == 0 && isImmediateControlFlow(decodedInstr.getId()))
                {
                    newOps[i] = opSrc;
                }
            }
        }

        return Instruction(
            decodedInstr.getAttribs(), decodedInstr.getId(), newOps, decodedInstr.getAccess(), vis, decodedInstr.getFlags(),
            decodedInstr.getLength());
    }

} // namespace zasm