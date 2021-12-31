#pragma once

#include <Zydis/Zydis.h>
#include <cstdint>
#include <zasm/core/bitsize.hpp>

namespace zasm::operands
{
    class Reg
    {
    protected:
        static_assert(ZYDIS_REGISTER_AL < ZYDIS_REGISTER_AH);
        static constexpr int8_t kGp8HiStartIndex = ZYDIS_REGISTER_AH - ZYDIS_REGISTER_AL;
        static_assert(kGp8HiStartIndex == 4, "This should be 4, if this triggers the definition probably changed");

    public:
        // For debug builds this makes inspection easier.
        // For release builds size matters more.
#ifdef _DEBUG
        using Id = ZydisRegister;
#else
        using Id = uint16_t;
#endif
    protected:
        Id _reg{ ZYDIS_REGISTER_NONE };

    public:
        constexpr Reg() noexcept = default;
        constexpr Reg(const ZydisRegister reg) noexcept
            : _reg{ static_cast<Id>(reg) }
        {
        }
#ifndef _DEBUG
        constexpr Reg(const Id reg) noexcept
            : _reg{ reg }
        {
        }
#endif
        BitSize getSize(ZydisMachineMode mode) const noexcept
        {
            return toBitSize(ZydisRegisterGetWidth(mode, getId()));
        }

        ZydisRegisterClass getClass() const noexcept
        {
            return ZydisRegisterGetClass(getId());
        }

        constexpr ZydisRegister getId() const noexcept
        {
            return static_cast<ZydisRegister>(_reg);
        }

        /// <summary>
        /// Returns the index per register class
        /// NOTE: For Gp8 there are 20 registers, hi/lo regs are in the same class.
        /// </summary>
        int8_t getIndex() const noexcept
        {
            return ZydisRegisterGetId(getId());
        }

        /// <summary>
        /// Returns the physical index which is also used for the encoding.
        /// </summary>
        /// <returns>Physical index, typically 0 to 31. Returns -1 if it has no index.</returns>
        int8_t getPhysicalIndex() const noexcept
        {
            const auto regIndex = ZydisRegisterGetId(getId());
            if (regIndex == -1)
                return -1;
            if (isGp8() && regIndex >= kGp8HiStartIndex)
            {
                return regIndex - kGp8HiStartIndex;
            }
            return regIndex;
        }

        /// <summary>
        /// Returns the offset in the space of the root register as bytes.
        /// This is typically 0 except for Gp8Hi registers.
        /// </summary>
        constexpr int8_t getOffset() const noexcept
        {
            switch (getId())
            {
                case ZYDIS_REGISTER_AH:
                case ZYDIS_REGISTER_CH:
                case ZYDIS_REGISTER_BH:
                case ZYDIS_REGISTER_DH:
                    return 1;
                default:
                    return 0;
            }
            return 0;
        }

        /// <summary>
        /// Returns the root register for registers that are lower size, ex.: root of ax
        /// would be eax on 32 bit mode and rax on 64 bit.
        /// In case the register has no root it will return Reg::None.
        /// </summary>
        Reg getRoot(ZydisMachineMode mode) const noexcept
        {
            return Reg{ ZydisRegisterGetLargestEnclosing(mode, getId()) };
        }

        constexpr bool isValid() const noexcept
        {
            return getId() != ZYDIS_REGISTER_NONE;
        }

        bool isGp8() const noexcept
        {
            return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_GPR8;
        }

        bool isGp8Lo() const noexcept
        {
            if (!isGp8())
                return false;
            switch (getId())
            {
                case ZYDIS_REGISTER_AH:
                case ZYDIS_REGISTER_CH:
                case ZYDIS_REGISTER_BH:
                case ZYDIS_REGISTER_DH:
                    return false;
                default:
                    return true;
            }
            return true;
        }

        bool isGp8Hi() const noexcept
        {
            if (!isGp8())
                return false;
            switch (getId())
            {
                case ZYDIS_REGISTER_AH:
                case ZYDIS_REGISTER_CH:
                case ZYDIS_REGISTER_BH:
                case ZYDIS_REGISTER_DH:
                    return true;
                default:
                    return false;
            }
            return false;
        }

