#pragma once

#include "testutils.hpp"

#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{

    using CodeGenFn = zasm::Error (*)(class Assembler& a);

    struct InstrTest
    {
        const char* instrBytes;
        const char* operation;
        CodeGenFn gen;
    };

#define INSTRUCTION_TEST(INSTR_BYTES, ...)                                                                                     \
    InstrTest                                                                                                                  \
    {                                                                                                                          \
#INSTR_BYTES, #__VA_ARGS__, [](auto& a) { using namespace zasm::operands; return a.__VA_ARGS__; }                              \
    }

} // namespace zasm::tests