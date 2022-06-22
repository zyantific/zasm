#pragma once

#include <array>
#include <cstdint>
#include <zasm/core/errors.hpp>
#include <zasm/program/instruction.hpp>

namespace zasm
{
    // Encoder context used for serialization by the Program.
    struct EncoderContext;

    enum class RelocationType : uint8_t
    {
        None = 0,
        Abs,
        Rel32,
    };

    enum class RelocationData : uint8_t
    {
        None = 0,
        Immediate,
        Memory,
        Data,
    };

    // A small buffer which holds the bytes of a single encoded instruction and the length.
    struct EncoderResult
    {
        std::array<uint8_t, 15> data{};
        uint8_t length{};
        RelocationType relocKind{};
        RelocationData relocData{};
        Label::Id relocLabel{ Label::Id::Invalid };
    };

    using EncoderOperands = std::array<Operand, 5 /* ZYDIS_ENCODER_MAX_OPERANDS */>;

    // This function might change some operands internally in order to encode without a context.
    // The purpose of this function is to generate instructions for the assembler before
    // full serialization. This allows to query instruction meta data such as operand access
    // and CPU flags, this can be also used to estimate the size.
    Error encodeEstimated(
        EncoderResult& buf, ZydisMachineMode mode, Instruction::Attribs attribs, ZydisMnemonic id, size_t numOps,
        const EncoderOperands& operands) noexcept;

    // Encodes with full context. This function still allows labels to be unbound and will not error
    // instead a temporary value be usually encoded. It is expected for the serialization to handle this
    // with multiple passes.
    Error encodeFull(EncoderResult& buf, EncoderContext& ctx, ZydisMachineMode mode, const Instruction& instr) noexcept;

} // namespace zasm