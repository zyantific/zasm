#include "../testutils.hpp"

#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(ExternalLabelTests, BasicTestX64)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);
        Serializer serializer;

        auto externalLabel = program.createExternalLabel("external");

        ASSERT_EQ(assembler.lea(rax, qword_ptr(externalLabel)), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000000400000), Error::None);

        const std::array<uint8_t, 7> expected = {
            0x48, 0x8D, 0x05, 0x00, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getRelocationCount(), 1);
        const auto* relocInfo = serializer.getRelocation(0);
        ASSERT_EQ(relocInfo->kind, RelocationType::Rel32);
        ASSERT_EQ(relocInfo->address, 0x0000000000400003);
        ASSERT_EQ(relocInfo->size, BitSize::_32);
        ASSERT_EQ(relocInfo->offset, 3);
    }

} // namespace zasm::tests