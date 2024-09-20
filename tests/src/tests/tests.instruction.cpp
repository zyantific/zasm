#include "../testutils.hpp"

#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(InstructionTests, BuildInstruction)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        const auto instr = zasm::Instruction()                  //
                               .setMnemonic(x86::Mnemonic::Mov) //
                               .addOperand(x86::eax)            //
                               .addOperand(zasm::Imm(1));       //

        ASSERT_EQ(assembler.emit(instr), ErrorCode::None);

        const auto* instrNode = assembler.getCursor();
        ASSERT_NE(instrNode, nullptr);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x00400000), ErrorCode::None);

        const std::array<uint8_t, 5> expected = {
            0xB8, 0x01, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(InstructionTests, ModifyInstruction)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        assembler.mov(x86::eax, Imm(2));

        auto* instrNode = assembler.getCursor();

        // Make copy.
        Instruction instr = assembler.getCursor()->get<Instruction>();

        // Modify operand.
        instr.setOperand(1, Imm(1));

        // Emit modified
        ASSERT_EQ(assembler.emit(instr), ErrorCode::None);

        // Remove original
        program.destroy(instrNode);

        instrNode = assembler.getCursor();
        ASSERT_NE(instrNode, nullptr);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x00400000), ErrorCode::None);

        const std::array<uint8_t, 5> expected = {
            0xB8, 0x01, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(InstructionTests, TestVisit)
    {
        auto ins = zasm::Instruction()                  //
                       .setMnemonic(x86::Mnemonic::Mov) //
                       .addOperand(x86::rax)            //
                       .addOperand(x86::rdx);           //

        // Test if the conversion from base to upper works.
        auto testVisit = [](InstructionBase& base) {
            return base.visit([](auto&& real) {
                //
                real.setMnemonic(x86::Mnemonic::Sub);
                return real.getOperandCount();
            });
        };

        auto detail = ins.getDetail(MachineMode::AMD64);
        detail->addOperand(x86::rdx);

        auto opCount1 = testVisit(ins);
        ASSERT_EQ(ins.getMnemonic(), x86::Mnemonic::Sub);
        ASSERT_EQ(opCount1, 2);

        auto opCount2 = testVisit(*detail);
        ASSERT_EQ(detail->getMnemonic(), x86::Mnemonic::Sub);
        ASSERT_EQ(opCount2, 3);
    }

} // namespace zasm::tests
