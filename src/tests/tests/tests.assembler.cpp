#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(AssemblerTests, TestBindLabel)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();
        ASSERT_EQ(label01.isValid(), true);
        ASSERT_EQ(assembler.bind(label01), Error::None);
    }

    TEST(AssemblerTests, TestDoubleBindLabel)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();
        ASSERT_EQ(label01.isValid(), true);
        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.bind(label01), Error::LabelAlreadyBound);
    }

    TEST(AssemblerTests, TestBindInvalidLabel)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        zasm::Label label01;
        ASSERT_EQ(label01.isValid(), false);
        ASSERT_EQ(assembler.bind(label01), Error::InvalidLabel);
    }

    TEST(AssemblerTests, TestEmitDirectMov)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.emit(x86::Mnemonic::Mov, x86::rax, Imm(01)), Error::None);
    }

    TEST(AssemblerTests, TestRemoveCursorNode)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);
        
        ASSERT_EQ(assembler.mov(x86::rax, x86::rax), Error::None);
        auto* nodeA = assembler.getCursor();
        ASSERT_EQ(assembler.mov(x86::rdx, x86::rdx), Error::None);
        auto* nodeB = assembler.getCursor();
        ASSERT_EQ(assembler.mov(x86::rbx, x86::rbx), Error::None);
        auto* nodeC = assembler.getCursor();
        
        program.destroy(nodeC);
        ASSERT_EQ(assembler.getCursor(), nodeB);

        program.destroy(nodeB);
        ASSERT_EQ(assembler.getCursor(), nodeA);

        program.destroy(nodeA);
        ASSERT_EQ(assembler.getCursor(), nullptr);
    }

} // namespace zasm::tests
