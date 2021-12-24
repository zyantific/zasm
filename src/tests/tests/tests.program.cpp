#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(ProgramTests, NodeInsertBeforeHead)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        Assembler assembler(program);

        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(eax, Imm(i)), Error::None);
        }
        ASSERT_EQ(program.size(), 10);

        auto* labelNode = program.bindLabel(program.createLabel());
        program.insertBefore(program.getHead(), labelNode);

        ASSERT_EQ(program.size(), 11);
        ASSERT_EQ(program.getHead()->is<Label>(), true);
    }

    TEST(ProgramTests, NodeInsertBeforeTail)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        Assembler assembler(program);

        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(eax, Imm(i)), Error::None);
        }
        ASSERT_EQ(program.size(), 10);

        auto* labelNode = program.bindLabel(program.createLabel());
        program.insertBefore(program.getTail(), labelNode);

        ASSERT_EQ(program.size(), 11);
        ASSERT_EQ(program.getTail()->getPrev()->is<Label>(), true);
    }

    TEST(ProgramTests, NodeDestroyHead)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        Assembler assembler(program);

        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(eax, Imm(i)), Error::None);
        }
        ASSERT_EQ(program.size(), 10);

        auto* nodeAfterHead = program.getHead()->getNext();
        ASSERT_NE(nodeAfterHead, nullptr);

        program.destroy(program.getHead());
        ASSERT_EQ(program.size(), 9);
        ASSERT_EQ(program.getHead(), nodeAfterHead);

        auto* node = program.getHead();
        auto* lastNode = node;
        for (int i = 1; i < 10; i++)
        {
            ASSERT_NE(node, nullptr);

            const auto& instr = node->as<Instruction>();

            const auto& imm = instr.getOperand<1, Imm>();
            ASSERT_EQ(imm.value<int>(), i);

            lastNode = node;
            node = node->getNext();
        }
        ASSERT_EQ(lastNode, program.getTail());
    }

    TEST(ProgramTests, NodeReorderMoveAfter)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        Assembler assembler(program);

        const Node* fifthNode = nullptr;
        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(eax, Imm(i)), Error::None);
            if (i == 5)
                fifthNode = assembler.getCursor();
        }
        ASSERT_EQ(program.size(), 10);

        ASSERT_EQ(program.moveAfter(program.getTail(), fifthNode), fifthNode);

        constexpr int NumberOrder[] = { 0, 1, 2, 3, 4, 6, 7, 8, 9, 5 };

        auto* node = program.getHead();
        auto* lastNode = node;
        for (int i = 0; i < 10; i++)
        {
            ASSERT_NE(node, nullptr);

            const auto& instr = node->as<Instruction>();

            const auto& imm = instr.getOperand<1, Imm>();
            ASSERT_EQ(imm.value<int>(), NumberOrder[i]);

            lastNode = node;
            node = node->getNext();
        }
        ASSERT_EQ(lastNode, program.getTail());
    }

    TEST(ProgramTests, NodeReorderMoveBefore)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        Assembler assembler(program);

        const Node* fifthNode = nullptr;
        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(eax, Imm(i)), Error::None);
            if (i == 5)
                fifthNode = assembler.getCursor();
        }
        ASSERT_EQ(program.size(), 10);

        ASSERT_EQ(program.moveBefore(program.getTail(), fifthNode), fifthNode);

        constexpr int NumberOrder[] = { 0, 1, 2, 3, 4, 6, 7, 8, 5, 9 };

        auto* node = program.getHead();
        auto* lastNode = node;
        for (int i = 0; i < 10; i++)
        {
            ASSERT_NE(node, nullptr);

            const auto& instr = node->as<Instruction>();

            const auto& imm = instr.getOperand<1, Imm>();
            ASSERT_EQ(imm.value<int>(), NumberOrder[i]);

            lastNode = node;
            node = node->getNext();
        }
        ASSERT_EQ(lastNode, program.getTail());
    }

} // namespace zasm::tests