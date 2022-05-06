#pragma once

#include <cstdint>
#include <optional>
#include <unordered_map>
#include <vector>
#include <zasm/core/errors.hpp>
#include <zasm/core/expected.hpp>
#include <zasm/program/instruction.hpp>

namespace zasm
{
    // Encoder context used for serialization by the Program.
    struct EncoderContext;

    enum class RelocationKind : uint8_t
    {
        None = 0,
        Immediate,
        Displacement,
        Data,
    };

    // A small buffer which holds the bytes of a single encoded instruction and the length.
    struct EncoderResult
    {
        std::array<uint8_t, 15> data{};
        uint8_t length{};
        RelocationKind relocKind{};
    };

    using EncoderOperands = std::array<Operand, ZYDIS_ENCODER_MAX_OPERANDS>;

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
    Error encodeFull(
        EncoderResult& buf, EncoderContext& ctx, ZydisMachineMode mode, Instruction::Attribs attribs, ZydisMnemonic mnemonic,
        size_t numOps, const EncoderOperands& operands) noexcept;

    // Helper function that unpacks the instruction and calls the explicit encodeFull variant.
    // Only explicit operands will be considered for the encoder request.
    Error encodeFull(EncoderResult& buf, EncoderContext& ctx, ZydisMachineMode mode, const Instruction& instr) noexcept;

} // namespace zasm