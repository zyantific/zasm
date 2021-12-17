#pragma once

#include <gtest/gtest.h>
#include "testutils.hpp"

namespace zasm::tests
{

#define INSTRUCTION_TEST(INSTR_BYTES, ...)                                                                                     \
    TEST(InstructionTests, T##INSTR_BYTES)                                                                                     \
    {                                                                                                                          \
        using namespace zasm::operands;                                                                                        \
                                                                                                                               \
        Program program(ZYDIS_MACHINE_MODE_LONG_64);                                                                           \
        Assembler assembler(program);                                                                                          \
                                                                                                                               \
        ASSERT_EQ(assembler.__VA_ARGS__, Error::None);                                                                         \
        ASSERT_EQ(program.serialize(0x0000000000401000), Error::None);                                                         \
        auto hexEncoded = hexEncode(program.getCode(), program.getCodeSize());                                                 \
        ASSERT_EQ(std::string(#INSTR_BYTES), hexEncoded) << #__VA_ARGS__;                                                      \
    }

} // namespace zasm::tests