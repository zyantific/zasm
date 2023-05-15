#pragma once

#include <filesystem>
#include <istream>
#include <zasm/core/errors.hpp>
#include <zasm/core/expected.hpp>

namespace zasm
{
    class Program;

    Error save(const Program& program, std::filesystem::path outputFilePath);
    Error save(const Program& program, std::iostream& stream);

    zasm::Expected<Program, Error> load(std::filesystem::path inputFilePath);
    zasm::Expected<Program, Error> load(std::iostream& stream);

} // namespace zasm
