#pragma once

#include <cassert>
#include <cstddef>
#include <cstdint>

namespace zasm
{
    enum class BitSize : std::uint8_t
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
        _96,
        _128,
        _160,
        _192,
        _224,
        _256,
        _320,
        _384,
        _512,
        _864,
        _1024,
        _2048,
        _4096,
        _4608,
    };

    /// <summary>
    /// Returns the BitSize enum value for the given number of bits.
    /// </summary>
    /// <typeparam name="T">Type</typeparam>
    /// <param name="numBits">Number of bits</param>
    /// <returns>Number of bits as BitSize</returns>
    constexpr BitSize toBitSize(const unsigned numBits) noexcept
    {
#define SWITCH_BIT(BIT_VALUE)                                                                                                  \
    case BIT_VALUE:                                                                                                            \
        return BitSize::_##BIT_VALUE

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
            SWITCH_BIT(96);
            SWITCH_BIT(128);
            SWITCH_BIT(160);
            SWITCH_BIT(192);
            SWITCH_BIT(224);
            SWITCH_BIT(256);
            SWITCH_BIT(320);
            SWITCH_BIT(384);
            SWITCH_BIT(512);
            SWITCH_BIT(864);
            SWITCH_BIT(1024);
            SWITCH_BIT(2048);
            SWITCH_BIT(4096);
            SWITCH_BIT(4608);
            default:
                assert(false);
        }
#undef SWITCH_BIT
        return BitSize::_0;
    }

    /// <summary>
    /// Returns the number of bits for the given BitSize enum value.
    /// </summary>
    /// <param name="bitSize">Bit Size</param>
    /// <returns>Number of bits</returns>
    constexpr unsigned getBitSize(BitSize bitSize) noexcept
    {
#define SWITCH_BIT(BIT_VALUE)                                                                                                  \
    case BitSize::_##BIT_VALUE:                                                                                                \
        return BIT_VALUE

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
            SWITCH_BIT(96);
            SWITCH_BIT(128);
            SWITCH_BIT(160);
            SWITCH_BIT(192);
            SWITCH_BIT(224);
            SWITCH_BIT(256);
            SWITCH_BIT(320);
            SWITCH_BIT(384);
            SWITCH_BIT(512);
            SWITCH_BIT(864);
            SWITCH_BIT(1024);
            SWITCH_BIT(2048);
            SWITCH_BIT(4096);
            SWITCH_BIT(4608);
            default:
                assert(false);
        }
#undef SWITCH_BIT
        return 0;
    }

} // namespace zasm
