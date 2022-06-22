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

        ASSERT_EQ(serializer.getRelocationCount(), 0);
        ASSERT_EQ(serializer.getExternalRelocationCount(), 1);
        const auto* relocInfo = serializer.getExternalRelocation(0);
        ASSERT_EQ(relocInfo->kind, RelocationType::Rel32);
        ASSERT_EQ(relocInfo->address, 0x0000000000400003);
        ASSERT_EQ(relocInfo->size, BitSize::_32);
        ASSERT_EQ(relocInfo->offset, 3);
    }

    TEST(ExternalLabelTests, EmbeddedExternalLabelX64)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);
        Serializer serializer;

        auto externalLabel = program.createExternalLabel("external");

        auto labelData = assembler.createLabel("EmbeddedLabelPos");
        ASSERT_EQ(assembler.lea(rax, qword_ptr(labelData)), Error::None);
        ASSERT_EQ(assembler.mov(rdx, qword_ptr(rax)), Error::None);
        ASSERT_EQ(assembler.bind(labelData), Error::None);
        ASSERT_EQ(assembler.embedLabel(externalLabel), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000000400000), Error::None);

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

    TEST(ExternalLabelTests, EmbeddedExternalLabelX86)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_COMPAT_32);
        Assembler assembler(program);
        Serializer serializer;

        auto externalLabel = program.createExternalLabel("external");

        auto labelData = assembler.createLabel("EmbeddedLabelPos");
        ASSERT_EQ(assembler.lea(eax, dword_ptr(labelData)), Error::None);
        ASSERT_EQ(assembler.mov(edx, dword_ptr(eax)), Error::None);
        ASSERT_EQ(assembler.bind(labelData), Error::None);
        ASSERT_EQ(assembler.embedLabel(externalLabel), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000000400000), Error::None);

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
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_COMPAT_32);
        Assembler assembler(program);
        Serializer serializer;

        auto externalLabel = program.createExternalLabel("external");

        auto labelData = assembler.createLabel("EmbeddedLabelPos");
        ASSERT_EQ(assembler.lea(eax, dword_ptr(labelData)), Error::None);
        ASSERT_EQ(assembler.mov(edx, dword_ptr(eax)), Error::None);
        ASSERT_EQ(assembler.bind(labelData), Error::None);
        ASSERT_EQ(assembler.embedLabel(externalLabel), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000000400000), Error::None);

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

        ASSERT_EQ(serializer.relocate(0x0000000000500000), Error::None);

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