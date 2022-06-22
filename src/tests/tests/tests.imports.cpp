#include <gtest/gtest.h>
#include <string>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(ImportLabelTests, BasicImport)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        const auto labelImpExitProcess = program.getOrCreateImportLabel("kernel32.dll", "ExitProcess");
        ASSERT_TRUE(labelImpExitProcess.isValid());

        const auto labelData = program.getLabelData(labelImpExitProcess);
        ASSERT_TRUE(labelData);
        ASSERT_EQ(std::string(labelData->name), std::string("ExitProcess"));
        ASSERT_EQ(std::string(labelData->moduleName), std::string("kernel32.dll"));
    }

    TEST(ImportLabelTests, TestUnique)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        const auto labelImpExitProcess = program.getOrCreateImportLabel("kernel32.dll", "ExitProcess");
        ASSERT_TRUE(labelImpExitProcess.isValid());

        const auto labelImpExitProcess2 = program.getOrCreateImportLabel("kernel32.dll", "ExitProcess");
        ASSERT_TRUE(labelImpExitProcess2.isValid());
        ASSERT_EQ(labelImpExitProcess.getId(), labelImpExitProcess2.getId());
    }

    TEST(ImportLabelTests, ImportReferenceTestX86)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_COMPAT_32);
        Assembler assembler(program);
        Serializer serializer;

        const auto labelImpExitProcess = program.getOrCreateImportLabel("kernel32.dll", "ExitProcess");
        ASSERT_TRUE(labelImpExitProcess.isValid());

        ASSERT_EQ(assembler.mov(eax, dword_ptr(labelImpExitProcess)), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<uint8_t, 5> expected = {
            0xA1, 0x00, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getExternalRelocationCount(), 1);
        const auto* relocInfo = serializer.getExternalRelocation(0);
        ASSERT_NE(relocInfo, nullptr);
        ASSERT_EQ(relocInfo->kind, RelocationType::Abs);
        ASSERT_EQ(relocInfo->address, 0x0000000000401001);
        ASSERT_EQ(relocInfo->size, BitSize::_32);
        ASSERT_EQ(relocInfo->offset, 1);
        ASSERT_EQ(relocInfo->label, labelImpExitProcess.getId());

        const auto labelData = program.getLabelData(Label{ relocInfo->label });
        ASSERT_TRUE(labelData);
        ASSERT_EQ(std::string(labelData->name), std::string("ExitProcess"));
        ASSERT_EQ(std::string(labelData->moduleName), std::string("kernel32.dll"));
    }

    TEST(ImportLabelTests, ImportReferenceTestX64)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);
        Serializer serializer;

        const auto labelImpExitProcess = program.getOrCreateImportLabel("kernel32.dll", "ExitProcess");
        ASSERT_TRUE(labelImpExitProcess.isValid());

        ASSERT_EQ(assembler.mov(rax, qword_ptr(labelImpExitProcess)), Error::None);
        ASSERT_EQ(serializer.serialize(program, 0x0000000000401000), Error::None);

        const std::array<uint8_t, 7> expected = {
            0x48, 0x8B, 0x05, 0x00, 0x00, 0x00, 0x00,
        };
        ASSERT_EQ(serializer.getCodeSize(), expected.size());

        const auto* data = serializer.getCode();
        ASSERT_NE(data, nullptr);
        for (size_t i = 0; i < expected.size(); i++)
        {
            ASSERT_EQ(data[i], expected[i]);
        }

        ASSERT_EQ(serializer.getExternalRelocationCount(), 1);
        const auto* relocInfo = serializer.getExternalRelocation(0);
        ASSERT_NE(relocInfo, nullptr);
        ASSERT_EQ(relocInfo->kind, RelocationType::Rel32);
        ASSERT_EQ(relocInfo->address, 0x0000000000401003);
        ASSERT_EQ(relocInfo->size, BitSize::_32);
        ASSERT_EQ(relocInfo->offset, 3);
        ASSERT_EQ(relocInfo->label, labelImpExitProcess.getId());

        const auto labelData = program.getLabelData(Label{ relocInfo->label });
        ASSERT_TRUE(labelData);
        ASSERT_EQ(std::string(labelData->name), std::string("ExitProcess"));
        ASSERT_EQ(std::string(labelData->moduleName), std::string("kernel32.dll"));
    }

} // namespace zasm::tests