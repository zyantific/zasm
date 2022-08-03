#include <gtest/gtest.h>
#include <zasm/formatter/formatter.hpp>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(FormatterTests, NodeInstr)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.mov(x86::eax, x86::edx), zasm::Error::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("mov eax, edx"));
    }

    TEST(FormatterTests, NodeInstrLock)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.lock().inc(x86::dword_ptr(x86::eax)), zasm::Error::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("lock inc dword ptr ds:[eax]"));
    }

    TEST(FormatterTests, NodeInstrMemLabel)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.lock().inc(x86::dword_ptr(label)), zasm::Error::None);
        ASSERT_EQ(assembler.bind(label), zasm::Error::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("lock inc dword ptr ds:[L0]"));
    }

    TEST(FormatterTests, EntireProgram)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();
        auto label02 = assembler.createLabel();

        ASSERT_EQ(assembler.jmp(label02), zasm::Error::None);
        ASSERT_EQ(assembler.lock().inc(x86::dword_ptr(label01)), zasm::Error::None);
        ASSERT_EQ(assembler.bind(label01), zasm::Error::None);
        ASSERT_EQ(assembler.dd(0), zasm::Error::None);
        ASSERT_EQ(assembler.bind(label02), zasm::Error::None);
        ASSERT_EQ(assembler.nop(), zasm::Error::None);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("jmp L1\nlock inc dword ptr ds:[L0]\nL0:\ndd 0x00000000\nL1:\nnop"));
    }

} // namespace zasm::tests
