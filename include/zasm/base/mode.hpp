#pragma once

#include <cstdint>

namespace zasm
{
    enum class MachineMode : uint8_t
    {
        I386,
        AMD64,
    };

} // namespace zasm
