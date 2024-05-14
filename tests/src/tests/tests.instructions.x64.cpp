#include "../testutils.hpp"

#include <gtest/gtest.h>
#include <zasm/testdata/x86/instructions.hpp>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    class InstructionEmitterTestsFixture : public ::testing::TestWithParam<data::InstrTest>
    {
    };

    TEST_P(InstructionEmitterTestsFixture, EncodeTestx64)
    {
        const auto& instrTest = GetParam();

        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        ASSERT_EQ(instrTest.emitter(assembler), ErrorCode::None) << instrTest.operation;

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), ErrorCode::None) << instrTest.operation;

        auto hexEncoded = hexEncode(serializer.getCode(), serializer.getCodeSize());
        ASSERT_EQ(std::string(instrTest.instrBytes), hexEncoded) << instrTest.operation;
    }

    INSTANTIATE_TEST_SUITE_P(
        InstructionEmitterTests, InstructionEmitterTestsFixture,
        ::testing::ValuesIn(std::begin(data::Instructions), std::end(data::Instructions)),
        [](const ::testing::TestParamInfo<data::InstrTest>& info) { return std::string{ info.param.instrBytes }; });

    TEST(InstructionEmitterTests, Combined)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        for (const auto& instrEntry : data::Instructions)
        {
            ASSERT_EQ(instrEntry.emitter(assembler), ErrorCode::None) << instrEntry.instrBytes << ", " << instrEntry.operation;
        }

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), ErrorCode::None);

        const uint8_t* codeBuf = serializer.getCode();
        size_t offset = 0;
        for (const auto& instrEntry : data::Instructions)
        {
            const auto numBytes = instrEntry.instrBytes.size() / 2;
            ASSERT_LE(offset + numBytes, serializer.getCodeSize());

            const auto hexEncoded = hexEncode(codeBuf + offset, numBytes);
            ASSERT_EQ(std::string(instrEntry.instrBytes), hexEncoded);

            offset += numBytes;
        }
    }

} // namespace zasm::tests
