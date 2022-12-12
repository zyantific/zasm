#pragma once

#include "operand.hpp"

#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <zasm/core/enumflags.hpp>
#include <zasm/core/packed.hpp>
#include <zasm/program/meta.hpp>

namespace zasm
{
    class Instruction final
    {
        static constexpr std::size_t kMaxOperands = 5;

    public:
        using Mnemonic = InstrMnemonic;
        using Attribs = InstrAttribs;
        using Category = InstrCategory;

        using OperandCount = std::uint8_t;
        using Operands = std::array<Operand, kMaxOperands>;

        using OperandsAccess = Packed<std::uint32_t, Operand::Access, 3>;
        using OperandsVisibility = Packed<std::uint32_t, Operand::Visibility, 3>;

    private:
        Attribs _attribs{};
        Mnemonic _mnemonic{};
        Operands _operands{};
        OperandCount _opCount{};

    public:
        constexpr Instruction() noexcept = default;

        constexpr Instruction(Mnemonic mnemonic) noexcept
            : _attribs{}
            , _mnemonic{ mnemonic }
            , _operands{}
            , _opCount{}
        {
        }

        constexpr Instruction(Mnemonic mnemonic, OperandCount opCount, const Operands& operands) noexcept
            : _attribs{}
            , _mnemonic{ mnemonic }
            , _operands{ operands }
            , _opCount{ opCount }
        {
        }

