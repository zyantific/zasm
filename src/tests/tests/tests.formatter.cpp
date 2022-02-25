#include <gtest/gtest.h>
#include <zasm/program/formatter.hpp>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(FormatterTests, NodeInstr)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        ASSERT_EQ(assembler.mov(eax, edx), zasm::Error::None);
        ASSERT_EQ(program.serialize(0x400000), zasm::Error::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("mov eax, edx"));
    }

    TEST(FormatterTests, NodeInstrLock)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        ASSERT_EQ(assembler.lock().inc(dword_ptr(eax)), zasm::Error::None);
        ASSERT_EQ(program.serialize(0x400000), zasm::Error::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("lock inc dword ptr ds:[eax]"));
    }

    TEST(FormatterTests, NodeInstrMemLabel)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.lock().inc(dword_ptr(label)), zasm::Error::None);
        ASSERT_EQ(assembler.bind(label), zasm::Error::None);

        ASSERT_EQ(program.serialize(0x400000), zasm::Error::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("lock inc dword ptr ds:[L0]"));
    }

    TEST(FormatterTests, EntireProgram)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        auto label01 = assembler.createLabel();
        auto label02 = assembler.createLabel();

        ASSERT_EQ(assembler.jmp(label02), zasm::Error::None);
        ASSERT_EQ(assembler.lock().inc(dword_ptr(label01)), zasm::Error::None);
        ASSERT_EQ(assembler.bind(label01), zasm::Error::None);
        ASSERT_EQ(assembler.dd(0), zasm::Error::None);
        ASSERT_EQ(assembler.bind(label02), zasm::Error::None);
        ASSERT_EQ(assembler.nop(), zasm::Error::None);

        ASSERT_EQ(program.serialize(0x400000), zasm::Error::None);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("jmp L1\nlock inc dword ptr ds:[L0]\nL0:\ndd 0x00000000\nL1:\nnop"));
    }

} // namespace zasm::tests