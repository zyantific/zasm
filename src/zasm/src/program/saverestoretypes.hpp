#pragma once

#include <cstdint>
#include <zasm/program/program.hpp>

namespace zasm
{
    enum class NodeType : uint8_t
    {
        Sentinel,
        Label,
        EmbeddedLabel,
        Data,
        Section,
        Align,
        Instruction,
    };

    namespace detail
    {
        static constexpr NodeType getNodeType(const Sentinel&)
        {
            return NodeType::Sentinel;
        }

        static constexpr NodeType getNodeType(const Label&)
        {
            return NodeType::Label;
        }

        static constexpr NodeType getNodeType(const EmbeddedLabel&)
        {
            return NodeType::EmbeddedLabel;
        }

        static constexpr NodeType getNodeType(const Data&)
        {
            return NodeType::Data;
        }

        static constexpr NodeType getNodeType(const Section&)
        {
            return NodeType::Section;
        }

        static constexpr NodeType getNodeType(const Align&)
        {
            return NodeType::Align;
        }

        static constexpr NodeType getNodeType(const Instruction&)
        {
            return NodeType::Instruction;
        }

    } // namespace detail

    static constexpr NodeType getNodeType(const Node& node)
    {
        return node.visit([](auto&& value) { return detail::getNodeType(value); });
    }

    enum class OperandType : std::uint8_t
    {
        None = 0,
        Register,
        Memory,
        Immediate,
        Label,
    };

    namespace detail
    {
        static constexpr OperandType getOperandType(const Operand::None&)
        {
            return OperandType::None;
        }

        static constexpr OperandType getOperandType(const Reg&)
        {
            return OperandType::Register;
        }

        static constexpr OperandType getOperandType(const Mem&)
        {
            return OperandType::Memory;
        }

        static constexpr OperandType getOperandType(const Imm&)
        {
            return OperandType::Label;
        }

        static constexpr OperandType getOperandType(const Label&)
        {
            return OperandType::Label;
        }

    } // namespace detail

    static constexpr OperandType getOperandType(const Operand& op)
    {
        return op.visit([](auto&& value) { return detail::getOperandType(value); });
    }

} // namespace zasm
