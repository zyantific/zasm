#include "../testutils.hpp"

#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(SectionTests, TestSectionImplicit)
    {
        using namespace zasm;
        using namespace zasm::operands;

        Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);
        Assembler a(program);

        auto labelA = a.createLabel();
        ASSERT_EQ(labelA.isValid(), true);

        // .text by default.
        {
            ASSERT_EQ(a.jmp(labelA), Error::None);
            ASSERT_EQ(a.nop(), Error::None);
            ASSERT_EQ(a.bind(labelA), Error::None);
            ASSERT_EQ(a.nop(), Error::None);
        }

        ASSERT_EQ(program.serialize(0x00400000), Error::None);

        ASSERT_EQ(program.getSectionCount(), 1);

        const auto* sectInfo01 = program.getSectionInfo(0);
        ASSERT_NE(sectInfo01, nullptr);
        ASSERT_EQ(sectInfo01->va, 0x00400000);
        ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo01->physicalSize, 0x4);
        ASSERT_EQ(
            hexEncode(sectInfo01->buffer, sectInfo01->physicalSize), std::string("EB019090"));
    }

    TEST(SectionTests, TestSectionBasic)
    {
        using namespace zasm;
        using namespace zasm::operands;

        Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);
        Assembler a(program);

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

        ASSERT_EQ(program.serialize(0x00400000), Error::None);

        ASSERT_EQ(program.getSectionCount(), 2);

        const auto* sectInfo01 = program.getSectionInfo(0);
        ASSERT_NE(sectInfo01, nullptr);
        ASSERT_EQ(sectInfo01->va, 0x00400000);
        ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo01->physicalSize, 0x15);
        ASSERT_EQ(
            hexEncode(sectInfo01->buffer, sectInfo01->physicalSize), std::string("488D05F90F0000488D1DFA0F0000488D15FB0F0000"));

        const auto* sectInfo02 = program.getSectionInfo(1);
        ASSERT_NE(sectInfo02, nullptr);
        ASSERT_EQ(sectInfo02->va, 0x00401000);
        ASSERT_EQ(sectInfo02->attribs, Section::Attribs::Data);
        ASSERT_EQ(sectInfo02->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo02->physicalSize, 0x18);
        ASSERT_EQ(
            hexEncode(sectInfo02->buffer, sectInfo02->physicalSize),
            std::string("8967452301000000214365870900000023F1DEBC0A000000"));
    }

    TEST(SectionTests, TestSectionMerged)
    {
        using namespace zasm;
        using namespace zasm::operands;

        Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);
        Assembler a(program);

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

        // Identical name attrib align causes a merge.
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

        ASSERT_EQ(program.serialize(0x00400000), Error::None);

        ASSERT_EQ(program.getSectionCount(), 2);

        const auto* sectInfo01 = program.getSectionInfo(0);
        ASSERT_NE(sectInfo01, nullptr);
        ASSERT_EQ(sectInfo01->va, 0x00400000);
        ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo01->physicalSize, 0x2a);
        ASSERT_EQ(
            hexEncode(sectInfo01->buffer, sectInfo01->physicalSize),
            std::string("488D05F90F0000488D1DFA0F0000488D15FB0F0000488D05E40F0000488D1DE50F0000488D15E60F0000"));

        const auto* sectInfo02 = program.getSectionInfo(1);
        ASSERT_NE(sectInfo02, nullptr);
        ASSERT_EQ(sectInfo02->va, 0x00401000);
        ASSERT_EQ(sectInfo02->attribs, Section::Attribs::Data);
        ASSERT_EQ(sectInfo02->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo02->physicalSize, 0x18);
        ASSERT_EQ(
            hexEncode(sectInfo02->buffer, sectInfo02->physicalSize),
            std::string("8967452301000000214365870900000023F1DEBC0A000000"));
    }

    TEST(SectionTests, TestSectionSameNameDiffAttrib)
    {
        using namespace zasm;
        using namespace zasm::operands;

        Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);
        Assembler a(program);

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

        ASSERT_EQ(a.section(".text", Section::Attribs::Exec), Error::None);
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

        ASSERT_EQ(program.serialize(0x00400000), Error::None);

        ASSERT_EQ(program.getSectionCount(), 3);

        const auto* sectInfo01 = program.getSectionInfo(0);
        ASSERT_NE(sectInfo01, nullptr);
        ASSERT_EQ(sectInfo01->va, 0x00400000);
        ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo01->physicalSize, 0x15);
        ASSERT_EQ(
            hexEncode(sectInfo01->buffer, sectInfo01->physicalSize), std::string("488D05F91F0000488D1DFA1F0000488D15FB1F0000"));

        const auto* sectInfo02 = program.getSectionInfo(1);
        ASSERT_NE(sectInfo02, nullptr);
        ASSERT_EQ(sectInfo02->va, 0x00401000);
        ASSERT_EQ(sectInfo02->attribs, Section::Attribs::Exec);
        ASSERT_EQ(sectInfo02->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo02->physicalSize, 0x15);
        ASSERT_EQ(
            hexEncode(sectInfo02->buffer, sectInfo02->physicalSize), std::string("488D05F90F0000488D1DFA0F0000488D15FB0F0000"));

        const auto* sectInfo03 = program.getSectionInfo(2);
        ASSERT_NE(sectInfo03, nullptr);
        ASSERT_EQ(sectInfo03->va, 0x00402000);
        ASSERT_EQ(sectInfo03->attribs, Section::Attribs::Data);
        ASSERT_EQ(sectInfo03->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo03->physicalSize, 0x18);
        ASSERT_EQ(
            hexEncode(sectInfo03->buffer, sectInfo03->physicalSize),
            std::string("8967452301000000214365870900000023F1DEBC0A000000"));
    }

    TEST(SectionTests, TestSectionCrossing01)
    {
        using namespace zasm;
        using namespace zasm::operands;

        Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);
        Assembler a(program);

        auto labelA = a.createLabel();
        ASSERT_EQ(labelA.isValid(), true);
        auto labelB = a.createLabel();
        ASSERT_EQ(labelB.isValid(), true);
        auto labelC = a.createLabel();
        ASSERT_EQ(labelC.isValid(), true);

        ASSERT_EQ(a.section(".text"), Error::None);
        {
            ASSERT_EQ(a.bind(labelA), Error::None);
            ASSERT_EQ(a.jmp(labelB), Error::None);
        }

        ASSERT_EQ(a.section(".text2", Section::Attribs::Code), Error::None);
        {
            ASSERT_EQ(a.bind(labelB), Error::None);
            ASSERT_EQ(a.jmp(labelA), Error::None);
        }

        ASSERT_EQ(program.serialize(0x00400000), Error::None);

        ASSERT_EQ(program.getSectionCount(), 2);

        const auto* sectInfo01 = program.getSectionInfo(0);
        ASSERT_NE(sectInfo01, nullptr);
        ASSERT_EQ(sectInfo01->va, 0x00400000);
        ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo01->physicalSize, 0x5);
        ASSERT_EQ(hexEncode(sectInfo01->buffer, sectInfo01->physicalSize), std::string("E9FB0F0000"));

        const auto* sectInfo02 = program.getSectionInfo(1);
        ASSERT_NE(sectInfo02, nullptr);
        ASSERT_EQ(sectInfo02->va, 0x00401000);
        ASSERT_EQ(sectInfo02->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo02->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo02->physicalSize, 0x5);
        ASSERT_EQ(hexEncode(sectInfo02->buffer, sectInfo02->physicalSize), std::string("E9FBEFFFFF"));
    }

    TEST(SectionTests, TestSectionCrossing02)
    {
        using namespace zasm;
        using namespace zasm::operands;

        Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);
        Assembler a(program);

        auto labelA = a.createLabel();
        ASSERT_EQ(labelA.isValid(), true);
        auto labelB = a.createLabel();
        ASSERT_EQ(labelB.isValid(), true);
        auto labelC = a.createLabel();
        ASSERT_EQ(labelC.isValid(), true);

        ASSERT_EQ(a.section(".text"), Error::None);
        {
            ASSERT_EQ(a.bind(labelA), Error::None);
            ASSERT_EQ(a.jz(labelB), Error::None);
        }

        ASSERT_EQ(a.section(".text2", Section::Attribs::Code), Error::None);
        {
            ASSERT_EQ(a.bind(labelB), Error::None);
            ASSERT_EQ(a.jz(labelA), Error::None);
        }

        ASSERT_EQ(program.serialize(0x00400000), Error::None);

        ASSERT_EQ(program.getSectionCount(), 2);

        const auto* sectInfo01 = program.getSectionInfo(0);
        ASSERT_NE(sectInfo01, nullptr);
        ASSERT_EQ(sectInfo01->va, 0x00400000);
        ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo01->physicalSize, 0x6);
        ASSERT_EQ(hexEncode(sectInfo01->buffer, sectInfo01->physicalSize), std::string("0F84FA0F0000"));

        const auto* sectInfo02 = program.getSectionInfo(1);
        ASSERT_NE(sectInfo02, nullptr);
        ASSERT_EQ(sectInfo02->va, 0x00401000);
        ASSERT_EQ(sectInfo02->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo02->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo02->physicalSize, 0x6);
        ASSERT_EQ(hexEncode(sectInfo02->buffer, sectInfo02->physicalSize), std::string("0F84FAEFFFFF"));
    }

} // namespace zasm::tests