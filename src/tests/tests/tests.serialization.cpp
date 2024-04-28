#include <cstddef>
#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(SerializationTests, LeaRax0X64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.lea(x86::rax, x86::qword_ptr(0)), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 8> expected = {
            0x48, 0x8D, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, LeaEax0X86)
    {
        Program program(MachineMode::I386);

        x86::Assembler assembler(program);

        ASSERT_EQ(assembler.lea(x86::eax, x86::dword_ptr(0)), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 6> expected = {
            0x8D, 0x05, 0x00, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, LeaRipLabelX64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();

        ASSERT_EQ(assembler.lea(x86::rax, x86::qword_ptr(x86::rip, label)), Error::None);
        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.dq(0x123C312F21329F31ULL), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 15> expected = {
            0x48, 0x8D, 0x05, 0x00, 0x00, 0x00, 0x00, 0x31, 0x9F, 0x32, 0x21, 0x2F, 0x31, 0x3C, 0x12,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, LeaLabelX86)
    {
        Program program(MachineMode::I386);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();

        ASSERT_EQ(assembler.lea(x86::eax, x86::dword_ptr(label)), Error::None);
        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.dq(0x123C312F21329F31ULL), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 14> expected = { 0x8D, 0x05, 0x06, 0x10, 0x40, 0x00, 0x31,
                                                        0x9F, 0x32, 0x21, 0x2F, 0x31, 0x3C, 0x12 };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, JmpLabelRel8FrontX64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();

        ASSERT_EQ(assembler.jmp(label), Error::None);
        for (int i = 0; i < 124; i++)
            ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.int3(), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 127> expected = {
            0xEB, 0x7C, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xCC,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, JmpLabelRel8FrontX86)
    {
        Program program(MachineMode::I386);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();

        ASSERT_EQ(assembler.jmp(label), Error::None);
        for (int i = 0; i < 100; i++)
            ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.align(Align::Type::Code, 16), Error::None);
        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.int3(), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 113> expected = {
            0xEB, 0x6E, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x90, 0xCC,
        };

        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        const auto labelVA = serializer.getLabelAddress(label.getId());
        ASSERT_EQ(labelVA % 16, 0);
        ASSERT_EQ(labelVA, 0x0000000000401070);
    }

    TEST(SerializationTests, JmpLabelRel32FrontX86)
    {
        Program program(MachineMode::I386);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();

        ASSERT_EQ(assembler.jmp(label), Error::None);
        for (int i = 0; i < 124; i++)
            ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.align(Align::Type::Code, 32), Error::None);
        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.int3(), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 161> expected = {
            0xE9, 0x9B, 0x00, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00, 0xCC,
        };

        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, JmpLabelRel8BackX64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.int3(), Error::None);
        for (int i = 0; i < 124; i++)
            ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.jmp(label), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 127> expected = {
            0xCC, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xEB, 0x81,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, JmpLabelRel8BackX86)
    {
        Program program(MachineMode::I386);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.int3(), Error::None);
        for (int i = 0; i < 124; i++)
            ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.jmp(label), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 127> expected = {
            0xCC, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xEB, 0x81,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, JmpLabelRel32BackX64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.int3(), Error::None);
        for (int i = 0; i < 125; i++)
            ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.jmp(label), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 131> expected = {
            0xCC, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xE9, 0x7D, 0xFF, 0xFF, 0xFF,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, JmpLabelRel32BackX86)
    {
        Program program(MachineMode::I386);

        x86::Assembler assembler(program);

        auto label = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.int3(), Error::None);
        for (int i = 0; i < 125; i++)
            ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.jmp(label), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 131> expected = {
            0xCC, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
            0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xE9, 0x7D, 0xFF, 0xFF, 0xFF,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, UnboundLabel)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.lea(x86::rax, x86::qword_ptr(label01)), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::UnresolvedLabel);
    }

    TEST(SerializationTests, UnBoundLabelRegression01)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler a(program);

        Label labelMain = a.createLabel("main");
        Label labelData01 = a.createLabel("data01");
        Label labelData02 = a.createLabel("data02");
        Label labelData03 = a.createLabel("data03");
        Label labelData04 = a.createLabel("data04");
        Label labelData05 = a.createLabel("data05");
        Label labelRData01 = a.createLabel("rdata01");
        Label labelRData02 = a.createLabel("rdata02");
        Label labelRData03 = a.createLabel("rdata03");
        Label labelRData04 = a.createLabel("rdata04");
        Label labelRData05 = a.createLabel("rdata05");
        Label labelStrTitle = a.createLabel("strTitle");
        Label labelStrMessage = a.createLabel("strMessage");
        Label labelImpExitProcess = program.getOrCreateImportLabel("kernel32.dll", "ExitProcess");
        Label labelImpMessageBoxA = program.getOrCreateImportLabel("user32.dll", "MessageBoxA");

        ASSERT_EQ(a.section(".text", Section::Attribs::Code | Section::Attribs::Exec | Section::Attribs::Read), Error::None);
        ASSERT_EQ(a.bind(labelMain), Error::None);
        ASSERT_EQ(a.sub(x86::rsp, Imm(0x28)), Error::None);
        ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(labelRData01)), Error::None);
        ASSERT_EQ(a.lea(x86::rax, x86::qword_ptr(x86::rdx)), Error::None);
        ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(labelData01)), Error::None);
        ASSERT_EQ(a.mov(x86::qword_ptr(x86::rdx), x86::rax), Error::None);
        ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(labelRData02)), Error::None);
        ASSERT_EQ(a.lea(x86::rax, x86::qword_ptr(x86::rdx)), Error::None);
        ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(labelData02)), Error::None);
        ASSERT_EQ(a.mov(x86::qword_ptr(x86::rdx), x86::rax), Error::None);
        ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(labelRData03)), Error::None);
        ASSERT_EQ(a.lea(x86::rax, x86::qword_ptr(x86::rdx)), Error::None);
        ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(labelData03)), Error::None);
        ASSERT_EQ(a.mov(x86::qword_ptr(x86::rdx), x86::rax), Error::None);
        ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(labelRData04)), Error::None);
        ASSERT_EQ(a.lea(x86::rax, x86::qword_ptr(x86::rdx)), Error::None);
        ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(labelData04)), Error::None);
        ASSERT_EQ(a.mov(x86::qword_ptr(x86::rdx), x86::rax), Error::None);
        ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(labelRData05)), Error::None);
        ASSERT_EQ(a.lea(x86::rax, x86::qword_ptr(x86::rdx)), Error::None);
        ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(labelData05)), Error::None);
        ASSERT_EQ(a.mov(x86::qword_ptr(x86::rdx), x86::rax), Error::None);
        ASSERT_EQ(a.xor_(x86::rcx, x86::rcx), Error::None);
        ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(labelStrMessage)), Error::None);
        ASSERT_EQ(a.lea(x86::r8, x86::qword_ptr(labelStrTitle)), Error::None);
        ASSERT_EQ(a.mov(x86::r9, Imm(0)), Error::None);
        ASSERT_EQ(a.call(x86::qword_ptr(labelImpMessageBoxA)), Error::None);
        ASSERT_EQ(a.xor_(x86::rcx, x86::rcx), Error::None);
        ASSERT_EQ(a.call(x86::qword_ptr(labelImpExitProcess)), Error::None);
        ASSERT_EQ(a.add(x86::rsp, Imm(0x28)), Error::None);
        ASSERT_EQ(a.ret(), Error::None);

        ASSERT_EQ(a.section(".data", Section::Attribs::Data | Section::Attribs::Read | Section::Attribs::Write), Error::None);
        ASSERT_EQ(a.bind(labelData01), Error::None);
        ASSERT_EQ(a.dq(01), Error::None);
        ASSERT_EQ(a.bind(labelData02), Error::None);
        ASSERT_EQ(a.dq(02), Error::None);
        ASSERT_EQ(a.bind(labelData03), Error::None);
        ASSERT_EQ(a.dq(03), Error::None);
        ASSERT_EQ(a.bind(labelData04), Error::None);
        ASSERT_EQ(a.dq(04), Error::None);
        ASSERT_EQ(a.bind(labelData05), Error::None);
        ASSERT_EQ(a.dq(05), Error::None);

        ASSERT_EQ(a.section(".rdata", Section::Attribs::RData | Section::Attribs::Read), Error::None);
        ASSERT_EQ(a.bind(labelStrMessage), Error::None);
        ASSERT_EQ(a.embed("Hello World", 12), Error::None);
        ASSERT_EQ(a.bind(labelRData01), Error::None);
        ASSERT_EQ(a.dq(01), Error::None);
        ASSERT_EQ(a.bind(labelRData02), Error::None);
        ASSERT_EQ(a.dq(02), Error::None);
        ASSERT_EQ(a.bind(labelRData03), Error::None);
        ASSERT_EQ(a.dq(03), Error::None);
        ASSERT_EQ(a.bind(labelRData04), Error::None);
        ASSERT_EQ(a.dq(04), Error::None);
        ASSERT_EQ(a.bind(labelRData05), Error::None);
        ASSERT_EQ(a.dq(05), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::UnresolvedLabel);
    }

    TEST(SerializationTests, EmbeddedLabelX64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.embedLabel(label01), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 10> expected = { 0x90, 0x90, 0x00, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00 };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EmbeddedLabelX86)
    {
        Program program(MachineMode::I386);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.embedLabel(label01), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 6> expected = { 0x90, 0x90, 0x00, 0x10, 0x40, 0x00 };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EmbeddedLabelRel8X64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();
        auto label02 = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.bind(label02), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.embedLabelRel(label02, label01, BitSize::_8), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 3> expected = { 0x90, 0x90, 0x01 };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EmbeddedLabelRel8BeforeEmbedX64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();
        auto label02 = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.embedLabelRel(label02, label01, BitSize::_8), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.bind(label02), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 3> expected = { 0x02, 0x90, 0x90 };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EmbeddedLabelRel8BeforeEmbedNegativeX64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();
        auto label02 = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.embedLabelRel(label01, label02, BitSize::_8), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.bind(label02), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 3> expected = { 0xFE, 0x90, 0x90 };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EmbeddedLabelRel16BeforeEmbedX64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();
        auto label02 = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.embedLabelRel(label02, label01, BitSize::_16), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.bind(label02), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 4> expected = { 0x03, 0x00, 0x90, 0x90 };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EmbeddedLabelRel16BeforeEmbedNegativeX64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();
        auto label02 = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.embedLabelRel(label01, label02, BitSize::_16), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.bind(label02), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 4> expected = { 0xFD, 0xFF, 0x90, 0x90 };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EmbeddedLabelRel32BeforeEmbedX64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();
        auto label02 = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.embedLabelRel(label02, label01, BitSize::_32), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.bind(label02), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 6> expected = { 0x05, 0x00, 0x00, 0x00, 0x90, 0x90 };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EmbeddedLabelRel32BeforeEmbedNegativeX64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();
        auto label02 = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.embedLabelRel(label01, label02, BitSize::_32), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.bind(label02), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 6> expected = { 0xFB, 0xFF, 0xFF, 0xFF, 0x90, 0x90 };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EmbedDbRepeat)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.db(0xCC, 16), Error::None);
        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.embedLabel(label01), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 24> expected = {
            0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC,
            0xCC, 0xCC, 0xCC, 0xCC, 0x10, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EmbedDwRepeat)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.dw(0x1234, 8), Error::None);
        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.embedLabel(label01), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 24> expected = {
            0x34, 0x12, 0x34, 0x12, 0x34, 0x12, 0x34, 0x12, 0x34, 0x12, 0x34, 0x12,
            0x34, 0x12, 0x34, 0x12, 0x10, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EmbedDdRepeat)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.dd(0x12345678, 4), Error::None);
        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.embedLabel(label01), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 24> expected = {
            0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12,
            0x78, 0x56, 0x34, 0x12, 0x10, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EmbedDqRepeat)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.dq(0x12345678AABBCCEE, 2), Error::None);
        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.embedLabel(label01), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 24> expected = {
            0xEE, 0xCC, 0xBB, 0xAA, 0x78, 0x56, 0x34, 0x12, 0xEE, 0xCC, 0xBB, 0xAA,
            0x78, 0x56, 0x34, 0x12, 0x10, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, AlignDataTest8)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.db(0xCC, 4), Error::None);

        ASSERT_EQ(assembler.align(Align::Type::Data, 8), Error::None);

        ASSERT_EQ(assembler.bind(label01), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 8> expected = {
            0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getLabelAddress(label01.getId()), 0x0000000000401008);
    }

    TEST(SerializationTests, AlignDataTest16)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.db(0xCC, 4), Error::None);

        ASSERT_EQ(assembler.align(Align::Type::Data, 16), Error::None);

        ASSERT_EQ(assembler.bind(label01), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 16> expected = {
            0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getLabelAddress(label01.getId()), 0x0000000000401010);
    }

    TEST(SerializationTests, AlignDataTest32)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.db(0xCC, 4), Error::None);

        ASSERT_EQ(assembler.align(Align::Type::Data, 32), Error::None);

        ASSERT_EQ(assembler.bind(label01), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 32> expected = {
            0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC,
            0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getLabelAddress(label01.getId()), 0x0000000000401020);
    }

    TEST(SerializationTests, AlignCodeTest8)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.inc(x86::eax), Error::None);

        ASSERT_EQ(assembler.align(Align::Type::Code, 8), Error::None);

        ASSERT_EQ(assembler.bind(label01), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 8> expected = {
            0xFF, 0xC0, 0x66, 0x0F, 0x1F, 0x44, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getLabelAddress(label01.getId()), 0x0000000000401008);
    }

    TEST(SerializationTests, AlignCodeTest16)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.inc(x86::eax), Error::None);

        ASSERT_EQ(assembler.align(Align::Type::Code, 16), Error::None);

        ASSERT_EQ(assembler.bind(label01), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 16> expected = {
            0xFF, 0xC0, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x0F, 0x1F, 0x44, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getLabelAddress(label01.getId()), 0x0000000000401010);
    }

    TEST(SerializationTests, AlignCodeTest32)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();

        ASSERT_EQ(assembler.inc(x86::eax), Error::None);

        ASSERT_EQ(assembler.align(Align::Type::Code, 32), Error::None);

        ASSERT_EQ(assembler.bind(label01), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 32> expected = {
            0xFF, 0xC0, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x0F, 0x1F, 0x44, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getLabelAddress(label01.getId()), 0x0000000000401020);
    }

    TEST(SerializationTests, SerializeDecodedSwapNodes)
    {
        zasm::Program program(zasm::MachineMode::I386);
        std::vector<zasm::Node*> tails = {};

        {
            zasm::x86::Assembler a(program);
            zasm::Decoder decoder(zasm::MachineMode::I386);

            const std::array<uint8_t, 12> raw_data = {
                0xB8, 0x00, 0x10, 0x40, 0x00, // mov eax, [blabla]
                0x83, 0xF8, 0x00,             // cmp eax, 0
                0x90,                         // nop
                0xEB, 0x00,                   // jmp short $+2
                0xC3                          // ret
            };
            const uintptr_t addr = 0x401030;

            size_t offset = 0;
            while (offset < raw_data.size())
            {
                auto v = decoder.decode(raw_data.data() + offset, raw_data.size() - offset, addr + offset);
                a.emit(v->getInstruction());
                tails.emplace_back(program.getTail());
                offset += v->getLength();
            }
        }
        ASSERT_EQ(tails.size(), 5);

        auto label = program.createLabel();
        auto bind_node = program.bindLabel(label);
        program.moveBefore(tails[4], *bind_node);

        tails[3]->getIf<zasm::Instruction>()->setOperand(0, label);

        zasm::x86::Assembler a(program);
        a.setCursor(tails[4]);
        a.xor_(zasm::x86::eax, zasm::x86::eax);

        zasm::Serializer serializer{};
        auto r = serializer.serialize(program, 0x406000);
        ASSERT_EQ(r, zasm::Error::None);

        const std::array<std::uint8_t, 14> expected = { 0xB8, 0x00, 0x10, 0x40, 0x00, 0x83, 0xF8,
                                                        0x00, 0x90, 0xEB, 0x00, 0xC3, 0x31, 0xC0 };
        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        ASSERT_EQ(serializer.getCodeSize(), expected.size());
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, EncodeRipRelAddress)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto reg = x86::rdx;
        auto address = (uint64_t)0x0000000000401000;

        ASSERT_EQ(assembler.mov(x86::Gp64(reg.getId()), x86::qword_ptr(x86::rip, (uintptr_t)address)), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<std::uint8_t, 7> expected = {
            0x48, 0x8B, 0x15, 0xF9, 0xFF, 0xFF, 0xFF
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }
    }

    TEST(SerializationTests, AlignCodeTestJump64)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto label01 = assembler.createLabel();
        auto label02 = assembler.createLabel();
        auto label03 = assembler.createLabel();

        ASSERT_EQ(assembler.bind(label03), Error::None);
        ASSERT_EQ(assembler.jmp(label01), Error::None);
        ASSERT_EQ(assembler.nop(), Error::None);
        ASSERT_EQ(assembler.align(Align::Type::Code, 8), Error::None);
        ASSERT_EQ(assembler.jmp(label02), Error::None);
        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.int3(), Error::None);
        ASSERT_EQ(assembler.align(Align::Type::Code, 10), Error::None);
        ASSERT_EQ(assembler.bind(label02), Error::None);
        ASSERT_EQ(assembler.int3(), Error::None);
        ASSERT_EQ(assembler.jmp(label03), Error::None);
        ASSERT_EQ(assembler.align(Align::Type::Code, 10), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<uint8_t, 30> expected = {
            0xEB, 0x08, 0x90, 0x0F, 0x1F, 0x44, 0x00, 0x00, 0xEB, 0x0A, 0xCC, 0x0F, 0x1F, 0x84, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x90, 0xCC, 0xEB, 0xE9, 0x0F, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getLabelAddress(label01.getId()), 0x000000000040100a);
        ASSERT_EQ(serializer.getLabelAddress(label02.getId()), 0x0000000000401014);
        ASSERT_EQ(serializer.getLabelAddress(label03.getId()), 0x0000000000401000);
    }

    TEST(SerializationTests, TestBasicLea)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler a(program);

        auto label = a.createLabel();
        ASSERT_EQ(a.push(x86::rbp), Error::None);
        ASSERT_EQ(a.lea(x86::rbp, x86::qword_ptr(x86::rip, label)), Error::None);
        ASSERT_EQ(a.xchg(x86::qword_ptr(x86::rsp), x86::rbp), Error::None);
        ASSERT_EQ(a.ret(), Error::None);
        ASSERT_EQ(a.bind(label), Error::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x140015000), Error::None);

        const std::array<uint8_t, 13> expected = {
            0x55, 0x48, 0x8D, 0x2D, 0x05, 0x00, 0x00, 0x00, 0x48, 0x87, 0x2C, 0x24, 0xC3,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (std::size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getLabelAddress(label.getId()), 0x140015000 + 13);
    }

} // namespace zasm::tests
