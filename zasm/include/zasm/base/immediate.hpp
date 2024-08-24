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
        std::int64_t _value;

    public:
        constexpr Imm() noexcept
            : _value{}
        {
        }
        constexpr Imm(std::uint32_t imm) noexcept
            : _value{ static_cast<std::int32_t>(imm) }
        {
        }
        constexpr Imm(std::int32_t imm) noexcept
            : _value{ imm }
        {
        }
        constexpr Imm(std::int64_t imm) noexcept
            : _value{ imm }
        {
        }
        constexpr Imm(std::uint64_t imm) noexcept
            : _value{ static_cast<std::int64_t>(imm) }
        {
        }

        constexpr bool operator==(const Imm& other) const noexcept
        {
            return _value == other._value;
        }

        constexpr bool operator!=(const Imm& other) const noexcept
        {
            return _value != other._value;
        }

        template<typename T> constexpr T value() const noexcept
        {
            return static_cast<T>(_value);
        }

        template<typename T> Imm& setValue(const T val)
        {
            _value = static_cast<std::int64_t>(val);

            return *this;
        }

        constexpr BitSize getBitSize() const noexcept
        {
            if (math::abs(_value) > std::numeric_limits<std::uint32_t>::max())
            {
                return BitSize::_64;
            }
            if (math::abs(_value) > std::numeric_limits<std::uint16_t>::max())
            {
                return BitSize::_32;
            }
            if (math::abs(_value) > std::numeric_limits<std::uint8_t>::max())
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
