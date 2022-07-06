#pragma once

#include "immediate.hpp"
#include "label.hpp"
#include "memory.hpp"
#include "register.hpp"

#include <cstdint>
#include <variant>
#include <zasm/core/enumflags.hpp>

namespace zasm
{
    namespace detail
    {
        enum class OperandVisibility : uint8_t
        {
            Invalid = 0,
            Explicit,
            Implicit,
            Hidden,
        };

        enum class OperandAccess : uint8_t
        {
            None = 0,

            // The operand is read by the instruction.
            Read = (1u << 0),
            // The operand is written by the instruction (must write).
            Write = (1u << 1),
            // The operand is conditionally written by the instruction (may write).
            CondRead = (1u << 2),
            // The operand is conditionally written by the instruction (may write).
            CondWrite = (1u << 3),

            // The operand is read (must read) and written by the instruction (must write).
            ReadWrite = (Read | Write),
            // The operand is conditionally read (may read) and conditionally written by the instruction (may write).
            CondReadCondWrite = (CondRead | CondWrite),
            // The operand is read (must read) and conditionally written by the instruction (may read).
            ReadCondWrite = (Read | CondWrite),
            // The operand is written (must write) and conditionally read by the instruction (may read).
            CondReadWrite = (CondRead | Write),

            // Masks
            MaskRead = (Read | CondRead),
            MaskWrite = (Write | CondWrite),
        };
        ZASM_ENABLE_ENUM_OPERATORS(OperandAccess);

    } // namespace detail

    class Operand
    {
    public:
        struct None
        {
            BitSize getBitSize(MachineMode) const noexcept
            {
                return BitSize::_0;
            }
        };

    private:
        using Variant = std::variant<None, Reg, Mem, Imm, Label>;
        Variant _data;

    public:
        using Visibility = detail::OperandVisibility;
        using Access = detail::OperandAccess;

    public:
        constexpr Operand() noexcept
            : _data{ None{} }
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
            : _data{ std::move(val) }
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

        template<typename T> const T& get() const
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

        template<typename T> const T* getIf() const noexcept
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return this;
            }
            else
            {
                return std::get_if<T>(&_data);
            }
            return nullptr;
        }

        template<typename T> constexpr bool holds() const noexcept
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return true;
            }
            else
            {
                return std::holds_alternative<T>(_data);
            }
            return false;
        }

        template<typename F> constexpr auto visit(F&& f) const
        {
            return std::visit(std::forward<F>(f), _data);
        }

        BitSize getBitSize(MachineMode mode) const noexcept
        {
            return visit([mode](auto&& op) { return op.getBitSize(mode); });
        }
    };

} // namespace zasm
