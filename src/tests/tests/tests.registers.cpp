#include <gtest/gtest.h>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    TEST(RegisterTests, TestGpConvertRax)
    {
        using namespace zasm::operands;

        ASSERT_EQ(al.r8lo(), al);
        ASSERT_EQ(al.r8hi(), ah);
        ASSERT_EQ(al.r16(), ax);
        ASSERT_EQ(al.r32(), eax);
        ASSERT_EQ(al.r64(), rax);
        ASSERT_EQ(ah.r8hi(), ah);
        ASSERT_EQ(ah.r16(), ax);
        ASSERT_EQ(ah.r32(), eax);
        ASSERT_EQ(ah.r64(), rax);
        ASSERT_EQ(ax.r8lo(), al);
        ASSERT_EQ(ax.r8hi(), ah);
        ASSERT_EQ(ax.r16(), ax);
        ASSERT_EQ(ax.r32(), eax);
        ASSERT_EQ(ax.r64(), rax);
        ASSERT_EQ(eax.r8lo(), al);
        ASSERT_EQ(eax.r8hi(), ah);
        ASSERT_EQ(eax.r16(), ax);
        ASSERT_EQ(eax.r32(), eax);
        ASSERT_EQ(eax.r64(), rax);
        ASSERT_EQ(rax.r8lo(), al);
        ASSERT_EQ(rax.r8hi(), ah);
        ASSERT_EQ(rax.r16(), ax);
        ASSERT_EQ(rax.r32(), eax);
        ASSERT_EQ(rax.r64(), rax);
    }

    TEST(RegisterTests, TestGpConvertRbx)
    {
        using namespace zasm::operands;

        ASSERT_EQ(bl.r8lo(), bl);
        ASSERT_EQ(bl.r8hi(), bh);
        ASSERT_EQ(bl.r16(), bx);
        ASSERT_EQ(bl.r32(), ebx);
        ASSERT_EQ(bl.r64(), rbx);
        ASSERT_EQ(bh.r8hi(), bh);
        ASSERT_EQ(bh.r16(), bx);
        ASSERT_EQ(bh.r32(), ebx);
        ASSERT_EQ(bh.r64(), rbx);
        ASSERT_EQ(bx.r8lo(), bl);
        ASSERT_EQ(bx.r8hi(), bh);
        ASSERT_EQ(bx.r16(), bx);
        ASSERT_EQ(bx.r32(), ebx);
        ASSERT_EQ(bx.r64(), rbx);
        ASSERT_EQ(ebx.r8lo(), bl);
        ASSERT_EQ(ebx.r8hi(), bh);
        ASSERT_EQ(ebx.r16(), bx);
        ASSERT_EQ(ebx.r32(), ebx);
        ASSERT_EQ(ebx.r64(), rbx);
        ASSERT_EQ(rbx.r8lo(), bl);
        ASSERT_EQ(rbx.r8hi(), bh);
        ASSERT_EQ(rbx.r16(), bx);
        ASSERT_EQ(rbx.r32(), ebx);
        ASSERT_EQ(rbx.r64(), rbx);
    }

    TEST(RegisterTests, TestGpConvertRcx)
    {
        using namespace zasm::operands;

        ASSERT_EQ(cl.r8lo(), cl);
        ASSERT_EQ(cl.r8hi(), ch);
        ASSERT_EQ(cl.r16(), cx);
        ASSERT_EQ(cl.r32(), ecx);
        ASSERT_EQ(cl.r64(), rcx);
        ASSERT_EQ(ch.r8hi(), ch);
        ASSERT_EQ(ch.r16(), cx);
        ASSERT_EQ(ch.r32(), ecx);
        ASSERT_EQ(ch.r64(), rcx);
        ASSERT_EQ(cx.r8lo(), cl);
        ASSERT_EQ(cx.r8hi(), ch);
        ASSERT_EQ(cx.r16(), cx);
        ASSERT_EQ(cx.r32(), ecx);
        ASSERT_EQ(cx.r64(), rcx);
        ASSERT_EQ(ecx.r8lo(), cl);
        ASSERT_EQ(ecx.r8hi(), ch);
        ASSERT_EQ(ecx.r16(), cx);
        ASSERT_EQ(ecx.r32(), ecx);
        ASSERT_EQ(ecx.r64(), rcx);
        ASSERT_EQ(rcx.r8lo(), cl);
        ASSERT_EQ(rcx.r8hi(), ch);
        ASSERT_EQ(rcx.r16(), cx);
        ASSERT_EQ(rcx.r32(), ecx);
        ASSERT_EQ(rcx.r64(), rcx);
    }

    TEST(RegisterTests, TestGpConvertRdx)
    {
        using namespace zasm::operands;

        ASSERT_EQ(dl.r8lo(), dl);
        ASSERT_EQ(dl.r8hi(), dh);
        ASSERT_EQ(dl.r16(), dx);
        ASSERT_EQ(dl.r32(), edx);
        ASSERT_EQ(dl.r64(), rdx);
        ASSERT_EQ(dh.r8hi(), dh);
        ASSERT_EQ(dh.r16(), dx);
        ASSERT_EQ(dh.r32(), edx);
        ASSERT_EQ(dh.r64(), rdx);
        ASSERT_EQ(dx.r8lo(), dl);
        ASSERT_EQ(dx.r8hi(), dh);
        ASSERT_EQ(dx.r16(), dx);
        ASSERT_EQ(dx.r32(), edx);
        ASSERT_EQ(dx.r64(), rdx);
        ASSERT_EQ(edx.r8lo(), dl);
        ASSERT_EQ(edx.r8hi(), dh);
        ASSERT_EQ(edx.r16(), dx);
        ASSERT_EQ(edx.r32(), edx);
        ASSERT_EQ(edx.r64(), rdx);
        ASSERT_EQ(rdx.r8lo(), dl);
        ASSERT_EQ(rdx.r8hi(), dh);
        ASSERT_EQ(rdx.r16(), dx);
        ASSERT_EQ(rdx.r32(), edx);
        ASSERT_EQ(rdx.r64(), rdx);
    }

    TEST(RegisterTests, TestGpConvertRbp)
    {
        using namespace zasm::operands;

        ASSERT_EQ(bpl.r8lo(), bpl);
        ASSERT_EQ(bpl.r8hi(), Gp{});
        ASSERT_EQ(bpl.r16(), bp);
        ASSERT_EQ(bpl.r32(), ebp);
        ASSERT_EQ(bpl.r64(), rbp);
        ASSERT_EQ(bp.r8lo(), bpl);
        ASSERT_EQ(bp.r8hi(), Gp{});
        ASSERT_EQ(bp.r16(), bp);
        ASSERT_EQ(bp.r32(), ebp);
        ASSERT_EQ(bp.r64(), rbp);
        ASSERT_EQ(ebp.r8lo(), bpl);
        ASSERT_EQ(ebp.r8hi(), Gp{});
        ASSERT_EQ(ebp.r16(), bp);
        ASSERT_EQ(ebp.r32(), ebp);
        ASSERT_EQ(ebp.r64(), rbp);
        ASSERT_EQ(rbp.r8lo(), bpl);
        ASSERT_EQ(rbp.r8hi(), Gp{});
        ASSERT_EQ(rbp.r16(), bp);
        ASSERT_EQ(rbp.r32(), ebp);
        ASSERT_EQ(rbp.r64(), rbp);
    }

    TEST(RegisterTests, TestGpConvertRsp)
    {
        using namespace zasm::operands;

        ASSERT_EQ(spl.r8lo(), spl);
        ASSERT_EQ(spl.r8hi(), Gp{});
        ASSERT_EQ(spl.r16(), sp);
        ASSERT_EQ(spl.r32(), esp);
        ASSERT_EQ(spl.r64(), rsp);
        ASSERT_EQ(sp.r8lo(), spl);
        ASSERT_EQ(sp.r8hi(), Gp{});
        ASSERT_EQ(sp.r16(), sp);
        ASSERT_EQ(sp.r32(), esp);
        ASSERT_EQ(sp.r64(), rsp);
        ASSERT_EQ(esp.r8lo(), spl);
        ASSERT_EQ(esp.r8hi(), Gp{});
        ASSERT_EQ(esp.r16(), sp);
        ASSERT_EQ(esp.r32(), esp);
        ASSERT_EQ(esp.r64(), rsp);
        ASSERT_EQ(rsp.r8lo(), spl);
        ASSERT_EQ(rsp.r8hi(), Gp{});
        ASSERT_EQ(rsp.r16(), sp);
        ASSERT_EQ(rsp.r32(), esp);
        ASSERT_EQ(rsp.r64(), rsp);
    }

    TEST(RegisterTests, TestGpConvertRsi)
    {
        using namespace zasm::operands;

        ASSERT_EQ(sil.r8lo(), sil);
        ASSERT_EQ(sil.r8hi(), Gp{});
        ASSERT_EQ(sil.r16(), si);
        ASSERT_EQ(sil.r32(), esi);
        ASSERT_EQ(sil.r64(), rsi);
        ASSERT_EQ(si.r8lo(), sil);
        ASSERT_EQ(si.r8hi(), Gp{});
        ASSERT_EQ(si.r16(), si);
        ASSERT_EQ(si.r32(), esi);
        ASSERT_EQ(si.r64(), rsi);
        ASSERT_EQ(esi.r8lo(), sil);
        ASSERT_EQ(esi.r8hi(), Gp{});
        ASSERT_EQ(esi.r16(), si);
        ASSERT_EQ(esi.r32(), esi);
        ASSERT_EQ(esi.r64(), rsi);
        ASSERT_EQ(rsi.r8lo(), sil);
        ASSERT_EQ(rsi.r8hi(), Gp{});
        ASSERT_EQ(rsi.r16(), si);
        ASSERT_EQ(rsi.r32(), esi);
        ASSERT_EQ(rsi.r64(), rsi);
    }

    TEST(RegisterTests, TestGpConvertRdi)
    {
        using namespace zasm::operands;

        ASSERT_EQ(dil.r8lo(), dil);
        ASSERT_EQ(dil.r8hi(), Gp{});
        ASSERT_EQ(dil.r16(), di);
        ASSERT_EQ(dil.r32(), edi);
        ASSERT_EQ(dil.r64(), rdi);
        ASSERT_EQ(di.r8lo(), dil);
        ASSERT_EQ(di.r8hi(), Gp{});
        ASSERT_EQ(di.r16(), di);
        ASSERT_EQ(di.r32(), edi);
        ASSERT_EQ(di.r64(), rdi);
        ASSERT_EQ(edi.r8lo(), dil);
        ASSERT_EQ(edi.r8hi(), Gp{});
        ASSERT_EQ(edi.r16(), di);
        ASSERT_EQ(edi.r32(), edi);
        ASSERT_EQ(edi.r64(), rdi);
        ASSERT_EQ(rdi.r8lo(), dil);
        ASSERT_EQ(rdi.r8hi(), Gp{});
        ASSERT_EQ(rdi.r16(), di);
        ASSERT_EQ(rdi.r32(), edi);
        ASSERT_EQ(rdi.r64(), rdi);
    }

    TEST(RegisterTests, TestGpConvertR8)
    {
        using namespace zasm::operands;

        ASSERT_EQ(r8b.r8lo(), r8b);
        ASSERT_EQ(r8b.r8hi(), Gp{});
        ASSERT_EQ(r8b.r16(), r8w);
        ASSERT_EQ(r8b.r32(), r8d);
        ASSERT_EQ(r8b.r64(), r8);
        ASSERT_EQ(r8w.r8lo(), r8b);
        ASSERT_EQ(r8w.r8hi(), Gp{});
        ASSERT_EQ(r8w.r16(), r8w);
        ASSERT_EQ(r8w.r32(), r8d);
        ASSERT_EQ(r8w.r64(), r8);
        ASSERT_EQ(r8d.r8lo(), r8b);
        ASSERT_EQ(r8d.r8hi(), Gp{});
        ASSERT_EQ(r8d.r16(), r8w);
        ASSERT_EQ(r8d.r32(), r8d);
        ASSERT_EQ(r8d.r64(), r8);
        ASSERT_EQ(r8.r8lo(), r8b);
        ASSERT_EQ(r8.r8hi(), Gp{});
        ASSERT_EQ(r8.r16(), r8w);
        ASSERT_EQ(r8.r32(), r8d);
        ASSERT_EQ(r8.r64(), r8);
    }

    TEST(RegisterTests, TestGpConvertR9)
    {
        using namespace zasm::operands;

        ASSERT_EQ(r9b.r8lo(), r9b);
        ASSERT_EQ(r9b.r8hi(), Gp{});
        ASSERT_EQ(r9b.r16(), r9w);
        ASSERT_EQ(r9b.r32(), r9d);
        ASSERT_EQ(r9b.r64(), r9);
        ASSERT_EQ(r9w.r8lo(), r9b);
        ASSERT_EQ(r9w.r8hi(), Gp{});
        ASSERT_EQ(r9w.r16(), r9w);
        ASSERT_EQ(r9w.r32(), r9d);
        ASSERT_EQ(r9w.r64(), r9);
        ASSERT_EQ(r9d.r8lo(), r9b);
        ASSERT_EQ(r9d.r8hi(), Gp{});
        ASSERT_EQ(r9d.r16(), r9w);
        ASSERT_EQ(r9d.r32(), r9d);
        ASSERT_EQ(r9d.r64(), r9);
        ASSERT_EQ(r9.r8lo(), r9b);
        ASSERT_EQ(r9.r8hi(), Gp{});
        ASSERT_EQ(r9.r16(), r9w);
        ASSERT_EQ(r9.r32(), r9d);
        ASSERT_EQ(r9.r64(), r9);
    }

    TEST(RegisterTests, TestGpConvertR10)
    {
        using namespace zasm::operands;

        ASSERT_EQ(r10b.r8lo(), r10b);
        ASSERT_EQ(r10b.r8hi(), Gp{});
        ASSERT_EQ(r10b.r16(), r10w);
        ASSERT_EQ(r10b.r32(), r10d);
        ASSERT_EQ(r10b.r64(), r10);
        ASSERT_EQ(r10w.r8lo(), r10b);
        ASSERT_EQ(r10w.r8hi(), Gp{});
        ASSERT_EQ(r10w.r16(), r10w);
        ASSERT_EQ(r10w.r32(), r10d);
        ASSERT_EQ(r10w.r64(), r10);
        ASSERT_EQ(r10d.r8lo(), r10b);
        ASSERT_EQ(r10d.r8hi(), Gp{});
        ASSERT_EQ(r10d.r16(), r10w);
        ASSERT_EQ(r10d.r32(), r10d);
        ASSERT_EQ(r10d.r64(), r10);
        ASSERT_EQ(r10.r8lo(), r10b);
        ASSERT_EQ(r10.r8hi(), Gp{});
        ASSERT_EQ(r10.r16(), r10w);
        ASSERT_EQ(r10.r32(), r10d);
        ASSERT_EQ(r10.r64(), r10);
    }

    TEST(RegisterTests, TestGpConvertR11)
    {
        using namespace zasm::operands;

        ASSERT_EQ(r11b.r8lo(), r11b);
        ASSERT_EQ(r11b.r8hi(), Gp{});
        ASSERT_EQ(r11b.r16(), r11w);
        ASSERT_EQ(r11b.r32(), r11d);
        ASSERT_EQ(r11b.r64(), r11);
        ASSERT_EQ(r11w.r8lo(), r11b);
        ASSERT_EQ(r11w.r8hi(), Gp{});
        ASSERT_EQ(r11w.r16(), r11w);
        ASSERT_EQ(r11w.r32(), r11d);
        ASSERT_EQ(r11w.r64(), r11);
        ASSERT_EQ(r11d.r8lo(), r11b);
        ASSERT_EQ(r11d.r8hi(), Gp{});
        ASSERT_EQ(r11d.r16(), r11w);
        ASSERT_EQ(r11d.r32(), r11d);
        ASSERT_EQ(r11d.r64(), r11);
        ASSERT_EQ(r11.r8lo(), r11b);
        ASSERT_EQ(r11.r8hi(), Gp{});
        ASSERT_EQ(r11.r16(), r11w);
        ASSERT_EQ(r11.r32(), r11d);
        ASSERT_EQ(r11.r64(), r11);
    }

    TEST(RegisterTests, TestGpConvertR12)
    {
        using namespace zasm::operands;

        ASSERT_EQ(r12b.r8lo(), r12b);
        ASSERT_EQ(r12b.r8hi(), Gp{});
        ASSERT_EQ(r12b.r16(), r12w);
        ASSERT_EQ(r12b.r32(), r12d);
        ASSERT_EQ(r12b.r64(), r12);
        ASSERT_EQ(r12w.r8lo(), r12b);
        ASSERT_EQ(r12w.r8hi(), Gp{});
        ASSERT_EQ(r12w.r16(), r12w);
        ASSERT_EQ(r12w.r32(), r12d);
        ASSERT_EQ(r12w.r64(), r12);
        ASSERT_EQ(r12d.r8lo(), r12b);
        ASSERT_EQ(r12d.r8hi(), Gp{});
        ASSERT_EQ(r12d.r16(), r12w);
        ASSERT_EQ(r12d.r32(), r12d);
        ASSERT_EQ(r12d.r64(), r12);
        ASSERT_EQ(r12.r8lo(), r12b);
        ASSERT_EQ(r12.r8hi(), Gp{});
        ASSERT_EQ(r12.r16(), r12w);
        ASSERT_EQ(r12.r32(), r12d);
        ASSERT_EQ(r12.r64(), r12);
    }

    TEST(RegisterTests, TestGpConvertR13)
    {
        using namespace zasm::operands;

        ASSERT_EQ(r13b.r8lo(), r13b);
        ASSERT_EQ(r13b.r8hi(), Gp{});
        ASSERT_EQ(r13b.r16(), r13w);
        ASSERT_EQ(r13b.r32(), r13d);
        ASSERT_EQ(r13b.r64(), r13);
        ASSERT_EQ(r13w.r8lo(), r13b);
        ASSERT_EQ(r13w.r8hi(), Gp{});
        ASSERT_EQ(r13w.r16(), r13w);
        ASSERT_EQ(r13w.r32(), r13d);
        ASSERT_EQ(r13w.r64(), r13);
        ASSERT_EQ(r13d.r8lo(), r13b);
        ASSERT_EQ(r13d.r8hi(), Gp{});
        ASSERT_EQ(r13d.r16(), r13w);
        ASSERT_EQ(r13d.r32(), r13d);
        ASSERT_EQ(r13d.r64(), r13);
        ASSERT_EQ(r13.r8lo(), r13b);
        ASSERT_EQ(r13.r8hi(), Gp{});
        ASSERT_EQ(r13.r16(), r13w);
        ASSERT_EQ(r13.r32(), r13d);
        ASSERT_EQ(r13.r64(), r13);
    }

    TEST(RegisterTests, TestGpConvertR14)
    {
        using namespace zasm::operands;

        ASSERT_EQ(r14b.r8lo(), r14b);
        ASSERT_EQ(r14b.r8hi(), Gp{});
        ASSERT_EQ(r14b.r16(), r14w);
        ASSERT_EQ(r14b.r32(), r14d);
        ASSERT_EQ(r14b.r64(), r14);
        ASSERT_EQ(r14w.r8lo(), r14b);
        ASSERT_EQ(r14w.r8hi(), Gp{});
        ASSERT_EQ(r14w.r16(), r14w);
        ASSERT_EQ(r14w.r32(), r14d);
        ASSERT_EQ(r14w.r64(), r14);
        ASSERT_EQ(r14d.r8lo(), r14b);
        ASSERT_EQ(r14d.r8hi(), Gp{});
        ASSERT_EQ(r14d.r16(), r14w);
        ASSERT_EQ(r14d.r32(), r14d);
        ASSERT_EQ(r14d.r64(), r14);
        ASSERT_EQ(r14.r8lo(), r14b);
        ASSERT_EQ(r14.r8hi(), Gp{});
        ASSERT_EQ(r14.r16(), r14w);
        ASSERT_EQ(r14.r32(), r14d);
        ASSERT_EQ(r14.r64(), r14);
    }

    TEST(RegisterTests, TestGpConvertR15)
    {
        using namespace zasm::operands;

        ASSERT_EQ(r15b.r8lo(), r15b);
        ASSERT_EQ(r15b.r8hi(), Gp{});
        ASSERT_EQ(r15b.r16(), r15w);
        ASSERT_EQ(r15b.r32(), r15d);
        ASSERT_EQ(r15b.r64(), r15);
        ASSERT_EQ(r15w.r8lo(), r15b);
        ASSERT_EQ(r15w.r8hi(), Gp{});
        ASSERT_EQ(r15w.r16(), r15w);
        ASSERT_EQ(r15w.r32(), r15d);
        ASSERT_EQ(r15w.r64(), r15);
        ASSERT_EQ(r15d.r8lo(), r15b);
        ASSERT_EQ(r15d.r8hi(), Gp{});
        ASSERT_EQ(r15d.r16(), r15w);
        ASSERT_EQ(r15d.r32(), r15d);
        ASSERT_EQ(r15d.r64(), r15);
        ASSERT_EQ(r15.r8lo(), r15b);
        ASSERT_EQ(r15.r8hi(), Gp{});
        ASSERT_EQ(r15.r16(), r15w);
        ASSERT_EQ(r15.r32(), r15d);
        ASSERT_EQ(r15.r64(), r15);
    }

} // namespace zasm::tests