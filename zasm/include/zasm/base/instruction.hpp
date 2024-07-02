#pragma once

#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <zasm/base/meta.hpp>
#include <zasm/base/mode.hpp>
#include <zasm/base/operand.hpp>

namespace zasm
{
    /// <summary>
    /// Base type for Instruction and InstructionDetail, not to be used directly.
    /// </summary>
    template<typename TBase, std::size_t TMaxOperands> class InstructionBase
    {
    public:
        using Length = std::uint8_t;
        using Mnemonic = InstrMnemonic;
        using Attribs = InstrAttribs;
        using Category = InstrCategory;

        using OperandCount = std::uint8_t;
        using Operands = std::array<Operand, TMaxOperands>;

    protected:
        Attribs _attribs{};
        OperandCount _opCount{};
        Mnemonic _mnemonic{};
        Operands _operands{};

    protected:
        constexpr InstructionBase() = default;
        constexpr InstructionBase(Attribs attribs, Mnemonic mnemonic, OperandCount opCount, const Operands& ops) noexcept
            : _attribs{ attribs }
            , _opCount{ opCount }
            , _mnemonic{ mnemonic }
            , _operands{ ops }
        {
        }

    public:
        constexpr bool operator==(const InstructionBase& other) const
        {
            return _attribs == other._attribs && _mnemonic == other._mnemonic && _opCount == other._opCount
                && _operands == other._operands;
        }

        constexpr bool operator!=(const InstructionBase& other) const
        {
            return !(*this == other);
        }

        /// <summary>
        /// Returns the architecture specific mnemonic for this instructions ex.: x86::Mnemonic::Mov
        /// </summary>
        constexpr Mnemonic getMnemonic() const noexcept
        {
            return _mnemonic;
        }

        /// <summary>
        /// Sets a new mnemonic for this instructions, this must be one of the architecture defined mnemonic
        /// ex.: x86::Mnemonic::Mov
        /// </summary>
        /// <param name="mnemonic">New mnemonic</param>
        /// <returns>Instruction&</returns>
        template<typename T> constexpr TBase& setMnemonic(T mnemonic)
        {
            _mnemonic = static_cast<Mnemonic>(mnemonic);
            return static_cast<TBase&>(*this);
        }

        /// <summary>
        /// Returns the architecture specific attributes this instruction currently has
        /// ex.: x86::Attribs::Lock
        /// </summary>
        /// <returns>Attribs</returns>
        constexpr Attribs getAttribs() const noexcept
        {
            return _attribs;
        }

        /// <summary>
        /// Returns true if the specified attribute is set.
        /// </summary>
        /// <param name="attrib">Attribute to check</param>
        /// <returns>True if set.</returns>
        constexpr bool hasAttrib(Attribs attrib) const noexcept
        {
            return (_attribs & attrib) != Attribs{};
        }

        /// <summary>
        /// Adds new architecture specific attributes to the instruction
        /// ex.: x86::Attribs::Lock
        /// </summary>
        /// <param name="attrib">Attributes to add</param>
        /// <returns>*this</returns>
        constexpr TBase& addAttribs(Attribs attrib)
        {
            _attribs = _attribs | attrib;
            return static_cast<TBase&>(*this);
        }

        /// <summary>
        /// Removes architecture specific attributes from the instruction
        /// ex.: x86::Attribs::Lock
        /// </summary>
        /// <param name="attrib">Attributes to remove</param>
        /// <returns>*this</returns>
        constexpr TBase& removeAttribs(Attribs attrib)
        {
            _attribs = _attribs & ~attrib;
            return static_cast<TBase&>(*this);
        }

        /// <summary>
        /// Adds a new operand to the instruction increasing the operand count by one.
        /// </summary>
        /// <param name="val">New operand</param>
        /// <returns>*this</returns>
        constexpr TBase& addOperand(const Operand& val) noexcept
        {
            assert(_opCount < _operands.size());
            if (_opCount < _operands.size())
            {
                _operands[_opCount] = val;
                _opCount++;
            }
            return static_cast<TBase&>(*this);
        }

        /// <summary>
        /// Sets the operand at the specified index, an already existing operand must exist at the index otherwise its a no-op.
        /// </summary>
        /// <param name="index"></param>
        /// <param name="val"></param>
        /// <returns>*this</returns>
        constexpr TBase& setOperand(std::size_t index, const Operand& val) noexcept
        {
            assert(index < _opCount);
            if (index < _opCount)
            {
                auto& op = _operands[index];
                op = val;
            }
            return static_cast<TBase&>(*this);
        }

        /// <summary>
        /// Returns the array to the operands storage, use getOperandCount to get the amount of used operands.
        /// </summary>
        /// <returns>Reference to operands</returns>
        constexpr const Operands& getOperands() const noexcept
        {
            return _operands;
        }

        /// <summary>
        /// Returns the array to the operands storage, use getOperandCount to get the amount of used operands.
        /// </summary>
        /// <returns>Reference to operands</returns>
        constexpr Operands& getOperands() noexcept
        {
            return _operands;
        }

        /// <summary>
        /// Returns the amount of used operands.
        /// </summary>
        /// <returns>Operand count</returns>
        constexpr std::size_t getOperandCount() const noexcept
        {
            return _opCount;
        }

        /// <summary>
        /// Returns the a reference to the operand at the specified compile time index if it is of the specified type T,
        /// </summary>
        /// <typeparam name="T">Expected operand type</typeparam>
        /// <typeparam name="TIndex">Operand index</typeparam>
        /// <returns>Reference to operand as T</returns>
        template<std::size_t TIndex, typename T = Operand> constexpr const T& getOperand() const
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return std::get<TIndex>(_operands);
            }
            else
            {
                const auto& operand = std::get<TIndex>(_operands);
                return operand.template get<T>();
            }
        }

        /// <summary>
        /// Returns the a reference to the operand at the specified compile time index if it is of the specified type T,
        /// </summary>
        /// <typeparam name="T">Expected operand type</typeparam>
        /// <typeparam name="TIndex">Operand index</typeparam>
        /// <returns>Reference to operand as T</returns>
        template<std::size_t TIndex, typename T = Operand> constexpr T& getOperand()
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return std::get<TIndex>(_operands);
            }
            else
            {
                auto& operand = std::get<TIndex>(_operands);
                return operand.template get<T>();
            }
        }

        /// <summary>
        /// Returns the a reference to the operand at the specified index if it is of the specified type T,
        /// will throw if the type does not match.
        /// </summary>
        /// <typeparam name="T">Expected operand type</typeparam>
        /// <param name="index">Operand index</param>
        /// <returns>A reference to the operand as T</returns>
        template<typename T = Operand> constexpr const T& getOperand(std::size_t index) const
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return _operands[index];
            }
            else
            {
                const auto& operand = _operands[index];
                return operand.template get<T>();
            }
        }

        /// <summary>
        /// Returns the a reference to the operand at the specified index if it is of the specified type T,
        /// will throw if the type does not match.
        /// </summary>
        /// <typeparam name="T">Expected operand type</typeparam>
        /// <param name="index">Operand index</param>
        /// <returns>A reference to the operand as T</returns>
        template<typename T = Operand> constexpr T& getOperand(std::size_t index)
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return _operands[index];
            }
            else
            {
                auto& op = _operands[index];
                return op.template get<T>();
            }
        }

        /// <summary>
        /// Returns the operand at the specified index if it is of the specified type T, otherwise nullptr.
        /// </summary>
        /// <typeparam name="T">Expected operand type</typeparam>
        /// <param name="index">Operand index</param>
        /// <returns>The operand as T if the type matches, otherwise nullptr</returns>
        template<typename T> constexpr const T* getOperandIf(std::size_t index) const noexcept
        {
            if (index >= _opCount || index >= _operands.size())
            {
                return nullptr;
            }

            const auto& operand = _operands[index];
            return operand.template getIf<T>();
        }

        /// <summary>
        /// Returns the operand at the specified index if it is of the specified type T, otherwise nullptr.
        /// </summary>
        /// <typeparam name="T">Expected operand type</typeparam>
        /// <param name="index">Operand index</param>
        /// <returns>The operand as T if the type matches, otherwise nullptr</returns>
        template<typename T> constexpr T* getOperandIf(std::size_t index) noexcept
        {
            if (index >= _opCount || index >= _operands.size())
            {
                return nullptr;
            }
            auto& operand = _operands[index];
            return operand.template getIf<T>();
        }

        /// <summary>
        /// Checks if the operand at the specified index is of the specified type T.
        /// </summary>
        /// <typeparam name="T">The type to check</typeparam>
        /// <param name="index">Operand index</param>
        /// <returns>True if the operand is type T</returns>
        template<typename T> constexpr bool isOperandType(std::size_t index) const noexcept
        {
            if (index >= _opCount || index >= _operands.size())
            {
                return false;
            }
            const auto& operand = _operands[index];
            return operand.template holds<T>();
        }
    };

} // namespace zasm
