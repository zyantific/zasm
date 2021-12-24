#pragma once

#include "immediate.hpp"
#include "label.hpp"
#include "memory.hpp"
#include "register.hpp"

#include <cstdint>
#include <variant>

namespace zasm
{
    namespace operands
    {
        struct None
        {
        };
    } // namespace operands

    class Operand
    {
        using Variant = std::variant<operands::None, operands::Reg, operands::Mem, operands::Imm, operands::Label>;

        Variant _data;

    public:
        constexpr Operand() noexcept
            : _data{ operands::None{} }
        {
        }
        constexpr Operand(Operand&& other) noexcept
            : _data{ std::move(other._data) }
        {
        }
        constexpr Operand(const Operand& other) noexcept
            : _data{ other._data }
        {
        }

        template<typename T>
        constexpr Operand(const T& val) noexcept
            : _data{ val }
        {
        }

        template<typename T>
        constexpr Operand(T&& val) noexcept
            : _data{ val }
        {
        }

        Operand& operator=(Operand&& other) noexcept
        {
            _data = std::move(other._data);
            return *this;
        }

        Operand& operator=(const Operand& other) noexcept
        {
            _data = other._data;
            return *this;
        }

        template<typename T> const T& as() const
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return *this;
            }
            else
            {
                return std::get<T>(_data);
            }
        }

        template<typename T> const T* tryAs() const noexcept
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return this;
            }
            else
            {
                return std::get_if<T>(&_data);
            }
        }

        template<typename T>
        constexpr bool is() const
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return true;
            }
            else
            {
                return std::holds_alternative<T>(_data);
            }
        }

        template<typename F> auto visit(F&& f) const
        {
            return std::visit([f = std::move(f)](auto&& op) { return f(op); }, _data);
        }
    };

    static constexpr auto SizeOfOperand = sizeof(Operand);

    enum class OperandVisibility : uint8_t
    {
        Invalid = ZYDIS_OPERAND_VISIBILITY_INVALID,
        Explicit = ZYDIS_OPERAND_VISIBILITY_EXPLICIT,
        Implicit = ZYDIS_OPERAND_VISIBILITY_IMPLICIT,
        Hidden = ZYDIS_OPERAND_VISIBILITY_HIDDEN,
    };

} // namespace zasm