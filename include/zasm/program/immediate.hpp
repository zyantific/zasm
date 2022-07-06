#pragma once

#include <cstdint>
#include <limits>
#include <zasm/base/mode.hpp>
#include <zasm/core/bitsize.hpp>

namespace zasm
{
    class Imm
    {
        union
        {
            int64_t s;
            uint64_t u;
        };

    public:
        constexpr Imm() noexcept
            : s{}
        {
        }
        constexpr Imm(uint32_t imm) noexcept
            : u{ imm }
        {
        }
        constexpr Imm(int32_t imm) noexcept
            : s{ imm }
        {
        }
        constexpr Imm(int64_t imm) noexcept
            : s{ imm }
        {
        }
        constexpr Imm(uint64_t imm) noexcept
            : u{ imm }
        {
        }

        template<typename T> constexpr T value() const noexcept
        {
            return static_cast<T>(s);
        }

        BitSize getBitSize() const noexcept
        {
            if (s > std::numeric_limits<int32_t>::max())
                return BitSize::_64;
            if (s > std::numeric_limits<int16_t>::max())
                return BitSize::_32;
            if (s > std::numeric_limits<int8_t>::max())
                return BitSize::_16;
            return BitSize::_8;
        }

        BitSize getBitSize(MachineMode) const noexcept
        {
            return getBitSize();
        }
    };

    namespace detail
    {
        template<typename T> class ImmT : public Imm
        {
        public:
            template<typename T2>
            constexpr ImmT(const T2 val) noexcept
                : Imm(static_cast<T>(val))
            {
            }
        };
    } // namespace detail

    /// <summary>
    /// Helpers to avoid casts.
    /// </summary>
    using Imm64 = detail::ImmT<int64_t>;
    using Imm32 = detail::ImmT<int32_t>;
    using Imm16 = detail::ImmT<int16_t>;
    using Imm8 = detail::ImmT<int8_t>;

} // namespace zasm
