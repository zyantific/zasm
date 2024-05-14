#pragma once

#include <cstdint>

namespace zasm
{
    enum class MachineMode : std::uint8_t
    {
        Invalid = 0,
        I386,
        AMD64,
    };

} // namespace zasm
