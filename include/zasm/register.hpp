#pragma once

#include "bitsize.hpp"

#include <Zydis/Zydis.h>
#include <cstdint>

namespace zasm::operands
{
    class Reg
    {
    public:
        // For debug builds this makes inspection easier.
        // For release builds size matters more.
#ifdef _DEBUG
        using Id = ZydisRegister;
#else
        using Id = uint16_t;
#endif
    private:
        Id _reg{ ZYDIS_REGISTER_NONE };

    public:
        constexpr Reg() = default;
        constexpr Reg(const ZydisRegister reg)
            : _reg{ static_cast<Id>(reg) }
        {
        }
#ifndef _DEBUG
        constexpr Reg(const Id reg)
            : _reg{ reg }
        {
        }
#endif
        BitSize getSize(ZydisMachineMode mode) const
        {
            return toBitSize(ZydisRegisterGetWidth(mode, id()));
        }

        ZydisRegisterClass getClass() const
        {
            return ZydisRegisterGetClass(id());
        }

        constexpr ZydisRegister id() const
        {
            return static_cast<ZydisRegister>(_reg);
        }

        constexpr bool operator==(const Reg& other) const noexcept
        {
            return _reg == other._reg;
        }

        constexpr bool operator!=(const Reg& other) const noexcept
        {
            return _reg != other._reg;
        }

        constexpr bool operator<(const Reg& other) const noexcept
        {
            return _reg < other._reg;
        }

        constexpr bool operator>(const Reg& other) const noexcept
        {
            return _reg > other._reg;
        }
    };

    // Strong type for Rip related registers.
    class Rip : public Reg
    {
    public:
        using Reg::Reg;
    };

    // Strong type for segment related registers.
    class Seg : public Reg
    {
    public:
        using Reg::Reg;
    };

    static constexpr auto SizeOfReg = sizeof(Reg);

