#pragma once

#include <filesystem>
#include <istream>
#include <zasm/core/errors.hpp>
#include <zasm/core/expected.hpp>
#include <zasm/core/stream.hpp>

namespace zasm
{
    class Program;

    Error save(const Program& program, std::filesystem::path outputFilePath);
    Error save(const Program& program, IStream& stream);

    zasm::Expected<Program, Error> load(std::filesystem::path inputFilePath);
    zasm::Expected<Program, Error> load(IStream& stream);

} // namespace zasm
