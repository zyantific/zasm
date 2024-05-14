#include "../testutils.hpp"

#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(ExternalLabelTests, BasicTestX64Rel)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto externalLabel = program.createExternalLabel("external");

        ASSERT_EQ(assembler.lea(x86::rax, x86::qword_ptr(x86::rip, externalLabel)), ErrorCode::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000400000), ErrorCode::None);

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

        ASSERT_EQ(serializer.getRelocationCount(), 0);
        ASSERT_EQ(serializer.getExternalRelocationCount(), 1);
        const auto* relocInfo = serializer.getExternalRelocation(0);
        ASSERT_EQ(relocInfo->kind, RelocationType::Rel32);
        ASSERT_EQ(relocInfo->address, 0x0000000000400003);
        ASSERT_EQ(relocInfo->size, BitSize::_32);
        ASSERT_EQ(relocInfo->offset, 3);
    }

    TEST(ExternalLabelTests, BasicTestX64Abs)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto externalLabel = program.createExternalLabel("external");

        ASSERT_EQ(assembler.lea(x86::rax, x86::qword_ptr(externalLabel)), ErrorCode::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000400000), ErrorCode::None);

        const std::array<uint8_t, 8> expected = { 0x48, 0x8d, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00 };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getRelocationCount(), 0);
        ASSERT_EQ(serializer.getExternalRelocationCount(), 1);
        const auto* relocInfo = serializer.getExternalRelocation(0);
        ASSERT_EQ(relocInfo->kind, RelocationType::Abs);
        ASSERT_EQ(relocInfo->address, 0x0000000000400004);
        ASSERT_EQ(relocInfo->size, BitSize::_32);
        ASSERT_EQ(relocInfo->offset, 4);
    }

    TEST(ExternalLabelTests, EmbeddedExternalLabelX64Rel)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto externalLabel = program.createExternalLabel("external");
        auto labelData = assembler.createLabel("EmbeddedLabelPos");
        ASSERT_EQ(assembler.lea(x86::rax, x86::qword_ptr(x86::rip, labelData)), ErrorCode::None);
        ASSERT_EQ(assembler.mov(x86::rdx, x86::qword_ptr(x86::rax)), ErrorCode::None);
        ASSERT_EQ(assembler.bind(labelData), ErrorCode::None);
        ASSERT_EQ(assembler.embedLabel(externalLabel), ErrorCode::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000400000), ErrorCode::None);

        const std::array<uint8_t, 18> expected = {
            0x48, 0x8D, 0x05, 0x03, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getRelocationCount(), 0);
        ASSERT_EQ(serializer.getExternalRelocationCount(), 1);
        const auto* relocInfo = serializer.getExternalRelocation(0);
        ASSERT_EQ(relocInfo->kind, RelocationType::Abs);
        ASSERT_EQ(relocInfo->address, 0x000000000040000A);
        ASSERT_EQ(relocInfo->size, BitSize::_64);
        ASSERT_EQ(relocInfo->offset, 10);
    }

    TEST(ExternalLabelTests, EmbeddedExternalLabelX64Abs)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);

        auto externalLabel = program.createExternalLabel("external");
        auto labelData = assembler.createLabel("EmbeddedLabelPos");
        ASSERT_EQ(assembler.lea(x86::rax, x86::qword_ptr(labelData)), ErrorCode::None);
        ASSERT_EQ(assembler.mov(x86::rdx, x86::qword_ptr(x86::rax)), ErrorCode::None);
        ASSERT_EQ(assembler.bind(labelData), ErrorCode::None);
        ASSERT_EQ(assembler.embedLabel(externalLabel), ErrorCode::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000400000), ErrorCode::None);

        const std::array<uint8_t, 19> expected = { 0x48, 0x8d, 0x04, 0x25, 0x0b, 0x00, 0x40, 0x00, 0x48, 0x8b,
                                                   0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getRelocationCount(), 1);
        ASSERT_EQ(serializer.getExternalRelocationCount(), 1);
        const auto* relocInfo = serializer.getExternalRelocation(0);
        ASSERT_EQ(relocInfo->kind, RelocationType::Abs);
        ASSERT_EQ(relocInfo->address, 0x000000000040000B);
        ASSERT_EQ(relocInfo->size, BitSize::_64);
        ASSERT_EQ(relocInfo->offset, 11);
    }

    TEST(ExternalLabelTests, EmbeddedExternalLabelX86)
    {
        Program program(MachineMode::I386);

        x86::Assembler assembler(program);

        auto externalLabel = program.createExternalLabel("external");

        auto labelData = assembler.createLabel("EmbeddedLabelPos");
        ASSERT_EQ(assembler.lea(x86::eax, x86::dword_ptr(labelData)), ErrorCode::None);
        ASSERT_EQ(assembler.mov(x86::edx, x86::dword_ptr(x86::eax)), ErrorCode::None);
        ASSERT_EQ(assembler.bind(labelData), ErrorCode::None);
        ASSERT_EQ(assembler.embedLabel(externalLabel), ErrorCode::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000400000), ErrorCode::None);

        const std::array<uint8_t, 12> expected = {
            0x8D, 0x05, 0x08, 0x00, 0x40, 0x00, 0x8B, 0x10, 0x00, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        {
            ASSERT_EQ(serializer.getRelocationCount(), 1);
            const auto* relocInfo = serializer.getRelocation(0);
            ASSERT_EQ(relocInfo->kind, RelocationType::Abs);
            ASSERT_EQ(relocInfo->address, 0x0000000000400002);
            ASSERT_EQ(relocInfo->size, BitSize::_32);
            ASSERT_EQ(relocInfo->offset, 2);
        }
        {
            ASSERT_EQ(serializer.getExternalRelocationCount(), 1);
            const auto* relocInfo = serializer.getExternalRelocation(0);
            ASSERT_EQ(relocInfo->kind, RelocationType::Abs);
            ASSERT_EQ(relocInfo->address, 0x0000000000400008);
            ASSERT_EQ(relocInfo->size, BitSize::_32);
            ASSERT_EQ(relocInfo->offset, 8);
        }
    }

    TEST(ExternalLabelTests, RelocateWithExternalLabelX86)
    {
        Program program(MachineMode::I386);

        x86::Assembler assembler(program);

        auto externalLabel = program.createExternalLabel("external");
        auto labelData = assembler.createLabel("EmbeddedLabelPos");
        ASSERT_EQ(assembler.lea(x86::eax, x86::dword_ptr(labelData)), ErrorCode::None);
        ASSERT_EQ(assembler.mov(x86::edx, x86::dword_ptr(x86::eax)), ErrorCode::None);
        ASSERT_EQ(assembler.bind(labelData), ErrorCode::None);
        ASSERT_EQ(assembler.embedLabel(externalLabel), ErrorCode::None);

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x0000000000400000), ErrorCode::None);

        {
            const std::array<uint8_t, 12> expected = {
                0x8D, 0x05, 0x08, 0x00, 0x40, 0x00, 0x8B, 0x10, 0x00, 0x00, 0x00, 0x00,
            };
            ASSERT_EQ(serializer.getCodeSize(), expected.size());

            const auto* data = serializer.getCode();
            ASSERT_NE(data, nullptr);
            for (size_t i = 0; i < expected.size(); i++)
            {
                ASSERT_EQ(data[i], expected[i]);
            }
        }

        {
            ASSERT_EQ(serializer.getRelocationCount(), 1);
            const auto* relocInfo = serializer.getRelocation(0);
            ASSERT_EQ(relocInfo->kind, RelocationType::Abs);
            ASSERT_EQ(relocInfo->address, 0x0000000000400002);
            ASSERT_EQ(relocInfo->size, BitSize::_32);
            ASSERT_EQ(relocInfo->offset, 2);
        }
        {
            ASSERT_EQ(serializer.getExternalRelocationCount(), 1);
            const auto* relocInfo = serializer.getExternalRelocation(0);
            ASSERT_EQ(relocInfo->kind, RelocationType::Abs);
            ASSERT_EQ(relocInfo->address, 0x0000000000400008);
            ASSERT_EQ(relocInfo->size, BitSize::_32);
            ASSERT_EQ(relocInfo->offset, 8);
        }

        ASSERT_EQ(serializer.relocate(0x0000000000500000), ErrorCode::None);

        {
            const std::array<uint8_t, 12> expected = {
                0x8D, 0x05, 0x08, 0x00, 0x50, 0x00, 0x8B, 0x10, 0x00, 0x00, 0x00, 0x00,
            };
            ASSERT_EQ(serializer.getCodeSize(), expected.size());

            const auto* data = serializer.getCode();
            ASSERT_NE(data, nullptr);
            for (size_t i = 0; i < expected.size(); i++)
            {
                ASSERT_EQ(data[i], expected[i]);
            }
        }

        {
            ASSERT_EQ(serializer.getRelocationCount(), 1);
            const auto* relocInfo = serializer.getRelocation(0);
            ASSERT_EQ(relocInfo->kind, RelocationType::Abs);
            ASSERT_EQ(relocInfo->address, 0x0000000000500002);
            ASSERT_EQ(relocInfo->size, BitSize::_32);
            ASSERT_EQ(relocInfo->offset, 2);
        }
        {
            ASSERT_EQ(serializer.getExternalRelocationCount(), 1);
            const auto* relocInfo = serializer.getExternalRelocation(0);
            ASSERT_EQ(relocInfo->kind, RelocationType::Abs);
            ASSERT_EQ(relocInfo->address, 0x0000000000500008);
            ASSERT_EQ(relocInfo->size, BitSize::_32);
            ASSERT_EQ(relocInfo->offset, 8);
        }
    }

} // namespace zasm::tests
