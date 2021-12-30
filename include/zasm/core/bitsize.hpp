#pragma once

#include <cassert>
#include <cstdint>
#include <ostream>

namespace zasm
{
    enum class BitSize : uint8_t
    {
        _0,
        _1,
        _2,
        _8,
        _16,
        _32,
        _48,
        _64,
        _80,
        _128,
        _160,
        _256,
        _320,
        _512,
        _1024,
        _2048,
        _4096,
    };

    static constexpr BitSize toBitSize(int32_t numBits) noexcept
    {
#define SWITCH_BIT(n)                                                                                                          \
    case n:                                                                                                                    \
        return BitSize::_##n

        switch (numBits)
        {
            SWITCH_BIT(0);
            SWITCH_BIT(1);
            SWITCH_BIT(2);
            SWITCH_BIT(8);
            SWITCH_BIT(16);
            SWITCH_BIT(32);
            SWITCH_BIT(48);
            SWITCH_BIT(64);
            SWITCH_BIT(80);
            SWITCH_BIT(128);
            SWITCH_BIT(160);
            SWITCH_BIT(256);
            SWITCH_BIT(320);
            SWITCH_BIT(512);
            SWITCH_BIT(1024);
            SWITCH_BIT(2048);
            SWITCH_BIT(4096);
            default:
                assert(false);
        }
#undef SWITCH_BIT
        return BitSize::_0;
    }

    static constexpr int32_t getBitSize(BitSize bitSize) noexcept
    {
#define SWITCH_BIT(n)                                                                                                          \
    case BitSize::_##n:                                                                                                        \
        return n

        switch (bitSize)
        {
            SWITCH_BIT(0);
            SWITCH_BIT(1);
            SWITCH_BIT(2);
            SWITCH_BIT(8);
            SWITCH_BIT(16);
            SWITCH_BIT(32);
            SWITCH_BIT(48);
            SWITCH_BIT(64);
            SWITCH_BIT(80);
            SWITCH_BIT(128);
            SWITCH_BIT(160);
            SWITCH_BIT(256);
            SWITCH_BIT(320);
            SWITCH_BIT(512);
            SWITCH_BIT(1024);
            SWITCH_BIT(2048);
            SWITCH_BIT(4096);
            default:
                assert(false);
        }
#undef SWITCH_BIT
        return 0;
    }

    // gtest support.
    inline std::ostream& operator<<(std::ostream& os, const BitSize& s)
    {
        return os << getBitSize(s) << "_bit";
    }

} // namespace zasm