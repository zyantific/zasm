#pragma once

#include "operand.hpp"

#include <array>
#include <zasm/core/enumflags.hpp>

namespace zasm
{
#pragma pack(push, 1)
    class Instruction
    {
        static constexpr size_t kMaxOperands = 10;

    public:
        enum class Mnemonic : uint16_t;
        enum class Encoding : uint8_t;
        enum class Attribs : uint16_t;
        enum class Category : uint8_t;

        using Length = uint8_t;
        using OperandCount = uint8_t;
        using Operands = std::array<Operand, kMaxOperands>;
        using OperandsAccess = std::array<Operand::Access, kMaxOperands>;
        using OperandsVisibility = std::array<Operand::Visibility, kMaxOperands>;

        struct CPUFlags
        {
            uint32_t read;
            uint32_t write;
            uint32_t undefined;
        };

    private:
        const Mnemonic _mnemonic{};
        const Length _length{};
        const OperandCount _opCount{};
        const Operands _operands{};
        const OperandsAccess _access{};
        const OperandsVisibility _opsVisibility{};
        const CPUFlags _cpuFlags{};
        const Category _category{};
        const Attribs _attribs{};

    public:
        constexpr Instruction() noexcept = default;
        constexpr Instruction(
            Attribs attribs, Mnemonic mnemonic, OperandCount opCount, const Operands& operands, const OperandsAccess& access,
            const OperandsVisibility& opsVisibility, const CPUFlags& flags, const Category& category,
            Length length = 0) noexcept
            : _operands{ operands }
            , _opCount{ opCount }
            , _mnemonic{ static_cast<Mnemonic>(mnemonic) }
            , _access{ access }
            , _opsVisibility{ opsVisibility }
            , _cpuFlags{ flags }
            , _category{ category }
            , _attribs{ attribs }
            , _length{ length }
        {
        }

        constexpr Mnemonic getMnemonic() const noexcept
        {
            return _mnemonic;
        }

        constexpr Attribs getAttribs() const noexcept
        {
            return _attribs;
        }

        template<typename T> constexpr bool hasAttrib(T attrib) const noexcept
        {
            static_assert(std::is_enum_v<T> || std::is_integral_v<T>, "Type must be integral or enum");

            return (static_cast<uint32_t>(_attribs) & static_cast<uint32_t>(attrib)) != 0u;
        }

        constexpr Category getCategory() const noexcept
        {
            return _category;
        }

        constexpr Length getLength() const noexcept
        {
            return _length;
        }

        constexpr const Operands& getOperands() const noexcept
        {
            return _operands;
        }

        constexpr size_t getOperandCount() const noexcept
        {
            return _opCount;
        }

        template<size_t TIndex, typename T = Operand> constexpr const T& getOperand() const
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return std::get<TIndex>(_operands);
            }
            else
            {
                auto& op = std::get<TIndex>(_operands);
                return op.template get<T>();
            }
        }

        template<typename T = Operand> constexpr const T& getOperand(size_t index) const
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

        template<typename T> constexpr const T* getOperandIf(size_t index) const noexcept
        {
            if (index >= _opCount || index >= _operands.size())
                return nullptr;

            auto& op = _operands[index];
            return op.template getIf<T>();
        }

        constexpr const OperandsVisibility& getOperandsVisibility() const noexcept
        {
            return _opsVisibility;
        }

        constexpr const Operand::Visibility getOperandVisibility(size_t index) const noexcept
        {
            if (index >= _opCount || index >= _opsVisibility.size())
                return Operand::Visibility::Invalid;
            return _opsVisibility[index];
        }

        constexpr bool isOperandHidden(size_t index) const noexcept
        {
            if (index >= _opCount)
                return true;
            return _opsVisibility[index] == Operand::Visibility::Hidden;
        }

        constexpr bool isOperandExplicit(size_t index) const noexcept
        {
            if (index >= _opCount)
                return false;
            return _opsVisibility[index] == Operand::Visibility::Explicit;
        }

        constexpr bool isOperandImplicit(size_t index) const noexcept
        {
            if (index >= _opCount)
                return false;
            return _opsVisibility[index] == Operand::Visibility::Implicit;
        }

        constexpr const OperandsAccess& getAccess() const noexcept
        {
            return _access;
        }

        constexpr const CPUFlags& getCPUFlags() const noexcept
        {
            return _cpuFlags;
        }
    };
#pragma pack(pop)

} // namespace zasm