#pragma once

#include "zasm/core/expected.hpp"
#include "zasm/decoder/decoder.hpp"
#include "zasm/encoder/encoder.hpp"

namespace zasm
{
    class InstrGenerator
    {
        Decoder _decoder;
        ZydisMachineMode _mode;

    public:
        using Result = zasm::Expected<Instruction, Error>;

        InstrGenerator(ZydisMachineMode mode) noexcept;

        // Generates an instruction without context.
        // This is primarily used by the assembler to obtain all relevant meta data.
        // Some operands will encode temporary values and switched back after decoding.
        Result generate(
            Instruction::Attribs attribs, ZydisMnemonic mnemonic, size_t numOps, EncoderOperands&& operands) noexcept;
    };

} // namespace zasm