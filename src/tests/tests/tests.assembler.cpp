#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(AssemblerTests, TestBindLabel)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        auto label01 = assembler.createLabel();
        ASSERT_EQ(label01.isValid(), true);
        ASSERT_EQ(assembler.bind(label01), Error::None);
    }

    TEST(AssemblerTests, TestDoubleBindLabel)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        auto label01 = assembler.createLabel();
        ASSERT_EQ(label01.isValid(), true);
        ASSERT_EQ(assembler.bind(label01), Error::None);
        ASSERT_EQ(assembler.bind(label01), Error::LabelAlreadyBound);
    }

    TEST(AssemblerTests, TestBindInvalidLabel)
    {
        using namespace zasm::operands;

        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        zasm::Label label01;
        ASSERT_EQ(label01.isValid(), false);
        ASSERT_EQ(assembler.bind(label01), Error::InvalidLabel);
    }

} // namespace zasm::tests