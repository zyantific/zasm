#pragma once

#include "zasm/decoder/decoder.hpp"
#include "zasm/encoder/encoder.hpp"
#include "zasm/core/expected.hpp"

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
        Result generate(Instruction::Attribs attribs, ZydisMnemonic mnemonic, const Instruction::Operands& operands) noexcept;
    };

} // namespace zasm