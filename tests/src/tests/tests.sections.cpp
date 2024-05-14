#include "../testutils.hpp"

#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(SectionTests, TestSectionImplicit)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler a(program);

        auto labelA = a.createLabel();
        ASSERT_EQ(labelA.isValid(), true);

        // .text by default.
        {
            ASSERT_EQ(a.jmp(labelA), ErrorCode::None);
            ASSERT_EQ(a.nop(), ErrorCode::None);
            ASSERT_EQ(a.bind(labelA), ErrorCode::None);
            ASSERT_EQ(a.nop(), ErrorCode::None);
        }

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x00400000), ErrorCode::None);

        ASSERT_EQ(serializer.getSectionCount(), 1);

        const auto* sectInfo01 = serializer.getSectionInfo(0);
        ASSERT_NE(sectInfo01, nullptr);
        ASSERT_EQ(sectInfo01->address, 0x00400000);
        ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo01->physicalSize, 0x4);
        ASSERT_EQ(hexEncode(serializer.getCode() + sectInfo01->offset, sectInfo01->physicalSize), std::string("EB019090"));
    }

    TEST(SectionTests, TestSectionBasic)
    {
        Program program(MachineMode::AMD64);
        x86::Assembler a(program);

        auto labelA = a.createLabel();
        ASSERT_EQ(labelA.isValid(), true);
        auto labelB = a.createLabel();
        ASSERT_EQ(labelB.isValid(), true);
        auto labelC = a.createLabel();
        ASSERT_EQ(labelC.isValid(), true);

        ASSERT_EQ(a.section(".text"), ErrorCode::None);
        {
            ASSERT_EQ(a.lea(x86::rax, x86::qword_ptr(x86::rip, labelA)), ErrorCode::None);
            ASSERT_EQ(a.lea(x86::rbx, x86::qword_ptr(x86::rip, labelB)), ErrorCode::None);
            ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(x86::rip, labelC)), ErrorCode::None);
        }

        ASSERT_EQ(a.section(".data", Section::Attribs::Data), ErrorCode::None);
        {
            ASSERT_EQ(a.bind(labelA), ErrorCode::None);
            ASSERT_EQ(a.dq(0x123456789), ErrorCode::None);
            ASSERT_EQ(a.bind(labelB), ErrorCode::None);
            ASSERT_EQ(a.dq(0x987654321), ErrorCode::None);
            ASSERT_EQ(a.bind(labelC), ErrorCode::None);
            ASSERT_EQ(a.dq(0xABCDEF123), ErrorCode::None);
        }

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x00400000), ErrorCode::None);

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

    TEST(SectionTests, TestSectionMerged)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler a(program);

        auto labelA = a.createLabel();
        ASSERT_EQ(labelA.isValid(), true);
        auto labelB = a.createLabel();
        ASSERT_EQ(labelB.isValid(), true);
        auto labelC = a.createLabel();
        ASSERT_EQ(labelC.isValid(), true);

        ASSERT_EQ(a.section(".text"), ErrorCode::None);
        {
            ASSERT_EQ(a.lea(x86::rax, x86::qword_ptr(x86::rip, labelA)), ErrorCode::None);
            ASSERT_EQ(a.lea(x86::rbx, x86::qword_ptr(x86::rip, labelB)), ErrorCode::None);
            ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(x86::rip, labelC)), ErrorCode::None);
        }

        // Identical name attrib align causes a merge.
        ASSERT_EQ(a.section(".text"), ErrorCode::None);
        {
            ASSERT_EQ(a.lea(x86::rax, x86::qword_ptr(x86::rip, labelA)), ErrorCode::None);
            ASSERT_EQ(a.lea(x86::rbx, x86::qword_ptr(x86::rip, labelB)), ErrorCode::None);
            ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(x86::rip, labelC)), ErrorCode::None);
        }

        ASSERT_EQ(a.section(".data", Section::Attribs::Data), ErrorCode::None);
        {
            ASSERT_EQ(a.bind(labelA), ErrorCode::None);
            ASSERT_EQ(a.dq(0x123456789), ErrorCode::None);
            ASSERT_EQ(a.bind(labelB), ErrorCode::None);
            ASSERT_EQ(a.dq(0x987654321), ErrorCode::None);
            ASSERT_EQ(a.bind(labelC), ErrorCode::None);
            ASSERT_EQ(a.dq(0xABCDEF123), ErrorCode::None);
        }

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x00400000), ErrorCode::None);

        ASSERT_EQ(serializer.getSectionCount(), 2);

        const auto* sectInfo01 = serializer.getSectionInfo(0);
        ASSERT_NE(sectInfo01, nullptr);
        ASSERT_EQ(sectInfo01->address, 0x00400000);
        ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo01->physicalSize, 0x2a);
        ASSERT_EQ(
            hexEncode(serializer.getCode() + sectInfo01->offset, sectInfo01->physicalSize),
            std::string("488D05F90F0000488D1DFA0F0000488D15FB0F0000488D05E40F0000488D1DE50F0000488D15E60F0000"));

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

    TEST(SectionTests, TestSectionSameNameDiffAttrib)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler a(program);

        auto labelA = a.createLabel();
        ASSERT_EQ(labelA.isValid(), true);
        auto labelB = a.createLabel();
        ASSERT_EQ(labelB.isValid(), true);
        auto labelC = a.createLabel();
        ASSERT_EQ(labelC.isValid(), true);

        ASSERT_EQ(a.section(".text"), ErrorCode::None);
        {
            ASSERT_EQ(a.lea(x86::rax, x86::qword_ptr(x86::rip, labelA)), ErrorCode::None);
            ASSERT_EQ(a.lea(x86::rbx, x86::qword_ptr(x86::rip, labelB)), ErrorCode::None);
            ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(x86::rip, labelC)), ErrorCode::None);
        }

        ASSERT_EQ(a.section(".text", Section::Attribs::Exec), ErrorCode::None);
        {
            ASSERT_EQ(a.lea(x86::rax, x86::qword_ptr(x86::rip, labelA)), ErrorCode::None);
            ASSERT_EQ(a.lea(x86::rbx, x86::qword_ptr(x86::rip, labelB)), ErrorCode::None);
            ASSERT_EQ(a.lea(x86::rdx, x86::qword_ptr(x86::rip, labelC)), ErrorCode::None);
        }

        ASSERT_EQ(a.section(".data", Section::Attribs::Data), ErrorCode::None);
        {
            ASSERT_EQ(a.bind(labelA), ErrorCode::None);
            ASSERT_EQ(a.dq(0x123456789), ErrorCode::None);
            ASSERT_EQ(a.bind(labelB), ErrorCode::None);
            ASSERT_EQ(a.dq(0x987654321), ErrorCode::None);
            ASSERT_EQ(a.bind(labelC), ErrorCode::None);
            ASSERT_EQ(a.dq(0xABCDEF123), ErrorCode::None);
        }

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x00400000), ErrorCode::None);

        ASSERT_EQ(serializer.getSectionCount(), 3);

        const auto* sectInfo01 = serializer.getSectionInfo(0);
        ASSERT_NE(sectInfo01, nullptr);
        ASSERT_EQ(sectInfo01->address, 0x00400000);
        ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo01->physicalSize, 0x15);
        ASSERT_EQ(
            hexEncode(serializer.getCode() + sectInfo01->offset, sectInfo01->physicalSize),
            std::string("488D05F91F0000488D1DFA1F0000488D15FB1F0000"));

        const auto* sectInfo02 = serializer.getSectionInfo(1);
        ASSERT_NE(sectInfo02, nullptr);
        ASSERT_EQ(sectInfo02->address, 0x00401000);
        ASSERT_EQ(sectInfo02->attribs, Section::Attribs::Exec);
        ASSERT_EQ(sectInfo02->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo02->physicalSize, 0x15);
        ASSERT_EQ(
            hexEncode(serializer.getCode() + sectInfo02->offset, sectInfo02->physicalSize),
            std::string("488D05F90F0000488D1DFA0F0000488D15FB0F0000"));

        const auto* sectInfo03 = serializer.getSectionInfo(2);
        ASSERT_NE(sectInfo03, nullptr);
        ASSERT_EQ(sectInfo03->address, 0x00402000);
        ASSERT_EQ(sectInfo03->attribs, Section::Attribs::Data);
        ASSERT_EQ(sectInfo03->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo03->physicalSize, 0x18);
        ASSERT_EQ(
            hexEncode(serializer.getCode() + sectInfo03->offset, sectInfo03->physicalSize),
            std::string("8967452301000000214365870900000023F1DEBC0A000000"));
    }

    TEST(SectionTests, TestSectionCrossing01)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler a(program);

        auto labelA = a.createLabel();
        ASSERT_EQ(labelA.isValid(), true);
        auto labelB = a.createLabel();
        ASSERT_EQ(labelB.isValid(), true);
        auto labelC = a.createLabel();
        ASSERT_EQ(labelC.isValid(), true);

        ASSERT_EQ(a.section(".text"), ErrorCode::None);
        {
            ASSERT_EQ(a.bind(labelA), ErrorCode::None);
            ASSERT_EQ(a.jmp(labelB), ErrorCode::None);
        }

        ASSERT_EQ(a.section(".text2", Section::Attribs::Code), ErrorCode::None);
        {
            ASSERT_EQ(a.bind(labelB), ErrorCode::None);
            ASSERT_EQ(a.jmp(labelA), ErrorCode::None);
        }

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x00400000), ErrorCode::None);
        ASSERT_EQ(serializer.getSectionCount(), 2);

        const auto* sectInfo01 = serializer.getSectionInfo(0);
        ASSERT_NE(sectInfo01, nullptr);
        ASSERT_EQ(sectInfo01->address, 0x00400000);
        ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo01->physicalSize, 0x5);
        ASSERT_EQ(hexEncode(serializer.getCode() + sectInfo01->offset, sectInfo01->physicalSize), std::string("E9FB0F0000"));

        const auto* sectInfo02 = serializer.getSectionInfo(1);
        ASSERT_NE(sectInfo02, nullptr);
        ASSERT_EQ(sectInfo02->address, 0x00401000);
        ASSERT_EQ(sectInfo02->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo02->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo02->physicalSize, 0x5);
        ASSERT_EQ(hexEncode(serializer.getCode() + sectInfo02->offset, sectInfo02->physicalSize), std::string("E9FBEFFFFF"));
    }

    TEST(SectionTests, TestSectionCrossing02)
    {
        Program program(MachineMode::AMD64);

        x86::Assembler a(program);

        auto labelA = a.createLabel();
        ASSERT_EQ(labelA.isValid(), true);
        auto labelB = a.createLabel();
        ASSERT_EQ(labelB.isValid(), true);
        auto labelC = a.createLabel();
        ASSERT_EQ(labelC.isValid(), true);

        ASSERT_EQ(a.section(".text"), ErrorCode::None);
        {
            ASSERT_EQ(a.bind(labelA), ErrorCode::None);
            ASSERT_EQ(a.jz(labelB), ErrorCode::None);
        }

        ASSERT_EQ(a.section(".text2", Section::Attribs::Code), ErrorCode::None);
        {
            ASSERT_EQ(a.bind(labelB), ErrorCode::None);
            ASSERT_EQ(a.jz(labelA), ErrorCode::None);
        }

        Serializer serializer;
        ASSERT_EQ(serializer.serialize(program, 0x00400000), ErrorCode::None);
        ASSERT_EQ(serializer.getSectionCount(), 2);

        const auto* sectInfo01 = serializer.getSectionInfo(0);
        ASSERT_NE(sectInfo01, nullptr);
        ASSERT_EQ(sectInfo01->address, 0x00400000);
        ASSERT_EQ(sectInfo01->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo01->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo01->physicalSize, 0x6);
        ASSERT_EQ(hexEncode(serializer.getCode() + sectInfo01->offset, sectInfo01->physicalSize), std::string("0F84FA0F0000"));

        const auto* sectInfo02 = serializer.getSectionInfo(1);
        ASSERT_NE(sectInfo02, nullptr);
        ASSERT_EQ(sectInfo02->address, 0x00401000);
        ASSERT_EQ(sectInfo02->attribs, Section::Attribs::Code);
        ASSERT_EQ(sectInfo02->virtualSize, 0x1000);
        ASSERT_EQ(sectInfo02->physicalSize, 0x6);
        ASSERT_EQ(hexEncode(serializer.getCode() + sectInfo02->offset, sectInfo02->physicalSize), std::string("0F84FAEFFFFF"));
    }

} // namespace zasm::tests
