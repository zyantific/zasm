#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <zasm/base/mode.hpp>
#include <zasm/core/errors.hpp>
#include <zasm/core/expected.hpp>
#include <zasm/program/instruction.hpp>

namespace zasm
{
    // Encoder context used for serialization by the Program.
    struct EncoderContext;

    enum class RelocationType : std::uint8_t
    {
        None = 0,
        Abs,
        Rel32,
    };

    enum class RelocationData : std::uint8_t
    {
        None = 0,
        Immediate,
        Memory,
        Data,
    };

    // A small buffer which holds the bytes of a single encoded instruction and the length.
    struct EncoderBuffer
    {
        static constexpr std::size_t kMaxInstructionSize = 15;

        std::array<std::uint8_t, kMaxInstructionSize> data{};
        std::uint8_t length{};
    };

    struct EncoderResult
    {
        EncoderBuffer buffer{};
        RelocationType relocKind{};
        RelocationData relocData{};
        Label::Id relocLabel{ Label::Id::Invalid };
    };

    using EncoderOperands = std::array<Operand, 5 /* ZYDIS_ENCODER_MAX_OPERANDS */>;

    // Encodes with the requested instruction without a context and will use temporary
    // values for operands like labels and rip-rel addressing.
    Expected<EncoderResult, Error> encode(
        MachineMode mode, Instruction::Attribs attribs, Instruction::Mnemonic mnemonic, std::size_t numOps,
        const Operand* operands);

    // Encodes with full context. This function still allows labels to be unbound and will not error
    // instead a temporary value be usually encoded. It is expected for the serialization to handle this
    // with multiple passes.
    Expected<EncoderResult, Error> encode(EncoderContext& ctx, MachineMode mode, const Instruction& instr);

} // namespace zasm