        bool isGp16() const noexcept
        {
            return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_GPR16;
        }

        bool isGp32() const noexcept
        {
            return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_GPR32;
        }

        bool isGp64() const noexcept
        {
            return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_GPR64;
        }

        bool isGp() const noexcept
        {
            return isGp8() || isGp16() || isGp32() || isGp64();
        }

        bool isXmm() const noexcept
        {
            return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_XMM;
        }

        bool isYmm() const noexcept
        {
            return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_YMM;
        }

        bool isZmm() const noexcept
        {
            return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_ZMM;
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

        template<typename T> constexpr T& as() noexcept
        {
            return static_cast<T&>(*this);
        }

        template<typename T> constexpr const T& as() const noexcept
        {
            return static_cast<T&>(*this);
        }
    };

    // Strong type for general purpose regs.
    class Gp : public Reg
    {
    public:
        using Reg::Reg;

        Gp r8lo() const noexcept
        {
            auto regIndex = getPhysicalIndex();
            if (regIndex >= kGp8HiStartIndex)
            {
                // Skip the hi ones.
                regIndex += kGp8HiStartIndex;
            }
            auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR8, regIndex);
            return Gp{ reg };
        }

        Gp r8() const noexcept
        {
            return r8lo();
        }

        Gp r8hi() const noexcept
        {
            auto regIndex = getPhysicalIndex();
            if (regIndex >= kGp8HiStartIndex)
            {
                // Unsupported.
                return Gp{};
            }
            auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR8, regIndex + kGp8HiStartIndex);
            return Gp{ reg };
        }

