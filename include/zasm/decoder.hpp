#pragma once

#include "errors.hpp"
#include "expected.hpp"
#include "instruction.hpp"

namespace zasm
{

    using DecoderResult = zasm::Expected<Instruction, Error>;

    DecoderResult decode(ZydisMachineMode mode, const void* data, const size_t len, uint64_t va);

} // namespace zasm