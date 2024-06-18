#pragma once

#include "mnemonic.hpp"
#include "register.hpp"

#include <zasm/base/operand.hpp>
#include <zasm/core/errors.hpp>
#include <zasm/program/instruction.hpp>

namespace zasm::x86
{
    template<typename T> class Emitter
    {
        template<typename... TArgs> inline Error emit(Instruction::Mnemonic id, TArgs&&... args)
        {
            auto& cls = static_cast<T&>(*this);
            return cls.emit(id, std::forward<TArgs>(args)...);
        }

    public:
        inline Error aaa()
        {
            return emit(x86::Mnemonic::Aaa);
        }
        inline Error aad(const Imm& a)
        {
            return emit(x86::Mnemonic::Aad, a);
        }
        inline Error aam(const Imm& a)
        {
            return emit(x86::Mnemonic::Aam, a);
        }
        inline Error aas()
        {
            return emit(x86::Mnemonic::Aas);
        }
        inline Error adc(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        inline Error adc(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        inline Error adc(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        inline Error adc(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        inline Error adc(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        inline Error adc(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        inline Error adc(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        inline Error adc(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        inline Error adc(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        inline Error adcx(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Adcx, a, b);
        }
        inline Error adcx(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Adcx, a, b);
        }
        inline Error adcx(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Adcx, a, b);
        }
        inline Error adcx(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Adcx, a, b);
        }
        inline Error add(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        inline Error add(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        inline Error add(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        inline Error add(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        inline Error add(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        inline Error add(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        inline Error add(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        inline Error add(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        inline Error add(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        inline Error addpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Addpd, a, b);
        }
        inline Error addpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Addpd, a, b);
        }
        inline Error addps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Addps, a, b);
        }
        inline Error addps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Addps, a, b);
        }
        inline Error addsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Addsd, a, b);
        }
        inline Error addsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Addsd, a, b);
        }
        inline Error addss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Addss, a, b);
        }
        inline Error addss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Addss, a, b);
        }
        inline Error addsubpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Addsubpd, a, b);
        }
        inline Error addsubpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Addsubpd, a, b);
        }
        inline Error addsubps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Addsubps, a, b);
        }
        inline Error addsubps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Addsubps, a, b);
        }
        inline Error adox(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Adox, a, b);
        }
        inline Error adox(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Adox, a, b);
        }
        inline Error adox(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Adox, a, b);
        }
        inline Error adox(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Adox, a, b);
        }
        inline Error aesdec(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Aesdec, a, b);
        }
        inline Error aesdec(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesdec, a, b);
        }
        inline Error aesdec128kl(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesdec128kl, a, b);
        }
        inline Error aesdec256kl(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesdec256kl, a, b);
        }
        inline Error aesdeclast(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Aesdeclast, a, b);
        }
        inline Error aesdeclast(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesdeclast, a, b);
        }
        inline Error aesdecwide128kl(const Mem& a)
        {
            return emit(x86::Mnemonic::Aesdecwide128kl, a);
        }
        inline Error aesdecwide256kl(const Mem& a)
        {
            return emit(x86::Mnemonic::Aesdecwide256kl, a);
        }
        inline Error aesenc(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Aesenc, a, b);
        }
        inline Error aesenc(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesenc, a, b);
        }
        inline Error aesenc128kl(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesenc128kl, a, b);
        }
        inline Error aesenc256kl(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesenc256kl, a, b);
        }
        inline Error aesenclast(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Aesenclast, a, b);
        }
        inline Error aesenclast(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesenclast, a, b);
        }
        inline Error aesencwide128kl(const Mem& a)
        {
            return emit(x86::Mnemonic::Aesencwide128kl, a);
        }
        inline Error aesencwide256kl(const Mem& a)
        {
            return emit(x86::Mnemonic::Aesencwide256kl, a);
        }
        inline Error aesimc(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Aesimc, a, b);
        }
        inline Error aesimc(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesimc, a, b);
        }
        inline Error aeskeygenassist(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Aeskeygenassist, a, b, c);
        }
        inline Error aeskeygenassist(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Aeskeygenassist, a, b, c);
        }
        inline Error and_(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        inline Error and_(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        inline Error and_(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        inline Error and_(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        inline Error and_(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        inline Error and_(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        inline Error and_(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        inline Error and_(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        inline Error and_(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        inline Error andn(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Andn, a, b, c);
        }
        inline Error andn(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Andn, a, b, c);
        }
        inline Error andn(const Gp32& a, const Gp32& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Andn, a, b, c);
        }
        inline Error andn(const Gp64& a, const Gp64& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Andn, a, b, c);
        }
        inline Error andnpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Andnpd, a, b);
        }
        inline Error andnpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Andnpd, a, b);
        }
        inline Error andnps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Andnps, a, b);
        }
        inline Error andnps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Andnps, a, b);
        }
        inline Error andpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Andpd, a, b);
        }
        inline Error andpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Andpd, a, b);
        }
        inline Error andps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Andps, a, b);
        }
        inline Error andps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Andps, a, b);
        }
        inline Error arpl(const Gp16& a, const Gp16& b)
        {
            return emit(x86::Mnemonic::Arpl, a, b);
        }
        inline Error arpl(const Mem& a, const Gp16& b)
        {
            return emit(x86::Mnemonic::Arpl, a, b);
        }
        inline Error bextr(const Gp& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Bextr, a, b, c);
        }
        inline Error bextr(const Gp& a, const Mem& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Bextr, a, b, c);
        }
        inline Error bextr(const Gp& a, const Gp& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Bextr, a, b, c);
        }
        inline Error bextr(const Gp& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Bextr, a, b, c);
        }
        inline Error blcfill(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blcfill, a, b);
        }
        inline Error blcfill(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blcfill, a, b);
        }
        inline Error blci(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blci, a, b);
        }
        inline Error blci(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blci, a, b);
        }
        inline Error blcic(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blcic, a, b);
        }
        inline Error blcic(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blcic, a, b);
        }
        inline Error blcmsk(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blcmsk, a, b);
        }
        inline Error blcmsk(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blcmsk, a, b);
        }
        inline Error blcs(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blcs, a, b);
        }
        inline Error blcs(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blcs, a, b);
        }
        inline Error blendpd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Blendpd, a, b, c);
        }
        inline Error blendpd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Blendpd, a, b, c);
        }
        inline Error blendps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Blendps, a, b, c);
        }
        inline Error blendps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Blendps, a, b, c);
        }
        inline Error blendvpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Blendvpd, a, b);
        }
        inline Error blendvpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blendvpd, a, b);
        }
        inline Error blendvps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Blendvps, a, b);
        }
        inline Error blendvps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blendvps, a, b);
        }
        inline Error blsfill(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blsfill, a, b);
        }
        inline Error blsfill(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blsfill, a, b);
        }
        inline Error blsi(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blsi, a, b);
        }
        inline Error blsi(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blsi, a, b);
        }
        inline Error blsic(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blsic, a, b);
        }
        inline Error blsic(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blsic, a, b);
        }
        inline Error blsmsk(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blsmsk, a, b);
        }
        inline Error blsmsk(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blsmsk, a, b);
        }
        inline Error blsr(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blsr, a, b);
        }
        inline Error blsr(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blsr, a, b);
        }
        inline Error bndcl(const Bnd& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Bndcl, a, b);
        }
        inline Error bndcl(const Bnd& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bndcl, a, b);
        }
        inline Error bndcl(const Bnd& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Bndcl, a, b);
        }
        inline Error bndcn(const Bnd& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Bndcn, a, b);
        }
        inline Error bndcn(const Bnd& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bndcn, a, b);
        }
        inline Error bndcn(const Bnd& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Bndcn, a, b);
        }
        inline Error bndcu(const Bnd& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Bndcu, a, b);
        }
        inline Error bndcu(const Bnd& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bndcu, a, b);
        }
        inline Error bndcu(const Bnd& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Bndcu, a, b);
        }
        inline Error bndldx(const Bnd& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bndldx, a, b);
        }
        inline Error bndmk(const Bnd& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bndmk, a, b);
        }
        inline Error bndmov(const Bnd& a, const Bnd& b)
        {
            return emit(x86::Mnemonic::Bndmov, a, b);
        }
        inline Error bndmov(const Bnd& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bndmov, a, b);
        }
        inline Error bndmov(const Mem& a, const Bnd& b)
        {
            return emit(x86::Mnemonic::Bndmov, a, b);
        }
        inline Error bndstx(const Mem& a, const Bnd& b)
        {
            return emit(x86::Mnemonic::Bndstx, a, b);
        }
        inline Error bound(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bound, a, b);
        }
        inline Error bsf(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Bsf, a, b);
        }
        inline Error bsf(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bsf, a, b);
        }
        inline Error bsr(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Bsr, a, b);
        }
        inline Error bsr(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bsr, a, b);
        }
        inline Error bswap(const Gp& a)
        {
            return emit(x86::Mnemonic::Bswap, a);
        }
        inline Error bt(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Bt, a, b);
        }
        inline Error bt(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Bt, a, b);
        }
        inline Error bt(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Bt, a, b);
        }
        inline Error bt(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Bt, a, b);
        }
        inline Error btc(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Btc, a, b);
        }
        inline Error btc(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Btc, a, b);
        }
        inline Error btc(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Btc, a, b);
        }
        inline Error btc(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Btc, a, b);
        }
        inline Error btr(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Btr, a, b);
        }
        inline Error btr(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Btr, a, b);
        }
        inline Error btr(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Btr, a, b);
        }
        inline Error btr(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Btr, a, b);
        }
        inline Error bts(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Bts, a, b);
        }
        inline Error bts(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Bts, a, b);
        }
        inline Error bts(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Bts, a, b);
        }
        inline Error bts(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Bts, a, b);
        }
        inline Error bzhi(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Bzhi, a, b, c);
        }
        inline Error bzhi(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Bzhi, a, b, c);
        }
        inline Error bzhi(const Gp32& a, const Mem& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Bzhi, a, b, c);
        }
        inline Error bzhi(const Gp64& a, const Mem& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Bzhi, a, b, c);
        }
        inline Error call(const Gp& a)
        {
            return emit(x86::Mnemonic::Call, a);
        }
        inline Error call(const Mem& a)
        {
            return emit(x86::Mnemonic::Call, a);
        }
        inline Error call(const Imm& a)
        {
            return emit(x86::Mnemonic::Call, a);
        }
        inline Error call(const Label& a)
        {
            return emit(x86::Mnemonic::Call, a);
        }
        inline Error cbw()
        {
            return emit(x86::Mnemonic::Cbw);
        }
        inline Error cdq()
        {
            return emit(x86::Mnemonic::Cdq);
        }
        inline Error cdqe()
        {
            return emit(x86::Mnemonic::Cdqe);
        }
        inline Error clac()
        {
            return emit(x86::Mnemonic::Clac);
        }
        inline Error clc()
        {
            return emit(x86::Mnemonic::Clc);
        }
        inline Error cld()
        {
            return emit(x86::Mnemonic::Cld);
        }
        inline Error cldemote(const Mem& a)
        {
            return emit(x86::Mnemonic::Cldemote, a);
        }
        inline Error clevict0(const Mem& a)
        {
            return emit(x86::Mnemonic::Clevict0, a);
        }
        inline Error clevict1(const Mem& a)
        {
            return emit(x86::Mnemonic::Clevict1, a);
        }
        inline Error clflush(const Mem& a)
        {
            return emit(x86::Mnemonic::Clflush, a);
        }
        inline Error clflushopt(const Mem& a)
        {
            return emit(x86::Mnemonic::Clflushopt, a);
        }
        inline Error clgi()
        {
            return emit(x86::Mnemonic::Clgi);
        }
        inline Error cli()
        {
            return emit(x86::Mnemonic::Cli);
        }
        inline Error clrssbsy(const Mem& a)
        {
            return emit(x86::Mnemonic::Clrssbsy, a);
        }
        inline Error clts()
        {
            return emit(x86::Mnemonic::Clts);
        }
        inline Error clui()
        {
            return emit(x86::Mnemonic::Clui);
        }
        inline Error clwb(const Mem& a)
        {
            return emit(x86::Mnemonic::Clwb, a);
        }
        inline Error clzero(const Gp& a)
        {
            return emit(x86::Mnemonic::Clzero, a);
        }
        inline Error cmc()
        {
            return emit(x86::Mnemonic::Cmc);
        }
        inline Error cmovb(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovb, a, b);
        }
        inline Error cmovb(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovb, a, b);
        }
        inline Error cmovbe(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovbe, a, b);
        }
        inline Error cmovbe(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovbe, a, b);
        }
        inline Error cmovl(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovl, a, b);
        }
        inline Error cmovl(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovl, a, b);
        }
        inline Error cmovle(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovle, a, b);
        }
        inline Error cmovle(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovle, a, b);
        }
        inline Error cmovnb(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovnb, a, b);
        }
        inline Error cmovnb(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovnb, a, b);
        }
        inline Error cmovnbe(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovnbe, a, b);
        }
        inline Error cmovnbe(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovnbe, a, b);
        }
        inline Error cmovnl(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovnl, a, b);
        }
        inline Error cmovnl(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovnl, a, b);
        }
        inline Error cmovnle(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovnle, a, b);
        }
        inline Error cmovnle(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovnle, a, b);
        }
        inline Error cmovno(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovno, a, b);
        }
        inline Error cmovno(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovno, a, b);
        }
        inline Error cmovnp(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovnp, a, b);
        }
        inline Error cmovnp(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovnp, a, b);
        }
        inline Error cmovns(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovns, a, b);
        }
        inline Error cmovns(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovns, a, b);
        }
        inline Error cmovnz(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovnz, a, b);
        }
        inline Error cmovnz(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovnz, a, b);
        }
        inline Error cmovo(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovo, a, b);
        }
        inline Error cmovo(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovo, a, b);
        }
        inline Error cmovp(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovp, a, b);
        }
        inline Error cmovp(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovp, a, b);
        }
        inline Error cmovs(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovs, a, b);
        }
        inline Error cmovs(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovs, a, b);
        }
        inline Error cmovz(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovz, a, b);
        }
        inline Error cmovz(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovz, a, b);
        }
        inline Error cmp(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        inline Error cmp(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        inline Error cmp(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        inline Error cmp(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        inline Error cmp(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        inline Error cmp(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        inline Error cmp(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        inline Error cmp(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        inline Error cmp(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        inline Error cmppd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmppd, a, b, c);
        }
        inline Error cmppd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmppd, a, b, c);
        }
        inline Error cmpps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmpps, a, b, c);
        }
        inline Error cmpps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmpps, a, b, c);
        }
        inline Error cmpsb()
        {
            return emit(x86::Mnemonic::Cmpsb);
        }
        inline Error cmpsd()
        {
            return emit(x86::Mnemonic::Cmpsd);
        }
        inline Error cmpsd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmpsd, a, b, c);
        }
        inline Error cmpsd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmpsd, a, b, c);
        }
        inline Error cmpsq()
        {
            return emit(x86::Mnemonic::Cmpsq);
        }
        inline Error cmpss(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmpss, a, b, c);
        }
        inline Error cmpss(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmpss, a, b, c);
        }
        inline Error cmpsw()
        {
            return emit(x86::Mnemonic::Cmpsw);
        }
        inline Error cmpxchg(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Cmpxchg, a, b);
        }
        inline Error cmpxchg(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Cmpxchg, a, b);
        }
        inline Error cmpxchg(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmpxchg, a, b);
        }
        inline Error cmpxchg(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmpxchg, a, b);
        }
        inline Error cmpxchg16b(const Mem& a)
        {
            return emit(x86::Mnemonic::Cmpxchg16b, a);
        }
        inline Error cmpxchg8b(const Mem& a)
        {
            return emit(x86::Mnemonic::Cmpxchg8b, a);
        }
        inline Error comisd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Comisd, a, b);
        }
        inline Error comisd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Comisd, a, b);
        }
        inline Error comiss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Comiss, a, b);
        }
        inline Error comiss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Comiss, a, b);
        }
        inline Error cpuid()
        {
            return emit(x86::Mnemonic::Cpuid);
        }
        inline Error cqo()
        {
            return emit(x86::Mnemonic::Cqo);
        }
        inline Error crc32(const Gp& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Crc32, a, b);
        }
        inline Error crc32(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Crc32, a, b);
        }
        inline Error crc32(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Crc32, a, b);
        }
        inline Error cvtdq2pd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtdq2pd, a, b);
        }
        inline Error cvtdq2pd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtdq2pd, a, b);
        }
        inline Error cvtdq2ps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtdq2ps, a, b);
        }
        inline Error cvtdq2ps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtdq2ps, a, b);
        }
        inline Error cvtpd2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtpd2dq, a, b);
        }
        inline Error cvtpd2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtpd2dq, a, b);
        }
        inline Error cvtpd2pi(const Mmx& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtpd2pi, a, b);
        }
        inline Error cvtpd2pi(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtpd2pi, a, b);
        }
        inline Error cvtpd2ps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtpd2ps, a, b);
        }
        inline Error cvtpd2ps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtpd2ps, a, b);
        }
        inline Error cvtpi2pd(const Xmm& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Cvtpi2pd, a, b);
        }
        inline Error cvtpi2pd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtpi2pd, a, b);
        }
        inline Error cvtpi2ps(const Xmm& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Cvtpi2ps, a, b);
        }
        inline Error cvtpi2ps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtpi2ps, a, b);
        }
        inline Error cvtps2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtps2dq, a, b);
        }
        inline Error cvtps2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtps2dq, a, b);
        }
        inline Error cvtps2pd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtps2pd, a, b);
        }
        inline Error cvtps2pd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtps2pd, a, b);
        }
        inline Error cvtps2pi(const Mmx& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtps2pi, a, b);
        }
        inline Error cvtps2pi(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtps2pi, a, b);
        }
        inline Error cvtsd2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtsd2si, a, b);
        }
        inline Error cvtsd2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtsd2si, a, b);
        }
        inline Error cvtsd2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtsd2si, a, b);
        }
        inline Error cvtsd2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtsd2si, a, b);
        }
        inline Error cvtsd2ss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtsd2ss, a, b);
        }
        inline Error cvtsd2ss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtsd2ss, a, b);
        }
        inline Error cvtsi2sd(const Xmm& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Cvtsi2sd, a, b);
        }
        inline Error cvtsi2sd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtsi2sd, a, b);
        }
        inline Error cvtsi2sd(const Xmm& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Cvtsi2sd, a, b);
        }
        inline Error cvtsi2ss(const Xmm& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Cvtsi2ss, a, b);
        }
        inline Error cvtsi2ss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtsi2ss, a, b);
        }
        inline Error cvtsi2ss(const Xmm& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Cvtsi2ss, a, b);
        }
        inline Error cvtss2sd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtss2sd, a, b);
        }
        inline Error cvtss2sd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtss2sd, a, b);
        }
        inline Error cvtss2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtss2si, a, b);
        }
        inline Error cvtss2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtss2si, a, b);
        }
        inline Error cvtss2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtss2si, a, b);
        }
        inline Error cvtss2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtss2si, a, b);
        }
        inline Error cvttpd2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttpd2dq, a, b);
        }
        inline Error cvttpd2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttpd2dq, a, b);
        }
        inline Error cvttpd2pi(const Mmx& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttpd2pi, a, b);
        }
        inline Error cvttpd2pi(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttpd2pi, a, b);
        }
        inline Error cvttps2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttps2dq, a, b);
        }
        inline Error cvttps2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttps2dq, a, b);
        }
        inline Error cvttps2pi(const Mmx& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttps2pi, a, b);
        }
        inline Error cvttps2pi(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttps2pi, a, b);
        }
        inline Error cvttsd2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttsd2si, a, b);
        }
        inline Error cvttsd2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttsd2si, a, b);
        }
        inline Error cvttsd2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttsd2si, a, b);
        }
        inline Error cvttsd2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttsd2si, a, b);
        }
        inline Error cvttss2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttss2si, a, b);
        }
        inline Error cvttss2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttss2si, a, b);
        }
        inline Error cvttss2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttss2si, a, b);
        }
        inline Error cvttss2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttss2si, a, b);
        }
        inline Error cwd()
        {
            return emit(x86::Mnemonic::Cwd);
        }
        inline Error cwde()
        {
            return emit(x86::Mnemonic::Cwde);
        }
        inline Error daa()
        {
            return emit(x86::Mnemonic::Daa);
        }
        inline Error das()
        {
            return emit(x86::Mnemonic::Das);
        }
        inline Error dec(const Gp& a)
        {
            return emit(x86::Mnemonic::Dec, a);
        }
        inline Error dec(const Gp8& a)
        {
            return emit(x86::Mnemonic::Dec, a);
        }
        inline Error dec(const Mem& a)
        {
            return emit(x86::Mnemonic::Dec, a);
        }
        inline Error delay(const Gp32& a)
        {
            return emit(x86::Mnemonic::Delay, a);
        }
        inline Error delay(const Gp64& a)
        {
            return emit(x86::Mnemonic::Delay, a);
        }
        inline Error div(const Gp8& a)
        {
            return emit(x86::Mnemonic::Div, a);
        }
        inline Error div(const Mem& a)
        {
            return emit(x86::Mnemonic::Div, a);
        }
        inline Error div(const Gp& a)
        {
            return emit(x86::Mnemonic::Div, a);
        }
        inline Error divpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Divpd, a, b);
        }
        inline Error divpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Divpd, a, b);
        }
        inline Error divps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Divps, a, b);
        }
        inline Error divps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Divps, a, b);
        }
        inline Error divsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Divsd, a, b);
        }
        inline Error divsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Divsd, a, b);
        }
        inline Error divss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Divss, a, b);
        }
        inline Error divss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Divss, a, b);
        }
        inline Error dppd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Dppd, a, b, c);
        }
        inline Error dppd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Dppd, a, b, c);
        }
        inline Error dpps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Dpps, a, b, c);
        }
        inline Error dpps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Dpps, a, b, c);
        }
        inline Error emms()
        {
            return emit(x86::Mnemonic::Emms);
        }
        inline Error encls()
        {
            return emit(x86::Mnemonic::Encls);
        }
        inline Error enclu()
        {
            return emit(x86::Mnemonic::Enclu);
        }
        inline Error enclv()
        {
            return emit(x86::Mnemonic::Enclv);
        }
        inline Error encodekey128(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Encodekey128, a, b);
        }
        inline Error encodekey256(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Encodekey256, a, b);
        }
        inline Error endbr32()
        {
            return emit(x86::Mnemonic::Endbr32);
        }
        inline Error endbr64()
        {
            return emit(x86::Mnemonic::Endbr64);
        }
        inline Error enqcmd(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Enqcmd, a, b);
        }
        inline Error enqcmds(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Enqcmds, a, b);
        }
        inline Error enter(const Imm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Enter, a, b);
        }
        inline Error extractps(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Extractps, a, b, c);
        }
        inline Error extractps(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Extractps, a, b, c);
        }
        inline Error extrq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Extrq, a, b);
        }
        inline Error extrq(const Xmm& a, const Imm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Extrq, a, b, c);
        }
        inline Error f2xm1()
        {
            return emit(x86::Mnemonic::F2xm1);
        }
        inline Error fabs()
        {
            return emit(x86::Mnemonic::Fabs);
        }
        inline Error fadd(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fadd, a, b);
        }
        inline Error fadd(const Mem& b)
        {
            return emit(x86::Mnemonic::Fadd, b);
        }
        inline Error faddp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Faddp, a, b);
        }
        inline Error fbld(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fbld, a, b);
        }
        inline Error fbstp(const Mem& a, const St& b)
        {
            return emit(x86::Mnemonic::Fbstp, a, b);
        }
        inline Error fchs()
        {
            return emit(x86::Mnemonic::Fchs);
        }
        inline Error fcmovb(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovb, a, b);
        }
        inline Error fcmovbe(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovbe, a, b);
        }
        inline Error fcmove(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmove, a, b);
        }
        inline Error fcmovnb(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovnb, a, b);
        }
        inline Error fcmovnbe(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovnbe, a, b);
        }
        inline Error fcmovne(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovne, a, b);
        }
        inline Error fcmovnu(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovnu, a, b);
        }
        inline Error fcmovu(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovu, a, b);
        }
        inline Error fcom(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcom, a, b);
        }
        inline Error fcom(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fcom, a, b);
        }
        inline Error fcomi(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcomi, a, b);
        }
        inline Error fcomip(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcomip, a, b);
        }
        inline Error fcomp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcomp, a, b);
        }
        inline Error fcomp(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fcomp, a, b);
        }
        inline Error fcompp()
        {
            return emit(x86::Mnemonic::Fcompp);
        }
        inline Error fcos()
        {
            return emit(x86::Mnemonic::Fcos);
        }
        inline Error fdecstp()
        {
            return emit(x86::Mnemonic::Fdecstp);
        }
        inline Error fdisi8087_nop()
        {
            return emit(x86::Mnemonic::Fdisi8087_nop);
        }
        inline Error fdiv(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fdiv, a, b);
        }
        inline Error fdiv(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fdiv, a, b);
        }
        inline Error fdivp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fdivp, a, b);
        }
        inline Error fdivr(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fdivr, a, b);
        }
        inline Error fdivr(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fdivr, a, b);
        }
        inline Error fdivrp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fdivrp, a, b);
        }
        inline Error femms()
        {
            return emit(x86::Mnemonic::Femms);
        }
        inline Error feni8087_nop()
        {
            return emit(x86::Mnemonic::Feni8087_nop);
        }
        inline Error ffree(const St& a)
        {
            return emit(x86::Mnemonic::Ffree, a);
        }
        inline Error ffreep(const St& a)
        {
            return emit(x86::Mnemonic::Ffreep, a);
        }
        inline Error fiadd(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fiadd, a, b);
        }
        inline Error ficom(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ficom, a, b);
        }
        inline Error ficomp(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ficomp, a, b);
        }
        inline Error fidiv(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fidiv, a, b);
        }
        inline Error fidivr(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fidivr, a, b);
        }
        inline Error fild(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fild, a, b);
        }
        inline Error fimul(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fimul, a, b);
        }
        inline Error fincstp()
        {
            return emit(x86::Mnemonic::Fincstp);
        }
        inline Error fist(const Mem& a, const St& b)
        {
            return emit(x86::Mnemonic::Fist, a, b);
        }
        inline Error fistp(const Mem& a, const St& b)
        {
            return emit(x86::Mnemonic::Fistp, a, b);
        }
        inline Error fisttp(const Mem& a, const St& b)
        {
            return emit(x86::Mnemonic::Fisttp, a, b);
        }
        inline Error fisub(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fisub, a, b);
        }
        inline Error fisubr(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fisubr, a, b);
        }
        inline Error fld(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fld, a, b);
        }
        inline Error fld(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fld, a, b);
        }
        inline Error fld1()
        {
            return emit(x86::Mnemonic::Fld1);
        }
        inline Error fldcw(const Mem& a)
        {
            return emit(x86::Mnemonic::Fldcw, a);
        }
        inline Error fldenv(const Mem& a)
        {
            return emit(x86::Mnemonic::Fldenv, a);
        }
        inline Error fldl2e()
        {
            return emit(x86::Mnemonic::Fldl2e);
        }
        inline Error fldl2t()
        {
            return emit(x86::Mnemonic::Fldl2t);
        }
        inline Error fldlg2()
        {
            return emit(x86::Mnemonic::Fldlg2);
        }
        inline Error fldln2()
        {
            return emit(x86::Mnemonic::Fldln2);
        }
        inline Error fldpi()
        {
            return emit(x86::Mnemonic::Fldpi);
        }
        inline Error fldz()
        {
            return emit(x86::Mnemonic::Fldz);
        }
        inline Error fmul(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fmul, a, b);
        }
        inline Error fmul(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fmul, a, b);
        }
        inline Error fmulp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fmulp, a, b);
        }
        inline Error fnclex()
        {
            return emit(x86::Mnemonic::Fnclex);
        }
        inline Error fninit()
        {
            return emit(x86::Mnemonic::Fninit);
        }
        inline Error fnop()
        {
            return emit(x86::Mnemonic::Fnop);
        }
        inline Error fnsave(const Mem& a)
        {
            return emit(x86::Mnemonic::Fnsave, a);
        }
        inline Error fnstcw(const Mem& a)
        {
            return emit(x86::Mnemonic::Fnstcw, a);
        }
        inline Error fnstenv(const Mem& a)
        {
            return emit(x86::Mnemonic::Fnstenv, a);
        }
        inline Error fnstsw(const Mem& a)
        {
            return emit(x86::Mnemonic::Fnstsw, a);
        }
        inline Error fnstsw(const Gp& a)
        {
            return emit(x86::Mnemonic::Fnstsw, a);
        }
        inline Error fpatan()
        {
            return emit(x86::Mnemonic::Fpatan);
        }
        inline Error fprem()
        {
            return emit(x86::Mnemonic::Fprem);
        }
        inline Error fprem1()
        {
            return emit(x86::Mnemonic::Fprem1);
        }
        inline Error fptan()
        {
            return emit(x86::Mnemonic::Fptan);
        }
        inline Error frndint()
        {
            return emit(x86::Mnemonic::Frndint);
        }
        inline Error frstor(const Mem& a)
        {
            return emit(x86::Mnemonic::Frstor, a);
        }
        inline Error fscale()
        {
            return emit(x86::Mnemonic::Fscale);
        }
        inline Error fsetpm287_nop()
        {
            return emit(x86::Mnemonic::Fsetpm287_nop);
        }
        inline Error fsin()
        {
            return emit(x86::Mnemonic::Fsin);
        }
        inline Error fsincos()
        {
            return emit(x86::Mnemonic::Fsincos);
        }
        inline Error fsqrt()
        {
            return emit(x86::Mnemonic::Fsqrt);
        }
        inline Error fst(const Mem& a, const St& b)
        {
            return emit(x86::Mnemonic::Fst, a, b);
        }
        inline Error fst(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fst, a, b);
        }
        inline Error fstp(const Mem& a, const St& b)
        {
            return emit(x86::Mnemonic::Fstp, a, b);
        }
        inline Error fstp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fstp, a, b);
        }
        inline Error fstpnce(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fstpnce, a, b);
        }
        inline Error fsub(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fsub, a, b);
        }
        inline Error fsub(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fsub, a, b);
        }
        inline Error fsubp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fsubp, a, b);
        }
        inline Error fsubr(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fsubr, a, b);
        }
        inline Error fsubr(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fsubr, a, b);
        }
        inline Error fsubrp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fsubrp, a, b);
        }
        inline Error ftst()
        {
            return emit(x86::Mnemonic::Ftst);
        }
        inline Error fucom(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fucom, a, b);
        }
        inline Error fucomi(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fucomi, a, b);
        }
        inline Error fucomip(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fucomip, a, b);
        }
        inline Error fucomp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fucomp, a, b);
        }
        inline Error fucompp()
        {
            return emit(x86::Mnemonic::Fucompp);
        }
        inline Error fwait()
        {
            return emit(x86::Mnemonic::Fwait);
        }
        inline Error fxam()
        {
            return emit(x86::Mnemonic::Fxam);
        }
        inline Error fxch(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fxch, a, b);
        }
        inline Error fxrstor(const Mem& a)
        {
            return emit(x86::Mnemonic::Fxrstor, a);
        }
        inline Error fxrstor64(const Mem& a)
        {
            return emit(x86::Mnemonic::Fxrstor64, a);
        }
        inline Error fxsave(const Mem& a)
        {
            return emit(x86::Mnemonic::Fxsave, a);
        }
        inline Error fxsave64(const Mem& a)
        {
            return emit(x86::Mnemonic::Fxsave64, a);
        }
        inline Error fxtract()
        {
            return emit(x86::Mnemonic::Fxtract);
        }
        inline Error fyl2x()
        {
            return emit(x86::Mnemonic::Fyl2x);
        }
        inline Error fyl2xp1()
        {
            return emit(x86::Mnemonic::Fyl2xp1);
        }
        inline Error getsec()
        {
            return emit(x86::Mnemonic::Getsec);
        }
        inline Error gf2p8affineinvqb(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Gf2p8affineinvqb, a, b, c);
        }
        inline Error gf2p8affineinvqb(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Gf2p8affineinvqb, a, b, c);
        }
        inline Error gf2p8affineqb(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Gf2p8affineqb, a, b, c);
        }
        inline Error gf2p8affineqb(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Gf2p8affineqb, a, b, c);
        }
        inline Error gf2p8mulb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Gf2p8mulb, a, b);
        }
        inline Error gf2p8mulb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Gf2p8mulb, a, b);
        }
        inline Error haddpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Haddpd, a, b);
        }
        inline Error haddpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Haddpd, a, b);
        }
        inline Error haddps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Haddps, a, b);
        }
        inline Error haddps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Haddps, a, b);
        }
        inline Error hlt()
        {
            return emit(x86::Mnemonic::Hlt);
        }
        inline Error hreset(const Imm& a)
        {
            return emit(x86::Mnemonic::Hreset, a);
        }
        inline Error hsubpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Hsubpd, a, b);
        }
        inline Error hsubpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Hsubpd, a, b);
        }
        inline Error hsubps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Hsubps, a, b);
        }
        inline Error hsubps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Hsubps, a, b);
        }
        inline Error idiv(const Gp8& a)
        {
            return emit(x86::Mnemonic::Idiv, a);
        }
        inline Error idiv(const Mem& a)
        {
            return emit(x86::Mnemonic::Idiv, a);
        }
        inline Error idiv(const Gp& a)
        {
            return emit(x86::Mnemonic::Idiv, a);
        }
        inline Error imul(const Gp8& a)
        {
            return emit(x86::Mnemonic::Imul, a);
        }
        inline Error imul(const Mem& a)
        {
            return emit(x86::Mnemonic::Imul, a);
        }
        inline Error imul(const Gp& a)
        {
            return emit(x86::Mnemonic::Imul, a);
        }
        inline Error imul(const Gp& a, const Gp& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Imul, a, b, c);
        }
        inline Error imul(const Gp& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Imul, a, b, c);
        }
        inline Error imul(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Imul, a, b);
        }
        inline Error imul(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Imul, a, b);
        }
        inline Error in_(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::In, a, b);
        }
        inline Error in_(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::In, a, b);
        }
        inline Error inc(const Gp& a)
        {
            return emit(x86::Mnemonic::Inc, a);
        }
        inline Error inc(const Gp8& a)
        {
            return emit(x86::Mnemonic::Inc, a);
        }
        inline Error inc(const Mem& a)
        {
            return emit(x86::Mnemonic::Inc, a);
        }
        inline Error incsspd(const Gp32& a)
        {
            return emit(x86::Mnemonic::Incsspd, a);
        }
        inline Error incsspq(const Gp64& a)
        {
            return emit(x86::Mnemonic::Incsspq, a);
        }
        inline Error insb()
        {
            return emit(x86::Mnemonic::Insb);
        }
        inline Error insd()
        {
            return emit(x86::Mnemonic::Insd);
        }
        inline Error insertps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Insertps, a, b, c);
        }
        inline Error insertps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Insertps, a, b, c);
        }
        inline Error insertq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Insertq, a, b);
        }
        inline Error insertq(const Xmm& a, const Xmm& b, const Imm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Insertq, a, b, c, d);
        }
        inline Error insw()
        {
            return emit(x86::Mnemonic::Insw);
        }
        inline Error int_(const Imm& a)
        {
            return emit(x86::Mnemonic::Int, a);
        }
        inline Error int1()
        {
            return emit(x86::Mnemonic::Int1);
        }
        inline Error int3()
        {
            return emit(x86::Mnemonic::Int3);
        }
        inline Error into()
        {
            return emit(x86::Mnemonic::Into);
        }
        inline Error invd()
        {
            return emit(x86::Mnemonic::Invd);
        }
        inline Error invept(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Invept, a, b);
        }
        inline Error invept(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Invept, a, b);
        }
        inline Error invlpg(const Mem& a)
        {
            return emit(x86::Mnemonic::Invlpg, a);
        }
        inline Error invlpga(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Invlpga, a, b);
        }
        inline Error invlpgb(const Gp& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Invlpgb, a, b, c);
        }
        inline Error invpcid(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Invpcid, a, b);
        }
        inline Error invpcid(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Invpcid, a, b);
        }
        inline Error invvpid(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Invvpid, a, b);
        }
        inline Error invvpid(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Invvpid, a, b);
        }
        inline Error iret()
        {
            return emit(x86::Mnemonic::Iret);
        }
        inline Error iretd()
        {
            return emit(x86::Mnemonic::Iretd);
        }
        inline Error iretq()
        {
            return emit(x86::Mnemonic::Iretq);
        }
        inline Error jb(const Imm& a)
        {
            return emit(x86::Mnemonic::Jb, a);
        }
        inline Error jb(const Label& a)
        {
            return emit(x86::Mnemonic::Jb, a);
        }
        inline Error jbe(const Imm& a)
        {
            return emit(x86::Mnemonic::Jbe, a);
        }
        inline Error jbe(const Label& a)
        {
            return emit(x86::Mnemonic::Jbe, a);
        }
        inline Error jcxz(const Imm& a)
        {
            return emit(x86::Mnemonic::Jcxz, a);
        }
        inline Error jcxz(const Label& a)
        {
            return emit(x86::Mnemonic::Jcxz, a);
        }
        inline Error jecxz(const Imm& a)
        {
            return emit(x86::Mnemonic::Jecxz, a);
        }
        inline Error jecxz(const Label& a)
        {
            return emit(x86::Mnemonic::Jecxz, a);
        }
        inline Error jl(const Imm& a)
        {
            return emit(x86::Mnemonic::Jl, a);
        }
        inline Error jl(const Label& a)
        {
            return emit(x86::Mnemonic::Jl, a);
        }
        inline Error jle(const Imm& a)
        {
            return emit(x86::Mnemonic::Jle, a);
        }
        inline Error jle(const Label& a)
        {
            return emit(x86::Mnemonic::Jle, a);
        }
        inline Error jmp(const Imm& a)
        {
            return emit(x86::Mnemonic::Jmp, a);
        }
        inline Error jmp(const Label& a)
        {
            return emit(x86::Mnemonic::Jmp, a);
        }
        inline Error jmp(const Gp& a)
        {
            return emit(x86::Mnemonic::Jmp, a);
        }
        inline Error jmp(const Mem& a)
        {
            return emit(x86::Mnemonic::Jmp, a);
        }
        inline Error jnb(const Imm& a)
        {
            return emit(x86::Mnemonic::Jnb, a);
        }
        inline Error jnb(const Label& a)
        {
            return emit(x86::Mnemonic::Jnb, a);
        }
        inline Error jnbe(const Imm& a)
        {
            return emit(x86::Mnemonic::Jnbe, a);
        }
        inline Error jnbe(const Label& a)
        {
            return emit(x86::Mnemonic::Jnbe, a);
        }
        inline Error jnl(const Imm& a)
        {
            return emit(x86::Mnemonic::Jnl, a);
        }
        inline Error jnl(const Label& a)
        {
            return emit(x86::Mnemonic::Jnl, a);
        }
        inline Error jnle(const Imm& a)
        {
            return emit(x86::Mnemonic::Jnle, a);
        }
        inline Error jnle(const Label& a)
        {
            return emit(x86::Mnemonic::Jnle, a);
        }
        inline Error jno(const Imm& a)
        {
            return emit(x86::Mnemonic::Jno, a);
        }
        inline Error jno(const Label& a)
        {
            return emit(x86::Mnemonic::Jno, a);
        }
        inline Error jnp(const Imm& a)
        {
            return emit(x86::Mnemonic::Jnp, a);
        }
        inline Error jnp(const Label& a)
        {
            return emit(x86::Mnemonic::Jnp, a);
        }
        inline Error jns(const Imm& a)
        {
            return emit(x86::Mnemonic::Jns, a);
        }
        inline Error jns(const Label& a)
        {
            return emit(x86::Mnemonic::Jns, a);
        }
        inline Error jnz(const Imm& a)
        {
            return emit(x86::Mnemonic::Jnz, a);
        }
        inline Error jnz(const Label& a)
        {
            return emit(x86::Mnemonic::Jnz, a);
        }
        inline Error jo(const Imm& a)
        {
            return emit(x86::Mnemonic::Jo, a);
        }
        inline Error jo(const Label& a)
        {
            return emit(x86::Mnemonic::Jo, a);
        }
        inline Error jp(const Imm& a)
        {
            return emit(x86::Mnemonic::Jp, a);
        }
        inline Error jp(const Label& a)
        {
            return emit(x86::Mnemonic::Jp, a);
        }
        inline Error jrcxz(const Imm& a)
        {
            return emit(x86::Mnemonic::Jrcxz, a);
        }
        inline Error jrcxz(const Label& a)
        {
            return emit(x86::Mnemonic::Jrcxz, a);
        }
        inline Error js(const Imm& a)
        {
            return emit(x86::Mnemonic::Js, a);
        }
        inline Error js(const Label& a)
        {
            return emit(x86::Mnemonic::Js, a);
        }
        inline Error jz(const Imm& a)
        {
            return emit(x86::Mnemonic::Jz, a);
        }
        inline Error jz(const Label& a)
        {
            return emit(x86::Mnemonic::Jz, a);
        }
        inline Error kaddb(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kaddb, a, b, c);
        }
        inline Error kaddd(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kaddd, a, b, c);
        }
        inline Error kaddq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kaddq, a, b, c);
        }
        inline Error kaddw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kaddw, a, b, c);
        }
        inline Error kand(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kand, a, b);
        }
        inline Error kandb(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandb, a, b, c);
        }
        inline Error kandd(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandd, a, b, c);
        }
        inline Error kandn(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kandn, a, b);
        }
        inline Error kandnb(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandnb, a, b, c);
        }
        inline Error kandnd(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandnd, a, b, c);
        }
        inline Error kandnq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandnq, a, b, c);
        }
        inline Error kandnr(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kandnr, a, b);
        }
        inline Error kandnw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandnw, a, b, c);
        }
        inline Error kandq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandq, a, b, c);
        }
        inline Error kandw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandw, a, b, c);
        }
        inline Error kconcath(const Gp64& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kconcath, a, b, c);
        }
        inline Error kconcatl(const Gp64& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kconcatl, a, b, c);
        }
        inline Error kextract(const Mask& a, const Gp64& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kextract, a, b, c);
        }
        inline Error kmerge2l1h(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmerge2l1h, a, b);
        }
        inline Error kmerge2l1l(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmerge2l1l, a, b);
        }
        inline Error kmov(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmov, a, b);
        }
        inline Error kmov(const Mask& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Kmov, a, b);
        }
        inline Error kmov(const Gp32& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmov, a, b);
        }
        inline Error kmovb(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovb, a, b);
        }
        inline Error kmovb(const Mask& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Kmovb, a, b);
        }
        inline Error kmovb(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovb, a, b);
        }
        inline Error kmovb(const Mask& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Kmovb, a, b);
        }
        inline Error kmovb(const Gp32& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovb, a, b);
        }
        inline Error kmovd(const Mask& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Kmovd, a, b);
        }
        inline Error kmovd(const Gp32& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovd, a, b);
        }
        inline Error kmovd(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovd, a, b);
        }
        inline Error kmovd(const Mask& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Kmovd, a, b);
        }
        inline Error kmovd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovd, a, b);
        }
        inline Error kmovq(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovq, a, b);
        }
        inline Error kmovq(const Mask& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Kmovq, a, b);
        }
        inline Error kmovq(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovq, a, b);
        }
        inline Error kmovq(const Mask& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Kmovq, a, b);
        }
        inline Error kmovq(const Gp64& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovq, a, b);
        }
        inline Error kmovw(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovw, a, b);
        }
        inline Error kmovw(const Mask& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Kmovw, a, b);
        }
        inline Error kmovw(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovw, a, b);
        }
        inline Error kmovw(const Mask& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Kmovw, a, b);
        }
        inline Error kmovw(const Gp32& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovw, a, b);
        }
        inline Error knot(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Knot, a, b);
        }
        inline Error knotb(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Knotb, a, b);
        }
        inline Error knotd(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Knotd, a, b);
        }
        inline Error knotq(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Knotq, a, b);
        }
        inline Error knotw(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Knotw, a, b);
        }
        inline Error kor(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kor, a, b);
        }
        inline Error korb(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Korb, a, b, c);
        }
        inline Error kord(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kord, a, b, c);
        }
        inline Error korq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Korq, a, b, c);
        }
        inline Error kortest(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kortest, a, b);
        }
        inline Error kortestb(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kortestb, a, b);
        }
        inline Error kortestd(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kortestd, a, b);
        }
        inline Error kortestq(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kortestq, a, b);
        }
        inline Error kortestw(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kortestw, a, b);
        }
        inline Error korw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Korw, a, b, c);
        }
        inline Error kshiftlb(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftlb, a, b, c);
        }
        inline Error kshiftld(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftld, a, b, c);
        }
        inline Error kshiftlq(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftlq, a, b, c);
        }
        inline Error kshiftlw(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftlw, a, b, c);
        }
        inline Error kshiftrb(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftrb, a, b, c);
        }
        inline Error kshiftrd(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftrd, a, b, c);
        }
        inline Error kshiftrq(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftrq, a, b, c);
        }
        inline Error kshiftrw(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftrw, a, b, c);
        }
        inline Error ktestb(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Ktestb, a, b);
        }
        inline Error ktestd(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Ktestd, a, b);
        }
        inline Error ktestq(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Ktestq, a, b);
        }
        inline Error ktestw(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Ktestw, a, b);
        }
        inline Error kunpckbw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kunpckbw, a, b, c);
        }
        inline Error kunpckdq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kunpckdq, a, b, c);
        }
        inline Error kunpckwd(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kunpckwd, a, b, c);
        }
        inline Error kxnor(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kxnor, a, b);
        }
        inline Error kxnorb(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxnorb, a, b, c);
        }
        inline Error kxnord(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxnord, a, b, c);
        }
        inline Error kxnorq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxnorq, a, b, c);
        }
        inline Error kxnorw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxnorw, a, b, c);
        }
        inline Error kxor(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kxor, a, b);
        }
        inline Error kxorb(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxorb, a, b, c);
        }
        inline Error kxord(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxord, a, b, c);
        }
        inline Error kxorq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxorq, a, b, c);
        }
        inline Error kxorw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxorw, a, b, c);
        }
        inline Error lahf()
        {
            return emit(x86::Mnemonic::Lahf);
        }
        inline Error lar(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Lar, a, b);
        }
        inline Error lar(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lar, a, b);
        }
        inline Error lddqu(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lddqu, a, b);
        }
        inline Error ldmxcsr(const Mem& a)
        {
            return emit(x86::Mnemonic::Ldmxcsr, a);
        }
        inline Error lds(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lds, a, b);
        }
        inline Error ldtilecfg(const Mem& a)
        {
            return emit(x86::Mnemonic::Ldtilecfg, a);
        }
        inline Error lea(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lea, a, b);
        }
        inline Error leave()
        {
            return emit(x86::Mnemonic::Leave);
        }
        inline Error les(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Les, a, b);
        }
        inline Error lfence()
        {
            return emit(x86::Mnemonic::Lfence);
        }
        inline Error lfs(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lfs, a, b);
        }
        inline Error lgdt(const Mem& a)
        {
            return emit(x86::Mnemonic::Lgdt, a);
        }
        inline Error lgs(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lgs, a, b);
        }
        inline Error lidt(const Mem& a)
        {
            return emit(x86::Mnemonic::Lidt, a);
        }
        inline Error lldt(const Gp16& a)
        {
            return emit(x86::Mnemonic::Lldt, a);
        }
        inline Error lldt(const Mem& a)
        {
            return emit(x86::Mnemonic::Lldt, a);
        }
        inline Error llwpcb(const Gp& a)
        {
            return emit(x86::Mnemonic::Llwpcb, a);
        }
        inline Error lmsw(const Gp16& a)
        {
            return emit(x86::Mnemonic::Lmsw, a);
        }
        inline Error lmsw(const Mem& a)
        {
            return emit(x86::Mnemonic::Lmsw, a);
        }
        inline Error loadiwkey(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Loadiwkey, a, b);
        }
        inline Error lodsb()
        {
            return emit(x86::Mnemonic::Lodsb);
        }
        inline Error lodsd()
        {
            return emit(x86::Mnemonic::Lodsd);
        }
        inline Error lodsq()
        {
            return emit(x86::Mnemonic::Lodsq);
        }
        inline Error lodsw()
        {
            return emit(x86::Mnemonic::Lodsw);
        }
        inline Error loop(const Imm& a)
        {
            return emit(x86::Mnemonic::Loop, a);
        }
        inline Error loope(const Imm& a)
        {
            return emit(x86::Mnemonic::Loope, a);
        }
        inline Error loopne(const Imm& a)
        {
            return emit(x86::Mnemonic::Loopne, a);
        }
        inline Error lsl(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Lsl, a, b);
        }
        inline Error lsl(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lsl, a, b);
        }
        inline Error lss(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lss, a, b);
        }
        inline Error ltr(const Gp16& a)
        {
            return emit(x86::Mnemonic::Ltr, a);
        }
        inline Error ltr(const Mem& a)
        {
            return emit(x86::Mnemonic::Ltr, a);
        }
        inline Error lwpins(const Gp& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Lwpins, a, b, c);
        }
        inline Error lwpins(const Gp& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Lwpins, a, b, c);
        }
        inline Error lwpval(const Gp& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Lwpval, a, b, c);
        }
        inline Error lwpval(const Gp& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Lwpval, a, b, c);
        }
        inline Error lzcnt(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Lzcnt, a, b);
        }
        inline Error lzcnt(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lzcnt, a, b);
        }
        inline Error lzcnt(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Lzcnt, a, b);
        }
        inline Error lzcnt(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Lzcnt, a, b);
        }
        inline Error maskmovdqu(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Maskmovdqu, a, b);
        }
        inline Error maskmovq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Maskmovq, a, b);
        }
        inline Error maxpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Maxpd, a, b);
        }
        inline Error maxpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Maxpd, a, b);
        }
        inline Error maxps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Maxps, a, b);
        }
        inline Error maxps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Maxps, a, b);
        }
        inline Error maxsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Maxsd, a, b);
        }
        inline Error maxsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Maxsd, a, b);
        }
        inline Error maxss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Maxss, a, b);
        }
        inline Error maxss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Maxss, a, b);
        }
        inline Error mcommit()
        {
            return emit(x86::Mnemonic::Mcommit);
        }
        inline Error mfence()
        {
            return emit(x86::Mnemonic::Mfence);
        }
        inline Error minpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Minpd, a, b);
        }
        inline Error minpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Minpd, a, b);
        }
        inline Error minps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Minps, a, b);
        }
        inline Error minps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Minps, a, b);
        }
        inline Error minsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Minsd, a, b);
        }
        inline Error minsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Minsd, a, b);
        }
        inline Error minss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Minss, a, b);
        }
        inline Error minss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Minss, a, b);
        }
        inline Error monitor()
        {
            return emit(x86::Mnemonic::Monitor);
        }
        inline Error monitorx()
        {
            return emit(x86::Mnemonic::Monitorx);
        }
        inline Error montmul()
        {
            return emit(x86::Mnemonic::Montmul);
        }
        inline Error mov(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Gp& a, const Seg& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Mem& a, const Seg& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Seg& a, const Gp16& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Seg& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Gp8& a, const Label& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Mem& a, const Label& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Gp64& a, const Cr& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Gp32& a, const Cr& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Gp64& a, const Dr& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Gp32& a, const Dr& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Cr& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Cr& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Dr& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Dr& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error mov(const Gp& a, const Label& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        inline Error movapd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movapd, a, b);
        }
        inline Error movapd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movapd, a, b);
        }
        inline Error movapd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movapd, a, b);
        }
        inline Error movaps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movaps, a, b);
        }
        inline Error movaps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movaps, a, b);
        }
        inline Error movaps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movaps, a, b);
        }
        inline Error movbe(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movbe, a, b);
        }
        inline Error movbe(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Movbe, a, b);
        }
        inline Error movd(const Mmx& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        inline Error movd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        inline Error movd(const Gp32& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        inline Error movd(const Mem& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        inline Error movd(const Xmm& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        inline Error movd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        inline Error movd(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        inline Error movd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        inline Error movddup(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movddup, a, b);
        }
        inline Error movddup(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movddup, a, b);
        }
        inline Error movdir64b(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movdir64b, a, b);
        }
        inline Error movdiri(const Mem& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Movdiri, a, b);
        }
        inline Error movdiri(const Mem& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Movdiri, a, b);
        }
        inline Error movdq2q(const Mmx& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movdq2q, a, b);
        }
        inline Error movdqa(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movdqa, a, b);
        }
        inline Error movdqa(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movdqa, a, b);
        }
        inline Error movdqa(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movdqa, a, b);
        }
        inline Error movdqu(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movdqu, a, b);
        }
        inline Error movdqu(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movdqu, a, b);
        }
        inline Error movdqu(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movdqu, a, b);
        }
        inline Error movhlps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movhlps, a, b);
        }
        inline Error movhpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movhpd, a, b);
        }
        inline Error movhpd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movhpd, a, b);
        }
        inline Error movhps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movhps, a, b);
        }
        inline Error movhps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movhps, a, b);
        }
        inline Error movlhps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movlhps, a, b);
        }
        inline Error movlpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movlpd, a, b);
        }
        inline Error movlpd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movlpd, a, b);
        }
        inline Error movlps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movlps, a, b);
        }
        inline Error movlps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movlps, a, b);
        }
        inline Error movmskpd(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movmskpd, a, b);
        }
        inline Error movmskps(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movmskps, a, b);
        }
        inline Error movntdq(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movntdq, a, b);
        }
        inline Error movntdqa(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movntdqa, a, b);
        }
        inline Error movnti(const Mem& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Movnti, a, b);
        }
        inline Error movnti(const Mem& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Movnti, a, b);
        }
        inline Error movntpd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movntpd, a, b);
        }
        inline Error movntps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movntps, a, b);
        }
        inline Error movntq(const Mem& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movntq, a, b);
        }
        inline Error movntsd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movntsd, a, b);
        }
        inline Error movntss(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movntss, a, b);
        }
        inline Error movq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        inline Error movq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        inline Error movq(const Mem& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        inline Error movq(const Mmx& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        inline Error movq(const Gp64& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        inline Error movq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        inline Error movq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        inline Error movq(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        inline Error movq(const Xmm& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        inline Error movq(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        inline Error movq2dq(const Xmm& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movq2dq, a, b);
        }
        inline Error movsb()
        {
            return emit(x86::Mnemonic::Movsb);
        }
        inline Error movsd()
        {
            return emit(x86::Mnemonic::Movsd);
        }
        inline Error movsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movsd, a, b);
        }
        inline Error movsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movsd, a, b);
        }
        inline Error movsd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movsd, a, b);
        }
        inline Error movshdup(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movshdup, a, b);
        }
        inline Error movshdup(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movshdup, a, b);
        }
        inline Error movsldup(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movsldup, a, b);
        }
        inline Error movsldup(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movsldup, a, b);
        }
        inline Error movsq()
        {
            return emit(x86::Mnemonic::Movsq);
        }
        inline Error movss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movss, a, b);
        }
        inline Error movss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movss, a, b);
        }
        inline Error movss(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movss, a, b);
        }
        inline Error movsw()
        {
            return emit(x86::Mnemonic::Movsw);
        }
        inline Error movsx(const Gp& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Movsx, a, b);
        }
        inline Error movsx(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movsx, a, b);
        }
        inline Error movsx(const Gp& a, const Gp16& b)
        {
            return emit(x86::Mnemonic::Movsx, a, b);
        }
        inline Error movsxd(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Movsxd, a, b);
        }
        inline Error movsxd(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movsxd, a, b);
        }
        inline Error movupd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movupd, a, b);
        }
        inline Error movupd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movupd, a, b);
        }
        inline Error movupd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movupd, a, b);
        }
        inline Error movups(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movups, a, b);
        }
        inline Error movups(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movups, a, b);
        }
        inline Error movups(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movups, a, b);
        }
        inline Error movzx(const Gp& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Movzx, a, b);
        }
        inline Error movzx(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movzx, a, b);
        }
        inline Error movzx(const Gp& a, const Gp16& b)
        {
            return emit(x86::Mnemonic::Movzx, a, b);
        }
        inline Error mpsadbw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Mpsadbw, a, b, c);
        }
        inline Error mpsadbw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Mpsadbw, a, b, c);
        }
        inline Error mul(const Gp8& a)
        {
            return emit(x86::Mnemonic::Mul, a);
        }
        inline Error mul(const Mem& a)
        {
            return emit(x86::Mnemonic::Mul, a);
        }
        inline Error mul(const Gp& a)
        {
            return emit(x86::Mnemonic::Mul, a);
        }
        inline Error mulpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Mulpd, a, b);
        }
        inline Error mulpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mulpd, a, b);
        }
        inline Error mulps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Mulps, a, b);
        }
        inline Error mulps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mulps, a, b);
        }
        inline Error mulsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Mulsd, a, b);
        }
        inline Error mulsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mulsd, a, b);
        }
        inline Error mulss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Mulss, a, b);
        }
        inline Error mulss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mulss, a, b);
        }
        inline Error mulx(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Mulx, a, b, c);
        }
        inline Error mulx(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Mulx, a, b, c);
        }
        inline Error mulx(const Gp32& a, const Gp32& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Mulx, a, b, c);
        }
        inline Error mulx(const Gp64& a, const Gp64& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Mulx, a, b, c);
        }
        inline Error mwait()
        {
            return emit(x86::Mnemonic::Mwait);
        }
        inline Error mwaitx()
        {
            return emit(x86::Mnemonic::Mwaitx);
        }
        inline Error neg(const Gp8& a)
        {
            return emit(x86::Mnemonic::Neg, a);
        }
        inline Error neg(const Mem& a)
        {
            return emit(x86::Mnemonic::Neg, a);
        }
        inline Error neg(const Gp& a)
        {
            return emit(x86::Mnemonic::Neg, a);
        }
        inline Error nop()
        {
            return emit(x86::Mnemonic::Nop);
        }
        inline Error nop(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Nop, a, b);
        }
        inline Error nop(const Gp& a)
        {
            return emit(x86::Mnemonic::Nop, a);
        }
        inline Error nop(const Mem& a)
        {
            return emit(x86::Mnemonic::Nop, a);
        }
        inline Error nop(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Nop, a, b);
        }
        inline Error not_(const Gp8& a)
        {
            return emit(x86::Mnemonic::Not, a);
        }
        inline Error not_(const Mem& a)
        {
            return emit(x86::Mnemonic::Not, a);
        }
        inline Error not_(const Gp& a)
        {
            return emit(x86::Mnemonic::Not, a);
        }
        inline Error or_(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        inline Error or_(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        inline Error or_(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        inline Error or_(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        inline Error or_(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        inline Error or_(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        inline Error or_(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        inline Error or_(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        inline Error or_(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        inline Error orpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Orpd, a, b);
        }
        inline Error orpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Orpd, a, b);
        }
        inline Error orps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Orps, a, b);
        }
        inline Error orps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Orps, a, b);
        }
        inline Error out_(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Out, a, b);
        }
        inline Error out_(const Imm& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Out, a, b);
        }
        inline Error outsb()
        {
            return emit(x86::Mnemonic::Outsb);
        }
        inline Error outsd()
        {
            return emit(x86::Mnemonic::Outsd);
        }
        inline Error outsw()
        {
            return emit(x86::Mnemonic::Outsw);
        }
        inline Error pabsb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pabsb, a, b);
        }
        inline Error pabsb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pabsb, a, b);
        }
        inline Error pabsb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pabsb, a, b);
        }
        inline Error pabsb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pabsb, a, b);
        }
        inline Error pabsd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pabsd, a, b);
        }
        inline Error pabsd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pabsd, a, b);
        }
        inline Error pabsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pabsd, a, b);
        }
        inline Error pabsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pabsd, a, b);
        }
        inline Error pabsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pabsw, a, b);
        }
        inline Error pabsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pabsw, a, b);
        }
        inline Error pabsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pabsw, a, b);
        }
        inline Error pabsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pabsw, a, b);
        }
        inline Error packssdw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Packssdw, a, b);
        }
        inline Error packssdw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packssdw, a, b);
        }
        inline Error packssdw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Packssdw, a, b);
        }
        inline Error packssdw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packssdw, a, b);
        }
        inline Error packsswb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Packsswb, a, b);
        }
        inline Error packsswb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packsswb, a, b);
        }
        inline Error packsswb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Packsswb, a, b);
        }
        inline Error packsswb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packsswb, a, b);
        }
        inline Error packusdw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Packusdw, a, b);
        }
        inline Error packusdw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packusdw, a, b);
        }
        inline Error packuswb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Packuswb, a, b);
        }
        inline Error packuswb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packuswb, a, b);
        }
        inline Error packuswb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Packuswb, a, b);
        }
        inline Error packuswb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packuswb, a, b);
        }
        inline Error paddb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddb, a, b);
        }
        inline Error paddb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddb, a, b);
        }
        inline Error paddb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddb, a, b);
        }
        inline Error paddb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddb, a, b);
        }
        inline Error paddd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddd, a, b);
        }
        inline Error paddd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddd, a, b);
        }
        inline Error paddd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddd, a, b);
        }
        inline Error paddd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddd, a, b);
        }
        inline Error paddq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddq, a, b);
        }
        inline Error paddq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddq, a, b);
        }
        inline Error paddq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddq, a, b);
        }
        inline Error paddq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddq, a, b);
        }
        inline Error paddsb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddsb, a, b);
        }
        inline Error paddsb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddsb, a, b);
        }
        inline Error paddsb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddsb, a, b);
        }
        inline Error paddsb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddsb, a, b);
        }
        inline Error paddsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddsw, a, b);
        }
        inline Error paddsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddsw, a, b);
        }
        inline Error paddsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddsw, a, b);
        }
        inline Error paddsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddsw, a, b);
        }
        inline Error paddusb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddusb, a, b);
        }
        inline Error paddusb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddusb, a, b);
        }
        inline Error paddusb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddusb, a, b);
        }
        inline Error paddusb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddusb, a, b);
        }
        inline Error paddusw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddusw, a, b);
        }
        inline Error paddusw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddusw, a, b);
        }
        inline Error paddusw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddusw, a, b);
        }
        inline Error paddusw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddusw, a, b);
        }
        inline Error paddw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddw, a, b);
        }
        inline Error paddw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddw, a, b);
        }
        inline Error paddw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddw, a, b);
        }
        inline Error paddw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddw, a, b);
        }
        inline Error palignr(const Mmx& a, const Mmx& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Palignr, a, b, c);
        }
        inline Error palignr(const Mmx& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Palignr, a, b, c);
        }
        inline Error palignr(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Palignr, a, b, c);
        }
        inline Error palignr(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Palignr, a, b, c);
        }
        inline Error pand(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pand, a, b);
        }
        inline Error pand(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pand, a, b);
        }
        inline Error pand(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pand, a, b);
        }
        inline Error pand(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pand, a, b);
        }
        inline Error pandn(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pandn, a, b);
        }
        inline Error pandn(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pandn, a, b);
        }
        inline Error pandn(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pandn, a, b);
        }
        inline Error pandn(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pandn, a, b);
        }
        inline Error pause()
        {
            return emit(x86::Mnemonic::Pause);
        }
        inline Error pavgb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pavgb, a, b);
        }
        inline Error pavgb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pavgb, a, b);
        }
        inline Error pavgb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pavgb, a, b);
        }
        inline Error pavgb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pavgb, a, b);
        }
        inline Error pavgusb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pavgusb, a, b);
        }
        inline Error pavgusb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pavgusb, a, b);
        }
        inline Error pavgw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pavgw, a, b);
        }
        inline Error pavgw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pavgw, a, b);
        }
        inline Error pavgw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pavgw, a, b);
        }
        inline Error pavgw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pavgw, a, b);
        }
        inline Error pblendvb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pblendvb, a, b);
        }
        inline Error pblendvb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pblendvb, a, b);
        }
        inline Error pblendw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pblendw, a, b, c);
        }
        inline Error pblendw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pblendw, a, b, c);
        }
        inline Error pclmulqdq(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pclmulqdq, a, b, c);
        }
        inline Error pclmulqdq(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pclmulqdq, a, b, c);
        }
        inline Error pcmpeqb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pcmpeqb, a, b);
        }
        inline Error pcmpeqb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqb, a, b);
        }
        inline Error pcmpeqb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpeqb, a, b);
        }
        inline Error pcmpeqb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqb, a, b);
        }
        inline Error pcmpeqd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pcmpeqd, a, b);
        }
        inline Error pcmpeqd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqd, a, b);
        }
        inline Error pcmpeqd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpeqd, a, b);
        }
        inline Error pcmpeqd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqd, a, b);
        }
        inline Error pcmpeqq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpeqq, a, b);
        }
        inline Error pcmpeqq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqq, a, b);
        }
        inline Error pcmpeqw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pcmpeqw, a, b);
        }
        inline Error pcmpeqw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqw, a, b);
        }
        inline Error pcmpeqw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpeqw, a, b);
        }
        inline Error pcmpeqw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqw, a, b);
        }
        inline Error pcmpestri(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpestri, a, b, c);
        }
        inline Error pcmpestri(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpestri, a, b, c);
        }
        inline Error pcmpestrm(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpestrm, a, b, c);
        }
        inline Error pcmpestrm(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpestrm, a, b, c);
        }
        inline Error pcmpgtb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pcmpgtb, a, b);
        }
        inline Error pcmpgtb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtb, a, b);
        }
        inline Error pcmpgtb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpgtb, a, b);
        }
        inline Error pcmpgtb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtb, a, b);
        }
        inline Error pcmpgtd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pcmpgtd, a, b);
        }
        inline Error pcmpgtd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtd, a, b);
        }
        inline Error pcmpgtd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpgtd, a, b);
        }
        inline Error pcmpgtd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtd, a, b);
        }
        inline Error pcmpgtq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpgtq, a, b);
        }
        inline Error pcmpgtq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtq, a, b);
        }
        inline Error pcmpgtw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pcmpgtw, a, b);
        }
        inline Error pcmpgtw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtw, a, b);
        }
        inline Error pcmpgtw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpgtw, a, b);
        }
        inline Error pcmpgtw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtw, a, b);
        }
        inline Error pcmpistri(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpistri, a, b, c);
        }
        inline Error pcmpistri(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpistri, a, b, c);
        }
        inline Error pcmpistrm(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpistrm, a, b, c);
        }
        inline Error pcmpistrm(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpistrm, a, b, c);
        }
        inline Error pconfig()
        {
            return emit(x86::Mnemonic::Pconfig);
        }
        inline Error pdep(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Pdep, a, b, c);
        }
        inline Error pdep(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Pdep, a, b, c);
        }
        inline Error pdep(const Gp32& a, const Gp32& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Pdep, a, b, c);
        }
        inline Error pdep(const Gp64& a, const Gp64& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Pdep, a, b, c);
        }
        inline Error pext(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Pext, a, b, c);
        }
        inline Error pext(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Pext, a, b, c);
        }
        inline Error pext(const Gp32& a, const Gp32& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Pext, a, b, c);
        }
        inline Error pext(const Gp64& a, const Gp64& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Pext, a, b, c);
        }
        inline Error pextrb(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrb, a, b, c);
        }
        inline Error pextrb(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrb, a, b, c);
        }
        inline Error pextrd(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrd, a, b, c);
        }
        inline Error pextrd(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrd, a, b, c);
        }
        inline Error pextrq(const Gp64& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrq, a, b, c);
        }
        inline Error pextrq(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrq, a, b, c);
        }
        inline Error pextrw(const Gp32& a, const Mmx& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrw, a, b, c);
        }
        inline Error pextrw(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrw, a, b, c);
        }
        inline Error pextrw(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrw, a, b, c);
        }
        inline Error pf2id(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pf2id, a, b);
        }
        inline Error pf2id(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pf2id, a, b);
        }
        inline Error pf2iw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pf2iw, a, b);
        }
        inline Error pf2iw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pf2iw, a, b);
        }
        inline Error pfacc(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfacc, a, b);
        }
        inline Error pfacc(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfacc, a, b);
        }
        inline Error pfadd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfadd, a, b);
        }
        inline Error pfadd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfadd, a, b);
        }
        inline Error pfcmpeq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfcmpeq, a, b);
        }
        inline Error pfcmpeq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfcmpeq, a, b);
        }
        inline Error pfcmpge(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfcmpge, a, b);
        }
        inline Error pfcmpge(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfcmpge, a, b);
        }
        inline Error pfcmpgt(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfcmpgt, a, b);
        }
        inline Error pfcmpgt(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfcmpgt, a, b);
        }
        inline Error pfcpit1(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfcpit1, a, b);
        }
        inline Error pfcpit1(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfcpit1, a, b);
        }
        inline Error pfmax(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfmax, a, b);
        }
        inline Error pfmax(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfmax, a, b);
        }
        inline Error pfmin(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfmin, a, b);
        }
        inline Error pfmin(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfmin, a, b);
        }
        inline Error pfmul(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfmul, a, b);
        }
        inline Error pfmul(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfmul, a, b);
        }
        inline Error pfnacc(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfnacc, a, b);
        }
        inline Error pfnacc(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfnacc, a, b);
        }
        inline Error pfpnacc(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfpnacc, a, b);
        }
        inline Error pfpnacc(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfpnacc, a, b);
        }
        inline Error pfrcp(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfrcp, a, b);
        }
        inline Error pfrcp(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfrcp, a, b);
        }
        inline Error pfrcpit2(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfrcpit2, a, b);
        }
        inline Error pfrcpit2(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfrcpit2, a, b);
        }
        inline Error pfrsqit1(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfrsqit1, a, b);
        }
        inline Error pfrsqit1(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfrsqit1, a, b);
        }
        inline Error pfsqrt(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfsqrt, a, b);
        }
        inline Error pfsqrt(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfsqrt, a, b);
        }
        inline Error pfsub(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfsub, a, b);
        }
        inline Error pfsub(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfsub, a, b);
        }
        inline Error pfsubr(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfsubr, a, b);
        }
        inline Error pfsubr(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfsubr, a, b);
        }
        inline Error phaddd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Phaddd, a, b);
        }
        inline Error phaddd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phaddd, a, b);
        }
        inline Error phaddd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phaddd, a, b);
        }
        inline Error phaddd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phaddd, a, b);
        }
        inline Error phaddsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Phaddsw, a, b);
        }
        inline Error phaddsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phaddsw, a, b);
        }
        inline Error phaddsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phaddsw, a, b);
        }
        inline Error phaddsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phaddsw, a, b);
        }
        inline Error phaddw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Phaddw, a, b);
        }
        inline Error phaddw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phaddw, a, b);
        }
        inline Error phaddw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phaddw, a, b);
        }
        inline Error phaddw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phaddw, a, b);
        }
        inline Error phminposuw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phminposuw, a, b);
        }
        inline Error phminposuw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phminposuw, a, b);
        }
        inline Error phsubd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Phsubd, a, b);
        }
        inline Error phsubd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phsubd, a, b);
        }
        inline Error phsubd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phsubd, a, b);
        }
        inline Error phsubd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phsubd, a, b);
        }
        inline Error phsubsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Phsubsw, a, b);
        }
        inline Error phsubsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phsubsw, a, b);
        }
        inline Error phsubsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phsubsw, a, b);
        }
        inline Error phsubsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phsubsw, a, b);
        }
        inline Error phsubw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Phsubw, a, b);
        }
        inline Error phsubw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phsubw, a, b);
        }
        inline Error phsubw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phsubw, a, b);
        }
        inline Error phsubw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phsubw, a, b);
        }
        inline Error pi2fd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pi2fd, a, b);
        }
        inline Error pi2fd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pi2fd, a, b);
        }
        inline Error pi2fw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pi2fw, a, b);
        }
        inline Error pi2fw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pi2fw, a, b);
        }
        inline Error pinsrb(const Xmm& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrb, a, b, c);
        }
        inline Error pinsrb(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrb, a, b, c);
        }
        inline Error pinsrd(const Xmm& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrd, a, b, c);
        }
        inline Error pinsrd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrd, a, b, c);
        }
        inline Error pinsrq(const Xmm& a, const Gp64& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrq, a, b, c);
        }
        inline Error pinsrq(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrq, a, b, c);
        }
        inline Error pinsrw(const Mmx& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrw, a, b, c);
        }
        inline Error pinsrw(const Mmx& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrw, a, b, c);
        }
        inline Error pinsrw(const Xmm& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrw, a, b, c);
        }
        inline Error pinsrw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrw, a, b, c);
        }
        inline Error pmaddubsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmaddubsw, a, b);
        }
        inline Error pmaddubsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaddubsw, a, b);
        }
        inline Error pmaddubsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaddubsw, a, b);
        }
        inline Error pmaddubsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaddubsw, a, b);
        }
        inline Error pmaddwd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmaddwd, a, b);
        }
        inline Error pmaddwd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaddwd, a, b);
        }
        inline Error pmaddwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaddwd, a, b);
        }
        inline Error pmaddwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaddwd, a, b);
        }
        inline Error pmaxsb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaxsb, a, b);
        }
        inline Error pmaxsb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxsb, a, b);
        }
        inline Error pmaxsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaxsd, a, b);
        }
        inline Error pmaxsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxsd, a, b);
        }
        inline Error pmaxsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmaxsw, a, b);
        }
        inline Error pmaxsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxsw, a, b);
        }
        inline Error pmaxsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaxsw, a, b);
        }
        inline Error pmaxsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxsw, a, b);
        }
        inline Error pmaxub(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmaxub, a, b);
        }
        inline Error pmaxub(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxub, a, b);
        }
        inline Error pmaxub(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaxub, a, b);
        }
        inline Error pmaxub(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxub, a, b);
        }
        inline Error pmaxud(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaxud, a, b);
        }
        inline Error pmaxud(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxud, a, b);
        }
        inline Error pmaxuw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaxuw, a, b);
        }
        inline Error pmaxuw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxuw, a, b);
        }
        inline Error pminsb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pminsb, a, b);
        }
        inline Error pminsb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminsb, a, b);
        }
        inline Error pminsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pminsd, a, b);
        }
        inline Error pminsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminsd, a, b);
        }
        inline Error pminsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pminsw, a, b);
        }
        inline Error pminsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminsw, a, b);
        }
        inline Error pminsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pminsw, a, b);
        }
        inline Error pminsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminsw, a, b);
        }
        inline Error pminub(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pminub, a, b);
        }
        inline Error pminub(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminub, a, b);
        }
        inline Error pminub(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pminub, a, b);
        }
        inline Error pminub(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminub, a, b);
        }
        inline Error pminud(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pminud, a, b);
        }
        inline Error pminud(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminud, a, b);
        }
        inline Error pminuw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pminuw, a, b);
        }
        inline Error pminuw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminuw, a, b);
        }
        inline Error pmovmskb(const Gp32& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmovmskb, a, b);
        }
        inline Error pmovmskb(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovmskb, a, b);
        }
        inline Error pmovsxbd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovsxbd, a, b);
        }
        inline Error pmovsxbd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovsxbd, a, b);
        }
        inline Error pmovsxbq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovsxbq, a, b);
        }
        inline Error pmovsxbq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovsxbq, a, b);
        }
        inline Error pmovsxbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovsxbw, a, b);
        }
        inline Error pmovsxbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovsxbw, a, b);
        }
        inline Error pmovsxdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovsxdq, a, b);
        }
        inline Error pmovsxdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovsxdq, a, b);
        }
        inline Error pmovsxwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovsxwd, a, b);
        }
        inline Error pmovsxwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovsxwd, a, b);
        }
        inline Error pmovsxwq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovsxwq, a, b);
        }
        inline Error pmovsxwq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovsxwq, a, b);
        }
        inline Error pmovzxbd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovzxbd, a, b);
        }
        inline Error pmovzxbd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovzxbd, a, b);
        }
        inline Error pmovzxbq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovzxbq, a, b);
        }
        inline Error pmovzxbq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovzxbq, a, b);
        }
        inline Error pmovzxbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovzxbw, a, b);
        }
        inline Error pmovzxbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovzxbw, a, b);
        }
        inline Error pmovzxdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovzxdq, a, b);
        }
        inline Error pmovzxdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovzxdq, a, b);
        }
        inline Error pmovzxwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovzxwd, a, b);
        }
        inline Error pmovzxwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovzxwd, a, b);
        }
        inline Error pmovzxwq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovzxwq, a, b);
        }
        inline Error pmovzxwq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovzxwq, a, b);
        }
        inline Error pmuldq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmuldq, a, b);
        }
        inline Error pmuldq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmuldq, a, b);
        }
        inline Error pmulhrsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmulhrsw, a, b);
        }
        inline Error pmulhrsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhrsw, a, b);
        }
        inline Error pmulhrsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmulhrsw, a, b);
        }
        inline Error pmulhrsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhrsw, a, b);
        }
        inline Error pmulhrw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmulhrw, a, b);
        }
        inline Error pmulhrw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhrw, a, b);
        }
        inline Error pmulhuw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmulhuw, a, b);
        }
        inline Error pmulhuw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhuw, a, b);
        }
        inline Error pmulhuw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmulhuw, a, b);
        }
        inline Error pmulhuw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhuw, a, b);
        }
        inline Error pmulhw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmulhw, a, b);
        }
        inline Error pmulhw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhw, a, b);
        }
        inline Error pmulhw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmulhw, a, b);
        }
        inline Error pmulhw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhw, a, b);
        }
        inline Error pmulld(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmulld, a, b);
        }
        inline Error pmulld(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulld, a, b);
        }
        inline Error pmullw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmullw, a, b);
        }
        inline Error pmullw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmullw, a, b);
        }
        inline Error pmullw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmullw, a, b);
        }
        inline Error pmullw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmullw, a, b);
        }
        inline Error pmuludq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmuludq, a, b);
        }
        inline Error pmuludq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmuludq, a, b);
        }
        inline Error pmuludq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmuludq, a, b);
        }
        inline Error pmuludq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmuludq, a, b);
        }
        inline Error pop(const Seg& a)
        {
            return emit(x86::Mnemonic::Pop, a);
        }
        inline Error pop(const Gp& a)
        {
            return emit(x86::Mnemonic::Pop, a);
        }
        inline Error pop(const Mem& a)
        {
            return emit(x86::Mnemonic::Pop, a);
        }
        inline Error popa()
        {
            return emit(x86::Mnemonic::Popa);
        }
        inline Error popad()
        {
            return emit(x86::Mnemonic::Popad);
        }
        inline Error popcnt(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Popcnt, a, b);
        }
        inline Error popcnt(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Popcnt, a, b);
        }
        inline Error popcnt(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Popcnt, a, b);
        }
        inline Error popcnt(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Popcnt, a, b);
        }
        inline Error popf()
        {
            return emit(x86::Mnemonic::Popf);
        }
        inline Error popfd()
        {
            return emit(x86::Mnemonic::Popfd);
        }
        inline Error popfq()
        {
            return emit(x86::Mnemonic::Popfq);
        }
        inline Error por(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Por, a, b);
        }
        inline Error por(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Por, a, b);
        }
        inline Error por(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Por, a, b);
        }
        inline Error por(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Por, a, b);
        }
        inline Error prefetch(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetch, a);
        }
        inline Error prefetchnta(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetchnta, a);
        }
        inline Error prefetcht0(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetcht0, a);
        }
        inline Error prefetcht1(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetcht1, a);
        }
        inline Error prefetcht2(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetcht2, a);
        }
        inline Error prefetchw(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetchw, a);
        }
        inline Error prefetchwt1(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetchwt1, a);
        }
        inline Error psadbw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psadbw, a, b);
        }
        inline Error psadbw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psadbw, a, b);
        }
        inline Error psadbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psadbw, a, b);
        }
        inline Error psadbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psadbw, a, b);
        }
        inline Error pshufb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pshufb, a, b);
        }
        inline Error pshufb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pshufb, a, b);
        }
        inline Error pshufb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pshufb, a, b);
        }
        inline Error pshufb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pshufb, a, b);
        }
        inline Error pshufd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshufd, a, b, c);
        }
        inline Error pshufd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshufd, a, b, c);
        }
        inline Error pshufhw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshufhw, a, b, c);
        }
        inline Error pshufhw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshufhw, a, b, c);
        }
        inline Error pshuflw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshuflw, a, b, c);
        }
        inline Error pshuflw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshuflw, a, b, c);
        }
        inline Error pshufw(const Mmx& a, const Mmx& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshufw, a, b, c);
        }
        inline Error pshufw(const Mmx& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshufw, a, b, c);
        }
        inline Error psignb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psignb, a, b);
        }
        inline Error psignb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psignb, a, b);
        }
        inline Error psignb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psignb, a, b);
        }
        inline Error psignb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psignb, a, b);
        }
        inline Error psignd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psignd, a, b);
        }
        inline Error psignd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psignd, a, b);
        }
        inline Error psignd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psignd, a, b);
        }
        inline Error psignd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psignd, a, b);
        }
        inline Error psignw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psignw, a, b);
        }
        inline Error psignw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psignw, a, b);
        }
        inline Error psignw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psignw, a, b);
        }
        inline Error psignw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psignw, a, b);
        }
        inline Error pslld(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pslld, a, b);
        }
        inline Error pslld(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pslld, a, b);
        }
        inline Error pslld(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Pslld, a, b);
        }
        inline Error pslld(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pslld, a, b);
        }
        inline Error pslld(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pslld, a, b);
        }
        inline Error pslld(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Pslld, a, b);
        }
        inline Error pslldq(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Pslldq, a, b);
        }
        inline Error psllq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psllq, a, b);
        }
        inline Error psllq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psllq, a, b);
        }
        inline Error psllq(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psllq, a, b);
        }
        inline Error psllq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psllq, a, b);
        }
        inline Error psllq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psllq, a, b);
        }
        inline Error psllq(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psllq, a, b);
        }
        inline Error psllw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psllw, a, b);
        }
        inline Error psllw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psllw, a, b);
        }
        inline Error psllw(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psllw, a, b);
        }
        inline Error psllw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psllw, a, b);
        }
        inline Error psllw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psllw, a, b);
        }
        inline Error psllw(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psllw, a, b);
        }
        inline Error psmash(const Gp& a)
        {
            return emit(x86::Mnemonic::Psmash, a);
        }
        inline Error psrad(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psrad, a, b);
        }
        inline Error psrad(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrad, a, b);
        }
        inline Error psrad(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrad, a, b);
        }
        inline Error psrad(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psrad, a, b);
        }
        inline Error psrad(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrad, a, b);
        }
        inline Error psrad(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrad, a, b);
        }
        inline Error psraw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psraw, a, b);
        }
        inline Error psraw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psraw, a, b);
        }
        inline Error psraw(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psraw, a, b);
        }
        inline Error psraw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psraw, a, b);
        }
        inline Error psraw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psraw, a, b);
        }
        inline Error psraw(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psraw, a, b);
        }
        inline Error psrld(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psrld, a, b);
        }
        inline Error psrld(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrld, a, b);
        }
        inline Error psrld(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrld, a, b);
        }
        inline Error psrld(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psrld, a, b);
        }
        inline Error psrld(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrld, a, b);
        }
        inline Error psrld(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrld, a, b);
        }
        inline Error psrldq(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrldq, a, b);
        }
        inline Error psrlq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psrlq, a, b);
        }
        inline Error psrlq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrlq, a, b);
        }
        inline Error psrlq(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrlq, a, b);
        }
        inline Error psrlq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psrlq, a, b);
        }
        inline Error psrlq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrlq, a, b);
        }
        inline Error psrlq(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrlq, a, b);
        }
        inline Error psrlw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psrlw, a, b);
        }
        inline Error psrlw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrlw, a, b);
        }
        inline Error psrlw(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrlw, a, b);
        }
        inline Error psrlw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psrlw, a, b);
        }
        inline Error psrlw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrlw, a, b);
        }
        inline Error psrlw(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrlw, a, b);
        }
        inline Error psubb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubb, a, b);
        }
        inline Error psubb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubb, a, b);
        }
        inline Error psubb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubb, a, b);
        }
        inline Error psubb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubb, a, b);
        }
        inline Error psubd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubd, a, b);
        }
        inline Error psubd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubd, a, b);
        }
        inline Error psubd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubd, a, b);
        }
        inline Error psubd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubd, a, b);
        }
        inline Error psubq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubq, a, b);
        }
        inline Error psubq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubq, a, b);
        }
        inline Error psubq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubq, a, b);
        }
        inline Error psubq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubq, a, b);
        }
        inline Error psubsb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubsb, a, b);
        }
        inline Error psubsb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubsb, a, b);
        }
        inline Error psubsb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubsb, a, b);
        }
        inline Error psubsb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubsb, a, b);
        }
        inline Error psubsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubsw, a, b);
        }
        inline Error psubsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubsw, a, b);
        }
        inline Error psubsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubsw, a, b);
        }
        inline Error psubsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubsw, a, b);
        }
        inline Error psubusb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubusb, a, b);
        }
        inline Error psubusb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubusb, a, b);
        }
        inline Error psubusb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubusb, a, b);
        }
        inline Error psubusb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubusb, a, b);
        }
        inline Error psubusw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubusw, a, b);
        }
        inline Error psubusw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubusw, a, b);
        }
        inline Error psubusw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubusw, a, b);
        }
        inline Error psubusw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubusw, a, b);
        }
        inline Error psubw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubw, a, b);
        }
        inline Error psubw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubw, a, b);
        }
        inline Error psubw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubw, a, b);
        }
        inline Error psubw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubw, a, b);
        }
        inline Error pswapd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pswapd, a, b);
        }
        inline Error pswapd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pswapd, a, b);
        }
        inline Error ptest(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Ptest, a, b);
        }
        inline Error ptest(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ptest, a, b);
        }
        inline Error ptwrite(const Gp& a)
        {
            return emit(x86::Mnemonic::Ptwrite, a);
        }
        inline Error ptwrite(const Mem& a)
        {
            return emit(x86::Mnemonic::Ptwrite, a);
        }
        inline Error punpckhbw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Punpckhbw, a, b);
        }
        inline Error punpckhbw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhbw, a, b);
        }
        inline Error punpckhbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpckhbw, a, b);
        }
        inline Error punpckhbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhbw, a, b);
        }
        inline Error punpckhdq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Punpckhdq, a, b);
        }
        inline Error punpckhdq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhdq, a, b);
        }
        inline Error punpckhdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpckhdq, a, b);
        }
        inline Error punpckhdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhdq, a, b);
        }
        inline Error punpckhqdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpckhqdq, a, b);
        }
        inline Error punpckhqdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhqdq, a, b);
        }
        inline Error punpckhwd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Punpckhwd, a, b);
        }
        inline Error punpckhwd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhwd, a, b);
        }
        inline Error punpckhwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpckhwd, a, b);
        }
        inline Error punpckhwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhwd, a, b);
        }
        inline Error punpcklbw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Punpcklbw, a, b);
        }
        inline Error punpcklbw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpcklbw, a, b);
        }
        inline Error punpcklbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpcklbw, a, b);
        }
        inline Error punpcklbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpcklbw, a, b);
        }
        inline Error punpckldq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Punpckldq, a, b);
        }
        inline Error punpckldq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckldq, a, b);
        }
        inline Error punpckldq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpckldq, a, b);
        }
        inline Error punpckldq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckldq, a, b);
        }
        inline Error punpcklqdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpcklqdq, a, b);
        }
        inline Error punpcklqdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpcklqdq, a, b);
        }
        inline Error punpcklwd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Punpcklwd, a, b);
        }
        inline Error punpcklwd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpcklwd, a, b);
        }
        inline Error punpcklwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpcklwd, a, b);
        }
        inline Error punpcklwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpcklwd, a, b);
        }
        inline Error push(const Seg& a)
        {
            return emit(x86::Mnemonic::Push, a);
        }
        inline Error push(const Gp& a)
        {
            return emit(x86::Mnemonic::Push, a);
        }
        inline Error push(const Imm& a)
        {
            return emit(x86::Mnemonic::Push, a);
        }
        inline Error push(const Mem& a)
        {
            return emit(x86::Mnemonic::Push, a);
        }
        inline Error pusha()
        {
            return emit(x86::Mnemonic::Pusha);
        }
        inline Error pushad()
        {
            return emit(x86::Mnemonic::Pushad);
        }
        inline Error pushf()
        {
            return emit(x86::Mnemonic::Pushf);
        }
        inline Error pushfd()
        {
            return emit(x86::Mnemonic::Pushfd);
        }
        inline Error pushfq()
        {
            return emit(x86::Mnemonic::Pushfq);
        }
        inline Error pvalidate(const Gp& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Pvalidate, a, b, c);
        }
        inline Error pxor(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pxor, a, b);
        }
        inline Error pxor(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pxor, a, b);
        }
        inline Error pxor(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pxor, a, b);
        }
        inline Error pxor(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pxor, a, b);
        }
        inline Error rcl(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rcl, a, b);
        }
        inline Error rcl(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rcl, a, b);
        }
        inline Error rcl(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rcl, a, b);
        }
        inline Error rcl(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rcl, a, b);
        }
        inline Error rcl(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rcl, a, b);
        }
        inline Error rcl(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rcl, a, b);
        }
        inline Error rcpps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Rcpps, a, b);
        }
        inline Error rcpps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Rcpps, a, b);
        }
        inline Error rcpss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Rcpss, a, b);
        }
        inline Error rcpss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Rcpss, a, b);
        }
        inline Error rcr(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rcr, a, b);
        }
        inline Error rcr(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rcr, a, b);
        }
        inline Error rcr(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rcr, a, b);
        }
        inline Error rcr(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rcr, a, b);
        }
        inline Error rcr(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rcr, a, b);
        }
        inline Error rcr(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rcr, a, b);
        }
        inline Error rdfsbase(const Gp& a)
        {
            return emit(x86::Mnemonic::Rdfsbase, a);
        }
        inline Error rdgsbase(const Gp& a)
        {
            return emit(x86::Mnemonic::Rdgsbase, a);
        }
        inline Error rdmsr()
        {
            return emit(x86::Mnemonic::Rdmsr);
        }
        inline Error rdpid(const Gp64& a)
        {
            return emit(x86::Mnemonic::Rdpid, a);
        }
        inline Error rdpid(const Gp32& a)
        {
            return emit(x86::Mnemonic::Rdpid, a);
        }
        inline Error rdpkru()
        {
            return emit(x86::Mnemonic::Rdpkru);
        }
        inline Error rdpmc()
        {
            return emit(x86::Mnemonic::Rdpmc);
        }
        inline Error rdpru()
        {
            return emit(x86::Mnemonic::Rdpru);
        }
        inline Error rdrand(const Gp& a)
        {
            return emit(x86::Mnemonic::Rdrand, a);
        }
        inline Error rdseed(const Gp& a)
        {
            return emit(x86::Mnemonic::Rdseed, a);
        }
        inline Error rdsspd(const Gp32& a)
        {
            return emit(x86::Mnemonic::Rdsspd, a);
        }
        inline Error rdsspq(const Gp64& a)
        {
            return emit(x86::Mnemonic::Rdsspq, a);
        }
        inline Error rdtsc()
        {
            return emit(x86::Mnemonic::Rdtsc);
        }
        inline Error rdtscp()
        {
            return emit(x86::Mnemonic::Rdtscp);
        }
        inline Error ret()
        {
            return emit(x86::Mnemonic::Ret);
        }
        inline Error ret(const Imm& a)
        {
            return emit(x86::Mnemonic::Ret, a);
        }
        inline Error rmpadjust(const Gp& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Rmpadjust, a, b, c);
        }
        inline Error rmpupdate(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rmpupdate, a, b);
        }
        inline Error rol(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rol, a, b);
        }
        inline Error rol(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rol, a, b);
        }
        inline Error rol(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rol, a, b);
        }
        inline Error rol(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rol, a, b);
        }
        inline Error rol(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rol, a, b);
        }
        inline Error rol(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rol, a, b);
        }
        inline Error ror(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Ror, a, b);
        }
        inline Error ror(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Ror, a, b);
        }
        inline Error ror(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Ror, a, b);
        }
        inline Error ror(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Ror, a, b);
        }
        inline Error ror(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Ror, a, b);
        }
        inline Error ror(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Ror, a, b);
        }
        inline Error rorx(const Gp32& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Rorx, a, b, c);
        }
        inline Error rorx(const Gp64& a, const Gp64& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Rorx, a, b, c);
        }
        inline Error rorx(const Gp32& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Rorx, a, b, c);
        }
        inline Error rorx(const Gp64& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Rorx, a, b, c);
        }
        inline Error roundpd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundpd, a, b, c);
        }
        inline Error roundpd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundpd, a, b, c);
        }
        inline Error roundps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundps, a, b, c);
        }
        inline Error roundps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundps, a, b, c);
        }
        inline Error roundsd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundsd, a, b, c);
        }
        inline Error roundsd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundsd, a, b, c);
        }
        inline Error roundss(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundss, a, b, c);
        }
        inline Error roundss(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundss, a, b, c);
        }
        inline Error rsm()
        {
            return emit(x86::Mnemonic::Rsm);
        }
        inline Error rsqrtps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Rsqrtps, a, b);
        }
        inline Error rsqrtps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Rsqrtps, a, b);
        }
        inline Error rsqrtss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Rsqrtss, a, b);
        }
        inline Error rsqrtss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Rsqrtss, a, b);
        }
        inline Error rstorssp(const Mem& a)
        {
            return emit(x86::Mnemonic::Rstorssp, a);
        }
        inline Error sahf()
        {
            return emit(x86::Mnemonic::Sahf);
        }
        inline Error salc()
        {
            return emit(x86::Mnemonic::Salc);
        }
        inline Error sar(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sar, a, b);
        }
        inline Error sar(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sar, a, b);
        }
        inline Error sar(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sar, a, b);
        }
        inline Error sar(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sar, a, b);
        }
        inline Error sar(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sar, a, b);
        }
        inline Error sar(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sar, a, b);
        }
        inline Error sarx(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Sarx, a, b, c);
        }
        inline Error sarx(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Sarx, a, b, c);
        }
        inline Error sarx(const Gp32& a, const Mem& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Sarx, a, b, c);
        }
        inline Error sarx(const Gp64& a, const Mem& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Sarx, a, b, c);
        }
        inline Error saveprevssp()
        {
            return emit(x86::Mnemonic::Saveprevssp);
        }
        inline Error sbb(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        inline Error sbb(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        inline Error sbb(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        inline Error sbb(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        inline Error sbb(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        inline Error sbb(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        inline Error sbb(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        inline Error sbb(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        inline Error sbb(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        inline Error scasb()
        {
            return emit(x86::Mnemonic::Scasb);
        }
        inline Error scasd()
        {
            return emit(x86::Mnemonic::Scasd);
        }
        inline Error scasq()
        {
            return emit(x86::Mnemonic::Scasq);
        }
        inline Error scasw()
        {
            return emit(x86::Mnemonic::Scasw);
        }
        inline Error seamcall()
        {
            return emit(x86::Mnemonic::Seamcall);
        }
        inline Error seamops()
        {
            return emit(x86::Mnemonic::Seamops);
        }
        inline Error seamret()
        {
            return emit(x86::Mnemonic::Seamret);
        }
        inline Error senduipi(const Gp32& a)
        {
            return emit(x86::Mnemonic::Senduipi, a);
        }
        inline Error serialize()
        {
            return emit(x86::Mnemonic::Serialize);
        }
        inline Error setb(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setb, a);
        }
        inline Error setb(const Mem& a)
        {
            return emit(x86::Mnemonic::Setb, a);
        }
        inline Error setbe(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setbe, a);
        }
        inline Error setbe(const Mem& a)
        {
            return emit(x86::Mnemonic::Setbe, a);
        }
        inline Error setl(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setl, a);
        }
        inline Error setl(const Mem& a)
        {
            return emit(x86::Mnemonic::Setl, a);
        }
        inline Error setle(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setle, a);
        }
        inline Error setle(const Mem& a)
        {
            return emit(x86::Mnemonic::Setle, a);
        }
        inline Error setnb(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setnb, a);
        }
        inline Error setnb(const Mem& a)
        {
            return emit(x86::Mnemonic::Setnb, a);
        }
        inline Error setnbe(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setnbe, a);
        }
        inline Error setnbe(const Mem& a)
        {
            return emit(x86::Mnemonic::Setnbe, a);
        }
        inline Error setnl(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setnl, a);
        }
        inline Error setnl(const Mem& a)
        {
            return emit(x86::Mnemonic::Setnl, a);
        }
        inline Error setnle(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setnle, a);
        }
        inline Error setnle(const Mem& a)
        {
            return emit(x86::Mnemonic::Setnle, a);
        }
        inline Error setno(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setno, a);
        }
        inline Error setno(const Mem& a)
        {
            return emit(x86::Mnemonic::Setno, a);
        }
        inline Error setnp(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setnp, a);
        }
        inline Error setnp(const Mem& a)
        {
            return emit(x86::Mnemonic::Setnp, a);
        }
        inline Error setns(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setns, a);
        }
        inline Error setns(const Mem& a)
        {
            return emit(x86::Mnemonic::Setns, a);
        }
        inline Error setnz(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setnz, a);
        }
        inline Error setnz(const Mem& a)
        {
            return emit(x86::Mnemonic::Setnz, a);
        }
        inline Error seto(const Gp8& a)
        {
            return emit(x86::Mnemonic::Seto, a);
        }
        inline Error seto(const Mem& a)
        {
            return emit(x86::Mnemonic::Seto, a);
        }
        inline Error setp(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setp, a);
        }
        inline Error setp(const Mem& a)
        {
            return emit(x86::Mnemonic::Setp, a);
        }
        inline Error sets(const Gp8& a)
        {
            return emit(x86::Mnemonic::Sets, a);
        }
        inline Error sets(const Mem& a)
        {
            return emit(x86::Mnemonic::Sets, a);
        }
        inline Error setssbsy()
        {
            return emit(x86::Mnemonic::Setssbsy);
        }
        inline Error setz(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setz, a);
        }
        inline Error setz(const Mem& a)
        {
            return emit(x86::Mnemonic::Setz, a);
        }
        inline Error sfence()
        {
            return emit(x86::Mnemonic::Sfence);
        }
        inline Error sgdt(const Mem& a)
        {
            return emit(x86::Mnemonic::Sgdt, a);
        }
        inline Error sha1msg1(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sha1msg1, a, b);
        }
        inline Error sha1msg1(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sha1msg1, a, b);
        }
        inline Error sha1msg2(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sha1msg2, a, b);
        }
        inline Error sha1msg2(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sha1msg2, a, b);
        }
        inline Error sha1nexte(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sha1nexte, a, b);
        }
        inline Error sha1nexte(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sha1nexte, a, b);
        }
        inline Error sha1rnds4(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Sha1rnds4, a, b, c);
        }
        inline Error sha1rnds4(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Sha1rnds4, a, b, c);
        }
        inline Error sha256msg1(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sha256msg1, a, b);
        }
        inline Error sha256msg1(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sha256msg1, a, b);
        }
        inline Error sha256msg2(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sha256msg2, a, b);
        }
        inline Error sha256msg2(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sha256msg2, a, b);
        }
        inline Error sha256rnds2(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sha256rnds2, a, b);
        }
        inline Error sha256rnds2(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sha256rnds2, a, b);
        }
        inline Error shl(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Shl, a, b);
        }
        inline Error shl(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Shl, a, b);
        }
        inline Error shl(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Shl, a, b);
        }
        inline Error shl(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Shl, a, b);
        }
        inline Error shl(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Shl, a, b);
        }
        inline Error shl(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Shl, a, b);
        }
        inline Error shld(const Gp& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Shld, a, b, c);
        }
        inline Error shld(const Mem& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Shld, a, b, c);
        }
        inline Error shld(const Gp& a, const Gp& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shld, a, b, c);
        }
        inline Error shld(const Mem& a, const Gp& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shld, a, b, c);
        }
        inline Error shlx(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Shlx, a, b, c);
        }
        inline Error shlx(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Shlx, a, b, c);
        }
        inline Error shlx(const Gp32& a, const Mem& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Shlx, a, b, c);
        }
        inline Error shlx(const Gp64& a, const Mem& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Shlx, a, b, c);
        }
        inline Error shr(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Shr, a, b);
        }
        inline Error shr(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Shr, a, b);
        }
        inline Error shr(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Shr, a, b);
        }
        inline Error shr(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Shr, a, b);
        }
        inline Error shr(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Shr, a, b);
        }
        inline Error shr(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Shr, a, b);
        }
        inline Error shrd(const Gp& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Shrd, a, b, c);
        }
        inline Error shrd(const Mem& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Shrd, a, b, c);
        }
        inline Error shrd(const Gp& a, const Gp& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shrd, a, b, c);
        }
        inline Error shrd(const Mem& a, const Gp& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shrd, a, b, c);
        }
        inline Error shrx(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Shrx, a, b, c);
        }
        inline Error shrx(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Shrx, a, b, c);
        }
        inline Error shrx(const Gp32& a, const Mem& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Shrx, a, b, c);
        }
        inline Error shrx(const Gp64& a, const Mem& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Shrx, a, b, c);
        }
        inline Error shufpd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shufpd, a, b, c);
        }
        inline Error shufpd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shufpd, a, b, c);
        }
        inline Error shufps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shufps, a, b, c);
        }
        inline Error shufps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shufps, a, b, c);
        }
        inline Error sidt(const Mem& a)
        {
            return emit(x86::Mnemonic::Sidt, a);
        }
        inline Error skinit(const Gp& a)
        {
            return emit(x86::Mnemonic::Skinit, a);
        }
        inline Error sldt(const Gp& a)
        {
            return emit(x86::Mnemonic::Sldt, a);
        }
        inline Error sldt(const Mem& a)
        {
            return emit(x86::Mnemonic::Sldt, a);
        }
        inline Error slwpcb(const Gp& a)
        {
            return emit(x86::Mnemonic::Slwpcb, a);
        }
        inline Error smsw(const Gp& a)
        {
            return emit(x86::Mnemonic::Smsw, a);
        }
        inline Error smsw(const Mem& a)
        {
            return emit(x86::Mnemonic::Smsw, a);
        }
        inline Error spflt(const Gp32& a)
        {
            return emit(x86::Mnemonic::Spflt, a);
        }
        inline Error spflt(const Gp64& a)
        {
            return emit(x86::Mnemonic::Spflt, a);
        }
        inline Error sqrtpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sqrtpd, a, b);
        }
        inline Error sqrtpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sqrtpd, a, b);
        }
        inline Error sqrtps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sqrtps, a, b);
        }
        inline Error sqrtps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sqrtps, a, b);
        }
        inline Error sqrtsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sqrtsd, a, b);
        }
        inline Error sqrtsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sqrtsd, a, b);
        }
        inline Error sqrtss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sqrtss, a, b);
        }
        inline Error sqrtss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sqrtss, a, b);
        }
        inline Error stac()
        {
            return emit(x86::Mnemonic::Stac);
        }
        inline Error stc()
        {
            return emit(x86::Mnemonic::Stc);
        }
        inline Error std()
        {
            return emit(x86::Mnemonic::Std);
        }
        inline Error stgi()
        {
            return emit(x86::Mnemonic::Stgi);
        }
        inline Error sti()
        {
            return emit(x86::Mnemonic::Sti);
        }
        inline Error stmxcsr(const Mem& a)
        {
            return emit(x86::Mnemonic::Stmxcsr, a);
        }
        inline Error stosb()
        {
            return emit(x86::Mnemonic::Stosb);
        }
        inline Error stosd()
        {
            return emit(x86::Mnemonic::Stosd);
        }
        inline Error stosq()
        {
            return emit(x86::Mnemonic::Stosq);
        }
        inline Error stosw()
        {
            return emit(x86::Mnemonic::Stosw);
        }
        inline Error str(const Gp& a)
        {
            return emit(x86::Mnemonic::Str, a);
        }
        inline Error str(const Mem& a)
        {
            return emit(x86::Mnemonic::Str, a);
        }
        inline Error sttilecfg(const Mem& a)
        {
            return emit(x86::Mnemonic::Sttilecfg, a);
        }
        inline Error stui()
        {
            return emit(x86::Mnemonic::Stui);
        }
        inline Error sub(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        inline Error sub(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        inline Error sub(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        inline Error sub(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        inline Error sub(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        inline Error sub(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        inline Error sub(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        inline Error sub(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        inline Error sub(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        inline Error subpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Subpd, a, b);
        }
        inline Error subpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Subpd, a, b);
        }
        inline Error subps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Subps, a, b);
        }
        inline Error subps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Subps, a, b);
        }
        inline Error subsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Subsd, a, b);
        }
        inline Error subsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Subsd, a, b);
        }
        inline Error subss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Subss, a, b);
        }
        inline Error subss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Subss, a, b);
        }
        inline Error swapgs()
        {
            return emit(x86::Mnemonic::Swapgs);
        }
        inline Error syscall()
        {
            return emit(x86::Mnemonic::Syscall);
        }
        inline Error sysenter()
        {
            return emit(x86::Mnemonic::Sysenter);
        }
        inline Error sysexit()
        {
            return emit(x86::Mnemonic::Sysexit);
        }
        inline Error sysret()
        {
            return emit(x86::Mnemonic::Sysret);
        }
        inline Error t1mskc(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::T1mskc, a, b);
        }
        inline Error t1mskc(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::T1mskc, a, b);
        }
        inline Error tdcall()
        {
            return emit(x86::Mnemonic::Tdcall);
        }
        inline Error tdpbf16ps(const Tmm& a, const Tmm& b, const Tmm& c)
        {
            return emit(x86::Mnemonic::Tdpbf16ps, a, b, c);
        }
        inline Error tdpbssd(const Tmm& a, const Tmm& b, const Tmm& c)
        {
            return emit(x86::Mnemonic::Tdpbssd, a, b, c);
        }
        inline Error tdpbsud(const Tmm& a, const Tmm& b, const Tmm& c)
        {
            return emit(x86::Mnemonic::Tdpbsud, a, b, c);
        }
        inline Error tdpbusd(const Tmm& a, const Tmm& b, const Tmm& c)
        {
            return emit(x86::Mnemonic::Tdpbusd, a, b, c);
        }
        inline Error tdpbuud(const Tmm& a, const Tmm& b, const Tmm& c)
        {
            return emit(x86::Mnemonic::Tdpbuud, a, b, c);
        }
        inline Error test(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        inline Error test(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        inline Error test(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        inline Error test(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        inline Error test(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        inline Error test(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        inline Error test(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        inline Error testui()
        {
            return emit(x86::Mnemonic::Testui);
        }
        inline Error tileloadd(const Tmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Tileloadd, a, b);
        }
        inline Error tileloaddt1(const Tmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Tileloaddt1, a, b);
        }
        inline Error tilerelease()
        {
            return emit(x86::Mnemonic::Tilerelease);
        }
        inline Error tilestored(const Mem& a, const Tmm& b)
        {
            return emit(x86::Mnemonic::Tilestored, a, b);
        }
        inline Error tilezero(const Tmm& a)
        {
            return emit(x86::Mnemonic::Tilezero, a);
        }
        inline Error tlbsync()
        {
            return emit(x86::Mnemonic::Tlbsync);
        }
        inline Error tpause(const Gp32& a)
        {
            return emit(x86::Mnemonic::Tpause, a);
        }
        inline Error tzcnt(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Tzcnt, a, b);
        }
        inline Error tzcnt(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Tzcnt, a, b);
        }
        inline Error tzcnt(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Tzcnt, a, b);
        }
        inline Error tzcnt(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Tzcnt, a, b);
        }
        inline Error tzcnti(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Tzcnti, a, b);
        }
        inline Error tzcnti(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Tzcnti, a, b);
        }
        inline Error tzmsk(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Tzmsk, a, b);
        }
        inline Error tzmsk(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Tzmsk, a, b);
        }
        inline Error ucomisd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Ucomisd, a, b);
        }
        inline Error ucomisd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ucomisd, a, b);
        }
        inline Error ucomiss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Ucomiss, a, b);
        }
        inline Error ucomiss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ucomiss, a, b);
        }
        inline Error ud0(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Ud0, a, b);
        }
        inline Error ud0(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ud0, a, b);
        }
        inline Error ud1(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Ud1, a, b);
        }
        inline Error ud1(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ud1, a, b);
        }
        inline Error ud2()
        {
            return emit(x86::Mnemonic::Ud2);
        }
        inline Error uiret()
        {
            return emit(x86::Mnemonic::Uiret);
        }
        inline Error umonitor(const Gp& a)
        {
            return emit(x86::Mnemonic::Umonitor, a);
        }
        inline Error umwait(const Gp32& a)
        {
            return emit(x86::Mnemonic::Umwait, a);
        }
        inline Error unpckhpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Unpckhpd, a, b);
        }
        inline Error unpckhpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Unpckhpd, a, b);
        }
        inline Error unpckhps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Unpckhps, a, b);
        }
        inline Error unpckhps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Unpckhps, a, b);
        }
        inline Error unpcklpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Unpcklpd, a, b);
        }
        inline Error unpcklpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Unpcklpd, a, b);
        }
        inline Error unpcklps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Unpcklps, a, b);
        }
        inline Error unpcklps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Unpcklps, a, b);
        }
        inline Error v4fmaddps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::V4fmaddps, a, b, c, d);
        }
        inline Error v4fmaddss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::V4fmaddss, a, b, c, d);
        }
        inline Error v4fnmaddps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::V4fnmaddps, a, b, c, d);
        }
        inline Error v4fnmaddss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::V4fnmaddss, a, b, c, d);
        }
        inline Error vaddnpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vaddnpd, a, b, c, d);
        }
        inline Error vaddnpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddnpd, a, b, c, d);
        }
        inline Error vaddnps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vaddnps, a, b, c, d);
        }
        inline Error vaddnps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddnps, a, b, c, d);
        }
        inline Error vaddpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c);
        }
        inline Error vaddpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c);
        }
        inline Error vaddpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c);
        }
        inline Error vaddpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c);
        }
        inline Error vaddpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c, d);
        }
        inline Error vaddpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c, d);
        }
        inline Error vaddpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c, d);
        }
        inline Error vaddpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c, d);
        }
        inline Error vaddpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c, d);
        }
        inline Error vaddpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c, d);
        }
        inline Error vaddph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vaddph, a, b, c, d);
        }
        inline Error vaddph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vaddph, a, b, c, d);
        }
        inline Error vaddph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vaddph, a, b, c, d);
        }
        inline Error vaddph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddph, a, b, c, d);
        }
        inline Error vaddph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddph, a, b, c, d);
        }
        inline Error vaddph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddph, a, b, c, d);
        }
        inline Error vaddps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c);
        }
        inline Error vaddps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c);
        }
        inline Error vaddps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c);
        }
        inline Error vaddps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c);
        }
        inline Error vaddps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c, d);
        }
        inline Error vaddps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c, d);
        }
        inline Error vaddps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c, d);
        }
        inline Error vaddps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c, d);
        }
        inline Error vaddps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c, d);
        }
        inline Error vaddps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c, d);
        }
        inline Error vaddsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaddsd, a, b, c);
        }
        inline Error vaddsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddsd, a, b, c);
        }
        inline Error vaddsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vaddsd, a, b, c, d);
        }
        inline Error vaddsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddsd, a, b, c, d);
        }
        inline Error vaddsetsps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vaddsetsps, a, b, c, d);
        }
        inline Error vaddsetsps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddsetsps, a, b, c, d);
        }
        inline Error vaddsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vaddsh, a, b, c, d);
        }
        inline Error vaddsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddsh, a, b, c, d);
        }
        inline Error vaddss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaddss, a, b, c);
        }
        inline Error vaddss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddss, a, b, c);
        }
        inline Error vaddss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vaddss, a, b, c, d);
        }
        inline Error vaddss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddss, a, b, c, d);
        }
        inline Error vaddsubpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaddsubpd, a, b, c);
        }
        inline Error vaddsubpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaddsubpd, a, b, c);
        }
        inline Error vaddsubpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddsubpd, a, b, c);
        }
        inline Error vaddsubpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddsubpd, a, b, c);
        }
        inline Error vaddsubps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaddsubps, a, b, c);
        }
        inline Error vaddsubps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaddsubps, a, b, c);
        }
        inline Error vaddsubps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddsubps, a, b, c);
        }
        inline Error vaddsubps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddsubps, a, b, c);
        }
        inline Error vaesdec(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaesdec, a, b, c);
        }
        inline Error vaesdec(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaesdec, a, b, c);
        }
        inline Error vaesdec(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesdec, a, b, c);
        }
        inline Error vaesdec(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesdec, a, b, c);
        }
        inline Error vaesdec(const Zmm& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vaesdec, a, b, c);
        }
        inline Error vaesdec(const Zmm& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesdec, a, b, c);
        }
        inline Error vaesdeclast(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaesdeclast, a, b, c);
        }
        inline Error vaesdeclast(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaesdeclast, a, b, c);
        }
        inline Error vaesdeclast(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesdeclast, a, b, c);
        }
        inline Error vaesdeclast(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesdeclast, a, b, c);
        }
        inline Error vaesdeclast(const Zmm& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vaesdeclast, a, b, c);
        }
        inline Error vaesdeclast(const Zmm& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesdeclast, a, b, c);
        }
        inline Error vaesenc(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaesenc, a, b, c);
        }
        inline Error vaesenc(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaesenc, a, b, c);
        }
        inline Error vaesenc(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesenc, a, b, c);
        }
        inline Error vaesenc(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesenc, a, b, c);
        }
        inline Error vaesenc(const Zmm& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vaesenc, a, b, c);
        }
        inline Error vaesenc(const Zmm& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesenc, a, b, c);
        }
        inline Error vaesenclast(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaesenclast, a, b, c);
        }
        inline Error vaesenclast(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaesenclast, a, b, c);
        }
        inline Error vaesenclast(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesenclast, a, b, c);
        }
        inline Error vaesenclast(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesenclast, a, b, c);
        }
        inline Error vaesenclast(const Zmm& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vaesenclast, a, b, c);
        }
        inline Error vaesenclast(const Zmm& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesenclast, a, b, c);
        }
        inline Error vaesimc(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vaesimc, a, b);
        }
        inline Error vaesimc(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vaesimc, a, b);
        }
        inline Error vaeskeygenassist(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vaeskeygenassist, a, b, c);
        }
        inline Error vaeskeygenassist(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vaeskeygenassist, a, b, c);
        }
        inline Error valignd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignd, a, b, c, d, e);
        }
        inline Error valignd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignd, a, b, c, d, e);
        }
        inline Error valignd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignd, a, b, c, d, e);
        }
        inline Error valignd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignd, a, b, c, d, e);
        }
        inline Error valignd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignd, a, b, c, d, e);
        }
        inline Error valignd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignd, a, b, c, d, e);
        }
        inline Error valignq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignq, a, b, c, d, e);
        }
        inline Error valignq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignq, a, b, c, d, e);
        }
        inline Error valignq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignq, a, b, c, d, e);
        }
        inline Error valignq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignq, a, b, c, d, e);
        }
        inline Error valignq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignq, a, b, c, d, e);
        }
        inline Error valignq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignq, a, b, c, d, e);
        }
        inline Error vandnpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c);
        }
        inline Error vandnpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c);
        }
        inline Error vandnpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c);
        }
        inline Error vandnpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c);
        }
        inline Error vandnpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c, d);
        }
        inline Error vandnpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c, d);
        }
        inline Error vandnpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c, d);
        }
        inline Error vandnpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c, d);
        }
        inline Error vandnpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c, d);
        }
        inline Error vandnpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c, d);
        }
        inline Error vandnps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c);
        }
        inline Error vandnps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c);
        }
        inline Error vandnps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c);
        }
        inline Error vandnps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c);
        }
        inline Error vandnps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c, d);
        }
        inline Error vandnps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c, d);
        }
        inline Error vandnps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c, d);
        }
        inline Error vandnps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c, d);
        }
        inline Error vandnps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c, d);
        }
        inline Error vandnps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c, d);
        }
        inline Error vandpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c);
        }
        inline Error vandpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c);
        }
        inline Error vandpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c);
        }
        inline Error vandpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c);
        }
        inline Error vandpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c, d);
        }
        inline Error vandpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c, d);
        }
        inline Error vandpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c, d);
        }
        inline Error vandpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c, d);
        }
        inline Error vandpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c, d);
        }
        inline Error vandpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c, d);
        }
        inline Error vandps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c);
        }
        inline Error vandps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c);
        }
        inline Error vandps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c);
        }
        inline Error vandps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c);
        }
        inline Error vandps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c, d);
        }
        inline Error vandps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c, d);
        }
        inline Error vandps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c, d);
        }
        inline Error vandps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c, d);
        }
        inline Error vandps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c, d);
        }
        inline Error vandps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c, d);
        }
        inline Error vblendmpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vblendmpd, a, b, c, d);
        }
        inline Error vblendmpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vblendmpd, a, b, c, d);
        }
        inline Error vblendmpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vblendmpd, a, b, c, d);
        }
        inline Error vblendmpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vblendmpd, a, b, c, d);
        }
        inline Error vblendmpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vblendmpd, a, b, c, d);
        }
        inline Error vblendmpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vblendmpd, a, b, c, d);
        }
        inline Error vblendmps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vblendmps, a, b, c, d);
        }
        inline Error vblendmps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vblendmps, a, b, c, d);
        }
        inline Error vblendmps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vblendmps, a, b, c, d);
        }
        inline Error vblendmps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vblendmps, a, b, c, d);
        }
        inline Error vblendmps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vblendmps, a, b, c, d);
        }
        inline Error vblendmps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vblendmps, a, b, c, d);
        }
        inline Error vblendpd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendpd, a, b, c, d);
        }
        inline Error vblendpd(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendpd, a, b, c, d);
        }
        inline Error vblendpd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendpd, a, b, c, d);
        }
        inline Error vblendpd(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendpd, a, b, c, d);
        }
        inline Error vblendps(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendps, a, b, c, d);
        }
        inline Error vblendps(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendps, a, b, c, d);
        }
        inline Error vblendps(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendps, a, b, c, d);
        }
        inline Error vblendps(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendps, a, b, c, d);
        }
        inline Error vblendvpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vblendvpd, a, b, c, d);
        }
        inline Error vblendvpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vblendvpd, a, b, c, d);
        }
        inline Error vblendvpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vblendvpd, a, b, c, d);
        }
        inline Error vblendvpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vblendvpd, a, b, c, d);
        }
        inline Error vblendvps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vblendvps, a, b, c, d);
        }
        inline Error vblendvps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vblendvps, a, b, c, d);
        }
        inline Error vblendvps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vblendvps, a, b, c, d);
        }
        inline Error vblendvps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vblendvps, a, b, c, d);
        }
        inline Error vbroadcastf128(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vbroadcastf128, a, b);
        }
        inline Error vbroadcastf32x2(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x2, a, b, c);
        }
        inline Error vbroadcastf32x2(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x2, a, b, c);
        }
        inline Error vbroadcastf32x2(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x2, a, b, c);
        }
        inline Error vbroadcastf32x2(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x2, a, b, c);
        }
        inline Error vbroadcastf32x4(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x4, a, b, c);
        }
        inline Error vbroadcastf32x4(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x4, a, b, c);
        }
        inline Error vbroadcastf32x8(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x8, a, b, c);
        }
        inline Error vbroadcastf64x2(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf64x2, a, b, c);
        }
        inline Error vbroadcastf64x2(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf64x2, a, b, c);
        }
        inline Error vbroadcastf64x4(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf64x4, a, b, c);
        }
        inline Error vbroadcasti128(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vbroadcasti128, a, b);
        }
        inline Error vbroadcasti32x2(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x2, a, b, c);
        }
        inline Error vbroadcasti32x2(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x2, a, b, c);
        }
        inline Error vbroadcasti32x2(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x2, a, b, c);
        }
        inline Error vbroadcasti32x2(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x2, a, b, c);
        }
        inline Error vbroadcasti32x2(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x2, a, b, c);
        }
        inline Error vbroadcasti32x2(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x2, a, b, c);
        }
        inline Error vbroadcasti32x4(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x4, a, b, c);
        }
        inline Error vbroadcasti32x4(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x4, a, b, c);
        }
        inline Error vbroadcasti32x8(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x8, a, b, c);
        }
        inline Error vbroadcasti64x2(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti64x2, a, b, c);
        }
        inline Error vbroadcasti64x2(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti64x2, a, b, c);
        }
        inline Error vbroadcasti64x4(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti64x4, a, b, c);
        }
        inline Error vbroadcastsd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vbroadcastsd, a, b);
        }
        inline Error vbroadcastsd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vbroadcastsd, a, b);
        }
        inline Error vbroadcastsd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastsd, a, b, c);
        }
        inline Error vbroadcastsd(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastsd, a, b, c);
        }
        inline Error vbroadcastsd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastsd, a, b, c);
        }
        inline Error vbroadcastsd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastsd, a, b, c);
        }
        inline Error vbroadcastss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b);
        }
        inline Error vbroadcastss(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b);
        }
        inline Error vbroadcastss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b);
        }
        inline Error vbroadcastss(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b);
        }
        inline Error vbroadcastss(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b, c);
        }
        inline Error vbroadcastss(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b, c);
        }
        inline Error vbroadcastss(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b, c);
        }
        inline Error vbroadcastss(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b, c);
        }
        inline Error vbroadcastss(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b, c);
        }
        inline Error vbroadcastss(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b, c);
        }
        inline Error vcmppd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d);
        }
        inline Error vcmppd(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d);
        }
        inline Error vcmppd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d);
        }
        inline Error vcmppd(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d);
        }
        inline Error vcmppd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d, e);
        }
        inline Error vcmppd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d, e);
        }
        inline Error vcmppd(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d, e);
        }
        inline Error vcmppd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d, e);
        }
        inline Error vcmppd(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d, e);
        }
        inline Error vcmppd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d, e);
        }
        inline Error vcmpph(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpph, a, b, c, d, e);
        }
        inline Error vcmpph(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpph, a, b, c, d, e);
        }
        inline Error vcmpph(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpph, a, b, c, d, e);
        }
        inline Error vcmpph(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpph, a, b, c, d, e);
        }
        inline Error vcmpph(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpph, a, b, c, d, e);
        }
        inline Error vcmpph(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpph, a, b, c, d, e);
        }
        inline Error vcmpps(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d);
        }
        inline Error vcmpps(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d);
        }
        inline Error vcmpps(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d);
        }
        inline Error vcmpps(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d);
        }
        inline Error vcmpps(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d, e);
        }
        inline Error vcmpps(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d, e);
        }
        inline Error vcmpps(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d, e);
        }
        inline Error vcmpps(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d, e);
        }
        inline Error vcmpps(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d, e);
        }
        inline Error vcmpps(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d, e);
        }
        inline Error vcmpsd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpsd, a, b, c, d);
        }
        inline Error vcmpsd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpsd, a, b, c, d);
        }
        inline Error vcmpsd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpsd, a, b, c, d, e);
        }
        inline Error vcmpsd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpsd, a, b, c, d, e);
        }
        inline Error vcmpsh(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpsh, a, b, c, d, e);
        }
        inline Error vcmpsh(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpsh, a, b, c, d, e);
        }
        inline Error vcmpss(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpss, a, b, c, d);
        }
        inline Error vcmpss(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpss, a, b, c, d);
        }
        inline Error vcmpss(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpss, a, b, c, d, e);
        }
        inline Error vcmpss(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpss, a, b, c, d, e);
        }
        inline Error vcomisd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcomisd, a, b);
        }
        inline Error vcomisd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcomisd, a, b);
        }
        inline Error vcomish(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcomish, a, b);
        }
        inline Error vcomish(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcomish, a, b);
        }
        inline Error vcomiss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcomiss, a, b);
        }
        inline Error vcomiss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcomiss, a, b);
        }
        inline Error vcompresspd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcompresspd, a, b, c);
        }
        inline Error vcompresspd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcompresspd, a, b, c);
        }
        inline Error vcompresspd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcompresspd, a, b, c);
        }
        inline Error vcompresspd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcompresspd, a, b, c);
        }
        inline Error vcompresspd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcompresspd, a, b, c);
        }
        inline Error vcompresspd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcompresspd, a, b, c);
        }
        inline Error vcompressps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcompressps, a, b, c);
        }
        inline Error vcompressps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcompressps, a, b, c);
        }
        inline Error vcompressps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcompressps, a, b, c);
        }
        inline Error vcompressps(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcompressps, a, b, c);
        }
        inline Error vcompressps(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcompressps, a, b, c);
        }
        inline Error vcompressps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcompressps, a, b, c);
        }
        inline Error vcvtdq2pd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b);
        }
        inline Error vcvtdq2pd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b);
        }
        inline Error vcvtdq2pd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b);
        }
        inline Error vcvtdq2pd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b);
        }
        inline Error vcvtdq2pd(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        inline Error vcvtdq2pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        inline Error vcvtdq2pd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        inline Error vcvtdq2pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        inline Error vcvtdq2pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        inline Error vcvtdq2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        inline Error vcvtdq2pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        inline Error vcvtdq2ph(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ph, a, b, c);
        }
        inline Error vcvtdq2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ph, a, b, c);
        }
        inline Error vcvtdq2ph(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ph, a, b, c);
        }
        inline Error vcvtdq2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ph, a, b, c);
        }
        inline Error vcvtdq2ph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ph, a, b, c);
        }
        inline Error vcvtdq2ps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b);
        }
        inline Error vcvtdq2ps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b);
        }
        inline Error vcvtdq2ps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b);
        }
        inline Error vcvtdq2ps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b);
        }
        inline Error vcvtdq2ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b, c);
        }
        inline Error vcvtdq2ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b, c);
        }
        inline Error vcvtdq2ps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b, c);
        }
        inline Error vcvtdq2ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b, c);
        }
        inline Error vcvtdq2ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b, c);
        }
        inline Error vcvtdq2ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b, c);
        }
        inline Error vcvtfxpntdq2ps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntdq2ps, a, b, c, d);
        }
        inline Error vcvtfxpntdq2ps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntdq2ps, a, b, c, d);
        }
        inline Error vcvtfxpntpd2dq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntpd2dq, a, b, c, d);
        }
        inline Error vcvtfxpntpd2dq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntpd2dq, a, b, c, d);
        }
        inline Error vcvtfxpntpd2udq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntpd2udq, a, b, c, d);
        }
        inline Error vcvtfxpntpd2udq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntpd2udq, a, b, c, d);
        }
        inline Error vcvtfxpntps2dq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntps2dq, a, b, c, d);
        }
        inline Error vcvtfxpntps2dq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntps2dq, a, b, c, d);
        }
        inline Error vcvtfxpntps2udq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntps2udq, a, b, c, d);
        }
        inline Error vcvtfxpntps2udq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntps2udq, a, b, c, d);
        }
        inline Error vcvtfxpntudq2ps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntudq2ps, a, b, c, d);
        }
        inline Error vcvtfxpntudq2ps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntudq2ps, a, b, c, d);
        }
        inline Error vcvtne2ps2bf16(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtne2ps2bf16, a, b, c, d);
        }
        inline Error vcvtne2ps2bf16(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vcvtne2ps2bf16, a, b, c, d);
        }
        inline Error vcvtne2ps2bf16(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vcvtne2ps2bf16, a, b, c, d);
        }
        inline Error vcvtne2ps2bf16(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtne2ps2bf16, a, b, c, d);
        }
        inline Error vcvtne2ps2bf16(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtne2ps2bf16, a, b, c, d);
        }
        inline Error vcvtne2ps2bf16(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtne2ps2bf16, a, b, c, d);
        }
        inline Error vcvtneps2bf16(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtneps2bf16, a, b, c);
        }
        inline Error vcvtneps2bf16(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtneps2bf16, a, b, c);
        }
        inline Error vcvtneps2bf16(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtneps2bf16, a, b, c);
        }
        inline Error vcvtneps2bf16(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtneps2bf16, a, b, c);
        }
        inline Error vcvtneps2bf16(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtneps2bf16, a, b, c);
        }
        inline Error vcvtpd2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b);
        }
        inline Error vcvtpd2dq(const Xmm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b);
        }
        inline Error vcvtpd2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b);
        }
        inline Error vcvtpd2dq(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b, c);
        }
        inline Error vcvtpd2dq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b, c);
        }
        inline Error vcvtpd2dq(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b, c);
        }
        inline Error vcvtpd2dq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b, c);
        }
        inline Error vcvtpd2dq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b, c);
        }
        inline Error vcvtpd2ph(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ph, a, b, c);
        }
        inline Error vcvtpd2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ph, a, b, c);
        }
        inline Error vcvtpd2ph(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ph, a, b, c);
        }
        inline Error vcvtpd2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ph, a, b, c);
        }
        inline Error vcvtpd2ps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b);
        }
        inline Error vcvtpd2ps(const Xmm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b);
        }
        inline Error vcvtpd2ps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b);
        }
        inline Error vcvtpd2ps(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        inline Error vcvtpd2ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        inline Error vcvtpd2ps(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        inline Error vcvtpd2ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        inline Error vcvtpd2ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        inline Error vcvtpd2ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        inline Error vcvtpd2ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        inline Error vcvtpd2qq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2qq, a, b, c);
        }
        inline Error vcvtpd2qq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2qq, a, b, c);
        }
        inline Error vcvtpd2qq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2qq, a, b, c);
        }
        inline Error vcvtpd2qq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2qq, a, b, c);
        }
        inline Error vcvtpd2qq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2qq, a, b, c);
        }
        inline Error vcvtpd2qq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2qq, a, b, c);
        }
        inline Error vcvtpd2udq(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2udq, a, b, c);
        }
        inline Error vcvtpd2udq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2udq, a, b, c);
        }
        inline Error vcvtpd2udq(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2udq, a, b, c);
        }
        inline Error vcvtpd2udq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2udq, a, b, c);
        }
        inline Error vcvtpd2udq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2udq, a, b, c);
        }
        inline Error vcvtpd2uqq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2uqq, a, b, c);
        }
        inline Error vcvtpd2uqq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2uqq, a, b, c);
        }
        inline Error vcvtpd2uqq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2uqq, a, b, c);
        }
        inline Error vcvtpd2uqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2uqq, a, b, c);
        }
        inline Error vcvtpd2uqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2uqq, a, b, c);
        }
        inline Error vcvtpd2uqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2uqq, a, b, c);
        }
        inline Error vcvtph2dq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2dq, a, b, c);
        }
        inline Error vcvtph2dq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2dq, a, b, c);
        }
        inline Error vcvtph2dq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2dq, a, b, c);
        }
        inline Error vcvtph2dq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2dq, a, b, c);
        }
        inline Error vcvtph2dq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2dq, a, b, c);
        }
        inline Error vcvtph2dq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2dq, a, b, c);
        }
        inline Error vcvtph2pd(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2pd, a, b, c);
        }
        inline Error vcvtph2pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2pd, a, b, c);
        }
        inline Error vcvtph2pd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2pd, a, b, c);
        }
        inline Error vcvtph2pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2pd, a, b, c);
        }
        inline Error vcvtph2pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2pd, a, b, c);
        }
        inline Error vcvtph2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2pd, a, b, c);
        }
        inline Error vcvtph2ps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b);
        }
        inline Error vcvtph2ps(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b);
        }
        inline Error vcvtph2ps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b);
        }
        inline Error vcvtph2ps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b);
        }
        inline Error vcvtph2ps(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b, c);
        }
        inline Error vcvtph2ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b, c);
        }
        inline Error vcvtph2ps(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b, c);
        }
        inline Error vcvtph2ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b, c);
        }
        inline Error vcvtph2ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b, c);
        }
        inline Error vcvtph2ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b, c);
        }
        inline Error vcvtph2psx(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2psx, a, b, c);
        }
        inline Error vcvtph2psx(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2psx, a, b, c);
        }
        inline Error vcvtph2psx(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2psx, a, b, c);
        }
        inline Error vcvtph2psx(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2psx, a, b, c);
        }
        inline Error vcvtph2psx(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2psx, a, b, c);
        }
        inline Error vcvtph2psx(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2psx, a, b, c);
        }
        inline Error vcvtph2qq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2qq, a, b, c);
        }
        inline Error vcvtph2qq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2qq, a, b, c);
        }
        inline Error vcvtph2qq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2qq, a, b, c);
        }
        inline Error vcvtph2qq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2qq, a, b, c);
        }
        inline Error vcvtph2qq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2qq, a, b, c);
        }
        inline Error vcvtph2qq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2qq, a, b, c);
        }
        inline Error vcvtph2udq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2udq, a, b, c);
        }
        inline Error vcvtph2udq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2udq, a, b, c);
        }
        inline Error vcvtph2udq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2udq, a, b, c);
        }
        inline Error vcvtph2udq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2udq, a, b, c);
        }
        inline Error vcvtph2udq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2udq, a, b, c);
        }
        inline Error vcvtph2udq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2udq, a, b, c);
        }
        inline Error vcvtph2uqq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uqq, a, b, c);
        }
        inline Error vcvtph2uqq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uqq, a, b, c);
        }
        inline Error vcvtph2uqq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uqq, a, b, c);
        }
        inline Error vcvtph2uqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uqq, a, b, c);
        }
        inline Error vcvtph2uqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uqq, a, b, c);
        }
        inline Error vcvtph2uqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uqq, a, b, c);
        }
        inline Error vcvtph2uw(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uw, a, b, c);
        }
        inline Error vcvtph2uw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uw, a, b, c);
        }
        inline Error vcvtph2uw(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uw, a, b, c);
        }
        inline Error vcvtph2uw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uw, a, b, c);
        }
        inline Error vcvtph2uw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uw, a, b, c);
        }
        inline Error vcvtph2uw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uw, a, b, c);
        }
        inline Error vcvtph2w(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2w, a, b, c);
        }
        inline Error vcvtph2w(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2w, a, b, c);
        }
        inline Error vcvtph2w(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2w, a, b, c);
        }
        inline Error vcvtph2w(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2w, a, b, c);
        }
        inline Error vcvtph2w(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2w, a, b, c);
        }
        inline Error vcvtph2w(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2w, a, b, c);
        }
        inline Error vcvtps2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b);
        }
        inline Error vcvtps2dq(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b);
        }
        inline Error vcvtps2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b);
        }
        inline Error vcvtps2dq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b);
        }
        inline Error vcvtps2dq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b, c);
        }
        inline Error vcvtps2dq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b, c);
        }
        inline Error vcvtps2dq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b, c);
        }
        inline Error vcvtps2dq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b, c);
        }
        inline Error vcvtps2dq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b, c);
        }
        inline Error vcvtps2dq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b, c);
        }
        inline Error vcvtps2pd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b);
        }
        inline Error vcvtps2pd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b);
        }
        inline Error vcvtps2pd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b);
        }
        inline Error vcvtps2pd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b);
        }
        inline Error vcvtps2pd(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        inline Error vcvtps2pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        inline Error vcvtps2pd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        inline Error vcvtps2pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        inline Error vcvtps2pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        inline Error vcvtps2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        inline Error vcvtps2pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        inline Error vcvtps2ph(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c);
        }
        inline Error vcvtps2ph(const Xmm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c);
        }
        inline Error vcvtps2ph(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c);
        }
        inline Error vcvtps2ph(const Mem& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c);
        }
        inline Error vcvtps2ph(const Ymm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c, d);
        }
        inline Error vcvtps2ph(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c, d);
        }
        inline Error vcvtps2ph(const Xmm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c, d);
        }
        inline Error vcvtps2ph(const Mem& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c, d);
        }
        inline Error vcvtps2ph(const Mem& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c, d);
        }
        inline Error vcvtps2ph(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c, d);
        }
        inline Error vcvtps2phx(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2phx, a, b, c);
        }
        inline Error vcvtps2phx(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2phx, a, b, c);
        }
        inline Error vcvtps2phx(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2phx, a, b, c);
        }
        inline Error vcvtps2phx(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2phx, a, b, c);
        }
        inline Error vcvtps2phx(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2phx, a, b, c);
        }
        inline Error vcvtps2qq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2qq, a, b, c);
        }
        inline Error vcvtps2qq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2qq, a, b, c);
        }
        inline Error vcvtps2qq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2qq, a, b, c);
        }
        inline Error vcvtps2qq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2qq, a, b, c);
        }
        inline Error vcvtps2qq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2qq, a, b, c);
        }
        inline Error vcvtps2qq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2qq, a, b, c);
        }
        inline Error vcvtps2udq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2udq, a, b, c);
        }
        inline Error vcvtps2udq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2udq, a, b, c);
        }
        inline Error vcvtps2udq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2udq, a, b, c);
        }
        inline Error vcvtps2udq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2udq, a, b, c);
        }
        inline Error vcvtps2udq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2udq, a, b, c);
        }
        inline Error vcvtps2udq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2udq, a, b, c);
        }
        inline Error vcvtps2uqq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2uqq, a, b, c);
        }
        inline Error vcvtps2uqq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2uqq, a, b, c);
        }
        inline Error vcvtps2uqq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2uqq, a, b, c);
        }
        inline Error vcvtps2uqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2uqq, a, b, c);
        }
        inline Error vcvtps2uqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2uqq, a, b, c);
        }
        inline Error vcvtps2uqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2uqq, a, b, c);
        }
        inline Error vcvtqq2pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2pd, a, b, c);
        }
        inline Error vcvtqq2pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2pd, a, b, c);
        }
        inline Error vcvtqq2pd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2pd, a, b, c);
        }
        inline Error vcvtqq2pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2pd, a, b, c);
        }
        inline Error vcvtqq2pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2pd, a, b, c);
        }
        inline Error vcvtqq2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2pd, a, b, c);
        }
        inline Error vcvtqq2ph(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ph, a, b, c);
        }
        inline Error vcvtqq2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ph, a, b, c);
        }
        inline Error vcvtqq2ph(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ph, a, b, c);
        }
        inline Error vcvtqq2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ph, a, b, c);
        }
        inline Error vcvtqq2ps(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ps, a, b, c);
        }
        inline Error vcvtqq2ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ps, a, b, c);
        }
        inline Error vcvtqq2ps(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ps, a, b, c);
        }
        inline Error vcvtqq2ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ps, a, b, c);
        }
        inline Error vcvtqq2ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ps, a, b, c);
        }
        inline Error vcvtsd2sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtsd2sh, a, b, c, d);
        }
        inline Error vcvtsd2sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtsd2sh, a, b, c, d);
        }
        inline Error vcvtsd2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2si, a, b);
        }
        inline Error vcvtsd2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2si, a, b);
        }
        inline Error vcvtsd2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2si, a, b);
        }
        inline Error vcvtsd2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2si, a, b);
        }
        inline Error vcvtsd2ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtsd2ss, a, b, c);
        }
        inline Error vcvtsd2ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtsd2ss, a, b, c);
        }
        inline Error vcvtsd2ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtsd2ss, a, b, c, d);
        }
        inline Error vcvtsd2ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtsd2ss, a, b, c, d);
        }
        inline Error vcvtsd2usi(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2usi, a, b);
        }
        inline Error vcvtsd2usi(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2usi, a, b);
        }
        inline Error vcvtsd2usi(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2usi, a, b);
        }
        inline Error vcvtsd2usi(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2usi, a, b);
        }
        inline Error vcvtsh2sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtsh2sd, a, b, c, d);
        }
        inline Error vcvtsh2sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtsh2sd, a, b, c, d);
        }
        inline Error vcvtsh2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2si, a, b);
        }
        inline Error vcvtsh2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2si, a, b);
        }
        inline Error vcvtsh2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2si, a, b);
        }
        inline Error vcvtsh2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2si, a, b);
        }
        inline Error vcvtsh2ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtsh2ss, a, b, c, d);
        }
        inline Error vcvtsh2ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtsh2ss, a, b, c, d);
        }
        inline Error vcvtsh2usi(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2usi, a, b);
        }
        inline Error vcvtsh2usi(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2usi, a, b);
        }
        inline Error vcvtsh2usi(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2usi, a, b);
        }
        inline Error vcvtsh2usi(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2usi, a, b);
        }
        inline Error vcvtsi2sd(const Xmm& a, const Xmm& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2sd, a, b, c);
        }
        inline Error vcvtsi2sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2sd, a, b, c);
        }
        inline Error vcvtsi2sd(const Xmm& a, const Xmm& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2sd, a, b, c);
        }
        inline Error vcvtsi2sh(const Xmm& a, const Xmm& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2sh, a, b, c);
        }
        inline Error vcvtsi2sh(const Xmm& a, const Xmm& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2sh, a, b, c);
        }
        inline Error vcvtsi2sh(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2sh, a, b, c);
        }
        inline Error vcvtsi2ss(const Xmm& a, const Xmm& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2ss, a, b, c);
        }
        inline Error vcvtsi2ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2ss, a, b, c);
        }
        inline Error vcvtsi2ss(const Xmm& a, const Xmm& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2ss, a, b, c);
        }
        inline Error vcvtss2sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtss2sd, a, b, c);
        }
        inline Error vcvtss2sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtss2sd, a, b, c);
        }
        inline Error vcvtss2sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtss2sd, a, b, c, d);
        }
        inline Error vcvtss2sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtss2sd, a, b, c, d);
        }
        inline Error vcvtss2sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtss2sh, a, b, c, d);
        }
        inline Error vcvtss2sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtss2sh, a, b, c, d);
        }
        inline Error vcvtss2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtss2si, a, b);
        }
        inline Error vcvtss2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtss2si, a, b);
        }
        inline Error vcvtss2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtss2si, a, b);
        }
        inline Error vcvtss2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtss2si, a, b);
        }
        inline Error vcvtss2usi(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtss2usi, a, b);
        }
        inline Error vcvtss2usi(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtss2usi, a, b);
        }
        inline Error vcvtss2usi(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtss2usi, a, b);
        }
        inline Error vcvtss2usi(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtss2usi, a, b);
        }
        inline Error vcvttpd2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b);
        }
        inline Error vcvttpd2dq(const Xmm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b);
        }
        inline Error vcvttpd2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b);
        }
        inline Error vcvttpd2dq(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b, c);
        }
        inline Error vcvttpd2dq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b, c);
        }
        inline Error vcvttpd2dq(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b, c);
        }
        inline Error vcvttpd2dq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b, c);
        }
        inline Error vcvttpd2dq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b, c);
        }
        inline Error vcvttpd2qq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2qq, a, b, c);
        }
        inline Error vcvttpd2qq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2qq, a, b, c);
        }
        inline Error vcvttpd2qq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2qq, a, b, c);
        }
        inline Error vcvttpd2qq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2qq, a, b, c);
        }
        inline Error vcvttpd2qq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2qq, a, b, c);
        }
        inline Error vcvttpd2qq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2qq, a, b, c);
        }
        inline Error vcvttpd2udq(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2udq, a, b, c);
        }
        inline Error vcvttpd2udq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2udq, a, b, c);
        }
        inline Error vcvttpd2udq(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2udq, a, b, c);
        }
        inline Error vcvttpd2udq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2udq, a, b, c);
        }
        inline Error vcvttpd2udq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2udq, a, b, c);
        }
        inline Error vcvttpd2uqq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2uqq, a, b, c);
        }
        inline Error vcvttpd2uqq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2uqq, a, b, c);
        }
        inline Error vcvttpd2uqq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2uqq, a, b, c);
        }
        inline Error vcvttpd2uqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2uqq, a, b, c);
        }
        inline Error vcvttpd2uqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2uqq, a, b, c);
        }
        inline Error vcvttpd2uqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2uqq, a, b, c);
        }
        inline Error vcvttph2dq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2dq, a, b, c);
        }
        inline Error vcvttph2dq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2dq, a, b, c);
        }
        inline Error vcvttph2dq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2dq, a, b, c);
        }
        inline Error vcvttph2dq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2dq, a, b, c);
        }
        inline Error vcvttph2dq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2dq, a, b, c);
        }
        inline Error vcvttph2dq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2dq, a, b, c);
        }
        inline Error vcvttph2qq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2qq, a, b, c);
        }
        inline Error vcvttph2qq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2qq, a, b, c);
        }
        inline Error vcvttph2qq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2qq, a, b, c);
        }
        inline Error vcvttph2qq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2qq, a, b, c);
        }
        inline Error vcvttph2qq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2qq, a, b, c);
        }
        inline Error vcvttph2qq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2qq, a, b, c);
        }
        inline Error vcvttph2udq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2udq, a, b, c);
        }
        inline Error vcvttph2udq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2udq, a, b, c);
        }
        inline Error vcvttph2udq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2udq, a, b, c);
        }
        inline Error vcvttph2udq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2udq, a, b, c);
        }
        inline Error vcvttph2udq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2udq, a, b, c);
        }
        inline Error vcvttph2udq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2udq, a, b, c);
        }
        inline Error vcvttph2uqq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uqq, a, b, c);
        }
        inline Error vcvttph2uqq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uqq, a, b, c);
        }
        inline Error vcvttph2uqq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uqq, a, b, c);
        }
        inline Error vcvttph2uqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uqq, a, b, c);
        }
        inline Error vcvttph2uqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uqq, a, b, c);
        }
        inline Error vcvttph2uqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uqq, a, b, c);
        }
        inline Error vcvttph2uw(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uw, a, b, c);
        }
        inline Error vcvttph2uw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uw, a, b, c);
        }
        inline Error vcvttph2uw(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uw, a, b, c);
        }
        inline Error vcvttph2uw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uw, a, b, c);
        }
        inline Error vcvttph2uw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uw, a, b, c);
        }
        inline Error vcvttph2uw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uw, a, b, c);
        }
        inline Error vcvttph2w(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2w, a, b, c);
        }
        inline Error vcvttph2w(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2w, a, b, c);
        }
        inline Error vcvttph2w(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2w, a, b, c);
        }
        inline Error vcvttph2w(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2w, a, b, c);
        }
        inline Error vcvttph2w(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2w, a, b, c);
        }
        inline Error vcvttph2w(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2w, a, b, c);
        }
        inline Error vcvttps2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b);
        }
        inline Error vcvttps2dq(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b);
        }
        inline Error vcvttps2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b);
        }
        inline Error vcvttps2dq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b);
        }
        inline Error vcvttps2dq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b, c);
        }
        inline Error vcvttps2dq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b, c);
        }
        inline Error vcvttps2dq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b, c);
        }
        inline Error vcvttps2dq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b, c);
        }
        inline Error vcvttps2dq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b, c);
        }
        inline Error vcvttps2dq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b, c);
        }
        inline Error vcvttps2qq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2qq, a, b, c);
        }
        inline Error vcvttps2qq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2qq, a, b, c);
        }
        inline Error vcvttps2qq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2qq, a, b, c);
        }
        inline Error vcvttps2qq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2qq, a, b, c);
        }
        inline Error vcvttps2qq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2qq, a, b, c);
        }
        inline Error vcvttps2qq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2qq, a, b, c);
        }
        inline Error vcvttps2udq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2udq, a, b, c);
        }
        inline Error vcvttps2udq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2udq, a, b, c);
        }
        inline Error vcvttps2udq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2udq, a, b, c);
        }
        inline Error vcvttps2udq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2udq, a, b, c);
        }
        inline Error vcvttps2udq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2udq, a, b, c);
        }
        inline Error vcvttps2udq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2udq, a, b, c);
        }
        inline Error vcvttps2uqq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2uqq, a, b, c);
        }
        inline Error vcvttps2uqq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2uqq, a, b, c);
        }
        inline Error vcvttps2uqq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2uqq, a, b, c);
        }
        inline Error vcvttps2uqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2uqq, a, b, c);
        }
        inline Error vcvttps2uqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2uqq, a, b, c);
        }
        inline Error vcvttps2uqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2uqq, a, b, c);
        }
        inline Error vcvttsd2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2si, a, b);
        }
        inline Error vcvttsd2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2si, a, b);
        }
        inline Error vcvttsd2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2si, a, b);
        }
        inline Error vcvttsd2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2si, a, b);
        }
        inline Error vcvttsd2usi(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2usi, a, b);
        }
        inline Error vcvttsd2usi(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2usi, a, b);
        }
        inline Error vcvttsd2usi(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2usi, a, b);
        }
        inline Error vcvttsd2usi(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2usi, a, b);
        }
        inline Error vcvttsh2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2si, a, b);
        }
        inline Error vcvttsh2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2si, a, b);
        }
        inline Error vcvttsh2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2si, a, b);
        }
        inline Error vcvttsh2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2si, a, b);
        }
        inline Error vcvttsh2usi(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2usi, a, b);
        }
        inline Error vcvttsh2usi(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2usi, a, b);
        }
        inline Error vcvttsh2usi(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2usi, a, b);
        }
        inline Error vcvttsh2usi(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2usi, a, b);
        }
        inline Error vcvttss2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttss2si, a, b);
        }
        inline Error vcvttss2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttss2si, a, b);
        }
        inline Error vcvttss2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttss2si, a, b);
        }
        inline Error vcvttss2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttss2si, a, b);
        }
        inline Error vcvttss2usi(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttss2usi, a, b);
        }
        inline Error vcvttss2usi(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttss2usi, a, b);
        }
        inline Error vcvttss2usi(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttss2usi, a, b);
        }
        inline Error vcvttss2usi(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttss2usi, a, b);
        }
        inline Error vcvtudq2pd(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        inline Error vcvtudq2pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        inline Error vcvtudq2pd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        inline Error vcvtudq2pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        inline Error vcvtudq2pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        inline Error vcvtudq2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        inline Error vcvtudq2pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        inline Error vcvtudq2ph(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ph, a, b, c);
        }
        inline Error vcvtudq2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ph, a, b, c);
        }
        inline Error vcvtudq2ph(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ph, a, b, c);
        }
        inline Error vcvtudq2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ph, a, b, c);
        }
        inline Error vcvtudq2ph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ph, a, b, c);
        }
        inline Error vcvtudq2ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ps, a, b, c);
        }
        inline Error vcvtudq2ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ps, a, b, c);
        }
        inline Error vcvtudq2ps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ps, a, b, c);
        }
        inline Error vcvtudq2ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ps, a, b, c);
        }
        inline Error vcvtudq2ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ps, a, b, c);
        }
        inline Error vcvtudq2ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ps, a, b, c);
        }
        inline Error vcvtuqq2pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2pd, a, b, c);
        }
        inline Error vcvtuqq2pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2pd, a, b, c);
        }
        inline Error vcvtuqq2pd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2pd, a, b, c);
        }
        inline Error vcvtuqq2pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2pd, a, b, c);
        }
        inline Error vcvtuqq2pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2pd, a, b, c);
        }
        inline Error vcvtuqq2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2pd, a, b, c);
        }
        inline Error vcvtuqq2ph(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ph, a, b, c);
        }
        inline Error vcvtuqq2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ph, a, b, c);
        }
        inline Error vcvtuqq2ph(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ph, a, b, c);
        }
        inline Error vcvtuqq2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ph, a, b, c);
        }
        inline Error vcvtuqq2ps(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ps, a, b, c);
        }
        inline Error vcvtuqq2ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ps, a, b, c);
        }
        inline Error vcvtuqq2ps(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ps, a, b, c);
        }
        inline Error vcvtuqq2ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ps, a, b, c);
        }
        inline Error vcvtuqq2ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ps, a, b, c);
        }
        inline Error vcvtusi2sd(const Xmm& a, const Xmm& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2sd, a, b, c);
        }
        inline Error vcvtusi2sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2sd, a, b, c);
        }
        inline Error vcvtusi2sd(const Xmm& a, const Xmm& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2sd, a, b, c);
        }
        inline Error vcvtusi2sh(const Xmm& a, const Xmm& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2sh, a, b, c);
        }
        inline Error vcvtusi2sh(const Xmm& a, const Xmm& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2sh, a, b, c);
        }
        inline Error vcvtusi2sh(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2sh, a, b, c);
        }
        inline Error vcvtusi2ss(const Xmm& a, const Xmm& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2ss, a, b, c);
        }
        inline Error vcvtusi2ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2ss, a, b, c);
        }
        inline Error vcvtusi2ss(const Xmm& a, const Xmm& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2ss, a, b, c);
        }
        inline Error vcvtuw2ph(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuw2ph, a, b, c);
        }
        inline Error vcvtuw2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuw2ph, a, b, c);
        }
        inline Error vcvtuw2ph(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtuw2ph, a, b, c);
        }
        inline Error vcvtuw2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuw2ph, a, b, c);
        }
        inline Error vcvtuw2ph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuw2ph, a, b, c);
        }
        inline Error vcvtuw2ph(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuw2ph, a, b, c);
        }
        inline Error vcvtw2ph(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtw2ph, a, b, c);
        }
        inline Error vcvtw2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtw2ph, a, b, c);
        }
        inline Error vcvtw2ph(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtw2ph, a, b, c);
        }
        inline Error vcvtw2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtw2ph, a, b, c);
        }
        inline Error vcvtw2ph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtw2ph, a, b, c);
        }
        inline Error vcvtw2ph(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtw2ph, a, b, c);
        }
        inline Error vdbpsadbw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vdbpsadbw, a, b, c, d, e);
        }
        inline Error vdbpsadbw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vdbpsadbw, a, b, c, d, e);
        }
        inline Error vdbpsadbw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vdbpsadbw, a, b, c, d, e);
        }
        inline Error vdbpsadbw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vdbpsadbw, a, b, c, d, e);
        }
        inline Error vdbpsadbw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vdbpsadbw, a, b, c, d, e);
        }
        inline Error vdbpsadbw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vdbpsadbw, a, b, c, d, e);
        }
        inline Error vdivpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c);
        }
        inline Error vdivpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c);
        }
        inline Error vdivpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c);
        }
        inline Error vdivpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c);
        }
        inline Error vdivpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c, d);
        }
        inline Error vdivpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c, d);
        }
        inline Error vdivpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c, d);
        }
        inline Error vdivpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c, d);
        }
        inline Error vdivpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c, d);
        }
        inline Error vdivpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c, d);
        }
        inline Error vdivph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vdivph, a, b, c, d);
        }
        inline Error vdivph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdivph, a, b, c, d);
        }
        inline Error vdivph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vdivph, a, b, c, d);
        }
        inline Error vdivph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivph, a, b, c, d);
        }
        inline Error vdivph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivph, a, b, c, d);
        }
        inline Error vdivph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivph, a, b, c, d);
        }
        inline Error vdivps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c);
        }
        inline Error vdivps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c);
        }
        inline Error vdivps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c);
        }
        inline Error vdivps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c);
        }
        inline Error vdivps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c, d);
        }
        inline Error vdivps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c, d);
        }
        inline Error vdivps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c, d);
        }
        inline Error vdivps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c, d);
        }
        inline Error vdivps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c, d);
        }
        inline Error vdivps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c, d);
        }
        inline Error vdivsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vdivsd, a, b, c);
        }
        inline Error vdivsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vdivsd, a, b, c);
        }
        inline Error vdivsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdivsd, a, b, c, d);
        }
        inline Error vdivsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivsd, a, b, c, d);
        }
        inline Error vdivsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdivsh, a, b, c, d);
        }
        inline Error vdivsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivsh, a, b, c, d);
        }
        inline Error vdivss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vdivss, a, b, c);
        }
        inline Error vdivss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vdivss, a, b, c);
        }
        inline Error vdivss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdivss, a, b, c, d);
        }
        inline Error vdivss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivss, a, b, c, d);
        }
        inline Error vdpbf16ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdpbf16ps, a, b, c, d);
        }
        inline Error vdpbf16ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vdpbf16ps, a, b, c, d);
        }
        inline Error vdpbf16ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vdpbf16ps, a, b, c, d);
        }
        inline Error vdpbf16ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdpbf16ps, a, b, c, d);
        }
        inline Error vdpbf16ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdpbf16ps, a, b, c, d);
        }
        inline Error vdpbf16ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdpbf16ps, a, b, c, d);
        }
        inline Error vdppd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vdppd, a, b, c, d);
        }
        inline Error vdppd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vdppd, a, b, c, d);
        }
        inline Error vdpps(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vdpps, a, b, c, d);
        }
        inline Error vdpps(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vdpps, a, b, c, d);
        }
        inline Error vdpps(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vdpps, a, b, c, d);
        }
        inline Error vdpps(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vdpps, a, b, c, d);
        }
        inline Error verr(const Gp16& a)
        {
            return emit(x86::Mnemonic::Verr, a);
        }
        inline Error verr(const Mem& a)
        {
            return emit(x86::Mnemonic::Verr, a);
        }
        inline Error verw(const Gp16& a)
        {
            return emit(x86::Mnemonic::Verw, a);
        }
        inline Error verw(const Mem& a)
        {
            return emit(x86::Mnemonic::Verw, a);
        }
        inline Error vexp223ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vexp223ps, a, b, c);
        }
        inline Error vexp223ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexp223ps, a, b, c);
        }
        inline Error vexp2pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vexp2pd, a, b, c);
        }
        inline Error vexp2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexp2pd, a, b, c);
        }
        inline Error vexp2ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vexp2ps, a, b, c);
        }
        inline Error vexp2ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexp2ps, a, b, c);
        }
        inline Error vexpandpd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vexpandpd, a, b, c);
        }
        inline Error vexpandpd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vexpandpd, a, b, c);
        }
        inline Error vexpandpd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vexpandpd, a, b, c);
        }
        inline Error vexpandpd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexpandpd, a, b, c);
        }
        inline Error vexpandpd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexpandpd, a, b, c);
        }
        inline Error vexpandpd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexpandpd, a, b, c);
        }
        inline Error vexpandps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vexpandps, a, b, c);
        }
        inline Error vexpandps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vexpandps, a, b, c);
        }
        inline Error vexpandps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vexpandps, a, b, c);
        }
        inline Error vexpandps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexpandps, a, b, c);
        }
        inline Error vexpandps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexpandps, a, b, c);
        }
        inline Error vexpandps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexpandps, a, b, c);
        }
        inline Error vextractf128(const Xmm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vextractf128, a, b, c);
        }
        inline Error vextractf128(const Mem& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vextractf128, a, b, c);
        }
        inline Error vextractf32x4(const Xmm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf32x4, a, b, c, d);
        }
        inline Error vextractf32x4(const Xmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf32x4, a, b, c, d);
        }
        inline Error vextractf32x4(const Mem& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf32x4, a, b, c, d);
        }
        inline Error vextractf32x4(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf32x4, a, b, c, d);
        }
        inline Error vextractf32x8(const Ymm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf32x8, a, b, c, d);
        }
        inline Error vextractf32x8(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf32x8, a, b, c, d);
        }
        inline Error vextractf64x2(const Xmm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf64x2, a, b, c, d);
        }
        inline Error vextractf64x2(const Xmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf64x2, a, b, c, d);
        }
        inline Error vextractf64x2(const Mem& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf64x2, a, b, c, d);
        }
        inline Error vextractf64x2(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf64x2, a, b, c, d);
        }
        inline Error vextractf64x4(const Ymm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf64x4, a, b, c, d);
        }
        inline Error vextractf64x4(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf64x4, a, b, c, d);
        }
        inline Error vextracti128(const Xmm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vextracti128, a, b, c);
        }
        inline Error vextracti128(const Mem& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vextracti128, a, b, c);
        }
        inline Error vextracti32x4(const Xmm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti32x4, a, b, c, d);
        }
        inline Error vextracti32x4(const Xmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti32x4, a, b, c, d);
        }
        inline Error vextracti32x4(const Mem& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti32x4, a, b, c, d);
        }
        inline Error vextracti32x4(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti32x4, a, b, c, d);
        }
        inline Error vextracti32x8(const Ymm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti32x8, a, b, c, d);
        }
        inline Error vextracti32x8(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti32x8, a, b, c, d);
        }
        inline Error vextracti64x2(const Xmm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti64x2, a, b, c, d);
        }
        inline Error vextracti64x2(const Xmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti64x2, a, b, c, d);
        }
        inline Error vextracti64x2(const Mem& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti64x2, a, b, c, d);
        }
        inline Error vextracti64x2(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti64x2, a, b, c, d);
        }
        inline Error vextracti64x4(const Ymm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti64x4, a, b, c, d);
        }
        inline Error vextracti64x4(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti64x4, a, b, c, d);
        }
        inline Error vextractps(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vextractps, a, b, c);
        }
        inline Error vextractps(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vextractps, a, b, c);
        }
        inline Error vfcmaddcph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcph, a, b, c, d);
        }
        inline Error vfcmaddcph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcph, a, b, c, d);
        }
        inline Error vfcmaddcph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcph, a, b, c, d);
        }
        inline Error vfcmaddcph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcph, a, b, c, d);
        }
        inline Error vfcmaddcph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcph, a, b, c, d);
        }
        inline Error vfcmaddcph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcph, a, b, c, d);
        }
        inline Error vfcmaddcsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcsh, a, b, c, d);
        }
        inline Error vfcmaddcsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcsh, a, b, c, d);
        }
        inline Error vfcmulcph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfcmulcph, a, b, c, d);
        }
        inline Error vfcmulcph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfcmulcph, a, b, c, d);
        }
        inline Error vfcmulcph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfcmulcph, a, b, c, d);
        }
        inline Error vfcmulcph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmulcph, a, b, c, d);
        }
        inline Error vfcmulcph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmulcph, a, b, c, d);
        }
        inline Error vfcmulcph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmulcph, a, b, c, d);
        }
        inline Error vfcmulcsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfcmulcsh, a, b, c, d);
        }
        inline Error vfcmulcsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmulcsh, a, b, c, d);
        }
        inline Error vfixupimmpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmpd, a, b, c, d, e);
        }
        inline Error vfixupimmpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmpd, a, b, c, d, e);
        }
        inline Error vfixupimmpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmpd, a, b, c, d, e);
        }
        inline Error vfixupimmpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmpd, a, b, c, d, e);
        }
        inline Error vfixupimmpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmpd, a, b, c, d, e);
        }
        inline Error vfixupimmpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmpd, a, b, c, d, e);
        }
        inline Error vfixupimmps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmps, a, b, c, d, e);
        }
        inline Error vfixupimmps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmps, a, b, c, d, e);
        }
        inline Error vfixupimmps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmps, a, b, c, d, e);
        }
        inline Error vfixupimmps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmps, a, b, c, d, e);
        }
        inline Error vfixupimmps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmps, a, b, c, d, e);
        }
        inline Error vfixupimmps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmps, a, b, c, d, e);
        }
        inline Error vfixupimmsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmsd, a, b, c, d, e);
        }
        inline Error vfixupimmsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmsd, a, b, c, d, e);
        }
        inline Error vfixupimmss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmss, a, b, c, d, e);
        }
        inline Error vfixupimmss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmss, a, b, c, d, e);
        }
        inline Error vfixupnanpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfixupnanpd, a, b, c, d);
        }
        inline Error vfixupnanpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfixupnanpd, a, b, c, d);
        }
        inline Error vfixupnanps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfixupnanps, a, b, c, d);
        }
        inline Error vfixupnanps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfixupnanps, a, b, c, d);
        }
        inline Error vfmadd132pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c);
        }
        inline Error vfmadd132pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c);
        }
        inline Error vfmadd132pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c);
        }
        inline Error vfmadd132pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c);
        }
        inline Error vfmadd132pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c, d);
        }
        inline Error vfmadd132pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c, d);
        }
        inline Error vfmadd132pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c, d);
        }
        inline Error vfmadd132pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c, d);
        }
        inline Error vfmadd132pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c, d);
        }
        inline Error vfmadd132pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c, d);
        }
        inline Error vfmadd132ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ph, a, b, c, d);
        }
        inline Error vfmadd132ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ph, a, b, c, d);
        }
        inline Error vfmadd132ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ph, a, b, c, d);
        }
        inline Error vfmadd132ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ph, a, b, c, d);
        }
        inline Error vfmadd132ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ph, a, b, c, d);
        }
        inline Error vfmadd132ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ph, a, b, c, d);
        }
        inline Error vfmadd132ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c);
        }
        inline Error vfmadd132ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c);
        }
        inline Error vfmadd132ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c);
        }
        inline Error vfmadd132ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c);
        }
        inline Error vfmadd132ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c, d);
        }
        inline Error vfmadd132ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c, d);
        }
        inline Error vfmadd132ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c, d);
        }
        inline Error vfmadd132ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c, d);
        }
        inline Error vfmadd132ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c, d);
        }
        inline Error vfmadd132ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c, d);
        }
        inline Error vfmadd132sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd132sd, a, b, c);
        }
        inline Error vfmadd132sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd132sd, a, b, c);
        }
        inline Error vfmadd132sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132sd, a, b, c, d);
        }
        inline Error vfmadd132sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132sd, a, b, c, d);
        }
        inline Error vfmadd132sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132sh, a, b, c, d);
        }
        inline Error vfmadd132sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132sh, a, b, c, d);
        }
        inline Error vfmadd132ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd132ss, a, b, c);
        }
        inline Error vfmadd132ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd132ss, a, b, c);
        }
        inline Error vfmadd132ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ss, a, b, c, d);
        }
        inline Error vfmadd132ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ss, a, b, c, d);
        }
        inline Error vfmadd213pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c);
        }
        inline Error vfmadd213pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c);
        }
        inline Error vfmadd213pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c);
        }
        inline Error vfmadd213pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c);
        }
        inline Error vfmadd213pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c, d);
        }
        inline Error vfmadd213pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c, d);
        }
        inline Error vfmadd213pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c, d);
        }
        inline Error vfmadd213pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c, d);
        }
        inline Error vfmadd213pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c, d);
        }
        inline Error vfmadd213pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c, d);
        }
        inline Error vfmadd213ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ph, a, b, c, d);
        }
        inline Error vfmadd213ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ph, a, b, c, d);
        }
        inline Error vfmadd213ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ph, a, b, c, d);
        }
        inline Error vfmadd213ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ph, a, b, c, d);
        }
        inline Error vfmadd213ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ph, a, b, c, d);
        }
        inline Error vfmadd213ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ph, a, b, c, d);
        }
        inline Error vfmadd213ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c);
        }
        inline Error vfmadd213ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c);
        }
        inline Error vfmadd213ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c);
        }
        inline Error vfmadd213ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c);
        }
        inline Error vfmadd213ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c, d);
        }
        inline Error vfmadd213ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c, d);
        }
        inline Error vfmadd213ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c, d);
        }
        inline Error vfmadd213ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c, d);
        }
        inline Error vfmadd213ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c, d);
        }
        inline Error vfmadd213ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c, d);
        }
        inline Error vfmadd213sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd213sd, a, b, c);
        }
        inline Error vfmadd213sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd213sd, a, b, c);
        }
        inline Error vfmadd213sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213sd, a, b, c, d);
        }
        inline Error vfmadd213sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213sd, a, b, c, d);
        }
        inline Error vfmadd213sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213sh, a, b, c, d);
        }
        inline Error vfmadd213sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213sh, a, b, c, d);
        }
        inline Error vfmadd213ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd213ss, a, b, c);
        }
        inline Error vfmadd213ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd213ss, a, b, c);
        }
        inline Error vfmadd213ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ss, a, b, c, d);
        }
        inline Error vfmadd213ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ss, a, b, c, d);
        }
        inline Error vfmadd231pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c);
        }
        inline Error vfmadd231pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c);
        }
        inline Error vfmadd231pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c);
        }
        inline Error vfmadd231pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c);
        }
        inline Error vfmadd231pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c, d);
        }
        inline Error vfmadd231pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c, d);
        }
        inline Error vfmadd231pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c, d);
        }
        inline Error vfmadd231pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c, d);
        }
        inline Error vfmadd231pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c, d);
        }
        inline Error vfmadd231pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c, d);
        }
        inline Error vfmadd231ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ph, a, b, c, d);
        }
        inline Error vfmadd231ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ph, a, b, c, d);
        }
        inline Error vfmadd231ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ph, a, b, c, d);
        }
        inline Error vfmadd231ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ph, a, b, c, d);
        }
        inline Error vfmadd231ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ph, a, b, c, d);
        }
        inline Error vfmadd231ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ph, a, b, c, d);
        }
        inline Error vfmadd231ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c);
        }
        inline Error vfmadd231ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c);
        }
        inline Error vfmadd231ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c);
        }
        inline Error vfmadd231ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c);
        }
        inline Error vfmadd231ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c, d);
        }
        inline Error vfmadd231ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c, d);
        }
        inline Error vfmadd231ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c, d);
        }
        inline Error vfmadd231ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c, d);
        }
        inline Error vfmadd231ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c, d);
        }
        inline Error vfmadd231ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c, d);
        }
        inline Error vfmadd231sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd231sd, a, b, c);
        }
        inline Error vfmadd231sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd231sd, a, b, c);
        }
        inline Error vfmadd231sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231sd, a, b, c, d);
        }
        inline Error vfmadd231sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231sd, a, b, c, d);
        }
        inline Error vfmadd231sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231sh, a, b, c, d);
        }
        inline Error vfmadd231sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231sh, a, b, c, d);
        }
        inline Error vfmadd231ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd231ss, a, b, c);
        }
        inline Error vfmadd231ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd231ss, a, b, c);
        }
        inline Error vfmadd231ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ss, a, b, c, d);
        }
        inline Error vfmadd231ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ss, a, b, c, d);
        }
        inline Error vfmadd233ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd233ps, a, b, c, d);
        }
        inline Error vfmadd233ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd233ps, a, b, c, d);
        }
        inline Error vfmaddcph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddcph, a, b, c, d);
        }
        inline Error vfmaddcph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddcph, a, b, c, d);
        }
        inline Error vfmaddcph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddcph, a, b, c, d);
        }
        inline Error vfmaddcph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddcph, a, b, c, d);
        }
        inline Error vfmaddcph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddcph, a, b, c, d);
        }
        inline Error vfmaddcph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddcph, a, b, c, d);
        }
        inline Error vfmaddcsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddcsh, a, b, c, d);
        }
        inline Error vfmaddcsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddcsh, a, b, c, d);
        }
        inline Error vfmaddpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddpd, a, b, c, d);
        }
        inline Error vfmaddpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddpd, a, b, c, d);
        }
        inline Error vfmaddpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddpd, a, b, c, d);
        }
        inline Error vfmaddpd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddpd, a, b, c, d);
        }
        inline Error vfmaddpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddpd, a, b, c, d);
        }
        inline Error vfmaddpd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddpd, a, b, c, d);
        }
        inline Error vfmaddps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddps, a, b, c, d);
        }
        inline Error vfmaddps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddps, a, b, c, d);
        }
        inline Error vfmaddps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddps, a, b, c, d);
        }
        inline Error vfmaddps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddps, a, b, c, d);
        }
        inline Error vfmaddps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddps, a, b, c, d);
        }
        inline Error vfmaddps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddps, a, b, c, d);
        }
        inline Error vfmaddsd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsd, a, b, c, d);
        }
        inline Error vfmaddsd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsd, a, b, c, d);
        }
        inline Error vfmaddsd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsd, a, b, c, d);
        }
        inline Error vfmaddss(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddss, a, b, c, d);
        }
        inline Error vfmaddss(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddss, a, b, c, d);
        }
        inline Error vfmaddss(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddss, a, b, c, d);
        }
        inline Error vfmaddsub132pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c);
        }
        inline Error vfmaddsub132pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c);
        }
        inline Error vfmaddsub132pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c);
        }
        inline Error vfmaddsub132pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c);
        }
        inline Error vfmaddsub132pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c, d);
        }
        inline Error vfmaddsub132pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c, d);
        }
        inline Error vfmaddsub132pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c, d);
        }
        inline Error vfmaddsub132pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c, d);
        }
        inline Error vfmaddsub132pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c, d);
        }
        inline Error vfmaddsub132pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c, d);
        }
        inline Error vfmaddsub132ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ph, a, b, c, d);
        }
        inline Error vfmaddsub132ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ph, a, b, c, d);
        }
        inline Error vfmaddsub132ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ph, a, b, c, d);
        }
        inline Error vfmaddsub132ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ph, a, b, c, d);
        }
        inline Error vfmaddsub132ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ph, a, b, c, d);
        }
        inline Error vfmaddsub132ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ph, a, b, c, d);
        }
        inline Error vfmaddsub132ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c);
        }
        inline Error vfmaddsub132ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c);
        }
        inline Error vfmaddsub132ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c);
        }
        inline Error vfmaddsub132ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c);
        }
        inline Error vfmaddsub132ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c, d);
        }
        inline Error vfmaddsub132ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c, d);
        }
        inline Error vfmaddsub132ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c, d);
        }
        inline Error vfmaddsub132ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c, d);
        }
        inline Error vfmaddsub132ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c, d);
        }
        inline Error vfmaddsub132ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c, d);
        }
        inline Error vfmaddsub213pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c);
        }
        inline Error vfmaddsub213pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c);
        }
        inline Error vfmaddsub213pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c);
        }
        inline Error vfmaddsub213pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c);
        }
        inline Error vfmaddsub213pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c, d);
        }
        inline Error vfmaddsub213pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c, d);
        }
        inline Error vfmaddsub213pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c, d);
        }
        inline Error vfmaddsub213pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c, d);
        }
        inline Error vfmaddsub213pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c, d);
        }
        inline Error vfmaddsub213pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c, d);
        }
        inline Error vfmaddsub213ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ph, a, b, c, d);
        }
        inline Error vfmaddsub213ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ph, a, b, c, d);
        }
        inline Error vfmaddsub213ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ph, a, b, c, d);
        }
        inline Error vfmaddsub213ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ph, a, b, c, d);
        }
        inline Error vfmaddsub213ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ph, a, b, c, d);
        }
        inline Error vfmaddsub213ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ph, a, b, c, d);
        }
        inline Error vfmaddsub213ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c);
        }
        inline Error vfmaddsub213ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c);
        }
        inline Error vfmaddsub213ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c);
        }
        inline Error vfmaddsub213ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c);
        }
        inline Error vfmaddsub213ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c, d);
        }
        inline Error vfmaddsub213ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c, d);
        }
        inline Error vfmaddsub213ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c, d);
        }
        inline Error vfmaddsub213ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c, d);
        }
        inline Error vfmaddsub213ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c, d);
        }
        inline Error vfmaddsub213ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c, d);
        }
        inline Error vfmaddsub231pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c);
        }
        inline Error vfmaddsub231pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c);
        }
        inline Error vfmaddsub231pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c);
        }
        inline Error vfmaddsub231pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c);
        }
        inline Error vfmaddsub231pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c, d);
        }
        inline Error vfmaddsub231pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c, d);
        }
        inline Error vfmaddsub231pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c, d);
        }
        inline Error vfmaddsub231pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c, d);
        }
        inline Error vfmaddsub231pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c, d);
        }
        inline Error vfmaddsub231pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c, d);
        }
        inline Error vfmaddsub231ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ph, a, b, c, d);
        }
        inline Error vfmaddsub231ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ph, a, b, c, d);
        }
        inline Error vfmaddsub231ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ph, a, b, c, d);
        }
        inline Error vfmaddsub231ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ph, a, b, c, d);
        }
        inline Error vfmaddsub231ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ph, a, b, c, d);
        }
        inline Error vfmaddsub231ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ph, a, b, c, d);
        }
        inline Error vfmaddsub231ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c);
        }
        inline Error vfmaddsub231ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c);
        }
        inline Error vfmaddsub231ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c);
        }
        inline Error vfmaddsub231ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c);
        }
        inline Error vfmaddsub231ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c, d);
        }
        inline Error vfmaddsub231ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c, d);
        }
        inline Error vfmaddsub231ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c, d);
        }
        inline Error vfmaddsub231ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c, d);
        }
        inline Error vfmaddsub231ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c, d);
        }
        inline Error vfmaddsub231ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c, d);
        }
        inline Error vfmaddsubpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubpd, a, b, c, d);
        }
        inline Error vfmaddsubpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubpd, a, b, c, d);
        }
        inline Error vfmaddsubpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubpd, a, b, c, d);
        }
        inline Error vfmaddsubpd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubpd, a, b, c, d);
        }
        inline Error vfmaddsubpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubpd, a, b, c, d);
        }
        inline Error vfmaddsubpd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubpd, a, b, c, d);
        }
        inline Error vfmaddsubps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubps, a, b, c, d);
        }
        inline Error vfmaddsubps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubps, a, b, c, d);
        }
        inline Error vfmaddsubps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubps, a, b, c, d);
        }
        inline Error vfmaddsubps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubps, a, b, c, d);
        }
        inline Error vfmaddsubps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubps, a, b, c, d);
        }
        inline Error vfmaddsubps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubps, a, b, c, d);
        }
        inline Error vfmsub132pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c);
        }
        inline Error vfmsub132pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c);
        }
        inline Error vfmsub132pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c);
        }
        inline Error vfmsub132pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c);
        }
        inline Error vfmsub132pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c, d);
        }
        inline Error vfmsub132pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c, d);
        }
        inline Error vfmsub132pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c, d);
        }
        inline Error vfmsub132pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c, d);
        }
        inline Error vfmsub132pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c, d);
        }
        inline Error vfmsub132pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c, d);
        }
        inline Error vfmsub132ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ph, a, b, c, d);
        }
        inline Error vfmsub132ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ph, a, b, c, d);
        }
        inline Error vfmsub132ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ph, a, b, c, d);
        }
        inline Error vfmsub132ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ph, a, b, c, d);
        }
        inline Error vfmsub132ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ph, a, b, c, d);
        }
        inline Error vfmsub132ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ph, a, b, c, d);
        }
        inline Error vfmsub132ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c);
        }
        inline Error vfmsub132ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c);
        }
        inline Error vfmsub132ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c);
        }
        inline Error vfmsub132ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c);
        }
        inline Error vfmsub132ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c, d);
        }
        inline Error vfmsub132ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c, d);
        }
        inline Error vfmsub132ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c, d);
        }
        inline Error vfmsub132ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c, d);
        }
        inline Error vfmsub132ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c, d);
        }
        inline Error vfmsub132ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c, d);
        }
        inline Error vfmsub132sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub132sd, a, b, c);
        }
        inline Error vfmsub132sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub132sd, a, b, c);
        }
        inline Error vfmsub132sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132sd, a, b, c, d);
        }
        inline Error vfmsub132sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132sd, a, b, c, d);
        }
        inline Error vfmsub132sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132sh, a, b, c, d);
        }
        inline Error vfmsub132sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132sh, a, b, c, d);
        }
        inline Error vfmsub132ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub132ss, a, b, c);
        }
        inline Error vfmsub132ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub132ss, a, b, c);
        }
        inline Error vfmsub132ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ss, a, b, c, d);
        }
        inline Error vfmsub132ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ss, a, b, c, d);
        }
        inline Error vfmsub213pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c);
        }
        inline Error vfmsub213pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c);
        }
        inline Error vfmsub213pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c);
        }
        inline Error vfmsub213pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c);
        }
        inline Error vfmsub213pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c, d);
        }
        inline Error vfmsub213pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c, d);
        }
        inline Error vfmsub213pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c, d);
        }
        inline Error vfmsub213pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c, d);
        }
        inline Error vfmsub213pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c, d);
        }
        inline Error vfmsub213pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c, d);
        }
        inline Error vfmsub213ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ph, a, b, c, d);
        }
        inline Error vfmsub213ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ph, a, b, c, d);
        }
        inline Error vfmsub213ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ph, a, b, c, d);
        }
        inline Error vfmsub213ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ph, a, b, c, d);
        }
        inline Error vfmsub213ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ph, a, b, c, d);
        }
        inline Error vfmsub213ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ph, a, b, c, d);
        }
        inline Error vfmsub213ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c);
        }
        inline Error vfmsub213ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c);
        }
        inline Error vfmsub213ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c);
        }
        inline Error vfmsub213ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c);
        }
        inline Error vfmsub213ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c, d);
        }
        inline Error vfmsub213ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c, d);
        }
        inline Error vfmsub213ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c, d);
        }
        inline Error vfmsub213ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c, d);
        }
        inline Error vfmsub213ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c, d);
        }
        inline Error vfmsub213ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c, d);
        }
        inline Error vfmsub213sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub213sd, a, b, c);
        }
        inline Error vfmsub213sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub213sd, a, b, c);
        }
        inline Error vfmsub213sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213sd, a, b, c, d);
        }
        inline Error vfmsub213sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213sd, a, b, c, d);
        }
        inline Error vfmsub213sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213sh, a, b, c, d);
        }
        inline Error vfmsub213sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213sh, a, b, c, d);
        }
        inline Error vfmsub213ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub213ss, a, b, c);
        }
        inline Error vfmsub213ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub213ss, a, b, c);
        }
        inline Error vfmsub213ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ss, a, b, c, d);
        }
        inline Error vfmsub213ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ss, a, b, c, d);
        }
        inline Error vfmsub231pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c);
        }
        inline Error vfmsub231pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c);
        }
        inline Error vfmsub231pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c);
        }
        inline Error vfmsub231pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c);
        }
        inline Error vfmsub231pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c, d);
        }
        inline Error vfmsub231pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c, d);
        }
        inline Error vfmsub231pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c, d);
        }
        inline Error vfmsub231pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c, d);
        }
        inline Error vfmsub231pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c, d);
        }
        inline Error vfmsub231pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c, d);
        }
        inline Error vfmsub231ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ph, a, b, c, d);
        }
        inline Error vfmsub231ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ph, a, b, c, d);
        }
        inline Error vfmsub231ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ph, a, b, c, d);
        }
        inline Error vfmsub231ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ph, a, b, c, d);
        }
        inline Error vfmsub231ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ph, a, b, c, d);
        }
        inline Error vfmsub231ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ph, a, b, c, d);
        }
        inline Error vfmsub231ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c);
        }
        inline Error vfmsub231ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c);
        }
        inline Error vfmsub231ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c);
        }
        inline Error vfmsub231ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c);
        }
        inline Error vfmsub231ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c, d);
        }
        inline Error vfmsub231ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c, d);
        }
        inline Error vfmsub231ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c, d);
        }
        inline Error vfmsub231ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c, d);
        }
        inline Error vfmsub231ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c, d);
        }
        inline Error vfmsub231ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c, d);
        }
        inline Error vfmsub231sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub231sd, a, b, c);
        }
        inline Error vfmsub231sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub231sd, a, b, c);
        }
        inline Error vfmsub231sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231sd, a, b, c, d);
        }
        inline Error vfmsub231sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231sd, a, b, c, d);
        }
        inline Error vfmsub231sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231sh, a, b, c, d);
        }
        inline Error vfmsub231sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231sh, a, b, c, d);
        }
        inline Error vfmsub231ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub231ss, a, b, c);
        }
        inline Error vfmsub231ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub231ss, a, b, c);
        }
        inline Error vfmsub231ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ss, a, b, c, d);
        }
        inline Error vfmsub231ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ss, a, b, c, d);
        }
        inline Error vfmsubadd132pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c);
        }
        inline Error vfmsubadd132pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c);
        }
        inline Error vfmsubadd132pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c);
        }
        inline Error vfmsubadd132pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c);
        }
        inline Error vfmsubadd132pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c, d);
        }
        inline Error vfmsubadd132pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c, d);
        }
        inline Error vfmsubadd132pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c, d);
        }
        inline Error vfmsubadd132pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c, d);
        }
        inline Error vfmsubadd132pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c, d);
        }
        inline Error vfmsubadd132pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c, d);
        }
        inline Error vfmsubadd132ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ph, a, b, c, d);
        }
        inline Error vfmsubadd132ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ph, a, b, c, d);
        }
        inline Error vfmsubadd132ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ph, a, b, c, d);
        }
        inline Error vfmsubadd132ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ph, a, b, c, d);
        }
        inline Error vfmsubadd132ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ph, a, b, c, d);
        }
        inline Error vfmsubadd132ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ph, a, b, c, d);
        }
        inline Error vfmsubadd132ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c);
        }
        inline Error vfmsubadd132ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c);
        }
        inline Error vfmsubadd132ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c);
        }
        inline Error vfmsubadd132ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c);
        }
        inline Error vfmsubadd132ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c, d);
        }
        inline Error vfmsubadd132ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c, d);
        }
        inline Error vfmsubadd132ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c, d);
        }
        inline Error vfmsubadd132ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c, d);
        }
        inline Error vfmsubadd132ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c, d);
        }
        inline Error vfmsubadd132ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c, d);
        }
        inline Error vfmsubadd213pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c);
        }
        inline Error vfmsubadd213pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c);
        }
        inline Error vfmsubadd213pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c);
        }
        inline Error vfmsubadd213pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c);
        }
        inline Error vfmsubadd213pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c, d);
        }
        inline Error vfmsubadd213pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c, d);
        }
        inline Error vfmsubadd213pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c, d);
        }
        inline Error vfmsubadd213pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c, d);
        }
        inline Error vfmsubadd213pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c, d);
        }
        inline Error vfmsubadd213pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c, d);
        }
        inline Error vfmsubadd213ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ph, a, b, c, d);
        }
        inline Error vfmsubadd213ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ph, a, b, c, d);
        }
        inline Error vfmsubadd213ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ph, a, b, c, d);
        }
        inline Error vfmsubadd213ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ph, a, b, c, d);
        }
        inline Error vfmsubadd213ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ph, a, b, c, d);
        }
        inline Error vfmsubadd213ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ph, a, b, c, d);
        }
        inline Error vfmsubadd213ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c);
        }
        inline Error vfmsubadd213ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c);
        }
        inline Error vfmsubadd213ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c);
        }
        inline Error vfmsubadd213ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c);
        }
        inline Error vfmsubadd213ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c, d);
        }
        inline Error vfmsubadd213ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c, d);
        }
        inline Error vfmsubadd213ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c, d);
        }
        inline Error vfmsubadd213ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c, d);
        }
        inline Error vfmsubadd213ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c, d);
        }
        inline Error vfmsubadd213ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c, d);
        }
        inline Error vfmsubadd231pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c);
        }
        inline Error vfmsubadd231pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c);
        }
        inline Error vfmsubadd231pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c);
        }
        inline Error vfmsubadd231pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c);
        }
        inline Error vfmsubadd231pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c, d);
        }
        inline Error vfmsubadd231pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c, d);
        }
        inline Error vfmsubadd231pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c, d);
        }
        inline Error vfmsubadd231pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c, d);
        }
        inline Error vfmsubadd231pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c, d);
        }
        inline Error vfmsubadd231pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c, d);
        }
        inline Error vfmsubadd231ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ph, a, b, c, d);
        }
        inline Error vfmsubadd231ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ph, a, b, c, d);
        }
        inline Error vfmsubadd231ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ph, a, b, c, d);
        }
        inline Error vfmsubadd231ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ph, a, b, c, d);
        }
        inline Error vfmsubadd231ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ph, a, b, c, d);
        }
        inline Error vfmsubadd231ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ph, a, b, c, d);
        }
        inline Error vfmsubadd231ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c);
        }
        inline Error vfmsubadd231ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c);
        }
        inline Error vfmsubadd231ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c);
        }
        inline Error vfmsubadd231ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c);
        }
        inline Error vfmsubadd231ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c, d);
        }
        inline Error vfmsubadd231ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c, d);
        }
        inline Error vfmsubadd231ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c, d);
        }
        inline Error vfmsubadd231ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c, d);
        }
        inline Error vfmsubadd231ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c, d);
        }
        inline Error vfmsubadd231ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c, d);
        }
        inline Error vfmsubaddpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddpd, a, b, c, d);
        }
        inline Error vfmsubaddpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddpd, a, b, c, d);
        }
        inline Error vfmsubaddpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddpd, a, b, c, d);
        }
        inline Error vfmsubaddpd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddpd, a, b, c, d);
        }
        inline Error vfmsubaddpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddpd, a, b, c, d);
        }
        inline Error vfmsubaddpd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddpd, a, b, c, d);
        }
        inline Error vfmsubaddps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddps, a, b, c, d);
        }
        inline Error vfmsubaddps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddps, a, b, c, d);
        }
        inline Error vfmsubaddps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddps, a, b, c, d);
        }
        inline Error vfmsubaddps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddps, a, b, c, d);
        }
        inline Error vfmsubaddps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddps, a, b, c, d);
        }
        inline Error vfmsubaddps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddps, a, b, c, d);
        }
        inline Error vfmsubpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubpd, a, b, c, d);
        }
        inline Error vfmsubpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubpd, a, b, c, d);
        }
        inline Error vfmsubpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubpd, a, b, c, d);
        }
        inline Error vfmsubpd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubpd, a, b, c, d);
        }
        inline Error vfmsubpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubpd, a, b, c, d);
        }
        inline Error vfmsubpd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubpd, a, b, c, d);
        }
        inline Error vfmsubps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubps, a, b, c, d);
        }
        inline Error vfmsubps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubps, a, b, c, d);
        }
        inline Error vfmsubps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubps, a, b, c, d);
        }
        inline Error vfmsubps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubps, a, b, c, d);
        }
        inline Error vfmsubps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubps, a, b, c, d);
        }
        inline Error vfmsubps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubps, a, b, c, d);
        }
        inline Error vfmsubsd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubsd, a, b, c, d);
        }
        inline Error vfmsubsd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubsd, a, b, c, d);
        }
        inline Error vfmsubsd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubsd, a, b, c, d);
        }
        inline Error vfmsubss(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubss, a, b, c, d);
        }
        inline Error vfmsubss(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubss, a, b, c, d);
        }
        inline Error vfmsubss(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubss, a, b, c, d);
        }
        inline Error vfmulcph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmulcph, a, b, c, d);
        }
        inline Error vfmulcph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmulcph, a, b, c, d);
        }
        inline Error vfmulcph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmulcph, a, b, c, d);
        }
        inline Error vfmulcph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmulcph, a, b, c, d);
        }
        inline Error vfmulcph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmulcph, a, b, c, d);
        }
        inline Error vfmulcph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmulcph, a, b, c, d);
        }
        inline Error vfmulcsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmulcsh, a, b, c, d);
        }
        inline Error vfmulcsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmulcsh, a, b, c, d);
        }
        inline Error vfnmadd132pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c);
        }
        inline Error vfnmadd132pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c);
        }
        inline Error vfnmadd132pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c);
        }
        inline Error vfnmadd132pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c);
        }
        inline Error vfnmadd132pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c, d);
        }
        inline Error vfnmadd132pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c, d);
        }
        inline Error vfnmadd132pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c, d);
        }
        inline Error vfnmadd132pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c, d);
        }
        inline Error vfnmadd132pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c, d);
        }
        inline Error vfnmadd132pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c, d);
        }
        inline Error vfnmadd132ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ph, a, b, c, d);
        }
        inline Error vfnmadd132ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ph, a, b, c, d);
        }
        inline Error vfnmadd132ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ph, a, b, c, d);
        }
        inline Error vfnmadd132ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ph, a, b, c, d);
        }
        inline Error vfnmadd132ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ph, a, b, c, d);
        }
        inline Error vfnmadd132ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ph, a, b, c, d);
        }
        inline Error vfnmadd132ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c);
        }
        inline Error vfnmadd132ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c);
        }
        inline Error vfnmadd132ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c);
        }
        inline Error vfnmadd132ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c);
        }
        inline Error vfnmadd132ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c, d);
        }
        inline Error vfnmadd132ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c, d);
        }
        inline Error vfnmadd132ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c, d);
        }
        inline Error vfnmadd132ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c, d);
        }
        inline Error vfnmadd132ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c, d);
        }
        inline Error vfnmadd132ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c, d);
        }
        inline Error vfnmadd132sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132sd, a, b, c);
        }
        inline Error vfnmadd132sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132sd, a, b, c);
        }
        inline Error vfnmadd132sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132sd, a, b, c, d);
        }
        inline Error vfnmadd132sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132sd, a, b, c, d);
        }
        inline Error vfnmadd132sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132sh, a, b, c, d);
        }
        inline Error vfnmadd132sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132sh, a, b, c, d);
        }
        inline Error vfnmadd132ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132ss, a, b, c);
        }
        inline Error vfnmadd132ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132ss, a, b, c);
        }
        inline Error vfnmadd132ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ss, a, b, c, d);
        }
        inline Error vfnmadd132ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ss, a, b, c, d);
        }
        inline Error vfnmadd213pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c);
        }
        inline Error vfnmadd213pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c);
        }
        inline Error vfnmadd213pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c);
        }
        inline Error vfnmadd213pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c);
        }
        inline Error vfnmadd213pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c, d);
        }
        inline Error vfnmadd213pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c, d);
        }
        inline Error vfnmadd213pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c, d);
        }
        inline Error vfnmadd213pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c, d);
        }
        inline Error vfnmadd213pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c, d);
        }
        inline Error vfnmadd213pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c, d);
        }
        inline Error vfnmadd213ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ph, a, b, c, d);
        }
        inline Error vfnmadd213ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ph, a, b, c, d);
        }
        inline Error vfnmadd213ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ph, a, b, c, d);
        }
        inline Error vfnmadd213ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ph, a, b, c, d);
        }
        inline Error vfnmadd213ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ph, a, b, c, d);
        }
        inline Error vfnmadd213ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ph, a, b, c, d);
        }
        inline Error vfnmadd213ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c);
        }
        inline Error vfnmadd213ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c);
        }
        inline Error vfnmadd213ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c);
        }
        inline Error vfnmadd213ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c);
        }
        inline Error vfnmadd213ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c, d);
        }
        inline Error vfnmadd213ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c, d);
        }
        inline Error vfnmadd213ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c, d);
        }
        inline Error vfnmadd213ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c, d);
        }
        inline Error vfnmadd213ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c, d);
        }
        inline Error vfnmadd213ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c, d);
        }
        inline Error vfnmadd213sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213sd, a, b, c);
        }
        inline Error vfnmadd213sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213sd, a, b, c);
        }
        inline Error vfnmadd213sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213sd, a, b, c, d);
        }
        inline Error vfnmadd213sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213sd, a, b, c, d);
        }
        inline Error vfnmadd213sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213sh, a, b, c, d);
        }
        inline Error vfnmadd213sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213sh, a, b, c, d);
        }
        inline Error vfnmadd213ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213ss, a, b, c);
        }
        inline Error vfnmadd213ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213ss, a, b, c);
        }
        inline Error vfnmadd213ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ss, a, b, c, d);
        }
        inline Error vfnmadd213ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ss, a, b, c, d);
        }
        inline Error vfnmadd231pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c);
        }
        inline Error vfnmadd231pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c);
        }
        inline Error vfnmadd231pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c);
        }
        inline Error vfnmadd231pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c);
        }
        inline Error vfnmadd231pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c, d);
        }
        inline Error vfnmadd231pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c, d);
        }
        inline Error vfnmadd231pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c, d);
        }
        inline Error vfnmadd231pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c, d);
        }
        inline Error vfnmadd231pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c, d);
        }
        inline Error vfnmadd231pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c, d);
        }
        inline Error vfnmadd231ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ph, a, b, c, d);
        }
        inline Error vfnmadd231ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ph, a, b, c, d);
        }
        inline Error vfnmadd231ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ph, a, b, c, d);
        }
        inline Error vfnmadd231ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ph, a, b, c, d);
        }
        inline Error vfnmadd231ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ph, a, b, c, d);
        }
        inline Error vfnmadd231ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ph, a, b, c, d);
        }
        inline Error vfnmadd231ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c);
        }
        inline Error vfnmadd231ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c);
        }
        inline Error vfnmadd231ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c);
        }
        inline Error vfnmadd231ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c);
        }
        inline Error vfnmadd231ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c, d);
        }
        inline Error vfnmadd231ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c, d);
        }
        inline Error vfnmadd231ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c, d);
        }
        inline Error vfnmadd231ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c, d);
        }
        inline Error vfnmadd231ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c, d);
        }
        inline Error vfnmadd231ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c, d);
        }
        inline Error vfnmadd231sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231sd, a, b, c);
        }
        inline Error vfnmadd231sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231sd, a, b, c);
        }
        inline Error vfnmadd231sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231sd, a, b, c, d);
        }
        inline Error vfnmadd231sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231sd, a, b, c, d);
        }
        inline Error vfnmadd231sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231sh, a, b, c, d);
        }
        inline Error vfnmadd231sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231sh, a, b, c, d);
        }
        inline Error vfnmadd231ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231ss, a, b, c);
        }
        inline Error vfnmadd231ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231ss, a, b, c);
        }
        inline Error vfnmadd231ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ss, a, b, c, d);
        }
        inline Error vfnmadd231ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ss, a, b, c, d);
        }
        inline Error vfnmaddpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddpd, a, b, c, d);
        }
        inline Error vfnmaddpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddpd, a, b, c, d);
        }
        inline Error vfnmaddpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddpd, a, b, c, d);
        }
        inline Error vfnmaddpd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmaddpd, a, b, c, d);
        }
        inline Error vfnmaddpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddpd, a, b, c, d);
        }
        inline Error vfnmaddpd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmaddpd, a, b, c, d);
        }
        inline Error vfnmaddps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddps, a, b, c, d);
        }
        inline Error vfnmaddps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddps, a, b, c, d);
        }
        inline Error vfnmaddps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddps, a, b, c, d);
        }
        inline Error vfnmaddps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmaddps, a, b, c, d);
        }
        inline Error vfnmaddps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddps, a, b, c, d);
        }
        inline Error vfnmaddps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmaddps, a, b, c, d);
        }
        inline Error vfnmaddsd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddsd, a, b, c, d);
        }
        inline Error vfnmaddsd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddsd, a, b, c, d);
        }
        inline Error vfnmaddsd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmaddsd, a, b, c, d);
        }
        inline Error vfnmaddss(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddss, a, b, c, d);
        }
        inline Error vfnmaddss(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddss, a, b, c, d);
        }
        inline Error vfnmaddss(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmaddss, a, b, c, d);
        }
        inline Error vfnmsub132pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c);
        }
        inline Error vfnmsub132pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c);
        }
        inline Error vfnmsub132pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c);
        }
        inline Error vfnmsub132pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c);
        }
        inline Error vfnmsub132pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c, d);
        }
        inline Error vfnmsub132pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c, d);
        }
        inline Error vfnmsub132pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c, d);
        }
        inline Error vfnmsub132pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c, d);
        }
        inline Error vfnmsub132pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c, d);
        }
        inline Error vfnmsub132pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c, d);
        }
        inline Error vfnmsub132ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ph, a, b, c, d);
        }
        inline Error vfnmsub132ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ph, a, b, c, d);
        }
        inline Error vfnmsub132ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ph, a, b, c, d);
        }
        inline Error vfnmsub132ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ph, a, b, c, d);
        }
        inline Error vfnmsub132ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ph, a, b, c, d);
        }
        inline Error vfnmsub132ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ph, a, b, c, d);
        }
        inline Error vfnmsub132ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c);
        }
        inline Error vfnmsub132ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c);
        }
        inline Error vfnmsub132ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c);
        }
        inline Error vfnmsub132ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c);
        }
        inline Error vfnmsub132ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c, d);
        }
        inline Error vfnmsub132ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c, d);
        }
        inline Error vfnmsub132ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c, d);
        }
        inline Error vfnmsub132ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c, d);
        }
        inline Error vfnmsub132ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c, d);
        }
        inline Error vfnmsub132ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c, d);
        }
        inline Error vfnmsub132sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132sd, a, b, c);
        }
        inline Error vfnmsub132sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132sd, a, b, c);
        }
        inline Error vfnmsub132sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132sd, a, b, c, d);
        }
        inline Error vfnmsub132sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132sd, a, b, c, d);
        }
        inline Error vfnmsub132sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132sh, a, b, c, d);
        }
        inline Error vfnmsub132sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132sh, a, b, c, d);
        }
        inline Error vfnmsub132ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132ss, a, b, c);
        }
        inline Error vfnmsub132ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132ss, a, b, c);
        }
        inline Error vfnmsub132ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ss, a, b, c, d);
        }
        inline Error vfnmsub132ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ss, a, b, c, d);
        }
        inline Error vfnmsub213pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c);
        }
        inline Error vfnmsub213pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c);
        }
        inline Error vfnmsub213pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c);
        }
        inline Error vfnmsub213pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c);
        }
        inline Error vfnmsub213pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c, d);
        }
        inline Error vfnmsub213pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c, d);
        }
        inline Error vfnmsub213pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c, d);
        }
        inline Error vfnmsub213pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c, d);
        }
        inline Error vfnmsub213pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c, d);
        }
        inline Error vfnmsub213pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c, d);
        }
        inline Error vfnmsub213ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ph, a, b, c, d);
        }
        inline Error vfnmsub213ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ph, a, b, c, d);
        }
        inline Error vfnmsub213ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ph, a, b, c, d);
        }
        inline Error vfnmsub213ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ph, a, b, c, d);
        }
        inline Error vfnmsub213ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ph, a, b, c, d);
        }
        inline Error vfnmsub213ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ph, a, b, c, d);
        }
        inline Error vfnmsub213ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c);
        }
        inline Error vfnmsub213ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c);
        }
        inline Error vfnmsub213ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c);
        }
        inline Error vfnmsub213ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c);
        }
        inline Error vfnmsub213ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c, d);
        }
        inline Error vfnmsub213ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c, d);
        }
        inline Error vfnmsub213ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c, d);
        }
        inline Error vfnmsub213ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c, d);
        }
        inline Error vfnmsub213ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c, d);
        }
        inline Error vfnmsub213ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c, d);
        }
        inline Error vfnmsub213sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213sd, a, b, c);
        }
        inline Error vfnmsub213sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213sd, a, b, c);
        }
        inline Error vfnmsub213sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213sd, a, b, c, d);
        }
        inline Error vfnmsub213sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213sd, a, b, c, d);
        }
        inline Error vfnmsub213sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213sh, a, b, c, d);
        }
        inline Error vfnmsub213sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213sh, a, b, c, d);
        }
        inline Error vfnmsub213ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213ss, a, b, c);
        }
        inline Error vfnmsub213ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213ss, a, b, c);
        }
        inline Error vfnmsub213ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ss, a, b, c, d);
        }
        inline Error vfnmsub213ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ss, a, b, c, d);
        }
        inline Error vfnmsub231pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c);
        }
        inline Error vfnmsub231pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c);
        }
        inline Error vfnmsub231pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c);
        }
        inline Error vfnmsub231pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c);
        }
        inline Error vfnmsub231pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c, d);
        }
        inline Error vfnmsub231pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c, d);
        }
        inline Error vfnmsub231pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c, d);
        }
        inline Error vfnmsub231pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c, d);
        }
        inline Error vfnmsub231pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c, d);
        }
        inline Error vfnmsub231pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c, d);
        }
        inline Error vfnmsub231ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ph, a, b, c, d);
        }
        inline Error vfnmsub231ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ph, a, b, c, d);
        }
        inline Error vfnmsub231ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ph, a, b, c, d);
        }
        inline Error vfnmsub231ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ph, a, b, c, d);
        }
        inline Error vfnmsub231ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ph, a, b, c, d);
        }
        inline Error vfnmsub231ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ph, a, b, c, d);
        }
        inline Error vfnmsub231ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c);
        }
        inline Error vfnmsub231ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c);
        }
        inline Error vfnmsub231ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c);
        }
        inline Error vfnmsub231ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c);
        }
        inline Error vfnmsub231ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c, d);
        }
        inline Error vfnmsub231ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c, d);
        }
        inline Error vfnmsub231ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c, d);
        }
        inline Error vfnmsub231ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c, d);
        }
        inline Error vfnmsub231ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c, d);
        }
        inline Error vfnmsub231ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c, d);
        }
        inline Error vfnmsub231sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231sd, a, b, c);
        }
        inline Error vfnmsub231sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231sd, a, b, c);
        }
        inline Error vfnmsub231sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231sd, a, b, c, d);
        }
        inline Error vfnmsub231sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231sd, a, b, c, d);
        }
        inline Error vfnmsub231sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231sh, a, b, c, d);
        }
        inline Error vfnmsub231sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231sh, a, b, c, d);
        }
        inline Error vfnmsub231ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231ss, a, b, c);
        }
        inline Error vfnmsub231ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231ss, a, b, c);
        }
        inline Error vfnmsub231ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ss, a, b, c, d);
        }
        inline Error vfnmsub231ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ss, a, b, c, d);
        }
        inline Error vfnmsubpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubpd, a, b, c, d);
        }
        inline Error vfnmsubpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubpd, a, b, c, d);
        }
        inline Error vfnmsubpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubpd, a, b, c, d);
        }
        inline Error vfnmsubpd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsubpd, a, b, c, d);
        }
        inline Error vfnmsubpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubpd, a, b, c, d);
        }
        inline Error vfnmsubpd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsubpd, a, b, c, d);
        }
        inline Error vfnmsubps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubps, a, b, c, d);
        }
        inline Error vfnmsubps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubps, a, b, c, d);
        }
        inline Error vfnmsubps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubps, a, b, c, d);
        }
        inline Error vfnmsubps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsubps, a, b, c, d);
        }
        inline Error vfnmsubps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubps, a, b, c, d);
        }
        inline Error vfnmsubps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsubps, a, b, c, d);
        }
        inline Error vfnmsubsd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubsd, a, b, c, d);
        }
        inline Error vfnmsubsd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubsd, a, b, c, d);
        }
        inline Error vfnmsubsd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsubsd, a, b, c, d);
        }
        inline Error vfnmsubss(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubss, a, b, c, d);
        }
        inline Error vfnmsubss(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubss, a, b, c, d);
        }
        inline Error vfnmsubss(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsubss, a, b, c, d);
        }
        inline Error vfpclasspd(const Mask& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasspd, a, b, c, d);
        }
        inline Error vfpclasspd(const Mask& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasspd, a, b, c, d);
        }
        inline Error vfpclasspd(const Mask& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasspd, a, b, c, d);
        }
        inline Error vfpclasspd(const Mask& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasspd, a, b, c, d);
        }
        inline Error vfpclassph(const Mask& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassph, a, b, c, d);
        }
        inline Error vfpclassph(const Mask& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassph, a, b, c, d);
        }
        inline Error vfpclassph(const Mask& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassph, a, b, c, d);
        }
        inline Error vfpclassph(const Mask& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassph, a, b, c, d);
        }
        inline Error vfpclassps(const Mask& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassps, a, b, c, d);
        }
        inline Error vfpclassps(const Mask& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassps, a, b, c, d);
        }
        inline Error vfpclassps(const Mask& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassps, a, b, c, d);
        }
        inline Error vfpclassps(const Mask& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassps, a, b, c, d);
        }
        inline Error vfpclasssd(const Mask& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasssd, a, b, c, d);
        }
        inline Error vfpclasssd(const Mask& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasssd, a, b, c, d);
        }
        inline Error vfpclasssh(const Mask& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasssh, a, b, c, d);
        }
        inline Error vfpclasssh(const Mask& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasssh, a, b, c, d);
        }
        inline Error vfpclassss(const Mask& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassss, a, b, c, d);
        }
        inline Error vfpclassss(const Mask& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassss, a, b, c, d);
        }
        inline Error vfrczpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vfrczpd, a, b);
        }
        inline Error vfrczpd(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vfrczpd, a, b);
        }
        inline Error vfrczpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vfrczpd, a, b);
        }
        inline Error vfrczpd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vfrczpd, a, b);
        }
        inline Error vfrczps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vfrczps, a, b);
        }
        inline Error vfrczps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vfrczps, a, b);
        }
        inline Error vfrczps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vfrczps, a, b);
        }
        inline Error vfrczps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vfrczps, a, b);
        }
        inline Error vfrczsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vfrczsd, a, b);
        }
        inline Error vfrczsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vfrczsd, a, b);
        }
        inline Error vfrczss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vfrczss, a, b);
        }
        inline Error vfrczss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vfrczss, a, b);
        }
        inline Error vgatherdpd(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgatherdpd, a, b, c);
        }
        inline Error vgatherdpd(const Ymm& a, const Mem& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgatherdpd, a, b, c);
        }
        inline Error vgatherdpd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherdpd, a, b, c);
        }
        inline Error vgatherdpd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherdpd, a, b, c);
        }
        inline Error vgatherdpd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherdpd, a, b, c);
        }
        inline Error vgatherdps(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgatherdps, a, b, c);
        }
        inline Error vgatherdps(const Ymm& a, const Mem& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgatherdps, a, b, c);
        }
        inline Error vgatherdps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherdps, a, b, c);
        }
        inline Error vgatherdps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherdps, a, b, c);
        }
        inline Error vgatherdps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherdps, a, b, c);
        }
        inline Error vgatherpf0dpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf0dpd, a, b);
        }
        inline Error vgatherpf0dps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf0dps, a, b);
        }
        inline Error vgatherpf0hintdpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf0hintdpd, a, b);
        }
        inline Error vgatherpf0hintdps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf0hintdps, a, b);
        }
        inline Error vgatherpf0qpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf0qpd, a, b);
        }
        inline Error vgatherpf0qps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf0qps, a, b);
        }
        inline Error vgatherpf1dpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf1dpd, a, b);
        }
        inline Error vgatherpf1dps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf1dps, a, b);
        }
        inline Error vgatherpf1qpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf1qpd, a, b);
        }
        inline Error vgatherpf1qps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf1qps, a, b);
        }
        inline Error vgatherqpd(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgatherqpd, a, b, c);
        }
        inline Error vgatherqpd(const Ymm& a, const Mem& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgatherqpd, a, b, c);
        }
        inline Error vgatherqpd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherqpd, a, b, c);
        }
        inline Error vgatherqpd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherqpd, a, b, c);
        }
        inline Error vgatherqpd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherqpd, a, b, c);
        }
        inline Error vgatherqps(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgatherqps, a, b, c);
        }
        inline Error vgatherqps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherqps, a, b, c);
        }
        inline Error vgatherqps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherqps, a, b, c);
        }
        inline Error vgetexppd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vgetexppd, a, b, c);
        }
        inline Error vgetexppd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgetexppd, a, b, c);
        }
        inline Error vgetexppd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgetexppd, a, b, c);
        }
        inline Error vgetexppd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexppd, a, b, c);
        }
        inline Error vgetexppd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexppd, a, b, c);
        }
        inline Error vgetexppd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexppd, a, b, c);
        }
        inline Error vgetexpph(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vgetexpph, a, b, c);
        }
        inline Error vgetexpph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgetexpph, a, b, c);
        }
        inline Error vgetexpph(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgetexpph, a, b, c);
        }
        inline Error vgetexpph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexpph, a, b, c);
        }
        inline Error vgetexpph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexpph, a, b, c);
        }
        inline Error vgetexpph(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexpph, a, b, c);
        }
        inline Error vgetexpps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vgetexpps, a, b, c);
        }
        inline Error vgetexpps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgetexpps, a, b, c);
        }
        inline Error vgetexpps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgetexpps, a, b, c);
        }
        inline Error vgetexpps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexpps, a, b, c);
        }
        inline Error vgetexpps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexpps, a, b, c);
        }
        inline Error vgetexpps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexpps, a, b, c);
        }
        inline Error vgetexpsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vgetexpsd, a, b, c, d);
        }
        inline Error vgetexpsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgetexpsd, a, b, c, d);
        }
        inline Error vgetexpsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vgetexpsh, a, b, c, d);
        }
        inline Error vgetexpsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgetexpsh, a, b, c, d);
        }
        inline Error vgetexpss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vgetexpss, a, b, c, d);
        }
        inline Error vgetexpss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgetexpss, a, b, c, d);
        }
        inline Error vgetmantpd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantpd, a, b, c, d);
        }
        inline Error vgetmantpd(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantpd, a, b, c, d);
        }
        inline Error vgetmantpd(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantpd, a, b, c, d);
        }
        inline Error vgetmantpd(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantpd, a, b, c, d);
        }
        inline Error vgetmantpd(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantpd, a, b, c, d);
        }
        inline Error vgetmantpd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantpd, a, b, c, d);
        }
        inline Error vgetmantph(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantph, a, b, c, d);
        }
        inline Error vgetmantph(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantph, a, b, c, d);
        }
        inline Error vgetmantph(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantph, a, b, c, d);
        }
        inline Error vgetmantph(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantph, a, b, c, d);
        }
        inline Error vgetmantph(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantph, a, b, c, d);
        }
        inline Error vgetmantph(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantph, a, b, c, d);
        }
        inline Error vgetmantps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantps, a, b, c, d);
        }
        inline Error vgetmantps(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantps, a, b, c, d);
        }
        inline Error vgetmantps(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantps, a, b, c, d);
        }
        inline Error vgetmantps(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantps, a, b, c, d);
        }
        inline Error vgetmantps(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantps, a, b, c, d);
        }
        inline Error vgetmantps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantps, a, b, c, d);
        }
        inline Error vgetmantsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgetmantsd, a, b, c, d, e);
        }
        inline Error vgetmantsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgetmantsd, a, b, c, d, e);
        }
        inline Error vgetmantsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgetmantsh, a, b, c, d, e);
        }
        inline Error vgetmantsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgetmantsh, a, b, c, d, e);
        }
        inline Error vgetmantss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgetmantss, a, b, c, d, e);
        }
        inline Error vgetmantss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgetmantss, a, b, c, d, e);
        }
        inline Error vgf2p8affineinvqb(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d);
        }
        inline Error vgf2p8affineinvqb(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d);
        }
        inline Error vgf2p8affineinvqb(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d);
        }
        inline Error vgf2p8affineinvqb(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d);
        }
        inline Error vgf2p8affineinvqb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d, e);
        }
        inline Error vgf2p8affineinvqb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d, e);
        }
        inline Error vgf2p8affineinvqb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d, e);
        }
        inline Error vgf2p8affineinvqb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d, e);
        }
        inline Error vgf2p8affineinvqb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d, e);
        }
        inline Error vgf2p8affineinvqb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d, e);
        }
        inline Error vgf2p8affineqb(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d);
        }
        inline Error vgf2p8affineqb(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d);
        }
        inline Error vgf2p8affineqb(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d);
        }
        inline Error vgf2p8affineqb(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d);
        }
        inline Error vgf2p8affineqb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d, e);
        }
        inline Error vgf2p8affineqb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d, e);
        }
        inline Error vgf2p8affineqb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d, e);
        }
        inline Error vgf2p8affineqb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d, e);
        }
        inline Error vgf2p8affineqb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d, e);
        }
        inline Error vgf2p8affineqb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d, e);
        }
        inline Error vgf2p8mulb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c);
        }
        inline Error vgf2p8mulb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c);
        }
        inline Error vgf2p8mulb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c);
        }
        inline Error vgf2p8mulb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c);
        }
        inline Error vgf2p8mulb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c, d);
        }
        inline Error vgf2p8mulb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c, d);
        }
        inline Error vgf2p8mulb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c, d);
        }
        inline Error vgf2p8mulb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c, d);
        }
        inline Error vgf2p8mulb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c, d);
        }
        inline Error vgf2p8mulb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c, d);
        }
        inline Error vgmaxabsps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vgmaxabsps, a, b, c, d);
        }
        inline Error vgmaxabsps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgmaxabsps, a, b, c, d);
        }
        inline Error vgmaxpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vgmaxpd, a, b, c, d);
        }
        inline Error vgmaxpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgmaxpd, a, b, c, d);
        }
        inline Error vgmaxps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vgmaxps, a, b, c, d);
        }
        inline Error vgmaxps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgmaxps, a, b, c, d);
        }
        inline Error vgminpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vgminpd, a, b, c, d);
        }
        inline Error vgminpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgminpd, a, b, c, d);
        }
        inline Error vgminps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vgminps, a, b, c, d);
        }
        inline Error vgminps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgminps, a, b, c, d);
        }
        inline Error vhaddpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vhaddpd, a, b, c);
        }
        inline Error vhaddpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vhaddpd, a, b, c);
        }
        inline Error vhaddpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhaddpd, a, b, c);
        }
        inline Error vhaddpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhaddpd, a, b, c);
        }
        inline Error vhaddps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vhaddps, a, b, c);
        }
        inline Error vhaddps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vhaddps, a, b, c);
        }
        inline Error vhaddps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhaddps, a, b, c);
        }
        inline Error vhaddps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhaddps, a, b, c);
        }
        inline Error vhsubpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vhsubpd, a, b, c);
        }
        inline Error vhsubpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vhsubpd, a, b, c);
        }
        inline Error vhsubpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhsubpd, a, b, c);
        }
        inline Error vhsubpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhsubpd, a, b, c);
        }
        inline Error vhsubps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vhsubps, a, b, c);
        }
        inline Error vhsubps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vhsubps, a, b, c);
        }
        inline Error vhsubps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhsubps, a, b, c);
        }
        inline Error vhsubps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhsubps, a, b, c);
        }
        inline Error vinsertf128(const Ymm& a, const Ymm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vinsertf128, a, b, c, d);
        }
        inline Error vinsertf128(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vinsertf128, a, b, c, d);
        }
        inline Error vinsertf32x4(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf32x4, a, b, c, d, e);
        }
        inline Error vinsertf32x4(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf32x4, a, b, c, d, e);
        }
        inline Error vinsertf32x4(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf32x4, a, b, c, d, e);
        }
        inline Error vinsertf32x4(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf32x4, a, b, c, d, e);
        }
        inline Error vinsertf32x8(const Zmm& a, const Mask& b, const Zmm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf32x8, a, b, c, d, e);
        }
        inline Error vinsertf32x8(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf32x8, a, b, c, d, e);
        }
        inline Error vinsertf64x2(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf64x2, a, b, c, d, e);
        }
        inline Error vinsertf64x2(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf64x2, a, b, c, d, e);
        }
        inline Error vinsertf64x2(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf64x2, a, b, c, d, e);
        }
        inline Error vinsertf64x2(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf64x2, a, b, c, d, e);
        }
        inline Error vinsertf64x4(const Zmm& a, const Mask& b, const Zmm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf64x4, a, b, c, d, e);
        }
        inline Error vinsertf64x4(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf64x4, a, b, c, d, e);
        }
        inline Error vinserti128(const Ymm& a, const Ymm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vinserti128, a, b, c, d);
        }
        inline Error vinserti128(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vinserti128, a, b, c, d);
        }
        inline Error vinserti32x4(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti32x4, a, b, c, d, e);
        }
        inline Error vinserti32x4(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti32x4, a, b, c, d, e);
        }
        inline Error vinserti32x4(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti32x4, a, b, c, d, e);
        }
        inline Error vinserti32x4(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti32x4, a, b, c, d, e);
        }
        inline Error vinserti32x8(const Zmm& a, const Mask& b, const Zmm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti32x8, a, b, c, d, e);
        }
        inline Error vinserti32x8(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti32x8, a, b, c, d, e);
        }
        inline Error vinserti64x2(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti64x2, a, b, c, d, e);
        }
        inline Error vinserti64x2(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti64x2, a, b, c, d, e);
        }
        inline Error vinserti64x2(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti64x2, a, b, c, d, e);
        }
        inline Error vinserti64x2(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti64x2, a, b, c, d, e);
        }
        inline Error vinserti64x4(const Zmm& a, const Mask& b, const Zmm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti64x4, a, b, c, d, e);
        }
        inline Error vinserti64x4(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti64x4, a, b, c, d, e);
        }
        inline Error vinsertps(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vinsertps, a, b, c, d);
        }
        inline Error vinsertps(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vinsertps, a, b, c, d);
        }
        inline Error vlddqu(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vlddqu, a, b);
        }
        inline Error vlddqu(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vlddqu, a, b);
        }
        inline Error vldmxcsr(const Mem& a)
        {
            return emit(x86::Mnemonic::Vldmxcsr, a);
        }
        inline Error vloadunpackhd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpackhd, a, b, c);
        }
        inline Error vloadunpackhpd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpackhpd, a, b, c);
        }
        inline Error vloadunpackhps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpackhps, a, b, c);
        }
        inline Error vloadunpackhq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpackhq, a, b, c);
        }
        inline Error vloadunpackld(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpackld, a, b, c);
        }
        inline Error vloadunpacklpd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpacklpd, a, b, c);
        }
        inline Error vloadunpacklps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpacklps, a, b, c);
        }
        inline Error vloadunpacklq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpacklq, a, b, c);
        }
        inline Error vlog2ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vlog2ps, a, b, c);
        }
        inline Error vlog2ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vlog2ps, a, b, c);
        }
        inline Error vmaskmovdqu(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmaskmovdqu, a, b);
        }
        inline Error vmaskmovpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaskmovpd, a, b, c);
        }
        inline Error vmaskmovpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaskmovpd, a, b, c);
        }
        inline Error vmaskmovpd(const Mem& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmaskmovpd, a, b, c);
        }
        inline Error vmaskmovpd(const Mem& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmaskmovpd, a, b, c);
        }
        inline Error vmaskmovps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaskmovps, a, b, c);
        }
        inline Error vmaskmovps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaskmovps, a, b, c);
        }
        inline Error vmaskmovps(const Mem& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmaskmovps, a, b, c);
        }
        inline Error vmaskmovps(const Mem& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmaskmovps, a, b, c);
        }
        inline Error vmaxpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c);
        }
        inline Error vmaxpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c);
        }
        inline Error vmaxpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c);
        }
        inline Error vmaxpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c);
        }
        inline Error vmaxpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c, d);
        }
        inline Error vmaxpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c, d);
        }
        inline Error vmaxpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c, d);
        }
        inline Error vmaxpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c, d);
        }
        inline Error vmaxpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c, d);
        }
        inline Error vmaxpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c, d);
        }
        inline Error vmaxph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vmaxph, a, b, c, d);
        }
        inline Error vmaxph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmaxph, a, b, c, d);
        }
        inline Error vmaxph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vmaxph, a, b, c, d);
        }
        inline Error vmaxph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxph, a, b, c, d);
        }
        inline Error vmaxph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxph, a, b, c, d);
        }
        inline Error vmaxph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxph, a, b, c, d);
        }
        inline Error vmaxps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c);
        }
        inline Error vmaxps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c);
        }
        inline Error vmaxps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c);
        }
        inline Error vmaxps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c);
        }
        inline Error vmaxps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c, d);
        }
        inline Error vmaxps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c, d);
        }
        inline Error vmaxps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c, d);
        }
        inline Error vmaxps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c, d);
        }
        inline Error vmaxps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c, d);
        }
        inline Error vmaxps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c, d);
        }
        inline Error vmaxsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmaxsd, a, b, c);
        }
        inline Error vmaxsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaxsd, a, b, c);
        }
        inline Error vmaxsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmaxsd, a, b, c, d);
        }
        inline Error vmaxsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxsd, a, b, c, d);
        }
        inline Error vmaxsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmaxsh, a, b, c, d);
        }
        inline Error vmaxsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxsh, a, b, c, d);
        }
        inline Error vmaxss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmaxss, a, b, c);
        }
        inline Error vmaxss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaxss, a, b, c);
        }
        inline Error vmaxss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmaxss, a, b, c, d);
        }
        inline Error vmaxss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxss, a, b, c, d);
        }
        inline Error vmcall()
        {
            return emit(x86::Mnemonic::Vmcall);
        }
        inline Error vmclear(const Mem& a)
        {
            return emit(x86::Mnemonic::Vmclear, a);
        }
        inline Error vmfunc()
        {
            return emit(x86::Mnemonic::Vmfunc);
        }
        inline Error vminpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c);
        }
        inline Error vminpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c);
        }
        inline Error vminpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c);
        }
        inline Error vminpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c);
        }
        inline Error vminpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c, d);
        }
        inline Error vminpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c, d);
        }
        inline Error vminpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c, d);
        }
        inline Error vminpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c, d);
        }
        inline Error vminpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c, d);
        }
        inline Error vminpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c, d);
        }
        inline Error vminph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vminph, a, b, c, d);
        }
        inline Error vminph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vminph, a, b, c, d);
        }
        inline Error vminph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vminph, a, b, c, d);
        }
        inline Error vminph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminph, a, b, c, d);
        }
        inline Error vminph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminph, a, b, c, d);
        }
        inline Error vminph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminph, a, b, c, d);
        }
        inline Error vminps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c);
        }
        inline Error vminps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c);
        }
        inline Error vminps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c);
        }
        inline Error vminps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c);
        }
        inline Error vminps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c, d);
        }
        inline Error vminps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c, d);
        }
        inline Error vminps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c, d);
        }
        inline Error vminps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c, d);
        }
        inline Error vminps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c, d);
        }
        inline Error vminps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c, d);
        }
        inline Error vminsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vminsd, a, b, c);
        }
        inline Error vminsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vminsd, a, b, c);
        }
        inline Error vminsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vminsd, a, b, c, d);
        }
        inline Error vminsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminsd, a, b, c, d);
        }
        inline Error vminsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vminsh, a, b, c, d);
        }
        inline Error vminsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminsh, a, b, c, d);
        }
        inline Error vminss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vminss, a, b, c);
        }
        inline Error vminss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vminss, a, b, c);
        }
        inline Error vminss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vminss, a, b, c, d);
        }
        inline Error vminss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminss, a, b, c, d);
        }
        inline Error vmlaunch()
        {
            return emit(x86::Mnemonic::Vmlaunch);
        }
        inline Error vmload(const Gp& a)
        {
            return emit(x86::Mnemonic::Vmload, a);
        }
        inline Error vmmcall()
        {
            return emit(x86::Mnemonic::Vmmcall);
        }
        inline Error vmovapd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b);
        }
        inline Error vmovapd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b);
        }
        inline Error vmovapd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b);
        }
        inline Error vmovapd(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b);
        }
        inline Error vmovapd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b);
        }
        inline Error vmovapd(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b);
        }
        inline Error vmovapd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        inline Error vmovapd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        inline Error vmovapd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        inline Error vmovapd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        inline Error vmovapd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        inline Error vmovapd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        inline Error vmovapd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        inline Error vmovapd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        inline Error vmovapd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        inline Error vmovaps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b);
        }
        inline Error vmovaps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b);
        }
        inline Error vmovaps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b);
        }
        inline Error vmovaps(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b);
        }
        inline Error vmovaps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b);
        }
        inline Error vmovaps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b);
        }
        inline Error vmovaps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        inline Error vmovaps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        inline Error vmovaps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        inline Error vmovaps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        inline Error vmovaps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        inline Error vmovaps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        inline Error vmovaps(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        inline Error vmovaps(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        inline Error vmovaps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        inline Error vmovd(const Xmm& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Vmovd, a, b);
        }
        inline Error vmovd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovd, a, b);
        }
        inline Error vmovd(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovd, a, b);
        }
        inline Error vmovd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovd, a, b);
        }
        inline Error vmovddup(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b);
        }
        inline Error vmovddup(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b);
        }
        inline Error vmovddup(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b);
        }
        inline Error vmovddup(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b);
        }
        inline Error vmovddup(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b, c);
        }
        inline Error vmovddup(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b, c);
        }
        inline Error vmovddup(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b, c);
        }
        inline Error vmovddup(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b, c);
        }
        inline Error vmovddup(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b, c);
        }
        inline Error vmovddup(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b, c);
        }
        inline Error vmovdqa(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovdqa, a, b);
        }
        inline Error vmovdqa(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovdqa, a, b);
        }
        inline Error vmovdqa(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovdqa, a, b);
        }
        inline Error vmovdqa(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovdqa, a, b);
        }
        inline Error vmovdqa(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovdqa, a, b);
        }
        inline Error vmovdqa(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovdqa, a, b);
        }
        inline Error vmovdqa32(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        inline Error vmovdqa32(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        inline Error vmovdqa32(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        inline Error vmovdqa32(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        inline Error vmovdqa32(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        inline Error vmovdqa32(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        inline Error vmovdqa32(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        inline Error vmovdqa32(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        inline Error vmovdqa32(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        inline Error vmovdqa64(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        inline Error vmovdqa64(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        inline Error vmovdqa64(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        inline Error vmovdqa64(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        inline Error vmovdqa64(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        inline Error vmovdqa64(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        inline Error vmovdqa64(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        inline Error vmovdqa64(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        inline Error vmovdqa64(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        inline Error vmovdqu(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovdqu, a, b);
        }
        inline Error vmovdqu(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovdqu, a, b);
        }
        inline Error vmovdqu(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovdqu, a, b);
        }
        inline Error vmovdqu(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovdqu, a, b);
        }
        inline Error vmovdqu(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovdqu, a, b);
        }
        inline Error vmovdqu(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovdqu, a, b);
        }
        inline Error vmovdqu16(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        inline Error vmovdqu16(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        inline Error vmovdqu16(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        inline Error vmovdqu16(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        inline Error vmovdqu16(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        inline Error vmovdqu16(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        inline Error vmovdqu16(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        inline Error vmovdqu16(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        inline Error vmovdqu16(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        inline Error vmovdqu32(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        inline Error vmovdqu32(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        inline Error vmovdqu32(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        inline Error vmovdqu32(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        inline Error vmovdqu32(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        inline Error vmovdqu32(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        inline Error vmovdqu32(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        inline Error vmovdqu32(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        inline Error vmovdqu32(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        inline Error vmovdqu64(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        inline Error vmovdqu64(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        inline Error vmovdqu64(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        inline Error vmovdqu64(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        inline Error vmovdqu64(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        inline Error vmovdqu64(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        inline Error vmovdqu64(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        inline Error vmovdqu64(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        inline Error vmovdqu64(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        inline Error vmovdqu8(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        inline Error vmovdqu8(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        inline Error vmovdqu8(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        inline Error vmovdqu8(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        inline Error vmovdqu8(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        inline Error vmovdqu8(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        inline Error vmovdqu8(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        inline Error vmovdqu8(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        inline Error vmovdqu8(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        inline Error vmovhlps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovhlps, a, b, c);
        }
        inline Error vmovhpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovhpd, a, b, c);
        }
        inline Error vmovhpd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovhpd, a, b);
        }
        inline Error vmovhps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovhps, a, b, c);
        }
        inline Error vmovhps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovhps, a, b);
        }
        inline Error vmovlhps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovlhps, a, b, c);
        }
        inline Error vmovlpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovlpd, a, b, c);
        }
        inline Error vmovlpd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovlpd, a, b);
        }
        inline Error vmovlps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovlps, a, b, c);
        }
        inline Error vmovlps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovlps, a, b);
        }
        inline Error vmovmskpd(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovmskpd, a, b);
        }
        inline Error vmovmskpd(const Gp32& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovmskpd, a, b);
        }
        inline Error vmovmskps(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovmskps, a, b);
        }
        inline Error vmovmskps(const Gp32& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovmskps, a, b);
        }
        inline Error vmovnrapd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovnrapd, a, b, c);
        }
        inline Error vmovnraps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovnraps, a, b, c);
        }
        inline Error vmovnrngoapd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovnrngoapd, a, b, c);
        }
        inline Error vmovnrngoaps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovnrngoaps, a, b, c);
        }
        inline Error vmovntdq(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovntdq, a, b);
        }
        inline Error vmovntdq(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovntdq, a, b);
        }
        inline Error vmovntdq(const Mem& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vmovntdq, a, b);
        }
        inline Error vmovntdqa(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovntdqa, a, b);
        }
        inline Error vmovntdqa(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovntdqa, a, b);
        }
        inline Error vmovntdqa(const Zmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovntdqa, a, b);
        }
        inline Error vmovntpd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovntpd, a, b);
        }
        inline Error vmovntpd(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovntpd, a, b);
        }
        inline Error vmovntpd(const Mem& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vmovntpd, a, b);
        }
        inline Error vmovntps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovntps, a, b);
        }
        inline Error vmovntps(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovntps, a, b);
        }
        inline Error vmovntps(const Mem& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vmovntps, a, b);
        }
        inline Error vmovq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovq, a, b);
        }
        inline Error vmovq(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovq, a, b);
        }
        inline Error vmovq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovq, a, b);
        }
        inline Error vmovq(const Xmm& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Vmovq, a, b);
        }
        inline Error vmovq(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovq, a, b);
        }
        inline Error vmovsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovsd, a, b);
        }
        inline Error vmovsd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovsd, a, b);
        }
        inline Error vmovsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovsd, a, b, c);
        }
        inline Error vmovsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmovsd, a, b, c, d);
        }
        inline Error vmovsd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovsd, a, b, c);
        }
        inline Error vmovsd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovsd, a, b, c);
        }
        inline Error vmovsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmovsh, a, b, c, d);
        }
        inline Error vmovsh(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovsh, a, b, c);
        }
        inline Error vmovsh(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovsh, a, b, c);
        }
        inline Error vmovshdup(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b);
        }
        inline Error vmovshdup(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b);
        }
        inline Error vmovshdup(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b);
        }
        inline Error vmovshdup(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b);
        }
        inline Error vmovshdup(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b, c);
        }
        inline Error vmovshdup(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b, c);
        }
        inline Error vmovshdup(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b, c);
        }
        inline Error vmovshdup(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b, c);
        }
        inline Error vmovshdup(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b, c);
        }
        inline Error vmovshdup(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b, c);
        }
        inline Error vmovsldup(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b);
        }
        inline Error vmovsldup(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b);
        }
        inline Error vmovsldup(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b);
        }
        inline Error vmovsldup(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b);
        }
        inline Error vmovsldup(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b, c);
        }
        inline Error vmovsldup(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b, c);
        }
        inline Error vmovsldup(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b, c);
        }
        inline Error vmovsldup(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b, c);
        }
        inline Error vmovsldup(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b, c);
        }
        inline Error vmovsldup(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b, c);
        }
        inline Error vmovss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovss, a, b);
        }
        inline Error vmovss(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovss, a, b);
        }
        inline Error vmovss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovss, a, b, c);
        }
        inline Error vmovss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmovss, a, b, c, d);
        }
        inline Error vmovss(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovss, a, b, c);
        }
        inline Error vmovss(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovss, a, b, c);
        }
        inline Error vmovupd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b);
        }
        inline Error vmovupd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b);
        }
        inline Error vmovupd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b);
        }
        inline Error vmovupd(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b);
        }
        inline Error vmovupd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b);
        }
        inline Error vmovupd(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b);
        }
        inline Error vmovupd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        inline Error vmovupd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        inline Error vmovupd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        inline Error vmovupd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        inline Error vmovupd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        inline Error vmovupd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        inline Error vmovupd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        inline Error vmovupd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        inline Error vmovupd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        inline Error vmovups(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovups, a, b);
        }
        inline Error vmovups(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovups, a, b);
        }
        inline Error vmovups(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovups, a, b);
        }
        inline Error vmovups(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovups, a, b);
        }
        inline Error vmovups(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovups, a, b);
        }
        inline Error vmovups(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovups, a, b);
        }
        inline Error vmovups(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        inline Error vmovups(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        inline Error vmovups(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        inline Error vmovups(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        inline Error vmovups(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        inline Error vmovups(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        inline Error vmovups(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        inline Error vmovups(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        inline Error vmovups(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        inline Error vmovw(const Xmm& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Vmovw, a, b);
        }
        inline Error vmovw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovw, a, b);
        }
        inline Error vmovw(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovw, a, b);
        }
        inline Error vmovw(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovw, a, b);
        }
        inline Error vmpsadbw(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vmpsadbw, a, b, c, d);
        }
        inline Error vmpsadbw(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vmpsadbw, a, b, c, d);
        }
        inline Error vmpsadbw(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vmpsadbw, a, b, c, d);
        }
        inline Error vmpsadbw(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vmpsadbw, a, b, c, d);
        }
        inline Error vmptrld(const Mem& a)
        {
            return emit(x86::Mnemonic::Vmptrld, a);
        }
        inline Error vmptrst(const Mem& a)
        {
            return emit(x86::Mnemonic::Vmptrst, a);
        }
        inline Error vmread(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Vmread, a, b);
        }
        inline Error vmread(const Mem& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Vmread, a, b);
        }
        inline Error vmread(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Vmread, a, b);
        }
        inline Error vmread(const Mem& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Vmread, a, b);
        }
        inline Error vmresume()
        {
            return emit(x86::Mnemonic::Vmresume);
        }
        inline Error vmrun(const Gp& a)
        {
            return emit(x86::Mnemonic::Vmrun, a);
        }
        inline Error vmsave(const Gp& a)
        {
            return emit(x86::Mnemonic::Vmsave, a);
        }
        inline Error vmulpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c);
        }
        inline Error vmulpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c);
        }
        inline Error vmulpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c);
        }
        inline Error vmulpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c);
        }
        inline Error vmulpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c, d);
        }
        inline Error vmulpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c, d);
        }
        inline Error vmulpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c, d);
        }
        inline Error vmulpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c, d);
        }
        inline Error vmulpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c, d);
        }
        inline Error vmulpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c, d);
        }
        inline Error vmulph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vmulph, a, b, c, d);
        }
        inline Error vmulph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmulph, a, b, c, d);
        }
        inline Error vmulph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vmulph, a, b, c, d);
        }
        inline Error vmulph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulph, a, b, c, d);
        }
        inline Error vmulph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulph, a, b, c, d);
        }
        inline Error vmulph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulph, a, b, c, d);
        }
        inline Error vmulps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c);
        }
        inline Error vmulps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c);
        }
        inline Error vmulps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c);
        }
        inline Error vmulps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c);
        }
        inline Error vmulps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c, d);
        }
        inline Error vmulps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c, d);
        }
        inline Error vmulps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c, d);
        }
        inline Error vmulps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c, d);
        }
        inline Error vmulps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c, d);
        }
        inline Error vmulps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c, d);
        }
        inline Error vmulsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmulsd, a, b, c);
        }
        inline Error vmulsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmulsd, a, b, c);
        }
        inline Error vmulsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmulsd, a, b, c, d);
        }
        inline Error vmulsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulsd, a, b, c, d);
        }
        inline Error vmulsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmulsh, a, b, c, d);
        }
        inline Error vmulsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulsh, a, b, c, d);
        }
        inline Error vmulss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmulss, a, b, c);
        }
        inline Error vmulss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmulss, a, b, c);
        }
        inline Error vmulss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmulss, a, b, c, d);
        }
        inline Error vmulss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulss, a, b, c, d);
        }
        inline Error vmwrite(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Vmwrite, a, b);
        }
        inline Error vmwrite(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmwrite, a, b);
        }
        inline Error vmwrite(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Vmwrite, a, b);
        }
        inline Error vmwrite(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmwrite, a, b);
        }
        inline Error vmxoff()
        {
            return emit(x86::Mnemonic::Vmxoff);
        }
        inline Error vmxon(const Mem& a)
        {
            return emit(x86::Mnemonic::Vmxon, a);
        }
        inline Error vorpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c);
        }
        inline Error vorpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c);
        }
        inline Error vorpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c);
        }
        inline Error vorpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c);
        }
        inline Error vorpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c, d);
        }
        inline Error vorpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c, d);
        }
        inline Error vorpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c, d);
        }
        inline Error vorpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c, d);
        }
        inline Error vorpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c, d);
        }
        inline Error vorpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c, d);
        }
        inline Error vorps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c);
        }
        inline Error vorps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c);
        }
        inline Error vorps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c);
        }
        inline Error vorps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c);
        }
        inline Error vorps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c, d);
        }
        inline Error vorps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c, d);
        }
        inline Error vorps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c, d);
        }
        inline Error vorps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c, d);
        }
        inline Error vorps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c, d);
        }
        inline Error vorps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c, d);
        }
        inline Error vp2intersectd(const Mask& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vp2intersectd, a, b, c);
        }
        inline Error vp2intersectd(const Mask& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vp2intersectd, a, b, c);
        }
        inline Error vp2intersectd(const Mask& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vp2intersectd, a, b, c);
        }
        inline Error vp2intersectd(const Mask& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vp2intersectd, a, b, c);
        }
        inline Error vp2intersectd(const Mask& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vp2intersectd, a, b, c);
        }
        inline Error vp2intersectd(const Mask& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vp2intersectd, a, b, c);
        }
        inline Error vp2intersectq(const Mask& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vp2intersectq, a, b, c);
        }
        inline Error vp2intersectq(const Mask& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vp2intersectq, a, b, c);
        }
        inline Error vp2intersectq(const Mask& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vp2intersectq, a, b, c);
        }
        inline Error vp2intersectq(const Mask& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vp2intersectq, a, b, c);
        }
        inline Error vp2intersectq(const Mask& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vp2intersectq, a, b, c);
        }
        inline Error vp2intersectq(const Mask& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vp2intersectq, a, b, c);
        }
        inline Error vp4dpwssd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vp4dpwssd, a, b, c, d);
        }
        inline Error vp4dpwssds(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vp4dpwssds, a, b, c, d);
        }
        inline Error vpabsb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b);
        }
        inline Error vpabsb(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b);
        }
        inline Error vpabsb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b);
        }
        inline Error vpabsb(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b);
        }
        inline Error vpabsb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b, c);
        }
        inline Error vpabsb(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b, c);
        }
        inline Error vpabsb(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b, c);
        }
        inline Error vpabsb(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b, c);
        }
        inline Error vpabsb(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b, c);
        }
        inline Error vpabsb(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b, c);
        }
        inline Error vpabsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b);
        }
        inline Error vpabsd(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b);
        }
        inline Error vpabsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b);
        }
        inline Error vpabsd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b);
        }
        inline Error vpabsd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b, c);
        }
        inline Error vpabsd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b, c);
        }
        inline Error vpabsd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b, c);
        }
        inline Error vpabsd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b, c);
        }
        inline Error vpabsd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b, c);
        }
        inline Error vpabsd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b, c);
        }
        inline Error vpabsq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpabsq, a, b, c);
        }
        inline Error vpabsq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpabsq, a, b, c);
        }
        inline Error vpabsq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpabsq, a, b, c);
        }
        inline Error vpabsq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsq, a, b, c);
        }
        inline Error vpabsq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsq, a, b, c);
        }
        inline Error vpabsq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsq, a, b, c);
        }
        inline Error vpabsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b);
        }
        inline Error vpabsw(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b);
        }
        inline Error vpabsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b);
        }
        inline Error vpabsw(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b);
        }
        inline Error vpabsw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b, c);
        }
        inline Error vpabsw(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b, c);
        }
        inline Error vpabsw(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b, c);
        }
        inline Error vpabsw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b, c);
        }
        inline Error vpabsw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b, c);
        }
        inline Error vpabsw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b, c);
        }
        inline Error vpackssdw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c);
        }
        inline Error vpackssdw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c);
        }
        inline Error vpackssdw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c);
        }
        inline Error vpackssdw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c);
        }
        inline Error vpackssdw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c, d);
        }
        inline Error vpackssdw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c, d);
        }
        inline Error vpackssdw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c, d);
        }
        inline Error vpackssdw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c, d);
        }
        inline Error vpackssdw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c, d);
        }
        inline Error vpackssdw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c, d);
        }
        inline Error vpacksswb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c);
        }
        inline Error vpacksswb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c);
        }
        inline Error vpacksswb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c);
        }
        inline Error vpacksswb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c);
        }
        inline Error vpacksswb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c, d);
        }
        inline Error vpacksswb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c, d);
        }
        inline Error vpacksswb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c, d);
        }
        inline Error vpacksswb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c, d);
        }
        inline Error vpacksswb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c, d);
        }
        inline Error vpacksswb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c, d);
        }
        inline Error vpackstorehd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorehd, a, b, c);
        }
        inline Error vpackstorehpd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorehpd, a, b, c);
        }
        inline Error vpackstorehps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorehps, a, b, c);
        }
        inline Error vpackstorehq(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorehq, a, b, c);
        }
        inline Error vpackstoreld(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstoreld, a, b, c);
        }
        inline Error vpackstorelpd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorelpd, a, b, c);
        }
        inline Error vpackstorelps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorelps, a, b, c);
        }
        inline Error vpackstorelq(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorelq, a, b, c);
        }
        inline Error vpackusdw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c);
        }
        inline Error vpackusdw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c);
        }
        inline Error vpackusdw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c);
        }
        inline Error vpackusdw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c);
        }
        inline Error vpackusdw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c, d);
        }
        inline Error vpackusdw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c, d);
        }
        inline Error vpackusdw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c, d);
        }
        inline Error vpackusdw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c, d);
        }
        inline Error vpackusdw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c, d);
        }
        inline Error vpackusdw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c, d);
        }
        inline Error vpackuswb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c);
        }
        inline Error vpackuswb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c);
        }
        inline Error vpackuswb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c);
        }
        inline Error vpackuswb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c);
        }
        inline Error vpackuswb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c, d);
        }
        inline Error vpackuswb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c, d);
        }
        inline Error vpackuswb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c, d);
        }
        inline Error vpackuswb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c, d);
        }
        inline Error vpackuswb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c, d);
        }
        inline Error vpackuswb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c, d);
        }
        inline Error vpadcd(const Zmm& a, const Mask& b, const Mask& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpadcd, a, b, c, d);
        }
        inline Error vpadcd(const Zmm& a, const Mask& b, const Mask& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpadcd, a, b, c, d);
        }
        inline Error vpaddb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c);
        }
        inline Error vpaddb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c);
        }
        inline Error vpaddb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c);
        }
        inline Error vpaddb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c);
        }
        inline Error vpaddb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c, d);
        }
        inline Error vpaddb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c, d);
        }
        inline Error vpaddb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c, d);
        }
        inline Error vpaddb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c, d);
        }
        inline Error vpaddb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c, d);
        }
        inline Error vpaddb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c, d);
        }
        inline Error vpaddd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c);
        }
        inline Error vpaddd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c);
        }
        inline Error vpaddd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c);
        }
        inline Error vpaddd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c);
        }
        inline Error vpaddd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c, d);
        }
        inline Error vpaddd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c, d);
        }
        inline Error vpaddd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c, d);
        }
        inline Error vpaddd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c, d);
        }
        inline Error vpaddd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c, d);
        }
        inline Error vpaddd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c, d);
        }
        inline Error vpaddq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c);
        }
        inline Error vpaddq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c);
        }
        inline Error vpaddq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c);
        }
        inline Error vpaddq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c);
        }
        inline Error vpaddq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c, d);
        }
        inline Error vpaddq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c, d);
        }
        inline Error vpaddq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c, d);
        }
        inline Error vpaddq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c, d);
        }
        inline Error vpaddq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c, d);
        }
        inline Error vpaddq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c, d);
        }
        inline Error vpaddsb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c);
        }
        inline Error vpaddsb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c);
        }
        inline Error vpaddsb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c);
        }
        inline Error vpaddsb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c);
        }
        inline Error vpaddsb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c, d);
        }
        inline Error vpaddsb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c, d);
        }
        inline Error vpaddsb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c, d);
        }
        inline Error vpaddsb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c, d);
        }
        inline Error vpaddsb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c, d);
        }
        inline Error vpaddsb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c, d);
        }
        inline Error vpaddsetcd(const Zmm& a, const Mask& b, const Mask& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddsetcd, a, b, c, d);
        }
        inline Error vpaddsetcd(const Zmm& a, const Mask& b, const Mask& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsetcd, a, b, c, d);
        }
        inline Error vpaddsetsd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddsetsd, a, b, c, d);
        }
        inline Error vpaddsetsd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsetsd, a, b, c, d);
        }
        inline Error vpaddsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c);
        }
        inline Error vpaddsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c);
        }
        inline Error vpaddsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c);
        }
        inline Error vpaddsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c);
        }
        inline Error vpaddsw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c, d);
        }
        inline Error vpaddsw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c, d);
        }
        inline Error vpaddsw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c, d);
        }
        inline Error vpaddsw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c, d);
        }
        inline Error vpaddsw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c, d);
        }
        inline Error vpaddsw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c, d);
        }
        inline Error vpaddusb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c);
        }
        inline Error vpaddusb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c);
        }
        inline Error vpaddusb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c);
        }
        inline Error vpaddusb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c);
        }
        inline Error vpaddusb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c, d);
        }
        inline Error vpaddusb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c, d);
        }
        inline Error vpaddusb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c, d);
        }
        inline Error vpaddusb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c, d);
        }
        inline Error vpaddusb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c, d);
        }
        inline Error vpaddusb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c, d);
        }
        inline Error vpaddusw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c);
        }
        inline Error vpaddusw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c);
        }
        inline Error vpaddusw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c);
        }
        inline Error vpaddusw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c);
        }
        inline Error vpaddusw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c, d);
        }
        inline Error vpaddusw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c, d);
        }
        inline Error vpaddusw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c, d);
        }
        inline Error vpaddusw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c, d);
        }
        inline Error vpaddusw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c, d);
        }
        inline Error vpaddusw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c, d);
        }
        inline Error vpaddw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c);
        }
        inline Error vpaddw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c);
        }
        inline Error vpaddw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c);
        }
        inline Error vpaddw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c);
        }
        inline Error vpaddw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c, d);
        }
        inline Error vpaddw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c, d);
        }
        inline Error vpaddw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c, d);
        }
        inline Error vpaddw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c, d);
        }
        inline Error vpaddw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c, d);
        }
        inline Error vpaddw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c, d);
        }
        inline Error vpalignr(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d);
        }
        inline Error vpalignr(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d);
        }
        inline Error vpalignr(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d);
        }
        inline Error vpalignr(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d);
        }
        inline Error vpalignr(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d, e);
        }
        inline Error vpalignr(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d, e);
        }
        inline Error vpalignr(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d, e);
        }
        inline Error vpalignr(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d, e);
        }
        inline Error vpalignr(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d, e);
        }
        inline Error vpalignr(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d, e);
        }
        inline Error vpand(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpand, a, b, c);
        }
        inline Error vpand(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpand, a, b, c);
        }
        inline Error vpand(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpand, a, b, c);
        }
        inline Error vpand(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpand, a, b, c);
        }
        inline Error vpandd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpandd, a, b, c, d);
        }
        inline Error vpandd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpandd, a, b, c, d);
        }
        inline Error vpandd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpandd, a, b, c, d);
        }
        inline Error vpandd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandd, a, b, c, d);
        }
        inline Error vpandd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandd, a, b, c, d);
        }
        inline Error vpandd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandd, a, b, c, d);
        }
        inline Error vpandn(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpandn, a, b, c);
        }
        inline Error vpandn(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpandn, a, b, c);
        }
        inline Error vpandn(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpandn, a, b, c);
        }
        inline Error vpandn(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpandn, a, b, c);
        }
        inline Error vpandnd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpandnd, a, b, c, d);
        }
        inline Error vpandnd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpandnd, a, b, c, d);
        }
        inline Error vpandnd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpandnd, a, b, c, d);
        }
        inline Error vpandnd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandnd, a, b, c, d);
        }
        inline Error vpandnd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandnd, a, b, c, d);
        }
        inline Error vpandnd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandnd, a, b, c, d);
        }
        inline Error vpandnq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpandnq, a, b, c, d);
        }
        inline Error vpandnq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpandnq, a, b, c, d);
        }
        inline Error vpandnq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpandnq, a, b, c, d);
        }
        inline Error vpandnq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandnq, a, b, c, d);
        }
        inline Error vpandnq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandnq, a, b, c, d);
        }
        inline Error vpandnq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandnq, a, b, c, d);
        }
        inline Error vpandq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpandq, a, b, c, d);
        }
        inline Error vpandq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpandq, a, b, c, d);
        }
        inline Error vpandq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpandq, a, b, c, d);
        }
        inline Error vpandq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandq, a, b, c, d);
        }
        inline Error vpandq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandq, a, b, c, d);
        }
        inline Error vpandq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandq, a, b, c, d);
        }
        inline Error vpavgb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c);
        }
        inline Error vpavgb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c);
        }
        inline Error vpavgb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c);
        }
        inline Error vpavgb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c);
        }
        inline Error vpavgb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c, d);
        }
        inline Error vpavgb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c, d);
        }
        inline Error vpavgb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c, d);
        }
        inline Error vpavgb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c, d);
        }
        inline Error vpavgb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c, d);
        }
        inline Error vpavgb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c, d);
        }
        inline Error vpavgw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c);
        }
        inline Error vpavgw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c);
        }
        inline Error vpavgw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c);
        }
        inline Error vpavgw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c);
        }
        inline Error vpavgw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c, d);
        }
        inline Error vpavgw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c, d);
        }
        inline Error vpavgw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c, d);
        }
        inline Error vpavgw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c, d);
        }
        inline Error vpavgw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c, d);
        }
        inline Error vpavgw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c, d);
        }
        inline Error vpblendd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendd, a, b, c, d);
        }
        inline Error vpblendd(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendd, a, b, c, d);
        }
        inline Error vpblendd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendd, a, b, c, d);
        }
        inline Error vpblendd(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendd, a, b, c, d);
        }
        inline Error vpblendmb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmb, a, b, c, d);
        }
        inline Error vpblendmb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpblendmb, a, b, c, d);
        }
        inline Error vpblendmb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmb, a, b, c, d);
        }
        inline Error vpblendmb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmb, a, b, c, d);
        }
        inline Error vpblendmb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmb, a, b, c, d);
        }
        inline Error vpblendmb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmb, a, b, c, d);
        }
        inline Error vpblendmd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmd, a, b, c, d);
        }
        inline Error vpblendmd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpblendmd, a, b, c, d);
        }
        inline Error vpblendmd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmd, a, b, c, d);
        }
        inline Error vpblendmd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmd, a, b, c, d);
        }
        inline Error vpblendmd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmd, a, b, c, d);
        }
        inline Error vpblendmd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmd, a, b, c, d);
        }
        inline Error vpblendmq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmq, a, b, c, d);
        }
        inline Error vpblendmq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpblendmq, a, b, c, d);
        }
        inline Error vpblendmq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmq, a, b, c, d);
        }
        inline Error vpblendmq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmq, a, b, c, d);
        }
        inline Error vpblendmq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmq, a, b, c, d);
        }
        inline Error vpblendmq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmq, a, b, c, d);
        }
        inline Error vpblendmw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmw, a, b, c, d);
        }
        inline Error vpblendmw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpblendmw, a, b, c, d);
        }
        inline Error vpblendmw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmw, a, b, c, d);
        }
        inline Error vpblendmw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmw, a, b, c, d);
        }
        inline Error vpblendmw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmw, a, b, c, d);
        }
        inline Error vpblendmw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmw, a, b, c, d);
        }
        inline Error vpblendvb(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpblendvb, a, b, c, d);
        }
        inline Error vpblendvb(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpblendvb, a, b, c, d);
        }
        inline Error vpblendvb(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpblendvb, a, b, c, d);
        }
        inline Error vpblendvb(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpblendvb, a, b, c, d);
        }
        inline Error vpblendw(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendw, a, b, c, d);
        }
        inline Error vpblendw(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendw, a, b, c, d);
        }
        inline Error vpblendw(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendw, a, b, c, d);
        }
        inline Error vpblendw(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendw, a, b, c, d);
        }
        inline Error vpbroadcastb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b);
        }
        inline Error vpbroadcastb(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b);
        }
        inline Error vpbroadcastb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b);
        }
        inline Error vpbroadcastb(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b);
        }
        inline Error vpbroadcastb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        inline Error vpbroadcastb(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        inline Error vpbroadcastb(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        inline Error vpbroadcastb(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        inline Error vpbroadcastb(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        inline Error vpbroadcastb(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        inline Error vpbroadcastb(const Xmm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        inline Error vpbroadcastb(const Ymm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        inline Error vpbroadcastb(const Zmm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        inline Error vpbroadcastd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b);
        }
        inline Error vpbroadcastd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b);
        }
        inline Error vpbroadcastd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b);
        }
        inline Error vpbroadcastd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b);
        }
        inline Error vpbroadcastd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        inline Error vpbroadcastd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        inline Error vpbroadcastd(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        inline Error vpbroadcastd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        inline Error vpbroadcastd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        inline Error vpbroadcastd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        inline Error vpbroadcastd(const Xmm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        inline Error vpbroadcastd(const Ymm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        inline Error vpbroadcastd(const Zmm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        inline Error vpbroadcastmb2q(const Xmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastmb2q, a, b);
        }
        inline Error vpbroadcastmb2q(const Ymm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastmb2q, a, b);
        }
        inline Error vpbroadcastmb2q(const Zmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastmb2q, a, b);
        }
        inline Error vpbroadcastmw2d(const Xmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastmw2d, a, b);
        }
        inline Error vpbroadcastmw2d(const Ymm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastmw2d, a, b);
        }
        inline Error vpbroadcastmw2d(const Zmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastmw2d, a, b);
        }
        inline Error vpbroadcastq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b);
        }
        inline Error vpbroadcastq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b);
        }
        inline Error vpbroadcastq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b);
        }
        inline Error vpbroadcastq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b);
        }
        inline Error vpbroadcastq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        inline Error vpbroadcastq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        inline Error vpbroadcastq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        inline Error vpbroadcastq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        inline Error vpbroadcastq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        inline Error vpbroadcastq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        inline Error vpbroadcastq(const Xmm& a, const Mask& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        inline Error vpbroadcastq(const Ymm& a, const Mask& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        inline Error vpbroadcastq(const Zmm& a, const Mask& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        inline Error vpbroadcastw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b);
        }
        inline Error vpbroadcastw(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b);
        }
        inline Error vpbroadcastw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b);
        }
        inline Error vpbroadcastw(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b);
        }
        inline Error vpbroadcastw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        inline Error vpbroadcastw(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        inline Error vpbroadcastw(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        inline Error vpbroadcastw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        inline Error vpbroadcastw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        inline Error vpbroadcastw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        inline Error vpbroadcastw(const Xmm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        inline Error vpbroadcastw(const Ymm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        inline Error vpbroadcastw(const Zmm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        inline Error vpclmulqdq(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpclmulqdq, a, b, c, d);
        }
        inline Error vpclmulqdq(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpclmulqdq, a, b, c, d);
        }
        inline Error vpclmulqdq(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpclmulqdq, a, b, c, d);
        }
        inline Error vpclmulqdq(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpclmulqdq, a, b, c, d);
        }
        inline Error vpclmulqdq(const Zmm& a, const Zmm& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpclmulqdq, a, b, c, d);
        }
        inline Error vpclmulqdq(const Zmm& a, const Zmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpclmulqdq, a, b, c, d);
        }
        inline Error vpcmov(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmov, a, b, c, d);
        }
        inline Error vpcmov(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmov, a, b, c, d);
        }
        inline Error vpcmov(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmov, a, b, c, d);
        }
        inline Error vpcmov(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmov, a, b, c, d);
        }
        inline Error vpcmov(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmov, a, b, c, d);
        }
        inline Error vpcmov(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmov, a, b, c, d);
        }
        inline Error vpcmpb(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpb, a, b, c, d, e);
        }
        inline Error vpcmpb(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpb, a, b, c, d, e);
        }
        inline Error vpcmpb(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpb, a, b, c, d, e);
        }
        inline Error vpcmpb(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpb, a, b, c, d, e);
        }
        inline Error vpcmpb(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpb, a, b, c, d, e);
        }
        inline Error vpcmpb(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpb, a, b, c, d, e);
        }
        inline Error vpcmpd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpd, a, b, c, d, e);
        }
        inline Error vpcmpd(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpd, a, b, c, d, e);
        }
        inline Error vpcmpd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpd, a, b, c, d, e);
        }
        inline Error vpcmpd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpd, a, b, c, d, e);
        }
        inline Error vpcmpd(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpd, a, b, c, d, e);
        }
        inline Error vpcmpd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpd, a, b, c, d, e);
        }
        inline Error vpcmpeqb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c);
        }
        inline Error vpcmpeqb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c);
        }
        inline Error vpcmpeqb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c);
        }
        inline Error vpcmpeqb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c);
        }
        inline Error vpcmpeqb(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c, d);
        }
        inline Error vpcmpeqb(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c, d);
        }
        inline Error vpcmpeqb(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c, d);
        }
        inline Error vpcmpeqb(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c, d);
        }
        inline Error vpcmpeqb(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c, d);
        }
        inline Error vpcmpeqb(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c, d);
        }
        inline Error vpcmpeqd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c);
        }
        inline Error vpcmpeqd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c);
        }
        inline Error vpcmpeqd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c);
        }
        inline Error vpcmpeqd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c);
        }
        inline Error vpcmpeqd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c, d);
        }
        inline Error vpcmpeqd(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c, d);
        }
        inline Error vpcmpeqd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c, d);
        }
        inline Error vpcmpeqd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c, d);
        }
        inline Error vpcmpeqd(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c, d);
        }
        inline Error vpcmpeqd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c, d);
        }
        inline Error vpcmpeqq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c);
        }
        inline Error vpcmpeqq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c);
        }
        inline Error vpcmpeqq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c);
        }
        inline Error vpcmpeqq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c);
        }
        inline Error vpcmpeqq(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c, d);
        }
        inline Error vpcmpeqq(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c, d);
        }
        inline Error vpcmpeqq(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c, d);
        }
        inline Error vpcmpeqq(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c, d);
        }
        inline Error vpcmpeqq(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c, d);
        }
        inline Error vpcmpeqq(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c, d);
        }
        inline Error vpcmpeqw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c);
        }
        inline Error vpcmpeqw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c);
        }
        inline Error vpcmpeqw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c);
        }
        inline Error vpcmpeqw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c);
        }
        inline Error vpcmpeqw(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c, d);
        }
        inline Error vpcmpeqw(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c, d);
        }
        inline Error vpcmpeqw(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c, d);
        }
        inline Error vpcmpeqw(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c, d);
        }
        inline Error vpcmpeqw(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c, d);
        }
        inline Error vpcmpeqw(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c, d);
        }
        inline Error vpcmpestri(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpestri, a, b, c);
        }
        inline Error vpcmpestri(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpestri, a, b, c);
        }
        inline Error vpcmpestrm(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpestrm, a, b, c);
        }
        inline Error vpcmpestrm(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpestrm, a, b, c);
        }
        inline Error vpcmpgtb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c);
        }
        inline Error vpcmpgtb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c);
        }
        inline Error vpcmpgtb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c);
        }
        inline Error vpcmpgtb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c);
        }
        inline Error vpcmpgtb(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c, d);
        }
        inline Error vpcmpgtb(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c, d);
        }
        inline Error vpcmpgtb(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c, d);
        }
        inline Error vpcmpgtb(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c, d);
        }
        inline Error vpcmpgtb(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c, d);
        }
        inline Error vpcmpgtb(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c, d);
        }
        inline Error vpcmpgtd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c);
        }
        inline Error vpcmpgtd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c);
        }
        inline Error vpcmpgtd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c);
        }
        inline Error vpcmpgtd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c);
        }
        inline Error vpcmpgtd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c, d);
        }
        inline Error vpcmpgtd(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c, d);
        }
        inline Error vpcmpgtd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c, d);
        }
        inline Error vpcmpgtd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c, d);
        }
        inline Error vpcmpgtd(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c, d);
        }
        inline Error vpcmpgtd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c, d);
        }
        inline Error vpcmpgtq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c);
        }
        inline Error vpcmpgtq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c);
        }
        inline Error vpcmpgtq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c);
        }
        inline Error vpcmpgtq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c);
        }
        inline Error vpcmpgtq(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c, d);
        }
        inline Error vpcmpgtq(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c, d);
        }
        inline Error vpcmpgtq(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c, d);
        }
        inline Error vpcmpgtq(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c, d);
        }
        inline Error vpcmpgtq(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c, d);
        }
        inline Error vpcmpgtq(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c, d);
        }
        inline Error vpcmpgtw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c);
        }
        inline Error vpcmpgtw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c);
        }
        inline Error vpcmpgtw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c);
        }
        inline Error vpcmpgtw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c);
        }
        inline Error vpcmpgtw(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c, d);
        }
        inline Error vpcmpgtw(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c, d);
        }
        inline Error vpcmpgtw(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c, d);
        }
        inline Error vpcmpgtw(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c, d);
        }
        inline Error vpcmpgtw(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c, d);
        }
        inline Error vpcmpgtw(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c, d);
        }
        inline Error vpcmpistri(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpistri, a, b, c);
        }
        inline Error vpcmpistri(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpistri, a, b, c);
        }
        inline Error vpcmpistrm(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpistrm, a, b, c);
        }
        inline Error vpcmpistrm(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpistrm, a, b, c);
        }
        inline Error vpcmpltd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpltd, a, b, c, d);
        }
        inline Error vpcmpltd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpltd, a, b, c, d);
        }
        inline Error vpcmpq(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpq, a, b, c, d, e);
        }
        inline Error vpcmpq(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpq, a, b, c, d, e);
        }
        inline Error vpcmpq(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpq, a, b, c, d, e);
        }
        inline Error vpcmpq(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpq, a, b, c, d, e);
        }
        inline Error vpcmpq(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpq, a, b, c, d, e);
        }
        inline Error vpcmpq(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpq, a, b, c, d, e);
        }
        inline Error vpcmpub(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpub, a, b, c, d, e);
        }
        inline Error vpcmpub(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpub, a, b, c, d, e);
        }
        inline Error vpcmpub(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpub, a, b, c, d, e);
        }
        inline Error vpcmpub(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpub, a, b, c, d, e);
        }
        inline Error vpcmpub(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpub, a, b, c, d, e);
        }
        inline Error vpcmpub(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpub, a, b, c, d, e);
        }
        inline Error vpcmpud(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpud, a, b, c, d, e);
        }
        inline Error vpcmpud(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpud, a, b, c, d, e);
        }
        inline Error vpcmpud(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpud, a, b, c, d, e);
        }
        inline Error vpcmpud(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpud, a, b, c, d, e);
        }
        inline Error vpcmpud(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpud, a, b, c, d, e);
        }
        inline Error vpcmpud(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpud, a, b, c, d, e);
        }
        inline Error vpcmpuq(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuq, a, b, c, d, e);
        }
        inline Error vpcmpuq(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuq, a, b, c, d, e);
        }
        inline Error vpcmpuq(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuq, a, b, c, d, e);
        }
        inline Error vpcmpuq(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuq, a, b, c, d, e);
        }
        inline Error vpcmpuq(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuq, a, b, c, d, e);
        }
        inline Error vpcmpuq(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuq, a, b, c, d, e);
        }
        inline Error vpcmpuw(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuw, a, b, c, d, e);
        }
        inline Error vpcmpuw(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuw, a, b, c, d, e);
        }
        inline Error vpcmpuw(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuw, a, b, c, d, e);
        }
        inline Error vpcmpuw(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuw, a, b, c, d, e);
        }
        inline Error vpcmpuw(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuw, a, b, c, d, e);
        }
        inline Error vpcmpuw(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuw, a, b, c, d, e);
        }
        inline Error vpcmpw(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpw, a, b, c, d, e);
        }
        inline Error vpcmpw(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpw, a, b, c, d, e);
        }
        inline Error vpcmpw(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpw, a, b, c, d, e);
        }
        inline Error vpcmpw(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpw, a, b, c, d, e);
        }
        inline Error vpcmpw(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpw, a, b, c, d, e);
        }
        inline Error vpcmpw(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpw, a, b, c, d, e);
        }
        inline Error vpcomb(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomb, a, b, c, d);
        }
        inline Error vpcomb(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomb, a, b, c, d);
        }
        inline Error vpcomd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomd, a, b, c, d);
        }
        inline Error vpcomd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomd, a, b, c, d);
        }
        inline Error vpcompressb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressb, a, b, c);
        }
        inline Error vpcompressb(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressb, a, b, c);
        }
        inline Error vpcompressb(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressb, a, b, c);
        }
        inline Error vpcompressb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressb, a, b, c);
        }
        inline Error vpcompressb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressb, a, b, c);
        }
        inline Error vpcompressb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressb, a, b, c);
        }
        inline Error vpcompressd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressd, a, b, c);
        }
        inline Error vpcompressd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressd, a, b, c);
        }
        inline Error vpcompressd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressd, a, b, c);
        }
        inline Error vpcompressd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressd, a, b, c);
        }
        inline Error vpcompressd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressd, a, b, c);
        }
        inline Error vpcompressd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressd, a, b, c);
        }
        inline Error vpcompressq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressq, a, b, c);
        }
        inline Error vpcompressq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressq, a, b, c);
        }
        inline Error vpcompressq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressq, a, b, c);
        }
        inline Error vpcompressq(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressq, a, b, c);
        }
        inline Error vpcompressq(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressq, a, b, c);
        }
        inline Error vpcompressq(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressq, a, b, c);
        }
        inline Error vpcompressw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressw, a, b, c);
        }
        inline Error vpcompressw(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressw, a, b, c);
        }
        inline Error vpcompressw(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressw, a, b, c);
        }
        inline Error vpcompressw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressw, a, b, c);
        }
        inline Error vpcompressw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressw, a, b, c);
        }
        inline Error vpcompressw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressw, a, b, c);
        }
        inline Error vpcomq(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomq, a, b, c, d);
        }
        inline Error vpcomq(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomq, a, b, c, d);
        }
        inline Error vpcomub(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomub, a, b, c, d);
        }
        inline Error vpcomub(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomub, a, b, c, d);
        }
        inline Error vpcomud(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomud, a, b, c, d);
        }
        inline Error vpcomud(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomud, a, b, c, d);
        }
        inline Error vpcomuq(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomuq, a, b, c, d);
        }
        inline Error vpcomuq(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomuq, a, b, c, d);
        }
        inline Error vpcomuw(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomuw, a, b, c, d);
        }
        inline Error vpcomuw(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomuw, a, b, c, d);
        }
        inline Error vpcomw(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomw, a, b, c, d);
        }
        inline Error vpcomw(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomw, a, b, c, d);
        }
        inline Error vpconflictd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpconflictd, a, b, c);
        }
        inline Error vpconflictd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpconflictd, a, b, c);
        }
        inline Error vpconflictd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpconflictd, a, b, c);
        }
        inline Error vpconflictd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpconflictd, a, b, c);
        }
        inline Error vpconflictd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpconflictd, a, b, c);
        }
        inline Error vpconflictd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpconflictd, a, b, c);
        }
        inline Error vpconflictq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpconflictq, a, b, c);
        }
        inline Error vpconflictq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpconflictq, a, b, c);
        }
        inline Error vpconflictq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpconflictq, a, b, c);
        }
        inline Error vpconflictq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpconflictq, a, b, c);
        }
        inline Error vpconflictq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpconflictq, a, b, c);
        }
        inline Error vpconflictq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpconflictq, a, b, c);
        }
        inline Error vpdpbusd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c);
        }
        inline Error vpdpbusd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c);
        }
        inline Error vpdpbusd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c);
        }
        inline Error vpdpbusd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c);
        }
        inline Error vpdpbusd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c, d);
        }
        inline Error vpdpbusd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c, d);
        }
        inline Error vpdpbusd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c, d);
        }
        inline Error vpdpbusd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c, d);
        }
        inline Error vpdpbusd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c, d);
        }
        inline Error vpdpbusd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c, d);
        }
        inline Error vpdpbusds(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c);
        }
        inline Error vpdpbusds(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c);
        }
        inline Error vpdpbusds(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c);
        }
        inline Error vpdpbusds(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c);
        }
        inline Error vpdpbusds(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c, d);
        }
        inline Error vpdpbusds(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c, d);
        }
        inline Error vpdpbusds(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c, d);
        }
        inline Error vpdpbusds(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c, d);
        }
        inline Error vpdpbusds(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c, d);
        }
        inline Error vpdpbusds(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c, d);
        }
        inline Error vpdpwssd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c);
        }
        inline Error vpdpwssd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c);
        }
        inline Error vpdpwssd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c);
        }
        inline Error vpdpwssd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c);
        }
        inline Error vpdpwssd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c, d);
        }
        inline Error vpdpwssd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c, d);
        }
        inline Error vpdpwssd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c, d);
        }
        inline Error vpdpwssd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c, d);
        }
        inline Error vpdpwssd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c, d);
        }
        inline Error vpdpwssd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c, d);
        }
        inline Error vpdpwssds(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c);
        }
        inline Error vpdpwssds(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c);
        }
        inline Error vpdpwssds(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c);
        }
        inline Error vpdpwssds(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c);
        }
        inline Error vpdpwssds(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c, d);
        }
        inline Error vpdpwssds(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c, d);
        }
        inline Error vpdpwssds(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c, d);
        }
        inline Error vpdpwssds(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c, d);
        }
        inline Error vpdpwssds(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c, d);
        }
        inline Error vpdpwssds(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c, d);
        }
        inline Error vperm2f128(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vperm2f128, a, b, c, d);
        }
        inline Error vperm2f128(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vperm2f128, a, b, c, d);
        }
        inline Error vperm2i128(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vperm2i128, a, b, c, d);
        }
        inline Error vperm2i128(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vperm2i128, a, b, c, d);
        }
        inline Error vpermb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermb, a, b, c, d);
        }
        inline Error vpermb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermb, a, b, c, d);
        }
        inline Error vpermb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermb, a, b, c, d);
        }
        inline Error vpermb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermb, a, b, c, d);
        }
        inline Error vpermb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermb, a, b, c, d);
        }
        inline Error vpermb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermb, a, b, c, d);
        }
        inline Error vpermd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpermd, a, b, c);
        }
        inline Error vpermd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpermd, a, b, c);
        }
        inline Error vpermd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermd, a, b, c, d);
        }
        inline Error vpermd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermd, a, b, c, d);
        }
        inline Error vpermd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermd, a, b, c, d);
        }
        inline Error vpermd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermd, a, b, c, d);
        }
        inline Error vpermf32x4(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermf32x4, a, b, c, d);
        }
        inline Error vpermf32x4(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermf32x4, a, b, c, d);
        }
        inline Error vpermi2b(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2b, a, b, c, d);
        }
        inline Error vpermi2b(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermi2b, a, b, c, d);
        }
        inline Error vpermi2b(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2b, a, b, c, d);
        }
        inline Error vpermi2b(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2b, a, b, c, d);
        }
        inline Error vpermi2b(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2b, a, b, c, d);
        }
        inline Error vpermi2b(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2b, a, b, c, d);
        }
        inline Error vpermi2d(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2d, a, b, c, d);
        }
        inline Error vpermi2d(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermi2d, a, b, c, d);
        }
        inline Error vpermi2d(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2d, a, b, c, d);
        }
        inline Error vpermi2d(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2d, a, b, c, d);
        }
        inline Error vpermi2d(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2d, a, b, c, d);
        }
        inline Error vpermi2d(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2d, a, b, c, d);
        }
        inline Error vpermi2pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2pd, a, b, c, d);
        }
        inline Error vpermi2pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermi2pd, a, b, c, d);
        }
        inline Error vpermi2pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2pd, a, b, c, d);
        }
        inline Error vpermi2pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2pd, a, b, c, d);
        }
        inline Error vpermi2pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2pd, a, b, c, d);
        }
        inline Error vpermi2pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2pd, a, b, c, d);
        }
        inline Error vpermi2ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2ps, a, b, c, d);
        }
        inline Error vpermi2ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermi2ps, a, b, c, d);
        }
        inline Error vpermi2ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2ps, a, b, c, d);
        }
        inline Error vpermi2ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2ps, a, b, c, d);
        }
        inline Error vpermi2ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2ps, a, b, c, d);
        }
        inline Error vpermi2ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2ps, a, b, c, d);
        }
        inline Error vpermi2q(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2q, a, b, c, d);
        }
        inline Error vpermi2q(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermi2q, a, b, c, d);
        }
        inline Error vpermi2q(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2q, a, b, c, d);
        }
        inline Error vpermi2q(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2q, a, b, c, d);
        }
        inline Error vpermi2q(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2q, a, b, c, d);
        }
        inline Error vpermi2q(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2q, a, b, c, d);
        }
        inline Error vpermi2w(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2w, a, b, c, d);
        }
        inline Error vpermi2w(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermi2w, a, b, c, d);
        }
        inline Error vpermi2w(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2w, a, b, c, d);
        }
        inline Error vpermi2w(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2w, a, b, c, d);
        }
        inline Error vpermi2w(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2w, a, b, c, d);
        }
        inline Error vpermi2w(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2w, a, b, c, d);
        }
        inline Error vpermil2pd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2pd, a, b, c, d, e);
        }
        inline Error vpermil2pd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2pd, a, b, c, d, e);
        }
        inline Error vpermil2pd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2pd, a, b, c, d, e);
        }
        inline Error vpermil2pd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2pd, a, b, c, d, e);
        }
        inline Error vpermil2pd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2pd, a, b, c, d, e);
        }
        inline Error vpermil2pd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2pd, a, b, c, d, e);
        }
        inline Error vpermil2ps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2ps, a, b, c, d, e);
        }
        inline Error vpermil2ps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2ps, a, b, c, d, e);
        }
        inline Error vpermil2ps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2ps, a, b, c, d, e);
        }
        inline Error vpermil2ps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2ps, a, b, c, d, e);
        }
        inline Error vpermil2ps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2ps, a, b, c, d, e);
        }
        inline Error vpermil2ps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2ps, a, b, c, d, e);
        }
        inline Error vpermilpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        inline Error vpermilpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        inline Error vpermilpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        inline Error vpermilpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        inline Error vpermilpd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        inline Error vpermilpd(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        inline Error vpermilpd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        inline Error vpermilpd(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        inline Error vpermilpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        inline Error vpermilpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        inline Error vpermilpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        inline Error vpermilpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        inline Error vpermilpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        inline Error vpermilpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        inline Error vpermilpd(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        inline Error vpermilpd(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        inline Error vpermilpd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        inline Error vpermilpd(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        inline Error vpermilpd(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        inline Error vpermilpd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        inline Error vpermilps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        inline Error vpermilps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        inline Error vpermilps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        inline Error vpermilps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        inline Error vpermilps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        inline Error vpermilps(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        inline Error vpermilps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        inline Error vpermilps(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        inline Error vpermilps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        inline Error vpermilps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        inline Error vpermilps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        inline Error vpermilps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        inline Error vpermilps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        inline Error vpermilps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        inline Error vpermilps(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        inline Error vpermilps(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        inline Error vpermilps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        inline Error vpermilps(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        inline Error vpermilps(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        inline Error vpermilps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        inline Error vpermpd(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c);
        }
        inline Error vpermpd(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c);
        }
        inline Error vpermpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        inline Error vpermpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        inline Error vpermpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        inline Error vpermpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        inline Error vpermpd(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        inline Error vpermpd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        inline Error vpermpd(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        inline Error vpermpd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        inline Error vpermps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpermps, a, b, c);
        }
        inline Error vpermps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpermps, a, b, c);
        }
        inline Error vpermps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermps, a, b, c, d);
        }
        inline Error vpermps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermps, a, b, c, d);
        }
        inline Error vpermps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermps, a, b, c, d);
        }
        inline Error vpermps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermps, a, b, c, d);
        }
        inline Error vpermq(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c);
        }
        inline Error vpermq(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c);
        }
        inline Error vpermq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        inline Error vpermq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        inline Error vpermq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        inline Error vpermq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        inline Error vpermq(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        inline Error vpermq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        inline Error vpermq(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        inline Error vpermq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        inline Error vpermt2b(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2b, a, b, c, d);
        }
        inline Error vpermt2b(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermt2b, a, b, c, d);
        }
        inline Error vpermt2b(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2b, a, b, c, d);
        }
        inline Error vpermt2b(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2b, a, b, c, d);
        }
        inline Error vpermt2b(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2b, a, b, c, d);
        }
        inline Error vpermt2b(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2b, a, b, c, d);
        }
        inline Error vpermt2d(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2d, a, b, c, d);
        }
        inline Error vpermt2d(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermt2d, a, b, c, d);
        }
        inline Error vpermt2d(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2d, a, b, c, d);
        }
        inline Error vpermt2d(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2d, a, b, c, d);
        }
        inline Error vpermt2d(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2d, a, b, c, d);
        }
        inline Error vpermt2d(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2d, a, b, c, d);
        }
        inline Error vpermt2pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2pd, a, b, c, d);
        }
        inline Error vpermt2pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermt2pd, a, b, c, d);
        }
        inline Error vpermt2pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2pd, a, b, c, d);
        }
        inline Error vpermt2pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2pd, a, b, c, d);
        }
        inline Error vpermt2pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2pd, a, b, c, d);
        }
        inline Error vpermt2pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2pd, a, b, c, d);
        }
        inline Error vpermt2ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2ps, a, b, c, d);
        }
        inline Error vpermt2ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermt2ps, a, b, c, d);
        }
        inline Error vpermt2ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2ps, a, b, c, d);
        }
        inline Error vpermt2ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2ps, a, b, c, d);
        }
        inline Error vpermt2ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2ps, a, b, c, d);
        }
        inline Error vpermt2ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2ps, a, b, c, d);
        }
        inline Error vpermt2q(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2q, a, b, c, d);
        }
        inline Error vpermt2q(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermt2q, a, b, c, d);
        }
        inline Error vpermt2q(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2q, a, b, c, d);
        }
        inline Error vpermt2q(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2q, a, b, c, d);
        }
        inline Error vpermt2q(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2q, a, b, c, d);
        }
        inline Error vpermt2q(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2q, a, b, c, d);
        }
        inline Error vpermt2w(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2w, a, b, c, d);
        }
        inline Error vpermt2w(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermt2w, a, b, c, d);
        }
        inline Error vpermt2w(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2w, a, b, c, d);
        }
        inline Error vpermt2w(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2w, a, b, c, d);
        }
        inline Error vpermt2w(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2w, a, b, c, d);
        }
        inline Error vpermt2w(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2w, a, b, c, d);
        }
        inline Error vpermw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermw, a, b, c, d);
        }
        inline Error vpermw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermw, a, b, c, d);
        }
        inline Error vpermw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermw, a, b, c, d);
        }
        inline Error vpermw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermw, a, b, c, d);
        }
        inline Error vpermw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermw, a, b, c, d);
        }
        inline Error vpermw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermw, a, b, c, d);
        }
        inline Error vpexpandb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandb, a, b, c);
        }
        inline Error vpexpandb(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpexpandb, a, b, c);
        }
        inline Error vpexpandb(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandb, a, b, c);
        }
        inline Error vpexpandb(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandb, a, b, c);
        }
        inline Error vpexpandb(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandb, a, b, c);
        }
        inline Error vpexpandb(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandb, a, b, c);
        }
        inline Error vpexpandd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandd, a, b, c);
        }
        inline Error vpexpandd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpexpandd, a, b, c);
        }
        inline Error vpexpandd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandd, a, b, c);
        }
        inline Error vpexpandd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandd, a, b, c);
        }
        inline Error vpexpandd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandd, a, b, c);
        }
        inline Error vpexpandd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandd, a, b, c);
        }
        inline Error vpexpandq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandq, a, b, c);
        }
        inline Error vpexpandq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpexpandq, a, b, c);
        }
        inline Error vpexpandq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandq, a, b, c);
        }
        inline Error vpexpandq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandq, a, b, c);
        }
        inline Error vpexpandq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandq, a, b, c);
        }
        inline Error vpexpandq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandq, a, b, c);
        }
        inline Error vpexpandw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandw, a, b, c);
        }
        inline Error vpexpandw(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpexpandw, a, b, c);
        }
        inline Error vpexpandw(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandw, a, b, c);
        }
        inline Error vpexpandw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandw, a, b, c);
        }
        inline Error vpexpandw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandw, a, b, c);
        }
        inline Error vpexpandw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandw, a, b, c);
        }
        inline Error vpextrb(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrb, a, b, c);
        }
        inline Error vpextrb(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrb, a, b, c);
        }
        inline Error vpextrd(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrd, a, b, c);
        }
        inline Error vpextrd(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrd, a, b, c);
        }
        inline Error vpextrq(const Gp64& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrq, a, b, c);
        }
        inline Error vpextrq(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrq, a, b, c);
        }
        inline Error vpextrw(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrw, a, b, c);
        }
        inline Error vpextrw(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrw, a, b, c);
        }
        inline Error vpgatherdd(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpgatherdd, a, b, c);
        }
        inline Error vpgatherdd(const Ymm& a, const Mem& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpgatherdd, a, b, c);
        }
        inline Error vpgatherdd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherdd, a, b, c);
        }
        inline Error vpgatherdd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherdd, a, b, c);
        }
        inline Error vpgatherdd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherdd, a, b, c);
        }
        inline Error vpgatherdq(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpgatherdq, a, b, c);
        }
        inline Error vpgatherdq(const Ymm& a, const Mem& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpgatherdq, a, b, c);
        }
        inline Error vpgatherdq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherdq, a, b, c);
        }
        inline Error vpgatherdq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherdq, a, b, c);
        }
        inline Error vpgatherdq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherdq, a, b, c);
        }
        inline Error vpgatherqd(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpgatherqd, a, b, c);
        }
        inline Error vpgatherqd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherqd, a, b, c);
        }
        inline Error vpgatherqd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherqd, a, b, c);
        }
        inline Error vpgatherqq(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpgatherqq, a, b, c);
        }
        inline Error vpgatherqq(const Ymm& a, const Mem& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpgatherqq, a, b, c);
        }
        inline Error vpgatherqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherqq, a, b, c);
        }
        inline Error vpgatherqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherqq, a, b, c);
        }
        inline Error vpgatherqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherqq, a, b, c);
        }
        inline Error vphaddbd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddbd, a, b);
        }
        inline Error vphaddbd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddbd, a, b);
        }
        inline Error vphaddbq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddbq, a, b);
        }
        inline Error vphaddbq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddbq, a, b);
        }
        inline Error vphaddbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddbw, a, b);
        }
        inline Error vphaddbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddbw, a, b);
        }
        inline Error vphaddd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vphaddd, a, b, c);
        }
        inline Error vphaddd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vphaddd, a, b, c);
        }
        inline Error vphaddd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphaddd, a, b, c);
        }
        inline Error vphaddd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphaddd, a, b, c);
        }
        inline Error vphadddq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphadddq, a, b);
        }
        inline Error vphadddq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphadddq, a, b);
        }
        inline Error vphaddsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vphaddsw, a, b, c);
        }
        inline Error vphaddsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vphaddsw, a, b, c);
        }
        inline Error vphaddsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphaddsw, a, b, c);
        }
        inline Error vphaddsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphaddsw, a, b, c);
        }
        inline Error vphaddubd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddubd, a, b);
        }
        inline Error vphaddubd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddubd, a, b);
        }
        inline Error vphaddubq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddubq, a, b);
        }
        inline Error vphaddubq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddubq, a, b);
        }
        inline Error vphaddubw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddubw, a, b);
        }
        inline Error vphaddubw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddubw, a, b);
        }
        inline Error vphaddudq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddudq, a, b);
        }
        inline Error vphaddudq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddudq, a, b);
        }
        inline Error vphadduwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphadduwd, a, b);
        }
        inline Error vphadduwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphadduwd, a, b);
        }
        inline Error vphadduwq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphadduwq, a, b);
        }
        inline Error vphadduwq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphadduwq, a, b);
        }
        inline Error vphaddw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vphaddw, a, b, c);
        }
        inline Error vphaddw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vphaddw, a, b, c);
        }
        inline Error vphaddw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphaddw, a, b, c);
        }
        inline Error vphaddw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphaddw, a, b, c);
        }
        inline Error vphaddwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddwd, a, b);
        }
        inline Error vphaddwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddwd, a, b);
        }
        inline Error vphaddwq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddwq, a, b);
        }
        inline Error vphaddwq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddwq, a, b);
        }
        inline Error vphminposuw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphminposuw, a, b);
        }
        inline Error vphminposuw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphminposuw, a, b);
        }
        inline Error vphsubbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphsubbw, a, b);
        }
        inline Error vphsubbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphsubbw, a, b);
        }
        inline Error vphsubd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vphsubd, a, b, c);
        }
        inline Error vphsubd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vphsubd, a, b, c);
        }
        inline Error vphsubd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphsubd, a, b, c);
        }
        inline Error vphsubd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphsubd, a, b, c);
        }
        inline Error vphsubdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphsubdq, a, b);
        }
        inline Error vphsubdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphsubdq, a, b);
        }
        inline Error vphsubsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vphsubsw, a, b, c);
        }
        inline Error vphsubsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vphsubsw, a, b, c);
        }
        inline Error vphsubsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphsubsw, a, b, c);
        }
        inline Error vphsubsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphsubsw, a, b, c);
        }
        inline Error vphsubw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vphsubw, a, b, c);
        }
        inline Error vphsubw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vphsubw, a, b, c);
        }
        inline Error vphsubw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphsubw, a, b, c);
        }
        inline Error vphsubw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphsubw, a, b, c);
        }
        inline Error vphsubwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphsubwd, a, b);
        }
        inline Error vphsubwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphsubwd, a, b);
        }
        inline Error vpinsrb(const Xmm& a, const Xmm& b, const Gp32& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrb, a, b, c, d);
        }
        inline Error vpinsrb(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrb, a, b, c, d);
        }
        inline Error vpinsrd(const Xmm& a, const Xmm& b, const Gp32& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrd, a, b, c, d);
        }
        inline Error vpinsrd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrd, a, b, c, d);
        }
        inline Error vpinsrq(const Xmm& a, const Xmm& b, const Gp64& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrq, a, b, c, d);
        }
        inline Error vpinsrq(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrq, a, b, c, d);
        }
        inline Error vpinsrw(const Xmm& a, const Xmm& b, const Gp32& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrw, a, b, c, d);
        }
        inline Error vpinsrw(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrw, a, b, c, d);
        }
        inline Error vplzcntd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vplzcntd, a, b, c);
        }
        inline Error vplzcntd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vplzcntd, a, b, c);
        }
        inline Error vplzcntd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vplzcntd, a, b, c);
        }
        inline Error vplzcntd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vplzcntd, a, b, c);
        }
        inline Error vplzcntd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vplzcntd, a, b, c);
        }
        inline Error vplzcntd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vplzcntd, a, b, c);
        }
        inline Error vplzcntq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vplzcntq, a, b, c);
        }
        inline Error vplzcntq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vplzcntq, a, b, c);
        }
        inline Error vplzcntq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vplzcntq, a, b, c);
        }
        inline Error vplzcntq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vplzcntq, a, b, c);
        }
        inline Error vplzcntq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vplzcntq, a, b, c);
        }
        inline Error vplzcntq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vplzcntq, a, b, c);
        }
        inline Error vpmacsdd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsdd, a, b, c, d);
        }
        inline Error vpmacsdd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsdd, a, b, c, d);
        }
        inline Error vpmacsdqh(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsdqh, a, b, c, d);
        }
        inline Error vpmacsdqh(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsdqh, a, b, c, d);
        }
        inline Error vpmacsdql(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsdql, a, b, c, d);
        }
        inline Error vpmacsdql(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsdql, a, b, c, d);
        }
        inline Error vpmacssdd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssdd, a, b, c, d);
        }
        inline Error vpmacssdd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssdd, a, b, c, d);
        }
        inline Error vpmacssdqh(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssdqh, a, b, c, d);
        }
        inline Error vpmacssdqh(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssdqh, a, b, c, d);
        }
        inline Error vpmacssdql(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssdql, a, b, c, d);
        }
        inline Error vpmacssdql(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssdql, a, b, c, d);
        }
        inline Error vpmacsswd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsswd, a, b, c, d);
        }
        inline Error vpmacsswd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsswd, a, b, c, d);
        }
        inline Error vpmacssww(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssww, a, b, c, d);
        }
        inline Error vpmacssww(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssww, a, b, c, d);
        }
        inline Error vpmacswd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacswd, a, b, c, d);
        }
        inline Error vpmacswd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacswd, a, b, c, d);
        }
        inline Error vpmacsww(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsww, a, b, c, d);
        }
        inline Error vpmacsww(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsww, a, b, c, d);
        }
        inline Error vpmadcsswd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmadcsswd, a, b, c, d);
        }
        inline Error vpmadcsswd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmadcsswd, a, b, c, d);
        }
        inline Error vpmadcswd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmadcswd, a, b, c, d);
        }
        inline Error vpmadcswd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmadcswd, a, b, c, d);
        }
        inline Error vpmadd231d(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmadd231d, a, b, c, d);
        }
        inline Error vpmadd231d(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd231d, a, b, c, d);
        }
        inline Error vpmadd233d(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmadd233d, a, b, c, d);
        }
        inline Error vpmadd233d(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd233d, a, b, c, d);
        }
        inline Error vpmadd52huq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmadd52huq, a, b, c, d);
        }
        inline Error vpmadd52huq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmadd52huq, a, b, c, d);
        }
        inline Error vpmadd52huq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmadd52huq, a, b, c, d);
        }
        inline Error vpmadd52huq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd52huq, a, b, c, d);
        }
        inline Error vpmadd52huq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd52huq, a, b, c, d);
        }
        inline Error vpmadd52huq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd52huq, a, b, c, d);
        }
        inline Error vpmadd52luq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmadd52luq, a, b, c, d);
        }
        inline Error vpmadd52luq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmadd52luq, a, b, c, d);
        }
        inline Error vpmadd52luq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmadd52luq, a, b, c, d);
        }
        inline Error vpmadd52luq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd52luq, a, b, c, d);
        }
        inline Error vpmadd52luq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd52luq, a, b, c, d);
        }
        inline Error vpmadd52luq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd52luq, a, b, c, d);
        }
        inline Error vpmaddubsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c);
        }
        inline Error vpmaddubsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c);
        }
        inline Error vpmaddubsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c);
        }
        inline Error vpmaddubsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c);
        }
        inline Error vpmaddubsw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c, d);
        }
        inline Error vpmaddubsw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c, d);
        }
        inline Error vpmaddubsw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c, d);
        }
        inline Error vpmaddubsw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c, d);
        }
        inline Error vpmaddubsw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c, d);
        }
        inline Error vpmaddubsw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c, d);
        }
        inline Error vpmaddwd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c);
        }
        inline Error vpmaddwd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c);
        }
        inline Error vpmaddwd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c);
        }
        inline Error vpmaddwd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c);
        }
        inline Error vpmaddwd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c, d);
        }
        inline Error vpmaddwd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c, d);
        }
        inline Error vpmaddwd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c, d);
        }
        inline Error vpmaddwd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c, d);
        }
        inline Error vpmaddwd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c, d);
        }
        inline Error vpmaddwd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c, d);
        }
        inline Error vpmaskmovd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovd, a, b, c);
        }
        inline Error vpmaskmovd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovd, a, b, c);
        }
        inline Error vpmaskmovd(const Mem& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovd, a, b, c);
        }
        inline Error vpmaskmovd(const Mem& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovd, a, b, c);
        }
        inline Error vpmaskmovq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovq, a, b, c);
        }
        inline Error vpmaskmovq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovq, a, b, c);
        }
        inline Error vpmaskmovq(const Mem& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovq, a, b, c);
        }
        inline Error vpmaskmovq(const Mem& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovq, a, b, c);
        }
        inline Error vpmaxsb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c);
        }
        inline Error vpmaxsb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c);
        }
        inline Error vpmaxsb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c);
        }
        inline Error vpmaxsb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c);
        }
        inline Error vpmaxsb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c, d);
        }
        inline Error vpmaxsb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c, d);
        }
        inline Error vpmaxsb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c, d);
        }
        inline Error vpmaxsb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c, d);
        }
        inline Error vpmaxsb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c, d);
        }
        inline Error vpmaxsb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c, d);
        }
        inline Error vpmaxsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c);
        }
        inline Error vpmaxsd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c);
        }
        inline Error vpmaxsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c);
        }
        inline Error vpmaxsd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c);
        }
        inline Error vpmaxsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c, d);
        }
        inline Error vpmaxsd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c, d);
        }
        inline Error vpmaxsd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c, d);
        }
        inline Error vpmaxsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c, d);
        }
        inline Error vpmaxsd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c, d);
        }
        inline Error vpmaxsd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c, d);
        }
        inline Error vpmaxsq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsq, a, b, c, d);
        }
        inline Error vpmaxsq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsq, a, b, c, d);
        }
        inline Error vpmaxsq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsq, a, b, c, d);
        }
        inline Error vpmaxsq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsq, a, b, c, d);
        }
        inline Error vpmaxsq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsq, a, b, c, d);
        }
        inline Error vpmaxsq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsq, a, b, c, d);
        }
        inline Error vpmaxsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c);
        }
        inline Error vpmaxsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c);
        }
        inline Error vpmaxsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c);
        }
        inline Error vpmaxsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c);
        }
        inline Error vpmaxsw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c, d);
        }
        inline Error vpmaxsw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c, d);
        }
        inline Error vpmaxsw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c, d);
        }
        inline Error vpmaxsw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c, d);
        }
        inline Error vpmaxsw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c, d);
        }
        inline Error vpmaxsw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c, d);
        }
        inline Error vpmaxub(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c);
        }
        inline Error vpmaxub(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c);
        }
        inline Error vpmaxub(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c);
        }
        inline Error vpmaxub(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c);
        }
        inline Error vpmaxub(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c, d);
        }
        inline Error vpmaxub(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c, d);
        }
        inline Error vpmaxub(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c, d);
        }
        inline Error vpmaxub(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c, d);
        }
        inline Error vpmaxub(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c, d);
        }
        inline Error vpmaxub(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c, d);
        }
        inline Error vpmaxud(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c);
        }
        inline Error vpmaxud(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c);
        }
        inline Error vpmaxud(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c);
        }
        inline Error vpmaxud(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c);
        }
        inline Error vpmaxud(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c, d);
        }
        inline Error vpmaxud(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c, d);
        }
        inline Error vpmaxud(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c, d);
        }
        inline Error vpmaxud(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c, d);
        }
        inline Error vpmaxud(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c, d);
        }
        inline Error vpmaxud(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c, d);
        }
        inline Error vpmaxuq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxuq, a, b, c, d);
        }
        inline Error vpmaxuq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxuq, a, b, c, d);
        }
        inline Error vpmaxuq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxuq, a, b, c, d);
        }
        inline Error vpmaxuq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxuq, a, b, c, d);
        }
        inline Error vpmaxuq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxuq, a, b, c, d);
        }
        inline Error vpmaxuq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxuq, a, b, c, d);
        }
        inline Error vpmaxuw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c);
        }
        inline Error vpmaxuw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c);
        }
        inline Error vpmaxuw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c);
        }
        inline Error vpmaxuw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c);
        }
        inline Error vpmaxuw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c, d);
        }
        inline Error vpmaxuw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c, d);
        }
        inline Error vpmaxuw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c, d);
        }
        inline Error vpmaxuw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c, d);
        }
        inline Error vpmaxuw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c, d);
        }
        inline Error vpmaxuw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c, d);
        }
        inline Error vpminsb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c);
        }
        inline Error vpminsb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c);
        }
        inline Error vpminsb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c);
        }
        inline Error vpminsb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c);
        }
        inline Error vpminsb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c, d);
        }
        inline Error vpminsb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c, d);
        }
        inline Error vpminsb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c, d);
        }
        inline Error vpminsb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c, d);
        }
        inline Error vpminsb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c, d);
        }
        inline Error vpminsb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c, d);
        }
        inline Error vpminsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c);
        }
        inline Error vpminsd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c);
        }
        inline Error vpminsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c);
        }
        inline Error vpminsd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c);
        }
        inline Error vpminsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c, d);
        }
        inline Error vpminsd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c, d);
        }
        inline Error vpminsd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c, d);
        }
        inline Error vpminsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c, d);
        }
        inline Error vpminsd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c, d);
        }
        inline Error vpminsd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c, d);
        }
        inline Error vpminsq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminsq, a, b, c, d);
        }
        inline Error vpminsq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminsq, a, b, c, d);
        }
        inline Error vpminsq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminsq, a, b, c, d);
        }
        inline Error vpminsq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsq, a, b, c, d);
        }
        inline Error vpminsq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsq, a, b, c, d);
        }
        inline Error vpminsq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsq, a, b, c, d);
        }
        inline Error vpminsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c);
        }
        inline Error vpminsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c);
        }
        inline Error vpminsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c);
        }
        inline Error vpminsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c);
        }
        inline Error vpminsw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c, d);
        }
        inline Error vpminsw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c, d);
        }
        inline Error vpminsw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c, d);
        }
        inline Error vpminsw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c, d);
        }
        inline Error vpminsw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c, d);
        }
        inline Error vpminsw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c, d);
        }
        inline Error vpminub(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c);
        }
        inline Error vpminub(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c);
        }
        inline Error vpminub(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c);
        }
        inline Error vpminub(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c);
        }
        inline Error vpminub(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c, d);
        }
        inline Error vpminub(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c, d);
        }
        inline Error vpminub(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c, d);
        }
        inline Error vpminub(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c, d);
        }
        inline Error vpminub(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c, d);
        }
        inline Error vpminub(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c, d);
        }
        inline Error vpminud(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c);
        }
        inline Error vpminud(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c);
        }
        inline Error vpminud(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c);
        }
        inline Error vpminud(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c);
        }
        inline Error vpminud(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c, d);
        }
        inline Error vpminud(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c, d);
        }
        inline Error vpminud(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c, d);
        }
        inline Error vpminud(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c, d);
        }
        inline Error vpminud(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c, d);
        }
        inline Error vpminud(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c, d);
        }
        inline Error vpminuq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminuq, a, b, c, d);
        }
        inline Error vpminuq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminuq, a, b, c, d);
        }
        inline Error vpminuq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminuq, a, b, c, d);
        }
        inline Error vpminuq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminuq, a, b, c, d);
        }
        inline Error vpminuq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminuq, a, b, c, d);
        }
        inline Error vpminuq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminuq, a, b, c, d);
        }
        inline Error vpminuw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c);
        }
        inline Error vpminuw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c);
        }
        inline Error vpminuw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c);
        }
        inline Error vpminuw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c);
        }
        inline Error vpminuw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c, d);
        }
        inline Error vpminuw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c, d);
        }
        inline Error vpminuw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c, d);
        }
        inline Error vpminuw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c, d);
        }
        inline Error vpminuw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c, d);
        }
        inline Error vpminuw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c, d);
        }
        inline Error vpmovb2m(const Mask& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovb2m, a, b);
        }
        inline Error vpmovb2m(const Mask& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpmovb2m, a, b);
        }
        inline Error vpmovb2m(const Mask& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vpmovb2m, a, b);
        }
        inline Error vpmovd2m(const Mask& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovd2m, a, b);
        }
        inline Error vpmovd2m(const Mask& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpmovd2m, a, b);
        }
        inline Error vpmovd2m(const Mask& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vpmovd2m, a, b);
        }
        inline Error vpmovdb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdb, a, b, c);
        }
        inline Error vpmovdb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovdb, a, b, c);
        }
        inline Error vpmovdb(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdb, a, b, c);
        }
        inline Error vpmovdb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdb, a, b, c);
        }
        inline Error vpmovdb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovdb, a, b, c);
        }
        inline Error vpmovdb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdb, a, b, c);
        }
        inline Error vpmovdw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdw, a, b, c);
        }
        inline Error vpmovdw(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovdw, a, b, c);
        }
        inline Error vpmovdw(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdw, a, b, c);
        }
        inline Error vpmovdw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdw, a, b, c);
        }
        inline Error vpmovdw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovdw, a, b, c);
        }
        inline Error vpmovdw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdw, a, b, c);
        }
        inline Error vpmovm2b(const Xmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2b, a, b);
        }
        inline Error vpmovm2b(const Ymm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2b, a, b);
        }
        inline Error vpmovm2b(const Zmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2b, a, b);
        }
        inline Error vpmovm2d(const Xmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2d, a, b);
        }
        inline Error vpmovm2d(const Ymm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2d, a, b);
        }
        inline Error vpmovm2d(const Zmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2d, a, b);
        }
        inline Error vpmovm2q(const Xmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2q, a, b);
        }
        inline Error vpmovm2q(const Ymm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2q, a, b);
        }
        inline Error vpmovm2q(const Zmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2q, a, b);
        }
        inline Error vpmovm2w(const Xmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2w, a, b);
        }
        inline Error vpmovm2w(const Ymm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2w, a, b);
        }
        inline Error vpmovm2w(const Zmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2w, a, b);
        }
        inline Error vpmovmskb(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovmskb, a, b);
        }
        inline Error vpmovmskb(const Gp32& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpmovmskb, a, b);
        }
        inline Error vpmovq2m(const Mask& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovq2m, a, b);
        }
        inline Error vpmovq2m(const Mask& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpmovq2m, a, b);
        }
        inline Error vpmovq2m(const Mask& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vpmovq2m, a, b);
        }
        inline Error vpmovqb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqb, a, b, c);
        }
        inline Error vpmovqb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovqb, a, b, c);
        }
        inline Error vpmovqb(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqb, a, b, c);
        }
        inline Error vpmovqb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqb, a, b, c);
        }
        inline Error vpmovqb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovqb, a, b, c);
        }
        inline Error vpmovqb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqb, a, b, c);
        }
        inline Error vpmovqd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqd, a, b, c);
        }
        inline Error vpmovqd(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovqd, a, b, c);
        }
        inline Error vpmovqd(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqd, a, b, c);
        }
        inline Error vpmovqd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqd, a, b, c);
        }
        inline Error vpmovqd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovqd, a, b, c);
        }
        inline Error vpmovqd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqd, a, b, c);
        }
        inline Error vpmovqw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqw, a, b, c);
        }
        inline Error vpmovqw(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovqw, a, b, c);
        }
        inline Error vpmovqw(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqw, a, b, c);
        }
        inline Error vpmovqw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqw, a, b, c);
        }
        inline Error vpmovqw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovqw, a, b, c);
        }
        inline Error vpmovqw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqw, a, b, c);
        }
        inline Error vpmovsdb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdb, a, b, c);
        }
        inline Error vpmovsdb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdb, a, b, c);
        }
        inline Error vpmovsdb(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdb, a, b, c);
        }
        inline Error vpmovsdb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdb, a, b, c);
        }
        inline Error vpmovsdb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdb, a, b, c);
        }
        inline Error vpmovsdb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdb, a, b, c);
        }
        inline Error vpmovsdw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdw, a, b, c);
        }
        inline Error vpmovsdw(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdw, a, b, c);
        }
        inline Error vpmovsdw(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdw, a, b, c);
        }
        inline Error vpmovsdw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdw, a, b, c);
        }
        inline Error vpmovsdw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdw, a, b, c);
        }
        inline Error vpmovsdw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdw, a, b, c);
        }
        inline Error vpmovsqb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqb, a, b, c);
        }
        inline Error vpmovsqb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqb, a, b, c);
        }
        inline Error vpmovsqb(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqb, a, b, c);
        }
        inline Error vpmovsqb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqb, a, b, c);
        }
        inline Error vpmovsqb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqb, a, b, c);
        }
        inline Error vpmovsqb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqb, a, b, c);
        }
        inline Error vpmovsqd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqd, a, b, c);
        }
        inline Error vpmovsqd(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqd, a, b, c);
        }
        inline Error vpmovsqd(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqd, a, b, c);
        }
        inline Error vpmovsqd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqd, a, b, c);
        }
        inline Error vpmovsqd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqd, a, b, c);
        }
        inline Error vpmovsqd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqd, a, b, c);
        }
        inline Error vpmovsqw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqw, a, b, c);
        }
        inline Error vpmovsqw(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqw, a, b, c);
        }
        inline Error vpmovsqw(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqw, a, b, c);
        }
        inline Error vpmovsqw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqw, a, b, c);
        }
        inline Error vpmovsqw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqw, a, b, c);
        }
        inline Error vpmovsqw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqw, a, b, c);
        }
        inline Error vpmovswb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovswb, a, b, c);
        }
        inline Error vpmovswb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovswb, a, b, c);
        }
        inline Error vpmovswb(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovswb, a, b, c);
        }
        inline Error vpmovswb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovswb, a, b, c);
        }
        inline Error vpmovswb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovswb, a, b, c);
        }
        inline Error vpmovswb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovswb, a, b, c);
        }
        inline Error vpmovsxbd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b);
        }
        inline Error vpmovsxbd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b);
        }
        inline Error vpmovsxbd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b);
        }
        inline Error vpmovsxbd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b);
        }
        inline Error vpmovsxbd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b, c);
        }
        inline Error vpmovsxbd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b, c);
        }
        inline Error vpmovsxbd(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b, c);
        }
        inline Error vpmovsxbd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b, c);
        }
        inline Error vpmovsxbd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b, c);
        }
        inline Error vpmovsxbd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b, c);
        }
        inline Error vpmovsxbq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b);
        }
        inline Error vpmovsxbq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b);
        }
        inline Error vpmovsxbq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b);
        }
        inline Error vpmovsxbq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b);
        }
        inline Error vpmovsxbq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b, c);
        }
        inline Error vpmovsxbq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b, c);
        }
        inline Error vpmovsxbq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b, c);
        }
        inline Error vpmovsxbq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b, c);
        }
        inline Error vpmovsxbq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b, c);
        }
        inline Error vpmovsxbq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b, c);
        }
        inline Error vpmovsxbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b);
        }
        inline Error vpmovsxbw(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b);
        }
        inline Error vpmovsxbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b);
        }
        inline Error vpmovsxbw(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b);
        }
        inline Error vpmovsxbw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b, c);
        }
        inline Error vpmovsxbw(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b, c);
        }
        inline Error vpmovsxbw(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b, c);
        }
        inline Error vpmovsxbw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b, c);
        }
        inline Error vpmovsxbw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b, c);
        }
        inline Error vpmovsxbw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b, c);
        }
        inline Error vpmovsxdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b);
        }
        inline Error vpmovsxdq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b);
        }
        inline Error vpmovsxdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b);
        }
        inline Error vpmovsxdq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b);
        }
        inline Error vpmovsxdq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b, c);
        }
        inline Error vpmovsxdq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b, c);
        }
        inline Error vpmovsxdq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b, c);
        }
        inline Error vpmovsxdq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b, c);
        }
        inline Error vpmovsxdq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b, c);
        }
        inline Error vpmovsxdq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b, c);
        }
        inline Error vpmovsxwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b);
        }
        inline Error vpmovsxwd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b);
        }
        inline Error vpmovsxwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b);
        }
        inline Error vpmovsxwd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b);
        }
        inline Error vpmovsxwd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b, c);
        }
        inline Error vpmovsxwd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b, c);
        }
        inline Error vpmovsxwd(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b, c);
        }
        inline Error vpmovsxwd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b, c);
        }
        inline Error vpmovsxwd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b, c);
        }
        inline Error vpmovsxwd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b, c);
        }
        inline Error vpmovsxwq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b);
        }
        inline Error vpmovsxwq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b);
        }
        inline Error vpmovsxwq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b);
        }
        inline Error vpmovsxwq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b);
        }
        inline Error vpmovsxwq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b, c);
        }
        inline Error vpmovsxwq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b, c);
        }
        inline Error vpmovsxwq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b, c);
        }
        inline Error vpmovsxwq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b, c);
        }
        inline Error vpmovsxwq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b, c);
        }
        inline Error vpmovsxwq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b, c);
        }
        inline Error vpmovusdb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdb, a, b, c);
        }
        inline Error vpmovusdb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdb, a, b, c);
        }
        inline Error vpmovusdb(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdb, a, b, c);
        }
        inline Error vpmovusdb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdb, a, b, c);
        }
        inline Error vpmovusdb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdb, a, b, c);
        }
        inline Error vpmovusdb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdb, a, b, c);
        }
        inline Error vpmovusdw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdw, a, b, c);
        }
        inline Error vpmovusdw(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdw, a, b, c);
        }
        inline Error vpmovusdw(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdw, a, b, c);
        }
        inline Error vpmovusdw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdw, a, b, c);
        }
        inline Error vpmovusdw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdw, a, b, c);
        }
        inline Error vpmovusdw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdw, a, b, c);
        }
        inline Error vpmovusqb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqb, a, b, c);
        }
        inline Error vpmovusqb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqb, a, b, c);
        }
        inline Error vpmovusqb(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqb, a, b, c);
        }
        inline Error vpmovusqb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqb, a, b, c);
        }
        inline Error vpmovusqb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqb, a, b, c);
        }
        inline Error vpmovusqb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqb, a, b, c);
        }
        inline Error vpmovusqd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqd, a, b, c);
        }
        inline Error vpmovusqd(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqd, a, b, c);
        }
        inline Error vpmovusqd(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqd, a, b, c);
        }
        inline Error vpmovusqd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqd, a, b, c);
        }
        inline Error vpmovusqd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqd, a, b, c);
        }
        inline Error vpmovusqd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqd, a, b, c);
        }
        inline Error vpmovusqw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqw, a, b, c);
        }
        inline Error vpmovusqw(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqw, a, b, c);
        }
        inline Error vpmovusqw(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqw, a, b, c);
        }
        inline Error vpmovusqw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqw, a, b, c);
        }
        inline Error vpmovusqw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqw, a, b, c);
        }
        inline Error vpmovusqw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqw, a, b, c);
        }
        inline Error vpmovuswb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovuswb, a, b, c);
        }
        inline Error vpmovuswb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovuswb, a, b, c);
        }
        inline Error vpmovuswb(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovuswb, a, b, c);
        }
        inline Error vpmovuswb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovuswb, a, b, c);
        }
        inline Error vpmovuswb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovuswb, a, b, c);
        }
        inline Error vpmovuswb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovuswb, a, b, c);
        }
        inline Error vpmovw2m(const Mask& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovw2m, a, b);
        }
        inline Error vpmovw2m(const Mask& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpmovw2m, a, b);
        }
        inline Error vpmovw2m(const Mask& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vpmovw2m, a, b);
        }
        inline Error vpmovwb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovwb, a, b, c);
        }
        inline Error vpmovwb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovwb, a, b, c);
        }
        inline Error vpmovwb(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovwb, a, b, c);
        }
        inline Error vpmovwb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovwb, a, b, c);
        }
        inline Error vpmovwb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovwb, a, b, c);
        }
        inline Error vpmovwb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovwb, a, b, c);
        }
        inline Error vpmovzxbd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b);
        }
        inline Error vpmovzxbd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b);
        }
        inline Error vpmovzxbd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b);
        }
        inline Error vpmovzxbd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b);
        }
        inline Error vpmovzxbd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b, c);
        }
        inline Error vpmovzxbd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b, c);
        }
        inline Error vpmovzxbd(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b, c);
        }
        inline Error vpmovzxbd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b, c);
        }
        inline Error vpmovzxbd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b, c);
        }
        inline Error vpmovzxbd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b, c);
        }
        inline Error vpmovzxbq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b);
        }
        inline Error vpmovzxbq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b);
        }
        inline Error vpmovzxbq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b);
        }
        inline Error vpmovzxbq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b);
        }
        inline Error vpmovzxbq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b, c);
        }
        inline Error vpmovzxbq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b, c);
        }
        inline Error vpmovzxbq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b, c);
        }
        inline Error vpmovzxbq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b, c);
        }
        inline Error vpmovzxbq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b, c);
        }
        inline Error vpmovzxbq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b, c);
        }
        inline Error vpmovzxbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b);
        }
        inline Error vpmovzxbw(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b);
        }
        inline Error vpmovzxbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b);
        }
        inline Error vpmovzxbw(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b);
        }
        inline Error vpmovzxbw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b, c);
        }
        inline Error vpmovzxbw(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b, c);
        }
        inline Error vpmovzxbw(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b, c);
        }
        inline Error vpmovzxbw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b, c);
        }
        inline Error vpmovzxbw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b, c);
        }
        inline Error vpmovzxbw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b, c);
        }
        inline Error vpmovzxdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b);
        }
        inline Error vpmovzxdq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b);
        }
        inline Error vpmovzxdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b);
        }
        inline Error vpmovzxdq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b);
        }
        inline Error vpmovzxdq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b, c);
        }
        inline Error vpmovzxdq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b, c);
        }
        inline Error vpmovzxdq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b, c);
        }
        inline Error vpmovzxdq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b, c);
        }
        inline Error vpmovzxdq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b, c);
        }
        inline Error vpmovzxdq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b, c);
        }
        inline Error vpmovzxwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b);
        }
        inline Error vpmovzxwd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b);
        }
        inline Error vpmovzxwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b);
        }
        inline Error vpmovzxwd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b);
        }
        inline Error vpmovzxwd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b, c);
        }
        inline Error vpmovzxwd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b, c);
        }
        inline Error vpmovzxwd(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b, c);
        }
        inline Error vpmovzxwd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b, c);
        }
        inline Error vpmovzxwd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b, c);
        }
        inline Error vpmovzxwd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b, c);
        }
        inline Error vpmovzxwq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b);
        }
        inline Error vpmovzxwq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b);
        }
        inline Error vpmovzxwq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b);
        }
        inline Error vpmovzxwq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b);
        }
        inline Error vpmovzxwq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b, c);
        }
        inline Error vpmovzxwq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b, c);
        }
        inline Error vpmovzxwq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b, c);
        }
        inline Error vpmovzxwq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b, c);
        }
        inline Error vpmovzxwq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b, c);
        }
        inline Error vpmovzxwq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b, c);
        }
        inline Error vpmuldq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c);
        }
        inline Error vpmuldq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c);
        }
        inline Error vpmuldq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c);
        }
        inline Error vpmuldq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c);
        }
        inline Error vpmuldq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c, d);
        }
        inline Error vpmuldq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c, d);
        }
        inline Error vpmuldq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c, d);
        }
        inline Error vpmuldq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c, d);
        }
        inline Error vpmuldq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c, d);
        }
        inline Error vpmuldq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c, d);
        }
        inline Error vpmulhd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhd, a, b, c, d);
        }
        inline Error vpmulhd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhd, a, b, c, d);
        }
        inline Error vpmulhrsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c);
        }
        inline Error vpmulhrsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c);
        }
        inline Error vpmulhrsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c);
        }
        inline Error vpmulhrsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c);
        }
        inline Error vpmulhrsw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c, d);
        }
        inline Error vpmulhrsw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c, d);
        }
        inline Error vpmulhrsw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c, d);
        }
        inline Error vpmulhrsw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c, d);
        }
        inline Error vpmulhrsw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c, d);
        }
        inline Error vpmulhrsw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c, d);
        }
        inline Error vpmulhud(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhud, a, b, c, d);
        }
        inline Error vpmulhud(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhud, a, b, c, d);
        }
        inline Error vpmulhuw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c);
        }
        inline Error vpmulhuw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c);
        }
        inline Error vpmulhuw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c);
        }
        inline Error vpmulhuw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c);
        }
        inline Error vpmulhuw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c, d);
        }
        inline Error vpmulhuw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c, d);
        }
        inline Error vpmulhuw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c, d);
        }
        inline Error vpmulhuw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c, d);
        }
        inline Error vpmulhuw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c, d);
        }
        inline Error vpmulhuw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c, d);
        }
        inline Error vpmulhw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c);
        }
        inline Error vpmulhw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c);
        }
        inline Error vpmulhw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c);
        }
        inline Error vpmulhw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c);
        }
        inline Error vpmulhw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c, d);
        }
        inline Error vpmulhw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c, d);
        }
        inline Error vpmulhw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c, d);
        }
        inline Error vpmulhw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c, d);
        }
        inline Error vpmulhw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c, d);
        }
        inline Error vpmulhw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c, d);
        }
        inline Error vpmulld(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c);
        }
        inline Error vpmulld(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c);
        }
        inline Error vpmulld(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c);
        }
        inline Error vpmulld(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c);
        }
        inline Error vpmulld(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c, d);
        }
        inline Error vpmulld(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c, d);
        }
        inline Error vpmulld(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c, d);
        }
        inline Error vpmulld(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c, d);
        }
        inline Error vpmulld(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c, d);
        }
        inline Error vpmulld(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c, d);
        }
        inline Error vpmullq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmullq, a, b, c, d);
        }
        inline Error vpmullq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmullq, a, b, c, d);
        }
        inline Error vpmullq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmullq, a, b, c, d);
        }
        inline Error vpmullq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmullq, a, b, c, d);
        }
        inline Error vpmullq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmullq, a, b, c, d);
        }
        inline Error vpmullq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmullq, a, b, c, d);
        }
        inline Error vpmullw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c);
        }
        inline Error vpmullw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c);
        }
        inline Error vpmullw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c);
        }
        inline Error vpmullw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c);
        }
        inline Error vpmullw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c, d);
        }
        inline Error vpmullw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c, d);
        }
        inline Error vpmullw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c, d);
        }
        inline Error vpmullw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c, d);
        }
        inline Error vpmullw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c, d);
        }
        inline Error vpmullw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c, d);
        }
        inline Error vpmultishiftqb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmultishiftqb, a, b, c, d);
        }
        inline Error vpmultishiftqb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmultishiftqb, a, b, c, d);
        }
        inline Error vpmultishiftqb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmultishiftqb, a, b, c, d);
        }
        inline Error vpmultishiftqb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmultishiftqb, a, b, c, d);
        }
        inline Error vpmultishiftqb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmultishiftqb, a, b, c, d);
        }
        inline Error vpmultishiftqb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmultishiftqb, a, b, c, d);
        }
        inline Error vpmuludq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c);
        }
        inline Error vpmuludq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c);
        }
        inline Error vpmuludq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c);
        }
        inline Error vpmuludq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c);
        }
        inline Error vpmuludq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c, d);
        }
        inline Error vpmuludq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c, d);
        }
        inline Error vpmuludq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c, d);
        }
        inline Error vpmuludq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c, d);
        }
        inline Error vpmuludq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c, d);
        }
        inline Error vpmuludq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c, d);
        }
        inline Error vpopcntb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntb, a, b, c);
        }
        inline Error vpopcntb(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpopcntb, a, b, c);
        }
        inline Error vpopcntb(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntb, a, b, c);
        }
        inline Error vpopcntb(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntb, a, b, c);
        }
        inline Error vpopcntb(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntb, a, b, c);
        }
        inline Error vpopcntb(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntb, a, b, c);
        }
        inline Error vpopcntd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntd, a, b, c);
        }
        inline Error vpopcntd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpopcntd, a, b, c);
        }
        inline Error vpopcntd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntd, a, b, c);
        }
        inline Error vpopcntd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntd, a, b, c);
        }
        inline Error vpopcntd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntd, a, b, c);
        }
        inline Error vpopcntd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntd, a, b, c);
        }
        inline Error vpopcntq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntq, a, b, c);
        }
        inline Error vpopcntq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpopcntq, a, b, c);
        }
        inline Error vpopcntq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntq, a, b, c);
        }
        inline Error vpopcntq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntq, a, b, c);
        }
        inline Error vpopcntq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntq, a, b, c);
        }
        inline Error vpopcntq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntq, a, b, c);
        }
        inline Error vpopcntw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntw, a, b, c);
        }
        inline Error vpopcntw(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpopcntw, a, b, c);
        }
        inline Error vpopcntw(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntw, a, b, c);
        }
        inline Error vpopcntw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntw, a, b, c);
        }
        inline Error vpopcntw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntw, a, b, c);
        }
        inline Error vpopcntw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntw, a, b, c);
        }
        inline Error vpor(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpor, a, b, c);
        }
        inline Error vpor(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpor, a, b, c);
        }
        inline Error vpor(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpor, a, b, c);
        }
        inline Error vpor(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpor, a, b, c);
        }
        inline Error vpord(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpord, a, b, c, d);
        }
        inline Error vpord(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpord, a, b, c, d);
        }
        inline Error vpord(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpord, a, b, c, d);
        }
        inline Error vpord(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpord, a, b, c, d);
        }
        inline Error vpord(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpord, a, b, c, d);
        }
        inline Error vpord(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpord, a, b, c, d);
        }
        inline Error vporq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vporq, a, b, c, d);
        }
        inline Error vporq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vporq, a, b, c, d);
        }
        inline Error vporq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vporq, a, b, c, d);
        }
        inline Error vporq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vporq, a, b, c, d);
        }
        inline Error vporq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vporq, a, b, c, d);
        }
        inline Error vporq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vporq, a, b, c, d);
        }
        inline Error vpperm(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpperm, a, b, c, d);
        }
        inline Error vpperm(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpperm, a, b, c, d);
        }
        inline Error vpperm(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpperm, a, b, c, d);
        }
        inline Error vprefetch0(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetch0, a);
        }
        inline Error vprefetch1(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetch1, a);
        }
        inline Error vprefetch2(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetch2, a);
        }
        inline Error vprefetche0(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetche0, a);
        }
        inline Error vprefetche1(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetche1, a);
        }
        inline Error vprefetche2(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetche2, a);
        }
        inline Error vprefetchenta(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetchenta, a);
        }
        inline Error vprefetchnta(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetchnta, a);
        }
        inline Error vprold(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprold, a, b, c, d);
        }
        inline Error vprold(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprold, a, b, c, d);
        }
        inline Error vprold(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprold, a, b, c, d);
        }
        inline Error vprold(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprold, a, b, c, d);
        }
        inline Error vprold(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprold, a, b, c, d);
        }
        inline Error vprold(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprold, a, b, c, d);
        }
        inline Error vprolq(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprolq, a, b, c, d);
        }
        inline Error vprolq(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprolq, a, b, c, d);
        }
        inline Error vprolq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprolq, a, b, c, d);
        }
        inline Error vprolq(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprolq, a, b, c, d);
        }
        inline Error vprolq(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprolq, a, b, c, d);
        }
        inline Error vprolq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprolq, a, b, c, d);
        }
        inline Error vprolvd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vprolvd, a, b, c, d);
        }
        inline Error vprolvd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vprolvd, a, b, c, d);
        }
        inline Error vprolvd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vprolvd, a, b, c, d);
        }
        inline Error vprolvd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprolvd, a, b, c, d);
        }
        inline Error vprolvd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprolvd, a, b, c, d);
        }
        inline Error vprolvd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprolvd, a, b, c, d);
        }
        inline Error vprolvq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vprolvq, a, b, c, d);
        }
        inline Error vprolvq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vprolvq, a, b, c, d);
        }
        inline Error vprolvq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vprolvq, a, b, c, d);
        }
        inline Error vprolvq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprolvq, a, b, c, d);
        }
        inline Error vprolvq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprolvq, a, b, c, d);
        }
        inline Error vprolvq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprolvq, a, b, c, d);
        }
        inline Error vprord(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprord, a, b, c, d);
        }
        inline Error vprord(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprord, a, b, c, d);
        }
        inline Error vprord(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprord, a, b, c, d);
        }
        inline Error vprord(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprord, a, b, c, d);
        }
        inline Error vprord(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprord, a, b, c, d);
        }
        inline Error vprord(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprord, a, b, c, d);
        }
        inline Error vprorq(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprorq, a, b, c, d);
        }
        inline Error vprorq(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprorq, a, b, c, d);
        }
        inline Error vprorq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprorq, a, b, c, d);
        }
        inline Error vprorq(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprorq, a, b, c, d);
        }
        inline Error vprorq(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprorq, a, b, c, d);
        }
        inline Error vprorq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprorq, a, b, c, d);
        }
        inline Error vprorvd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vprorvd, a, b, c, d);
        }
        inline Error vprorvd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vprorvd, a, b, c, d);
        }
        inline Error vprorvd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vprorvd, a, b, c, d);
        }
        inline Error vprorvd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprorvd, a, b, c, d);
        }
        inline Error vprorvd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprorvd, a, b, c, d);
        }
        inline Error vprorvd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprorvd, a, b, c, d);
        }
        inline Error vprorvq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vprorvq, a, b, c, d);
        }
        inline Error vprorvq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vprorvq, a, b, c, d);
        }
        inline Error vprorvq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vprorvq, a, b, c, d);
        }
        inline Error vprorvq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprorvq, a, b, c, d);
        }
        inline Error vprorvq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprorvq, a, b, c, d);
        }
        inline Error vprorvq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprorvq, a, b, c, d);
        }
        inline Error vprotb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotb, a, b, c);
        }
        inline Error vprotb(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotb, a, b, c);
        }
        inline Error vprotb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vprotb, a, b, c);
        }
        inline Error vprotb(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotb, a, b, c);
        }
        inline Error vprotb(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotb, a, b, c);
        }
        inline Error vprotd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotd, a, b, c);
        }
        inline Error vprotd(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotd, a, b, c);
        }
        inline Error vprotd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vprotd, a, b, c);
        }
        inline Error vprotd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotd, a, b, c);
        }
        inline Error vprotd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotd, a, b, c);
        }
        inline Error vprotq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotq, a, b, c);
        }
        inline Error vprotq(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotq, a, b, c);
        }
        inline Error vprotq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vprotq, a, b, c);
        }
        inline Error vprotq(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotq, a, b, c);
        }
        inline Error vprotq(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotq, a, b, c);
        }
        inline Error vprotw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotw, a, b, c);
        }
        inline Error vprotw(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotw, a, b, c);
        }
        inline Error vprotw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vprotw, a, b, c);
        }
        inline Error vprotw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotw, a, b, c);
        }
        inline Error vprotw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotw, a, b, c);
        }
        inline Error vpsadbw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsadbw, a, b, c);
        }
        inline Error vpsadbw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsadbw, a, b, c);
        }
        inline Error vpsadbw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsadbw, a, b, c);
        }
        inline Error vpsadbw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsadbw, a, b, c);
        }
        inline Error vpsadbw(const Zmm& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpsadbw, a, b, c);
        }
        inline Error vpsadbw(const Zmm& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsadbw, a, b, c);
        }
        inline Error vpsbbd(const Zmm& a, const Mask& b, const Mask& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsbbd, a, b, c, d);
        }
        inline Error vpsbbd(const Zmm& a, const Mask& b, const Mask& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsbbd, a, b, c, d);
        }
        inline Error vpsbbrd(const Zmm& a, const Mask& b, const Mask& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsbbrd, a, b, c, d);
        }
        inline Error vpsbbrd(const Zmm& a, const Mask& b, const Mask& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsbbrd, a, b, c, d);
        }
        inline Error vpscatterdd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterdd, a, b, c);
        }
        inline Error vpscatterdd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpscatterdd, a, b, c);
        }
        inline Error vpscatterdd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterdd, a, b, c);
        }
        inline Error vpscatterdq(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterdq, a, b, c);
        }
        inline Error vpscatterdq(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpscatterdq, a, b, c);
        }
        inline Error vpscatterdq(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterdq, a, b, c);
        }
        inline Error vpscatterqd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterqd, a, b, c);
        }
        inline Error vpscatterqd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpscatterqd, a, b, c);
        }
        inline Error vpscatterqq(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterqq, a, b, c);
        }
        inline Error vpscatterqq(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpscatterqq, a, b, c);
        }
        inline Error vpscatterqq(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterqq, a, b, c);
        }
        inline Error vpshab(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshab, a, b, c);
        }
        inline Error vpshab(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshab, a, b, c);
        }
        inline Error vpshab(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshab, a, b, c);
        }
        inline Error vpshad(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshad, a, b, c);
        }
        inline Error vpshad(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshad, a, b, c);
        }
        inline Error vpshad(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshad, a, b, c);
        }
        inline Error vpshaq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshaq, a, b, c);
        }
        inline Error vpshaq(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshaq, a, b, c);
        }
        inline Error vpshaq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshaq, a, b, c);
        }
        inline Error vpshaw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshaw, a, b, c);
        }
        inline Error vpshaw(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshaw, a, b, c);
        }
        inline Error vpshaw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshaw, a, b, c);
        }
        inline Error vpshlb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshlb, a, b, c);
        }
        inline Error vpshlb(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshlb, a, b, c);
        }
        inline Error vpshlb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshlb, a, b, c);
        }
        inline Error vpshld(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshld, a, b, c);
        }
        inline Error vpshld(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshld, a, b, c);
        }
        inline Error vpshld(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshld, a, b, c);
        }
        inline Error vpshldd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldd, a, b, c, d, e);
        }
        inline Error vpshldd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldd, a, b, c, d, e);
        }
        inline Error vpshldd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldd, a, b, c, d, e);
        }
        inline Error vpshldd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldd, a, b, c, d, e);
        }
        inline Error vpshldd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldd, a, b, c, d, e);
        }
        inline Error vpshldd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldd, a, b, c, d, e);
        }
        inline Error vpshldq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldq, a, b, c, d, e);
        }
        inline Error vpshldq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldq, a, b, c, d, e);
        }
        inline Error vpshldq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldq, a, b, c, d, e);
        }
        inline Error vpshldq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldq, a, b, c, d, e);
        }
        inline Error vpshldq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldq, a, b, c, d, e);
        }
        inline Error vpshldq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldq, a, b, c, d, e);
        }
        inline Error vpshldvd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshldvd, a, b, c, d);
        }
        inline Error vpshldvd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshldvd, a, b, c, d);
        }
        inline Error vpshldvd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshldvd, a, b, c, d);
        }
        inline Error vpshldvd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvd, a, b, c, d);
        }
        inline Error vpshldvd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvd, a, b, c, d);
        }
        inline Error vpshldvd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvd, a, b, c, d);
        }
        inline Error vpshldvq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshldvq, a, b, c, d);
        }
        inline Error vpshldvq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshldvq, a, b, c, d);
        }
        inline Error vpshldvq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshldvq, a, b, c, d);
        }
        inline Error vpshldvq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvq, a, b, c, d);
        }
        inline Error vpshldvq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvq, a, b, c, d);
        }
        inline Error vpshldvq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvq, a, b, c, d);
        }
        inline Error vpshldvw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshldvw, a, b, c, d);
        }
        inline Error vpshldvw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshldvw, a, b, c, d);
        }
        inline Error vpshldvw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshldvw, a, b, c, d);
        }
        inline Error vpshldvw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvw, a, b, c, d);
        }
        inline Error vpshldvw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvw, a, b, c, d);
        }
        inline Error vpshldvw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvw, a, b, c, d);
        }
        inline Error vpshldw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldw, a, b, c, d, e);
        }
        inline Error vpshldw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldw, a, b, c, d, e);
        }
        inline Error vpshldw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldw, a, b, c, d, e);
        }
        inline Error vpshldw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldw, a, b, c, d, e);
        }
        inline Error vpshldw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldw, a, b, c, d, e);
        }
        inline Error vpshldw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldw, a, b, c, d, e);
        }
        inline Error vpshlq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshlq, a, b, c);
        }
        inline Error vpshlq(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshlq, a, b, c);
        }
        inline Error vpshlq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshlq, a, b, c);
        }
        inline Error vpshlw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshlw, a, b, c);
        }
        inline Error vpshlw(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshlw, a, b, c);
        }
        inline Error vpshlw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshlw, a, b, c);
        }
        inline Error vpshrdd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdd, a, b, c, d, e);
        }
        inline Error vpshrdd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdd, a, b, c, d, e);
        }
        inline Error vpshrdd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdd, a, b, c, d, e);
        }
        inline Error vpshrdd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdd, a, b, c, d, e);
        }
        inline Error vpshrdd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdd, a, b, c, d, e);
        }
        inline Error vpshrdd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdd, a, b, c, d, e);
        }
        inline Error vpshrdq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdq, a, b, c, d, e);
        }
        inline Error vpshrdq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdq, a, b, c, d, e);
        }
        inline Error vpshrdq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdq, a, b, c, d, e);
        }
        inline Error vpshrdq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdq, a, b, c, d, e);
        }
        inline Error vpshrdq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdq, a, b, c, d, e);
        }
        inline Error vpshrdq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdq, a, b, c, d, e);
        }
        inline Error vpshrdvd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvd, a, b, c, d);
        }
        inline Error vpshrdvd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvd, a, b, c, d);
        }
        inline Error vpshrdvd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvd, a, b, c, d);
        }
        inline Error vpshrdvd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvd, a, b, c, d);
        }
        inline Error vpshrdvd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvd, a, b, c, d);
        }
        inline Error vpshrdvd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvd, a, b, c, d);
        }
        inline Error vpshrdvq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvq, a, b, c, d);
        }
        inline Error vpshrdvq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvq, a, b, c, d);
        }
        inline Error vpshrdvq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvq, a, b, c, d);
        }
        inline Error vpshrdvq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvq, a, b, c, d);
        }
        inline Error vpshrdvq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvq, a, b, c, d);
        }
        inline Error vpshrdvq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvq, a, b, c, d);
        }
        inline Error vpshrdvw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvw, a, b, c, d);
        }
        inline Error vpshrdvw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvw, a, b, c, d);
        }
        inline Error vpshrdvw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvw, a, b, c, d);
        }
        inline Error vpshrdvw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvw, a, b, c, d);
        }
        inline Error vpshrdvw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvw, a, b, c, d);
        }
        inline Error vpshrdvw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvw, a, b, c, d);
        }
        inline Error vpshrdw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdw, a, b, c, d, e);
        }
        inline Error vpshrdw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdw, a, b, c, d, e);
        }
        inline Error vpshrdw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdw, a, b, c, d, e);
        }
        inline Error vpshrdw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdw, a, b, c, d, e);
        }
        inline Error vpshrdw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdw, a, b, c, d, e);
        }
        inline Error vpshrdw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdw, a, b, c, d, e);
        }
        inline Error vpshufb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c);
        }
        inline Error vpshufb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c);
        }
        inline Error vpshufb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c);
        }
        inline Error vpshufb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c);
        }
        inline Error vpshufb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c, d);
        }
        inline Error vpshufb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c, d);
        }
        inline Error vpshufb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c, d);
        }
        inline Error vpshufb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c, d);
        }
        inline Error vpshufb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c, d);
        }
        inline Error vpshufb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c, d);
        }
        inline Error vpshufbitqmb(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshufbitqmb, a, b, c, d);
        }
        inline Error vpshufbitqmb(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshufbitqmb, a, b, c, d);
        }
        inline Error vpshufbitqmb(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshufbitqmb, a, b, c, d);
        }
        inline Error vpshufbitqmb(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshufbitqmb, a, b, c, d);
        }
        inline Error vpshufbitqmb(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshufbitqmb, a, b, c, d);
        }
        inline Error vpshufbitqmb(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshufbitqmb, a, b, c, d);
        }
        inline Error vpshufd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c);
        }
        inline Error vpshufd(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c);
        }
        inline Error vpshufd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c);
        }
        inline Error vpshufd(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c);
        }
        inline Error vpshufd(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c, d);
        }
        inline Error vpshufd(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c, d);
        }
        inline Error vpshufd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c, d);
        }
        inline Error vpshufd(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c, d);
        }
        inline Error vpshufd(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c, d);
        }
        inline Error vpshufd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c, d);
        }
        inline Error vpshufhw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c);
        }
        inline Error vpshufhw(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c);
        }
        inline Error vpshufhw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c);
        }
        inline Error vpshufhw(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c);
        }
        inline Error vpshufhw(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c, d);
        }
        inline Error vpshufhw(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c, d);
        }
        inline Error vpshufhw(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c, d);
        }
        inline Error vpshufhw(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c, d);
        }
        inline Error vpshufhw(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c, d);
        }
        inline Error vpshufhw(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c, d);
        }
        inline Error vpshuflw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c);
        }
        inline Error vpshuflw(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c);
        }
        inline Error vpshuflw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c);
        }
        inline Error vpshuflw(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c);
        }
        inline Error vpshuflw(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c, d);
        }
        inline Error vpshuflw(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c, d);
        }
        inline Error vpshuflw(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c, d);
        }
        inline Error vpshuflw(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c, d);
        }
        inline Error vpshuflw(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c, d);
        }
        inline Error vpshuflw(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c, d);
        }
        inline Error vpsignb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsignb, a, b, c);
        }
        inline Error vpsignb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsignb, a, b, c);
        }
        inline Error vpsignb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsignb, a, b, c);
        }
        inline Error vpsignb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsignb, a, b, c);
        }
        inline Error vpsignd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsignd, a, b, c);
        }
        inline Error vpsignd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsignd, a, b, c);
        }
        inline Error vpsignd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsignd, a, b, c);
        }
        inline Error vpsignd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsignd, a, b, c);
        }
        inline Error vpsignw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsignw, a, b, c);
        }
        inline Error vpsignw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsignw, a, b, c);
        }
        inline Error vpsignw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsignw, a, b, c);
        }
        inline Error vpsignw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsignw, a, b, c);
        }
        inline Error vpslld(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c);
        }
        inline Error vpslld(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c);
        }
        inline Error vpslld(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c);
        }
        inline Error vpslld(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c);
        }
        inline Error vpslld(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c);
        }
        inline Error vpslld(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c);
        }
        inline Error vpslld(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        inline Error vpslld(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        inline Error vpslld(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        inline Error vpslld(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        inline Error vpslld(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        inline Error vpslld(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        inline Error vpslld(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        inline Error vpslld(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        inline Error vpslld(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        inline Error vpslld(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        inline Error vpslld(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        inline Error vpslld(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        inline Error vpslldq(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslldq, a, b, c);
        }
        inline Error vpslldq(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslldq, a, b, c);
        }
        inline Error vpslldq(const Zmm& a, const Zmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslldq, a, b, c);
        }
        inline Error vpslldq(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslldq, a, b, c);
        }
        inline Error vpslldq(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslldq, a, b, c);
        }
        inline Error vpslldq(const Zmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslldq, a, b, c);
        }
        inline Error vpsllq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c);
        }
        inline Error vpsllq(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c);
        }
        inline Error vpsllq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c);
        }
        inline Error vpsllq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c);
        }
        inline Error vpsllq(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c);
        }
        inline Error vpsllq(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c);
        }
        inline Error vpsllq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        inline Error vpsllq(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        inline Error vpsllq(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        inline Error vpsllq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        inline Error vpsllq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        inline Error vpsllq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        inline Error vpsllq(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        inline Error vpsllq(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        inline Error vpsllq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        inline Error vpsllq(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        inline Error vpsllq(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        inline Error vpsllq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        inline Error vpsllvd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c);
        }
        inline Error vpsllvd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c);
        }
        inline Error vpsllvd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c);
        }
        inline Error vpsllvd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c);
        }
        inline Error vpsllvd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c, d);
        }
        inline Error vpsllvd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c, d);
        }
        inline Error vpsllvd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c, d);
        }
        inline Error vpsllvd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c, d);
        }
        inline Error vpsllvd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c, d);
        }
        inline Error vpsllvd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c, d);
        }
        inline Error vpsllvq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c);
        }
        inline Error vpsllvq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c);
        }
        inline Error vpsllvq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c);
        }
        inline Error vpsllvq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c);
        }
        inline Error vpsllvq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c, d);
        }
        inline Error vpsllvq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c, d);
        }
        inline Error vpsllvq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c, d);
        }
        inline Error vpsllvq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c, d);
        }
        inline Error vpsllvq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c, d);
        }
        inline Error vpsllvq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c, d);
        }
        inline Error vpsllvw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllvw, a, b, c, d);
        }
        inline Error vpsllvw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsllvw, a, b, c, d);
        }
        inline Error vpsllvw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsllvw, a, b, c, d);
        }
        inline Error vpsllvw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvw, a, b, c, d);
        }
        inline Error vpsllvw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvw, a, b, c, d);
        }
        inline Error vpsllvw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvw, a, b, c, d);
        }
        inline Error vpsllw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c);
        }
        inline Error vpsllw(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c);
        }
        inline Error vpsllw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c);
        }
        inline Error vpsllw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c);
        }
        inline Error vpsllw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c);
        }
        inline Error vpsllw(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c);
        }
        inline Error vpsllw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        inline Error vpsllw(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        inline Error vpsllw(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        inline Error vpsllw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        inline Error vpsllw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        inline Error vpsllw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        inline Error vpsllw(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        inline Error vpsllw(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        inline Error vpsllw(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        inline Error vpsllw(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        inline Error vpsllw(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        inline Error vpsllw(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        inline Error vpsrad(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c);
        }
        inline Error vpsrad(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c);
        }
        inline Error vpsrad(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c);
        }
        inline Error vpsrad(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c);
        }
        inline Error vpsrad(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c);
        }
        inline Error vpsrad(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c);
        }
        inline Error vpsrad(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        inline Error vpsrad(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        inline Error vpsrad(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        inline Error vpsrad(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        inline Error vpsrad(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        inline Error vpsrad(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        inline Error vpsrad(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        inline Error vpsrad(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        inline Error vpsrad(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        inline Error vpsrad(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        inline Error vpsrad(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        inline Error vpsrad(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        inline Error vpsraq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        inline Error vpsraq(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        inline Error vpsraq(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        inline Error vpsraq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        inline Error vpsraq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        inline Error vpsraq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        inline Error vpsraq(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        inline Error vpsraq(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        inline Error vpsraq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        inline Error vpsraq(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        inline Error vpsraq(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        inline Error vpsraq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        inline Error vpsravd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c);
        }
        inline Error vpsravd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c);
        }
        inline Error vpsravd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c);
        }
        inline Error vpsravd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c);
        }
        inline Error vpsravd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c, d);
        }
        inline Error vpsravd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c, d);
        }
        inline Error vpsravd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c, d);
        }
        inline Error vpsravd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c, d);
        }
        inline Error vpsravd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c, d);
        }
        inline Error vpsravd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c, d);
        }
        inline Error vpsravq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsravq, a, b, c, d);
        }
        inline Error vpsravq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsravq, a, b, c, d);
        }
        inline Error vpsravq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsravq, a, b, c, d);
        }
        inline Error vpsravq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravq, a, b, c, d);
        }
        inline Error vpsravq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravq, a, b, c, d);
        }
        inline Error vpsravq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravq, a, b, c, d);
        }
        inline Error vpsravw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsravw, a, b, c, d);
        }
        inline Error vpsravw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsravw, a, b, c, d);
        }
        inline Error vpsravw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsravw, a, b, c, d);
        }
        inline Error vpsravw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravw, a, b, c, d);
        }
        inline Error vpsravw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravw, a, b, c, d);
        }
        inline Error vpsravw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravw, a, b, c, d);
        }
        inline Error vpsraw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c);
        }
        inline Error vpsraw(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c);
        }
        inline Error vpsraw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c);
        }
        inline Error vpsraw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c);
        }
        inline Error vpsraw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c);
        }
        inline Error vpsraw(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c);
        }
        inline Error vpsraw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        inline Error vpsraw(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        inline Error vpsraw(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        inline Error vpsraw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        inline Error vpsraw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        inline Error vpsraw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        inline Error vpsraw(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        inline Error vpsraw(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        inline Error vpsraw(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        inline Error vpsraw(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        inline Error vpsraw(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        inline Error vpsraw(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        inline Error vpsrld(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c);
        }
        inline Error vpsrld(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c);
        }
        inline Error vpsrld(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c);
        }
        inline Error vpsrld(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c);
        }
        inline Error vpsrld(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c);
        }
        inline Error vpsrld(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c);
        }
        inline Error vpsrld(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        inline Error vpsrld(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        inline Error vpsrld(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        inline Error vpsrld(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        inline Error vpsrld(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        inline Error vpsrld(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        inline Error vpsrld(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        inline Error vpsrld(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        inline Error vpsrld(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        inline Error vpsrld(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        inline Error vpsrld(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        inline Error vpsrld(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        inline Error vpsrldq(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrldq, a, b, c);
        }
        inline Error vpsrldq(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrldq, a, b, c);
        }
        inline Error vpsrldq(const Zmm& a, const Zmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrldq, a, b, c);
        }
        inline Error vpsrldq(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrldq, a, b, c);
        }
        inline Error vpsrldq(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrldq, a, b, c);
        }
        inline Error vpsrldq(const Zmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrldq, a, b, c);
        }
        inline Error vpsrlq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c);
        }
        inline Error vpsrlq(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c);
        }
        inline Error vpsrlq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c);
        }
        inline Error vpsrlq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c);
        }
        inline Error vpsrlq(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c);
        }
        inline Error vpsrlq(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c);
        }
        inline Error vpsrlq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        inline Error vpsrlq(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        inline Error vpsrlq(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        inline Error vpsrlq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        inline Error vpsrlq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        inline Error vpsrlq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        inline Error vpsrlq(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        inline Error vpsrlq(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        inline Error vpsrlq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        inline Error vpsrlq(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        inline Error vpsrlq(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        inline Error vpsrlq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        inline Error vpsrlvd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c);
        }
        inline Error vpsrlvd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c);
        }
        inline Error vpsrlvd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c);
        }
        inline Error vpsrlvd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c);
        }
        inline Error vpsrlvd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c, d);
        }
        inline Error vpsrlvd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c, d);
        }
        inline Error vpsrlvd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c, d);
        }
        inline Error vpsrlvd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c, d);
        }
        inline Error vpsrlvd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c, d);
        }
        inline Error vpsrlvd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c, d);
        }
        inline Error vpsrlvq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c);
        }
        inline Error vpsrlvq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c);
        }
        inline Error vpsrlvq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c);
        }
        inline Error vpsrlvq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c);
        }
        inline Error vpsrlvq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c, d);
        }
        inline Error vpsrlvq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c, d);
        }
        inline Error vpsrlvq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c, d);
        }
        inline Error vpsrlvq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c, d);
        }
        inline Error vpsrlvq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c, d);
        }
        inline Error vpsrlvq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c, d);
        }
        inline Error vpsrlvw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvw, a, b, c, d);
        }
        inline Error vpsrlvw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvw, a, b, c, d);
        }
        inline Error vpsrlvw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvw, a, b, c, d);
        }
        inline Error vpsrlvw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvw, a, b, c, d);
        }
        inline Error vpsrlvw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvw, a, b, c, d);
        }
        inline Error vpsrlvw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvw, a, b, c, d);
        }
        inline Error vpsrlw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c);
        }
        inline Error vpsrlw(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c);
        }
        inline Error vpsrlw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c);
        }
        inline Error vpsrlw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c);
        }
        inline Error vpsrlw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c);
        }
        inline Error vpsrlw(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c);
        }
        inline Error vpsrlw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        inline Error vpsrlw(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        inline Error vpsrlw(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        inline Error vpsrlw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        inline Error vpsrlw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        inline Error vpsrlw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        inline Error vpsrlw(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        inline Error vpsrlw(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        inline Error vpsrlw(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        inline Error vpsrlw(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        inline Error vpsrlw(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        inline Error vpsrlw(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        inline Error vpsubb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c);
        }
        inline Error vpsubb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c);
        }
        inline Error vpsubb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c);
        }
        inline Error vpsubb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c);
        }
        inline Error vpsubb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c, d);
        }
        inline Error vpsubb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c, d);
        }
        inline Error vpsubb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c, d);
        }
        inline Error vpsubb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c, d);
        }
        inline Error vpsubb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c, d);
        }
        inline Error vpsubb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c, d);
        }
        inline Error vpsubd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c);
        }
        inline Error vpsubd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c);
        }
        inline Error vpsubd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c);
        }
        inline Error vpsubd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c);
        }
        inline Error vpsubd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c, d);
        }
        inline Error vpsubd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c, d);
        }
        inline Error vpsubd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c, d);
        }
        inline Error vpsubd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c, d);
        }
        inline Error vpsubd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c, d);
        }
        inline Error vpsubd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c, d);
        }
        inline Error vpsubq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c);
        }
        inline Error vpsubq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c);
        }
        inline Error vpsubq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c);
        }
        inline Error vpsubq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c);
        }
        inline Error vpsubq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c, d);
        }
        inline Error vpsubq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c, d);
        }
        inline Error vpsubq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c, d);
        }
        inline Error vpsubq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c, d);
        }
        inline Error vpsubq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c, d);
        }
        inline Error vpsubq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c, d);
        }
        inline Error vpsubrd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubrd, a, b, c, d);
        }
        inline Error vpsubrd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubrd, a, b, c, d);
        }
        inline Error vpsubrsetbd(const Zmm& a, const Mask& b, const Mask& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubrsetbd, a, b, c, d);
        }
        inline Error vpsubrsetbd(const Zmm& a, const Mask& b, const Mask& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubrsetbd, a, b, c, d);
        }
        inline Error vpsubsb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c);
        }
        inline Error vpsubsb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c);
        }
        inline Error vpsubsb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c);
        }
        inline Error vpsubsb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c);
        }
        inline Error vpsubsb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c, d);
        }
        inline Error vpsubsb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c, d);
        }
        inline Error vpsubsb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c, d);
        }
        inline Error vpsubsb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c, d);
        }
        inline Error vpsubsb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c, d);
        }
        inline Error vpsubsb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c, d);
        }
        inline Error vpsubsetbd(const Zmm& a, const Mask& b, const Mask& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubsetbd, a, b, c, d);
        }
        inline Error vpsubsetbd(const Zmm& a, const Mask& b, const Mask& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsetbd, a, b, c, d);
        }
        inline Error vpsubsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c);
        }
        inline Error vpsubsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c);
        }
        inline Error vpsubsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c);
        }
        inline Error vpsubsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c);
        }
        inline Error vpsubsw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c, d);
        }
        inline Error vpsubsw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c, d);
        }
        inline Error vpsubsw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c, d);
        }
        inline Error vpsubsw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c, d);
        }
        inline Error vpsubsw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c, d);
        }
        inline Error vpsubsw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c, d);
        }
        inline Error vpsubusb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c);
        }
        inline Error vpsubusb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c);
        }
        inline Error vpsubusb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c);
        }
        inline Error vpsubusb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c);
        }
        inline Error vpsubusb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c, d);
        }
        inline Error vpsubusb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c, d);
        }
        inline Error vpsubusb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c, d);
        }
        inline Error vpsubusb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c, d);
        }
        inline Error vpsubusb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c, d);
        }
        inline Error vpsubusb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c, d);
        }
        inline Error vpsubusw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c);
        }
        inline Error vpsubusw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c);
        }
        inline Error vpsubusw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c);
        }
        inline Error vpsubusw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c);
        }
        inline Error vpsubusw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c, d);
        }
        inline Error vpsubusw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c, d);
        }
        inline Error vpsubusw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c, d);
        }
        inline Error vpsubusw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c, d);
        }
        inline Error vpsubusw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c, d);
        }
        inline Error vpsubusw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c, d);
        }
        inline Error vpsubw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c);
        }
        inline Error vpsubw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c);
        }
        inline Error vpsubw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c);
        }
        inline Error vpsubw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c);
        }
        inline Error vpsubw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c, d);
        }
        inline Error vpsubw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c, d);
        }
        inline Error vpsubw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c, d);
        }
        inline Error vpsubw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c, d);
        }
        inline Error vpsubw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c, d);
        }
        inline Error vpsubw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c, d);
        }
        inline Error vpternlogd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogd, a, b, c, d, e);
        }
        inline Error vpternlogd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogd, a, b, c, d, e);
        }
        inline Error vpternlogd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogd, a, b, c, d, e);
        }
        inline Error vpternlogd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogd, a, b, c, d, e);
        }
        inline Error vpternlogd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogd, a, b, c, d, e);
        }
        inline Error vpternlogd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogd, a, b, c, d, e);
        }
        inline Error vpternlogq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogq, a, b, c, d, e);
        }
        inline Error vpternlogq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogq, a, b, c, d, e);
        }
        inline Error vpternlogq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogq, a, b, c, d, e);
        }
        inline Error vpternlogq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogq, a, b, c, d, e);
        }
        inline Error vpternlogq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogq, a, b, c, d, e);
        }
        inline Error vpternlogq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogq, a, b, c, d, e);
        }
        inline Error vptest(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vptest, a, b);
        }
        inline Error vptest(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vptest, a, b);
        }
        inline Error vptest(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vptest, a, b);
        }
        inline Error vptest(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vptest, a, b);
        }
        inline Error vptestmb(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestmb, a, b, c, d);
        }
        inline Error vptestmb(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestmb, a, b, c, d);
        }
        inline Error vptestmb(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestmb, a, b, c, d);
        }
        inline Error vptestmb(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmb, a, b, c, d);
        }
        inline Error vptestmb(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmb, a, b, c, d);
        }
        inline Error vptestmb(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmb, a, b, c, d);
        }
        inline Error vptestmd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestmd, a, b, c, d);
        }
        inline Error vptestmd(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestmd, a, b, c, d);
        }
        inline Error vptestmd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestmd, a, b, c, d);
        }
        inline Error vptestmd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmd, a, b, c, d);
        }
        inline Error vptestmd(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmd, a, b, c, d);
        }
        inline Error vptestmd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmd, a, b, c, d);
        }
        inline Error vptestmq(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestmq, a, b, c, d);
        }
        inline Error vptestmq(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestmq, a, b, c, d);
        }
        inline Error vptestmq(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestmq, a, b, c, d);
        }
        inline Error vptestmq(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmq, a, b, c, d);
        }
        inline Error vptestmq(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmq, a, b, c, d);
        }
        inline Error vptestmq(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmq, a, b, c, d);
        }
        inline Error vptestmw(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestmw, a, b, c, d);
        }
        inline Error vptestmw(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestmw, a, b, c, d);
        }
        inline Error vptestmw(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestmw, a, b, c, d);
        }
        inline Error vptestmw(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmw, a, b, c, d);
        }
        inline Error vptestmw(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmw, a, b, c, d);
        }
        inline Error vptestmw(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmw, a, b, c, d);
        }
        inline Error vptestnmb(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmb, a, b, c, d);
        }
        inline Error vptestnmb(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestnmb, a, b, c, d);
        }
        inline Error vptestnmb(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmb, a, b, c, d);
        }
        inline Error vptestnmb(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmb, a, b, c, d);
        }
        inline Error vptestnmb(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmb, a, b, c, d);
        }
        inline Error vptestnmb(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmb, a, b, c, d);
        }
        inline Error vptestnmd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmd, a, b, c, d);
        }
        inline Error vptestnmd(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestnmd, a, b, c, d);
        }
        inline Error vptestnmd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmd, a, b, c, d);
        }
        inline Error vptestnmd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmd, a, b, c, d);
        }
        inline Error vptestnmd(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmd, a, b, c, d);
        }
        inline Error vptestnmd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmd, a, b, c, d);
        }
        inline Error vptestnmq(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmq, a, b, c, d);
        }
        inline Error vptestnmq(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestnmq, a, b, c, d);
        }
        inline Error vptestnmq(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmq, a, b, c, d);
        }
        inline Error vptestnmq(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmq, a, b, c, d);
        }
        inline Error vptestnmq(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmq, a, b, c, d);
        }
        inline Error vptestnmq(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmq, a, b, c, d);
        }
        inline Error vptestnmw(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmw, a, b, c, d);
        }
        inline Error vptestnmw(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestnmw, a, b, c, d);
        }
        inline Error vptestnmw(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmw, a, b, c, d);
        }
        inline Error vptestnmw(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmw, a, b, c, d);
        }
        inline Error vptestnmw(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmw, a, b, c, d);
        }
        inline Error vptestnmw(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmw, a, b, c, d);
        }
        inline Error vpunpckhbw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c);
        }
        inline Error vpunpckhbw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c);
        }
        inline Error vpunpckhbw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c);
        }
        inline Error vpunpckhbw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c);
        }
        inline Error vpunpckhbw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c, d);
        }
        inline Error vpunpckhbw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c, d);
        }
        inline Error vpunpckhbw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c, d);
        }
        inline Error vpunpckhbw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c, d);
        }
        inline Error vpunpckhbw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c, d);
        }
        inline Error vpunpckhbw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c, d);
        }
        inline Error vpunpckhdq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c);
        }
        inline Error vpunpckhdq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c);
        }
        inline Error vpunpckhdq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c);
        }
        inline Error vpunpckhdq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c);
        }
        inline Error vpunpckhdq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c, d);
        }
        inline Error vpunpckhdq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c, d);
        }
        inline Error vpunpckhdq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c, d);
        }
        inline Error vpunpckhdq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c, d);
        }
        inline Error vpunpckhdq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c, d);
        }
        inline Error vpunpckhdq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c, d);
        }
        inline Error vpunpckhqdq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c);
        }
        inline Error vpunpckhqdq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c);
        }
        inline Error vpunpckhqdq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c);
        }
        inline Error vpunpckhqdq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c);
        }
        inline Error vpunpckhqdq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c, d);
        }
        inline Error vpunpckhqdq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c, d);
        }
        inline Error vpunpckhqdq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c, d);
        }
        inline Error vpunpckhqdq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c, d);
        }
        inline Error vpunpckhqdq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c, d);
        }
        inline Error vpunpckhqdq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c, d);
        }
        inline Error vpunpckhwd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c);
        }
        inline Error vpunpckhwd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c);
        }
        inline Error vpunpckhwd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c);
        }
        inline Error vpunpckhwd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c);
        }
        inline Error vpunpckhwd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c, d);
        }
        inline Error vpunpckhwd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c, d);
        }
        inline Error vpunpckhwd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c, d);
        }
        inline Error vpunpckhwd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c, d);
        }
        inline Error vpunpckhwd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c, d);
        }
        inline Error vpunpckhwd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c, d);
        }
        inline Error vpunpcklbw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c);
        }
        inline Error vpunpcklbw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c);
        }
        inline Error vpunpcklbw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c);
        }
        inline Error vpunpcklbw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c);
        }
        inline Error vpunpcklbw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c, d);
        }
        inline Error vpunpcklbw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c, d);
        }
        inline Error vpunpcklbw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c, d);
        }
        inline Error vpunpcklbw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c, d);
        }
        inline Error vpunpcklbw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c, d);
        }
        inline Error vpunpcklbw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c, d);
        }
        inline Error vpunpckldq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c);
        }
        inline Error vpunpckldq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c);
        }
        inline Error vpunpckldq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c);
        }
        inline Error vpunpckldq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c);
        }
        inline Error vpunpckldq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c, d);
        }
        inline Error vpunpckldq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c, d);
        }
        inline Error vpunpckldq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c, d);
        }
        inline Error vpunpckldq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c, d);
        }
        inline Error vpunpckldq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c, d);
        }
        inline Error vpunpckldq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c, d);
        }
        inline Error vpunpcklqdq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c);
        }
        inline Error vpunpcklqdq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c);
        }
        inline Error vpunpcklqdq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c);
        }
        inline Error vpunpcklqdq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c);
        }
        inline Error vpunpcklqdq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c, d);
        }
        inline Error vpunpcklqdq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c, d);
        }
        inline Error vpunpcklqdq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c, d);
        }
        inline Error vpunpcklqdq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c, d);
        }
        inline Error vpunpcklqdq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c, d);
        }
        inline Error vpunpcklqdq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c, d);
        }
        inline Error vpunpcklwd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c);
        }
        inline Error vpunpcklwd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c);
        }
        inline Error vpunpcklwd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c);
        }
        inline Error vpunpcklwd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c);
        }
        inline Error vpunpcklwd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c, d);
        }
        inline Error vpunpcklwd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c, d);
        }
        inline Error vpunpcklwd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c, d);
        }
        inline Error vpunpcklwd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c, d);
        }
        inline Error vpunpcklwd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c, d);
        }
        inline Error vpunpcklwd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c, d);
        }
        inline Error vpxor(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpxor, a, b, c);
        }
        inline Error vpxor(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpxor, a, b, c);
        }
        inline Error vpxor(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpxor, a, b, c);
        }
        inline Error vpxor(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpxor, a, b, c);
        }
        inline Error vpxord(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpxord, a, b, c, d);
        }
        inline Error vpxord(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpxord, a, b, c, d);
        }
        inline Error vpxord(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpxord, a, b, c, d);
        }
        inline Error vpxord(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpxord, a, b, c, d);
        }
        inline Error vpxord(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpxord, a, b, c, d);
        }
        inline Error vpxord(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpxord, a, b, c, d);
        }
        inline Error vpxorq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpxorq, a, b, c, d);
        }
        inline Error vpxorq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpxorq, a, b, c, d);
        }
        inline Error vpxorq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpxorq, a, b, c, d);
        }
        inline Error vpxorq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpxorq, a, b, c, d);
        }
        inline Error vpxorq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpxorq, a, b, c, d);
        }
        inline Error vpxorq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpxorq, a, b, c, d);
        }
        inline Error vrangepd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangepd, a, b, c, d, e);
        }
        inline Error vrangepd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangepd, a, b, c, d, e);
        }
        inline Error vrangepd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangepd, a, b, c, d, e);
        }
        inline Error vrangepd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangepd, a, b, c, d, e);
        }
        inline Error vrangepd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangepd, a, b, c, d, e);
        }
        inline Error vrangepd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangepd, a, b, c, d, e);
        }
        inline Error vrangeps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangeps, a, b, c, d, e);
        }
        inline Error vrangeps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangeps, a, b, c, d, e);
        }
        inline Error vrangeps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangeps, a, b, c, d, e);
        }
        inline Error vrangeps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangeps, a, b, c, d, e);
        }
        inline Error vrangeps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangeps, a, b, c, d, e);
        }
        inline Error vrangeps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangeps, a, b, c, d, e);
        }
        inline Error vrangesd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangesd, a, b, c, d, e);
        }
        inline Error vrangesd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangesd, a, b, c, d, e);
        }
        inline Error vrangess(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangess, a, b, c, d, e);
        }
        inline Error vrangess(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangess, a, b, c, d, e);
        }
        inline Error vrcp14pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrcp14pd, a, b, c);
        }
        inline Error vrcp14pd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vrcp14pd, a, b, c);
        }
        inline Error vrcp14pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrcp14pd, a, b, c);
        }
        inline Error vrcp14pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp14pd, a, b, c);
        }
        inline Error vrcp14pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp14pd, a, b, c);
        }
        inline Error vrcp14pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp14pd, a, b, c);
        }
        inline Error vrcp14ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrcp14ps, a, b, c);
        }
        inline Error vrcp14ps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vrcp14ps, a, b, c);
        }
        inline Error vrcp14ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrcp14ps, a, b, c);
        }
        inline Error vrcp14ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp14ps, a, b, c);
        }
        inline Error vrcp14ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp14ps, a, b, c);
        }
        inline Error vrcp14ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp14ps, a, b, c);
        }
        inline Error vrcp14sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrcp14sd, a, b, c, d);
        }
        inline Error vrcp14sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrcp14sd, a, b, c, d);
        }
        inline Error vrcp14ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrcp14ss, a, b, c, d);
        }
        inline Error vrcp14ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrcp14ss, a, b, c, d);
        }
        inline Error vrcp23ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrcp23ps, a, b, c);
        }
        inline Error vrcp23ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp23ps, a, b, c);
        }
        inline Error vrcp28pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrcp28pd, a, b, c);
        }
        inline Error vrcp28pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp28pd, a, b, c);
        }
        inline Error vrcp28ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrcp28ps, a, b, c);
        }
        inline Error vrcp28ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp28ps, a, b, c);
        }
        inline Error vrcp28sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrcp28sd, a, b, c, d);
        }
        inline Error vrcp28sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrcp28sd, a, b, c, d);
        }
        inline Error vrcp28ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrcp28ss, a, b, c, d);
        }
        inline Error vrcp28ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrcp28ss, a, b, c, d);
        }
        inline Error vrcpph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrcpph, a, b, c);
        }
        inline Error vrcpph(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vrcpph, a, b, c);
        }
        inline Error vrcpph(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrcpph, a, b, c);
        }
        inline Error vrcpph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcpph, a, b, c);
        }
        inline Error vrcpph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcpph, a, b, c);
        }
        inline Error vrcpph(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcpph, a, b, c);
        }
        inline Error vrcpps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vrcpps, a, b);
        }
        inline Error vrcpps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vrcpps, a, b);
        }
        inline Error vrcpps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vrcpps, a, b);
        }
        inline Error vrcpps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vrcpps, a, b);
        }
        inline Error vrcpsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrcpsh, a, b, c, d);
        }
        inline Error vrcpsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrcpsh, a, b, c, d);
        }
        inline Error vrcpss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrcpss, a, b, c);
        }
        inline Error vrcpss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcpss, a, b, c);
        }
        inline Error vreducepd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreducepd, a, b, c, d);
        }
        inline Error vreducepd(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreducepd, a, b, c, d);
        }
        inline Error vreducepd(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreducepd, a, b, c, d);
        }
        inline Error vreducepd(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreducepd, a, b, c, d);
        }
        inline Error vreducepd(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreducepd, a, b, c, d);
        }
        inline Error vreducepd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreducepd, a, b, c, d);
        }
        inline Error vreduceph(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceph, a, b, c, d);
        }
        inline Error vreduceph(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceph, a, b, c, d);
        }
        inline Error vreduceph(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceph, a, b, c, d);
        }
        inline Error vreduceph(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceph, a, b, c, d);
        }
        inline Error vreduceph(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceph, a, b, c, d);
        }
        inline Error vreduceph(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceph, a, b, c, d);
        }
        inline Error vreduceps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceps, a, b, c, d);
        }
        inline Error vreduceps(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceps, a, b, c, d);
        }
        inline Error vreduceps(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceps, a, b, c, d);
        }
        inline Error vreduceps(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceps, a, b, c, d);
        }
        inline Error vreduceps(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceps, a, b, c, d);
        }
        inline Error vreduceps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceps, a, b, c, d);
        }
        inline Error vreducesd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vreducesd, a, b, c, d, e);
        }
        inline Error vreducesd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vreducesd, a, b, c, d, e);
        }
        inline Error vreducesh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vreducesh, a, b, c, d, e);
        }
        inline Error vreducesh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vreducesh, a, b, c, d, e);
        }
        inline Error vreducess(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vreducess, a, b, c, d, e);
        }
        inline Error vreducess(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vreducess, a, b, c, d, e);
        }
        inline Error vrndfxpntpd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndfxpntpd, a, b, c, d);
        }
        inline Error vrndfxpntpd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndfxpntpd, a, b, c, d);
        }
        inline Error vrndfxpntps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndfxpntps, a, b, c, d);
        }
        inline Error vrndfxpntps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndfxpntps, a, b, c, d);
        }
        inline Error vrndscalepd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscalepd, a, b, c, d);
        }
        inline Error vrndscalepd(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscalepd, a, b, c, d);
        }
        inline Error vrndscalepd(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscalepd, a, b, c, d);
        }
        inline Error vrndscalepd(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscalepd, a, b, c, d);
        }
        inline Error vrndscalepd(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscalepd, a, b, c, d);
        }
        inline Error vrndscalepd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscalepd, a, b, c, d);
        }
        inline Error vrndscaleph(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleph, a, b, c, d);
        }
        inline Error vrndscaleph(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleph, a, b, c, d);
        }
        inline Error vrndscaleph(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleph, a, b, c, d);
        }
        inline Error vrndscaleph(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleph, a, b, c, d);
        }
        inline Error vrndscaleph(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleph, a, b, c, d);
        }
        inline Error vrndscaleph(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleph, a, b, c, d);
        }
        inline Error vrndscaleps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleps, a, b, c, d);
        }
        inline Error vrndscaleps(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleps, a, b, c, d);
        }
        inline Error vrndscaleps(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleps, a, b, c, d);
        }
        inline Error vrndscaleps(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleps, a, b, c, d);
        }
        inline Error vrndscaleps(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleps, a, b, c, d);
        }
        inline Error vrndscaleps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleps, a, b, c, d);
        }
        inline Error vrndscalesd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrndscalesd, a, b, c, d, e);
        }
        inline Error vrndscalesd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrndscalesd, a, b, c, d, e);
        }
        inline Error vrndscalesh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrndscalesh, a, b, c, d, e);
        }
        inline Error vrndscalesh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrndscalesh, a, b, c, d, e);
        }
        inline Error vrndscaless(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrndscaless, a, b, c, d, e);
        }
        inline Error vrndscaless(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrndscaless, a, b, c, d, e);
        }
        inline Error vroundpd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundpd, a, b, c);
        }
        inline Error vroundpd(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundpd, a, b, c);
        }
        inline Error vroundpd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundpd, a, b, c);
        }
        inline Error vroundpd(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundpd, a, b, c);
        }
        inline Error vroundps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundps, a, b, c);
        }
        inline Error vroundps(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundps, a, b, c);
        }
        inline Error vroundps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundps, a, b, c);
        }
        inline Error vroundps(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundps, a, b, c);
        }
        inline Error vroundsd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vroundsd, a, b, c, d);
        }
        inline Error vroundsd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vroundsd, a, b, c, d);
        }
        inline Error vroundss(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vroundss, a, b, c, d);
        }
        inline Error vroundss(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vroundss, a, b, c, d);
        }
        inline Error vrsqrt14pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14pd, a, b, c);
        }
        inline Error vrsqrt14pd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14pd, a, b, c);
        }
        inline Error vrsqrt14pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14pd, a, b, c);
        }
        inline Error vrsqrt14pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14pd, a, b, c);
        }
        inline Error vrsqrt14pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14pd, a, b, c);
        }
        inline Error vrsqrt14pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14pd, a, b, c);
        }
        inline Error vrsqrt14ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14ps, a, b, c);
        }
        inline Error vrsqrt14ps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14ps, a, b, c);
        }
        inline Error vrsqrt14ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14ps, a, b, c);
        }
        inline Error vrsqrt14ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14ps, a, b, c);
        }
        inline Error vrsqrt14ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14ps, a, b, c);
        }
        inline Error vrsqrt14ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14ps, a, b, c);
        }
        inline Error vrsqrt14sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrsqrt14sd, a, b, c, d);
        }
        inline Error vrsqrt14sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrsqrt14sd, a, b, c, d);
        }
        inline Error vrsqrt14ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrsqrt14ss, a, b, c, d);
        }
        inline Error vrsqrt14ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrsqrt14ss, a, b, c, d);
        }
        inline Error vrsqrt23ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt23ps, a, b, c);
        }
        inline Error vrsqrt23ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt23ps, a, b, c);
        }
        inline Error vrsqrt28pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt28pd, a, b, c);
        }
        inline Error vrsqrt28pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt28pd, a, b, c);
        }
        inline Error vrsqrt28ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt28ps, a, b, c);
        }
        inline Error vrsqrt28ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt28ps, a, b, c);
        }
        inline Error vrsqrt28sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrsqrt28sd, a, b, c, d);
        }
        inline Error vrsqrt28sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrsqrt28sd, a, b, c, d);
        }
        inline Error vrsqrt28ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrsqrt28ss, a, b, c, d);
        }
        inline Error vrsqrt28ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrsqrt28ss, a, b, c, d);
        }
        inline Error vrsqrtph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrtph, a, b, c);
        }
        inline Error vrsqrtph(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vrsqrtph, a, b, c);
        }
        inline Error vrsqrtph(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrtph, a, b, c);
        }
        inline Error vrsqrtph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrtph, a, b, c);
        }
        inline Error vrsqrtph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrtph, a, b, c);
        }
        inline Error vrsqrtph(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrtph, a, b, c);
        }
        inline Error vrsqrtps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vrsqrtps, a, b);
        }
        inline Error vrsqrtps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vrsqrtps, a, b);
        }
        inline Error vrsqrtps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vrsqrtps, a, b);
        }
        inline Error vrsqrtps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vrsqrtps, a, b);
        }
        inline Error vrsqrtsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrsqrtsh, a, b, c, d);
        }
        inline Error vrsqrtsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrsqrtsh, a, b, c, d);
        }
        inline Error vrsqrtss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrtss, a, b, c);
        }
        inline Error vrsqrtss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrtss, a, b, c);
        }
        inline Error vscalefpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vscalefpd, a, b, c, d);
        }
        inline Error vscalefpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vscalefpd, a, b, c, d);
        }
        inline Error vscalefpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vscalefpd, a, b, c, d);
        }
        inline Error vscalefpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefpd, a, b, c, d);
        }
        inline Error vscalefpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefpd, a, b, c, d);
        }
        inline Error vscalefpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefpd, a, b, c, d);
        }
        inline Error vscalefph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vscalefph, a, b, c, d);
        }
        inline Error vscalefph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vscalefph, a, b, c, d);
        }
        inline Error vscalefph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vscalefph, a, b, c, d);
        }
        inline Error vscalefph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefph, a, b, c, d);
        }
        inline Error vscalefph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefph, a, b, c, d);
        }
        inline Error vscalefph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefph, a, b, c, d);
        }
        inline Error vscalefps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vscalefps, a, b, c, d);
        }
        inline Error vscalefps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vscalefps, a, b, c, d);
        }
        inline Error vscalefps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vscalefps, a, b, c, d);
        }
        inline Error vscalefps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefps, a, b, c, d);
        }
        inline Error vscalefps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefps, a, b, c, d);
        }
        inline Error vscalefps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefps, a, b, c, d);
        }
        inline Error vscalefsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vscalefsd, a, b, c, d);
        }
        inline Error vscalefsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefsd, a, b, c, d);
        }
        inline Error vscalefsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vscalefsh, a, b, c, d);
        }
        inline Error vscalefsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefsh, a, b, c, d);
        }
        inline Error vscalefss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vscalefss, a, b, c, d);
        }
        inline Error vscalefss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefss, a, b, c, d);
        }
        inline Error vscaleps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vscaleps, a, b, c, d);
        }
        inline Error vscaleps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscaleps, a, b, c, d);
        }
        inline Error vscatterdpd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vscatterdpd, a, b, c);
        }
        inline Error vscatterdpd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vscatterdpd, a, b, c);
        }
        inline Error vscatterdpd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vscatterdpd, a, b, c);
        }
        inline Error vscatterdps(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vscatterdps, a, b, c);
        }
        inline Error vscatterdps(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vscatterdps, a, b, c);
        }
        inline Error vscatterdps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vscatterdps, a, b, c);
        }
        inline Error vscatterpf0dpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf0dpd, a, b);
        }
        inline Error vscatterpf0dps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf0dps, a, b);
        }
        inline Error vscatterpf0hintdpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf0hintdpd, a, b);
        }
        inline Error vscatterpf0hintdps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf0hintdps, a, b);
        }
        inline Error vscatterpf0qpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf0qpd, a, b);
        }
        inline Error vscatterpf0qps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf0qps, a, b);
        }
        inline Error vscatterpf1dpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf1dpd, a, b);
        }
        inline Error vscatterpf1dps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf1dps, a, b);
        }
        inline Error vscatterpf1qpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf1qpd, a, b);
        }
        inline Error vscatterpf1qps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf1qps, a, b);
        }
        inline Error vscatterqpd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vscatterqpd, a, b, c);
        }
        inline Error vscatterqpd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vscatterqpd, a, b, c);
        }
        inline Error vscatterqpd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vscatterqpd, a, b, c);
        }
        inline Error vscatterqps(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vscatterqps, a, b, c);
        }
        inline Error vscatterqps(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vscatterqps, a, b, c);
        }
        inline Error vshuff32x4(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff32x4, a, b, c, d, e);
        }
        inline Error vshuff32x4(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff32x4, a, b, c, d, e);
        }
        inline Error vshuff32x4(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff32x4, a, b, c, d, e);
        }
        inline Error vshuff32x4(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff32x4, a, b, c, d, e);
        }
        inline Error vshuff64x2(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff64x2, a, b, c, d, e);
        }
        inline Error vshuff64x2(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff64x2, a, b, c, d, e);
        }
        inline Error vshuff64x2(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff64x2, a, b, c, d, e);
        }
        inline Error vshuff64x2(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff64x2, a, b, c, d, e);
        }
        inline Error vshufi32x4(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi32x4, a, b, c, d, e);
        }
        inline Error vshufi32x4(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi32x4, a, b, c, d, e);
        }
        inline Error vshufi32x4(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi32x4, a, b, c, d, e);
        }
        inline Error vshufi32x4(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi32x4, a, b, c, d, e);
        }
        inline Error vshufi64x2(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi64x2, a, b, c, d, e);
        }
        inline Error vshufi64x2(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi64x2, a, b, c, d, e);
        }
        inline Error vshufi64x2(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi64x2, a, b, c, d, e);
        }
        inline Error vshufi64x2(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi64x2, a, b, c, d, e);
        }
        inline Error vshufpd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d);
        }
        inline Error vshufpd(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d);
        }
        inline Error vshufpd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d);
        }
        inline Error vshufpd(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d);
        }
        inline Error vshufpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d, e);
        }
        inline Error vshufpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d, e);
        }
        inline Error vshufpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d, e);
        }
        inline Error vshufpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d, e);
        }
        inline Error vshufpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d, e);
        }
        inline Error vshufpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d, e);
        }
        inline Error vshufps(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d);
        }
        inline Error vshufps(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d);
        }
        inline Error vshufps(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d);
        }
        inline Error vshufps(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d);
        }
        inline Error vshufps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d, e);
        }
        inline Error vshufps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d, e);
        }
        inline Error vshufps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d, e);
        }
        inline Error vshufps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d, e);
        }
        inline Error vshufps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d, e);
        }
        inline Error vshufps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d, e);
        }
        inline Error vsqrtpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b);
        }
        inline Error vsqrtpd(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b);
        }
        inline Error vsqrtpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b);
        }
        inline Error vsqrtpd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b);
        }
        inline Error vsqrtpd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b, c);
        }
        inline Error vsqrtpd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b, c);
        }
        inline Error vsqrtpd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b, c);
        }
        inline Error vsqrtpd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b, c);
        }
        inline Error vsqrtpd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b, c);
        }
        inline Error vsqrtpd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b, c);
        }
        inline Error vsqrtph(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtph, a, b, c);
        }
        inline Error vsqrtph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtph, a, b, c);
        }
        inline Error vsqrtph(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vsqrtph, a, b, c);
        }
        inline Error vsqrtph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtph, a, b, c);
        }
        inline Error vsqrtph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtph, a, b, c);
        }
        inline Error vsqrtph(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtph, a, b, c);
        }
        inline Error vsqrtps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b);
        }
        inline Error vsqrtps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b);
        }
        inline Error vsqrtps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b);
        }
        inline Error vsqrtps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b);
        }
        inline Error vsqrtps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b, c);
        }
        inline Error vsqrtps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b, c);
        }
        inline Error vsqrtps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b, c);
        }
        inline Error vsqrtps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b, c);
        }
        inline Error vsqrtps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b, c);
        }
        inline Error vsqrtps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b, c);
        }
        inline Error vsqrtsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtsd, a, b, c);
        }
        inline Error vsqrtsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtsd, a, b, c);
        }
        inline Error vsqrtsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsqrtsd, a, b, c, d);
        }
        inline Error vsqrtsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsqrtsd, a, b, c, d);
        }
        inline Error vsqrtsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsqrtsh, a, b, c, d);
        }
        inline Error vsqrtsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsqrtsh, a, b, c, d);
        }
        inline Error vsqrtss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtss, a, b, c);
        }
        inline Error vsqrtss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtss, a, b, c);
        }
        inline Error vsqrtss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsqrtss, a, b, c, d);
        }
        inline Error vsqrtss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsqrtss, a, b, c, d);
        }
        inline Error vstmxcsr(const Mem& a)
        {
            return emit(x86::Mnemonic::Vstmxcsr, a);
        }
        inline Error vsubpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c);
        }
        inline Error vsubpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c);
        }
        inline Error vsubpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c);
        }
        inline Error vsubpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c);
        }
        inline Error vsubpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c, d);
        }
        inline Error vsubpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c, d);
        }
        inline Error vsubpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c, d);
        }
        inline Error vsubpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c, d);
        }
        inline Error vsubpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c, d);
        }
        inline Error vsubpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c, d);
        }
        inline Error vsubph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vsubph, a, b, c, d);
        }
        inline Error vsubph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsubph, a, b, c, d);
        }
        inline Error vsubph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vsubph, a, b, c, d);
        }
        inline Error vsubph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubph, a, b, c, d);
        }
        inline Error vsubph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubph, a, b, c, d);
        }
        inline Error vsubph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubph, a, b, c, d);
        }
        inline Error vsubps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c);
        }
        inline Error vsubps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c);
        }
        inline Error vsubps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c);
        }
        inline Error vsubps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c);
        }
        inline Error vsubps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c, d);
        }
        inline Error vsubps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c, d);
        }
        inline Error vsubps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c, d);
        }
        inline Error vsubps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c, d);
        }
        inline Error vsubps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c, d);
        }
        inline Error vsubps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c, d);
        }
        inline Error vsubrpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vsubrpd, a, b, c, d);
        }
        inline Error vsubrpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubrpd, a, b, c, d);
        }
        inline Error vsubrps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vsubrps, a, b, c, d);
        }
        inline Error vsubrps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubrps, a, b, c, d);
        }
        inline Error vsubsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsubsd, a, b, c);
        }
        inline Error vsubsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsubsd, a, b, c);
        }
        inline Error vsubsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsubsd, a, b, c, d);
        }
        inline Error vsubsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubsd, a, b, c, d);
        }
        inline Error vsubsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsubsh, a, b, c, d);
        }
        inline Error vsubsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubsh, a, b, c, d);
        }
        inline Error vsubss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsubss, a, b, c);
        }
        inline Error vsubss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsubss, a, b, c);
        }
        inline Error vsubss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsubss, a, b, c, d);
        }
        inline Error vsubss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubss, a, b, c, d);
        }
        inline Error vtestpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vtestpd, a, b);
        }
        inline Error vtestpd(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vtestpd, a, b);
        }
        inline Error vtestpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vtestpd, a, b);
        }
        inline Error vtestpd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vtestpd, a, b);
        }
        inline Error vtestps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vtestps, a, b);
        }
        inline Error vtestps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vtestps, a, b);
        }
        inline Error vtestps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vtestps, a, b);
        }
        inline Error vtestps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vtestps, a, b);
        }
        inline Error vucomisd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vucomisd, a, b);
        }
        inline Error vucomisd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vucomisd, a, b);
        }
        inline Error vucomish(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vucomish, a, b);
        }
        inline Error vucomish(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vucomish, a, b);
        }
        inline Error vucomiss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vucomiss, a, b);
        }
        inline Error vucomiss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vucomiss, a, b);
        }
        inline Error vunpckhpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c);
        }
        inline Error vunpckhpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c);
        }
        inline Error vunpckhpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c);
        }
        inline Error vunpckhpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c);
        }
        inline Error vunpckhpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c, d);
        }
        inline Error vunpckhpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c, d);
        }
        inline Error vunpckhpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c, d);
        }
        inline Error vunpckhpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c, d);
        }
        inline Error vunpckhpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c, d);
        }
        inline Error vunpckhpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c, d);
        }
        inline Error vunpckhps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c);
        }
        inline Error vunpckhps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c);
        }
        inline Error vunpckhps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c);
        }
        inline Error vunpckhps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c);
        }
        inline Error vunpckhps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c, d);
        }
        inline Error vunpckhps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c, d);
        }
        inline Error vunpckhps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c, d);
        }
        inline Error vunpckhps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c, d);
        }
        inline Error vunpckhps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c, d);
        }
        inline Error vunpckhps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c, d);
        }
        inline Error vunpcklpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c);
        }
        inline Error vunpcklpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c);
        }
        inline Error vunpcklpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c);
        }
        inline Error vunpcklpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c);
        }
        inline Error vunpcklpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c, d);
        }
        inline Error vunpcklpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c, d);
        }
        inline Error vunpcklpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c, d);
        }
        inline Error vunpcklpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c, d);
        }
        inline Error vunpcklpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c, d);
        }
        inline Error vunpcklpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c, d);
        }
        inline Error vunpcklps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c);
        }
        inline Error vunpcklps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c);
        }
        inline Error vunpcklps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c);
        }
        inline Error vunpcklps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c);
        }
        inline Error vunpcklps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c, d);
        }
        inline Error vunpcklps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c, d);
        }
        inline Error vunpcklps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c, d);
        }
        inline Error vunpcklps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c, d);
        }
        inline Error vunpcklps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c, d);
        }
        inline Error vunpcklps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c, d);
        }
        inline Error vxorpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c);
        }
        inline Error vxorpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c);
        }
        inline Error vxorpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c);
        }
        inline Error vxorpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c);
        }
        inline Error vxorpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c, d);
        }
        inline Error vxorpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c, d);
        }
        inline Error vxorpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c, d);
        }
        inline Error vxorpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c, d);
        }
        inline Error vxorpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c, d);
        }
        inline Error vxorpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c, d);
        }
        inline Error vxorps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c);
        }
        inline Error vxorps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c);
        }
        inline Error vxorps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c);
        }
        inline Error vxorps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c);
        }
        inline Error vxorps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c, d);
        }
        inline Error vxorps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c, d);
        }
        inline Error vxorps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c, d);
        }
        inline Error vxorps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c, d);
        }
        inline Error vxorps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c, d);
        }
        inline Error vxorps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c, d);
        }
        inline Error vzeroall()
        {
            return emit(x86::Mnemonic::Vzeroall);
        }
        inline Error vzeroupper()
        {
            return emit(x86::Mnemonic::Vzeroupper);
        }
        inline Error wbinvd()
        {
            return emit(x86::Mnemonic::Wbinvd);
        }
        inline Error wrfsbase(const Gp& a)
        {
            return emit(x86::Mnemonic::Wrfsbase, a);
        }
        inline Error wrgsbase(const Gp& a)
        {
            return emit(x86::Mnemonic::Wrgsbase, a);
        }
        inline Error wrmsr()
        {
            return emit(x86::Mnemonic::Wrmsr);
        }
        inline Error wrpkru()
        {
            return emit(x86::Mnemonic::Wrpkru);
        }
        inline Error wrssd(const Mem& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Wrssd, a, b);
        }
        inline Error wrssq(const Mem& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Wrssq, a, b);
        }
        inline Error wrussd(const Mem& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Wrussd, a, b);
        }
        inline Error wrussq(const Mem& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Wrussq, a, b);
        }
        inline Error xabort(const Imm& a)
        {
            return emit(x86::Mnemonic::Xabort, a);
        }
        inline Error xadd(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Xadd, a, b);
        }
        inline Error xadd(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Xadd, a, b);
        }
        inline Error xadd(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Xadd, a, b);
        }
        inline Error xadd(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Xadd, a, b);
        }
        inline Error xbegin(const Imm& a)
        {
            return emit(x86::Mnemonic::Xbegin, a);
        }
        inline Error xchg(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Xchg, a, b);
        }
        inline Error xchg(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Xchg, a, b);
        }
        inline Error xchg(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Xchg, a, b);
        }
        inline Error xchg(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Xchg, a, b);
        }
        inline Error xchg(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Xchg, b, a);
        }
        inline Error xcrypt_cbc()
        {
            return emit(x86::Mnemonic::Xcrypt_cbc);
        }
        inline Error xcrypt_cfb()
        {
            return emit(x86::Mnemonic::Xcrypt_cfb);
        }
        inline Error xcrypt_ctr()
        {
            return emit(x86::Mnemonic::Xcrypt_ctr);
        }
        inline Error xcrypt_ecb()
        {
            return emit(x86::Mnemonic::Xcrypt_ecb);
        }
        inline Error xcrypt_ofb()
        {
            return emit(x86::Mnemonic::Xcrypt_ofb);
        }
        inline Error xend()
        {
            return emit(x86::Mnemonic::Xend);
        }
        inline Error xgetbv()
        {
            return emit(x86::Mnemonic::Xgetbv);
        }
        inline Error xlat()
        {
            return emit(x86::Mnemonic::Xlat);
        }
        inline Error xor_(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        inline Error xor_(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        inline Error xor_(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        inline Error xor_(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        inline Error xor_(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        inline Error xor_(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        inline Error xor_(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        inline Error xor_(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        inline Error xor_(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        inline Error xorpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Xorpd, a, b);
        }
        inline Error xorpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Xorpd, a, b);
        }
        inline Error xorps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Xorps, a, b);
        }
        inline Error xorps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Xorps, a, b);
        }
        inline Error xresldtrk()
        {
            return emit(x86::Mnemonic::Xresldtrk);
        }
        inline Error xrstor(const Mem& a)
        {
            return emit(x86::Mnemonic::Xrstor, a);
        }
        inline Error xrstor64(const Mem& a)
        {
            return emit(x86::Mnemonic::Xrstor64, a);
        }
        inline Error xrstors(const Mem& a)
        {
            return emit(x86::Mnemonic::Xrstors, a);
        }
        inline Error xrstors64(const Mem& a)
        {
            return emit(x86::Mnemonic::Xrstors64, a);
        }
        inline Error xsave(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsave, a);
        }
        inline Error xsave64(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsave64, a);
        }
        inline Error xsavec(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsavec, a);
        }
        inline Error xsavec64(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsavec64, a);
        }
        inline Error xsaveopt(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsaveopt, a);
        }
        inline Error xsaveopt64(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsaveopt64, a);
        }
        inline Error xsaves(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsaves, a);
        }
        inline Error xsaves64(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsaves64, a);
        }
        inline Error xsetbv()
        {
            return emit(x86::Mnemonic::Xsetbv);
        }
        inline Error xsha1()
        {
            return emit(x86::Mnemonic::Xsha1);
        }
        inline Error xsha256()
        {
            return emit(x86::Mnemonic::Xsha256);
        }
        inline Error xstore()
        {
            return emit(x86::Mnemonic::Xstore);
        }
        inline Error xsusldtrk()
        {
            return emit(x86::Mnemonic::Xsusldtrk);
        }
        inline Error xtest()
        {
            return emit(x86::Mnemonic::Xtest);
        }
    };

} // namespace zasm::x86
