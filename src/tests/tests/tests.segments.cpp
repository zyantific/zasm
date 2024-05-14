#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(AssemblerTests, TestSegmentFS64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.mov(x86::rax, x86::qword_ptr(x86::fs, 0x30)), ErrorCode::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), ErrorCode::None);

        const std::array<uint8_t, 8> expected = {
            0x64, 0x67, 0x48, 0xA1, 0x30, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(AssemblerTests, TestSegmentFS86)
    {
        Program program(MachineMode::I386);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.mov(x86::eax, x86::dword_ptr(x86::fs, 0x30)), ErrorCode::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), ErrorCode::None);

        const std::array<uint8_t, 5> expected = {
            0x64, 0x67, 0xA1, 0x30, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(AssemblerTests, TestSegmentGS64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.mov(x86::rax, x86::qword_ptr(x86::gs, 0x30)), ErrorCode::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), ErrorCode::None);

        const std::array<uint8_t, 8> expected = {
            0x65, 0x67, 0x48, 0xA1, 0x30, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(AssemblerTests, TestSegmentGS86)
    {
        Program program(MachineMode::I386);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.mov(x86::eax, x86::dword_ptr(x86::gs, 0x30)), ErrorCode::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), ErrorCode::None);

        const std::array<uint8_t, 5> expected = {
            0x65, 0x67, 0xA1, 0x30, 0x00,
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
