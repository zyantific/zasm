#pragma once

#include "operand.hpp"

#include <array>
#include <zydis/Zydis.h>

namespace zasm
{
#pragma pack(push, 1)
    class Instruction
    {
    public:
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

        enum class Prefix : uint8_t
        {
            None = 0,
            Lock = (1u << 0),
            Rep = (1u << 1),
            Repe = (1u << 2),
            Repne = (1u << 3),
            Bnd = (1u << 4),
            Xacquire = (1u << 5),
            Xrelease = (1u << 6),
        };

        // For debug builds this makes inspection easier.
        // For release builds size matters more.
#ifdef _DEBUG
        using Mnemonic = ZydisMnemonic;
#else
        using Mnemonic = uint16_t;
#endif

    private:
        Mnemonic _id{};
        Operands _operands{};
        Access _access{};
        Visibility _visibility{};
        Flags _flags{};
        Prefix _prefixes{};
        Length _length{};

    public:
        constexpr Instruction() = default;
        constexpr Instruction(
            Prefix prefixes, ZydisMnemonic mnemonic, const Operands& operands, const Access& access, const Visibility& vis,
            const Flags& flags, Length length = 0)
            : _id{ static_cast<Mnemonic>(mnemonic) }
            , _operands{ operands }
            , _access{ access }
            , _visibility{ vis }
            , _flags{ flags }
            , _prefixes{ prefixes }
            , _length{ length }
        {
        }

        constexpr ZydisMnemonic getId() const
        {
            return static_cast<ZydisMnemonic>(_id);
        }

        constexpr Prefix getPrefixes() const
        {
            return _prefixes;
        }

        constexpr bool hasPrefix(Prefix prefix) const
        {
            return (static_cast<unsigned>(_prefixes) & static_cast<unsigned>(prefix)) != 0u;
        }

        constexpr Length getLength() const
        {
            return _length;
        }

        constexpr const Operands& getOperands() const
        {
            return _operands;
        }

        constexpr const Visibility& getVisibility() const
        {
            return _visibility;
        }

        constexpr const Access& getAccess() const
        {
            return _access;
        }

        constexpr const Flags& getFlags() const
        {
            return _flags;
        }
    };
#pragma pack(pop)

    static constexpr auto SizeOfInstruction = sizeof(Instruction);

} // namespace zasm