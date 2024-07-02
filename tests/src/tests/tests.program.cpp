#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(ProgramTests, NodeInsertBeforeHead)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(x86::eax, Imm(i)), ErrorCode::None);
        }
        ASSERT_EQ(program.size(), 10);

        auto labelNode = program.bindLabel(program.createLabel());
        ASSERT_EQ(labelNode.hasValue(), true);
        program.insertBefore(program.getHead(), labelNode.value());

        ASSERT_EQ(program.size(), 11);
        ASSERT_EQ(program.getHead()->holds<Label>(), true);
    }

    TEST(ProgramTests, NodeInsertBeforeTail)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(x86::eax, Imm(i)), ErrorCode::None);
        }
        ASSERT_EQ(program.size(), 10);

        auto labelNode = program.bindLabel(program.createLabel());
        ASSERT_EQ(labelNode.hasValue(), true);
        program.insertBefore(program.getTail(), labelNode.value());

        ASSERT_EQ(program.size(), 11);
        ASSERT_EQ(program.getTail()->getPrev()->holds<Label>(), true);
    }

    TEST(ProgramTests, NodeDestroyHead)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(x86::eax, Imm(i)), ErrorCode::None);
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

            const auto& instr = node->get<Instruction>();

            const auto& imm = instr.getOperand<1, Imm>();
            ASSERT_EQ(imm.value<int>(), i);

            lastNode = node;
            node = node->getNext();
        }
        ASSERT_EQ(lastNode, program.getTail());
    }

    TEST(ProgramTests, NodeDestroyTail)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(x86::eax, Imm(i)), ErrorCode::None);
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

            const auto& instr = node->get<Instruction>();

            const auto& imm = instr.getOperand<1, Imm>();
            ASSERT_EQ(imm.value<int>(), i);

            lastNode = node;
            node = node->getNext();
        }
        ASSERT_EQ(lastNode, program.getTail());
    }

    TEST(ProgramTests, NodeDestroySingleHead)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.mov(x86::eax, Imm(0)), ErrorCode::None);
        ASSERT_EQ(program.size(), 1);

        ASSERT_EQ(program.getHead(), program.getTail());
        program.destroy(program.getHead());
        ASSERT_EQ(program.size(), 0);
        ASSERT_EQ(program.getHead(), nullptr);
    }

    TEST(ProgramTests, NodeDestroySingleTail)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.mov(x86::eax, Imm(0)), ErrorCode::None);
        ASSERT_EQ(program.size(), 1);

        ASSERT_EQ(program.getHead(), program.getTail());
        program.destroy(program.getTail());
        ASSERT_EQ(program.size(), 0);
        ASSERT_EQ(program.getTail(), nullptr);
    }

    TEST(ProgramTests, NodeReorderMoveAfter)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        Node* fifthNode = nullptr;
        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(x86::eax, Imm(i)), ErrorCode::None);
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

            const auto& instr = node->get<Instruction>();

            const auto& imm = instr.getOperand<1, Imm>();
            ASSERT_EQ(imm.value<int>(), NumberOrder[i]);

            lastNode = node;
            node = node->getNext();
        }
        ASSERT_EQ(lastNode, program.getTail());
    }

    TEST(ProgramTests, NodeReorderMoveBefore)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        Node* fifthNode = nullptr;
        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(x86::eax, Imm(i)), ErrorCode::None);
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

            const auto& instr = node->get<Instruction>();

            const auto& imm = instr.getOperand<1, Imm>();
            ASSERT_EQ(imm.value<int>(), NumberOrder[i]);

            lastNode = node;
            node = node->getNext();
        }
        ASSERT_EQ(lastNode, program.getTail());
    }

    TEST(ProgramTests, TestClear)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.mov(x86::eax, x86::ebx), ErrorCode::None);
        ASSERT_EQ(assembler.xor_(x86::ebx, x86::edx), ErrorCode::None);
        ASSERT_EQ(assembler.add(x86::eax, Imm(1)), ErrorCode::None);
        ASSERT_EQ(assembler.not_(x86::eax), ErrorCode::None);
        ASSERT_EQ(assembler.xor_(x86::eax, Imm(1)), ErrorCode::None);

        auto labelFoo = assembler.createLabel("foo");
        ASSERT_EQ(labelFoo.getId(), Label::Id{ 0 });
        ASSERT_EQ(labelFoo.isValid(), true);
        ASSERT_EQ(assembler.bind(labelFoo), ErrorCode::None);
        ASSERT_EQ(assembler.mov(x86::dword_ptr(x86::rip, labelFoo), x86::eax), ErrorCode::None);

        ASSERT_EQ(program.size(), 7);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x400000), ErrorCode::None);

        const std::array<uint8_t, 18> expected = {
            0x89, 0xd8, 0x31, 0xd3, 0x83, 0xc0, 0x01, 0xf7, 0xd0, 0x83, 0xf0, 0x01, 0x89, 0x05, 0xfa, 0xff, 0xff, 0xff,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        program.clear();
        ASSERT_EQ(program.size(), 0);

        serializer.clear();
        ASSERT_EQ(serializer.getCodeSize(), 0);
    }

    TEST(ProgramTests, TestClear2)
    {
        Program program(MachineMode::AMD64);
        Serializer serializer;

        int64_t address = 0x00400000;
        for (int i = 0; i < 1'000; i++)
        {
            x86::Assembler assembler(program);

            ASSERT_EQ(assembler.push(x86::rax), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::rcx), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::rdx), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::rbx), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::rbp), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::rsi), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::rdi), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::r8), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::r9), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::r10), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::r11), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::r12), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::r13), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::r14), ErrorCode::None);
            ASSERT_EQ(assembler.push(x86::r15), ErrorCode::None);
            ASSERT_EQ(assembler.pushfq(), ErrorCode::None);

            ASSERT_EQ(assembler.popfq(), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::r15), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::r14), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::r13), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::r12), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::r11), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::r10), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::r9), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::r8), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::rdi), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::rsi), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::rbp), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::rbx), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::rdx), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::rcx), ErrorCode::None);
            ASSERT_EQ(assembler.pop(x86::rax), ErrorCode::None);

            ASSERT_EQ(serializer.serialize(program, address), ErrorCode::None);
            address += 0x10;

            ASSERT_NE(serializer.getCodeSize(), 0);

            const auto* data = serializer.getCode();
            ASSERT_NE(data, nullptr);

            program.clear();
            serializer.clear();
        }
    }

    TEST(ProgramTests, TestLabelNodeLookup)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.mov(x86::eax, Imm(0)), ErrorCode::None);
        ASSERT_EQ(assembler.mov(x86::eax, Imm(1)), ErrorCode::None);
        ASSERT_EQ(assembler.mov(x86::eax, Imm(2)), ErrorCode::None);
        ASSERT_EQ(assembler.bind(label), ErrorCode::None);
        ASSERT_EQ(assembler.mov(x86::eax, Imm(3)), ErrorCode::None);

        auto* labelNode = program.getNodeForLabel(label);
        ASSERT_NE(labelNode, nullptr);

        ASSERT_EQ(labelNode->holds<Label>(), true);
        ASSERT_EQ(labelNode->get<Label>().getId(), label.getId());

        auto* nextNode = labelNode->getNext();
        ASSERT_NE(nextNode, nullptr);

        ASSERT_EQ(nextNode->holds<Instruction>(), true);
        const auto& instr = nextNode->get<Instruction>();

        ASSERT_EQ(instr.isOperandType<Imm>(1), true);

        const auto& imm = instr.getOperand<1, Imm>();
        ASSERT_EQ(imm.value<int>(), 3);
    }

} // namespace zasm::tests
