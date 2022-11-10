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
        enum class OperandVisibility : std::uint8_t
        {
            Invalid = 0,
            Explicit,
            Implicit,
            Hidden,
        };

        enum class OperandAccess : std::uint8_t
        {
            None = 0,

            // The operand is read by the instruction.
            Read = (1U << 0),
            // The operand is written by the instruction (must write).
            Write = (1U << 1),
            // The operand is conditionally written by the instruction (may write).
            CondRead = (1U << 2),
            // The operand is conditionally written by the instruction (may write).
            CondWrite = (1U << 3),

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
        struct None final
        {
            static BitSize getBitSize(MachineMode /*unused*/) noexcept
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

        constexpr Operand() noexcept
            : _data{ None{} }
        {
        }

        constexpr Operand(const Operand& other) noexcept

            = default;

        constexpr Operand(Operand&& other) noexcept
            : _data{ std::move(other._data) }
        {
        }

        constexpr Operand(None&& other) noexcept
            : _data{ other }
        {
        }

        constexpr Operand(const None& other) noexcept
            : _data{ other }
        {
        }

        constexpr Operand(Reg&& other) noexcept
            : _data{ std::move(other) }
        {
        }

        constexpr Operand(const Reg& other) noexcept
            : _data{ other }
        {
        }

        constexpr Operand(Mem&& other) noexcept
            : _data{ std::move(other) }
        {
        }

        constexpr Operand(const Mem& other) noexcept
            : _data{ other }
        {
        }

        constexpr Operand(Imm&& other) noexcept
            : _data{ std::move(other) }
        {
        }

        constexpr Operand(const Imm& other) noexcept
            : _data{ other }
        {
        }

        constexpr Operand(Label&& other) noexcept
            : _data{ std::move(other) }
        {
        }

        constexpr Operand(const Label& other) noexcept
            : _data{ other }
        {
        }

        Operand& operator=(Operand&& other) noexcept
        {
            _data = other._data;
            return *this;
        }

        Operand& operator=(const Operand& other) noexcept = default;

        Operand& operator=(None&& other) noexcept
        {
            _data = other;
            return *this;
        }

        Operand& operator=(const None& other) noexcept
        {
            _data = other;
            return *this;
        }

        Operand& operator=(Reg&& other) noexcept
        {
            _data = other;
            return *this;
        }

        Operand& operator=(const Reg& other) noexcept
        {
            _data = other;
            return *this;
        }

        Operand& operator=(Mem&& other) noexcept
        {
            _data = other;
            return *this;
        }

        Operand& operator=(const Mem& other) noexcept
        {
            _data = other;
            return *this;
        }

        Operand& operator=(Imm&& other) noexcept
        {
            _data = other;
            return *this;
        }

        Operand& operator=(const Imm& other) noexcept
        {
            _data = other;
            return *this;
        }

        Operand& operator=(Label&& other) noexcept
        {
            _data = other;
            return *this;
        }

        Operand& operator=(const Label& other) noexcept
        {
            _data = other;
            return *this;
        }

        bool isEmpty() const noexcept
        {
            return std::holds_alternative<Operand::None>(_data);
        }

        template<typename T> T& get()
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

        constexpr std::size_t getTypeIndex() const noexcept
        {
            return _data.index();
        }

        constexpr bool isExchangableType(const Operand& other) const noexcept
        {
            if ((holds<Label>() && other.holds<Imm>()) || (holds<Imm>() && other.holds<Label>()))
            {
                return true;
            }
            return getTypeIndex() == other.getTypeIndex();
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
