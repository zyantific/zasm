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
    /// Lightweight instruction object that represents the instruction signature rather than the full instruction,
    /// this is the type that is stored as a node in the Program to keep the memory footprint low.
    /// </summary>
    class Instruction final : public TInstructionBase<Instruction, 5>
    {
    public:
        static constexpr auto kInstrType = InstructionBase::Type::Signanture;

        constexpr Instruction() noexcept = default;

        constexpr Instruction(Mnemonic mnemonic) noexcept
            : TInstructionBase({}, mnemonic, {}, {})
        {
        }

        constexpr Instruction(Mnemonic mnemonic, OperandCount opCount, const Operands& operands) noexcept
            : TInstructionBase({}, mnemonic, opCount, operands)
        {
        }

        constexpr Instruction(Attribs attribs, Mnemonic mnemonic, OperandCount opCount, const Operands& operands) noexcept
            : TInstructionBase(attribs, mnemonic, opCount, operands)
        {
        }

        constexpr bool operator==(const Instruction& other) const
        {
            return TInstructionBase::operator==(other);
        }

        constexpr bool operator!=(const Instruction& other) const
        {
            return !(*this == other);
        }

        /// <summary>
        /// Returns InstructionDetail or zasm::Error for given mode and instruction.
        /// NOTE: The function is doing a bit of processing, so it should be only called when
        ///       all the instruction details are required.
        /// </summary>
        Expected<InstructionDetail, Error> getDetail(MachineMode mode) const;

        static Expected<InstructionDetail, Error> getDetail(MachineMode mode, const Instruction& instr);
    };

    class InstructionDetail final : public TInstructionBase<InstructionDetail, 10>
    {
    public:
        static constexpr auto kInstrType = InstructionBase::Type::Detail;

        using OperandsAccess = Packed<std::uint64_t, Operand::Access, 4>;
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
            : TInstructionBase{ attribs, mnemonic, opCount, operands }
            , _access{ access }
            , _opsVisibility{ opsVisibility }
            , _cpuFlags{ flags }
            , _category{ category }
            , _length{ length }
        {
        }

        constexpr bool operator==(const InstructionDetail& other) const
        {
            return TInstructionBase::operator==(other) && _access == other._access && _opsVisibility == other._opsVisibility
                && _cpuFlags == other._cpuFlags && _category == other._category && _length == other._length;
        }

        constexpr bool operator!=(const InstructionDetail& other) const
        {
            return !(*this == other);
        }

        /// <summary>
        /// Returns the instruction category, this is target architecture specific.
        /// </summary>
        /// <returns>Instruction Category</returns>
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

        /// <summary>
        /// Returns a reference to the array that holds the visibility for each operand.
        /// </summary>
        /// <returns>Reference to operands visibility</returns>
        constexpr const OperandsVisibility& getOperandsVisibility() const noexcept
        {
            return _opsVisibility;
        }

        /// <summary>
        /// Returns the operand visibility for the specified index.
        /// </summary>
        /// <param name="index">Operand Index</param>
        /// <returns>Operand Visibility</returns>
        constexpr Operand::Visibility getOperandVisibility(std::size_t index) const noexcept
        {
            if (index >= _opCount)
            {
                return Operand::Visibility::Invalid;
            }
            return _opsVisibility.get(index);
        }

        /// <summary>
        /// Returns true if the operand specified by the index is hidden.
        /// </summary>
        /// <param name="index">Operand Index</param>
        /// <returns>bool</returns>
        constexpr bool isOperandHidden(std::size_t index) const noexcept
        {
            return getOperandVisibility(index) == Operand::Visibility::Hidden;
        }

        /// <summary>
        /// Returns true if the operand specified by the index is explicit.
        /// </summary>
        /// <param name="index">Operand Index</param>
        /// <returns>bool</returns>
        constexpr bool isOperandExplicit(std::size_t index) const noexcept
        {
            return getOperandVisibility(index) == Operand::Visibility::Explicit;
        }

        /// <summary>
        /// Returns true if the operand specified by the index is implicit.
        /// </summary>
        /// <param name="index">Operand Index</param>
        /// <returns>bool</returns>
        constexpr bool isOperandImplicit(std::size_t index) const noexcept
        {
            return getOperandVisibility(index) == Operand::Visibility::Implicit;
        }

        /// <summary>
        /// Returns the operand access mask specified by the index.
        /// </summary>
        /// <param name="index">Operand Index</param>
        /// <returns>Access mask</returns>
        constexpr Operand::Access getOperandAccess(std::size_t index) const noexcept
        {
            if (index >= _opCount)
            {
                return Operand::Access::None;
            }
            return _access.get(index);
        }

        /// <summary>
        /// Returns true if the operand at the specified index contains the access mask.
        /// </summary>
        /// <param name="index">Operand Index</param>
        /// <returns>bool</returns>
        constexpr bool hasOperandAccess(std::size_t index, Operand::Access accessMask)
        {
            return (getOperandAccess(index) & accessMask) != Operand::Access::None;
        }

        /// <summary>
        /// Returns true if the operand is read by the instruction (may read).
        /// </summary>
        /// <param name="index">Operand Index</param>
        /// <returns>bool</returns>
        constexpr bool isOperandRead(std::size_t index)
        {
            return hasOperandAccess(index, Operand::Access::MaskRead);
        }

        /// <summary>
        /// Returns true if the operand is conditionally read by the instruction (may read).
        /// </summary>
        /// <param name="index">Operand Index</param>
        /// <returns>bool</returns>
        constexpr bool isOperandCondRead(std::size_t index)
        {
            return hasOperandAccess(index, Operand::Access::CondRead);
        }

        /// <summary>
        /// Returns true if the operand is written by the instruction (may write).
        /// </summary>
        /// <param name="index">Operand Index</param>
        /// <returns>bool</returns>
        constexpr bool isOperandWrite(std::size_t index)
        {
            return hasOperandAccess(index, Operand::Access::MaskWrite);
        }

        /// <summary>
        /// Returns true if the operand is conditionally written by the instruction (may write).
        /// </summary>
        /// <param name="index">Operand Index</param>
        /// <returns>bool</returns>
        constexpr bool isOperandCondWrite(std::size_t index)
        {
            return hasOperandAccess(index, Operand::Access::CondWrite);
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
