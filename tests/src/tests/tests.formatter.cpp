#include <gtest/gtest.h>
#include <zasm/formatter/formatter.hpp>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(FormatterTests, NodeInstr)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.mov(x86::eax, x86::edx), ErrorCode::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("mov eax, edx"));
    }

    TEST(FormatterTests, NodeInstrLock)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.lock().inc(x86::dword_ptr(x86::eax)), ErrorCode::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("lock inc dword ptr ds:[eax]"));
    }

    TEST(FormatterTests, NodeInstrMemLabel)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.lock().inc(x86::dword_ptr(label)), ErrorCode::None);
        ASSERT_EQ(assembler.bind(label), ErrorCode::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("lock inc dword ptr ds:[L0]"));
    }

    TEST(FormatterTests, ImmediateNegative)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.mov(x86::eax, Imm(-1)), ErrorCode::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("mov eax, -1"));
    }

    TEST(FormatterTests, ImmediatePositive)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.mov(x86::eax, Imm(0x12345678)), ErrorCode::None);

        auto nodeStr = formatter::toString(program, program.getHead());
        ASSERT_EQ(nodeStr, std::string("mov eax, 305419896"));
    }

    TEST(FormatterTests, HexImmediates)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.mov(x86::eax, Imm(0x12345678)), ErrorCode::None);

        auto nodeStr = formatter::toString(program, program.getHead(), formatter::Options::HexImmediates);
        ASSERT_EQ(nodeStr, std::string("mov eax, 0x12345678"));
    }

    TEST(FormatterTests, HexOffsetPositive)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.mov(x86::eax, x86::dword_ptr(x86::eax, 0x12345678)), ErrorCode::None);

        auto nodeStr = formatter::toString(program, program.getHead(), formatter::Options::HexOffsets);
        ASSERT_EQ(nodeStr, std::string("mov eax, dword ptr ds:[eax+0x12345678]"));
    }

    TEST(FormatterTests, HexOffsetNegative)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.mov(x86::eax, x86::dword_ptr(x86::eax, -0x12345678)), ErrorCode::None);

        auto nodeStr = formatter::toString(program, program.getHead(), formatter::Options::HexOffsets);
        ASSERT_EQ(nodeStr, std::string("mov eax, dword ptr ds:[eax-0x12345678]"));
    }

    TEST(FormatterTests, EntireProgram)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();
        auto label02 = assembler.createLabel();

        ASSERT_EQ(assembler.jmp(label02), ErrorCode::None);
        ASSERT_EQ(assembler.lock().inc(x86::dword_ptr(label01)), ErrorCode::None);
        ASSERT_EQ(assembler.bind(label01), ErrorCode::None);
        ASSERT_EQ(assembler.dd(0), ErrorCode::None);
        ASSERT_EQ(assembler.bind(label02), ErrorCode::None);
        ASSERT_EQ(assembler.nop(), ErrorCode::None);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("jmp L1\nlock inc dword ptr ds:[L0]\nL0:\ndd 0x00000000\nL1:\nnop"));
    }

    TEST(FormatterTests, NamedLabels)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel("Label01");
        auto label02 = assembler.createLabel("Label02");

        ASSERT_EQ(assembler.jmp(label02), ErrorCode::None);
        ASSERT_EQ(assembler.lock().inc(x86::dword_ptr(label01)), ErrorCode::None);
        ASSERT_EQ(assembler.bind(label01), ErrorCode::None);
        ASSERT_EQ(assembler.dd(0), ErrorCode::None);
        ASSERT_EQ(assembler.bind(label02), ErrorCode::None);
        ASSERT_EQ(assembler.nop(), ErrorCode::None);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("jmp Label02\nlock inc dword ptr ds:[Label01]\nLabel01:\ndd 0x00000000\nLabel02:\nnop"));
    }

    TEST(FormatterTests, DataDb)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        assembler.db(0xF3);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("db 0xf3"));
    }

    TEST(FormatterTests, DataTimes15Db)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        assembler.db(0xF3, 15);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("times 15 db 0xf3"));
    }

    TEST(FormatterTests, DataDw)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        assembler.dw(0xF3FC);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("dw 0xf3fc"));
    }

    TEST(FormatterTests, DataTimes15Dw)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        assembler.dw(0xF3FC, 15);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("times 15 dw 0xf3fc"));
    }

    TEST(FormatterTests, DataDd)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        assembler.dd(0xF3FCF199);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("dd 0xf3fcf199"));
    }

    TEST(FormatterTests, DataTimes15Dd)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        assembler.dd(0xF3FCF199, 15);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("times 15 dd 0xf3fcf199"));
    }

    TEST(FormatterTests, DataDq)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        assembler.dq(0xF3FCF199F3FCF199);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("dq 0xf3fcf199f3fcf199"));
    }

    TEST(FormatterTests, DataTimes15Dq)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        assembler.dq(0xF3FCF199F3FCF199, 15);

        auto nodeStr = formatter::toString(program);
        ASSERT_EQ(nodeStr, std::string("times 15 dq 0xf3fcf199f3fcf199"));
    }

} // namespace zasm::tests
