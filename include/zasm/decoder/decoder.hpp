#pragma once

#include <Zydis/Zydis.h>
#include <cstddef>
#include <zasm/base/mode.hpp>
#include <zasm/core/errors.hpp>
#include <zasm/core/expected.hpp>
#include <zasm/program/instruction.hpp>

namespace zasm
{
    class Decoder final
    {
        ZydisDecoder _decoder{};
        MachineMode _mode{};
        Error _status{};

    public:
        using Result = zasm::Expected<InstructionDetail, Error>;

        Decoder(MachineMode mode) noexcept;

        Result decode(const void* data, std::size_t len, std::uint64_t address) noexcept;
    };

} // namespace zasm
