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
        constexpr Imm()
            : s{}
        {
        }
        constexpr Imm(uint32_t imm)
            : u{ imm }
        {
        }
        constexpr Imm(int32_t imm)
            : s{ imm }
        {
        }
        constexpr Imm(int64_t imm)
            : s{ imm }
        {
        }
        constexpr Imm(uint64_t imm)
            : u{ imm }
        {
        }

        template<typename T> constexpr T value() const noexcept
        {
            return static_cast<T>(s);
        }
    };

} // namespace zasm::operands