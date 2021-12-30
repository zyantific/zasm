#pragma once

#include <cstdint>

namespace zasm::operands
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
    };

    namespace detail {
        template<typename T> class ImmT : public Imm
        {
        public:
            template<typename T2>
            constexpr ImmT(const T2 val) noexcept
                : Imm(static_cast<T>(val))
            {
            }
        };
    }

    /// <summary>
    /// Helpers to avoid casts.
    /// </summary>
    using Imm64 = detail::ImmT<int64_t>;
    using Imm32 = detail::ImmT<int32_t>;
    using Imm16 = detail::ImmT<int16_t>;
    using Imm8 = detail::ImmT<int8_t>;

} // namespace zasm::operands