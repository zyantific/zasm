#pragma once

#include <Zydis/Zydis.h>
#include <zasm/base/register.hpp>

namespace zasm::x86
{
    using Reg = zasm::Reg;

    // Strong type for general purpose regs.
    class Gp  : public Reg 
    {
    public:
        using Reg::Reg;

        Gp r8lo() const noexcept;
        Gp r8() const noexcept;
        Gp r8hi() const noexcept;
        Gp r16() const noexcept;
        Gp r32() const noexcept;
        Gp r64() const noexcept;
    };

    class Gp8 final : public Gp
    {
    public:
        using Gp::Gp;
    };

    class Gp16 final : public Gp
    {
    public:
        using Gp::Gp;
    };

    class Gp32 final : public Gp
    {
    public:
        using Gp::Gp;
    };

    class Gp64 final : public Gp
    {
    public:
        using Gp::Gp;
    };

    class Rip final : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Seg final : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Mmx final : public Reg
    {
    public:
        using Reg::Reg;
    };

    class St final : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Tmm final : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Xmm final : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Ymm final : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Zmm final : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Cr final : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Dr final : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Tr final : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Mask final : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Bnd final : public Reg
    {
    public:
        using Reg::Reg;
    };

    // General purpose registers  8-bit
    static constexpr Gp8 al(static_cast<Reg::Id>(ZYDIS_REGISTER_AL));
    static constexpr Gp8 cl(static_cast<Reg::Id>(ZYDIS_REGISTER_CL));
    static constexpr Gp8 dl(static_cast<Reg::Id>(ZYDIS_REGISTER_DL));
    static constexpr Gp8 bl(static_cast<Reg::Id>(ZYDIS_REGISTER_BL));
    static constexpr Gp8 ah(static_cast<Reg::Id>(ZYDIS_REGISTER_AH));
    static constexpr Gp8 ch(static_cast<Reg::Id>(ZYDIS_REGISTER_CH));
    static constexpr Gp8 dh(static_cast<Reg::Id>(ZYDIS_REGISTER_DH));
    static constexpr Gp8 bh(static_cast<Reg::Id>(ZYDIS_REGISTER_BH));
    static constexpr Gp8 spl(static_cast<Reg::Id>(ZYDIS_REGISTER_SPL));
    static constexpr Gp8 bpl(static_cast<Reg::Id>(ZYDIS_REGISTER_BPL));
    static constexpr Gp8 sil(static_cast<Reg::Id>(ZYDIS_REGISTER_SIL));
    static constexpr Gp8 dil(static_cast<Reg::Id>(ZYDIS_REGISTER_DIL));
    static constexpr Gp8 r8b(static_cast<Reg::Id>(ZYDIS_REGISTER_R8B));
    static constexpr Gp8 r9b(static_cast<Reg::Id>(ZYDIS_REGISTER_R9B));
    static constexpr Gp8 r10b(static_cast<Reg::Id>(ZYDIS_REGISTER_R10B));
    static constexpr Gp8 r11b(static_cast<Reg::Id>(ZYDIS_REGISTER_R11B));
    static constexpr Gp8 r12b(static_cast<Reg::Id>(ZYDIS_REGISTER_R12B));
    static constexpr Gp8 r13b(static_cast<Reg::Id>(ZYDIS_REGISTER_R13B));
    static constexpr Gp8 r14b(static_cast<Reg::Id>(ZYDIS_REGISTER_R14B));
    static constexpr Gp8 r15b(static_cast<Reg::Id>(ZYDIS_REGISTER_R15B));
    // General purpose registers 16-bit
    static constexpr Gp16 ax(static_cast<Reg::Id>(ZYDIS_REGISTER_AX));
    static constexpr Gp16 cx(static_cast<Reg::Id>(ZYDIS_REGISTER_CX));
    static constexpr Gp16 dx(static_cast<Reg::Id>(ZYDIS_REGISTER_DX));
    static constexpr Gp16 bx(static_cast<Reg::Id>(ZYDIS_REGISTER_BX));
    static constexpr Gp16 sp(static_cast<Reg::Id>(ZYDIS_REGISTER_SP));
    static constexpr Gp16 bp(static_cast<Reg::Id>(ZYDIS_REGISTER_BP));
    static constexpr Gp16 si(static_cast<Reg::Id>(ZYDIS_REGISTER_SI));
    static constexpr Gp16 di(static_cast<Reg::Id>(ZYDIS_REGISTER_DI));
    static constexpr Gp16 r8w(static_cast<Reg::Id>(ZYDIS_REGISTER_R8W));
    static constexpr Gp16 r9w(static_cast<Reg::Id>(ZYDIS_REGISTER_R9W));
    static constexpr Gp16 r10w(static_cast<Reg::Id>(ZYDIS_REGISTER_R10W));
    static constexpr Gp16 r11w(static_cast<Reg::Id>(ZYDIS_REGISTER_R11W));
    static constexpr Gp16 r12w(static_cast<Reg::Id>(ZYDIS_REGISTER_R12W));
    static constexpr Gp16 r13w(static_cast<Reg::Id>(ZYDIS_REGISTER_R13W));
    static constexpr Gp16 r14w(static_cast<Reg::Id>(ZYDIS_REGISTER_R14W));
    static constexpr Gp16 r15w(static_cast<Reg::Id>(ZYDIS_REGISTER_R15W));
    // General purpose registers 32-bit
    static constexpr Gp32 eax(static_cast<Reg::Id>(ZYDIS_REGISTER_EAX));
    static constexpr Gp32 ecx(static_cast<Reg::Id>(ZYDIS_REGISTER_ECX));
    static constexpr Gp32 edx(static_cast<Reg::Id>(ZYDIS_REGISTER_EDX));
    static constexpr Gp32 ebx(static_cast<Reg::Id>(ZYDIS_REGISTER_EBX));
    static constexpr Gp32 esp(static_cast<Reg::Id>(ZYDIS_REGISTER_ESP));
    static constexpr Gp32 ebp(static_cast<Reg::Id>(ZYDIS_REGISTER_EBP));
    static constexpr Gp32 esi(static_cast<Reg::Id>(ZYDIS_REGISTER_ESI));
    static constexpr Gp32 edi(static_cast<Reg::Id>(ZYDIS_REGISTER_EDI));
    static constexpr Gp32 r8d(static_cast<Reg::Id>(ZYDIS_REGISTER_R8D));
    static constexpr Gp32 r9d(static_cast<Reg::Id>(ZYDIS_REGISTER_R9D));
    static constexpr Gp32 r10d(static_cast<Reg::Id>(ZYDIS_REGISTER_R10D));
    static constexpr Gp32 r11d(static_cast<Reg::Id>(ZYDIS_REGISTER_R11D));
    static constexpr Gp32 r12d(static_cast<Reg::Id>(ZYDIS_REGISTER_R12D));
    static constexpr Gp32 r13d(static_cast<Reg::Id>(ZYDIS_REGISTER_R13D));
    static constexpr Gp32 r14d(static_cast<Reg::Id>(ZYDIS_REGISTER_R14D));
    static constexpr Gp32 r15d(static_cast<Reg::Id>(ZYDIS_REGISTER_R15D));
    // General purpose registers 64-bit
    static constexpr Gp64 rax(static_cast<Reg::Id>(ZYDIS_REGISTER_RAX));
    static constexpr Gp64 rcx(static_cast<Reg::Id>(ZYDIS_REGISTER_RCX));
    static constexpr Gp64 rdx(static_cast<Reg::Id>(ZYDIS_REGISTER_RDX));
    static constexpr Gp64 rbx(static_cast<Reg::Id>(ZYDIS_REGISTER_RBX));
    static constexpr Gp64 rsp(static_cast<Reg::Id>(ZYDIS_REGISTER_RSP));
    static constexpr Gp64 rbp(static_cast<Reg::Id>(ZYDIS_REGISTER_RBP));
    static constexpr Gp64 rsi(static_cast<Reg::Id>(ZYDIS_REGISTER_RSI));
    static constexpr Gp64 rdi(static_cast<Reg::Id>(ZYDIS_REGISTER_RDI));
    static constexpr Gp64 r8(static_cast<Reg::Id>(ZYDIS_REGISTER_R8));
    static constexpr Gp64 r9(static_cast<Reg::Id>(ZYDIS_REGISTER_R9));
    static constexpr Gp64 r10(static_cast<Reg::Id>(ZYDIS_REGISTER_R10));
    static constexpr Gp64 r11(static_cast<Reg::Id>(ZYDIS_REGISTER_R11));
    static constexpr Gp64 r12(static_cast<Reg::Id>(ZYDIS_REGISTER_R12));
    static constexpr Gp64 r13(static_cast<Reg::Id>(ZYDIS_REGISTER_R13));
    static constexpr Gp64 r14(static_cast<Reg::Id>(ZYDIS_REGISTER_R14));
    static constexpr Gp64 r15(static_cast<Reg::Id>(ZYDIS_REGISTER_R15));
    // Floating point legacy registers
    static constexpr St st0(static_cast<Reg::Id>(ZYDIS_REGISTER_ST0));
    static constexpr St st1(static_cast<Reg::Id>(ZYDIS_REGISTER_ST1));
    static constexpr St st2(static_cast<Reg::Id>(ZYDIS_REGISTER_ST2));
    static constexpr St st3(static_cast<Reg::Id>(ZYDIS_REGISTER_ST3));
    static constexpr St st4(static_cast<Reg::Id>(ZYDIS_REGISTER_ST4));
    static constexpr St st5(static_cast<Reg::Id>(ZYDIS_REGISTER_ST5));
    static constexpr St st6(static_cast<Reg::Id>(ZYDIS_REGISTER_ST6));
    static constexpr St st7(static_cast<Reg::Id>(ZYDIS_REGISTER_ST7));
    static constexpr Reg x87control(static_cast<Reg::Id>(ZYDIS_REGISTER_X87CONTROL));
    static constexpr Reg x87status(static_cast<Reg::Id>(ZYDIS_REGISTER_X87STATUS));
    static constexpr Reg x87tag(static_cast<Reg::Id>(ZYDIS_REGISTER_X87TAG));
    // Floating point multimedia registers
    static constexpr Mmx mm0(static_cast<Reg::Id>(ZYDIS_REGISTER_MM0));
    static constexpr Mmx mm1(static_cast<Reg::Id>(ZYDIS_REGISTER_MM1));
    static constexpr Mmx mm2(static_cast<Reg::Id>(ZYDIS_REGISTER_MM2));
    static constexpr Mmx mm3(static_cast<Reg::Id>(ZYDIS_REGISTER_MM3));
    static constexpr Mmx mm4(static_cast<Reg::Id>(ZYDIS_REGISTER_MM4));
    static constexpr Mmx mm5(static_cast<Reg::Id>(ZYDIS_REGISTER_MM5));
    static constexpr Mmx mm6(static_cast<Reg::Id>(ZYDIS_REGISTER_MM6));
    static constexpr Mmx mm7(static_cast<Reg::Id>(ZYDIS_REGISTER_MM7));
    // Floating point vector registers 128-bit
    static constexpr Xmm xmm0(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM0));
    static constexpr Xmm xmm1(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM1));
    static constexpr Xmm xmm2(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM2));
    static constexpr Xmm xmm3(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM3));
    static constexpr Xmm xmm4(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM4));
    static constexpr Xmm xmm5(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM5));
    static constexpr Xmm xmm6(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM6));
    static constexpr Xmm xmm7(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM7));
    static constexpr Xmm xmm8(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM8));
    static constexpr Xmm xmm9(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM9));
    static constexpr Xmm xmm10(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM10));
    static constexpr Xmm xmm11(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM11));
    static constexpr Xmm xmm12(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM12));
    static constexpr Xmm xmm13(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM13));
    static constexpr Xmm xmm14(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM14));
    static constexpr Xmm xmm15(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM15));
    static constexpr Xmm xmm16(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM16));
    static constexpr Xmm xmm17(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM17));
    static constexpr Xmm xmm18(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM18));
    static constexpr Xmm xmm19(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM19));
    static constexpr Xmm xmm20(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM20));
    static constexpr Xmm xmm21(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM21));
    static constexpr Xmm xmm22(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM22));
    static constexpr Xmm xmm23(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM23));
    static constexpr Xmm xmm24(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM24));
    static constexpr Xmm xmm25(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM25));
    static constexpr Xmm xmm26(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM26));
    static constexpr Xmm xmm27(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM27));
    static constexpr Xmm xmm28(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM28));
    static constexpr Xmm xmm29(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM29));
    static constexpr Xmm xmm30(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM30));
    static constexpr Xmm xmm31(static_cast<Reg::Id>(ZYDIS_REGISTER_XMM31));
    // Floating point vector registers 256-bit
    static constexpr Ymm ymm0(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM0));
    static constexpr Ymm ymm1(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM1));
    static constexpr Ymm ymm2(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM2));
    static constexpr Ymm ymm3(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM3));
    static constexpr Ymm ymm4(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM4));
    static constexpr Ymm ymm5(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM5));
    static constexpr Ymm ymm6(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM6));
    static constexpr Ymm ymm7(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM7));
    static constexpr Ymm ymm8(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM8));
    static constexpr Ymm ymm9(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM9));
    static constexpr Ymm ymm10(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM10));
    static constexpr Ymm ymm11(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM11));
    static constexpr Ymm ymm12(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM12));
    static constexpr Ymm ymm13(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM13));
    static constexpr Ymm ymm14(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM14));
    static constexpr Ymm ymm15(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM15));
    static constexpr Ymm ymm16(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM16));
    static constexpr Ymm ymm17(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM17));
    static constexpr Ymm ymm18(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM18));
    static constexpr Ymm ymm19(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM19));
    static constexpr Ymm ymm20(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM20));
    static constexpr Ymm ymm21(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM21));
    static constexpr Ymm ymm22(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM22));
    static constexpr Ymm ymm23(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM23));
    static constexpr Ymm ymm24(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM24));
    static constexpr Ymm ymm25(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM25));
    static constexpr Ymm ymm26(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM26));
    static constexpr Ymm ymm27(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM27));
    static constexpr Ymm ymm28(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM28));
    static constexpr Ymm ymm29(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM29));
    static constexpr Ymm ymm30(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM30));
    static constexpr Ymm ymm31(static_cast<Reg::Id>(ZYDIS_REGISTER_YMM31));
    // Floating point vector registers 512-bit
    static constexpr Zmm zmm0(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM0));
    static constexpr Zmm zmm1(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM1));
    static constexpr Zmm zmm2(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM2));
    static constexpr Zmm zmm3(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM3));
    static constexpr Zmm zmm4(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM4));
    static constexpr Zmm zmm5(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM5));
    static constexpr Zmm zmm6(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM6));
    static constexpr Zmm zmm7(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM7));
    static constexpr Zmm zmm8(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM8));
    static constexpr Zmm zmm9(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM9));
    static constexpr Zmm zmm10(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM10));
    static constexpr Zmm zmm11(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM11));
    static constexpr Zmm zmm12(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM12));
    static constexpr Zmm zmm13(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM13));
    static constexpr Zmm zmm14(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM14));
    static constexpr Zmm zmm15(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM15));
    static constexpr Zmm zmm16(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM16));
    static constexpr Zmm zmm17(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM17));
    static constexpr Zmm zmm18(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM18));
    static constexpr Zmm zmm19(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM19));
    static constexpr Zmm zmm20(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM20));
    static constexpr Zmm zmm21(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM21));
    static constexpr Zmm zmm22(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM22));
    static constexpr Zmm zmm23(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM23));
    static constexpr Zmm zmm24(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM24));
    static constexpr Zmm zmm25(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM25));
    static constexpr Zmm zmm26(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM26));
    static constexpr Zmm zmm27(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM27));
    static constexpr Zmm zmm28(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM28));
    static constexpr Zmm zmm29(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM29));
    static constexpr Zmm zmm30(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM30));
    static constexpr Zmm zmm31(static_cast<Reg::Id>(ZYDIS_REGISTER_ZMM31));
    // Matrix registers
    static constexpr Tmm tmm0(static_cast<Reg::Id>(ZYDIS_REGISTER_TMM0));
    static constexpr Tmm tmm1(static_cast<Reg::Id>(ZYDIS_REGISTER_TMM1));
    static constexpr Tmm tmm2(static_cast<Reg::Id>(ZYDIS_REGISTER_TMM2));
    static constexpr Tmm tmm3(static_cast<Reg::Id>(ZYDIS_REGISTER_TMM3));
    static constexpr Tmm tmm4(static_cast<Reg::Id>(ZYDIS_REGISTER_TMM4));
    static constexpr Tmm tmm5(static_cast<Reg::Id>(ZYDIS_REGISTER_TMM5));
    static constexpr Tmm tmm6(static_cast<Reg::Id>(ZYDIS_REGISTER_TMM6));
    static constexpr Tmm tmm7(static_cast<Reg::Id>(ZYDIS_REGISTER_TMM7));
    // Flags registers
    static constexpr Reg flags(static_cast<Reg::Id>(ZYDIS_REGISTER_FLAGS));
    static constexpr Reg eflags(static_cast<Reg::Id>(ZYDIS_REGISTER_EFLAGS));
    static constexpr Reg rflags(static_cast<Reg::Id>(ZYDIS_REGISTER_RFLAGS));
    // Instruction-pointer registers
    static constexpr Rip ip(static_cast<Reg::Id>(ZYDIS_REGISTER_IP));
    static constexpr Rip eip(static_cast<Reg::Id>(ZYDIS_REGISTER_EIP));
    static constexpr Rip rip(static_cast<Reg::Id>(ZYDIS_REGISTER_RIP));
    // Segment registers
    static constexpr Seg es(static_cast<Reg::Id>(ZYDIS_REGISTER_ES));
    static constexpr Seg cs(static_cast<Reg::Id>(ZYDIS_REGISTER_CS));
    static constexpr Seg ss(static_cast<Reg::Id>(ZYDIS_REGISTER_SS));
    static constexpr Seg ds(static_cast<Reg::Id>(ZYDIS_REGISTER_DS));
    static constexpr Seg fs(static_cast<Reg::Id>(ZYDIS_REGISTER_FS));
    static constexpr Seg gs(static_cast<Reg::Id>(ZYDIS_REGISTER_GS));
    // Table registers
    static constexpr Seg gdtr(static_cast<Reg::Id>(ZYDIS_REGISTER_GDTR));
    static constexpr Seg ldtr(static_cast<Reg::Id>(ZYDIS_REGISTER_LDTR));
    static constexpr Seg idtr(static_cast<Reg::Id>(ZYDIS_REGISTER_IDTR));
    static constexpr Seg tr(static_cast<Reg::Id>(ZYDIS_REGISTER_TR));
    // Test registers
    static constexpr Tr tr0(static_cast<Reg::Id>(ZYDIS_REGISTER_TR0));
    static constexpr Tr tr1(static_cast<Reg::Id>(ZYDIS_REGISTER_TR1));
    static constexpr Tr tr2(static_cast<Reg::Id>(ZYDIS_REGISTER_TR2));
    static constexpr Tr tr3(static_cast<Reg::Id>(ZYDIS_REGISTER_TR3));
    static constexpr Tr tr4(static_cast<Reg::Id>(ZYDIS_REGISTER_TR4));
    static constexpr Tr tr5(static_cast<Reg::Id>(ZYDIS_REGISTER_TR5));
    static constexpr Tr tr6(static_cast<Reg::Id>(ZYDIS_REGISTER_TR6));
    static constexpr Tr tr7(static_cast<Reg::Id>(ZYDIS_REGISTER_TR7));
    // Control registers
    static constexpr Cr cr0(static_cast<Reg::Id>(ZYDIS_REGISTER_CR0));
    static constexpr Cr cr1(static_cast<Reg::Id>(ZYDIS_REGISTER_CR1));
    static constexpr Cr cr2(static_cast<Reg::Id>(ZYDIS_REGISTER_CR2));
    static constexpr Cr cr3(static_cast<Reg::Id>(ZYDIS_REGISTER_CR3));
    static constexpr Cr cr4(static_cast<Reg::Id>(ZYDIS_REGISTER_CR4));
    static constexpr Cr cr5(static_cast<Reg::Id>(ZYDIS_REGISTER_CR5));
    static constexpr Cr cr6(static_cast<Reg::Id>(ZYDIS_REGISTER_CR6));
    static constexpr Cr cr7(static_cast<Reg::Id>(ZYDIS_REGISTER_CR7));
    static constexpr Cr cr8(static_cast<Reg::Id>(ZYDIS_REGISTER_CR8));
    static constexpr Cr cr9(static_cast<Reg::Id>(ZYDIS_REGISTER_CR9));
    static constexpr Cr cr10(static_cast<Reg::Id>(ZYDIS_REGISTER_CR10));
    static constexpr Cr cr11(static_cast<Reg::Id>(ZYDIS_REGISTER_CR11));
    static constexpr Cr cr12(static_cast<Reg::Id>(ZYDIS_REGISTER_CR12));
    static constexpr Cr cr13(static_cast<Reg::Id>(ZYDIS_REGISTER_CR13));
    static constexpr Cr cr14(static_cast<Reg::Id>(ZYDIS_REGISTER_CR14));
    static constexpr Cr cr15(static_cast<Reg::Id>(ZYDIS_REGISTER_CR15));
    // Debug registers
    static constexpr Dr dr0(static_cast<Reg::Id>(ZYDIS_REGISTER_DR0));
    static constexpr Dr dr1(static_cast<Reg::Id>(ZYDIS_REGISTER_DR1));
    static constexpr Dr dr2(static_cast<Reg::Id>(ZYDIS_REGISTER_DR2));
    static constexpr Dr dr3(static_cast<Reg::Id>(ZYDIS_REGISTER_DR3));
    static constexpr Dr dr4(static_cast<Reg::Id>(ZYDIS_REGISTER_DR4));
    static constexpr Dr dr5(static_cast<Reg::Id>(ZYDIS_REGISTER_DR5));
    static constexpr Dr dr6(static_cast<Reg::Id>(ZYDIS_REGISTER_DR6));
    static constexpr Dr dr7(static_cast<Reg::Id>(ZYDIS_REGISTER_DR7));
    static constexpr Dr dr8(static_cast<Reg::Id>(ZYDIS_REGISTER_DR8));
    static constexpr Dr dr9(static_cast<Reg::Id>(ZYDIS_REGISTER_DR9));
    static constexpr Dr dr10(static_cast<Reg::Id>(ZYDIS_REGISTER_DR10));
    static constexpr Dr dr11(static_cast<Reg::Id>(ZYDIS_REGISTER_DR11));
    static constexpr Dr dr12(static_cast<Reg::Id>(ZYDIS_REGISTER_DR12));
    static constexpr Dr dr13(static_cast<Reg::Id>(ZYDIS_REGISTER_DR13));
    static constexpr Dr dr14(static_cast<Reg::Id>(ZYDIS_REGISTER_DR14));
    static constexpr Dr dr15(static_cast<Reg::Id>(ZYDIS_REGISTER_DR15));
    // Mask registers
    static constexpr Mask k0(static_cast<Reg::Id>(ZYDIS_REGISTER_K0));
    static constexpr Mask k1(static_cast<Reg::Id>(ZYDIS_REGISTER_K1));
    static constexpr Mask k2(static_cast<Reg::Id>(ZYDIS_REGISTER_K2));
    static constexpr Mask k3(static_cast<Reg::Id>(ZYDIS_REGISTER_K3));
    static constexpr Mask k4(static_cast<Reg::Id>(ZYDIS_REGISTER_K4));
    static constexpr Mask k5(static_cast<Reg::Id>(ZYDIS_REGISTER_K5));
    static constexpr Mask k6(static_cast<Reg::Id>(ZYDIS_REGISTER_K6));
    static constexpr Mask k7(static_cast<Reg::Id>(ZYDIS_REGISTER_K7));
    // Bound registers
    static constexpr Bnd bnd0(static_cast<Reg::Id>(ZYDIS_REGISTER_BND0));
    static constexpr Bnd bnd1(static_cast<Reg::Id>(ZYDIS_REGISTER_BND1));
    static constexpr Bnd bnd2(static_cast<Reg::Id>(ZYDIS_REGISTER_BND2));
    static constexpr Bnd bnd3(static_cast<Reg::Id>(ZYDIS_REGISTER_BND3));
    static constexpr Bnd bndcfg(static_cast<Reg::Id>(ZYDIS_REGISTER_BNDCFG));
    static constexpr Bnd bndstatus(static_cast<Reg::Id>(ZYDIS_REGISTER_BNDSTATUS));
    // Uncategorized
    static constexpr Reg mxcsr(static_cast<Reg::Id>(ZYDIS_REGISTER_MXCSR));
    static constexpr Reg pkru(static_cast<Reg::Id>(ZYDIS_REGISTER_PKRU));
    static constexpr Reg xcr0(static_cast<Reg::Id>(ZYDIS_REGISTER_XCR0));
    static constexpr Reg uif(static_cast<Reg::Id>(ZYDIS_REGISTER_UIF));

} // namespace zasm::x86