    // General purpose registers  8-bit
    static constexpr Reg al(ZYDIS_REGISTER_AL);
    static constexpr Reg cl(ZYDIS_REGISTER_CL);
    static constexpr Reg dl(ZYDIS_REGISTER_DL);
    static constexpr Reg bl(ZYDIS_REGISTER_BL);
    static constexpr Reg ah(ZYDIS_REGISTER_AH);
    static constexpr Reg ch(ZYDIS_REGISTER_CH);
    static constexpr Reg dh(ZYDIS_REGISTER_DH);
    static constexpr Reg bh(ZYDIS_REGISTER_BH);
    static constexpr Reg spl(ZYDIS_REGISTER_SPL);
    static constexpr Reg bpl(ZYDIS_REGISTER_BPL);
    static constexpr Reg sil(ZYDIS_REGISTER_SIL);
    static constexpr Reg dil(ZYDIS_REGISTER_DIL);
    static constexpr Reg r8b(ZYDIS_REGISTER_R8B);
    static constexpr Reg r9b(ZYDIS_REGISTER_R9B);
    static constexpr Reg r10b(ZYDIS_REGISTER_R10B);
    static constexpr Reg r11b(ZYDIS_REGISTER_R11B);
    static constexpr Reg r12b(ZYDIS_REGISTER_R12B);
    static constexpr Reg r13b(ZYDIS_REGISTER_R13B);
    static constexpr Reg r14b(ZYDIS_REGISTER_R14B);
    static constexpr Reg r15b(ZYDIS_REGISTER_R15B);
    // General purpose registers 16-bit
    static constexpr Reg ax(ZYDIS_REGISTER_AX);
    static constexpr Reg cx(ZYDIS_REGISTER_CX);
    static constexpr Reg dx(ZYDIS_REGISTER_DX);
    static constexpr Reg bx(ZYDIS_REGISTER_BX);
    static constexpr Reg sp(ZYDIS_REGISTER_SP);
    static constexpr Reg bp(ZYDIS_REGISTER_BP);
    static constexpr Reg si(ZYDIS_REGISTER_SI);
    static constexpr Reg di(ZYDIS_REGISTER_DI);
    static constexpr Reg r8w(ZYDIS_REGISTER_R8W);
    static constexpr Reg r9w(ZYDIS_REGISTER_R9W);
    static constexpr Reg r10w(ZYDIS_REGISTER_R10W);
    static constexpr Reg r11w(ZYDIS_REGISTER_R11W);
    static constexpr Reg r12w(ZYDIS_REGISTER_R12W);
    static constexpr Reg r13w(ZYDIS_REGISTER_R13W);
    static constexpr Reg r14w(ZYDIS_REGISTER_R14W);
    static constexpr Reg r15w(ZYDIS_REGISTER_R15W);
    // General purpose registers 32-bit
    static constexpr Reg eax(ZYDIS_REGISTER_EAX);
    static constexpr Reg ecx(ZYDIS_REGISTER_ECX);
    static constexpr Reg edx(ZYDIS_REGISTER_EDX);
    static constexpr Reg ebx(ZYDIS_REGISTER_EBX);
    static constexpr Reg esp(ZYDIS_REGISTER_ESP);
    static constexpr Reg ebp(ZYDIS_REGISTER_EBP);
    static constexpr Reg esi(ZYDIS_REGISTER_ESI);
    static constexpr Reg edi(ZYDIS_REGISTER_EDI);
    static constexpr Reg r8d(ZYDIS_REGISTER_R8D);
    static constexpr Reg r9d(ZYDIS_REGISTER_R9D);
    static constexpr Reg r10d(ZYDIS_REGISTER_R10D);
    static constexpr Reg r11d(ZYDIS_REGISTER_R11D);
    static constexpr Reg r12d(ZYDIS_REGISTER_R12D);
    static constexpr Reg r13d(ZYDIS_REGISTER_R13D);
    static constexpr Reg r14d(ZYDIS_REGISTER_R14D);
    static constexpr Reg r15d(ZYDIS_REGISTER_R15D);
    // General purpose registers 64-bit
    static constexpr Reg rax(ZYDIS_REGISTER_RAX);
    static constexpr Reg rcx(ZYDIS_REGISTER_RCX);
    static constexpr Reg rdx(ZYDIS_REGISTER_RDX);
    static constexpr Reg rbx(ZYDIS_REGISTER_RBX);
    static constexpr Reg rsp(ZYDIS_REGISTER_RSP);
    static constexpr Reg rbp(ZYDIS_REGISTER_RBP);
    static constexpr Reg rsi(ZYDIS_REGISTER_RSI);
    static constexpr Reg rdi(ZYDIS_REGISTER_RDI);
    static constexpr Reg r8(ZYDIS_REGISTER_R8);
    static constexpr Reg r9(ZYDIS_REGISTER_R9);
    static constexpr Reg r10(ZYDIS_REGISTER_R10);
    static constexpr Reg r11(ZYDIS_REGISTER_R11);
    static constexpr Reg r12(ZYDIS_REGISTER_R12);
    static constexpr Reg r13(ZYDIS_REGISTER_R13);
    static constexpr Reg r14(ZYDIS_REGISTER_R14);
    static constexpr Reg r15(ZYDIS_REGISTER_R15);
    // Floating point legacy registers
    static constexpr Reg st0(ZYDIS_REGISTER_ST0);
    static constexpr Reg st1(ZYDIS_REGISTER_ST1);
    static constexpr Reg st2(ZYDIS_REGISTER_ST2);
    static constexpr Reg st3(ZYDIS_REGISTER_ST3);
    static constexpr Reg st4(ZYDIS_REGISTER_ST4);
    static constexpr Reg st5(ZYDIS_REGISTER_ST5);
    static constexpr Reg st6(ZYDIS_REGISTER_ST6);
    static constexpr Reg st7(ZYDIS_REGISTER_ST7);
    static constexpr Reg x87control(ZYDIS_REGISTER_X87CONTROL);
    static constexpr Reg x87status(ZYDIS_REGISTER_X87STATUS);
    static constexpr Reg x87tag(ZYDIS_REGISTER_X87TAG);
    // Floating point multimedia registers
    static constexpr Reg mm0(ZYDIS_REGISTER_MM0);
    static constexpr Reg mm1(ZYDIS_REGISTER_MM1);
    static constexpr Reg mm2(ZYDIS_REGISTER_MM2);
    static constexpr Reg mm3(ZYDIS_REGISTER_MM3);
    static constexpr Reg mm4(ZYDIS_REGISTER_MM4);
    static constexpr Reg mm5(ZYDIS_REGISTER_MM5);
    static constexpr Reg mm6(ZYDIS_REGISTER_MM6);
    static constexpr Reg mm7(ZYDIS_REGISTER_MM7);
    // Floating point vector registers 128-bit
    static constexpr Reg xmm0(ZYDIS_REGISTER_XMM0);
    static constexpr Reg xmm1(ZYDIS_REGISTER_XMM1);
    static constexpr Reg xmm2(ZYDIS_REGISTER_XMM2);
    static constexpr Reg xmm3(ZYDIS_REGISTER_XMM3);
    static constexpr Reg xmm4(ZYDIS_REGISTER_XMM4);
    static constexpr Reg xmm5(ZYDIS_REGISTER_XMM5);
    static constexpr Reg xmm6(ZYDIS_REGISTER_XMM6);
    static constexpr Reg xmm7(ZYDIS_REGISTER_XMM7);
    static constexpr Reg xmm8(ZYDIS_REGISTER_XMM8);
    static constexpr Reg xmm9(ZYDIS_REGISTER_XMM9);
    static constexpr Reg xmm10(ZYDIS_REGISTER_XMM10);
    static constexpr Reg xmm11(ZYDIS_REGISTER_XMM11);
    static constexpr Reg xmm12(ZYDIS_REGISTER_XMM12);
    static constexpr Reg xmm13(ZYDIS_REGISTER_XMM13);
    static constexpr Reg xmm14(ZYDIS_REGISTER_XMM14);
    static constexpr Reg xmm15(ZYDIS_REGISTER_XMM15);
    static constexpr Reg xmm16(ZYDIS_REGISTER_XMM16);
    static constexpr Reg xmm17(ZYDIS_REGISTER_XMM17);
    static constexpr Reg xmm18(ZYDIS_REGISTER_XMM18);
    static constexpr Reg xmm19(ZYDIS_REGISTER_XMM19);
    static constexpr Reg xmm20(ZYDIS_REGISTER_XMM20);
    static constexpr Reg xmm21(ZYDIS_REGISTER_XMM21);
    static constexpr Reg xmm22(ZYDIS_REGISTER_XMM22);
    static constexpr Reg xmm23(ZYDIS_REGISTER_XMM23);
    static constexpr Reg xmm24(ZYDIS_REGISTER_XMM24);
    static constexpr Reg xmm25(ZYDIS_REGISTER_XMM25);
    static constexpr Reg xmm26(ZYDIS_REGISTER_XMM26);
    static constexpr Reg xmm27(ZYDIS_REGISTER_XMM27);
    static constexpr Reg xmm28(ZYDIS_REGISTER_XMM28);
    static constexpr Reg xmm29(ZYDIS_REGISTER_XMM29);
    static constexpr Reg xmm30(ZYDIS_REGISTER_XMM30);
    static constexpr Reg xmm31(ZYDIS_REGISTER_XMM31);
    // Floating point vector registers 256-bit
    static constexpr Reg ymm0(ZYDIS_REGISTER_YMM0);
    static constexpr Reg ymm1(ZYDIS_REGISTER_YMM1);
    static constexpr Reg ymm2(ZYDIS_REGISTER_YMM2);
    static constexpr Reg ymm3(ZYDIS_REGISTER_YMM3);
    static constexpr Reg ymm4(ZYDIS_REGISTER_YMM4);
    static constexpr Reg ymm5(ZYDIS_REGISTER_YMM5);
    static constexpr Reg ymm6(ZYDIS_REGISTER_YMM6);
    static constexpr Reg ymm7(ZYDIS_REGISTER_YMM7);
    static constexpr Reg ymm8(ZYDIS_REGISTER_YMM8);
    static constexpr Reg ymm9(ZYDIS_REGISTER_YMM9);
    static constexpr Reg ymm10(ZYDIS_REGISTER_YMM10);
    static constexpr Reg ymm11(ZYDIS_REGISTER_YMM11);
    static constexpr Reg ymm12(ZYDIS_REGISTER_YMM12);
    static constexpr Reg ymm13(ZYDIS_REGISTER_YMM13);
    static constexpr Reg ymm14(ZYDIS_REGISTER_YMM14);
    static constexpr Reg ymm15(ZYDIS_REGISTER_YMM15);
    static constexpr Reg ymm16(ZYDIS_REGISTER_YMM16);
    static constexpr Reg ymm17(ZYDIS_REGISTER_YMM17);
    static constexpr Reg ymm18(ZYDIS_REGISTER_YMM18);
    static constexpr Reg ymm19(ZYDIS_REGISTER_YMM19);
    static constexpr Reg ymm20(ZYDIS_REGISTER_YMM20);
    static constexpr Reg ymm21(ZYDIS_REGISTER_YMM21);
    static constexpr Reg ymm22(ZYDIS_REGISTER_YMM22);
    static constexpr Reg ymm23(ZYDIS_REGISTER_YMM23);
    static constexpr Reg ymm24(ZYDIS_REGISTER_YMM24);
    static constexpr Reg ymm25(ZYDIS_REGISTER_YMM25);
    static constexpr Reg ymm26(ZYDIS_REGISTER_YMM26);
    static constexpr Reg ymm27(ZYDIS_REGISTER_YMM27);
    static constexpr Reg ymm28(ZYDIS_REGISTER_YMM28);
    static constexpr Reg ymm29(ZYDIS_REGISTER_YMM29);
    static constexpr Reg ymm30(ZYDIS_REGISTER_YMM30);
    static constexpr Reg ymm31(ZYDIS_REGISTER_YMM31);
    // Floating point vector registers 512-bit
    static constexpr Reg zmm0(ZYDIS_REGISTER_ZMM0);
    static constexpr Reg zmm1(ZYDIS_REGISTER_ZMM1);
    static constexpr Reg zmm2(ZYDIS_REGISTER_ZMM2);
    static constexpr Reg zmm3(ZYDIS_REGISTER_ZMM3);
    static constexpr Reg zmm4(ZYDIS_REGISTER_ZMM4);
    static constexpr Reg zmm5(ZYDIS_REGISTER_ZMM5);
    static constexpr Reg zmm6(ZYDIS_REGISTER_ZMM6);
    static constexpr Reg zmm7(ZYDIS_REGISTER_ZMM7);
    static constexpr Reg zmm8(ZYDIS_REGISTER_ZMM8);
    static constexpr Reg zmm9(ZYDIS_REGISTER_ZMM9);
    static constexpr Reg zmm10(ZYDIS_REGISTER_ZMM10);
    static constexpr Reg zmm11(ZYDIS_REGISTER_ZMM11);
    static constexpr Reg zmm12(ZYDIS_REGISTER_ZMM12);
    static constexpr Reg zmm13(ZYDIS_REGISTER_ZMM13);
    static constexpr Reg zmm14(ZYDIS_REGISTER_ZMM14);
    static constexpr Reg zmm15(ZYDIS_REGISTER_ZMM15);
    static constexpr Reg zmm16(ZYDIS_REGISTER_ZMM16);
    static constexpr Reg zmm17(ZYDIS_REGISTER_ZMM17);
    static constexpr Reg zmm18(ZYDIS_REGISTER_ZMM18);
    static constexpr Reg zmm19(ZYDIS_REGISTER_ZMM19);
    static constexpr Reg zmm20(ZYDIS_REGISTER_ZMM20);
    static constexpr Reg zmm21(ZYDIS_REGISTER_ZMM21);
    static constexpr Reg zmm22(ZYDIS_REGISTER_ZMM22);
    static constexpr Reg zmm23(ZYDIS_REGISTER_ZMM23);
    static constexpr Reg zmm24(ZYDIS_REGISTER_ZMM24);
    static constexpr Reg zmm25(ZYDIS_REGISTER_ZMM25);
    static constexpr Reg zmm26(ZYDIS_REGISTER_ZMM26);
    static constexpr Reg zmm27(ZYDIS_REGISTER_ZMM27);
    static constexpr Reg zmm28(ZYDIS_REGISTER_ZMM28);
    static constexpr Reg zmm29(ZYDIS_REGISTER_ZMM29);
    static constexpr Reg zmm30(ZYDIS_REGISTER_ZMM30);
    static constexpr Reg zmm31(ZYDIS_REGISTER_ZMM31);
    // Matrix registers
    static constexpr Reg tmm0(ZYDIS_REGISTER_TMM0);
    static constexpr Reg tmm1(ZYDIS_REGISTER_TMM1);
    static constexpr Reg tmm2(ZYDIS_REGISTER_TMM2);
    static constexpr Reg tmm3(ZYDIS_REGISTER_TMM3);
    static constexpr Reg tmm4(ZYDIS_REGISTER_TMM4);
    static constexpr Reg tmm5(ZYDIS_REGISTER_TMM5);
    static constexpr Reg tmm6(ZYDIS_REGISTER_TMM6);
    static constexpr Reg tmm7(ZYDIS_REGISTER_TMM7);
    // Flags registers
    static constexpr Reg flags(ZYDIS_REGISTER_FLAGS);
    static constexpr Reg eflags(ZYDIS_REGISTER_EFLAGS);
    static constexpr Reg rflags(ZYDIS_REGISTER_RFLAGS);
    // Instruction-pointer registers
    static constexpr Rip ip(ZYDIS_REGISTER_IP);
    static constexpr Rip eip(ZYDIS_REGISTER_EIP);
    static constexpr Rip rip(ZYDIS_REGISTER_RIP);
    // Segment registers
    static constexpr Seg es(ZYDIS_REGISTER_ES);
    static constexpr Seg cs(ZYDIS_REGISTER_CS);
    static constexpr Seg ss(ZYDIS_REGISTER_SS);
    static constexpr Seg ds(ZYDIS_REGISTER_DS);
    static constexpr Seg fs(ZYDIS_REGISTER_FS);
    static constexpr Seg gs(ZYDIS_REGISTER_GS);
    // Table registers
    static constexpr Seg gdtr(ZYDIS_REGISTER_GDTR);
    static constexpr Seg ldtr(ZYDIS_REGISTER_LDTR);
    static constexpr Seg idtr(ZYDIS_REGISTER_IDTR);
    static constexpr Seg tr(ZYDIS_REGISTER_TR);
    // Test registers
    static constexpr Reg tr0(ZYDIS_REGISTER_TR0);
    static constexpr Reg tr1(ZYDIS_REGISTER_TR1);
    static constexpr Reg tr2(ZYDIS_REGISTER_TR2);
    static constexpr Reg tr3(ZYDIS_REGISTER_TR3);
    static constexpr Reg tr4(ZYDIS_REGISTER_TR4);
    static constexpr Reg tr5(ZYDIS_REGISTER_TR5);
    static constexpr Reg tr6(ZYDIS_REGISTER_TR6);
    static constexpr Reg tr7(ZYDIS_REGISTER_TR7);
    // Control registers
    static constexpr Reg cr0(ZYDIS_REGISTER_CR0);
    static constexpr Reg cr1(ZYDIS_REGISTER_CR1);
    static constexpr Reg cr2(ZYDIS_REGISTER_CR2);
    static constexpr Reg cr3(ZYDIS_REGISTER_CR3);
    static constexpr Reg cr4(ZYDIS_REGISTER_CR4);
    static constexpr Reg cr5(ZYDIS_REGISTER_CR5);
    static constexpr Reg cr6(ZYDIS_REGISTER_CR6);
    static constexpr Reg cr7(ZYDIS_REGISTER_CR7);
    static constexpr Reg cr8(ZYDIS_REGISTER_CR8);
    static constexpr Reg cr9(ZYDIS_REGISTER_CR9);
    static constexpr Reg cr10(ZYDIS_REGISTER_CR10);
    static constexpr Reg cr11(ZYDIS_REGISTER_CR11);
    static constexpr Reg cr12(ZYDIS_REGISTER_CR12);
    static constexpr Reg cr13(ZYDIS_REGISTER_CR13);
    static constexpr Reg cr14(ZYDIS_REGISTER_CR14);
    static constexpr Reg cr15(ZYDIS_REGISTER_CR15);
    // Debug registers
    static constexpr Reg dr0(ZYDIS_REGISTER_DR0);
    static constexpr Reg dr1(ZYDIS_REGISTER_DR1);
    static constexpr Reg dr2(ZYDIS_REGISTER_DR2);
    static constexpr Reg dr3(ZYDIS_REGISTER_DR3);
    static constexpr Reg dr4(ZYDIS_REGISTER_DR4);
    static constexpr Reg dr5(ZYDIS_REGISTER_DR5);
    static constexpr Reg dr6(ZYDIS_REGISTER_DR6);
    static constexpr Reg dr7(ZYDIS_REGISTER_DR7);
    static constexpr Reg dr8(ZYDIS_REGISTER_DR8);
    static constexpr Reg dr9(ZYDIS_REGISTER_DR9);
    static constexpr Reg dr10(ZYDIS_REGISTER_DR10);
    static constexpr Reg dr11(ZYDIS_REGISTER_DR11);
    static constexpr Reg dr12(ZYDIS_REGISTER_DR12);
    static constexpr Reg dr13(ZYDIS_REGISTER_DR13);
    static constexpr Reg dr14(ZYDIS_REGISTER_DR14);
    static constexpr Reg dr15(ZYDIS_REGISTER_DR15);
    // Mask registers
    static constexpr Reg k0(ZYDIS_REGISTER_K0);
    static constexpr Reg k1(ZYDIS_REGISTER_K1);
    static constexpr Reg k2(ZYDIS_REGISTER_K2);
    static constexpr Reg k3(ZYDIS_REGISTER_K3);
    static constexpr Reg k4(ZYDIS_REGISTER_K4);
    static constexpr Reg k5(ZYDIS_REGISTER_K5);
    static constexpr Reg k6(ZYDIS_REGISTER_K6);
    static constexpr Reg k7(ZYDIS_REGISTER_K7);
    // Bound registers
    static constexpr Reg bnd0(ZYDIS_REGISTER_BND0);
    static constexpr Reg bnd1(ZYDIS_REGISTER_BND1);
    static constexpr Reg bnd2(ZYDIS_REGISTER_BND2);
    static constexpr Reg bnd3(ZYDIS_REGISTER_BND3);
    static constexpr Reg bndcfg(ZYDIS_REGISTER_BNDCFG);
    static constexpr Reg bndstatus(ZYDIS_REGISTER_BNDSTATUS);
    // Uncategorized
    static constexpr Reg mxcsr(ZYDIS_REGISTER_MXCSR);
    static constexpr Reg pkru(ZYDIS_REGISTER_PKRU);
    static constexpr Reg xcr0(ZYDIS_REGISTER_XCR0);
    static constexpr Reg uif(ZYDIS_REGISTER_UIF);

} // namespace zasm::operands