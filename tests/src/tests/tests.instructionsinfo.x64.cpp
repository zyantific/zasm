#include "../testutils.hpp"

#include <gtest/gtest.h>
#include <zasm/testdata/x86/instructions.hpp>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    class InstructionInfoTestsFixture : public ::testing::TestWithParam<data::InstrTest>
    {
    };

    TEST_P(InstructionInfoTestsFixture, InstructionInfoX64Test)
    {
        const auto& instrTest = GetParam();

        Program program(MachineMode::AMD64);

        x86::Assembler assembler(program);
        ASSERT_EQ(instrTest.emitter(assembler), ErrorCode::None) << instrTest.operation;

        const auto* node = assembler.getCursor();
        ASSERT_NE(node, nullptr);

        const auto& instr = node->get<Instruction>();

        const auto info = instr.getDetail(program.getMode());
        ASSERT_EQ(info.hasValue(), true);

        ASSERT_EQ(instr.getOperandCount(), info->getVisibleOperandCount());

        const auto& instrInfo = info.value();
        for (std::size_t i = 0; i < instr.getOperandCount(); i++)
        {
            const auto& opInfo = instrInfo.getOperand(i);
            const auto& op = instr.getOperand(i);

            ASSERT_EQ(opInfo.getTypeIndex(), op.getTypeIndex());
            if (auto* opInfoMem = opInfo.getIf<Mem>(); opInfoMem != nullptr)
            {
                auto* opMem = op.getIf<Mem>();
                if (opMem->getSegment().isValid())
                {
                    // Segment can be optional, only compare if one is specified by user.
                    ASSERT_EQ(opInfoMem->getSegment(), opMem->getSegment());
                }
                ASSERT_EQ(opInfoMem->getBase(), opMem->getBase());
                ASSERT_EQ(opInfoMem->getIndex(), opMem->getIndex());
                ASSERT_EQ(opInfoMem->getScale(), opMem->getScale());
                ASSERT_EQ(opInfoMem->getDisplacement(), opMem->getDisplacement());
            }
            else
            {
                ASSERT_EQ(opInfo, op);
            }
        }
    }

    INSTANTIATE_TEST_SUITE_P(
        InstructionInfoTestsFixture, InstructionInfoTestsFixture,
        ::testing::ValuesIn(std::begin(data::Instructions), std::end(data::Instructions)),
        [](const ::testing::TestParamInfo<data::InstrTest>& info) { return std::string{ info.param.instrBytes }; });

} // namespace zasm::tests
