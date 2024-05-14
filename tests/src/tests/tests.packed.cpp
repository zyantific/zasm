#include <gtest/gtest.h>
#include <zasm/base/operand.hpp>
#include <zasm/core/packed.hpp>
#include <zasm/x86/register.hpp>

namespace zasm::tests
{
    TEST(PackedTests, TestPackRegs)
    {
        using PackedRegs = Packed<uint64_t, Reg::Id, 9>;
        static_assert(sizeof(PackedRegs) == sizeof(uint64_t));

        PackedRegs regs{};
        ASSERT_EQ(regs.size(), 7);
        ASSERT_EQ(regs.capacity(), 7);

        ASSERT_EQ(regs.get<0>(), Reg::Id::None);
        ASSERT_EQ(regs.get<1>(), Reg::Id::None);
        ASSERT_EQ(regs.get<2>(), Reg::Id::None);
        ASSERT_EQ(regs.get<3>(), Reg::Id::None);
        ASSERT_EQ(regs.get<4>(), Reg::Id::None);
        ASSERT_EQ(regs.get<5>(), Reg::Id::None);
        ASSERT_EQ(regs.get<6>(), Reg::Id::None);
        regs.set<0>(x86::rax.getId());
        ASSERT_EQ(regs.get<0>(), x86::rax.getId());
        ASSERT_EQ(regs.get<1>(), Reg::Id::None);
        ASSERT_EQ(regs.get<2>(), Reg::Id::None);
        ASSERT_EQ(regs.get<3>(), Reg::Id::None);
        ASSERT_EQ(regs.get<4>(), Reg::Id::None);
        ASSERT_EQ(regs.get<5>(), Reg::Id::None);
        ASSERT_EQ(regs.get<6>(), Reg::Id::None);
        regs.set<5>(x86::rcx.getId());
        ASSERT_EQ(regs.get<0>(), x86::rax.getId());
        ASSERT_EQ(regs.get<1>(), Reg::Id::None);
        ASSERT_EQ(regs.get<2>(), Reg::Id::None);
        ASSERT_EQ(regs.get<3>(), Reg::Id::None);
        ASSERT_EQ(regs.get<4>(), Reg::Id::None);
        ASSERT_EQ(regs.get<5>(), x86::rcx.getId());
        ASSERT_EQ(regs.get<6>(), Reg::Id::None);
    }

    TEST(PackedTests, TestPackVisibility)
    {
        using PackedOperandVisibility = Packed<uint32_t, Operand::Visibility, 3>;
        static_assert(sizeof(PackedOperandVisibility) == sizeof(uint32_t));

        PackedOperandVisibility vis{};
        ASSERT_EQ(vis.size(), 10);
        ASSERT_EQ(vis.capacity(), 10);

        ASSERT_EQ(vis.get<0>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<1>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<2>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<3>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<4>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<5>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<6>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<7>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<8>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<9>(), Operand::Visibility::Invalid);
        vis.set<0>(Operand::Visibility::Explicit);
        ASSERT_EQ(vis.get<0>(), Operand::Visibility::Explicit);
        ASSERT_EQ(vis.get<1>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<2>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<3>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<4>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<5>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<6>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<7>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<8>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<9>(), Operand::Visibility::Invalid);
        vis.set<5>(Operand::Visibility::Hidden);
        ASSERT_EQ(vis.get<0>(), Operand::Visibility::Explicit);
        ASSERT_EQ(vis.get<1>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<2>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<3>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<4>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<5>(), Operand::Visibility::Hidden);
        ASSERT_EQ(vis.get<6>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<7>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<8>(), Operand::Visibility::Invalid);
        ASSERT_EQ(vis.get<9>(), Operand::Visibility::Invalid);
    }
} // namespace zasm::tests
