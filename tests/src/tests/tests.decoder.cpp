#include "../testutils.hpp"

#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(DecoderTests, DecodeToAssembler01)
    {
        Program program(MachineMode::AMD64);
        Decoder decoder(MachineMode::AMD64);

        x86::Assembler assembler(program);

        const std::array<uint8_t, 5> inputBytes = {
            0xB8, 0x01, 0x00, 0x00, 0x00, // mov eax, 0x1
        };

        auto decoded = decoder.decode(inputBytes.data(), inputBytes.size(), 0x00400000);
        ASSERT_TRUE(decoded);

        ASSERT_EQ(decoded->getMnemonic(), x86::Mnemonic::Mov);
        ASSERT_EQ(decoded->getOperandCount(), 2);

        ASSERT_EQ(assembler.emit(decoded.value().getInstruction()), ErrorCode::None);

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

    TEST(DecoderTests, Regression_74)
    {
        Program program(MachineMode::AMD64);
        Decoder decoder(MachineMode::AMD64);

        x86::Assembler assembler(program);

        const std::array<uint8_t, 6> inputBytes = {
            0xFF, 0x15, 0x73, 0x16, 0x00, 0x00, // CALL QWORD PTR DS:[0x00007FF8833E0679]
        };

        auto decoded = decoder.decode(inputBytes.data(), inputBytes.size(), 0x00007FF8833DF000);
        ASSERT_TRUE(decoded);

        ASSERT_EQ(decoded->getMnemonic(), x86::Mnemonic::Call);
        ASSERT_EQ(decoded->getVisibleOperandCount(), 1);
        ASSERT_EQ(decoded->getOperandCount(), 4);
        ASSERT_EQ(decoded->getOperand<Mem>(0).getBase(), x86::rip);
        ASSERT_EQ(decoded->getOperand<Mem>(0).getDisplacement(), 0x00007FF8833E0679);

        ASSERT_EQ(assembler.emit(decoded.value().getInstruction()), ErrorCode::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x00007FF8833DF000), ErrorCode::None);

        const std::array<uint8_t, 6> expected = {
            0xFF, 0x15, 0x73, 0x16, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

} // namespace zasm::tests
