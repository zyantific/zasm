#pragma once

#include "expected.hpp"
#include "instruction.hpp"
#include "errors.hpp"

namespace zasm
{

    using DecoderResult = xstd::expected<Instruction, Error>;

    DecoderResult decode(ZydisMachineMode mode, const void* data, const size_t len, uint64_t va);

} // namespace zasm