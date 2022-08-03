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

    TEST(FormatterTests, ImmediateNegative)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.mov(x86::eax, Imm(-1)), zasm::Error::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("mov eax, -1"));
    }

    TEST(FormatterTests, ImmediatePositive)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.mov(x86::eax, Imm(0x12345678)), zasm::Error::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("mov eax, 305419896"));
    }
        
    TEST(FormatterTests, HexImmediates)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.mov(x86::eax, Imm(0x12345678)), zasm::Error::None);

        auto nodeStr = formatter::toString(program, program.getHead(), formatter::Options::HexImmediates);
        ASSERT_EQ(nodeStr, std::string("mov eax, 0x12345678"));
    }

    TEST(FormatterTests, HexOffsetPositive)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.mov(x86::eax, x86::dword_ptr(x86::eax, 0x12345678)), zasm::Error::None);

        auto nodeStr = formatter::toString(program, program.getHead(), formatter::Options::HexOffsets);
        ASSERT_EQ(nodeStr, std::string("mov eax, dword ptr ds:[eax+0x12345678]"));
    }

    TEST(FormatterTests, HexOffsetNegative)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.mov(x86::eax, x86::dword_ptr(x86::eax, -0x12345678)), zasm::Error::None);

        auto nodeStr = formatter::toString(program, program.getHead(), formatter::Options::HexOffsets);
        ASSERT_EQ(nodeStr, std::string("mov eax, dword ptr ds:[eax-0x12345678]"));
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

    TEST(FormatterTests, NamedLabels)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel("Label01");
        auto label02 = assembler.createLabel("Label02");

        ASSERT_EQ(assembler.jmp(label02), zasm::Error::None);
        ASSERT_EQ(assembler.lock().inc(x86::dword_ptr(label01)), zasm::Error::None);
        ASSERT_EQ(assembler.bind(label01), zasm::Error::None);
        ASSERT_EQ(assembler.dd(0), zasm::Error::None);
        ASSERT_EQ(assembler.bind(label02), zasm::Error::None);
        ASSERT_EQ(assembler.nop(), zasm::Error::None);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("jmp Label02\nlock inc dword ptr ds:[Label01]\nLabel01:\ndd 0x00000000\nLabel02:\nnop"));
    }

} // namespace zasm::tests
