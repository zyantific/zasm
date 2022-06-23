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
            ASSERT_EQ(assembler.mov(x86::eax, Imm(i)), Error::None);
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
            ASSERT_EQ(assembler.mov(x86::eax, Imm(i)), Error::None);
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
            ASSERT_EQ(assembler.mov(x86::eax, Imm(i)), Error::None);
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

            const auto& instr = node->get<zasm::Instruction>();

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
            ASSERT_EQ(assembler.mov(x86::eax, Imm(i)), Error::None);
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

            const auto& instr = node->get<zasm::Instruction>();

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

        ASSERT_EQ(assembler.mov(x86::eax, Imm(0)), Error::None);
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

        ASSERT_EQ(assembler.mov(x86::eax, Imm(0)), Error::None);
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

        const Node* fifthNode = nullptr;
        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(x86::eax, Imm(i)), Error::None);
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

            const auto& instr = node->get<zasm::Instruction>();

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

        const Node* fifthNode = nullptr;
        for (int i = 0; i < 10; i++)
        {
            ASSERT_EQ(assembler.mov(x86::eax, Imm(i)), Error::None);
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

            const auto& instr = node->get<zasm::Instruction>();

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

        ASSERT_EQ(assembler.mov(x86::eax, x86::ebx), zasm::Error::None);
        ASSERT_EQ(assembler.xor_(x86::ebx, x86::edx), zasm::Error::None);
        ASSERT_EQ(assembler.add(x86::eax, Imm(1)), zasm::Error::None);
        ASSERT_EQ(assembler.not_(x86::eax), zasm::Error::None);
        ASSERT_EQ(assembler.xor_(x86::eax, Imm(1)), zasm::Error::None);

        auto labelFoo = assembler.createLabel("foo");
        ASSERT_EQ(labelFoo.getId(), zasm::Label::Id{ 0 });
        ASSERT_EQ(labelFoo.isValid(), true);
        ASSERT_EQ(assembler.bind(labelFoo), zasm::Error::None);
        ASSERT_EQ(assembler.mov(x86::dword_ptr(labelFoo), x86::eax), zasm::Error::None);

        ASSERT_EQ(program.size(), 7);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x400000), zasm::Error::None);

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

            ASSERT_EQ(assembler.push(x86::rax), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::rcx), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::rdx), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::rbx), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::rbp), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::rsi), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::rdi), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::r8), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::r9), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::r10), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::r11), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::r12), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::r13), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::r14), zasm::Error::None);
            ASSERT_EQ(assembler.push(x86::r15), zasm::Error::None);
            ASSERT_EQ(assembler.pushfq(), zasm::Error::None);

            ASSERT_EQ(assembler.popfq(), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::r15), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::r14), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::r13), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::r12), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::r11), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::r10), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::r9), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::r8), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::rdi), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::rsi), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::rbp), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::rbx), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::rdx), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::rcx), zasm::Error::None);
            ASSERT_EQ(assembler.pop(x86::rax), zasm::Error::None);

            ASSERT_EQ(serializer.serialize(program, address), zasm::Error::None);
            address += 0x10;

            ASSERT_NE(serializer.getCodeSize(), 0);

            const auto* data = serializer.getCode();
            ASSERT_NE(data, nullptr);

            program.clear();
            serializer.clear();
        }
    }

} // namespace zasm::tests