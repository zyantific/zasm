#include "../testutils.hpp"

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
        ASSERT_EQ(relocInfo->address, 0x0000000000401004);
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
        ASSERT_EQ(relocInfo->address, 0x0000000000401002);
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
        ASSERT_EQ(relocInfo->address, 0x0000000000401001);
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
        ASSERT_EQ(relocInfo->address, 0x0000000401000002);
        ASSERT_EQ(relocInfo->size, BitSize::_64);
        ASSERT_EQ(relocInfo->offset, 2);
    }

    TEST(RelocationTests, MovEaxMemLabelX86)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_COMPAT_32);
        Assembler assembler(program);
        Serializer serializer;

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.mov(eax, dword_ptr(label)), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<uint8_t, 5> expected = {
            0xA1, 0x00, 0x10, 0x40, 0x00,
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
        ASSERT_EQ(relocInfo->address, 0x0000000000401001);
        ASSERT_EQ(relocInfo->size, BitSize::_32);
        ASSERT_EQ(relocInfo->offset, 1);
    }

    TEST(RelocationTests, RelocateX86)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_COMPAT_32);
        Assembler assembler(program);
        Serializer serializer;

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.mov(eax, dword_ptr(label)), Error::None);
        ASSERT_EQ(assembler.embedLabel(label), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        {
            const std::array<uint8_t, 9> expected = {
                0xA1, 0x00, 0x10, 0x40, 0x00, 0x00, 0x10, 0x40, 0x00,
            };
            ASSERT_EQ(serializer.getCodeSize(), expected.size());

            const auto* data = serializer.getCode();
            ASSERT_NE(data, nullptr);
            for (size_t i = 0; i < expected.size(); i++)
            {
                ASSERT_EQ(data[i], expected[i]);
            }

            ASSERT_EQ(serializer.getRelocationCount(), 2);
            const auto* relocInfo01 = serializer.getRelocation(0);
            ASSERT_EQ(relocInfo01->kind, RelocationKind::Displacement);
            ASSERT_EQ(relocInfo01->address, 0x0000000000401001);
            ASSERT_EQ(relocInfo01->size, BitSize::_32);
            ASSERT_EQ(relocInfo01->offset, 1);

            const auto* relocInfo02 = serializer.getRelocation(1);
            ASSERT_EQ(relocInfo02->kind, RelocationKind::Data);
            ASSERT_EQ(relocInfo02->address, 0x0000000000401005);
            ASSERT_EQ(relocInfo02->size, BitSize::_32);
            ASSERT_EQ(relocInfo02->offset, 5);
        }

        ASSERT_EQ(serializer.relocate(0x0000000000501000), Error::None);

        {
            const std::array<uint8_t, 9> expected = {
                0xA1, 0x00, 0x10, 0x50, 0x00, 0x00, 0x10, 0x50, 0x00,
            };
            ASSERT_EQ(serializer.getCodeSize(), expected.size());

            const auto* data = serializer.getCode();
            ASSERT_NE(data, nullptr);
            for (size_t i = 0; i < expected.size(); i++)
            {
                ASSERT_EQ(data[i], expected[i]);
            }

            ASSERT_EQ(serializer.getRelocationCount(), 2);
            const auto* relocInfo01 = serializer.getRelocation(0);
            ASSERT_EQ(relocInfo01->kind, RelocationKind::Displacement);
            ASSERT_EQ(relocInfo01->address, 0x0000000000501001);
            ASSERT_EQ(relocInfo01->size, BitSize::_32);
            ASSERT_EQ(relocInfo01->offset, 1);

            const auto* relocInfo02 = serializer.getRelocation(1);
            ASSERT_EQ(relocInfo02->kind, RelocationKind::Data);
            ASSERT_EQ(relocInfo02->address, 0x0000000000501005);
            ASSERT_EQ(relocInfo02->size, BitSize::_32);
            ASSERT_EQ(relocInfo02->offset, 5);
        }
    }

    TEST(RelocationTests, RelocateX64)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);
        Serializer serializer;

        auto label = assembler.createLabel();
        ASSERT_EQ(assembler.bind(label), Error::None);
        ASSERT_EQ(assembler.mov(rax, label), Error::None);
        ASSERT_EQ(assembler.embedLabel(label), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000401000000), Error::None);

        {
            const std::array<uint8_t, 18> expected = {
                0x48, 0xB8, 0x00, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00, 0x00,
            };
            ASSERT_EQ(serializer.getCodeSize(), expected.size());

            const auto* data = serializer.getCode();
            ASSERT_NE(data, nullptr);
            for (size_t i = 0; i < expected.size(); i++)
            {
                ASSERT_EQ(data[i], expected[i]);
            }

            ASSERT_EQ(serializer.getRelocationCount(), 2);

            const auto* relocInfo01 = serializer.getRelocation(0);
            ASSERT_EQ(relocInfo01->kind, RelocationKind::Immediate);
            ASSERT_EQ(relocInfo01->address, 0x0000000401000002);
            ASSERT_EQ(relocInfo01->size, BitSize::_64);
            ASSERT_EQ(relocInfo01->offset, 2);

            const auto* relocInfo02 = serializer.getRelocation(1);
            ASSERT_EQ(relocInfo02->kind, RelocationKind::Data);
            ASSERT_EQ(relocInfo02->address, 0x000000040100000a);
            ASSERT_EQ(relocInfo02->size, BitSize::_64);
            ASSERT_EQ(relocInfo02->offset, 10);
        }

        ASSERT_EQ(serializer.relocate(0x0000000501000000), Error::None);

        {
            const std::array<uint8_t, 18> expected = {
                0x48, 0xB8, 0x00, 0x00, 0x00, 0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x05, 0x00, 0x00, 0x00,
            };
            ASSERT_EQ(serializer.getCodeSize(), expected.size());

            const auto* data = serializer.getCode();
            ASSERT_NE(data, nullptr);
            for (size_t i = 0; i < expected.size(); i++)
            {
                ASSERT_EQ(data[i], expected[i]);
            }

            ASSERT_EQ(serializer.getRelocationCount(), 2);

            const auto* relocInfo01 = serializer.getRelocation(0);
            ASSERT_EQ(relocInfo01->kind, RelocationKind::Immediate);
            ASSERT_EQ(relocInfo01->address, 0x0000000501000002);
            ASSERT_EQ(relocInfo01->size, BitSize::_64);
            ASSERT_EQ(relocInfo01->offset, 2);

            const auto* relocInfo02 = serializer.getRelocation(1);
            ASSERT_EQ(relocInfo02->kind, RelocationKind::Data);
            ASSERT_EQ(relocInfo02->address, 0x000000050100000a);
            ASSERT_EQ(relocInfo02->size, BitSize::_64);
            ASSERT_EQ(relocInfo02->offset, 10);
        }
    }

    TEST(RelocationTests, RelocateSectionsX64)
    {
        using namespace zasm;
        using namespace zasm::operands;

        Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);
        Assembler a(program);
        Serializer serializer;

        auto labelA = a.createLabel();
        ASSERT_EQ(labelA.isValid(), true);
        auto labelB = a.createLabel();
        ASSERT_EQ(labelB.isValid(), true);
        auto labelC = a.createLabel();
        ASSERT_EQ(labelC.isValid(), true);

        ASSERT_EQ(a.section(".text"), Error::None);
        {
            ASSERT_EQ(a.lea(rax, qword_ptr(labelA)), Error::None);
            ASSERT_EQ(a.lea(rbx, qword_ptr(labelB)), Error::None);
            ASSERT_EQ(a.lea(rdx, qword_ptr(labelC)), Error::None);
        }

        ASSERT_EQ(a.section(".data", Section::Attribs::Data), Error::None);
        {
            ASSERT_EQ(a.bind(labelA), Error::None);
            ASSERT_EQ(a.dq(0x123456789), Error::None);
            ASSERT_EQ(a.bind(labelB), Error::None);
            ASSERT_EQ(a.dq(0x987654321), Error::None);
            ASSERT_EQ(a.bind(labelC), Error::None);
            ASSERT_EQ(a.dq(0xABCDEF123), Error::None);
        }

        ASSERT_EQ(serializer.serialize(program, 0x00400000), Error::None);

        {
            ASSERT_EQ(serializer.getSectionCount(), 2);

            const auto* sectInfo01 = serializer.getSectionInfo(0);
            ASSERT_NE(sectInfo01, nullptr);
            ASSERT_EQ(sectInfo01->address, 0x00400000);
            ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
            ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
            ASSERT_EQ(sectInfo01->physicalSize, 0x15);
            ASSERT_EQ(
                hexEncode(serializer.getCode() + sectInfo01->offset, sectInfo01->physicalSize),
                std::string("488D05F90F0000488D1DFA0F0000488D15FB0F0000"));

            const auto* sectInfo02 = serializer.getSectionInfo(1);
            ASSERT_NE(sectInfo02, nullptr);
            ASSERT_EQ(sectInfo02->address, 0x00401000);
            ASSERT_EQ(sectInfo02->attribs, Section::Attribs::Data);
            ASSERT_EQ(sectInfo02->virtualSize, 0x1000);
            ASSERT_EQ(sectInfo02->physicalSize, 0x18);
            ASSERT_EQ(
                hexEncode(serializer.getCode() + sectInfo02->offset, sectInfo02->physicalSize),
                std::string("8967452301000000214365870900000023F1DEBC0A000000"));
        }
 
        ASSERT_EQ(serializer.relocate(0x00500000), Error::None);

        {
            ASSERT_EQ(serializer.getSectionCount(), 2);

            const auto* sectInfo01 = serializer.getSectionInfo(0);
            ASSERT_NE(sectInfo01, nullptr);
            ASSERT_EQ(sectInfo01->address, 0x00500000);
            ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
            ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
            ASSERT_EQ(sectInfo01->physicalSize, 0x15);
            ASSERT_EQ(
                hexEncode(serializer.getCode() + sectInfo01->offset, sectInfo01->physicalSize),
                std::string("488D05F90F0000488D1DFA0F0000488D15FB0F0000"));

            const auto* sectInfo02 = serializer.getSectionInfo(1);
            ASSERT_NE(sectInfo02, nullptr);
            ASSERT_EQ(sectInfo02->address, 0x00501000);
            ASSERT_EQ(sectInfo02->attribs, Section::Attribs::Data);
            ASSERT_EQ(sectInfo02->virtualSize, 0x1000);
            ASSERT_EQ(sectInfo02->physicalSize, 0x18);
            ASSERT_EQ(
                hexEncode(serializer.getCode() + sectInfo02->offset, sectInfo02->physicalSize),
                std::string("8967452301000000214365870900000023F1DEBC0A000000"));
        }
    }

} // namespace zasm::tests