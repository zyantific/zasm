#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(RelocationTests, LeaRax0X64)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);
        Serializer serializer;

        ASSERT_EQ(assembler.lea(rax, qword_ptr(0)), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<uint8_t, 8> expected = {
            0x48, 0x8D, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
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
        ASSERT_EQ(relocInfo->kind, RelocationKind::Displacement);
        ASSERT_EQ(relocInfo->size, BitSize::_32);
        ASSERT_EQ(relocInfo->offset, 4);
    }

    TEST(RelocationTests, LeaEax0X86)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_COMPAT_32);
        Assembler assembler(program);
        Serializer serializer;

        ASSERT_EQ(assembler.lea(eax, dword_ptr(0)), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<uint8_t, 6> expected = {
            0x8D, 0x05, 0x00, 0x00, 0x00, 0x00,
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
        ASSERT_EQ(relocInfo->kind, RelocationKind::Displacement);
        ASSERT_EQ(relocInfo->size, BitSize::_32);
        ASSERT_EQ(relocInfo->offset, 2);
    }

    TEST(RelocationTests, MovEaxLabelX86)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_COMPAT_32);
        Assembler assembler(program);
        Serializer serializer;

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.mov(eax, label), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<uint8_t, 5> expected = {
            0xb8, 0x00, 0x10, 0x40, 0x00,
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
        ASSERT_EQ(relocInfo->kind, RelocationKind::Immediate);
        ASSERT_EQ(relocInfo->size, BitSize::_32);
        ASSERT_EQ(relocInfo->offset, 1);
    }

    TEST(RelocationTests, MovRaxLabelX64)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);
        Serializer serializer;

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.mov(rax, label), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000401000000), Error::None);

        const std::array<uint8_t, 10> expected = {
            0x48, 0xB8, 0x00, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00, 0x00,
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
        ASSERT_EQ(relocInfo->kind, RelocationKind::Immediate);
        ASSERT_EQ(relocInfo->size, BitSize::_64);
        ASSERT_EQ(relocInfo->offset, 2);
    }
    

} // namespace zasm::tests