#include <array>
#include <cassert>
#include <tuple>
#include <variant>
#include <zasm/base/mode.hpp>
#include <zasm/decoder/decoder.hpp>
#include <zasm/encoder/encoder.hpp>
#include <zasm/program/operand.hpp>
#include <zasm/x86/memory.hpp>
#include <zasm/x86/meta.hpp>
#include <zasm/x86/mnemonic.hpp>
#include <zasm/x86/register.hpp>

namespace zasm::x86
{
    static thread_local Decoder _decoderI386(MachineMode::I386);
    static thread_local Decoder _decoderAMD64(MachineMode::AMD64);

    static Decoder* getDecoder(MachineMode mode) noexcept
    {
        switch (mode)
        {
            case MachineMode::I386:
                return &_decoderI386;
            case MachineMode::AMD64:
                return &_decoderAMD64;
            default:
                break;
        }
        return nullptr;
    }

    zasm::Expected<zasm::InstructionInfo, zasm::Error> getInstructionInfo(MachineMode mode, const Instruction& instr)
    {
        const auto& operands = instr.getOperands();
        const auto opCount = instr.getOperandCount();

        auto encodeResult = encode(mode, instr.getAttribs(), instr.getMnemonic(), opCount, operands.data());
        if (!encodeResult)
        {
            return zasm::makeUnexpected(encodeResult.error());
        }

        Decoder* decoder = getDecoder(mode);
        assert(decoder != nullptr);

        auto decodeResult = decoder->decode(encodeResult->data.data(), encodeResult->length, 0);
        if (!decodeResult)
        {
            return zasm::makeUnexpected(decodeResult.error());
        }

        zasm::InstructionInfo& decoded = *decodeResult;

        if (decoded.getVisibleOperandCount() != opCount)
        {
            return zasm::makeUnexpected(Error::InvalidOperation);
        }

        // Replace the decoded operands with user specified operands.
        auto& dstOps = decoded.getOperands();
        for (std::size_t i = 0; i < opCount; i++)
        {           
            const auto& opSrc = operands[i];
            if (opSrc.holds<Mem>() && dstOps[i].holds<Mem>())
            {
                const auto& seg = dstOps[i].get<Mem>().getSegment();
                dstOps[i] = operands[i];
                dstOps[i].get<Mem>().setSegment(seg);
            }
            else
            {
                dstOps[i] = operands[i];
            }
        }

        return decoded;
    }

} // namespace zasm::x86