        constexpr Instruction(Attribs attribs, Mnemonic mnemonic, OperandCount opCount, const Operands& operands) noexcept
            : _attribs{ attribs }
            , _mnemonic{ mnemonic }
            , _operands{ operands }
            , _opCount{ opCount }
        {
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
        template<typename T> constexpr Instruction& setMnemonic(T mnemonic)
        {
            _mnemonic = static_cast<Mnemonic>(mnemonic);
            return *this;
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
        /// <returns>Instruction&</returns>
        constexpr Instruction& addAttribs(Attribs attrib)
        {
            _attribs = _attribs | attrib;
            return *this;
        }

        /// <summary>
        /// Removes architecture specific attributes from the instruction
        /// ex.: x86::Attribs::Lock
        /// </summary>
        /// <param name="attrib">Attributes to remove</param>
        /// <returns>Instruction&</returns>
        constexpr Instruction& removeAttribs(Attribs attrib)
        {
            _attribs = _attribs & ~attrib;
            return *this;
        }

        constexpr const Operands& getOperands() const noexcept
        {
            return _operands;
        }

        constexpr std::size_t getOperandCount() const noexcept
        {
            return _opCount;
        }

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

        template<typename T> constexpr const T* getOperandIf(std::size_t index) const noexcept
        {
            if (index >= _opCount || index >= _operands.size())
            {
                return nullptr;
            }

            const auto& operand = _operands[index];
            return operand.template getIf<T>();
        }

        template<typename T> constexpr T* getOperandIf(std::size_t index) noexcept
        {
            if (index >= _opCount || index >= _operands.size())
            {
                return nullptr;
            }
            auto& operand = _operands[index];
            return operand.template getIf<T>();
        }

        constexpr Instruction& addOperand(const Operand& val) noexcept
        {
            assert(_opCount < _operands.size());
            if (_opCount < _operands.size())
            {
                _operands[_opCount] = val;
                _opCount++;
            }
            return *this;
        }

        constexpr Instruction& setOperand(std::size_t index, const Operand& val) noexcept
        {
            assert(index < _opCount);
            if (index < _opCount)
            {
                auto& op = _operands[index];
                op = val;
            }
            return *this;
        }
    };

    class InstructionInfo final
    {
        static constexpr std::size_t kMaxOperands = 10;

    public:
        using Length = std::uint8_t;
        using OperandCount = Instruction::OperandCount;
        using Category = Instruction::Category;
        using Attribs = Instruction::Attribs;
        using Mnemonic = Instruction::Mnemonic;
        using Operands = std::array<Operand, kMaxOperands>;

        using OperandsAccess = Packed<std::uint32_t, Operand::Access, 3>;
        using OperandsVisibility = Packed<std::uint32_t, Operand::Visibility, 3>;

        struct CPUFlags
        {
            std::uint32_t set1;
            std::uint32_t set0;
            std::uint32_t modified;
            std::uint32_t tested;
            std::uint32_t undefined;
        };

    private:
        OperandsAccess _access{};
        OperandsVisibility _opsVisibility{};
        Operands _operands{};
        CPUFlags _cpuFlags{};
        Mnemonic _mnemonic{};
        Attribs _attribs{};
        OperandCount _opCount{};
        Category _category{};
        Length _length{};

    public:
        constexpr InstructionInfo() noexcept = default;
        constexpr InstructionInfo(
            Instruction::Attribs attribs, Mnemonic mnemonic, OperandCount opCount, const Operands& operands,
            const OperandsAccess& access, const OperandsVisibility& opsVisibility, const CPUFlags& flags,
            const Category& category, Length length = 0) noexcept
            : _access{ access }
            , _opsVisibility{ opsVisibility }
            , _operands{ operands }
            , _cpuFlags{ flags }
            , _mnemonic{ mnemonic }
            , _attribs{ attribs }
            , _opCount{ opCount }
            , _category{ category }
            , _length{ length }
        {
        }

        /// <summary>
        /// Returns the architecture specific mnemonic for this instructions ex.: x86::Mnemonic::Mov
        /// </summary>
        constexpr Mnemonic getMnemonic() const noexcept
        {
            return _mnemonic;
        }

        /// <summary>
        /// Returns the architecture specific attributes this instruction currently has
        /// ex.: x86::Attribs::Lock
        /// </summary>
        /// <returns>Attribs</returns>
        constexpr Instruction::Attribs getAttribs() const noexcept
        {
            return _attribs;
        }

        /// <summary>
        /// Returns true if the specified attribute is set.
        /// </summary>
        /// <param name="attrib">Attribute to check</param>
        /// <returns>True if set.</returns>
        template<typename T> constexpr bool hasAttrib(T attrib) const noexcept
        {
            static_assert(std::is_enum_v<T> || std::is_integral_v<T>, "Type must be integral or enum");

            return (static_cast<uint32_t>(_attribs) & static_cast<uint32_t>(attrib)) != 0U;
        }

        constexpr Category getCategory() const noexcept
        {
            return _category;
        }

        /// <summary>
        /// Returns the length of the instruction, if this is not from the decoder
        /// it will be an estimate with worst case size.
        /// </summary>
        /// <returns>Length of instruction if available</returns>
        constexpr Length getLength() const noexcept
        {
            return _length;
        }

        constexpr const Operands& getOperands() const noexcept
        {
            return _operands;
        }

        constexpr Operands& getOperands() noexcept
        {
            return _operands;
        }

        constexpr std::size_t getOperandCount() const noexcept
        {
            return _opCount;
        }

        /// <summary>
        /// Returns the amount of operands that are not hidden.
        /// </summary>
        constexpr OperandCount getVisibleOperandCount() const noexcept
        {
            auto opCount = _opCount;
            while (opCount > 0 && _opsVisibility.get(opCount - 1) == Operand::Visibility::Hidden)
            {
                --opCount;
            }
            return opCount;
        }

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

        template<typename T> constexpr const T* getOperandIf(std::size_t index) const noexcept
        {
            if (index >= _opCount || index >= _operands.size())
            {
                return nullptr;
            }

            const auto& operand = _operands[index];
            return operand.template getIf<T>();
        }

        constexpr const OperandsVisibility& getOperandsVisibility() const noexcept
        {
            return _opsVisibility;
        }

        constexpr Operand::Visibility getOperandVisibility(std::size_t index) const noexcept
        {
            if (index >= _opCount)
            {
                return Operand::Visibility::Invalid;
            }
            return _opsVisibility.get(index);
        }

        constexpr bool isOperandHidden(std::size_t index) const noexcept
        {
            return getOperandVisibility(index) == Operand::Visibility::Hidden;
        }

        constexpr bool isOperandExplicit(std::size_t index) const noexcept
        {
            return getOperandVisibility(index) == Operand::Visibility::Explicit;
        }

        constexpr bool isOperandImplicit(std::size_t index) const noexcept
        {
            return getOperandVisibility(index) == Operand::Visibility::Implicit;
        }

        constexpr Operand::Access getOperandAccess(std::size_t index) const noexcept
        {
            if (index >= _opCount)
            {
                return Operand::Access::None;
            }
            return _access.get(index);
        }

        constexpr const OperandsAccess& getOperandsAccess() const noexcept
        {
            return _access;
        }

        constexpr const CPUFlags& getCPUFlags() const noexcept
        {
            return _cpuFlags;
        }

        constexpr Instruction getInstruction() const
        {
            const auto& ops = getOperands();
            return Instruction(
                getAttribs(), getMnemonic(), getVisibleOperandCount(), { ops[0], ops[1], ops[2], ops[3], ops[4] });
        }
    };

} // namespace zasm