        Gp r16() const noexcept
        {
            auto regIndex = getPhysicalIndex();
            auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR16, regIndex);
            return Gp{ reg };
        }

        Gp r32() const noexcept
        {
            auto regIndex = getPhysicalIndex();
            auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR32, regIndex);
            return Gp{ reg };
        }

        Gp r64() const noexcept
        {
            auto regIndex = getPhysicalIndex();
            auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR64, regIndex);
            return Gp{ reg };
        }
    };

    class Gp8 : public Gp
    {
    public:
        using Gp::Gp;
    };

    class Gp16 : public Gp
    {
    public:
        using Gp::Gp;
    };

    class Gp32 : public Gp
    {
    public:
        using Gp::Gp;
    };

    class Gp64 : public Gp
    {
    public:
        using Gp::Gp;
    };

    class Rip : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Seg : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Mmx : public Reg
    {
    public:
        using Reg::Reg;
    };

    class St : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Tmm : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Xmm : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Ymm : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Zmm : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Cr : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Dr : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Tr : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Mask : public Reg
    {
    public:
        using Reg::Reg;
    };

    class Bnd : public Reg
    {
    public:
        using Reg::Reg;
    };

    static constexpr auto SizeOfReg = sizeof(Reg);

    // General purpose registers  8-bit
    static constexpr Gp8 al(ZYDIS_REGISTER_AL);
    static constexpr Gp8 cl(ZYDIS_REGISTER_CL);
    static constexpr Gp8 dl(ZYDIS_REGISTER_DL);
    static constexpr Gp8 bl(ZYDIS_REGISTER_BL);
    static constexpr Gp8 ah(ZYDIS_REGISTER_AH);
    static constexpr Gp8 ch(ZYDIS_REGISTER_CH);
    static constexpr Gp8 dh(ZYDIS_REGISTER_DH);
    static constexpr Gp8 bh(ZYDIS_REGISTER_BH);
    static constexpr Gp8 spl(ZYDIS_REGISTER_SPL);
    static constexpr Gp8 bpl(ZYDIS_REGISTER_BPL);
    static constexpr Gp8 sil(ZYDIS_REGISTER_SIL);
    static constexpr Gp8 dil(ZYDIS_REGISTER_DIL);
    static constexpr Gp8 r8b(ZYDIS_REGISTER_R8B);
    static constexpr Gp8 r9b(ZYDIS_REGISTER_R9B);
    static constexpr Gp8 r10b(ZYDIS_REGISTER_R10B);
    static constexpr Gp8 r11b(ZYDIS_REGISTER_R11B);
    static constexpr Gp8 r12b(ZYDIS_REGISTER_R12B);
    static constexpr Gp8 r13b(ZYDIS_REGISTER_R13B);
    static constexpr Gp8 r14b(ZYDIS_REGISTER_R14B);
    static constexpr Gp8 r15b(ZYDIS_REGISTER_R15B);
    // General purpose registers 16-bit
    static constexpr Gp16 ax(ZYDIS_REGISTER_AX);
    static constexpr Gp16 cx(ZYDIS_REGISTER_CX);
    static constexpr Gp16 dx(ZYDIS_REGISTER_DX);
    static constexpr Gp16 bx(ZYDIS_REGISTER_BX);
    static constexpr Gp16 sp(ZYDIS_REGISTER_SP);
    static constexpr Gp16 bp(ZYDIS_REGISTER_BP);
    static constexpr Gp16 si(ZYDIS_REGISTER_SI);
    static constexpr Gp16 di(ZYDIS_REGISTER_DI);
    static constexpr Gp16 r8w(ZYDIS_REGISTER_R8W);
    static constexpr Gp16 r9w(ZYDIS_REGISTER_R9W);
    static constexpr Gp16 r10w(ZYDIS_REGISTER_R10W);
    static constexpr Gp16 r11w(ZYDIS_REGISTER_R11W);
    static constexpr Gp16 r12w(ZYDIS_REGISTER_R12W);
    static constexpr Gp16 r13w(ZYDIS_REGISTER_R13W);
    static constexpr Gp16 r14w(ZYDIS_REGISTER_R14W);
    static constexpr Gp16 r15w(ZYDIS_REGISTER_R15W);
    // General purpose registers 32-bit
    static constexpr Gp32 eax(ZYDIS_REGISTER_EAX);
    static constexpr Gp32 ecx(ZYDIS_REGISTER_ECX);
    static constexpr Gp32 edx(ZYDIS_REGISTER_EDX);
    static constexpr Gp32 ebx(ZYDIS_REGISTER_EBX);
    static constexpr Gp32 esp(ZYDIS_REGISTER_ESP);
    static constexpr Gp32 ebp(ZYDIS_REGISTER_EBP);
    static constexpr Gp32 esi(ZYDIS_REGISTER_ESI);
    static constexpr Gp32 edi(ZYDIS_REGISTER_EDI);
    static constexpr Gp32 r8d(ZYDIS_REGISTER_R8D);
    static constexpr Gp32 r9d(ZYDIS_REGISTER_R9D);
    static constexpr Gp32 r10d(ZYDIS_REGISTER_R10D);
    static constexpr Gp32 r11d(ZYDIS_REGISTER_R11D);
    static constexpr Gp32 r12d(ZYDIS_REGISTER_R12D);
    static constexpr Gp32 r13d(ZYDIS_REGISTER_R13D);
    static constexpr Gp32 r14d(ZYDIS_REGISTER_R14D);
    static constexpr Gp32 r15d(ZYDIS_REGISTER_R15D);
    // General purpose registers 64-bit
    static constexpr Gp64 rax(ZYDIS_REGISTER_RAX);
    static constexpr Gp64 rcx(ZYDIS_REGISTER_RCX);
    static constexpr Gp64 rdx(ZYDIS_REGISTER_RDX);
    static constexpr Gp64 rbx(ZYDIS_REGISTER_RBX);
    static constexpr Gp64 rsp(ZYDIS_REGISTER_RSP);
    static constexpr Gp64 rbp(ZYDIS_REGISTER_RBP);
    static constexpr Gp64 rsi(ZYDIS_REGISTER_RSI);
    static constexpr Gp64 rdi(ZYDIS_REGISTER_RDI);
    static constexpr Gp64 r8(ZYDIS_REGISTER_R8);
    static constexpr Gp64 r9(ZYDIS_REGISTER_R9);
    static constexpr Gp64 r10(ZYDIS_REGISTER_R10);
    static constexpr Gp64 r11(ZYDIS_REGISTER_R11);
    static constexpr Gp64 r12(ZYDIS_REGISTER_R12);
    static constexpr Gp64 r13(ZYDIS_REGISTER_R13);
    static constexpr Gp64 r14(ZYDIS_REGISTER_R14);
    static constexpr Gp64 r15(ZYDIS_REGISTER_R15);
    // Floating point legacy registers
    static constexpr St st0(ZYDIS_REGISTER_ST0);
    static constexpr St st1(ZYDIS_REGISTER_ST1);
    static constexpr St st2(ZYDIS_REGISTER_ST2);
    static constexpr St st3(ZYDIS_REGISTER_ST3);
    static constexpr St st4(ZYDIS_REGISTER_ST4);
    static constexpr St st5(ZYDIS_REGISTER_ST5);
    static constexpr St st6(ZYDIS_REGISTER_ST6);
    static constexpr St st7(ZYDIS_REGISTER_ST7);
    static constexpr Reg x87control(ZYDIS_REGISTER_X87CONTROL);
    static constexpr Reg x87status(ZYDIS_REGISTER_X87STATUS);
    static constexpr Reg x87tag(ZYDIS_REGISTER_X87TAG);
    // Floating point multimedia registers
    static constexpr Mmx mm0(ZYDIS_REGISTER_MM0);
    static constexpr Mmx mm1(ZYDIS_REGISTER_MM1);
    static constexpr Mmx mm2(ZYDIS_REGISTER_MM2);
    static constexpr Mmx mm3(ZYDIS_REGISTER_MM3);
    static constexpr Mmx mm4(ZYDIS_REGISTER_MM4);
    static constexpr Mmx mm5(ZYDIS_REGISTER_MM5);
    static constexpr Mmx mm6(ZYDIS_REGISTER_MM6);
    static constexpr Mmx mm7(ZYDIS_REGISTER_MM7);
    // Floating point vector registers 128-bit
    static constexpr Xmm xmm0(ZYDIS_REGISTER_XMM0);
    static constexpr Xmm xmm1(ZYDIS_REGISTER_XMM1);
    static constexpr Xmm xmm2(ZYDIS_REGISTER_XMM2);
    static constexpr Xmm xmm3(ZYDIS_REGISTER_XMM3);
    static constexpr Xmm xmm4(ZYDIS_REGISTER_XMM4);
    static constexpr Xmm xmm5(ZYDIS_REGISTER_XMM5);
    static constexpr Xmm xmm6(ZYDIS_REGISTER_XMM6);
    static constexpr Xmm xmm7(ZYDIS_REGISTER_XMM7);
    static constexpr Xmm xmm8(ZYDIS_REGISTER_XMM8);
    static constexpr Xmm xmm9(ZYDIS_REGISTER_XMM9);
    static constexpr Xmm xmm10(ZYDIS_REGISTER_XMM10);
    static constexpr Xmm xmm11(ZYDIS_REGISTER_XMM11);
    static constexpr Xmm xmm12(ZYDIS_REGISTER_XMM12);
    static constexpr Xmm xmm13(ZYDIS_REGISTER_XMM13);
    static constexpr Xmm xmm14(ZYDIS_REGISTER_XMM14);
    static constexpr Xmm xmm15(ZYDIS_REGISTER_XMM15);
    static constexpr Xmm xmm16(ZYDIS_REGISTER_XMM16);
    static constexpr Xmm xmm17(ZYDIS_REGISTER_XMM17);
    static constexpr Xmm xmm18(ZYDIS_REGISTER_XMM18);
    static constexpr Xmm xmm19(ZYDIS_REGISTER_XMM19);
    static constexpr Xmm xmm20(ZYDIS_REGISTER_XMM20);
    static constexpr Xmm xmm21(ZYDIS_REGISTER_XMM21);
    static constexpr Xmm xmm22(ZYDIS_REGISTER_XMM22);
    static constexpr Xmm xmm23(ZYDIS_REGISTER_XMM23);
    static constexpr Xmm xmm24(ZYDIS_REGISTER_XMM24);
    static constexpr Xmm xmm25(ZYDIS_REGISTER_XMM25);
    static constexpr Xmm xmm26(ZYDIS_REGISTER_XMM26);
    static constexpr Xmm xmm27(ZYDIS_REGISTER_XMM27);
    static constexpr Xmm xmm28(ZYDIS_REGISTER_XMM28);
    static constexpr Xmm xmm29(ZYDIS_REGISTER_XMM29);
    static constexpr Xmm xmm30(ZYDIS_REGISTER_XMM30);
    static constexpr Xmm xmm31(ZYDIS_REGISTER_XMM31);
    // Floating point vector registers 256-bit
    static constexpr Ymm ymm0(ZYDIS_REGISTER_YMM0);
    static constexpr Ymm ymm1(ZYDIS_REGISTER_YMM1);
    static constexpr Ymm ymm2(ZYDIS_REGISTER_YMM2);
    static constexpr Ymm ymm3(ZYDIS_REGISTER_YMM3);
    static constexpr Ymm ymm4(ZYDIS_REGISTER_YMM4);
    static constexpr Ymm ymm5(ZYDIS_REGISTER_YMM5);
    static constexpr Ymm ymm6(ZYDIS_REGISTER_YMM6);
    static constexpr Ymm ymm7(ZYDIS_REGISTER_YMM7);
    static constexpr Ymm ymm8(ZYDIS_REGISTER_YMM8);
    static constexpr Ymm ymm9(ZYDIS_REGISTER_YMM9);
    static constexpr Ymm ymm10(ZYDIS_REGISTER_YMM10);
    static constexpr Ymm ymm11(ZYDIS_REGISTER_YMM11);
    static constexpr Ymm ymm12(ZYDIS_REGISTER_YMM12);
    static constexpr Ymm ymm13(ZYDIS_REGISTER_YMM13);
    static constexpr Ymm ymm14(ZYDIS_REGISTER_YMM14);
    static constexpr Ymm ymm15(ZYDIS_REGISTER_YMM15);
    static constexpr Ymm ymm16(ZYDIS_REGISTER_YMM16);
    static constexpr Ymm ymm17(ZYDIS_REGISTER_YMM17);
    static constexpr Ymm ymm18(ZYDIS_REGISTER_YMM18);
    static constexpr Ymm ymm19(ZYDIS_REGISTER_YMM19);
    static constexpr Ymm ymm20(ZYDIS_REGISTER_YMM20);
    static constexpr Ymm ymm21(ZYDIS_REGISTER_YMM21);
    static constexpr Ymm ymm22(ZYDIS_REGISTER_YMM22);
    static constexpr Ymm ymm23(ZYDIS_REGISTER_YMM23);
    static constexpr Ymm ymm24(ZYDIS_REGISTER_YMM24);
    static constexpr Ymm ymm25(ZYDIS_REGISTER_YMM25);
    static constexpr Ymm ymm26(ZYDIS_REGISTER_YMM26);
    static constexpr Ymm ymm27(ZYDIS_REGISTER_YMM27);
    static constexpr Ymm ymm28(ZYDIS_REGISTER_YMM28);
    static constexpr Ymm ymm29(ZYDIS_REGISTER_YMM29);
    static constexpr Ymm ymm30(ZYDIS_REGISTER_YMM30);
    static constexpr Ymm ymm31(ZYDIS_REGISTER_YMM31);
    // Floating point vector registers 512-bit
    static constexpr Zmm zmm0(ZYDIS_REGISTER_ZMM0);
    static constexpr Zmm zmm1(ZYDIS_REGISTER_ZMM1);
    static constexpr Zmm zmm2(ZYDIS_REGISTER_ZMM2);
    static constexpr Zmm zmm3(ZYDIS_REGISTER_ZMM3);
    static constexpr Zmm zmm4(ZYDIS_REGISTER_ZMM4);
    static constexpr Zmm zmm5(ZYDIS_REGISTER_ZMM5);
    static constexpr Zmm zmm6(ZYDIS_REGISTER_ZMM6);
    static constexpr Zmm zmm7(ZYDIS_REGISTER_ZMM7);
    static constexpr Zmm zmm8(ZYDIS_REGISTER_ZMM8);
    static constexpr Zmm zmm9(ZYDIS_REGISTER_ZMM9);
    static constexpr Zmm zmm10(ZYDIS_REGISTER_ZMM10);
    static constexpr Zmm zmm11(ZYDIS_REGISTER_ZMM11);
    static constexpr Zmm zmm12(ZYDIS_REGISTER_ZMM12);
    static constexpr Zmm zmm13(ZYDIS_REGISTER_ZMM13);
    static constexpr Zmm zmm14(ZYDIS_REGISTER_ZMM14);
    static constexpr Zmm zmm15(ZYDIS_REGISTER_ZMM15);
    static constexpr Zmm zmm16(ZYDIS_REGISTER_ZMM16);
    static constexpr Zmm zmm17(ZYDIS_REGISTER_ZMM17);
    static constexpr Zmm zmm18(ZYDIS_REGISTER_ZMM18);
    static constexpr Zmm zmm19(ZYDIS_REGISTER_ZMM19);
    static constexpr Zmm zmm20(ZYDIS_REGISTER_ZMM20);
    static constexpr Zmm zmm21(ZYDIS_REGISTER_ZMM21);
    static constexpr Zmm zmm22(ZYDIS_REGISTER_ZMM22);
    static constexpr Zmm zmm23(ZYDIS_REGISTER_ZMM23);
    static constexpr Zmm zmm24(ZYDIS_REGISTER_ZMM24);
    static constexpr Zmm zmm25(ZYDIS_REGISTER_ZMM25);
    static constexpr Zmm zmm26(ZYDIS_REGISTER_ZMM26);
    static constexpr Zmm zmm27(ZYDIS_REGISTER_ZMM27);
    static constexpr Zmm zmm28(ZYDIS_REGISTER_ZMM28);
    static constexpr Zmm zmm29(ZYDIS_REGISTER_ZMM29);
    static constexpr Zmm zmm30(ZYDIS_REGISTER_ZMM30);
    static constexpr Zmm zmm31(ZYDIS_REGISTER_ZMM31);
    // Matrix registers
    static constexpr Tmm tmm0(ZYDIS_REGISTER_TMM0);
    static constexpr Tmm tmm1(ZYDIS_REGISTER_TMM1);
    static constexpr Tmm tmm2(ZYDIS_REGISTER_TMM2);
    static constexpr Tmm tmm3(ZYDIS_REGISTER_TMM3);
    static constexpr Tmm tmm4(ZYDIS_REGISTER_TMM4);
    static constexpr Tmm tmm5(ZYDIS_REGISTER_TMM5);
    static constexpr Tmm tmm6(ZYDIS_REGISTER_TMM6);
    static constexpr Tmm tmm7(ZYDIS_REGISTER_TMM7);
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
    static constexpr Tr tr0(ZYDIS_REGISTER_TR0);
    static constexpr Tr tr1(ZYDIS_REGISTER_TR1);
    static constexpr Tr tr2(ZYDIS_REGISTER_TR2);
    static constexpr Tr tr3(ZYDIS_REGISTER_TR3);
    static constexpr Tr tr4(ZYDIS_REGISTER_TR4);
    static constexpr Tr tr5(ZYDIS_REGISTER_TR5);
    static constexpr Tr tr6(ZYDIS_REGISTER_TR6);
    static constexpr Tr tr7(ZYDIS_REGISTER_TR7);
    // Control registers
    static constexpr Cr cr0(ZYDIS_REGISTER_CR0);
    static constexpr Cr cr1(ZYDIS_REGISTER_CR1);
    static constexpr Cr cr2(ZYDIS_REGISTER_CR2);
    static constexpr Cr cr3(ZYDIS_REGISTER_CR3);
    static constexpr Cr cr4(ZYDIS_REGISTER_CR4);
    static constexpr Cr cr5(ZYDIS_REGISTER_CR5);
    static constexpr Cr cr6(ZYDIS_REGISTER_CR6);
    static constexpr Cr cr7(ZYDIS_REGISTER_CR7);
    static constexpr Cr cr8(ZYDIS_REGISTER_CR8);
    static constexpr Cr cr9(ZYDIS_REGISTER_CR9);
    static constexpr Cr cr10(ZYDIS_REGISTER_CR10);
    static constexpr Cr cr11(ZYDIS_REGISTER_CR11);
    static constexpr Cr cr12(ZYDIS_REGISTER_CR12);
    static constexpr Cr cr13(ZYDIS_REGISTER_CR13);
    static constexpr Cr cr14(ZYDIS_REGISTER_CR14);
    static constexpr Cr cr15(ZYDIS_REGISTER_CR15);
    // Debug registers
    static constexpr Dr dr0(ZYDIS_REGISTER_DR0);
    static constexpr Dr dr1(ZYDIS_REGISTER_DR1);
    static constexpr Dr dr2(ZYDIS_REGISTER_DR2);
    static constexpr Dr dr3(ZYDIS_REGISTER_DR3);
    static constexpr Dr dr4(ZYDIS_REGISTER_DR4);
    static constexpr Dr dr5(ZYDIS_REGISTER_DR5);
    static constexpr Dr dr6(ZYDIS_REGISTER_DR6);
    static constexpr Dr dr7(ZYDIS_REGISTER_DR7);
    static constexpr Dr dr8(ZYDIS_REGISTER_DR8);
    static constexpr Dr dr9(ZYDIS_REGISTER_DR9);
    static constexpr Dr dr10(ZYDIS_REGISTER_DR10);
    static constexpr Dr dr11(ZYDIS_REGISTER_DR11);
    static constexpr Dr dr12(ZYDIS_REGISTER_DR12);
    static constexpr Dr dr13(ZYDIS_REGISTER_DR13);
    static constexpr Dr dr14(ZYDIS_REGISTER_DR14);
    static constexpr Dr dr15(ZYDIS_REGISTER_DR15);
    // Mask registers
    static constexpr Mask k0(ZYDIS_REGISTER_K0);
    static constexpr Mask k1(ZYDIS_REGISTER_K1);
    static constexpr Mask k2(ZYDIS_REGISTER_K2);
    static constexpr Mask k3(ZYDIS_REGISTER_K3);
    static constexpr Mask k4(ZYDIS_REGISTER_K4);
    static constexpr Mask k5(ZYDIS_REGISTER_K5);
    static constexpr Mask k6(ZYDIS_REGISTER_K6);
    static constexpr Mask k7(ZYDIS_REGISTER_K7);
    // Bound registers
    static constexpr Bnd bnd0(ZYDIS_REGISTER_BND0);
    static constexpr Bnd bnd1(ZYDIS_REGISTER_BND1);
    static constexpr Bnd bnd2(ZYDIS_REGISTER_BND2);
    static constexpr Bnd bnd3(ZYDIS_REGISTER_BND3);
    static constexpr Bnd bndcfg(ZYDIS_REGISTER_BNDCFG);
    static constexpr Bnd bndstatus(ZYDIS_REGISTER_BNDSTATUS);
    // Uncategorized
    static constexpr Reg mxcsr(ZYDIS_REGISTER_MXCSR);
    static constexpr Reg pkru(ZYDIS_REGISTER_PKRU);
    static constexpr Reg xcr0(ZYDIS_REGISTER_XCR0);
    static constexpr Reg uif(ZYDIS_REGISTER_UIF);

} // namespace zasm::operands