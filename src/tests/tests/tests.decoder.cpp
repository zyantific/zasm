#include "../testutils.hpp"

#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(DecoderTests, DecodeToAssembler)
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
        
        ASSERT_EQ(assembler.emit(decoded.value()), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x00400000), Error::None);

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

} // namespace zasm::tests
