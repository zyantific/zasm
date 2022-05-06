#include <testdata/instructions.hpp>
#include "../testutils.hpp"

#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
	class InstructionTestsFixture : public ::testing::TestWithParam<data::InstrTest>
	{
	};

	TEST_P(InstructionTestsFixture, EncodeTestx64)
    {
        const auto& instrTest = GetParam();

		Program program(ZYDIS_MACHINE_MODE_LONG_64);                                                                           
		Assembler assembler(program);
		Serializer serializer;

		ASSERT_EQ(instrTest.emitter(assembler), Error::None) << instrTest.operation;
		ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None) << instrTest.operation;

		auto hexEncoded = hexEncode(serializer.getCode(), serializer.getCodeSize());
		ASSERT_EQ(std::string(instrTest.instrBytes), hexEncoded) << instrTest.operation;
    }

	INSTANTIATE_TEST_SUITE_P
	(
		InstructionTests, 
		InstructionTestsFixture,
		::testing::ValuesIn(std::begin(data::Instructions), std::end(data::Instructions)),
		[](const ::testing::TestParamInfo<data::InstrTest>& info) 
		{
			return std::string{ info.param.instrBytes };
		}
	);

	TEST(InstructionTests, Combined)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);
		Serializer serializer;

		for (const auto& instrEntry : data::Instructions)
		{
			ASSERT_EQ(instrEntry.emitter(assembler), Error::None) << instrEntry.instrBytes << ", " << instrEntry.operation;
		}

		ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

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