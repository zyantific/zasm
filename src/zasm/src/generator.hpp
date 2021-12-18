#pragma once

#include "zasm/decoder.hpp"
#include "zasm/encoder.hpp"
#include "zasm/expected.hpp"

namespace zasm
{
    using GeneratorResult = zasm::Expected<Instruction, Error>;

    GeneratorResult generator(
        ZydisMachineMode mode, Instruction::Attribs attribs, ZydisMnemonic mnemonic, const Instruction::Operands& operands);

} // namespace zasm