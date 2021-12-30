#pragma once

#include <Zydis/Zydis.h>
#include <zasm/core/errors.hpp>
#include <zasm/core/expected.hpp>
#include <zasm/program/instruction.hpp>

namespace zasm
{
    class Decoder
    {
        ZydisDecoder _decoder;
        Error _status{};

    public:
        using Result = zasm::Expected<Instruction, Error>;

        Decoder(ZydisMachineMode mode) noexcept;

        Result decode(const void* data, const size_t len, uint64_t va) noexcept;
    };

} // namespace zasm