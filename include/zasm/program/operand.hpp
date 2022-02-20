#pragma once

#include "immediate.hpp"
#include "label.hpp"
#include "memory.hpp"
#include "register.hpp"

#include <cstdint>
#include <variant>

namespace zasm
{
    namespace operands
    {
        struct None
        {
        };
    } // namespace operands

    namespace detail
    {
        enum class OperandVisibility : uint8_t
        {
            Invalid = ZYDIS_OPERAND_VISIBILITY_INVALID,
            Explicit = ZYDIS_OPERAND_VISIBILITY_EXPLICIT,
            Implicit = ZYDIS_OPERAND_VISIBILITY_IMPLICIT,
            Hidden = ZYDIS_OPERAND_VISIBILITY_HIDDEN,
        };

        enum class OperandEncoding : uint8_t
        {
            None = ZYDIS_OPERAND_ENCODING_NONE,
            ModRMReg = ZYDIS_OPERAND_ENCODING_MODRM_REG,
            ModRmRm = ZYDIS_OPERAND_ENCODING_MODRM_RM,
            Opcode = ZYDIS_OPERAND_ENCODING_OPCODE,
            Ndsndd = ZYDIS_OPERAND_ENCODING_NDSNDD,
            Is4 = ZYDIS_OPERAND_ENCODING_IS4,
            Mask = ZYDIS_OPERAND_ENCODING_MASK,
            Disp8 = ZYDIS_OPERAND_ENCODING_DISP8,
            Disp16 = ZYDIS_OPERAND_ENCODING_DISP16,
            Disp32 = ZYDIS_OPERAND_ENCODING_DISP32,
            Disp64 = ZYDIS_OPERAND_ENCODING_DISP64,
            Disp16_32_64 = ZYDIS_OPERAND_ENCODING_DISP16_32_64,
            Disp32_32_64 = ZYDIS_OPERAND_ENCODING_DISP32_32_64,
            Disp16_32_32 = ZYDIS_OPERAND_ENCODING_DISP16_32_32,
            U8 = ZYDIS_OPERAND_ENCODING_UIMM8,
            U16 = ZYDIS_OPERAND_ENCODING_UIMM16,
            U32 = ZYDIS_OPERAND_ENCODING_UIMM32,
            U64 = ZYDIS_OPERAND_ENCODING_UIMM64,
            U16_32_64 = ZYDIS_OPERAND_ENCODING_UIMM16_32_64,
            U32_32_64 = ZYDIS_OPERAND_ENCODING_UIMM32_32_64,
            U16_32_32 = ZYDIS_OPERAND_ENCODING_UIMM16_32_32,
            I8 = ZYDIS_OPERAND_ENCODING_SIMM8,
            I16 = ZYDIS_OPERAND_ENCODING_SIMM16,
            I32 = ZYDIS_OPERAND_ENCODING_SIMM32,
            I64 = ZYDIS_OPERAND_ENCODING_SIMM64,
            I16_32_64 = ZYDIS_OPERAND_ENCODING_SIMM16_32_64,
            I32_32_64 = ZYDIS_OPERAND_ENCODING_SIMM32_32_64,
            I16_32_32 = ZYDIS_OPERAND_ENCODING_SIMM16_32_32,
            JI8 = ZYDIS_OPERAND_ENCODING_JIMM8,
            JI16 = ZYDIS_OPERAND_ENCODING_JIMM16,
            JI32 = ZYDIS_OPERAND_ENCODING_JIMM32,
            JI64 = ZYDIS_OPERAND_ENCODING_JIMM64,
            JI16_32_64 = ZYDIS_OPERAND_ENCODING_JIMM16_32_64,
            JI32_32_64 = ZYDIS_OPERAND_ENCODING_JIMM32_32_64,
            JI16_32_32 = ZYDIS_OPERAND_ENCODING_JIMM16_32_32,
        };
    }

    class Operand
    {
        using Variant = std::variant<operands::None, operands::Reg, operands::Mem, operands::Imm, operands::Label>;

        Variant _data;

    public:
        using Visibility = detail::OperandVisibility;
        using Encoding = detail::OperandEncoding;

    public:
        constexpr Operand() noexcept
            : _data{ operands::None{} }
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
            : _data{ val }
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

        template<typename T> const T& as() const
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

        template<typename T> const T* tryAs() const noexcept
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return this;
            }
            else
            {
                return std::get_if<T>(&_data);
            }
        }

        template<typename T>
        constexpr bool is() const
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return true;
            }
            else
            {
                return std::holds_alternative<T>(_data);
            }
        }

        template<typename F> auto visit(F&& f) const
        {
            return std::visit([f = std::move(f)](auto&& op) { return f(op); }, _data);
        }
    };

    static constexpr auto SizeOfOperand = sizeof(Operand);

} // namespace zasm