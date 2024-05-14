#pragma once

#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <zasm/base/instruction.hpp>
#include <zasm/base/meta.hpp>
#include <zasm/base/mode.hpp>
#include <zasm/base/operand.hpp>
#include <zasm/core/errors.hpp>
#include <zasm/core/expected.hpp>
#include <zasm/core/packed.hpp>

namespace zasm
{
    class InstructionDetail;

    /// <summary>
    /// Lightweight instruction object that represents the instruction signature rather than the full instruction.
    /// </summary>
    class Instruction final : public InstructionBase<Instruction, 5>
    {
    public:
        constexpr Instruction() noexcept = default;

        constexpr Instruction(Mnemonic mnemonic) noexcept
            : InstructionBase({}, mnemonic, {}, {})
        {
        }

        constexpr Instruction(Mnemonic mnemonic, OperandCount opCount, const Operands& operands) noexcept
            : InstructionBase({}, mnemonic, opCount, operands)
        {
        }

        constexpr Instruction(Attribs attribs, Mnemonic mnemonic, OperandCount opCount, const Operands& operands) noexcept
            : InstructionBase(attribs, mnemonic, opCount, operands)
        {
        }

        constexpr bool operator==(const Instruction& other) const
        {
            return InstructionBase::operator==(other);
        }

        constexpr bool operator!=(const Instruction& other) const
        {
            return !(*this == other);
        }

        /// <summary>
        /// Returns InstructionInfo or zasm::Error for given mode and instruction.
        /// </summary>
        Expected<const InstructionDetail, Error> getDetail(MachineMode mode) const;

        static Expected<const InstructionDetail, Error> getDetail(MachineMode mode, const Instruction& instr);
    };

    class InstructionDetail final : public InstructionBase<InstructionDetail, 10>
    {
    public:
        using OperandsAccess = Packed<std::uint32_t, Operand::Access, 3>;
        using OperandsVisibility = Packed<std::uint32_t, Operand::Visibility, 3>;

        struct CPUFlags
        {
            InstrCPUFlags set1{};
            InstrCPUFlags set0{};
            InstrCPUFlags modified{};
            InstrCPUFlags tested{};
            InstrCPUFlags undefined{};

            constexpr bool operator==(const CPUFlags& other) const
            {
                return set1 == other.set1 && set0 == other.set0 && modified == other.modified && tested == other.tested
                    && undefined == other.undefined;
            }

            constexpr bool operator!=(const CPUFlags& other) const
            {
                return !(*this == other);
            }
        };

    private:
        OperandsAccess _access{};
        OperandsVisibility _opsVisibility{};
        CPUFlags _cpuFlags{};
        Category _category{};
        Length _length{};

    public:
        constexpr InstructionDetail() noexcept = default;
        constexpr InstructionDetail(
            Attribs attribs, Mnemonic mnemonic, OperandCount opCount, const Operands& operands, const OperandsAccess& access,
            const OperandsVisibility& opsVisibility, const CPUFlags& flags, const Category& category,
            Length length = 0) noexcept
            : InstructionBase{ attribs, mnemonic, opCount, operands }
            , _access{ access }
            , _opsVisibility{ opsVisibility }
            , _cpuFlags{ flags }
            , _category{ category }
            , _length{ length }
        {
        }

        constexpr bool operator==(const InstructionDetail& other) const
        {
            return InstructionBase::operator==(other) && _access == other._access && _opsVisibility == other._opsVisibility
                && _cpuFlags == other._cpuFlags && _category == other._category && _length == other._length;
        }

        constexpr bool operator!=(const InstructionDetail& other) const
        {
            return !(*this == other);
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

        /// <summary>
        /// Constructs an Instruction object from this InstructionDetail object.
        /// </summary>
        constexpr Instruction getInstruction() const
        {
            const auto& ops = getOperands();
            return Instruction(
                getAttribs(), getMnemonic(), getVisibleOperandCount(), { ops[0], ops[1], ops[2], ops[3], ops[4] });
        }
    };

} // namespace zasm
