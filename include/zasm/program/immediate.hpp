#pragma once

#include <cstdint>
#include <limits>
#include <zasm/base/mode.hpp>
#include <zasm/core/bitsize.hpp>
#include <zasm/core/math.hpp>

namespace zasm
{
    class Imm 
    {
        union
        {
            std::int64_t s;
            std::uint64_t u;
        };

    public:
        constexpr Imm() noexcept
            : s{}
        {
        }
        constexpr Imm(std::uint32_t imm) noexcept
            : u{ imm }
        {
        }
        constexpr Imm(std::int32_t imm) noexcept
            : s{ imm }
        {
        }
        constexpr Imm(std::int64_t imm) noexcept
            : s{ imm }
        {
        }
        constexpr Imm(std::uint64_t imm) noexcept
            : u{ imm }
        {
        }

        constexpr bool operator==(const Imm& other) const noexcept
        {
            return u == other.u;
        }

        constexpr bool operator!=(const Imm& other) const noexcept
        {
            return u != other.u;
        }

        template<typename T> constexpr T value() const noexcept
        {
            return static_cast<T>(s);
        }

        template<typename T> Imm& setValue(const T val)
        {
            s = static_cast<std::int64_t>(val);

            return *this;
        }

        constexpr BitSize getBitSize() const noexcept
        {
            if (math::abs(s) > std::numeric_limits<std::uint32_t>::max())
            {
                return BitSize::_64;
            }
            if (math::abs(s) > std::numeric_limits<std::uint16_t>::max())
            {
                return BitSize::_32;
            }
            if (math::abs(s) > std::numeric_limits<std::uint8_t>::max())
            {
                return BitSize::_16;
            }
            return BitSize::_8;
        }

        constexpr BitSize getBitSize([[maybe_unused]] MachineMode mode) const noexcept
        {
            return getBitSize();
        }
    };

    namespace detail
    {
        template<typename T> class ImmT final : public Imm 
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
    using Imm64 = detail::ImmT<std::int64_t>;
    using Imm32 = detail::ImmT<std::int32_t>;
    using Imm16 = detail::ImmT<std::int16_t>;
    using Imm8 = detail::ImmT<std::int8_t>;

} // namespace zasm
