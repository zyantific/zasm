#pragma once

#include "zasm/base/mode.hpp"
#include "zasm/core/expected.hpp"
#include "zasm/decoder/decoder.hpp"
#include "zasm/encoder/encoder.hpp"
#include "zasm/program/instruction.hpp"
#include "zasm/x86/instruction.hpp"

namespace zasm
{
    class InstrGenerator
    {
        Decoder _decoder;
        MachineMode _mode;

    public:
        using Result = zasm::Expected<zasm::Instruction, Error>;

        InstrGenerator(MachineMode mode) noexcept;

        // Generates an instruction without context.
        // This is primarily used by the assembler to obtain all relevant meta data.
        // Some operands will encode temporary values and switched back after decoding.
        Result generate(
            Instruction::Attribs attribs, Instruction::Mnemonic mnemonic, size_t numOps, EncoderOperands&& operands);
    };

} // namespace zasm
