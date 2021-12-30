#pragma once

#include "operand.hpp"

#include <Zydis/Zydis.h>
#include <array>
#include <zasm/core/enumflags.hpp>

namespace zasm
{
    namespace detail
    {
        enum class InstructionAttribs : uint16_t
        {
            None = 0,
            Lock = (1u << 0),
            Rep = (1u << 1),
            Repe = (1u << 2),
            Repne = (1u << 3),
            Bnd = (1u << 4),
            Xacquire = (1u << 5),
            Xrelease = (1u << 6),
            OperandSize8 = (1u << 7),
            OperandSize16 = (1u << 8),
            OperandSize32 = (1u << 9),
            OperandSize64 = (1u << 10),
        };
        ZASM_ENABLE_ENUM_OPERATORS(InstructionAttribs);

    } // namespace detail

#pragma pack(push, 1)
    class Instruction
    {
    public:
        // For debug builds this makes inspection easier.
        // For release builds size matters more.
#ifdef _DEBUG
        using Mnemonic = ZydisMnemonic;
#else
        using Mnemonic = uint16_t;
#endif
        using Operands = std::array<Operand, ZYDIS_MAX_OPERAND_COUNT>;
        using Access = std::array<ZydisOperandActions, ZYDIS_MAX_OPERAND_COUNT>;
        using Visibility = std::array<OperandVisibility, ZYDIS_MAX_OPERAND_COUNT>;
        using Length = uint8_t;

        struct Flags
        {
            uint32_t read;
            uint32_t write;
            uint32_t undefined;
        };

        using Attribs = detail::InstructionAttribs;

    private:
        Operands _operands{};
        Mnemonic _id{};
        Access _access{};
        Visibility _visibility{};
        Flags _flags{};
        Attribs _attribs{};
        Length _length{};

    public:
        constexpr Instruction() noexcept = default;
        constexpr Instruction(
            Attribs attribs, ZydisMnemonic mnemonic, const Operands& operands, const Access& access, const Visibility& vis,
            const Flags& flags, Length length = 0) noexcept
            : _operands{ operands }
            , _id{ static_cast<Mnemonic>(mnemonic) }
            , _access{ access }
            , _visibility{ vis }
            , _flags{ flags }
            , _attribs{ attribs }
            , _length{ length }
        {
        }

        constexpr ZydisMnemonic getId() const noexcept
        {
            return static_cast<ZydisMnemonic>(_id);
        }

        constexpr Attribs getAttribs() const noexcept
        {
            return _attribs;
        }

        constexpr bool hasAttrib(Attribs attrib) const noexcept
        {
            return (_attribs & attrib) != Attribs::None;
        }

        constexpr Length getLength() const noexcept
        {
            return _length;
        }

        constexpr const Operands& getOperands() const noexcept
        {
            return _operands;
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
                return op.template as<T>();
            }
        }

        constexpr const Operand& getOperand(size_t index) const noexcept
        {
            return _operands[index];
        }

        template<typename T> constexpr const T* tryGetOperandAs(size_t index) const noexcept
        {
            if (index >= _operands.size())
                return nullptr;

            auto& op = _operands[index];
            return op.template tryAs<T>();
        }

        constexpr const Visibility& getVisibility() const noexcept
        {
            return _visibility;
        }

        constexpr const Access& getAccess() const noexcept
        {
            return _access;
        }

        constexpr const Flags& getFlags() const noexcept
        {
            return _flags;
        }
    };
#pragma pack(pop)

} // namespace zasm