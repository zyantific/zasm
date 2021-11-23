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

    using Operand = std::variant<operands::None, operands::Reg, operands::Mem, operands::Imm, operands::Label>;

    static constexpr auto SizeOfOperand = sizeof(Operand);

    enum class OperandVisibility : uint8_t
    {
        Invalid = ZYDIS_OPERAND_VISIBILITY_INVALID,
        Explicit = ZYDIS_OPERAND_VISIBILITY_EXPLICIT,
        Implicit = ZYDIS_OPERAND_VISIBILITY_IMPLICIT,
        Hidden = ZYDIS_OPERAND_VISIBILITY_HIDDEN,
    };

} // namespace zasm