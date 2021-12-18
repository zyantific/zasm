#pragma once

#include "zasm/decoder.hpp"
#include "zasm/encoder.hpp"
#include "zasm/expected.hpp"

namespace zasm
{
    using GeneratorResult = xstd::expected<Instruction, Error>;

    GeneratorResult generator(
        ZydisMachineMode mode, Instruction::Attribs prefixes, ZydisMnemonic mnemonic, const Instruction::Operands& operands);

} // namespace zasm