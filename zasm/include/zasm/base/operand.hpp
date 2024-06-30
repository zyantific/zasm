#pragma once

#include <cstdint>
#include <variant>
#include <zasm/base/immediate.hpp>
#include <zasm/base/label.hpp>
#include <zasm/base/memory.hpp>
#include <zasm/base/register.hpp>
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
            // The operand is conditionally read by the instruction (may read).
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
            static BitSize getBitSize(MachineMode) noexcept
            {
                return BitSize::_0;
            }

            constexpr bool operator==(const None& other) const noexcept
            {
                return true;
            }

            constexpr bool operator!=(const None& other) const noexcept
            {
                return false;
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

        constexpr Operand(const Operand& other) noexcept = default;

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

        constexpr bool operator==(const Operand& other) const noexcept
        {
            if (_data.index() != other._data.index())
                return false;
            const auto isEq = std::visit(
                [&](auto&& lhs) { return lhs == std::get<std::decay_t<decltype(lhs)>>(other._data); }, _data);
            return isEq;
        }

        constexpr bool operator!=(const Operand& other) const noexcept
        {
            return _data != other._data;
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

        /// <summary>
        /// Returns true if the operands holds nothing.
        /// </summary>
        /// <returns>True if the operand is not set.</returns>
        bool isEmpty() const noexcept
        {
            return std::holds_alternative<Operand::None>(_data);
        }

        /// <summary>
        /// Returns a reference with given type, throws if type mismatches.
        /// </summary>
        /// <typeparam name="T">Operand Type</typeparam>
        /// <returns>Reference to operand or throws std::bad_variant_access if type mismatches</returns>
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

        /// <summary>
        /// Returns a reference with given type, throws if type mismatches.
        /// </summary>
        /// <typeparam name="T">Operand Type</typeparam>
        /// <returns>Reference to operand or throws std::bad_variant_access if type mismatches</returns>
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

        /// <summary>
        /// Returns a pointer with the type specified if the type matches.
        /// </summary>
        /// <typeparam name="T">Operand Type</typeparam>
        /// <returns>Returns T* if type matches nullptr otherwise</returns>
        template<typename T> T* getIf() noexcept
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

        /// <summary>
        /// Returns a pointer with the type specified if the type matches.
        /// </summary>
        /// <typeparam name="T">Type to test</typeparam>
        /// <returns>Returns T* if type matches nullptr otherwise</returns>
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

        /// <summary>
        /// Checks if the operand holds the specified type.
        /// </summary>
        /// <typeparam name="T">Operand Type</typeparam>
        /// <returns>True if the operand holds the specified type.</returns>
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

        /// <summary>
        /// Returns the current internal index for the operand type.
        /// This may change from version to version.
        /// </summary>
        /// <returns>Index of the operand type</returns>
        constexpr std::size_t getTypeIndex() const noexcept
        {
            return _data.index();
        }

        /// <summary>
        /// Checks if the operand can be exchanged without changing the encoding.
        /// Currently this only applies to Imm and Label operands.
        /// </summary>
        /// <param name="other">Other operand to check</param>
        /// <returns>True if this operand can be exchanged with the other operand</returns>
        constexpr bool isExchangableType(const Operand& other) const noexcept
        {
            if ((holds<Label>() && other.holds<Imm>()) || (holds<Imm>() && other.holds<Label>()))
            {
                return true;
            }
            return getTypeIndex() == other.getTypeIndex();
        }

        /// <summary>
        /// Works like std::visit, calls the specified function with the current operand type.
        /// </summary>
        /// <typeparam name="F">Visitor</typeparam>
        /// <param name="f">Visitor</param>
        /// <returns>Result of the visitor</returns>
        template<typename F> constexpr auto visit(F&& f) const
        {
            return std::visit(std::forward<F>(f), _data);
        }

        /// <summary>
        /// Returns the size of the operand, some operands can have different sizes
        /// depending on the machine mode.
        /// </summary>
        /// <param name="mode">Machine mode</param>
        /// <returns>Size of the operand in bits</returns>
        BitSize getBitSize(MachineMode mode) const noexcept
        {
            return visit([mode](auto&& op) { return op.getBitSize(mode); });
        }
    };

} // namespace zasm
