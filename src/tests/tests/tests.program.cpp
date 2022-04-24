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

        auto labelNode = program.bindLabel(program.createLabel());
        ASSERT_EQ(labelNode.hasValue(), true);
        program.insertBefore(program.getHead(), labelNode.value());

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

        auto labelNode = program.bindLabel(program.createLabel());
        ASSERT_EQ(labelNode.hasValue(), true);
        program.insertBefore(program.getTail(), labelNode.value());

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

    TEST(ProgramTests, NodeDestroyTail)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        Assembler assembler(program);

        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(eax, Imm(i)), Error::None);
        }
        ASSERT_EQ(program.size(), 10);

        auto* nodeBeforeTail = program.getTail()->getPrev();
        ASSERT_NE(nodeBeforeTail, nullptr);

        program.destroy(program.getTail());
        ASSERT_EQ(program.size(), 9);
        ASSERT_EQ(program.getTail(), nodeBeforeTail);

        auto* node = program.getHead();
        auto* lastNode = node;
        for (int i = 0; i < 9; i++)
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

    TEST(ProgramTests, NodeDestroySingleHead)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        Assembler assembler(program);

        ASSERT_EQ(assembler.mov(eax, Imm(0)), Error::None);
        ASSERT_EQ(program.size(), 1);

        ASSERT_EQ(program.getHead(), program.getTail());
        program.destroy(program.getHead());
        ASSERT_EQ(program.size(), 0);
        ASSERT_EQ(program.getHead(), nullptr);
    }

    TEST(ProgramTests, NodeDestroySingleTail)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        Assembler assembler(program);

        ASSERT_EQ(assembler.mov(eax, Imm(0)), Error::None);
        ASSERT_EQ(program.size(), 1);

        ASSERT_EQ(program.getHead(), program.getTail());
        program.destroy(program.getTail());
        ASSERT_EQ(program.size(), 0);
        ASSERT_EQ(program.getTail(), nullptr);
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

    TEST(ProgramTests, TestClear)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        ASSERT_EQ(assembler.mov(eax, ebx), zasm::Error::None);
        ASSERT_EQ(assembler.xor_(ebx, edx), zasm::Error::None);
        ASSERT_EQ(assembler.add(eax, Imm(1)), zasm::Error::None);
        ASSERT_EQ(assembler.not_(eax), zasm::Error::None);
        ASSERT_EQ(assembler.xor_(eax, Imm(1)), zasm::Error::None);

        auto labelFoo = assembler.createLabel("foo");
        ASSERT_EQ(labelFoo.getId(), zasm::Label::Id{ 0 });
        ASSERT_EQ(labelFoo.isValid(), true);
        ASSERT_EQ(assembler.bind(labelFoo), zasm::Error::None);
        ASSERT_EQ(assembler.mov(dword_ptr(labelFoo), eax), zasm::Error::None);

        ASSERT_EQ(program.size(), 7);

        ASSERT_EQ(program.serialize(0x400000), zasm::Error::None);

        const std::array<uint8_t, 18> expected = {
            0x89, 0xd8, 0x31, 0xd3, 0x83, 0xc0, 0x01, 0xf7, 0xd0, 0x83, 0xf0, 0x01, 0x89, 0x05, 0xfa, 0xff, 0xff, 0xff,
        };
        ASSERT_EQ(program.getCodeSize(), expected.size());

        const auto* data = program.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        program.clear();

        ASSERT_EQ(program.size(), 0);
        ASSERT_EQ(program.getCodeSize(), 0);
    }

    TEST(ProgramTests, TestClear2)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        int64_t address = 0x00400000;
        for (int i = 0; i < 1'000; i++)
        {
            Assembler assembler(program);

            ASSERT_EQ(assembler.push(rax), zasm::Error::None);
            ASSERT_EQ(assembler.push(rcx), zasm::Error::None);
            ASSERT_EQ(assembler.push(rdx), zasm::Error::None);
            ASSERT_EQ(assembler.push(rbx), zasm::Error::None);
            ASSERT_EQ(assembler.push(rbp), zasm::Error::None);
            ASSERT_EQ(assembler.push(rsi), zasm::Error::None);
            ASSERT_EQ(assembler.push(rdi), zasm::Error::None);
            ASSERT_EQ(assembler.push(r8), zasm::Error::None);
            ASSERT_EQ(assembler.push(r9), zasm::Error::None);
            ASSERT_EQ(assembler.push(r10), zasm::Error::None);
            ASSERT_EQ(assembler.push(r11), zasm::Error::None);
            ASSERT_EQ(assembler.push(r12), zasm::Error::None);
            ASSERT_EQ(assembler.push(r13), zasm::Error::None);
            ASSERT_EQ(assembler.push(r14), zasm::Error::None);
            ASSERT_EQ(assembler.push(r15), zasm::Error::None);
            ASSERT_EQ(assembler.pushfq(), zasm::Error::None);

            ASSERT_EQ(assembler.popfq(), zasm::Error::None);
            ASSERT_EQ(assembler.pop(r15), zasm::Error::None);
            ASSERT_EQ(assembler.pop(r14), zasm::Error::None);
            ASSERT_EQ(assembler.pop(r13), zasm::Error::None);
            ASSERT_EQ(assembler.pop(r12), zasm::Error::None);
            ASSERT_EQ(assembler.pop(r11), zasm::Error::None);
            ASSERT_EQ(assembler.pop(r10), zasm::Error::None);
            ASSERT_EQ(assembler.pop(r9), zasm::Error::None);
            ASSERT_EQ(assembler.pop(r8), zasm::Error::None);
            ASSERT_EQ(assembler.pop(rdi), zasm::Error::None);
            ASSERT_EQ(assembler.pop(rsi), zasm::Error::None);
            ASSERT_EQ(assembler.pop(rbp), zasm::Error::None);
            ASSERT_EQ(assembler.pop(rbx), zasm::Error::None);
            ASSERT_EQ(assembler.pop(rdx), zasm::Error::None);
            ASSERT_EQ(assembler.pop(rcx), zasm::Error::None);
            ASSERT_EQ(assembler.pop(rax), zasm::Error::None);

            ASSERT_EQ(program.serialize(address), zasm::Error::None);
            address += 0x10;

            ASSERT_NE(program.getCodeSize(), 0);

            const auto* data = program.getCode();
            ASSERT_NE(data, nullptr);

            program.clear();
        }
    }

} // namespace zasm::tests