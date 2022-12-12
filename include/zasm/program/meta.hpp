#pragma once

#include <cstdint>
#include <zasm/core/strongtype.hpp>

namespace zasm
{
    using InstrCategory = StrongType<std::uint8_t>;

    using InstrAttribs = StrongType<std::uint32_t>;

    using InstrMnemonic = StrongType<std::uint16_t>;

} // namespace zasm
