#pragma once

#include "instruction.hpp"
#include "register.hpp"

#include <zasm/core/errors.hpp>
#include <zasm/program/instruction.hpp>
#include <zasm/program/operand.hpp>

namespace zasm::x86
{
    template<typename T> class Emitter
    {
        template<typename... TArgs> Error emit(x86::Mnemonic id, TArgs&&... args)
        {
            auto& cls = static_cast<T&>(*this);
            return cls.emit(id, std::forward<TArgs>(args)...);
        }

    public:
        Error aaa()
        {
            return emit(x86::Mnemonic::Aaa);
        }
        Error aad(const Imm& a)
        {
            return emit(x86::Mnemonic::Aad, a);
        }
        Error aam(const Imm& a)
        {
            return emit(x86::Mnemonic::Aam, a);
        }
        Error aas()
        {
            return emit(x86::Mnemonic::Aas);
        }
        Error adc(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        Error adc(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        Error adc(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        Error adc(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        Error adc(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        Error adc(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        Error adc(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        Error adc(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        Error adc(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Adc, a, b);
        }
        Error adcx(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Adcx, a, b);
        }
        Error adcx(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Adcx, a, b);
        }
        Error adcx(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Adcx, a, b);
        }
        Error adcx(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Adcx, a, b);
        }
        Error add(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        Error add(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        Error add(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        Error add(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        Error add(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        Error add(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        Error add(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        Error add(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        Error add(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Add, a, b);
        }
        Error addpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Addpd, a, b);
        }
        Error addpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Addpd, a, b);
        }
        Error addps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Addps, a, b);
        }
        Error addps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Addps, a, b);
        }
        Error addsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Addsd, a, b);
        }
        Error addsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Addsd, a, b);
        }
        Error addss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Addss, a, b);
        }
        Error addss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Addss, a, b);
        }
        Error addsubpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Addsubpd, a, b);
        }
        Error addsubpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Addsubpd, a, b);
        }
        Error addsubps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Addsubps, a, b);
        }
        Error addsubps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Addsubps, a, b);
        }
        Error adox(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Adox, a, b);
        }
        Error adox(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Adox, a, b);
        }
        Error adox(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Adox, a, b);
        }
        Error adox(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Adox, a, b);
        }
        Error aesdec(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Aesdec, a, b);
        }
        Error aesdec(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesdec, a, b);
        }
        Error aesdec128kl(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesdec128kl, a, b);
        }
        Error aesdec256kl(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesdec256kl, a, b);
        }
        Error aesdeclast(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Aesdeclast, a, b);
        }
        Error aesdeclast(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesdeclast, a, b);
        }
        Error aesdecwide128kl(const Mem& a)
        {
            return emit(x86::Mnemonic::Aesdecwide128kl, a);
        }
        Error aesdecwide256kl(const Mem& a)
        {
            return emit(x86::Mnemonic::Aesdecwide256kl, a);
        }
        Error aesenc(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Aesenc, a, b);
        }
        Error aesenc(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesenc, a, b);
        }
        Error aesenc128kl(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesenc128kl, a, b);
        }
        Error aesenc256kl(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesenc256kl, a, b);
        }
        Error aesenclast(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Aesenclast, a, b);
        }
        Error aesenclast(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesenclast, a, b);
        }
        Error aesencwide128kl(const Mem& a)
        {
            return emit(x86::Mnemonic::Aesencwide128kl, a);
        }
        Error aesencwide256kl(const Mem& a)
        {
            return emit(x86::Mnemonic::Aesencwide256kl, a);
        }
        Error aesimc(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Aesimc, a, b);
        }
        Error aesimc(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Aesimc, a, b);
        }
        Error aeskeygenassist(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Aeskeygenassist, a, b, c);
        }
        Error aeskeygenassist(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Aeskeygenassist, a, b, c);
        }
        Error and_(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        Error and_(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        Error and_(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        Error and_(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        Error and_(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        Error and_(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        Error and_(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        Error and_(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        Error and_(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::And, a, b);
        }
        Error andn(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Andn, a, b, c);
        }
        Error andn(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Andn, a, b, c);
        }
        Error andn(const Gp32& a, const Gp32& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Andn, a, b, c);
        }
        Error andn(const Gp64& a, const Gp64& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Andn, a, b, c);
        }
        Error andnpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Andnpd, a, b);
        }
        Error andnpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Andnpd, a, b);
        }
        Error andnps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Andnps, a, b);
        }
        Error andnps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Andnps, a, b);
        }
        Error andpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Andpd, a, b);
        }
        Error andpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Andpd, a, b);
        }
        Error andps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Andps, a, b);
        }
        Error andps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Andps, a, b);
        }
        Error arpl(const Gp16& a, const Gp16& b)
        {
            return emit(x86::Mnemonic::Arpl, a, b);
        }
        Error arpl(const Mem& a, const Gp16& b)
        {
            return emit(x86::Mnemonic::Arpl, a, b);
        }
        Error bextr(const Gp& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Bextr, a, b, c);
        }
        Error bextr(const Gp& a, const Mem& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Bextr, a, b, c);
        }
        Error bextr(const Gp& a, const Gp& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Bextr, a, b, c);
        }
        Error bextr(const Gp& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Bextr, a, b, c);
        }
        Error blcfill(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blcfill, a, b);
        }
        Error blcfill(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blcfill, a, b);
        }
        Error blci(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blci, a, b);
        }
        Error blci(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blci, a, b);
        }
        Error blcic(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blcic, a, b);
        }
        Error blcic(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blcic, a, b);
        }
        Error blcmsk(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blcmsk, a, b);
        }
        Error blcmsk(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blcmsk, a, b);
        }
        Error blcs(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blcs, a, b);
        }
        Error blcs(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blcs, a, b);
        }
        Error blendpd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Blendpd, a, b, c);
        }
        Error blendpd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Blendpd, a, b, c);
        }
        Error blendps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Blendps, a, b, c);
        }
        Error blendps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Blendps, a, b, c);
        }
        Error blendvpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Blendvpd, a, b);
        }
        Error blendvpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blendvpd, a, b);
        }
        Error blendvps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Blendvps, a, b);
        }
        Error blendvps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blendvps, a, b);
        }
        Error blsfill(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blsfill, a, b);
        }
        Error blsfill(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blsfill, a, b);
        }
        Error blsi(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blsi, a, b);
        }
        Error blsi(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blsi, a, b);
        }
        Error blsic(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blsic, a, b);
        }
        Error blsic(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blsic, a, b);
        }
        Error blsmsk(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blsmsk, a, b);
        }
        Error blsmsk(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blsmsk, a, b);
        }
        Error blsr(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Blsr, a, b);
        }
        Error blsr(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Blsr, a, b);
        }
        Error bndcl(const Bnd& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Bndcl, a, b);
        }
        Error bndcl(const Bnd& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bndcl, a, b);
        }
        Error bndcl(const Bnd& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Bndcl, a, b);
        }
        Error bndcn(const Bnd& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Bndcn, a, b);
        }
        Error bndcn(const Bnd& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bndcn, a, b);
        }
        Error bndcn(const Bnd& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Bndcn, a, b);
        }
        Error bndcu(const Bnd& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Bndcu, a, b);
        }
        Error bndcu(const Bnd& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bndcu, a, b);
        }
        Error bndcu(const Bnd& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Bndcu, a, b);
        }
        Error bndldx(const Bnd& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bndldx, a, b);
        }
        Error bndmk(const Bnd& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bndmk, a, b);
        }
        Error bndmov(const Bnd& a, const Bnd& b)
        {
            return emit(x86::Mnemonic::Bndmov, a, b);
        }
        Error bndmov(const Bnd& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bndmov, a, b);
        }
        Error bndmov(const Mem& a, const Bnd& b)
        {
            return emit(x86::Mnemonic::Bndmov, a, b);
        }
        Error bndstx(const Mem& a, const Bnd& b)
        {
            return emit(x86::Mnemonic::Bndstx, a, b);
        }
        Error bound(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bound, a, b);
        }
        Error bsf(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Bsf, a, b);
        }
        Error bsf(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bsf, a, b);
        }
        Error bsr(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Bsr, a, b);
        }
        Error bsr(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Bsr, a, b);
        }
        Error bswap(const Gp& a)
        {
            return emit(x86::Mnemonic::Bswap, a);
        }
        Error bt(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Bt, a, b);
        }
        Error bt(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Bt, a, b);
        }
        Error bt(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Bt, a, b);
        }
        Error bt(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Bt, a, b);
        }
        Error btc(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Btc, a, b);
        }
        Error btc(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Btc, a, b);
        }
        Error btc(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Btc, a, b);
        }
        Error btc(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Btc, a, b);
        }
        Error btr(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Btr, a, b);
        }
        Error btr(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Btr, a, b);
        }
        Error btr(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Btr, a, b);
        }
        Error btr(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Btr, a, b);
        }
        Error bts(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Bts, a, b);
        }
        Error bts(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Bts, a, b);
        }
        Error bts(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Bts, a, b);
        }
        Error bts(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Bts, a, b);
        }
        Error bzhi(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Bzhi, a, b, c);
        }
        Error bzhi(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Bzhi, a, b, c);
        }
        Error bzhi(const Gp32& a, const Mem& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Bzhi, a, b, c);
        }
        Error bzhi(const Gp64& a, const Mem& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Bzhi, a, b, c);
        }
        Error call(const Gp& a)
        {
            return emit(x86::Mnemonic::Call, a);
        }
        Error call(const Mem& a)
        {
            return emit(x86::Mnemonic::Call, a);
        }
        Error call(const Imm& a)
        {
            return emit(x86::Mnemonic::Call, a);
        }
        Error call(const Label& a)
        {
            return emit(x86::Mnemonic::Call, a);
        }
        Error cbw()
        {
            return emit(x86::Mnemonic::Cbw);
        }
        Error cdq()
        {
            return emit(x86::Mnemonic::Cdq);
        }
        Error cdqe()
        {
            return emit(x86::Mnemonic::Cdqe);
        }
        Error clac()
        {
            return emit(x86::Mnemonic::Clac);
        }
        Error clc()
        {
            return emit(x86::Mnemonic::Clc);
        }
        Error cld()
        {
            return emit(x86::Mnemonic::Cld);
        }
        Error cldemote(const Mem& a)
        {
            return emit(x86::Mnemonic::Cldemote, a);
        }
        Error clevict0(const Mem& a)
        {
            return emit(x86::Mnemonic::Clevict0, a);
        }
        Error clevict1(const Mem& a)
        {
            return emit(x86::Mnemonic::Clevict1, a);
        }
        Error clflush(const Mem& a)
        {
            return emit(x86::Mnemonic::Clflush, a);
        }
        Error clflushopt(const Mem& a)
        {
            return emit(x86::Mnemonic::Clflushopt, a);
        }
        Error clgi()
        {
            return emit(x86::Mnemonic::Clgi);
        }
        Error cli()
        {
            return emit(x86::Mnemonic::Cli);
        }
        Error clrssbsy(const Mem& a)
        {
            return emit(x86::Mnemonic::Clrssbsy, a);
        }
        Error clts()
        {
            return emit(x86::Mnemonic::Clts);
        }
        Error clui()
        {
            return emit(x86::Mnemonic::Clui);
        }
        Error clwb(const Mem& a)
        {
            return emit(x86::Mnemonic::Clwb, a);
        }
        Error clzero(const Gp& a)
        {
            return emit(x86::Mnemonic::Clzero, a);
        }
        Error cmc()
        {
            return emit(x86::Mnemonic::Cmc);
        }
        Error cmovb(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovb, a, b);
        }
        Error cmovb(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovb, a, b);
        }
        Error cmovbe(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovbe, a, b);
        }
        Error cmovbe(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovbe, a, b);
        }
        Error cmovl(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovl, a, b);
        }
        Error cmovl(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovl, a, b);
        }
        Error cmovle(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovle, a, b);
        }
        Error cmovle(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovle, a, b);
        }
        Error cmovnb(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovnb, a, b);
        }
        Error cmovnb(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovnb, a, b);
        }
        Error cmovnbe(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovnbe, a, b);
        }
        Error cmovnbe(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovnbe, a, b);
        }
        Error cmovnl(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovnl, a, b);
        }
        Error cmovnl(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovnl, a, b);
        }
        Error cmovnle(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovnle, a, b);
        }
        Error cmovnle(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovnle, a, b);
        }
        Error cmovno(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovno, a, b);
        }
        Error cmovno(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovno, a, b);
        }
        Error cmovnp(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovnp, a, b);
        }
        Error cmovnp(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovnp, a, b);
        }
        Error cmovns(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovns, a, b);
        }
        Error cmovns(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovns, a, b);
        }
        Error cmovnz(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovnz, a, b);
        }
        Error cmovnz(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovnz, a, b);
        }
        Error cmovo(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovo, a, b);
        }
        Error cmovo(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovo, a, b);
        }
        Error cmovp(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovp, a, b);
        }
        Error cmovp(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovp, a, b);
        }
        Error cmovs(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovs, a, b);
        }
        Error cmovs(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovs, a, b);
        }
        Error cmovz(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmovz, a, b);
        }
        Error cmovz(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmovz, a, b);
        }
        Error cmp(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        Error cmp(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        Error cmp(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        Error cmp(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        Error cmp(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        Error cmp(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        Error cmp(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        Error cmp(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        Error cmp(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Cmp, a, b);
        }
        Error cmppd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmppd, a, b, c);
        }
        Error cmppd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmppd, a, b, c);
        }
        Error cmpps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmpps, a, b, c);
        }
        Error cmpps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmpps, a, b, c);
        }
        Error cmpsb()
        {
            return emit(x86::Mnemonic::Cmpsb);
        }
        Error cmpsd()
        {
            return emit(x86::Mnemonic::Cmpsd);
        }
        Error cmpsd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmpsd, a, b, c);
        }
        Error cmpsd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmpsd, a, b, c);
        }
        Error cmpsq()
        {
            return emit(x86::Mnemonic::Cmpsq);
        }
        Error cmpss(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmpss, a, b, c);
        }
        Error cmpss(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Cmpss, a, b, c);
        }
        Error cmpsw()
        {
            return emit(x86::Mnemonic::Cmpsw);
        }
        Error cmpxchg(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Cmpxchg, a, b);
        }
        Error cmpxchg(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Cmpxchg, a, b);
        }
        Error cmpxchg(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmpxchg, a, b);
        }
        Error cmpxchg(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Cmpxchg, a, b);
        }
        Error cmpxchg16b(const Mem& a)
        {
            return emit(x86::Mnemonic::Cmpxchg16b, a);
        }
        Error cmpxchg8b(const Mem& a)
        {
            return emit(x86::Mnemonic::Cmpxchg8b, a);
        }
        Error comisd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Comisd, a, b);
        }
        Error comisd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Comisd, a, b);
        }
        Error comiss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Comiss, a, b);
        }
        Error comiss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Comiss, a, b);
        }
        Error cpuid()
        {
            return emit(x86::Mnemonic::Cpuid);
        }
        Error cqo()
        {
            return emit(x86::Mnemonic::Cqo);
        }
        Error crc32(const Gp& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Crc32, a, b);
        }
        Error crc32(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Crc32, a, b);
        }
        Error crc32(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Crc32, a, b);
        }
        Error cvtdq2pd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtdq2pd, a, b);
        }
        Error cvtdq2pd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtdq2pd, a, b);
        }
        Error cvtdq2ps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtdq2ps, a, b);
        }
        Error cvtdq2ps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtdq2ps, a, b);
        }
        Error cvtpd2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtpd2dq, a, b);
        }
        Error cvtpd2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtpd2dq, a, b);
        }
        Error cvtpd2pi(const Mmx& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtpd2pi, a, b);
        }
        Error cvtpd2pi(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtpd2pi, a, b);
        }
        Error cvtpd2ps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtpd2ps, a, b);
        }
        Error cvtpd2ps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtpd2ps, a, b);
        }
        Error cvtpi2pd(const Xmm& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Cvtpi2pd, a, b);
        }
        Error cvtpi2pd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtpi2pd, a, b);
        }
        Error cvtpi2ps(const Xmm& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Cvtpi2ps, a, b);
        }
        Error cvtpi2ps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtpi2ps, a, b);
        }
        Error cvtps2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtps2dq, a, b);
        }
        Error cvtps2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtps2dq, a, b);
        }
        Error cvtps2pd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtps2pd, a, b);
        }
        Error cvtps2pd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtps2pd, a, b);
        }
        Error cvtps2pi(const Mmx& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtps2pi, a, b);
        }
        Error cvtps2pi(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtps2pi, a, b);
        }
        Error cvtsd2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtsd2si, a, b);
        }
        Error cvtsd2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtsd2si, a, b);
        }
        Error cvtsd2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtsd2si, a, b);
        }
        Error cvtsd2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtsd2si, a, b);
        }
        Error cvtsd2ss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtsd2ss, a, b);
        }
        Error cvtsd2ss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtsd2ss, a, b);
        }
        Error cvtsi2sd(const Xmm& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Cvtsi2sd, a, b);
        }
        Error cvtsi2sd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtsi2sd, a, b);
        }
        Error cvtsi2sd(const Xmm& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Cvtsi2sd, a, b);
        }
        Error cvtsi2ss(const Xmm& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Cvtsi2ss, a, b);
        }
        Error cvtsi2ss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtsi2ss, a, b);
        }
        Error cvtsi2ss(const Xmm& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Cvtsi2ss, a, b);
        }
        Error cvtss2sd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtss2sd, a, b);
        }
        Error cvtss2sd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtss2sd, a, b);
        }
        Error cvtss2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtss2si, a, b);
        }
        Error cvtss2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtss2si, a, b);
        }
        Error cvtss2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvtss2si, a, b);
        }
        Error cvtss2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvtss2si, a, b);
        }
        Error cvttpd2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttpd2dq, a, b);
        }
        Error cvttpd2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttpd2dq, a, b);
        }
        Error cvttpd2pi(const Mmx& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttpd2pi, a, b);
        }
        Error cvttpd2pi(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttpd2pi, a, b);
        }
        Error cvttps2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttps2dq, a, b);
        }
        Error cvttps2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttps2dq, a, b);
        }
        Error cvttps2pi(const Mmx& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttps2pi, a, b);
        }
        Error cvttps2pi(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttps2pi, a, b);
        }
        Error cvttsd2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttsd2si, a, b);
        }
        Error cvttsd2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttsd2si, a, b);
        }
        Error cvttsd2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttsd2si, a, b);
        }
        Error cvttsd2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttsd2si, a, b);
        }
        Error cvttss2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttss2si, a, b);
        }
        Error cvttss2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttss2si, a, b);
        }
        Error cvttss2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Cvttss2si, a, b);
        }
        Error cvttss2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Cvttss2si, a, b);
        }
        Error cwd()
        {
            return emit(x86::Mnemonic::Cwd);
        }
        Error cwde()
        {
            return emit(x86::Mnemonic::Cwde);
        }
        Error daa()
        {
            return emit(x86::Mnemonic::Daa);
        }
        Error das()
        {
            return emit(x86::Mnemonic::Das);
        }
        Error dec(const Gp& a)
        {
            return emit(x86::Mnemonic::Dec, a);
        }
        Error dec(const Gp8& a)
        {
            return emit(x86::Mnemonic::Dec, a);
        }
        Error dec(const Mem& a)
        {
            return emit(x86::Mnemonic::Dec, a);
        }
        Error delay(const Gp32& a)
        {
            return emit(x86::Mnemonic::Delay, a);
        }
        Error delay(const Gp64& a)
        {
            return emit(x86::Mnemonic::Delay, a);
        }
        Error div(const Gp8& a)
        {
            return emit(x86::Mnemonic::Div, a);
        }
        Error div(const Mem& a)
        {
            return emit(x86::Mnemonic::Div, a);
        }
        Error div(const Gp& a)
        {
            return emit(x86::Mnemonic::Div, a);
        }
        Error divpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Divpd, a, b);
        }
        Error divpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Divpd, a, b);
        }
        Error divps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Divps, a, b);
        }
        Error divps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Divps, a, b);
        }
        Error divsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Divsd, a, b);
        }
        Error divsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Divsd, a, b);
        }
        Error divss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Divss, a, b);
        }
        Error divss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Divss, a, b);
        }
        Error dppd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Dppd, a, b, c);
        }
        Error dppd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Dppd, a, b, c);
        }
        Error dpps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Dpps, a, b, c);
        }
        Error dpps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Dpps, a, b, c);
        }
        Error emms()
        {
            return emit(x86::Mnemonic::Emms);
        }
        Error encls()
        {
            return emit(x86::Mnemonic::Encls);
        }
        Error enclu()
        {
            return emit(x86::Mnemonic::Enclu);
        }
        Error enclv()
        {
            return emit(x86::Mnemonic::Enclv);
        }
        Error encodekey128(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Encodekey128, a, b);
        }
        Error encodekey256(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Encodekey256, a, b);
        }
        Error endbr32()
        {
            return emit(x86::Mnemonic::Endbr32);
        }
        Error endbr64()
        {
            return emit(x86::Mnemonic::Endbr64);
        }
        Error enqcmd(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Enqcmd, a, b);
        }
        Error enqcmds(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Enqcmds, a, b);
        }
        Error enter(const Imm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Enter, a, b);
        }
        Error extractps(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Extractps, a, b, c);
        }
        Error extractps(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Extractps, a, b, c);
        }
        Error extrq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Extrq, a, b);
        }
        Error extrq(const Xmm& a, const Imm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Extrq, a, b, c);
        }
        Error f2xm1()
        {
            return emit(x86::Mnemonic::F2xm1);
        }
        Error fabs()
        {
            return emit(x86::Mnemonic::Fabs);
        }
        Error fadd(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fadd, a, b);
        }
        Error fadd(const Mem& b)
        {
            return emit(x86::Mnemonic::Fadd, b);
        }
        Error faddp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Faddp, a, b);
        }
        Error fbld(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fbld, a, b);
        }
        Error fbstp(const Mem& a, const St& b)
        {
            return emit(x86::Mnemonic::Fbstp, a, b);
        }
        Error fchs()
        {
            return emit(x86::Mnemonic::Fchs);
        }
        Error fcmovb(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovb, a, b);
        }
        Error fcmovbe(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovbe, a, b);
        }
        Error fcmove(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmove, a, b);
        }
        Error fcmovnb(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovnb, a, b);
        }
        Error fcmovnbe(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovnbe, a, b);
        }
        Error fcmovne(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovne, a, b);
        }
        Error fcmovnu(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovnu, a, b);
        }
        Error fcmovu(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcmovu, a, b);
        }
        Error fcom(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcom, a, b);
        }
        Error fcom(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fcom, a, b);
        }
        Error fcomi(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcomi, a, b);
        }
        Error fcomip(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcomip, a, b);
        }
        Error fcomp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fcomp, a, b);
        }
        Error fcomp(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fcomp, a, b);
        }
        Error fcompp()
        {
            return emit(x86::Mnemonic::Fcompp);
        }
        Error fcos()
        {
            return emit(x86::Mnemonic::Fcos);
        }
        Error fdecstp()
        {
            return emit(x86::Mnemonic::Fdecstp);
        }
        Error fdisi8087_nop()
        {
            return emit(x86::Mnemonic::Fdisi8087_nop);
        }
        Error fdiv(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fdiv, a, b);
        }
        Error fdiv(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fdiv, a, b);
        }
        Error fdivp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fdivp, a, b);
        }
        Error fdivr(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fdivr, a, b);
        }
        Error fdivr(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fdivr, a, b);
        }
        Error fdivrp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fdivrp, a, b);
        }
        Error femms()
        {
            return emit(x86::Mnemonic::Femms);
        }
        Error feni8087_nop()
        {
            return emit(x86::Mnemonic::Feni8087_nop);
        }
        Error ffree(const St& a)
        {
            return emit(x86::Mnemonic::Ffree, a);
        }
        Error ffreep(const St& a)
        {
            return emit(x86::Mnemonic::Ffreep, a);
        }
        Error fiadd(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fiadd, a, b);
        }
        Error ficom(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ficom, a, b);
        }
        Error ficomp(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ficomp, a, b);
        }
        Error fidiv(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fidiv, a, b);
        }
        Error fidivr(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fidivr, a, b);
        }
        Error fild(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fild, a, b);
        }
        Error fimul(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fimul, a, b);
        }
        Error fincstp()
        {
            return emit(x86::Mnemonic::Fincstp);
        }
        Error fist(const Mem& a, const St& b)
        {
            return emit(x86::Mnemonic::Fist, a, b);
        }
        Error fistp(const Mem& a, const St& b)
        {
            return emit(x86::Mnemonic::Fistp, a, b);
        }
        Error fisttp(const Mem& a, const St& b)
        {
            return emit(x86::Mnemonic::Fisttp, a, b);
        }
        Error fisub(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fisub, a, b);
        }
        Error fisubr(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fisubr, a, b);
        }
        Error fld(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fld, a, b);
        }
        Error fld(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fld, a, b);
        }
        Error fld1()
        {
            return emit(x86::Mnemonic::Fld1);
        }
        Error fldcw(const Mem& a)
        {
            return emit(x86::Mnemonic::Fldcw, a);
        }
        Error fldenv(const Mem& a)
        {
            return emit(x86::Mnemonic::Fldenv, a);
        }
        Error fldl2e()
        {
            return emit(x86::Mnemonic::Fldl2e);
        }
        Error fldl2t()
        {
            return emit(x86::Mnemonic::Fldl2t);
        }
        Error fldlg2()
        {
            return emit(x86::Mnemonic::Fldlg2);
        }
        Error fldln2()
        {
            return emit(x86::Mnemonic::Fldln2);
        }
        Error fldpi()
        {
            return emit(x86::Mnemonic::Fldpi);
        }
        Error fldz()
        {
            return emit(x86::Mnemonic::Fldz);
        }
        Error fmul(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fmul, a, b);
        }
        Error fmul(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fmul, a, b);
        }
        Error fmulp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fmulp, a, b);
        }
        Error fnclex()
        {
            return emit(x86::Mnemonic::Fnclex);
        }
        Error fninit()
        {
            return emit(x86::Mnemonic::Fninit);
        }
        Error fnop()
        {
            return emit(x86::Mnemonic::Fnop);
        }
        Error fnsave(const Mem& a)
        {
            return emit(x86::Mnemonic::Fnsave, a);
        }
        Error fnstcw(const Mem& a)
        {
            return emit(x86::Mnemonic::Fnstcw, a);
        }
        Error fnstenv(const Mem& a)
        {
            return emit(x86::Mnemonic::Fnstenv, a);
        }
        Error fnstsw(const Mem& a)
        {
            return emit(x86::Mnemonic::Fnstsw, a);
        }
        Error fnstsw(const Gp& a)
        {
            return emit(x86::Mnemonic::Fnstsw, a);
        }
        Error fpatan()
        {
            return emit(x86::Mnemonic::Fpatan);
        }
        Error fprem()
        {
            return emit(x86::Mnemonic::Fprem);
        }
        Error fprem1()
        {
            return emit(x86::Mnemonic::Fprem1);
        }
        Error fptan()
        {
            return emit(x86::Mnemonic::Fptan);
        }
        Error frndint()
        {
            return emit(x86::Mnemonic::Frndint);
        }
        Error frstor(const Mem& a)
        {
            return emit(x86::Mnemonic::Frstor, a);
        }
        Error fscale()
        {
            return emit(x86::Mnemonic::Fscale);
        }
        Error fsetpm287_nop()
        {
            return emit(x86::Mnemonic::Fsetpm287_nop);
        }
        Error fsin()
        {
            return emit(x86::Mnemonic::Fsin);
        }
        Error fsincos()
        {
            return emit(x86::Mnemonic::Fsincos);
        }
        Error fsqrt()
        {
            return emit(x86::Mnemonic::Fsqrt);
        }
        Error fst(const Mem& a, const St& b)
        {
            return emit(x86::Mnemonic::Fst, a, b);
        }
        Error fst(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fst, a, b);
        }
        Error fstp(const Mem& a, const St& b)
        {
            return emit(x86::Mnemonic::Fstp, a, b);
        }
        Error fstp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fstp, a, b);
        }
        Error fstpnce(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fstpnce, a, b);
        }
        Error fsub(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fsub, a, b);
        }
        Error fsub(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fsub, a, b);
        }
        Error fsubp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fsubp, a, b);
        }
        Error fsubr(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fsubr, a, b);
        }
        Error fsubr(const St& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Fsubr, a, b);
        }
        Error fsubrp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fsubrp, a, b);
        }
        Error ftst()
        {
            return emit(x86::Mnemonic::Ftst);
        }
        Error fucom(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fucom, a, b);
        }
        Error fucomi(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fucomi, a, b);
        }
        Error fucomip(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fucomip, a, b);
        }
        Error fucomp(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fucomp, a, b);
        }
        Error fucompp()
        {
            return emit(x86::Mnemonic::Fucompp);
        }
        Error fwait()
        {
            return emit(x86::Mnemonic::Fwait);
        }
        Error fxam()
        {
            return emit(x86::Mnemonic::Fxam);
        }
        Error fxch(const St& a, const St& b)
        {
            return emit(x86::Mnemonic::Fxch, a, b);
        }
        Error fxrstor(const Mem& a)
        {
            return emit(x86::Mnemonic::Fxrstor, a);
        }
        Error fxrstor64(const Mem& a)
        {
            return emit(x86::Mnemonic::Fxrstor64, a);
        }
        Error fxsave(const Mem& a)
        {
            return emit(x86::Mnemonic::Fxsave, a);
        }
        Error fxsave64(const Mem& a)
        {
            return emit(x86::Mnemonic::Fxsave64, a);
        }
        Error fxtract()
        {
            return emit(x86::Mnemonic::Fxtract);
        }
        Error fyl2x()
        {
            return emit(x86::Mnemonic::Fyl2x);
        }
        Error fyl2xp1()
        {
            return emit(x86::Mnemonic::Fyl2xp1);
        }
        Error getsec()
        {
            return emit(x86::Mnemonic::Getsec);
        }
        Error gf2p8affineinvqb(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Gf2p8affineinvqb, a, b, c);
        }
        Error gf2p8affineinvqb(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Gf2p8affineinvqb, a, b, c);
        }
        Error gf2p8affineqb(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Gf2p8affineqb, a, b, c);
        }
        Error gf2p8affineqb(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Gf2p8affineqb, a, b, c);
        }
        Error gf2p8mulb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Gf2p8mulb, a, b);
        }
        Error gf2p8mulb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Gf2p8mulb, a, b);
        }
        Error haddpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Haddpd, a, b);
        }
        Error haddpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Haddpd, a, b);
        }
        Error haddps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Haddps, a, b);
        }
        Error haddps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Haddps, a, b);
        }
        Error hlt()
        {
            return emit(x86::Mnemonic::Hlt);
        }
        Error hreset(const Imm& a)
        {
            return emit(x86::Mnemonic::Hreset, a);
        }
        Error hsubpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Hsubpd, a, b);
        }
        Error hsubpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Hsubpd, a, b);
        }
        Error hsubps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Hsubps, a, b);
        }
        Error hsubps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Hsubps, a, b);
        }
        Error idiv(const Gp8& a)
        {
            return emit(x86::Mnemonic::Idiv, a);
        }
        Error idiv(const Mem& a)
        {
            return emit(x86::Mnemonic::Idiv, a);
        }
        Error idiv(const Gp& a)
        {
            return emit(x86::Mnemonic::Idiv, a);
        }
        Error imul(const Gp8& a)
        {
            return emit(x86::Mnemonic::Imul, a);
        }
        Error imul(const Mem& a)
        {
            return emit(x86::Mnemonic::Imul, a);
        }
        Error imul(const Gp& a)
        {
            return emit(x86::Mnemonic::Imul, a);
        }
        Error imul(const Gp& a, const Gp& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Imul, a, b, c);
        }
        Error imul(const Gp& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Imul, a, b, c);
        }
        Error imul(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Imul, a, b);
        }
        Error imul(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Imul, a, b);
        }
        Error in_(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::In, a, b);
        }
        Error in_(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::In, a, b);
        }
        Error inc(const Gp& a)
        {
            return emit(x86::Mnemonic::Inc, a);
        }
        Error inc(const Gp8& a)
        {
            return emit(x86::Mnemonic::Inc, a);
        }
        Error inc(const Mem& a)
        {
            return emit(x86::Mnemonic::Inc, a);
        }
        Error incsspd(const Gp32& a)
        {
            return emit(x86::Mnemonic::Incsspd, a);
        }
        Error incsspq(const Gp64& a)
        {
            return emit(x86::Mnemonic::Incsspq, a);
        }
        Error insb()
        {
            return emit(x86::Mnemonic::Insb);
        }
        Error insd()
        {
            return emit(x86::Mnemonic::Insd);
        }
        Error insertps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Insertps, a, b, c);
        }
        Error insertps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Insertps, a, b, c);
        }
        Error insertq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Insertq, a, b);
        }
        Error insertq(const Xmm& a, const Xmm& b, const Imm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Insertq, a, b, c, d);
        }
        Error insw()
        {
            return emit(x86::Mnemonic::Insw);
        }
        Error int_(const Imm& a)
        {
            return emit(x86::Mnemonic::Int, a);
        }
        Error int1()
        {
            return emit(x86::Mnemonic::Int1);
        }
        Error int3()
        {
            return emit(x86::Mnemonic::Int3);
        }
        Error into()
        {
            return emit(x86::Mnemonic::Into);
        }
        Error invd()
        {
            return emit(x86::Mnemonic::Invd);
        }
        Error invept(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Invept, a, b);
        }
        Error invept(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Invept, a, b);
        }
        Error invlpg(const Mem& a)
        {
            return emit(x86::Mnemonic::Invlpg, a);
        }
        Error invlpga(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Invlpga, a, b);
        }
        Error invlpgb(const Gp& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Invlpgb, a, b, c);
        }
        Error invpcid(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Invpcid, a, b);
        }
        Error invpcid(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Invpcid, a, b);
        }
        Error invvpid(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Invvpid, a, b);
        }
        Error invvpid(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Invvpid, a, b);
        }
        Error iret()
        {
            return emit(x86::Mnemonic::Iret);
        }
        Error iretd()
        {
            return emit(x86::Mnemonic::Iretd);
        }
        Error iretq()
        {
            return emit(x86::Mnemonic::Iretq);
        }
        Error jb(const Imm& a)
        {
            return emit(x86::Mnemonic::Jb, a);
        }
        Error jb(const Label& a)
        {
            return emit(x86::Mnemonic::Jb, a);
        }
        Error jbe(const Imm& a)
        {
            return emit(x86::Mnemonic::Jbe, a);
        }
        Error jbe(const Label& a)
        {
            return emit(x86::Mnemonic::Jbe, a);
        }
        Error jcxz(const Imm& a)
        {
            return emit(x86::Mnemonic::Jcxz, a);
        }
        Error jcxz(const Label& a)
        {
            return emit(x86::Mnemonic::Jcxz, a);
        }
        Error jecxz(const Imm& a)
        {
            return emit(x86::Mnemonic::Jecxz, a);
        }
        Error jknzd(const Mask& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Jknzd, a, b);
        }
        Error jkzd(const Mask& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Jkzd, a, b);
        }
        Error jl(const Imm& a)
        {
            return emit(x86::Mnemonic::Jl, a);
        }
        Error jl(const Label& a)
        {
            return emit(x86::Mnemonic::Jl, a);
        }
        Error jle(const Imm& a)
        {
            return emit(x86::Mnemonic::Jle, a);
        }
        Error jle(const Label& a)
        {
            return emit(x86::Mnemonic::Jle, a);
        }
        Error jmp(const Imm& a)
        {
            return emit(x86::Mnemonic::Jmp, a);
        }
        Error jmp(const Label& a)
        {
            return emit(x86::Mnemonic::Jmp, a);
        }
        Error jmp(const Gp& a)
        {
            return emit(x86::Mnemonic::Jmp, a);
        }
        Error jmp(const Mem& a)
        {
            return emit(x86::Mnemonic::Jmp, a);
        }
        Error jnb(const Imm& a)
        {
            return emit(x86::Mnemonic::Jnb, a);
        }
        Error jnb(const Label& a)
        {
            return emit(x86::Mnemonic::Jnb, a);
        }
        Error jnbe(const Imm& a)
        {
            return emit(x86::Mnemonic::Jnbe, a);
        }
        Error jnbe(const Label& a)
        {
            return emit(x86::Mnemonic::Jnbe, a);
        }
        Error jnl(const Imm& a)
        {
            return emit(x86::Mnemonic::Jnl, a);
        }
        Error jnl(const Label& a)
        {
            return emit(x86::Mnemonic::Jnl, a);
        }
        Error jnle(const Imm& a)
        {
            return emit(x86::Mnemonic::Jnle, a);
        }
        Error jnle(const Label& a)
        {
            return emit(x86::Mnemonic::Jnle, a);
        }
        Error jno(const Imm& a)
        {
            return emit(x86::Mnemonic::Jno, a);
        }
        Error jno(const Label& a)
        {
            return emit(x86::Mnemonic::Jno, a);
        }
        Error jnp(const Imm& a)
        {
            return emit(x86::Mnemonic::Jnp, a);
        }
        Error jnp(const Label& a)
        {
            return emit(x86::Mnemonic::Jnp, a);
        }
        Error jns(const Imm& a)
        {
            return emit(x86::Mnemonic::Jns, a);
        }
        Error jns(const Label& a)
        {
            return emit(x86::Mnemonic::Jns, a);
        }
        Error jnz(const Imm& a)
        {
            return emit(x86::Mnemonic::Jnz, a);
        }
        Error jnz(const Label& a)
        {
            return emit(x86::Mnemonic::Jnz, a);
        }
        Error jo(const Imm& a)
        {
            return emit(x86::Mnemonic::Jo, a);
        }
        Error jo(const Label& a)
        {
            return emit(x86::Mnemonic::Jo, a);
        }
        Error jp(const Imm& a)
        {
            return emit(x86::Mnemonic::Jp, a);
        }
        Error jp(const Label& a)
        {
            return emit(x86::Mnemonic::Jp, a);
        }
        Error jrcxz(const Imm& a)
        {
            return emit(x86::Mnemonic::Jrcxz, a);
        }
        Error jrcxz(const Label& a)
        {
            return emit(x86::Mnemonic::Jrcxz, a);
        }
        Error js(const Imm& a)
        {
            return emit(x86::Mnemonic::Js, a);
        }
        Error js(const Label& a)
        {
            return emit(x86::Mnemonic::Js, a);
        }
        Error jz(const Imm& a)
        {
            return emit(x86::Mnemonic::Jz, a);
        }
        Error jz(const Label& a)
        {
            return emit(x86::Mnemonic::Jz, a);
        }
        Error kaddb(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kaddb, a, b, c);
        }
        Error kaddd(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kaddd, a, b, c);
        }
        Error kaddq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kaddq, a, b, c);
        }
        Error kaddw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kaddw, a, b, c);
        }
        Error kand(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kand, a, b);
        }
        Error kandb(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandb, a, b, c);
        }
        Error kandd(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandd, a, b, c);
        }
        Error kandn(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kandn, a, b);
        }
        Error kandnb(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandnb, a, b, c);
        }
        Error kandnd(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandnd, a, b, c);
        }
        Error kandnq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandnq, a, b, c);
        }
        Error kandnr(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kandnr, a, b);
        }
        Error kandnw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandnw, a, b, c);
        }
        Error kandq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandq, a, b, c);
        }
        Error kandw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kandw, a, b, c);
        }
        Error kconcath(const Gp64& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kconcath, a, b, c);
        }
        Error kconcatl(const Gp64& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kconcatl, a, b, c);
        }
        Error kextract(const Mask& a, const Gp64& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kextract, a, b, c);
        }
        Error kmerge2l1h(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmerge2l1h, a, b);
        }
        Error kmerge2l1l(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmerge2l1l, a, b);
        }
        Error kmov(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmov, a, b);
        }
        Error kmov(const Mask& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Kmov, a, b);
        }
        Error kmov(const Gp32& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmov, a, b);
        }
        Error kmovb(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovb, a, b);
        }
        Error kmovb(const Mask& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Kmovb, a, b);
        }
        Error kmovb(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovb, a, b);
        }
        Error kmovb(const Mask& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Kmovb, a, b);
        }
        Error kmovb(const Gp32& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovb, a, b);
        }
        Error kmovd(const Mask& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Kmovd, a, b);
        }
        Error kmovd(const Gp32& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovd, a, b);
        }
        Error kmovd(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovd, a, b);
        }
        Error kmovd(const Mask& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Kmovd, a, b);
        }
        Error kmovd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovd, a, b);
        }
        Error kmovq(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovq, a, b);
        }
        Error kmovq(const Mask& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Kmovq, a, b);
        }
        Error kmovq(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovq, a, b);
        }
        Error kmovq(const Mask& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Kmovq, a, b);
        }
        Error kmovq(const Gp64& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovq, a, b);
        }
        Error kmovw(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovw, a, b);
        }
        Error kmovw(const Mask& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Kmovw, a, b);
        }
        Error kmovw(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovw, a, b);
        }
        Error kmovw(const Mask& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Kmovw, a, b);
        }
        Error kmovw(const Gp32& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kmovw, a, b);
        }
        Error knot(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Knot, a, b);
        }
        Error knotb(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Knotb, a, b);
        }
        Error knotd(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Knotd, a, b);
        }
        Error knotq(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Knotq, a, b);
        }
        Error knotw(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Knotw, a, b);
        }
        Error kor(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kor, a, b);
        }
        Error korb(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Korb, a, b, c);
        }
        Error kord(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kord, a, b, c);
        }
        Error korq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Korq, a, b, c);
        }
        Error kortest(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kortest, a, b);
        }
        Error kortestb(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kortestb, a, b);
        }
        Error kortestd(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kortestd, a, b);
        }
        Error kortestq(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kortestq, a, b);
        }
        Error kortestw(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kortestw, a, b);
        }
        Error korw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Korw, a, b, c);
        }
        Error kshiftlb(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftlb, a, b, c);
        }
        Error kshiftld(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftld, a, b, c);
        }
        Error kshiftlq(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftlq, a, b, c);
        }
        Error kshiftlw(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftlw, a, b, c);
        }
        Error kshiftrb(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftrb, a, b, c);
        }
        Error kshiftrd(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftrd, a, b, c);
        }
        Error kshiftrq(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftrq, a, b, c);
        }
        Error kshiftrw(const Mask& a, const Mask& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Kshiftrw, a, b, c);
        }
        Error ktestb(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Ktestb, a, b);
        }
        Error ktestd(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Ktestd, a, b);
        }
        Error ktestq(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Ktestq, a, b);
        }
        Error ktestw(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Ktestw, a, b);
        }
        Error kunpckbw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kunpckbw, a, b, c);
        }
        Error kunpckdq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kunpckdq, a, b, c);
        }
        Error kunpckwd(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kunpckwd, a, b, c);
        }
        Error kxnor(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kxnor, a, b);
        }
        Error kxnorb(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxnorb, a, b, c);
        }
        Error kxnord(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxnord, a, b, c);
        }
        Error kxnorq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxnorq, a, b, c);
        }
        Error kxnorw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxnorw, a, b, c);
        }
        Error kxor(const Mask& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Kxor, a, b);
        }
        Error kxorb(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxorb, a, b, c);
        }
        Error kxord(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxord, a, b, c);
        }
        Error kxorq(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxorq, a, b, c);
        }
        Error kxorw(const Mask& a, const Mask& b, const Mask& c)
        {
            return emit(x86::Mnemonic::Kxorw, a, b, c);
        }
        Error lahf()
        {
            return emit(x86::Mnemonic::Lahf);
        }
        Error lar(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Lar, a, b);
        }
        Error lar(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lar, a, b);
        }
        Error lddqu(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lddqu, a, b);
        }
        Error ldmxcsr(const Mem& a)
        {
            return emit(x86::Mnemonic::Ldmxcsr, a);
        }
        Error lds(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lds, a, b);
        }
        Error ldtilecfg(const Mem& a)
        {
            return emit(x86::Mnemonic::Ldtilecfg, a);
        }
        Error lea(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lea, a, b);
        }
        Error leave()
        {
            return emit(x86::Mnemonic::Leave);
        }
        Error les(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Les, a, b);
        }
        Error lfence()
        {
            return emit(x86::Mnemonic::Lfence);
        }
        Error lfs(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lfs, a, b);
        }
        Error lgdt(const Mem& a)
        {
            return emit(x86::Mnemonic::Lgdt, a);
        }
        Error lgs(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lgs, a, b);
        }
        Error lidt(const Mem& a)
        {
            return emit(x86::Mnemonic::Lidt, a);
        }
        Error lldt(const Gp16& a)
        {
            return emit(x86::Mnemonic::Lldt, a);
        }
        Error lldt(const Mem& a)
        {
            return emit(x86::Mnemonic::Lldt, a);
        }
        Error llwpcb(const Gp& a)
        {
            return emit(x86::Mnemonic::Llwpcb, a);
        }
        Error lmsw(const Gp16& a)
        {
            return emit(x86::Mnemonic::Lmsw, a);
        }
        Error lmsw(const Mem& a)
        {
            return emit(x86::Mnemonic::Lmsw, a);
        }
        Error loadiwkey(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Loadiwkey, a, b);
        }
        Error lodsb()
        {
            return emit(x86::Mnemonic::Lodsb);
        }
        Error lodsd()
        {
            return emit(x86::Mnemonic::Lodsd);
        }
        Error lodsq()
        {
            return emit(x86::Mnemonic::Lodsq);
        }
        Error lodsw()
        {
            return emit(x86::Mnemonic::Lodsw);
        }
        Error loop(const Imm& a)
        {
            return emit(x86::Mnemonic::Loop, a);
        }
        Error loope(const Imm& a)
        {
            return emit(x86::Mnemonic::Loope, a);
        }
        Error loopne(const Imm& a)
        {
            return emit(x86::Mnemonic::Loopne, a);
        }
        Error lsl(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Lsl, a, b);
        }
        Error lsl(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lsl, a, b);
        }
        Error lss(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lss, a, b);
        }
        Error ltr(const Gp16& a)
        {
            return emit(x86::Mnemonic::Ltr, a);
        }
        Error ltr(const Mem& a)
        {
            return emit(x86::Mnemonic::Ltr, a);
        }
        Error lwpins(const Gp& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Lwpins, a, b, c);
        }
        Error lwpins(const Gp& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Lwpins, a, b, c);
        }
        Error lwpval(const Gp& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Lwpval, a, b, c);
        }
        Error lwpval(const Gp& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Lwpval, a, b, c);
        }
        Error lzcnt(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Lzcnt, a, b);
        }
        Error lzcnt(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Lzcnt, a, b);
        }
        Error lzcnt(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Lzcnt, a, b);
        }
        Error lzcnt(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Lzcnt, a, b);
        }
        Error maskmovdqu(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Maskmovdqu, a, b);
        }
        Error maskmovq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Maskmovq, a, b);
        }
        Error maxpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Maxpd, a, b);
        }
        Error maxpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Maxpd, a, b);
        }
        Error maxps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Maxps, a, b);
        }
        Error maxps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Maxps, a, b);
        }
        Error maxsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Maxsd, a, b);
        }
        Error maxsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Maxsd, a, b);
        }
        Error maxss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Maxss, a, b);
        }
        Error maxss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Maxss, a, b);
        }
        Error mcommit()
        {
            return emit(x86::Mnemonic::Mcommit);
        }
        Error mfence()
        {
            return emit(x86::Mnemonic::Mfence);
        }
        Error minpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Minpd, a, b);
        }
        Error minpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Minpd, a, b);
        }
        Error minps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Minps, a, b);
        }
        Error minps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Minps, a, b);
        }
        Error minsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Minsd, a, b);
        }
        Error minsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Minsd, a, b);
        }
        Error minss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Minss, a, b);
        }
        Error minss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Minss, a, b);
        }
        Error monitor()
        {
            return emit(x86::Mnemonic::Monitor);
        }
        Error monitorx()
        {
            return emit(x86::Mnemonic::Monitorx);
        }
        Error montmul()
        {
            return emit(x86::Mnemonic::Montmul);
        }
        Error mov(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Gp& a, const Seg& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Mem& a, const Seg& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Seg& a, const Gp16& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Seg& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Gp8& a, const Label& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Mem& a, const Label& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Gp64& a, const Cr& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Gp32& a, const Cr& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Gp64& a, const Dr& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Gp32& a, const Dr& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Cr& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Cr& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Dr& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Dr& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error mov(const Gp& a, const Label& b)
        {
            return emit(x86::Mnemonic::Mov, a, b);
        }
        Error movapd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movapd, a, b);
        }
        Error movapd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movapd, a, b);
        }
        Error movapd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movapd, a, b);
        }
        Error movaps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movaps, a, b);
        }
        Error movaps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movaps, a, b);
        }
        Error movaps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movaps, a, b);
        }
        Error movbe(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movbe, a, b);
        }
        Error movbe(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Movbe, a, b);
        }
        Error movd(const Mmx& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        Error movd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        Error movd(const Gp32& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        Error movd(const Mem& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        Error movd(const Xmm& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        Error movd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        Error movd(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        Error movd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movd, a, b);
        }
        Error movddup(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movddup, a, b);
        }
        Error movddup(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movddup, a, b);
        }
        Error movdir64b(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movdir64b, a, b);
        }
        Error movdiri(const Mem& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Movdiri, a, b);
        }
        Error movdiri(const Mem& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Movdiri, a, b);
        }
        Error movdq2q(const Mmx& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movdq2q, a, b);
        }
        Error movdqa(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movdqa, a, b);
        }
        Error movdqa(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movdqa, a, b);
        }
        Error movdqa(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movdqa, a, b);
        }
        Error movdqu(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movdqu, a, b);
        }
        Error movdqu(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movdqu, a, b);
        }
        Error movdqu(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movdqu, a, b);
        }
        Error movhlps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movhlps, a, b);
        }
        Error movhpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movhpd, a, b);
        }
        Error movhpd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movhpd, a, b);
        }
        Error movhps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movhps, a, b);
        }
        Error movhps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movhps, a, b);
        }
        Error movlhps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movlhps, a, b);
        }
        Error movlpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movlpd, a, b);
        }
        Error movlpd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movlpd, a, b);
        }
        Error movlps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movlps, a, b);
        }
        Error movlps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movlps, a, b);
        }
        Error movmskpd(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movmskpd, a, b);
        }
        Error movmskps(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movmskps, a, b);
        }
        Error movntdq(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movntdq, a, b);
        }
        Error movntdqa(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movntdqa, a, b);
        }
        Error movnti(const Mem& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Movnti, a, b);
        }
        Error movnti(const Mem& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Movnti, a, b);
        }
        Error movntpd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movntpd, a, b);
        }
        Error movntps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movntps, a, b);
        }
        Error movntq(const Mem& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movntq, a, b);
        }
        Error movntsd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movntsd, a, b);
        }
        Error movntss(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movntss, a, b);
        }
        Error movq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        Error movq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        Error movq(const Mem& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        Error movq(const Mmx& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        Error movq(const Gp64& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        Error movq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        Error movq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        Error movq(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        Error movq(const Xmm& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        Error movq(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movq, a, b);
        }
        Error movq2dq(const Xmm& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Movq2dq, a, b);
        }
        Error movsb()
        {
            return emit(x86::Mnemonic::Movsb);
        }
        Error movsd()
        {
            return emit(x86::Mnemonic::Movsd);
        }
        Error movsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movsd, a, b);
        }
        Error movsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movsd, a, b);
        }
        Error movsd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movsd, a, b);
        }
        Error movshdup(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movshdup, a, b);
        }
        Error movshdup(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movshdup, a, b);
        }
        Error movsldup(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movsldup, a, b);
        }
        Error movsldup(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movsldup, a, b);
        }
        Error movsq()
        {
            return emit(x86::Mnemonic::Movsq);
        }
        Error movss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movss, a, b);
        }
        Error movss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movss, a, b);
        }
        Error movss(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movss, a, b);
        }
        Error movsw()
        {
            return emit(x86::Mnemonic::Movsw);
        }
        Error movsx(const Gp& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Movsx, a, b);
        }
        Error movsx(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movsx, a, b);
        }
        Error movsx(const Gp& a, const Gp16& b)
        {
            return emit(x86::Mnemonic::Movsx, a, b);
        }
        Error movsxd(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Movsxd, a, b);
        }
        Error movsxd(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movsxd, a, b);
        }
        Error movupd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movupd, a, b);
        }
        Error movupd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movupd, a, b);
        }
        Error movupd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movupd, a, b);
        }
        Error movups(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movups, a, b);
        }
        Error movups(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movups, a, b);
        }
        Error movups(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Movups, a, b);
        }
        Error movzx(const Gp& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Movzx, a, b);
        }
        Error movzx(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Movzx, a, b);
        }
        Error movzx(const Gp& a, const Gp16& b)
        {
            return emit(x86::Mnemonic::Movzx, a, b);
        }
        Error mpsadbw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Mpsadbw, a, b, c);
        }
        Error mpsadbw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Mpsadbw, a, b, c);
        }
        Error mul(const Gp8& a)
        {
            return emit(x86::Mnemonic::Mul, a);
        }
        Error mul(const Mem& a)
        {
            return emit(x86::Mnemonic::Mul, a);
        }
        Error mul(const Gp& a)
        {
            return emit(x86::Mnemonic::Mul, a);
        }
        Error mulpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Mulpd, a, b);
        }
        Error mulpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mulpd, a, b);
        }
        Error mulps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Mulps, a, b);
        }
        Error mulps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mulps, a, b);
        }
        Error mulsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Mulsd, a, b);
        }
        Error mulsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mulsd, a, b);
        }
        Error mulss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Mulss, a, b);
        }
        Error mulss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Mulss, a, b);
        }
        Error mulx(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Mulx, a, b, c);
        }
        Error mulx(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Mulx, a, b, c);
        }
        Error mulx(const Gp32& a, const Gp32& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Mulx, a, b, c);
        }
        Error mulx(const Gp64& a, const Gp64& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Mulx, a, b, c);
        }
        Error mwait()
        {
            return emit(x86::Mnemonic::Mwait);
        }
        Error mwaitx()
        {
            return emit(x86::Mnemonic::Mwaitx);
        }
        Error neg(const Gp8& a)
        {
            return emit(x86::Mnemonic::Neg, a);
        }
        Error neg(const Mem& a)
        {
            return emit(x86::Mnemonic::Neg, a);
        }
        Error neg(const Gp& a)
        {
            return emit(x86::Mnemonic::Neg, a);
        }
        Error nop()
        {
            return emit(x86::Mnemonic::Nop);
        }
        Error nop(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Nop, a, b);
        }
        Error nop(const Gp& a)
        {
            return emit(x86::Mnemonic::Nop, a);
        }
        Error nop(const Mem& a)
        {
            return emit(x86::Mnemonic::Nop, a);
        }
        Error nop(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Nop, a, b);
        }
        Error not_(const Gp8& a)
        {
            return emit(x86::Mnemonic::Not, a);
        }
        Error not_(const Mem& a)
        {
            return emit(x86::Mnemonic::Not, a);
        }
        Error not_(const Gp& a)
        {
            return emit(x86::Mnemonic::Not, a);
        }
        Error or_(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        Error or_(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        Error or_(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        Error or_(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        Error or_(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        Error or_(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        Error or_(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        Error or_(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        Error or_(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Or, a, b);
        }
        Error orpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Orpd, a, b);
        }
        Error orpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Orpd, a, b);
        }
        Error orps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Orps, a, b);
        }
        Error orps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Orps, a, b);
        }
        Error out_(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Out, a, b);
        }
        Error out_(const Imm& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Out, a, b);
        }
        Error outsb()
        {
            return emit(x86::Mnemonic::Outsb);
        }
        Error outsd()
        {
            return emit(x86::Mnemonic::Outsd);
        }
        Error outsw()
        {
            return emit(x86::Mnemonic::Outsw);
        }
        Error pabsb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pabsb, a, b);
        }
        Error pabsb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pabsb, a, b);
        }
        Error pabsb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pabsb, a, b);
        }
        Error pabsb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pabsb, a, b);
        }
        Error pabsd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pabsd, a, b);
        }
        Error pabsd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pabsd, a, b);
        }
        Error pabsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pabsd, a, b);
        }
        Error pabsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pabsd, a, b);
        }
        Error pabsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pabsw, a, b);
        }
        Error pabsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pabsw, a, b);
        }
        Error pabsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pabsw, a, b);
        }
        Error pabsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pabsw, a, b);
        }
        Error packssdw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Packssdw, a, b);
        }
        Error packssdw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packssdw, a, b);
        }
        Error packssdw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Packssdw, a, b);
        }
        Error packssdw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packssdw, a, b);
        }
        Error packsswb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Packsswb, a, b);
        }
        Error packsswb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packsswb, a, b);
        }
        Error packsswb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Packsswb, a, b);
        }
        Error packsswb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packsswb, a, b);
        }
        Error packusdw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Packusdw, a, b);
        }
        Error packusdw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packusdw, a, b);
        }
        Error packuswb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Packuswb, a, b);
        }
        Error packuswb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packuswb, a, b);
        }
        Error packuswb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Packuswb, a, b);
        }
        Error packuswb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Packuswb, a, b);
        }
        Error paddb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddb, a, b);
        }
        Error paddb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddb, a, b);
        }
        Error paddb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddb, a, b);
        }
        Error paddb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddb, a, b);
        }
        Error paddd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddd, a, b);
        }
        Error paddd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddd, a, b);
        }
        Error paddd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddd, a, b);
        }
        Error paddd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddd, a, b);
        }
        Error paddq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddq, a, b);
        }
        Error paddq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddq, a, b);
        }
        Error paddq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddq, a, b);
        }
        Error paddq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddq, a, b);
        }
        Error paddsb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddsb, a, b);
        }
        Error paddsb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddsb, a, b);
        }
        Error paddsb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddsb, a, b);
        }
        Error paddsb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddsb, a, b);
        }
        Error paddsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddsw, a, b);
        }
        Error paddsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddsw, a, b);
        }
        Error paddsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddsw, a, b);
        }
        Error paddsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddsw, a, b);
        }
        Error paddusb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddusb, a, b);
        }
        Error paddusb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddusb, a, b);
        }
        Error paddusb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddusb, a, b);
        }
        Error paddusb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddusb, a, b);
        }
        Error paddusw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddusw, a, b);
        }
        Error paddusw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddusw, a, b);
        }
        Error paddusw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddusw, a, b);
        }
        Error paddusw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddusw, a, b);
        }
        Error paddw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Paddw, a, b);
        }
        Error paddw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddw, a, b);
        }
        Error paddw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Paddw, a, b);
        }
        Error paddw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Paddw, a, b);
        }
        Error palignr(const Mmx& a, const Mmx& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Palignr, a, b, c);
        }
        Error palignr(const Mmx& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Palignr, a, b, c);
        }
        Error palignr(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Palignr, a, b, c);
        }
        Error palignr(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Palignr, a, b, c);
        }
        Error pand(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pand, a, b);
        }
        Error pand(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pand, a, b);
        }
        Error pand(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pand, a, b);
        }
        Error pand(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pand, a, b);
        }
        Error pandn(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pandn, a, b);
        }
        Error pandn(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pandn, a, b);
        }
        Error pandn(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pandn, a, b);
        }
        Error pandn(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pandn, a, b);
        }
        Error pause()
        {
            return emit(x86::Mnemonic::Pause);
        }
        Error pavgb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pavgb, a, b);
        }
        Error pavgb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pavgb, a, b);
        }
        Error pavgb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pavgb, a, b);
        }
        Error pavgb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pavgb, a, b);
        }
        Error pavgusb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pavgusb, a, b);
        }
        Error pavgusb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pavgusb, a, b);
        }
        Error pavgw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pavgw, a, b);
        }
        Error pavgw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pavgw, a, b);
        }
        Error pavgw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pavgw, a, b);
        }
        Error pavgw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pavgw, a, b);
        }
        Error pblendvb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pblendvb, a, b);
        }
        Error pblendvb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pblendvb, a, b);
        }
        Error pblendw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pblendw, a, b, c);
        }
        Error pblendw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pblendw, a, b, c);
        }
        Error pclmulqdq(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pclmulqdq, a, b, c);
        }
        Error pclmulqdq(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pclmulqdq, a, b, c);
        }
        Error pcmpeqb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pcmpeqb, a, b);
        }
        Error pcmpeqb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqb, a, b);
        }
        Error pcmpeqb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpeqb, a, b);
        }
        Error pcmpeqb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqb, a, b);
        }
        Error pcmpeqd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pcmpeqd, a, b);
        }
        Error pcmpeqd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqd, a, b);
        }
        Error pcmpeqd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpeqd, a, b);
        }
        Error pcmpeqd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqd, a, b);
        }
        Error pcmpeqq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpeqq, a, b);
        }
        Error pcmpeqq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqq, a, b);
        }
        Error pcmpeqw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pcmpeqw, a, b);
        }
        Error pcmpeqw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqw, a, b);
        }
        Error pcmpeqw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpeqw, a, b);
        }
        Error pcmpeqw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpeqw, a, b);
        }
        Error pcmpestri(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpestri, a, b, c);
        }
        Error pcmpestri(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpestri, a, b, c);
        }
        Error pcmpestrm(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpestrm, a, b, c);
        }
        Error pcmpestrm(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpestrm, a, b, c);
        }
        Error pcmpgtb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pcmpgtb, a, b);
        }
        Error pcmpgtb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtb, a, b);
        }
        Error pcmpgtb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpgtb, a, b);
        }
        Error pcmpgtb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtb, a, b);
        }
        Error pcmpgtd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pcmpgtd, a, b);
        }
        Error pcmpgtd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtd, a, b);
        }
        Error pcmpgtd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpgtd, a, b);
        }
        Error pcmpgtd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtd, a, b);
        }
        Error pcmpgtq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpgtq, a, b);
        }
        Error pcmpgtq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtq, a, b);
        }
        Error pcmpgtw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pcmpgtw, a, b);
        }
        Error pcmpgtw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtw, a, b);
        }
        Error pcmpgtw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pcmpgtw, a, b);
        }
        Error pcmpgtw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pcmpgtw, a, b);
        }
        Error pcmpistri(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpistri, a, b, c);
        }
        Error pcmpistri(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpistri, a, b, c);
        }
        Error pcmpistrm(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpistrm, a, b, c);
        }
        Error pcmpistrm(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pcmpistrm, a, b, c);
        }
        Error pconfig()
        {
            return emit(x86::Mnemonic::Pconfig);
        }
        Error pdep(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Pdep, a, b, c);
        }
        Error pdep(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Pdep, a, b, c);
        }
        Error pdep(const Gp32& a, const Gp32& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Pdep, a, b, c);
        }
        Error pdep(const Gp64& a, const Gp64& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Pdep, a, b, c);
        }
        Error pext(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Pext, a, b, c);
        }
        Error pext(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Pext, a, b, c);
        }
        Error pext(const Gp32& a, const Gp32& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Pext, a, b, c);
        }
        Error pext(const Gp64& a, const Gp64& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Pext, a, b, c);
        }
        Error pextrb(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrb, a, b, c);
        }
        Error pextrb(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrb, a, b, c);
        }
        Error pextrd(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrd, a, b, c);
        }
        Error pextrd(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrd, a, b, c);
        }
        Error pextrq(const Gp64& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrq, a, b, c);
        }
        Error pextrq(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrq, a, b, c);
        }
        Error pextrw(const Gp32& a, const Mmx& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrw, a, b, c);
        }
        Error pextrw(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrw, a, b, c);
        }
        Error pextrw(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pextrw, a, b, c);
        }
        Error pf2id(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pf2id, a, b);
        }
        Error pf2id(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pf2id, a, b);
        }
        Error pf2iw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pf2iw, a, b);
        }
        Error pf2iw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pf2iw, a, b);
        }
        Error pfacc(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfacc, a, b);
        }
        Error pfacc(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfacc, a, b);
        }
        Error pfadd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfadd, a, b);
        }
        Error pfadd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfadd, a, b);
        }
        Error pfcmpeq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfcmpeq, a, b);
        }
        Error pfcmpeq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfcmpeq, a, b);
        }
        Error pfcmpge(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfcmpge, a, b);
        }
        Error pfcmpge(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfcmpge, a, b);
        }
        Error pfcmpgt(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfcmpgt, a, b);
        }
        Error pfcmpgt(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfcmpgt, a, b);
        }
        Error pfcpit1(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfcpit1, a, b);
        }
        Error pfcpit1(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfcpit1, a, b);
        }
        Error pfmax(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfmax, a, b);
        }
        Error pfmax(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfmax, a, b);
        }
        Error pfmin(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfmin, a, b);
        }
        Error pfmin(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfmin, a, b);
        }
        Error pfmul(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfmul, a, b);
        }
        Error pfmul(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfmul, a, b);
        }
        Error pfnacc(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfnacc, a, b);
        }
        Error pfnacc(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfnacc, a, b);
        }
        Error pfpnacc(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfpnacc, a, b);
        }
        Error pfpnacc(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfpnacc, a, b);
        }
        Error pfrcp(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfrcp, a, b);
        }
        Error pfrcp(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfrcp, a, b);
        }
        Error pfrcpit2(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfrcpit2, a, b);
        }
        Error pfrcpit2(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfrcpit2, a, b);
        }
        Error pfrsqit1(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfrsqit1, a, b);
        }
        Error pfrsqit1(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfrsqit1, a, b);
        }
        Error pfsqrt(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfsqrt, a, b);
        }
        Error pfsqrt(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfsqrt, a, b);
        }
        Error pfsub(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfsub, a, b);
        }
        Error pfsub(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfsub, a, b);
        }
        Error pfsubr(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pfsubr, a, b);
        }
        Error pfsubr(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pfsubr, a, b);
        }
        Error phaddd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Phaddd, a, b);
        }
        Error phaddd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phaddd, a, b);
        }
        Error phaddd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phaddd, a, b);
        }
        Error phaddd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phaddd, a, b);
        }
        Error phaddsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Phaddsw, a, b);
        }
        Error phaddsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phaddsw, a, b);
        }
        Error phaddsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phaddsw, a, b);
        }
        Error phaddsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phaddsw, a, b);
        }
        Error phaddw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Phaddw, a, b);
        }
        Error phaddw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phaddw, a, b);
        }
        Error phaddw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phaddw, a, b);
        }
        Error phaddw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phaddw, a, b);
        }
        Error phminposuw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phminposuw, a, b);
        }
        Error phminposuw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phminposuw, a, b);
        }
        Error phsubd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Phsubd, a, b);
        }
        Error phsubd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phsubd, a, b);
        }
        Error phsubd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phsubd, a, b);
        }
        Error phsubd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phsubd, a, b);
        }
        Error phsubsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Phsubsw, a, b);
        }
        Error phsubsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phsubsw, a, b);
        }
        Error phsubsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phsubsw, a, b);
        }
        Error phsubsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phsubsw, a, b);
        }
        Error phsubw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Phsubw, a, b);
        }
        Error phsubw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phsubw, a, b);
        }
        Error phsubw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Phsubw, a, b);
        }
        Error phsubw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Phsubw, a, b);
        }
        Error pi2fd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pi2fd, a, b);
        }
        Error pi2fd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pi2fd, a, b);
        }
        Error pi2fw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pi2fw, a, b);
        }
        Error pi2fw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pi2fw, a, b);
        }
        Error pinsrb(const Xmm& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrb, a, b, c);
        }
        Error pinsrb(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrb, a, b, c);
        }
        Error pinsrd(const Xmm& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrd, a, b, c);
        }
        Error pinsrd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrd, a, b, c);
        }
        Error pinsrq(const Xmm& a, const Gp64& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrq, a, b, c);
        }
        Error pinsrq(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrq, a, b, c);
        }
        Error pinsrw(const Mmx& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrw, a, b, c);
        }
        Error pinsrw(const Mmx& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrw, a, b, c);
        }
        Error pinsrw(const Xmm& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrw, a, b, c);
        }
        Error pinsrw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pinsrw, a, b, c);
        }
        Error pmaddubsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmaddubsw, a, b);
        }
        Error pmaddubsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaddubsw, a, b);
        }
        Error pmaddubsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaddubsw, a, b);
        }
        Error pmaddubsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaddubsw, a, b);
        }
        Error pmaddwd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmaddwd, a, b);
        }
        Error pmaddwd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaddwd, a, b);
        }
        Error pmaddwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaddwd, a, b);
        }
        Error pmaddwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaddwd, a, b);
        }
        Error pmaxsb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaxsb, a, b);
        }
        Error pmaxsb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxsb, a, b);
        }
        Error pmaxsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaxsd, a, b);
        }
        Error pmaxsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxsd, a, b);
        }
        Error pmaxsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmaxsw, a, b);
        }
        Error pmaxsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxsw, a, b);
        }
        Error pmaxsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaxsw, a, b);
        }
        Error pmaxsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxsw, a, b);
        }
        Error pmaxub(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmaxub, a, b);
        }
        Error pmaxub(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxub, a, b);
        }
        Error pmaxub(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaxub, a, b);
        }
        Error pmaxub(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxub, a, b);
        }
        Error pmaxud(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaxud, a, b);
        }
        Error pmaxud(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxud, a, b);
        }
        Error pmaxuw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmaxuw, a, b);
        }
        Error pmaxuw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmaxuw, a, b);
        }
        Error pminsb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pminsb, a, b);
        }
        Error pminsb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminsb, a, b);
        }
        Error pminsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pminsd, a, b);
        }
        Error pminsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminsd, a, b);
        }
        Error pminsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pminsw, a, b);
        }
        Error pminsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminsw, a, b);
        }
        Error pminsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pminsw, a, b);
        }
        Error pminsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminsw, a, b);
        }
        Error pminub(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pminub, a, b);
        }
        Error pminub(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminub, a, b);
        }
        Error pminub(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pminub, a, b);
        }
        Error pminub(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminub, a, b);
        }
        Error pminud(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pminud, a, b);
        }
        Error pminud(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminud, a, b);
        }
        Error pminuw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pminuw, a, b);
        }
        Error pminuw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pminuw, a, b);
        }
        Error pmovmskb(const Gp32& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmovmskb, a, b);
        }
        Error pmovmskb(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovmskb, a, b);
        }
        Error pmovsxbd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovsxbd, a, b);
        }
        Error pmovsxbd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovsxbd, a, b);
        }
        Error pmovsxbq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovsxbq, a, b);
        }
        Error pmovsxbq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovsxbq, a, b);
        }
        Error pmovsxbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovsxbw, a, b);
        }
        Error pmovsxbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovsxbw, a, b);
        }
        Error pmovsxdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovsxdq, a, b);
        }
        Error pmovsxdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovsxdq, a, b);
        }
        Error pmovsxwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovsxwd, a, b);
        }
        Error pmovsxwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovsxwd, a, b);
        }
        Error pmovsxwq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovsxwq, a, b);
        }
        Error pmovsxwq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovsxwq, a, b);
        }
        Error pmovzxbd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovzxbd, a, b);
        }
        Error pmovzxbd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovzxbd, a, b);
        }
        Error pmovzxbq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovzxbq, a, b);
        }
        Error pmovzxbq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovzxbq, a, b);
        }
        Error pmovzxbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovzxbw, a, b);
        }
        Error pmovzxbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovzxbw, a, b);
        }
        Error pmovzxdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovzxdq, a, b);
        }
        Error pmovzxdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovzxdq, a, b);
        }
        Error pmovzxwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovzxwd, a, b);
        }
        Error pmovzxwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovzxwd, a, b);
        }
        Error pmovzxwq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmovzxwq, a, b);
        }
        Error pmovzxwq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmovzxwq, a, b);
        }
        Error pmuldq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmuldq, a, b);
        }
        Error pmuldq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmuldq, a, b);
        }
        Error pmulhrsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmulhrsw, a, b);
        }
        Error pmulhrsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhrsw, a, b);
        }
        Error pmulhrsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmulhrsw, a, b);
        }
        Error pmulhrsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhrsw, a, b);
        }
        Error pmulhrw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmulhrw, a, b);
        }
        Error pmulhrw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhrw, a, b);
        }
        Error pmulhuw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmulhuw, a, b);
        }
        Error pmulhuw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhuw, a, b);
        }
        Error pmulhuw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmulhuw, a, b);
        }
        Error pmulhuw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhuw, a, b);
        }
        Error pmulhw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmulhw, a, b);
        }
        Error pmulhw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhw, a, b);
        }
        Error pmulhw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmulhw, a, b);
        }
        Error pmulhw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulhw, a, b);
        }
        Error pmulld(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmulld, a, b);
        }
        Error pmulld(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmulld, a, b);
        }
        Error pmullw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmullw, a, b);
        }
        Error pmullw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmullw, a, b);
        }
        Error pmullw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmullw, a, b);
        }
        Error pmullw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmullw, a, b);
        }
        Error pmuludq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pmuludq, a, b);
        }
        Error pmuludq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmuludq, a, b);
        }
        Error pmuludq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pmuludq, a, b);
        }
        Error pmuludq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pmuludq, a, b);
        }
        Error pop(const Seg& a)
        {
            return emit(x86::Mnemonic::Pop, a);
        }
        Error pop(const Gp& a)
        {
            return emit(x86::Mnemonic::Pop, a);
        }
        Error pop(const Mem& a)
        {
            return emit(x86::Mnemonic::Pop, a);
        }
        Error popa()
        {
            return emit(x86::Mnemonic::Popa);
        }
        Error popad()
        {
            return emit(x86::Mnemonic::Popad);
        }
        Error popcnt(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Popcnt, a, b);
        }
        Error popcnt(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Popcnt, a, b);
        }
        Error popcnt(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Popcnt, a, b);
        }
        Error popcnt(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Popcnt, a, b);
        }
        Error popf()
        {
            return emit(x86::Mnemonic::Popf);
        }
        Error popfd()
        {
            return emit(x86::Mnemonic::Popfd);
        }
        Error popfq()
        {
            return emit(x86::Mnemonic::Popfq);
        }
        Error por(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Por, a, b);
        }
        Error por(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Por, a, b);
        }
        Error por(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Por, a, b);
        }
        Error por(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Por, a, b);
        }
        Error prefetch(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetch, a);
        }
        Error prefetchnta(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetchnta, a);
        }
        Error prefetcht0(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetcht0, a);
        }
        Error prefetcht1(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetcht1, a);
        }
        Error prefetcht2(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetcht2, a);
        }
        Error prefetchw(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetchw, a);
        }
        Error prefetchwt1(const Mem& a)
        {
            return emit(x86::Mnemonic::Prefetchwt1, a);
        }
        Error psadbw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psadbw, a, b);
        }
        Error psadbw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psadbw, a, b);
        }
        Error psadbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psadbw, a, b);
        }
        Error psadbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psadbw, a, b);
        }
        Error pshufb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pshufb, a, b);
        }
        Error pshufb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pshufb, a, b);
        }
        Error pshufb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pshufb, a, b);
        }
        Error pshufb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pshufb, a, b);
        }
        Error pshufd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshufd, a, b, c);
        }
        Error pshufd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshufd, a, b, c);
        }
        Error pshufhw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshufhw, a, b, c);
        }
        Error pshufhw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshufhw, a, b, c);
        }
        Error pshuflw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshuflw, a, b, c);
        }
        Error pshuflw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshuflw, a, b, c);
        }
        Error pshufw(const Mmx& a, const Mmx& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshufw, a, b, c);
        }
        Error pshufw(const Mmx& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Pshufw, a, b, c);
        }
        Error psignb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psignb, a, b);
        }
        Error psignb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psignb, a, b);
        }
        Error psignb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psignb, a, b);
        }
        Error psignb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psignb, a, b);
        }
        Error psignd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psignd, a, b);
        }
        Error psignd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psignd, a, b);
        }
        Error psignd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psignd, a, b);
        }
        Error psignd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psignd, a, b);
        }
        Error psignw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psignw, a, b);
        }
        Error psignw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psignw, a, b);
        }
        Error psignw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psignw, a, b);
        }
        Error psignw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psignw, a, b);
        }
        Error pslld(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pslld, a, b);
        }
        Error pslld(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pslld, a, b);
        }
        Error pslld(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Pslld, a, b);
        }
        Error pslld(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pslld, a, b);
        }
        Error pslld(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pslld, a, b);
        }
        Error pslld(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Pslld, a, b);
        }
        Error pslldq(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Pslldq, a, b);
        }
        Error psllq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psllq, a, b);
        }
        Error psllq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psllq, a, b);
        }
        Error psllq(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psllq, a, b);
        }
        Error psllq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psllq, a, b);
        }
        Error psllq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psllq, a, b);
        }
        Error psllq(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psllq, a, b);
        }
        Error psllw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psllw, a, b);
        }
        Error psllw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psllw, a, b);
        }
        Error psllw(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psllw, a, b);
        }
        Error psllw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psllw, a, b);
        }
        Error psllw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psllw, a, b);
        }
        Error psllw(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psllw, a, b);
        }
        Error psmash(const Gp& a)
        {
            return emit(x86::Mnemonic::Psmash, a);
        }
        Error psrad(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psrad, a, b);
        }
        Error psrad(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrad, a, b);
        }
        Error psrad(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrad, a, b);
        }
        Error psrad(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psrad, a, b);
        }
        Error psrad(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrad, a, b);
        }
        Error psrad(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrad, a, b);
        }
        Error psraw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psraw, a, b);
        }
        Error psraw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psraw, a, b);
        }
        Error psraw(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psraw, a, b);
        }
        Error psraw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psraw, a, b);
        }
        Error psraw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psraw, a, b);
        }
        Error psraw(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psraw, a, b);
        }
        Error psrld(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psrld, a, b);
        }
        Error psrld(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrld, a, b);
        }
        Error psrld(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrld, a, b);
        }
        Error psrld(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psrld, a, b);
        }
        Error psrld(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrld, a, b);
        }
        Error psrld(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrld, a, b);
        }
        Error psrldq(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrldq, a, b);
        }
        Error psrlq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psrlq, a, b);
        }
        Error psrlq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrlq, a, b);
        }
        Error psrlq(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrlq, a, b);
        }
        Error psrlq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psrlq, a, b);
        }
        Error psrlq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrlq, a, b);
        }
        Error psrlq(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrlq, a, b);
        }
        Error psrlw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psrlw, a, b);
        }
        Error psrlw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrlw, a, b);
        }
        Error psrlw(const Mmx& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrlw, a, b);
        }
        Error psrlw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psrlw, a, b);
        }
        Error psrlw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psrlw, a, b);
        }
        Error psrlw(const Xmm& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Psrlw, a, b);
        }
        Error psubb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubb, a, b);
        }
        Error psubb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubb, a, b);
        }
        Error psubb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubb, a, b);
        }
        Error psubb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubb, a, b);
        }
        Error psubd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubd, a, b);
        }
        Error psubd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubd, a, b);
        }
        Error psubd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubd, a, b);
        }
        Error psubd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubd, a, b);
        }
        Error psubq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubq, a, b);
        }
        Error psubq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubq, a, b);
        }
        Error psubq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubq, a, b);
        }
        Error psubq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubq, a, b);
        }
        Error psubsb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubsb, a, b);
        }
        Error psubsb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubsb, a, b);
        }
        Error psubsb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubsb, a, b);
        }
        Error psubsb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubsb, a, b);
        }
        Error psubsw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubsw, a, b);
        }
        Error psubsw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubsw, a, b);
        }
        Error psubsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubsw, a, b);
        }
        Error psubsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubsw, a, b);
        }
        Error psubusb(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubusb, a, b);
        }
        Error psubusb(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubusb, a, b);
        }
        Error psubusb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubusb, a, b);
        }
        Error psubusb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubusb, a, b);
        }
        Error psubusw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubusw, a, b);
        }
        Error psubusw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubusw, a, b);
        }
        Error psubusw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubusw, a, b);
        }
        Error psubusw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubusw, a, b);
        }
        Error psubw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Psubw, a, b);
        }
        Error psubw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubw, a, b);
        }
        Error psubw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Psubw, a, b);
        }
        Error psubw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Psubw, a, b);
        }
        Error pswapd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pswapd, a, b);
        }
        Error pswapd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pswapd, a, b);
        }
        Error ptest(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Ptest, a, b);
        }
        Error ptest(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ptest, a, b);
        }
        Error ptwrite(const Gp& a)
        {
            return emit(x86::Mnemonic::Ptwrite, a);
        }
        Error ptwrite(const Mem& a)
        {
            return emit(x86::Mnemonic::Ptwrite, a);
        }
        Error punpckhbw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Punpckhbw, a, b);
        }
        Error punpckhbw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhbw, a, b);
        }
        Error punpckhbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpckhbw, a, b);
        }
        Error punpckhbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhbw, a, b);
        }
        Error punpckhdq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Punpckhdq, a, b);
        }
        Error punpckhdq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhdq, a, b);
        }
        Error punpckhdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpckhdq, a, b);
        }
        Error punpckhdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhdq, a, b);
        }
        Error punpckhqdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpckhqdq, a, b);
        }
        Error punpckhqdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhqdq, a, b);
        }
        Error punpckhwd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Punpckhwd, a, b);
        }
        Error punpckhwd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhwd, a, b);
        }
        Error punpckhwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpckhwd, a, b);
        }
        Error punpckhwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckhwd, a, b);
        }
        Error punpcklbw(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Punpcklbw, a, b);
        }
        Error punpcklbw(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpcklbw, a, b);
        }
        Error punpcklbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpcklbw, a, b);
        }
        Error punpcklbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpcklbw, a, b);
        }
        Error punpckldq(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Punpckldq, a, b);
        }
        Error punpckldq(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckldq, a, b);
        }
        Error punpckldq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpckldq, a, b);
        }
        Error punpckldq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpckldq, a, b);
        }
        Error punpcklqdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpcklqdq, a, b);
        }
        Error punpcklqdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpcklqdq, a, b);
        }
        Error punpcklwd(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Punpcklwd, a, b);
        }
        Error punpcklwd(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpcklwd, a, b);
        }
        Error punpcklwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Punpcklwd, a, b);
        }
        Error punpcklwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Punpcklwd, a, b);
        }
        Error push(const Seg& a)
        {
            return emit(x86::Mnemonic::Push, a);
        }
        Error push(const Gp& a)
        {
            return emit(x86::Mnemonic::Push, a);
        }
        Error push(const Imm& a)
        {
            return emit(x86::Mnemonic::Push, a);
        }
        Error push(const Mem& a)
        {
            return emit(x86::Mnemonic::Push, a);
        }
        Error pusha()
        {
            return emit(x86::Mnemonic::Pusha);
        }
        Error pushad()
        {
            return emit(x86::Mnemonic::Pushad);
        }
        Error pushf()
        {
            return emit(x86::Mnemonic::Pushf);
        }
        Error pushfd()
        {
            return emit(x86::Mnemonic::Pushfd);
        }
        Error pushfq()
        {
            return emit(x86::Mnemonic::Pushfq);
        }
        Error pvalidate(const Gp& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Pvalidate, a, b, c);
        }
        Error pxor(const Mmx& a, const Mmx& b)
        {
            return emit(x86::Mnemonic::Pxor, a, b);
        }
        Error pxor(const Mmx& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pxor, a, b);
        }
        Error pxor(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Pxor, a, b);
        }
        Error pxor(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Pxor, a, b);
        }
        Error rcl(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rcl, a, b);
        }
        Error rcl(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rcl, a, b);
        }
        Error rcl(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rcl, a, b);
        }
        Error rcl(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rcl, a, b);
        }
        Error rcl(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rcl, a, b);
        }
        Error rcl(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rcl, a, b);
        }
        Error rcpps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Rcpps, a, b);
        }
        Error rcpps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Rcpps, a, b);
        }
        Error rcpss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Rcpss, a, b);
        }
        Error rcpss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Rcpss, a, b);
        }
        Error rcr(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rcr, a, b);
        }
        Error rcr(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rcr, a, b);
        }
        Error rcr(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rcr, a, b);
        }
        Error rcr(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rcr, a, b);
        }
        Error rcr(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rcr, a, b);
        }
        Error rcr(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rcr, a, b);
        }
        Error rdfsbase(const Gp& a)
        {
            return emit(x86::Mnemonic::Rdfsbase, a);
        }
        Error rdgsbase(const Gp& a)
        {
            return emit(x86::Mnemonic::Rdgsbase, a);
        }
        Error rdmsr()
        {
            return emit(x86::Mnemonic::Rdmsr);
        }
        Error rdpid(const Gp64& a)
        {
            return emit(x86::Mnemonic::Rdpid, a);
        }
        Error rdpid(const Gp32& a)
        {
            return emit(x86::Mnemonic::Rdpid, a);
        }
        Error rdpkru()
        {
            return emit(x86::Mnemonic::Rdpkru);
        }
        Error rdpmc()
        {
            return emit(x86::Mnemonic::Rdpmc);
        }
        Error rdpru()
        {
            return emit(x86::Mnemonic::Rdpru);
        }
        Error rdrand(const Gp& a)
        {
            return emit(x86::Mnemonic::Rdrand, a);
        }
        Error rdseed(const Gp& a)
        {
            return emit(x86::Mnemonic::Rdseed, a);
        }
        Error rdsspd(const Gp32& a)
        {
            return emit(x86::Mnemonic::Rdsspd, a);
        }
        Error rdsspq(const Gp64& a)
        {
            return emit(x86::Mnemonic::Rdsspq, a);
        }
        Error rdtsc()
        {
            return emit(x86::Mnemonic::Rdtsc);
        }
        Error rdtscp()
        {
            return emit(x86::Mnemonic::Rdtscp);
        }
        Error ret()
        {
            return emit(x86::Mnemonic::Ret);
        }
        Error ret(const Imm& a)
        {
            return emit(x86::Mnemonic::Ret, a);
        }
        Error rmpadjust(const Gp& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Rmpadjust, a, b, c);
        }
        Error rmpupdate(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rmpupdate, a, b);
        }
        Error rol(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rol, a, b);
        }
        Error rol(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rol, a, b);
        }
        Error rol(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Rol, a, b);
        }
        Error rol(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rol, a, b);
        }
        Error rol(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rol, a, b);
        }
        Error rol(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Rol, a, b);
        }
        Error ror(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Ror, a, b);
        }
        Error ror(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Ror, a, b);
        }
        Error ror(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Ror, a, b);
        }
        Error ror(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Ror, a, b);
        }
        Error ror(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Ror, a, b);
        }
        Error ror(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Ror, a, b);
        }
        Error rorx(const Gp32& a, const Gp32& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Rorx, a, b, c);
        }
        Error rorx(const Gp64& a, const Gp64& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Rorx, a, b, c);
        }
        Error rorx(const Gp32& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Rorx, a, b, c);
        }
        Error rorx(const Gp64& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Rorx, a, b, c);
        }
        Error roundpd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundpd, a, b, c);
        }
        Error roundpd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundpd, a, b, c);
        }
        Error roundps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundps, a, b, c);
        }
        Error roundps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundps, a, b, c);
        }
        Error roundsd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundsd, a, b, c);
        }
        Error roundsd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundsd, a, b, c);
        }
        Error roundss(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundss, a, b, c);
        }
        Error roundss(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Roundss, a, b, c);
        }
        Error rsm()
        {
            return emit(x86::Mnemonic::Rsm);
        }
        Error rsqrtps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Rsqrtps, a, b);
        }
        Error rsqrtps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Rsqrtps, a, b);
        }
        Error rsqrtss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Rsqrtss, a, b);
        }
        Error rsqrtss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Rsqrtss, a, b);
        }
        Error rstorssp(const Mem& a)
        {
            return emit(x86::Mnemonic::Rstorssp, a);
        }
        Error sahf()
        {
            return emit(x86::Mnemonic::Sahf);
        }
        Error salc()
        {
            return emit(x86::Mnemonic::Salc);
        }
        Error sar(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sar, a, b);
        }
        Error sar(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sar, a, b);
        }
        Error sar(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sar, a, b);
        }
        Error sar(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sar, a, b);
        }
        Error sar(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sar, a, b);
        }
        Error sar(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sar, a, b);
        }
        Error sarx(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Sarx, a, b, c);
        }
        Error sarx(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Sarx, a, b, c);
        }
        Error sarx(const Gp32& a, const Mem& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Sarx, a, b, c);
        }
        Error sarx(const Gp64& a, const Mem& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Sarx, a, b, c);
        }
        Error saveprevssp()
        {
            return emit(x86::Mnemonic::Saveprevssp);
        }
        Error sbb(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        Error sbb(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        Error sbb(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        Error sbb(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        Error sbb(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        Error sbb(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        Error sbb(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        Error sbb(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        Error sbb(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sbb, a, b);
        }
        Error scasb()
        {
            return emit(x86::Mnemonic::Scasb);
        }
        Error scasd()
        {
            return emit(x86::Mnemonic::Scasd);
        }
        Error scasq()
        {
            return emit(x86::Mnemonic::Scasq);
        }
        Error scasw()
        {
            return emit(x86::Mnemonic::Scasw);
        }
        Error seamcall()
        {
            return emit(x86::Mnemonic::Seamcall);
        }
        Error seamops()
        {
            return emit(x86::Mnemonic::Seamops);
        }
        Error seamret()
        {
            return emit(x86::Mnemonic::Seamret);
        }
        Error senduipi(const Gp32& a)
        {
            return emit(x86::Mnemonic::Senduipi, a);
        }
        Error serialize()
        {
            return emit(x86::Mnemonic::Serialize);
        }
        Error setb(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setb, a);
        }
        Error setb(const Mem& a)
        {
            return emit(x86::Mnemonic::Setb, a);
        }
        Error setbe(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setbe, a);
        }
        Error setbe(const Mem& a)
        {
            return emit(x86::Mnemonic::Setbe, a);
        }
        Error setl(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setl, a);
        }
        Error setl(const Mem& a)
        {
            return emit(x86::Mnemonic::Setl, a);
        }
        Error setle(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setle, a);
        }
        Error setle(const Mem& a)
        {
            return emit(x86::Mnemonic::Setle, a);
        }
        Error setnb(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setnb, a);
        }
        Error setnb(const Mem& a)
        {
            return emit(x86::Mnemonic::Setnb, a);
        }
        Error setnbe(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setnbe, a);
        }
        Error setnbe(const Mem& a)
        {
            return emit(x86::Mnemonic::Setnbe, a);
        }
        Error setnl(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setnl, a);
        }
        Error setnl(const Mem& a)
        {
            return emit(x86::Mnemonic::Setnl, a);
        }
        Error setnle(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setnle, a);
        }
        Error setnle(const Mem& a)
        {
            return emit(x86::Mnemonic::Setnle, a);
        }
        Error setno(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setno, a);
        }
        Error setno(const Mem& a)
        {
            return emit(x86::Mnemonic::Setno, a);
        }
        Error setnp(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setnp, a);
        }
        Error setnp(const Mem& a)
        {
            return emit(x86::Mnemonic::Setnp, a);
        }
        Error setns(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setns, a);
        }
        Error setns(const Mem& a)
        {
            return emit(x86::Mnemonic::Setns, a);
        }
        Error setnz(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setnz, a);
        }
        Error setnz(const Mem& a)
        {
            return emit(x86::Mnemonic::Setnz, a);
        }
        Error seto(const Gp8& a)
        {
            return emit(x86::Mnemonic::Seto, a);
        }
        Error seto(const Mem& a)
        {
            return emit(x86::Mnemonic::Seto, a);
        }
        Error setp(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setp, a);
        }
        Error setp(const Mem& a)
        {
            return emit(x86::Mnemonic::Setp, a);
        }
        Error sets(const Gp8& a)
        {
            return emit(x86::Mnemonic::Sets, a);
        }
        Error sets(const Mem& a)
        {
            return emit(x86::Mnemonic::Sets, a);
        }
        Error setssbsy()
        {
            return emit(x86::Mnemonic::Setssbsy);
        }
        Error setz(const Gp8& a)
        {
            return emit(x86::Mnemonic::Setz, a);
        }
        Error setz(const Mem& a)
        {
            return emit(x86::Mnemonic::Setz, a);
        }
        Error sfence()
        {
            return emit(x86::Mnemonic::Sfence);
        }
        Error sgdt(const Mem& a)
        {
            return emit(x86::Mnemonic::Sgdt, a);
        }
        Error sha1msg1(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sha1msg1, a, b);
        }
        Error sha1msg1(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sha1msg1, a, b);
        }
        Error sha1msg2(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sha1msg2, a, b);
        }
        Error sha1msg2(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sha1msg2, a, b);
        }
        Error sha1nexte(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sha1nexte, a, b);
        }
        Error sha1nexte(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sha1nexte, a, b);
        }
        Error sha1rnds4(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Sha1rnds4, a, b, c);
        }
        Error sha1rnds4(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Sha1rnds4, a, b, c);
        }
        Error sha256msg1(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sha256msg1, a, b);
        }
        Error sha256msg1(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sha256msg1, a, b);
        }
        Error sha256msg2(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sha256msg2, a, b);
        }
        Error sha256msg2(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sha256msg2, a, b);
        }
        Error sha256rnds2(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sha256rnds2, a, b);
        }
        Error sha256rnds2(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sha256rnds2, a, b);
        }
        Error shl(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Shl, a, b);
        }
        Error shl(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Shl, a, b);
        }
        Error shl(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Shl, a, b);
        }
        Error shl(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Shl, a, b);
        }
        Error shl(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Shl, a, b);
        }
        Error shl(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Shl, a, b);
        }
        Error shld(const Gp& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Shld, a, b, c);
        }
        Error shld(const Mem& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Shld, a, b, c);
        }
        Error shld(const Gp& a, const Gp& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shld, a, b, c);
        }
        Error shld(const Mem& a, const Gp& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shld, a, b, c);
        }
        Error shlx(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Shlx, a, b, c);
        }
        Error shlx(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Shlx, a, b, c);
        }
        Error shlx(const Gp32& a, const Mem& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Shlx, a, b, c);
        }
        Error shlx(const Gp64& a, const Mem& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Shlx, a, b, c);
        }
        Error shr(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Shr, a, b);
        }
        Error shr(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Shr, a, b);
        }
        Error shr(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Shr, a, b);
        }
        Error shr(const Gp8& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Shr, a, b);
        }
        Error shr(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Shr, a, b);
        }
        Error shr(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Shr, a, b);
        }
        Error shrd(const Gp& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Shrd, a, b, c);
        }
        Error shrd(const Mem& a, const Gp& b, const Gp& c)
        {
            return emit(x86::Mnemonic::Shrd, a, b, c);
        }
        Error shrd(const Gp& a, const Gp& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shrd, a, b, c);
        }
        Error shrd(const Mem& a, const Gp& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shrd, a, b, c);
        }
        Error shrx(const Gp32& a, const Gp32& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Shrx, a, b, c);
        }
        Error shrx(const Gp64& a, const Gp64& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Shrx, a, b, c);
        }
        Error shrx(const Gp32& a, const Mem& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Shrx, a, b, c);
        }
        Error shrx(const Gp64& a, const Mem& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Shrx, a, b, c);
        }
        Error shufpd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shufpd, a, b, c);
        }
        Error shufpd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shufpd, a, b, c);
        }
        Error shufps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shufps, a, b, c);
        }
        Error shufps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Shufps, a, b, c);
        }
        Error sidt(const Mem& a)
        {
            return emit(x86::Mnemonic::Sidt, a);
        }
        Error skinit(const Gp& a)
        {
            return emit(x86::Mnemonic::Skinit, a);
        }
        Error sldt(const Gp& a)
        {
            return emit(x86::Mnemonic::Sldt, a);
        }
        Error sldt(const Mem& a)
        {
            return emit(x86::Mnemonic::Sldt, a);
        }
        Error slwpcb(const Gp& a)
        {
            return emit(x86::Mnemonic::Slwpcb, a);
        }
        Error smsw(const Gp& a)
        {
            return emit(x86::Mnemonic::Smsw, a);
        }
        Error smsw(const Mem& a)
        {
            return emit(x86::Mnemonic::Smsw, a);
        }
        Error spflt(const Gp32& a)
        {
            return emit(x86::Mnemonic::Spflt, a);
        }
        Error spflt(const Gp64& a)
        {
            return emit(x86::Mnemonic::Spflt, a);
        }
        Error sqrtpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sqrtpd, a, b);
        }
        Error sqrtpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sqrtpd, a, b);
        }
        Error sqrtps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sqrtps, a, b);
        }
        Error sqrtps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sqrtps, a, b);
        }
        Error sqrtsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sqrtsd, a, b);
        }
        Error sqrtsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sqrtsd, a, b);
        }
        Error sqrtss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Sqrtss, a, b);
        }
        Error sqrtss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sqrtss, a, b);
        }
        Error stac()
        {
            return emit(x86::Mnemonic::Stac);
        }
        Error stc()
        {
            return emit(x86::Mnemonic::Stc);
        }
        Error std()
        {
            return emit(x86::Mnemonic::Std);
        }
        Error stgi()
        {
            return emit(x86::Mnemonic::Stgi);
        }
        Error sti()
        {
            return emit(x86::Mnemonic::Sti);
        }
        Error stmxcsr(const Mem& a)
        {
            return emit(x86::Mnemonic::Stmxcsr, a);
        }
        Error stosb()
        {
            return emit(x86::Mnemonic::Stosb);
        }
        Error stosd()
        {
            return emit(x86::Mnemonic::Stosd);
        }
        Error stosq()
        {
            return emit(x86::Mnemonic::Stosq);
        }
        Error stosw()
        {
            return emit(x86::Mnemonic::Stosw);
        }
        Error str(const Gp& a)
        {
            return emit(x86::Mnemonic::Str, a);
        }
        Error str(const Mem& a)
        {
            return emit(x86::Mnemonic::Str, a);
        }
        Error sttilecfg(const Mem& a)
        {
            return emit(x86::Mnemonic::Sttilecfg, a);
        }
        Error stui()
        {
            return emit(x86::Mnemonic::Stui);
        }
        Error sub(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        Error sub(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        Error sub(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        Error sub(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        Error sub(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        Error sub(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        Error sub(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        Error sub(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        Error sub(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Sub, a, b);
        }
        Error subpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Subpd, a, b);
        }
        Error subpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Subpd, a, b);
        }
        Error subps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Subps, a, b);
        }
        Error subps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Subps, a, b);
        }
        Error subsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Subsd, a, b);
        }
        Error subsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Subsd, a, b);
        }
        Error subss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Subss, a, b);
        }
        Error subss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Subss, a, b);
        }
        Error swapgs()
        {
            return emit(x86::Mnemonic::Swapgs);
        }
        Error syscall()
        {
            return emit(x86::Mnemonic::Syscall);
        }
        Error sysenter()
        {
            return emit(x86::Mnemonic::Sysenter);
        }
        Error sysexit()
        {
            return emit(x86::Mnemonic::Sysexit);
        }
        Error sysret()
        {
            return emit(x86::Mnemonic::Sysret);
        }
        Error t1mskc(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::T1mskc, a, b);
        }
        Error t1mskc(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::T1mskc, a, b);
        }
        Error tdcall()
        {
            return emit(x86::Mnemonic::Tdcall);
        }
        Error tdpbf16ps(const Tmm& a, const Tmm& b, const Tmm& c)
        {
            return emit(x86::Mnemonic::Tdpbf16ps, a, b, c);
        }
        Error tdpbssd(const Tmm& a, const Tmm& b, const Tmm& c)
        {
            return emit(x86::Mnemonic::Tdpbssd, a, b, c);
        }
        Error tdpbsud(const Tmm& a, const Tmm& b, const Tmm& c)
        {
            return emit(x86::Mnemonic::Tdpbsud, a, b, c);
        }
        Error tdpbusd(const Tmm& a, const Tmm& b, const Tmm& c)
        {
            return emit(x86::Mnemonic::Tdpbusd, a, b, c);
        }
        Error tdpbuud(const Tmm& a, const Tmm& b, const Tmm& c)
        {
            return emit(x86::Mnemonic::Tdpbuud, a, b, c);
        }
        Error test(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        Error test(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        Error test(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        Error test(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        Error test(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        Error test(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        Error test(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Test, a, b);
        }
        Error testui()
        {
            return emit(x86::Mnemonic::Testui);
        }
        Error tileloadd(const Tmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Tileloadd, a, b);
        }
        Error tileloaddt1(const Tmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Tileloaddt1, a, b);
        }
        Error tilerelease()
        {
            return emit(x86::Mnemonic::Tilerelease);
        }
        Error tilestored(const Mem& a, const Tmm& b)
        {
            return emit(x86::Mnemonic::Tilestored, a, b);
        }
        Error tilezero(const Tmm& a)
        {
            return emit(x86::Mnemonic::Tilezero, a);
        }
        Error tlbsync()
        {
            return emit(x86::Mnemonic::Tlbsync);
        }
        Error tpause(const Gp32& a)
        {
            return emit(x86::Mnemonic::Tpause, a);
        }
        Error tzcnt(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Tzcnt, a, b);
        }
        Error tzcnt(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Tzcnt, a, b);
        }
        Error tzcnt(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Tzcnt, a, b);
        }
        Error tzcnt(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Tzcnt, a, b);
        }
        Error tzcnti(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Tzcnti, a, b);
        }
        Error tzcnti(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Tzcnti, a, b);
        }
        Error tzmsk(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Tzmsk, a, b);
        }
        Error tzmsk(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Tzmsk, a, b);
        }
        Error ucomisd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Ucomisd, a, b);
        }
        Error ucomisd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ucomisd, a, b);
        }
        Error ucomiss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Ucomiss, a, b);
        }
        Error ucomiss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ucomiss, a, b);
        }
        Error ud0(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Ud0, a, b);
        }
        Error ud0(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ud0, a, b);
        }
        Error ud1(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Ud1, a, b);
        }
        Error ud1(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Ud1, a, b);
        }
        Error ud2()
        {
            return emit(x86::Mnemonic::Ud2);
        }
        Error uiret()
        {
            return emit(x86::Mnemonic::Uiret);
        }
        Error umonitor(const Gp& a)
        {
            return emit(x86::Mnemonic::Umonitor, a);
        }
        Error umwait(const Gp32& a)
        {
            return emit(x86::Mnemonic::Umwait, a);
        }
        Error unpckhpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Unpckhpd, a, b);
        }
        Error unpckhpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Unpckhpd, a, b);
        }
        Error unpckhps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Unpckhps, a, b);
        }
        Error unpckhps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Unpckhps, a, b);
        }
        Error unpcklpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Unpcklpd, a, b);
        }
        Error unpcklpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Unpcklpd, a, b);
        }
        Error unpcklps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Unpcklps, a, b);
        }
        Error unpcklps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Unpcklps, a, b);
        }
        Error v4fmaddps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::V4fmaddps, a, b, c, d);
        }
        Error v4fmaddss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::V4fmaddss, a, b, c, d);
        }
        Error v4fnmaddps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::V4fnmaddps, a, b, c, d);
        }
        Error v4fnmaddss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::V4fnmaddss, a, b, c, d);
        }
        Error vaddnpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vaddnpd, a, b, c, d);
        }
        Error vaddnpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddnpd, a, b, c, d);
        }
        Error vaddnps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vaddnps, a, b, c, d);
        }
        Error vaddnps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddnps, a, b, c, d);
        }
        Error vaddpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c);
        }
        Error vaddpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c);
        }
        Error vaddpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c);
        }
        Error vaddpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c);
        }
        Error vaddpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c, d);
        }
        Error vaddpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c, d);
        }
        Error vaddpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c, d);
        }
        Error vaddpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c, d);
        }
        Error vaddpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c, d);
        }
        Error vaddpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddpd, a, b, c, d);
        }
        Error vaddph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vaddph, a, b, c, d);
        }
        Error vaddph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vaddph, a, b, c, d);
        }
        Error vaddph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vaddph, a, b, c, d);
        }
        Error vaddph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddph, a, b, c, d);
        }
        Error vaddph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddph, a, b, c, d);
        }
        Error vaddph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddph, a, b, c, d);
        }
        Error vaddps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c);
        }
        Error vaddps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c);
        }
        Error vaddps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c);
        }
        Error vaddps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c);
        }
        Error vaddps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c, d);
        }
        Error vaddps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c, d);
        }
        Error vaddps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c, d);
        }
        Error vaddps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c, d);
        }
        Error vaddps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c, d);
        }
        Error vaddps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddps, a, b, c, d);
        }
        Error vaddsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaddsd, a, b, c);
        }
        Error vaddsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddsd, a, b, c);
        }
        Error vaddsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vaddsd, a, b, c, d);
        }
        Error vaddsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddsd, a, b, c, d);
        }
        Error vaddsetsps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vaddsetsps, a, b, c, d);
        }
        Error vaddsetsps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddsetsps, a, b, c, d);
        }
        Error vaddsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vaddsh, a, b, c, d);
        }
        Error vaddsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddsh, a, b, c, d);
        }
        Error vaddss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaddss, a, b, c);
        }
        Error vaddss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddss, a, b, c);
        }
        Error vaddss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vaddss, a, b, c, d);
        }
        Error vaddss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vaddss, a, b, c, d);
        }
        Error vaddsubpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaddsubpd, a, b, c);
        }
        Error vaddsubpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaddsubpd, a, b, c);
        }
        Error vaddsubpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddsubpd, a, b, c);
        }
        Error vaddsubpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddsubpd, a, b, c);
        }
        Error vaddsubps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaddsubps, a, b, c);
        }
        Error vaddsubps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaddsubps, a, b, c);
        }
        Error vaddsubps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddsubps, a, b, c);
        }
        Error vaddsubps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaddsubps, a, b, c);
        }
        Error vaesdec(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaesdec, a, b, c);
        }
        Error vaesdec(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaesdec, a, b, c);
        }
        Error vaesdec(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesdec, a, b, c);
        }
        Error vaesdec(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesdec, a, b, c);
        }
        Error vaesdec(const Zmm& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vaesdec, a, b, c);
        }
        Error vaesdec(const Zmm& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesdec, a, b, c);
        }
        Error vaesdeclast(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaesdeclast, a, b, c);
        }
        Error vaesdeclast(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaesdeclast, a, b, c);
        }
        Error vaesdeclast(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesdeclast, a, b, c);
        }
        Error vaesdeclast(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesdeclast, a, b, c);
        }
        Error vaesdeclast(const Zmm& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vaesdeclast, a, b, c);
        }
        Error vaesdeclast(const Zmm& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesdeclast, a, b, c);
        }
        Error vaesenc(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaesenc, a, b, c);
        }
        Error vaesenc(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaesenc, a, b, c);
        }
        Error vaesenc(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesenc, a, b, c);
        }
        Error vaesenc(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesenc, a, b, c);
        }
        Error vaesenc(const Zmm& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vaesenc, a, b, c);
        }
        Error vaesenc(const Zmm& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesenc, a, b, c);
        }
        Error vaesenclast(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vaesenclast, a, b, c);
        }
        Error vaesenclast(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vaesenclast, a, b, c);
        }
        Error vaesenclast(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesenclast, a, b, c);
        }
        Error vaesenclast(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesenclast, a, b, c);
        }
        Error vaesenclast(const Zmm& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vaesenclast, a, b, c);
        }
        Error vaesenclast(const Zmm& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vaesenclast, a, b, c);
        }
        Error vaesimc(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vaesimc, a, b);
        }
        Error vaesimc(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vaesimc, a, b);
        }
        Error vaeskeygenassist(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vaeskeygenassist, a, b, c);
        }
        Error vaeskeygenassist(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vaeskeygenassist, a, b, c);
        }
        Error valignd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignd, a, b, c, d, e);
        }
        Error valignd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignd, a, b, c, d, e);
        }
        Error valignd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignd, a, b, c, d, e);
        }
        Error valignd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignd, a, b, c, d, e);
        }
        Error valignd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignd, a, b, c, d, e);
        }
        Error valignd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignd, a, b, c, d, e);
        }
        Error valignq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignq, a, b, c, d, e);
        }
        Error valignq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignq, a, b, c, d, e);
        }
        Error valignq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignq, a, b, c, d, e);
        }
        Error valignq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignq, a, b, c, d, e);
        }
        Error valignq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignq, a, b, c, d, e);
        }
        Error valignq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Valignq, a, b, c, d, e);
        }
        Error vandnpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c);
        }
        Error vandnpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c);
        }
        Error vandnpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c);
        }
        Error vandnpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c);
        }
        Error vandnpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c, d);
        }
        Error vandnpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c, d);
        }
        Error vandnpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c, d);
        }
        Error vandnpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c, d);
        }
        Error vandnpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c, d);
        }
        Error vandnpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandnpd, a, b, c, d);
        }
        Error vandnps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c);
        }
        Error vandnps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c);
        }
        Error vandnps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c);
        }
        Error vandnps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c);
        }
        Error vandnps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c, d);
        }
        Error vandnps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c, d);
        }
        Error vandnps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c, d);
        }
        Error vandnps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c, d);
        }
        Error vandnps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c, d);
        }
        Error vandnps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandnps, a, b, c, d);
        }
        Error vandpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c);
        }
        Error vandpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c);
        }
        Error vandpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c);
        }
        Error vandpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c);
        }
        Error vandpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c, d);
        }
        Error vandpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c, d);
        }
        Error vandpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c, d);
        }
        Error vandpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c, d);
        }
        Error vandpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c, d);
        }
        Error vandpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandpd, a, b, c, d);
        }
        Error vandps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c);
        }
        Error vandps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c);
        }
        Error vandps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c);
        }
        Error vandps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c);
        }
        Error vandps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c, d);
        }
        Error vandps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c, d);
        }
        Error vandps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c, d);
        }
        Error vandps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c, d);
        }
        Error vandps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c, d);
        }
        Error vandps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vandps, a, b, c, d);
        }
        Error vblendmpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vblendmpd, a, b, c, d);
        }
        Error vblendmpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vblendmpd, a, b, c, d);
        }
        Error vblendmpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vblendmpd, a, b, c, d);
        }
        Error vblendmpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vblendmpd, a, b, c, d);
        }
        Error vblendmpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vblendmpd, a, b, c, d);
        }
        Error vblendmpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vblendmpd, a, b, c, d);
        }
        Error vblendmps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vblendmps, a, b, c, d);
        }
        Error vblendmps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vblendmps, a, b, c, d);
        }
        Error vblendmps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vblendmps, a, b, c, d);
        }
        Error vblendmps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vblendmps, a, b, c, d);
        }
        Error vblendmps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vblendmps, a, b, c, d);
        }
        Error vblendmps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vblendmps, a, b, c, d);
        }
        Error vblendpd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendpd, a, b, c, d);
        }
        Error vblendpd(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendpd, a, b, c, d);
        }
        Error vblendpd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendpd, a, b, c, d);
        }
        Error vblendpd(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendpd, a, b, c, d);
        }
        Error vblendps(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendps, a, b, c, d);
        }
        Error vblendps(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendps, a, b, c, d);
        }
        Error vblendps(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendps, a, b, c, d);
        }
        Error vblendps(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vblendps, a, b, c, d);
        }
        Error vblendvpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vblendvpd, a, b, c, d);
        }
        Error vblendvpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vblendvpd, a, b, c, d);
        }
        Error vblendvpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vblendvpd, a, b, c, d);
        }
        Error vblendvpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vblendvpd, a, b, c, d);
        }
        Error vblendvps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vblendvps, a, b, c, d);
        }
        Error vblendvps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vblendvps, a, b, c, d);
        }
        Error vblendvps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vblendvps, a, b, c, d);
        }
        Error vblendvps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vblendvps, a, b, c, d);
        }
        Error vbroadcastf128(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vbroadcastf128, a, b);
        }
        Error vbroadcastf32x2(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x2, a, b, c);
        }
        Error vbroadcastf32x2(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x2, a, b, c);
        }
        Error vbroadcastf32x2(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x2, a, b, c);
        }
        Error vbroadcastf32x2(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x2, a, b, c);
        }
        Error vbroadcastf32x4(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x4, a, b, c);
        }
        Error vbroadcastf32x4(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x4, a, b, c);
        }
        Error vbroadcastf32x8(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf32x8, a, b, c);
        }
        Error vbroadcastf64x2(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf64x2, a, b, c);
        }
        Error vbroadcastf64x2(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf64x2, a, b, c);
        }
        Error vbroadcastf64x4(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastf64x4, a, b, c);
        }
        Error vbroadcasti128(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vbroadcasti128, a, b);
        }
        Error vbroadcasti32x2(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x2, a, b, c);
        }
        Error vbroadcasti32x2(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x2, a, b, c);
        }
        Error vbroadcasti32x2(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x2, a, b, c);
        }
        Error vbroadcasti32x2(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x2, a, b, c);
        }
        Error vbroadcasti32x2(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x2, a, b, c);
        }
        Error vbroadcasti32x2(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x2, a, b, c);
        }
        Error vbroadcasti32x4(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x4, a, b, c);
        }
        Error vbroadcasti32x4(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x4, a, b, c);
        }
        Error vbroadcasti32x8(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti32x8, a, b, c);
        }
        Error vbroadcasti64x2(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti64x2, a, b, c);
        }
        Error vbroadcasti64x2(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti64x2, a, b, c);
        }
        Error vbroadcasti64x4(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcasti64x4, a, b, c);
        }
        Error vbroadcastsd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vbroadcastsd, a, b);
        }
        Error vbroadcastsd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vbroadcastsd, a, b);
        }
        Error vbroadcastsd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastsd, a, b, c);
        }
        Error vbroadcastsd(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastsd, a, b, c);
        }
        Error vbroadcastsd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastsd, a, b, c);
        }
        Error vbroadcastsd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastsd, a, b, c);
        }
        Error vbroadcastss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b);
        }
        Error vbroadcastss(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b);
        }
        Error vbroadcastss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b);
        }
        Error vbroadcastss(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b);
        }
        Error vbroadcastss(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b, c);
        }
        Error vbroadcastss(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b, c);
        }
        Error vbroadcastss(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b, c);
        }
        Error vbroadcastss(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b, c);
        }
        Error vbroadcastss(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b, c);
        }
        Error vbroadcastss(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vbroadcastss, a, b, c);
        }
        Error vcmppd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d);
        }
        Error vcmppd(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d);
        }
        Error vcmppd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d);
        }
        Error vcmppd(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d);
        }
        Error vcmppd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d, e);
        }
        Error vcmppd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d, e);
        }
        Error vcmppd(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d, e);
        }
        Error vcmppd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d, e);
        }
        Error vcmppd(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d, e);
        }
        Error vcmppd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmppd, a, b, c, d, e);
        }
        Error vcmpph(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpph, a, b, c, d, e);
        }
        Error vcmpph(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpph, a, b, c, d, e);
        }
        Error vcmpph(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpph, a, b, c, d, e);
        }
        Error vcmpph(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpph, a, b, c, d, e);
        }
        Error vcmpph(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpph, a, b, c, d, e);
        }
        Error vcmpph(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpph, a, b, c, d, e);
        }
        Error vcmpps(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d);
        }
        Error vcmpps(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d);
        }
        Error vcmpps(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d);
        }
        Error vcmpps(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d);
        }
        Error vcmpps(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d, e);
        }
        Error vcmpps(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d, e);
        }
        Error vcmpps(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d, e);
        }
        Error vcmpps(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d, e);
        }
        Error vcmpps(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d, e);
        }
        Error vcmpps(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpps, a, b, c, d, e);
        }
        Error vcmpsd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpsd, a, b, c, d);
        }
        Error vcmpsd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpsd, a, b, c, d);
        }
        Error vcmpsd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpsd, a, b, c, d, e);
        }
        Error vcmpsd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpsd, a, b, c, d, e);
        }
        Error vcmpsh(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpsh, a, b, c, d, e);
        }
        Error vcmpsh(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpsh, a, b, c, d, e);
        }
        Error vcmpss(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpss, a, b, c, d);
        }
        Error vcmpss(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcmpss, a, b, c, d);
        }
        Error vcmpss(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpss, a, b, c, d, e);
        }
        Error vcmpss(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vcmpss, a, b, c, d, e);
        }
        Error vcomisd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcomisd, a, b);
        }
        Error vcomisd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcomisd, a, b);
        }
        Error vcomish(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcomish, a, b);
        }
        Error vcomish(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcomish, a, b);
        }
        Error vcomiss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcomiss, a, b);
        }
        Error vcomiss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcomiss, a, b);
        }
        Error vcompresspd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcompresspd, a, b, c);
        }
        Error vcompresspd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcompresspd, a, b, c);
        }
        Error vcompresspd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcompresspd, a, b, c);
        }
        Error vcompresspd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcompresspd, a, b, c);
        }
        Error vcompresspd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcompresspd, a, b, c);
        }
        Error vcompresspd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcompresspd, a, b, c);
        }
        Error vcompressps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcompressps, a, b, c);
        }
        Error vcompressps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcompressps, a, b, c);
        }
        Error vcompressps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcompressps, a, b, c);
        }
        Error vcompressps(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcompressps, a, b, c);
        }
        Error vcompressps(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcompressps, a, b, c);
        }
        Error vcompressps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcompressps, a, b, c);
        }
        Error vcvtdq2pd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b);
        }
        Error vcvtdq2pd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b);
        }
        Error vcvtdq2pd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b);
        }
        Error vcvtdq2pd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b);
        }
        Error vcvtdq2pd(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        Error vcvtdq2pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        Error vcvtdq2pd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        Error vcvtdq2pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        Error vcvtdq2pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        Error vcvtdq2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        Error vcvtdq2pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2pd, a, b, c);
        }
        Error vcvtdq2ph(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ph, a, b, c);
        }
        Error vcvtdq2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ph, a, b, c);
        }
        Error vcvtdq2ph(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ph, a, b, c);
        }
        Error vcvtdq2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ph, a, b, c);
        }
        Error vcvtdq2ph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ph, a, b, c);
        }
        Error vcvtdq2ps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b);
        }
        Error vcvtdq2ps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b);
        }
        Error vcvtdq2ps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b);
        }
        Error vcvtdq2ps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b);
        }
        Error vcvtdq2ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b, c);
        }
        Error vcvtdq2ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b, c);
        }
        Error vcvtdq2ps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b, c);
        }
        Error vcvtdq2ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b, c);
        }
        Error vcvtdq2ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b, c);
        }
        Error vcvtdq2ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtdq2ps, a, b, c);
        }
        Error vcvtfxpntdq2ps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntdq2ps, a, b, c, d);
        }
        Error vcvtfxpntdq2ps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntdq2ps, a, b, c, d);
        }
        Error vcvtfxpntpd2dq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntpd2dq, a, b, c, d);
        }
        Error vcvtfxpntpd2dq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntpd2dq, a, b, c, d);
        }
        Error vcvtfxpntpd2udq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntpd2udq, a, b, c, d);
        }
        Error vcvtfxpntpd2udq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntpd2udq, a, b, c, d);
        }
        Error vcvtfxpntps2dq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntps2dq, a, b, c, d);
        }
        Error vcvtfxpntps2dq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntps2dq, a, b, c, d);
        }
        Error vcvtfxpntps2udq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntps2udq, a, b, c, d);
        }
        Error vcvtfxpntps2udq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntps2udq, a, b, c, d);
        }
        Error vcvtfxpntudq2ps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntudq2ps, a, b, c, d);
        }
        Error vcvtfxpntudq2ps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtfxpntudq2ps, a, b, c, d);
        }
        Error vcvtne2ps2bf16(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtne2ps2bf16, a, b, c, d);
        }
        Error vcvtne2ps2bf16(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vcvtne2ps2bf16, a, b, c, d);
        }
        Error vcvtne2ps2bf16(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vcvtne2ps2bf16, a, b, c, d);
        }
        Error vcvtne2ps2bf16(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtne2ps2bf16, a, b, c, d);
        }
        Error vcvtne2ps2bf16(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtne2ps2bf16, a, b, c, d);
        }
        Error vcvtne2ps2bf16(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtne2ps2bf16, a, b, c, d);
        }
        Error vcvtneps2bf16(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtneps2bf16, a, b, c);
        }
        Error vcvtneps2bf16(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtneps2bf16, a, b, c);
        }
        Error vcvtneps2bf16(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtneps2bf16, a, b, c);
        }
        Error vcvtneps2bf16(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtneps2bf16, a, b, c);
        }
        Error vcvtneps2bf16(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtneps2bf16, a, b, c);
        }
        Error vcvtpd2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b);
        }
        Error vcvtpd2dq(const Xmm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b);
        }
        Error vcvtpd2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b);
        }
        Error vcvtpd2dq(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b, c);
        }
        Error vcvtpd2dq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b, c);
        }
        Error vcvtpd2dq(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b, c);
        }
        Error vcvtpd2dq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b, c);
        }
        Error vcvtpd2dq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2dq, a, b, c);
        }
        Error vcvtpd2ph(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ph, a, b, c);
        }
        Error vcvtpd2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ph, a, b, c);
        }
        Error vcvtpd2ph(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ph, a, b, c);
        }
        Error vcvtpd2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ph, a, b, c);
        }
        Error vcvtpd2ps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b);
        }
        Error vcvtpd2ps(const Xmm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b);
        }
        Error vcvtpd2ps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b);
        }
        Error vcvtpd2ps(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        Error vcvtpd2ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        Error vcvtpd2ps(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        Error vcvtpd2ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        Error vcvtpd2ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        Error vcvtpd2ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        Error vcvtpd2ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2ps, a, b, c);
        }
        Error vcvtpd2qq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2qq, a, b, c);
        }
        Error vcvtpd2qq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2qq, a, b, c);
        }
        Error vcvtpd2qq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2qq, a, b, c);
        }
        Error vcvtpd2qq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2qq, a, b, c);
        }
        Error vcvtpd2qq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2qq, a, b, c);
        }
        Error vcvtpd2qq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2qq, a, b, c);
        }
        Error vcvtpd2udq(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2udq, a, b, c);
        }
        Error vcvtpd2udq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2udq, a, b, c);
        }
        Error vcvtpd2udq(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2udq, a, b, c);
        }
        Error vcvtpd2udq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2udq, a, b, c);
        }
        Error vcvtpd2udq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2udq, a, b, c);
        }
        Error vcvtpd2uqq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2uqq, a, b, c);
        }
        Error vcvtpd2uqq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2uqq, a, b, c);
        }
        Error vcvtpd2uqq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2uqq, a, b, c);
        }
        Error vcvtpd2uqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2uqq, a, b, c);
        }
        Error vcvtpd2uqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2uqq, a, b, c);
        }
        Error vcvtpd2uqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtpd2uqq, a, b, c);
        }
        Error vcvtph2dq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2dq, a, b, c);
        }
        Error vcvtph2dq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2dq, a, b, c);
        }
        Error vcvtph2dq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2dq, a, b, c);
        }
        Error vcvtph2dq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2dq, a, b, c);
        }
        Error vcvtph2dq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2dq, a, b, c);
        }
        Error vcvtph2dq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2dq, a, b, c);
        }
        Error vcvtph2pd(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2pd, a, b, c);
        }
        Error vcvtph2pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2pd, a, b, c);
        }
        Error vcvtph2pd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2pd, a, b, c);
        }
        Error vcvtph2pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2pd, a, b, c);
        }
        Error vcvtph2pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2pd, a, b, c);
        }
        Error vcvtph2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2pd, a, b, c);
        }
        Error vcvtph2ps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b);
        }
        Error vcvtph2ps(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b);
        }
        Error vcvtph2ps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b);
        }
        Error vcvtph2ps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b);
        }
        Error vcvtph2ps(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b, c);
        }
        Error vcvtph2ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b, c);
        }
        Error vcvtph2ps(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b, c);
        }
        Error vcvtph2ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b, c);
        }
        Error vcvtph2ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b, c);
        }
        Error vcvtph2ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2ps, a, b, c);
        }
        Error vcvtph2psx(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2psx, a, b, c);
        }
        Error vcvtph2psx(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2psx, a, b, c);
        }
        Error vcvtph2psx(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2psx, a, b, c);
        }
        Error vcvtph2psx(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2psx, a, b, c);
        }
        Error vcvtph2psx(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2psx, a, b, c);
        }
        Error vcvtph2psx(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2psx, a, b, c);
        }
        Error vcvtph2qq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2qq, a, b, c);
        }
        Error vcvtph2qq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2qq, a, b, c);
        }
        Error vcvtph2qq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2qq, a, b, c);
        }
        Error vcvtph2qq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2qq, a, b, c);
        }
        Error vcvtph2qq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2qq, a, b, c);
        }
        Error vcvtph2qq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2qq, a, b, c);
        }
        Error vcvtph2udq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2udq, a, b, c);
        }
        Error vcvtph2udq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2udq, a, b, c);
        }
        Error vcvtph2udq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2udq, a, b, c);
        }
        Error vcvtph2udq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2udq, a, b, c);
        }
        Error vcvtph2udq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2udq, a, b, c);
        }
        Error vcvtph2udq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2udq, a, b, c);
        }
        Error vcvtph2uqq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uqq, a, b, c);
        }
        Error vcvtph2uqq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uqq, a, b, c);
        }
        Error vcvtph2uqq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uqq, a, b, c);
        }
        Error vcvtph2uqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uqq, a, b, c);
        }
        Error vcvtph2uqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uqq, a, b, c);
        }
        Error vcvtph2uqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uqq, a, b, c);
        }
        Error vcvtph2uw(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uw, a, b, c);
        }
        Error vcvtph2uw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uw, a, b, c);
        }
        Error vcvtph2uw(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uw, a, b, c);
        }
        Error vcvtph2uw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uw, a, b, c);
        }
        Error vcvtph2uw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uw, a, b, c);
        }
        Error vcvtph2uw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2uw, a, b, c);
        }
        Error vcvtph2w(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2w, a, b, c);
        }
        Error vcvtph2w(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2w, a, b, c);
        }
        Error vcvtph2w(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtph2w, a, b, c);
        }
        Error vcvtph2w(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2w, a, b, c);
        }
        Error vcvtph2w(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2w, a, b, c);
        }
        Error vcvtph2w(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtph2w, a, b, c);
        }
        Error vcvtps2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b);
        }
        Error vcvtps2dq(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b);
        }
        Error vcvtps2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b);
        }
        Error vcvtps2dq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b);
        }
        Error vcvtps2dq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b, c);
        }
        Error vcvtps2dq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b, c);
        }
        Error vcvtps2dq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b, c);
        }
        Error vcvtps2dq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b, c);
        }
        Error vcvtps2dq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b, c);
        }
        Error vcvtps2dq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2dq, a, b, c);
        }
        Error vcvtps2pd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b);
        }
        Error vcvtps2pd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b);
        }
        Error vcvtps2pd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b);
        }
        Error vcvtps2pd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b);
        }
        Error vcvtps2pd(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        Error vcvtps2pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        Error vcvtps2pd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        Error vcvtps2pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        Error vcvtps2pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        Error vcvtps2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        Error vcvtps2pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2pd, a, b, c);
        }
        Error vcvtps2ph(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c);
        }
        Error vcvtps2ph(const Xmm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c);
        }
        Error vcvtps2ph(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c);
        }
        Error vcvtps2ph(const Mem& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c);
        }
        Error vcvtps2ph(const Ymm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c, d);
        }
        Error vcvtps2ph(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c, d);
        }
        Error vcvtps2ph(const Xmm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c, d);
        }
        Error vcvtps2ph(const Mem& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c, d);
        }
        Error vcvtps2ph(const Mem& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c, d);
        }
        Error vcvtps2ph(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vcvtps2ph, a, b, c, d);
        }
        Error vcvtps2phx(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2phx, a, b, c);
        }
        Error vcvtps2phx(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2phx, a, b, c);
        }
        Error vcvtps2phx(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2phx, a, b, c);
        }
        Error vcvtps2phx(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2phx, a, b, c);
        }
        Error vcvtps2phx(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2phx, a, b, c);
        }
        Error vcvtps2qq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2qq, a, b, c);
        }
        Error vcvtps2qq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2qq, a, b, c);
        }
        Error vcvtps2qq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2qq, a, b, c);
        }
        Error vcvtps2qq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2qq, a, b, c);
        }
        Error vcvtps2qq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2qq, a, b, c);
        }
        Error vcvtps2qq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2qq, a, b, c);
        }
        Error vcvtps2udq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2udq, a, b, c);
        }
        Error vcvtps2udq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2udq, a, b, c);
        }
        Error vcvtps2udq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2udq, a, b, c);
        }
        Error vcvtps2udq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2udq, a, b, c);
        }
        Error vcvtps2udq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2udq, a, b, c);
        }
        Error vcvtps2udq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2udq, a, b, c);
        }
        Error vcvtps2uqq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2uqq, a, b, c);
        }
        Error vcvtps2uqq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2uqq, a, b, c);
        }
        Error vcvtps2uqq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtps2uqq, a, b, c);
        }
        Error vcvtps2uqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2uqq, a, b, c);
        }
        Error vcvtps2uqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2uqq, a, b, c);
        }
        Error vcvtps2uqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtps2uqq, a, b, c);
        }
        Error vcvtqq2pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2pd, a, b, c);
        }
        Error vcvtqq2pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2pd, a, b, c);
        }
        Error vcvtqq2pd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2pd, a, b, c);
        }
        Error vcvtqq2pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2pd, a, b, c);
        }
        Error vcvtqq2pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2pd, a, b, c);
        }
        Error vcvtqq2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2pd, a, b, c);
        }
        Error vcvtqq2ph(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ph, a, b, c);
        }
        Error vcvtqq2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ph, a, b, c);
        }
        Error vcvtqq2ph(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ph, a, b, c);
        }
        Error vcvtqq2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ph, a, b, c);
        }
        Error vcvtqq2ps(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ps, a, b, c);
        }
        Error vcvtqq2ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ps, a, b, c);
        }
        Error vcvtqq2ps(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ps, a, b, c);
        }
        Error vcvtqq2ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ps, a, b, c);
        }
        Error vcvtqq2ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtqq2ps, a, b, c);
        }
        Error vcvtsd2sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtsd2sh, a, b, c, d);
        }
        Error vcvtsd2sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtsd2sh, a, b, c, d);
        }
        Error vcvtsd2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2si, a, b);
        }
        Error vcvtsd2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2si, a, b);
        }
        Error vcvtsd2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2si, a, b);
        }
        Error vcvtsd2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2si, a, b);
        }
        Error vcvtsd2ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtsd2ss, a, b, c);
        }
        Error vcvtsd2ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtsd2ss, a, b, c);
        }
        Error vcvtsd2ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtsd2ss, a, b, c, d);
        }
        Error vcvtsd2ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtsd2ss, a, b, c, d);
        }
        Error vcvtsd2usi(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2usi, a, b);
        }
        Error vcvtsd2usi(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2usi, a, b);
        }
        Error vcvtsd2usi(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2usi, a, b);
        }
        Error vcvtsd2usi(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsd2usi, a, b);
        }
        Error vcvtsh2sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtsh2sd, a, b, c, d);
        }
        Error vcvtsh2sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtsh2sd, a, b, c, d);
        }
        Error vcvtsh2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2si, a, b);
        }
        Error vcvtsh2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2si, a, b);
        }
        Error vcvtsh2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2si, a, b);
        }
        Error vcvtsh2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2si, a, b);
        }
        Error vcvtsh2ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtsh2ss, a, b, c, d);
        }
        Error vcvtsh2ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtsh2ss, a, b, c, d);
        }
        Error vcvtsh2usi(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2usi, a, b);
        }
        Error vcvtsh2usi(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2usi, a, b);
        }
        Error vcvtsh2usi(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2usi, a, b);
        }
        Error vcvtsh2usi(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtsh2usi, a, b);
        }
        Error vcvtsi2sd(const Xmm& a, const Xmm& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2sd, a, b, c);
        }
        Error vcvtsi2sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2sd, a, b, c);
        }
        Error vcvtsi2sd(const Xmm& a, const Xmm& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2sd, a, b, c);
        }
        Error vcvtsi2sh(const Xmm& a, const Xmm& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2sh, a, b, c);
        }
        Error vcvtsi2sh(const Xmm& a, const Xmm& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2sh, a, b, c);
        }
        Error vcvtsi2sh(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2sh, a, b, c);
        }
        Error vcvtsi2ss(const Xmm& a, const Xmm& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2ss, a, b, c);
        }
        Error vcvtsi2ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2ss, a, b, c);
        }
        Error vcvtsi2ss(const Xmm& a, const Xmm& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vcvtsi2ss, a, b, c);
        }
        Error vcvtss2sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtss2sd, a, b, c);
        }
        Error vcvtss2sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtss2sd, a, b, c);
        }
        Error vcvtss2sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtss2sd, a, b, c, d);
        }
        Error vcvtss2sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtss2sd, a, b, c, d);
        }
        Error vcvtss2sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vcvtss2sh, a, b, c, d);
        }
        Error vcvtss2sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vcvtss2sh, a, b, c, d);
        }
        Error vcvtss2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtss2si, a, b);
        }
        Error vcvtss2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtss2si, a, b);
        }
        Error vcvtss2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtss2si, a, b);
        }
        Error vcvtss2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtss2si, a, b);
        }
        Error vcvtss2usi(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtss2usi, a, b);
        }
        Error vcvtss2usi(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtss2usi, a, b);
        }
        Error vcvtss2usi(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvtss2usi, a, b);
        }
        Error vcvtss2usi(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvtss2usi, a, b);
        }
        Error vcvttpd2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b);
        }
        Error vcvttpd2dq(const Xmm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b);
        }
        Error vcvttpd2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b);
        }
        Error vcvttpd2dq(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b, c);
        }
        Error vcvttpd2dq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b, c);
        }
        Error vcvttpd2dq(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b, c);
        }
        Error vcvttpd2dq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b, c);
        }
        Error vcvttpd2dq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2dq, a, b, c);
        }
        Error vcvttpd2qq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2qq, a, b, c);
        }
        Error vcvttpd2qq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2qq, a, b, c);
        }
        Error vcvttpd2qq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2qq, a, b, c);
        }
        Error vcvttpd2qq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2qq, a, b, c);
        }
        Error vcvttpd2qq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2qq, a, b, c);
        }
        Error vcvttpd2qq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2qq, a, b, c);
        }
        Error vcvttpd2udq(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2udq, a, b, c);
        }
        Error vcvttpd2udq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2udq, a, b, c);
        }
        Error vcvttpd2udq(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2udq, a, b, c);
        }
        Error vcvttpd2udq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2udq, a, b, c);
        }
        Error vcvttpd2udq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2udq, a, b, c);
        }
        Error vcvttpd2uqq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2uqq, a, b, c);
        }
        Error vcvttpd2uqq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2uqq, a, b, c);
        }
        Error vcvttpd2uqq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2uqq, a, b, c);
        }
        Error vcvttpd2uqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2uqq, a, b, c);
        }
        Error vcvttpd2uqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2uqq, a, b, c);
        }
        Error vcvttpd2uqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttpd2uqq, a, b, c);
        }
        Error vcvttph2dq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2dq, a, b, c);
        }
        Error vcvttph2dq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2dq, a, b, c);
        }
        Error vcvttph2dq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2dq, a, b, c);
        }
        Error vcvttph2dq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2dq, a, b, c);
        }
        Error vcvttph2dq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2dq, a, b, c);
        }
        Error vcvttph2dq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2dq, a, b, c);
        }
        Error vcvttph2qq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2qq, a, b, c);
        }
        Error vcvttph2qq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2qq, a, b, c);
        }
        Error vcvttph2qq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2qq, a, b, c);
        }
        Error vcvttph2qq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2qq, a, b, c);
        }
        Error vcvttph2qq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2qq, a, b, c);
        }
        Error vcvttph2qq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2qq, a, b, c);
        }
        Error vcvttph2udq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2udq, a, b, c);
        }
        Error vcvttph2udq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2udq, a, b, c);
        }
        Error vcvttph2udq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2udq, a, b, c);
        }
        Error vcvttph2udq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2udq, a, b, c);
        }
        Error vcvttph2udq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2udq, a, b, c);
        }
        Error vcvttph2udq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2udq, a, b, c);
        }
        Error vcvttph2uqq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uqq, a, b, c);
        }
        Error vcvttph2uqq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uqq, a, b, c);
        }
        Error vcvttph2uqq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uqq, a, b, c);
        }
        Error vcvttph2uqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uqq, a, b, c);
        }
        Error vcvttph2uqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uqq, a, b, c);
        }
        Error vcvttph2uqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uqq, a, b, c);
        }
        Error vcvttph2uw(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uw, a, b, c);
        }
        Error vcvttph2uw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uw, a, b, c);
        }
        Error vcvttph2uw(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uw, a, b, c);
        }
        Error vcvttph2uw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uw, a, b, c);
        }
        Error vcvttph2uw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uw, a, b, c);
        }
        Error vcvttph2uw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2uw, a, b, c);
        }
        Error vcvttph2w(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2w, a, b, c);
        }
        Error vcvttph2w(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2w, a, b, c);
        }
        Error vcvttph2w(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttph2w, a, b, c);
        }
        Error vcvttph2w(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2w, a, b, c);
        }
        Error vcvttph2w(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2w, a, b, c);
        }
        Error vcvttph2w(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttph2w, a, b, c);
        }
        Error vcvttps2dq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b);
        }
        Error vcvttps2dq(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b);
        }
        Error vcvttps2dq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b);
        }
        Error vcvttps2dq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b);
        }
        Error vcvttps2dq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b, c);
        }
        Error vcvttps2dq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b, c);
        }
        Error vcvttps2dq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b, c);
        }
        Error vcvttps2dq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b, c);
        }
        Error vcvttps2dq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b, c);
        }
        Error vcvttps2dq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2dq, a, b, c);
        }
        Error vcvttps2qq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2qq, a, b, c);
        }
        Error vcvttps2qq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2qq, a, b, c);
        }
        Error vcvttps2qq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2qq, a, b, c);
        }
        Error vcvttps2qq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2qq, a, b, c);
        }
        Error vcvttps2qq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2qq, a, b, c);
        }
        Error vcvttps2qq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2qq, a, b, c);
        }
        Error vcvttps2udq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2udq, a, b, c);
        }
        Error vcvttps2udq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2udq, a, b, c);
        }
        Error vcvttps2udq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2udq, a, b, c);
        }
        Error vcvttps2udq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2udq, a, b, c);
        }
        Error vcvttps2udq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2udq, a, b, c);
        }
        Error vcvttps2udq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2udq, a, b, c);
        }
        Error vcvttps2uqq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2uqq, a, b, c);
        }
        Error vcvttps2uqq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2uqq, a, b, c);
        }
        Error vcvttps2uqq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvttps2uqq, a, b, c);
        }
        Error vcvttps2uqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2uqq, a, b, c);
        }
        Error vcvttps2uqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2uqq, a, b, c);
        }
        Error vcvttps2uqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvttps2uqq, a, b, c);
        }
        Error vcvttsd2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2si, a, b);
        }
        Error vcvttsd2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2si, a, b);
        }
        Error vcvttsd2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2si, a, b);
        }
        Error vcvttsd2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2si, a, b);
        }
        Error vcvttsd2usi(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2usi, a, b);
        }
        Error vcvttsd2usi(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2usi, a, b);
        }
        Error vcvttsd2usi(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2usi, a, b);
        }
        Error vcvttsd2usi(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsd2usi, a, b);
        }
        Error vcvttsh2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2si, a, b);
        }
        Error vcvttsh2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2si, a, b);
        }
        Error vcvttsh2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2si, a, b);
        }
        Error vcvttsh2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2si, a, b);
        }
        Error vcvttsh2usi(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2usi, a, b);
        }
        Error vcvttsh2usi(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2usi, a, b);
        }
        Error vcvttsh2usi(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2usi, a, b);
        }
        Error vcvttsh2usi(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttsh2usi, a, b);
        }
        Error vcvttss2si(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttss2si, a, b);
        }
        Error vcvttss2si(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttss2si, a, b);
        }
        Error vcvttss2si(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttss2si, a, b);
        }
        Error vcvttss2si(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttss2si, a, b);
        }
        Error vcvttss2usi(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttss2usi, a, b);
        }
        Error vcvttss2usi(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttss2usi, a, b);
        }
        Error vcvttss2usi(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vcvttss2usi, a, b);
        }
        Error vcvttss2usi(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vcvttss2usi, a, b);
        }
        Error vcvtudq2pd(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        Error vcvtudq2pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        Error vcvtudq2pd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        Error vcvtudq2pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        Error vcvtudq2pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        Error vcvtudq2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        Error vcvtudq2pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2pd, a, b, c);
        }
        Error vcvtudq2ph(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ph, a, b, c);
        }
        Error vcvtudq2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ph, a, b, c);
        }
        Error vcvtudq2ph(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ph, a, b, c);
        }
        Error vcvtudq2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ph, a, b, c);
        }
        Error vcvtudq2ph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ph, a, b, c);
        }
        Error vcvtudq2ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ps, a, b, c);
        }
        Error vcvtudq2ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ps, a, b, c);
        }
        Error vcvtudq2ps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ps, a, b, c);
        }
        Error vcvtudq2ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ps, a, b, c);
        }
        Error vcvtudq2ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ps, a, b, c);
        }
        Error vcvtudq2ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtudq2ps, a, b, c);
        }
        Error vcvtuqq2pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2pd, a, b, c);
        }
        Error vcvtuqq2pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2pd, a, b, c);
        }
        Error vcvtuqq2pd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2pd, a, b, c);
        }
        Error vcvtuqq2pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2pd, a, b, c);
        }
        Error vcvtuqq2pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2pd, a, b, c);
        }
        Error vcvtuqq2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2pd, a, b, c);
        }
        Error vcvtuqq2ph(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ph, a, b, c);
        }
        Error vcvtuqq2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ph, a, b, c);
        }
        Error vcvtuqq2ph(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ph, a, b, c);
        }
        Error vcvtuqq2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ph, a, b, c);
        }
        Error vcvtuqq2ps(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ps, a, b, c);
        }
        Error vcvtuqq2ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ps, a, b, c);
        }
        Error vcvtuqq2ps(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ps, a, b, c);
        }
        Error vcvtuqq2ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ps, a, b, c);
        }
        Error vcvtuqq2ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuqq2ps, a, b, c);
        }
        Error vcvtusi2sd(const Xmm& a, const Xmm& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2sd, a, b, c);
        }
        Error vcvtusi2sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2sd, a, b, c);
        }
        Error vcvtusi2sd(const Xmm& a, const Xmm& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2sd, a, b, c);
        }
        Error vcvtusi2sh(const Xmm& a, const Xmm& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2sh, a, b, c);
        }
        Error vcvtusi2sh(const Xmm& a, const Xmm& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2sh, a, b, c);
        }
        Error vcvtusi2sh(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2sh, a, b, c);
        }
        Error vcvtusi2ss(const Xmm& a, const Xmm& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2ss, a, b, c);
        }
        Error vcvtusi2ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2ss, a, b, c);
        }
        Error vcvtusi2ss(const Xmm& a, const Xmm& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vcvtusi2ss, a, b, c);
        }
        Error vcvtuw2ph(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuw2ph, a, b, c);
        }
        Error vcvtuw2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtuw2ph, a, b, c);
        }
        Error vcvtuw2ph(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtuw2ph, a, b, c);
        }
        Error vcvtuw2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuw2ph, a, b, c);
        }
        Error vcvtuw2ph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuw2ph, a, b, c);
        }
        Error vcvtuw2ph(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtuw2ph, a, b, c);
        }
        Error vcvtw2ph(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vcvtw2ph, a, b, c);
        }
        Error vcvtw2ph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vcvtw2ph, a, b, c);
        }
        Error vcvtw2ph(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vcvtw2ph, a, b, c);
        }
        Error vcvtw2ph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtw2ph, a, b, c);
        }
        Error vcvtw2ph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtw2ph, a, b, c);
        }
        Error vcvtw2ph(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vcvtw2ph, a, b, c);
        }
        Error vdbpsadbw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vdbpsadbw, a, b, c, d, e);
        }
        Error vdbpsadbw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vdbpsadbw, a, b, c, d, e);
        }
        Error vdbpsadbw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vdbpsadbw, a, b, c, d, e);
        }
        Error vdbpsadbw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vdbpsadbw, a, b, c, d, e);
        }
        Error vdbpsadbw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vdbpsadbw, a, b, c, d, e);
        }
        Error vdbpsadbw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vdbpsadbw, a, b, c, d, e);
        }
        Error vdivpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c);
        }
        Error vdivpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c);
        }
        Error vdivpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c);
        }
        Error vdivpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c);
        }
        Error vdivpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c, d);
        }
        Error vdivpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c, d);
        }
        Error vdivpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c, d);
        }
        Error vdivpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c, d);
        }
        Error vdivpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c, d);
        }
        Error vdivpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivpd, a, b, c, d);
        }
        Error vdivph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vdivph, a, b, c, d);
        }
        Error vdivph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdivph, a, b, c, d);
        }
        Error vdivph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vdivph, a, b, c, d);
        }
        Error vdivph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivph, a, b, c, d);
        }
        Error vdivph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivph, a, b, c, d);
        }
        Error vdivph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivph, a, b, c, d);
        }
        Error vdivps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c);
        }
        Error vdivps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c);
        }
        Error vdivps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c);
        }
        Error vdivps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c);
        }
        Error vdivps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c, d);
        }
        Error vdivps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c, d);
        }
        Error vdivps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c, d);
        }
        Error vdivps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c, d);
        }
        Error vdivps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c, d);
        }
        Error vdivps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivps, a, b, c, d);
        }
        Error vdivsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vdivsd, a, b, c);
        }
        Error vdivsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vdivsd, a, b, c);
        }
        Error vdivsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdivsd, a, b, c, d);
        }
        Error vdivsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivsd, a, b, c, d);
        }
        Error vdivsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdivsh, a, b, c, d);
        }
        Error vdivsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivsh, a, b, c, d);
        }
        Error vdivss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vdivss, a, b, c);
        }
        Error vdivss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vdivss, a, b, c);
        }
        Error vdivss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdivss, a, b, c, d);
        }
        Error vdivss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdivss, a, b, c, d);
        }
        Error vdpbf16ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vdpbf16ps, a, b, c, d);
        }
        Error vdpbf16ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vdpbf16ps, a, b, c, d);
        }
        Error vdpbf16ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vdpbf16ps, a, b, c, d);
        }
        Error vdpbf16ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdpbf16ps, a, b, c, d);
        }
        Error vdpbf16ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdpbf16ps, a, b, c, d);
        }
        Error vdpbf16ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vdpbf16ps, a, b, c, d);
        }
        Error vdppd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vdppd, a, b, c, d);
        }
        Error vdppd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vdppd, a, b, c, d);
        }
        Error vdpps(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vdpps, a, b, c, d);
        }
        Error vdpps(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vdpps, a, b, c, d);
        }
        Error vdpps(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vdpps, a, b, c, d);
        }
        Error vdpps(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vdpps, a, b, c, d);
        }
        Error verr(const Gp16& a)
        {
            return emit(x86::Mnemonic::Verr, a);
        }
        Error verr(const Mem& a)
        {
            return emit(x86::Mnemonic::Verr, a);
        }
        Error verw(const Gp16& a)
        {
            return emit(x86::Mnemonic::Verw, a);
        }
        Error verw(const Mem& a)
        {
            return emit(x86::Mnemonic::Verw, a);
        }
        Error vexp223ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vexp223ps, a, b, c);
        }
        Error vexp223ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexp223ps, a, b, c);
        }
        Error vexp2pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vexp2pd, a, b, c);
        }
        Error vexp2pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexp2pd, a, b, c);
        }
        Error vexp2ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vexp2ps, a, b, c);
        }
        Error vexp2ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexp2ps, a, b, c);
        }
        Error vexpandpd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vexpandpd, a, b, c);
        }
        Error vexpandpd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vexpandpd, a, b, c);
        }
        Error vexpandpd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vexpandpd, a, b, c);
        }
        Error vexpandpd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexpandpd, a, b, c);
        }
        Error vexpandpd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexpandpd, a, b, c);
        }
        Error vexpandpd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexpandpd, a, b, c);
        }
        Error vexpandps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vexpandps, a, b, c);
        }
        Error vexpandps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vexpandps, a, b, c);
        }
        Error vexpandps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vexpandps, a, b, c);
        }
        Error vexpandps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexpandps, a, b, c);
        }
        Error vexpandps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexpandps, a, b, c);
        }
        Error vexpandps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vexpandps, a, b, c);
        }
        Error vextractf128(const Xmm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vextractf128, a, b, c);
        }
        Error vextractf128(const Mem& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vextractf128, a, b, c);
        }
        Error vextractf32x4(const Xmm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf32x4, a, b, c, d);
        }
        Error vextractf32x4(const Xmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf32x4, a, b, c, d);
        }
        Error vextractf32x4(const Mem& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf32x4, a, b, c, d);
        }
        Error vextractf32x4(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf32x4, a, b, c, d);
        }
        Error vextractf32x8(const Ymm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf32x8, a, b, c, d);
        }
        Error vextractf32x8(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf32x8, a, b, c, d);
        }
        Error vextractf64x2(const Xmm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf64x2, a, b, c, d);
        }
        Error vextractf64x2(const Xmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf64x2, a, b, c, d);
        }
        Error vextractf64x2(const Mem& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf64x2, a, b, c, d);
        }
        Error vextractf64x2(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf64x2, a, b, c, d);
        }
        Error vextractf64x4(const Ymm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf64x4, a, b, c, d);
        }
        Error vextractf64x4(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextractf64x4, a, b, c, d);
        }
        Error vextracti128(const Xmm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vextracti128, a, b, c);
        }
        Error vextracti128(const Mem& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vextracti128, a, b, c);
        }
        Error vextracti32x4(const Xmm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti32x4, a, b, c, d);
        }
        Error vextracti32x4(const Xmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti32x4, a, b, c, d);
        }
        Error vextracti32x4(const Mem& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti32x4, a, b, c, d);
        }
        Error vextracti32x4(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti32x4, a, b, c, d);
        }
        Error vextracti32x8(const Ymm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti32x8, a, b, c, d);
        }
        Error vextracti32x8(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti32x8, a, b, c, d);
        }
        Error vextracti64x2(const Xmm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti64x2, a, b, c, d);
        }
        Error vextracti64x2(const Xmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti64x2, a, b, c, d);
        }
        Error vextracti64x2(const Mem& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti64x2, a, b, c, d);
        }
        Error vextracti64x2(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti64x2, a, b, c, d);
        }
        Error vextracti64x4(const Ymm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti64x4, a, b, c, d);
        }
        Error vextracti64x4(const Mem& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vextracti64x4, a, b, c, d);
        }
        Error vextractps(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vextractps, a, b, c);
        }
        Error vextractps(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vextractps, a, b, c);
        }
        Error vfcmaddcph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcph, a, b, c, d);
        }
        Error vfcmaddcph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcph, a, b, c, d);
        }
        Error vfcmaddcph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcph, a, b, c, d);
        }
        Error vfcmaddcph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcph, a, b, c, d);
        }
        Error vfcmaddcph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcph, a, b, c, d);
        }
        Error vfcmaddcph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcph, a, b, c, d);
        }
        Error vfcmaddcsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcsh, a, b, c, d);
        }
        Error vfcmaddcsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmaddcsh, a, b, c, d);
        }
        Error vfcmulcph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfcmulcph, a, b, c, d);
        }
        Error vfcmulcph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfcmulcph, a, b, c, d);
        }
        Error vfcmulcph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfcmulcph, a, b, c, d);
        }
        Error vfcmulcph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmulcph, a, b, c, d);
        }
        Error vfcmulcph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmulcph, a, b, c, d);
        }
        Error vfcmulcph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmulcph, a, b, c, d);
        }
        Error vfcmulcsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfcmulcsh, a, b, c, d);
        }
        Error vfcmulcsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfcmulcsh, a, b, c, d);
        }
        Error vfixupimmpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmpd, a, b, c, d, e);
        }
        Error vfixupimmpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmpd, a, b, c, d, e);
        }
        Error vfixupimmpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmpd, a, b, c, d, e);
        }
        Error vfixupimmpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmpd, a, b, c, d, e);
        }
        Error vfixupimmpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmpd, a, b, c, d, e);
        }
        Error vfixupimmpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmpd, a, b, c, d, e);
        }
        Error vfixupimmps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmps, a, b, c, d, e);
        }
        Error vfixupimmps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmps, a, b, c, d, e);
        }
        Error vfixupimmps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmps, a, b, c, d, e);
        }
        Error vfixupimmps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmps, a, b, c, d, e);
        }
        Error vfixupimmps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmps, a, b, c, d, e);
        }
        Error vfixupimmps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmps, a, b, c, d, e);
        }
        Error vfixupimmsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmsd, a, b, c, d, e);
        }
        Error vfixupimmsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmsd, a, b, c, d, e);
        }
        Error vfixupimmss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmss, a, b, c, d, e);
        }
        Error vfixupimmss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vfixupimmss, a, b, c, d, e);
        }
        Error vfixupnanpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfixupnanpd, a, b, c, d);
        }
        Error vfixupnanpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfixupnanpd, a, b, c, d);
        }
        Error vfixupnanps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfixupnanps, a, b, c, d);
        }
        Error vfixupnanps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfixupnanps, a, b, c, d);
        }
        Error vfmadd132pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c);
        }
        Error vfmadd132pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c);
        }
        Error vfmadd132pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c);
        }
        Error vfmadd132pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c);
        }
        Error vfmadd132pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c, d);
        }
        Error vfmadd132pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c, d);
        }
        Error vfmadd132pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c, d);
        }
        Error vfmadd132pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c, d);
        }
        Error vfmadd132pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c, d);
        }
        Error vfmadd132pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132pd, a, b, c, d);
        }
        Error vfmadd132ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ph, a, b, c, d);
        }
        Error vfmadd132ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ph, a, b, c, d);
        }
        Error vfmadd132ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ph, a, b, c, d);
        }
        Error vfmadd132ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ph, a, b, c, d);
        }
        Error vfmadd132ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ph, a, b, c, d);
        }
        Error vfmadd132ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ph, a, b, c, d);
        }
        Error vfmadd132ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c);
        }
        Error vfmadd132ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c);
        }
        Error vfmadd132ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c);
        }
        Error vfmadd132ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c);
        }
        Error vfmadd132ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c, d);
        }
        Error vfmadd132ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c, d);
        }
        Error vfmadd132ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c, d);
        }
        Error vfmadd132ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c, d);
        }
        Error vfmadd132ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c, d);
        }
        Error vfmadd132ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ps, a, b, c, d);
        }
        Error vfmadd132sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd132sd, a, b, c);
        }
        Error vfmadd132sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd132sd, a, b, c);
        }
        Error vfmadd132sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132sd, a, b, c, d);
        }
        Error vfmadd132sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132sd, a, b, c, d);
        }
        Error vfmadd132sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132sh, a, b, c, d);
        }
        Error vfmadd132sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132sh, a, b, c, d);
        }
        Error vfmadd132ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd132ss, a, b, c);
        }
        Error vfmadd132ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd132ss, a, b, c);
        }
        Error vfmadd132ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ss, a, b, c, d);
        }
        Error vfmadd132ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd132ss, a, b, c, d);
        }
        Error vfmadd213pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c);
        }
        Error vfmadd213pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c);
        }
        Error vfmadd213pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c);
        }
        Error vfmadd213pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c);
        }
        Error vfmadd213pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c, d);
        }
        Error vfmadd213pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c, d);
        }
        Error vfmadd213pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c, d);
        }
        Error vfmadd213pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c, d);
        }
        Error vfmadd213pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c, d);
        }
        Error vfmadd213pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213pd, a, b, c, d);
        }
        Error vfmadd213ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ph, a, b, c, d);
        }
        Error vfmadd213ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ph, a, b, c, d);
        }
        Error vfmadd213ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ph, a, b, c, d);
        }
        Error vfmadd213ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ph, a, b, c, d);
        }
        Error vfmadd213ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ph, a, b, c, d);
        }
        Error vfmadd213ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ph, a, b, c, d);
        }
        Error vfmadd213ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c);
        }
        Error vfmadd213ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c);
        }
        Error vfmadd213ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c);
        }
        Error vfmadd213ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c);
        }
        Error vfmadd213ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c, d);
        }
        Error vfmadd213ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c, d);
        }
        Error vfmadd213ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c, d);
        }
        Error vfmadd213ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c, d);
        }
        Error vfmadd213ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c, d);
        }
        Error vfmadd213ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ps, a, b, c, d);
        }
        Error vfmadd213sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd213sd, a, b, c);
        }
        Error vfmadd213sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd213sd, a, b, c);
        }
        Error vfmadd213sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213sd, a, b, c, d);
        }
        Error vfmadd213sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213sd, a, b, c, d);
        }
        Error vfmadd213sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213sh, a, b, c, d);
        }
        Error vfmadd213sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213sh, a, b, c, d);
        }
        Error vfmadd213ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd213ss, a, b, c);
        }
        Error vfmadd213ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd213ss, a, b, c);
        }
        Error vfmadd213ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ss, a, b, c, d);
        }
        Error vfmadd213ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd213ss, a, b, c, d);
        }
        Error vfmadd231pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c);
        }
        Error vfmadd231pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c);
        }
        Error vfmadd231pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c);
        }
        Error vfmadd231pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c);
        }
        Error vfmadd231pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c, d);
        }
        Error vfmadd231pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c, d);
        }
        Error vfmadd231pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c, d);
        }
        Error vfmadd231pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c, d);
        }
        Error vfmadd231pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c, d);
        }
        Error vfmadd231pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231pd, a, b, c, d);
        }
        Error vfmadd231ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ph, a, b, c, d);
        }
        Error vfmadd231ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ph, a, b, c, d);
        }
        Error vfmadd231ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ph, a, b, c, d);
        }
        Error vfmadd231ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ph, a, b, c, d);
        }
        Error vfmadd231ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ph, a, b, c, d);
        }
        Error vfmadd231ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ph, a, b, c, d);
        }
        Error vfmadd231ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c);
        }
        Error vfmadd231ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c);
        }
        Error vfmadd231ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c);
        }
        Error vfmadd231ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c);
        }
        Error vfmadd231ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c, d);
        }
        Error vfmadd231ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c, d);
        }
        Error vfmadd231ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c, d);
        }
        Error vfmadd231ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c, d);
        }
        Error vfmadd231ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c, d);
        }
        Error vfmadd231ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ps, a, b, c, d);
        }
        Error vfmadd231sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd231sd, a, b, c);
        }
        Error vfmadd231sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd231sd, a, b, c);
        }
        Error vfmadd231sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231sd, a, b, c, d);
        }
        Error vfmadd231sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231sd, a, b, c, d);
        }
        Error vfmadd231sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231sh, a, b, c, d);
        }
        Error vfmadd231sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231sh, a, b, c, d);
        }
        Error vfmadd231ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmadd231ss, a, b, c);
        }
        Error vfmadd231ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmadd231ss, a, b, c);
        }
        Error vfmadd231ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ss, a, b, c, d);
        }
        Error vfmadd231ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd231ss, a, b, c, d);
        }
        Error vfmadd233ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmadd233ps, a, b, c, d);
        }
        Error vfmadd233ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmadd233ps, a, b, c, d);
        }
        Error vfmaddcph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddcph, a, b, c, d);
        }
        Error vfmaddcph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddcph, a, b, c, d);
        }
        Error vfmaddcph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddcph, a, b, c, d);
        }
        Error vfmaddcph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddcph, a, b, c, d);
        }
        Error vfmaddcph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddcph, a, b, c, d);
        }
        Error vfmaddcph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddcph, a, b, c, d);
        }
        Error vfmaddcsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddcsh, a, b, c, d);
        }
        Error vfmaddcsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddcsh, a, b, c, d);
        }
        Error vfmaddpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddpd, a, b, c, d);
        }
        Error vfmaddpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddpd, a, b, c, d);
        }
        Error vfmaddpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddpd, a, b, c, d);
        }
        Error vfmaddpd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddpd, a, b, c, d);
        }
        Error vfmaddpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddpd, a, b, c, d);
        }
        Error vfmaddpd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddpd, a, b, c, d);
        }
        Error vfmaddps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddps, a, b, c, d);
        }
        Error vfmaddps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddps, a, b, c, d);
        }
        Error vfmaddps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddps, a, b, c, d);
        }
        Error vfmaddps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddps, a, b, c, d);
        }
        Error vfmaddps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddps, a, b, c, d);
        }
        Error vfmaddps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddps, a, b, c, d);
        }
        Error vfmaddsd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsd, a, b, c, d);
        }
        Error vfmaddsd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsd, a, b, c, d);
        }
        Error vfmaddsd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsd, a, b, c, d);
        }
        Error vfmaddss(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddss, a, b, c, d);
        }
        Error vfmaddss(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddss, a, b, c, d);
        }
        Error vfmaddss(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddss, a, b, c, d);
        }
        Error vfmaddsub132pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c);
        }
        Error vfmaddsub132pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c);
        }
        Error vfmaddsub132pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c);
        }
        Error vfmaddsub132pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c);
        }
        Error vfmaddsub132pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c, d);
        }
        Error vfmaddsub132pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c, d);
        }
        Error vfmaddsub132pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c, d);
        }
        Error vfmaddsub132pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c, d);
        }
        Error vfmaddsub132pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c, d);
        }
        Error vfmaddsub132pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132pd, a, b, c, d);
        }
        Error vfmaddsub132ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ph, a, b, c, d);
        }
        Error vfmaddsub132ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ph, a, b, c, d);
        }
        Error vfmaddsub132ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ph, a, b, c, d);
        }
        Error vfmaddsub132ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ph, a, b, c, d);
        }
        Error vfmaddsub132ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ph, a, b, c, d);
        }
        Error vfmaddsub132ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ph, a, b, c, d);
        }
        Error vfmaddsub132ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c);
        }
        Error vfmaddsub132ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c);
        }
        Error vfmaddsub132ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c);
        }
        Error vfmaddsub132ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c);
        }
        Error vfmaddsub132ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c, d);
        }
        Error vfmaddsub132ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c, d);
        }
        Error vfmaddsub132ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c, d);
        }
        Error vfmaddsub132ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c, d);
        }
        Error vfmaddsub132ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c, d);
        }
        Error vfmaddsub132ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub132ps, a, b, c, d);
        }
        Error vfmaddsub213pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c);
        }
        Error vfmaddsub213pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c);
        }
        Error vfmaddsub213pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c);
        }
        Error vfmaddsub213pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c);
        }
        Error vfmaddsub213pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c, d);
        }
        Error vfmaddsub213pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c, d);
        }
        Error vfmaddsub213pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c, d);
        }
        Error vfmaddsub213pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c, d);
        }
        Error vfmaddsub213pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c, d);
        }
        Error vfmaddsub213pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213pd, a, b, c, d);
        }
        Error vfmaddsub213ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ph, a, b, c, d);
        }
        Error vfmaddsub213ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ph, a, b, c, d);
        }
        Error vfmaddsub213ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ph, a, b, c, d);
        }
        Error vfmaddsub213ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ph, a, b, c, d);
        }
        Error vfmaddsub213ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ph, a, b, c, d);
        }
        Error vfmaddsub213ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ph, a, b, c, d);
        }
        Error vfmaddsub213ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c);
        }
        Error vfmaddsub213ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c);
        }
        Error vfmaddsub213ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c);
        }
        Error vfmaddsub213ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c);
        }
        Error vfmaddsub213ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c, d);
        }
        Error vfmaddsub213ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c, d);
        }
        Error vfmaddsub213ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c, d);
        }
        Error vfmaddsub213ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c, d);
        }
        Error vfmaddsub213ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c, d);
        }
        Error vfmaddsub213ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub213ps, a, b, c, d);
        }
        Error vfmaddsub231pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c);
        }
        Error vfmaddsub231pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c);
        }
        Error vfmaddsub231pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c);
        }
        Error vfmaddsub231pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c);
        }
        Error vfmaddsub231pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c, d);
        }
        Error vfmaddsub231pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c, d);
        }
        Error vfmaddsub231pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c, d);
        }
        Error vfmaddsub231pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c, d);
        }
        Error vfmaddsub231pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c, d);
        }
        Error vfmaddsub231pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231pd, a, b, c, d);
        }
        Error vfmaddsub231ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ph, a, b, c, d);
        }
        Error vfmaddsub231ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ph, a, b, c, d);
        }
        Error vfmaddsub231ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ph, a, b, c, d);
        }
        Error vfmaddsub231ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ph, a, b, c, d);
        }
        Error vfmaddsub231ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ph, a, b, c, d);
        }
        Error vfmaddsub231ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ph, a, b, c, d);
        }
        Error vfmaddsub231ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c);
        }
        Error vfmaddsub231ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c);
        }
        Error vfmaddsub231ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c);
        }
        Error vfmaddsub231ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c);
        }
        Error vfmaddsub231ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c, d);
        }
        Error vfmaddsub231ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c, d);
        }
        Error vfmaddsub231ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c, d);
        }
        Error vfmaddsub231ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c, d);
        }
        Error vfmaddsub231ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c, d);
        }
        Error vfmaddsub231ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsub231ps, a, b, c, d);
        }
        Error vfmaddsubpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubpd, a, b, c, d);
        }
        Error vfmaddsubpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubpd, a, b, c, d);
        }
        Error vfmaddsubpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubpd, a, b, c, d);
        }
        Error vfmaddsubpd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubpd, a, b, c, d);
        }
        Error vfmaddsubpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubpd, a, b, c, d);
        }
        Error vfmaddsubpd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubpd, a, b, c, d);
        }
        Error vfmaddsubps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubps, a, b, c, d);
        }
        Error vfmaddsubps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubps, a, b, c, d);
        }
        Error vfmaddsubps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubps, a, b, c, d);
        }
        Error vfmaddsubps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubps, a, b, c, d);
        }
        Error vfmaddsubps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubps, a, b, c, d);
        }
        Error vfmaddsubps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmaddsubps, a, b, c, d);
        }
        Error vfmsub132pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c);
        }
        Error vfmsub132pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c);
        }
        Error vfmsub132pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c);
        }
        Error vfmsub132pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c);
        }
        Error vfmsub132pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c, d);
        }
        Error vfmsub132pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c, d);
        }
        Error vfmsub132pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c, d);
        }
        Error vfmsub132pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c, d);
        }
        Error vfmsub132pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c, d);
        }
        Error vfmsub132pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132pd, a, b, c, d);
        }
        Error vfmsub132ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ph, a, b, c, d);
        }
        Error vfmsub132ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ph, a, b, c, d);
        }
        Error vfmsub132ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ph, a, b, c, d);
        }
        Error vfmsub132ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ph, a, b, c, d);
        }
        Error vfmsub132ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ph, a, b, c, d);
        }
        Error vfmsub132ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ph, a, b, c, d);
        }
        Error vfmsub132ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c);
        }
        Error vfmsub132ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c);
        }
        Error vfmsub132ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c);
        }
        Error vfmsub132ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c);
        }
        Error vfmsub132ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c, d);
        }
        Error vfmsub132ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c, d);
        }
        Error vfmsub132ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c, d);
        }
        Error vfmsub132ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c, d);
        }
        Error vfmsub132ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c, d);
        }
        Error vfmsub132ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ps, a, b, c, d);
        }
        Error vfmsub132sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub132sd, a, b, c);
        }
        Error vfmsub132sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub132sd, a, b, c);
        }
        Error vfmsub132sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132sd, a, b, c, d);
        }
        Error vfmsub132sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132sd, a, b, c, d);
        }
        Error vfmsub132sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132sh, a, b, c, d);
        }
        Error vfmsub132sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132sh, a, b, c, d);
        }
        Error vfmsub132ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub132ss, a, b, c);
        }
        Error vfmsub132ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub132ss, a, b, c);
        }
        Error vfmsub132ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ss, a, b, c, d);
        }
        Error vfmsub132ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub132ss, a, b, c, d);
        }
        Error vfmsub213pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c);
        }
        Error vfmsub213pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c);
        }
        Error vfmsub213pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c);
        }
        Error vfmsub213pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c);
        }
        Error vfmsub213pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c, d);
        }
        Error vfmsub213pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c, d);
        }
        Error vfmsub213pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c, d);
        }
        Error vfmsub213pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c, d);
        }
        Error vfmsub213pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c, d);
        }
        Error vfmsub213pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213pd, a, b, c, d);
        }
        Error vfmsub213ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ph, a, b, c, d);
        }
        Error vfmsub213ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ph, a, b, c, d);
        }
        Error vfmsub213ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ph, a, b, c, d);
        }
        Error vfmsub213ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ph, a, b, c, d);
        }
        Error vfmsub213ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ph, a, b, c, d);
        }
        Error vfmsub213ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ph, a, b, c, d);
        }
        Error vfmsub213ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c);
        }
        Error vfmsub213ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c);
        }
        Error vfmsub213ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c);
        }
        Error vfmsub213ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c);
        }
        Error vfmsub213ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c, d);
        }
        Error vfmsub213ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c, d);
        }
        Error vfmsub213ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c, d);
        }
        Error vfmsub213ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c, d);
        }
        Error vfmsub213ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c, d);
        }
        Error vfmsub213ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ps, a, b, c, d);
        }
        Error vfmsub213sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub213sd, a, b, c);
        }
        Error vfmsub213sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub213sd, a, b, c);
        }
        Error vfmsub213sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213sd, a, b, c, d);
        }
        Error vfmsub213sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213sd, a, b, c, d);
        }
        Error vfmsub213sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213sh, a, b, c, d);
        }
        Error vfmsub213sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213sh, a, b, c, d);
        }
        Error vfmsub213ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub213ss, a, b, c);
        }
        Error vfmsub213ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub213ss, a, b, c);
        }
        Error vfmsub213ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ss, a, b, c, d);
        }
        Error vfmsub213ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub213ss, a, b, c, d);
        }
        Error vfmsub231pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c);
        }
        Error vfmsub231pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c);
        }
        Error vfmsub231pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c);
        }
        Error vfmsub231pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c);
        }
        Error vfmsub231pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c, d);
        }
        Error vfmsub231pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c, d);
        }
        Error vfmsub231pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c, d);
        }
        Error vfmsub231pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c, d);
        }
        Error vfmsub231pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c, d);
        }
        Error vfmsub231pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231pd, a, b, c, d);
        }
        Error vfmsub231ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ph, a, b, c, d);
        }
        Error vfmsub231ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ph, a, b, c, d);
        }
        Error vfmsub231ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ph, a, b, c, d);
        }
        Error vfmsub231ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ph, a, b, c, d);
        }
        Error vfmsub231ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ph, a, b, c, d);
        }
        Error vfmsub231ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ph, a, b, c, d);
        }
        Error vfmsub231ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c);
        }
        Error vfmsub231ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c);
        }
        Error vfmsub231ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c);
        }
        Error vfmsub231ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c);
        }
        Error vfmsub231ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c, d);
        }
        Error vfmsub231ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c, d);
        }
        Error vfmsub231ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c, d);
        }
        Error vfmsub231ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c, d);
        }
        Error vfmsub231ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c, d);
        }
        Error vfmsub231ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ps, a, b, c, d);
        }
        Error vfmsub231sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub231sd, a, b, c);
        }
        Error vfmsub231sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub231sd, a, b, c);
        }
        Error vfmsub231sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231sd, a, b, c, d);
        }
        Error vfmsub231sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231sd, a, b, c, d);
        }
        Error vfmsub231sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231sh, a, b, c, d);
        }
        Error vfmsub231sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231sh, a, b, c, d);
        }
        Error vfmsub231ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsub231ss, a, b, c);
        }
        Error vfmsub231ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsub231ss, a, b, c);
        }
        Error vfmsub231ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ss, a, b, c, d);
        }
        Error vfmsub231ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsub231ss, a, b, c, d);
        }
        Error vfmsubadd132pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c);
        }
        Error vfmsubadd132pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c);
        }
        Error vfmsubadd132pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c);
        }
        Error vfmsubadd132pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c);
        }
        Error vfmsubadd132pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c, d);
        }
        Error vfmsubadd132pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c, d);
        }
        Error vfmsubadd132pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c, d);
        }
        Error vfmsubadd132pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c, d);
        }
        Error vfmsubadd132pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c, d);
        }
        Error vfmsubadd132pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132pd, a, b, c, d);
        }
        Error vfmsubadd132ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ph, a, b, c, d);
        }
        Error vfmsubadd132ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ph, a, b, c, d);
        }
        Error vfmsubadd132ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ph, a, b, c, d);
        }
        Error vfmsubadd132ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ph, a, b, c, d);
        }
        Error vfmsubadd132ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ph, a, b, c, d);
        }
        Error vfmsubadd132ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ph, a, b, c, d);
        }
        Error vfmsubadd132ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c);
        }
        Error vfmsubadd132ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c);
        }
        Error vfmsubadd132ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c);
        }
        Error vfmsubadd132ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c);
        }
        Error vfmsubadd132ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c, d);
        }
        Error vfmsubadd132ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c, d);
        }
        Error vfmsubadd132ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c, d);
        }
        Error vfmsubadd132ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c, d);
        }
        Error vfmsubadd132ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c, d);
        }
        Error vfmsubadd132ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd132ps, a, b, c, d);
        }
        Error vfmsubadd213pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c);
        }
        Error vfmsubadd213pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c);
        }
        Error vfmsubadd213pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c);
        }
        Error vfmsubadd213pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c);
        }
        Error vfmsubadd213pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c, d);
        }
        Error vfmsubadd213pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c, d);
        }
        Error vfmsubadd213pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c, d);
        }
        Error vfmsubadd213pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c, d);
        }
        Error vfmsubadd213pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c, d);
        }
        Error vfmsubadd213pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213pd, a, b, c, d);
        }
        Error vfmsubadd213ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ph, a, b, c, d);
        }
        Error vfmsubadd213ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ph, a, b, c, d);
        }
        Error vfmsubadd213ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ph, a, b, c, d);
        }
        Error vfmsubadd213ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ph, a, b, c, d);
        }
        Error vfmsubadd213ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ph, a, b, c, d);
        }
        Error vfmsubadd213ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ph, a, b, c, d);
        }
        Error vfmsubadd213ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c);
        }
        Error vfmsubadd213ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c);
        }
        Error vfmsubadd213ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c);
        }
        Error vfmsubadd213ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c);
        }
        Error vfmsubadd213ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c, d);
        }
        Error vfmsubadd213ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c, d);
        }
        Error vfmsubadd213ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c, d);
        }
        Error vfmsubadd213ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c, d);
        }
        Error vfmsubadd213ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c, d);
        }
        Error vfmsubadd213ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd213ps, a, b, c, d);
        }
        Error vfmsubadd231pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c);
        }
        Error vfmsubadd231pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c);
        }
        Error vfmsubadd231pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c);
        }
        Error vfmsubadd231pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c);
        }
        Error vfmsubadd231pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c, d);
        }
        Error vfmsubadd231pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c, d);
        }
        Error vfmsubadd231pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c, d);
        }
        Error vfmsubadd231pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c, d);
        }
        Error vfmsubadd231pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c, d);
        }
        Error vfmsubadd231pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231pd, a, b, c, d);
        }
        Error vfmsubadd231ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ph, a, b, c, d);
        }
        Error vfmsubadd231ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ph, a, b, c, d);
        }
        Error vfmsubadd231ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ph, a, b, c, d);
        }
        Error vfmsubadd231ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ph, a, b, c, d);
        }
        Error vfmsubadd231ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ph, a, b, c, d);
        }
        Error vfmsubadd231ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ph, a, b, c, d);
        }
        Error vfmsubadd231ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c);
        }
        Error vfmsubadd231ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c);
        }
        Error vfmsubadd231ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c);
        }
        Error vfmsubadd231ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c);
        }
        Error vfmsubadd231ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c, d);
        }
        Error vfmsubadd231ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c, d);
        }
        Error vfmsubadd231ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c, d);
        }
        Error vfmsubadd231ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c, d);
        }
        Error vfmsubadd231ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c, d);
        }
        Error vfmsubadd231ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubadd231ps, a, b, c, d);
        }
        Error vfmsubaddpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddpd, a, b, c, d);
        }
        Error vfmsubaddpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddpd, a, b, c, d);
        }
        Error vfmsubaddpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddpd, a, b, c, d);
        }
        Error vfmsubaddpd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddpd, a, b, c, d);
        }
        Error vfmsubaddpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddpd, a, b, c, d);
        }
        Error vfmsubaddpd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddpd, a, b, c, d);
        }
        Error vfmsubaddps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddps, a, b, c, d);
        }
        Error vfmsubaddps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddps, a, b, c, d);
        }
        Error vfmsubaddps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddps, a, b, c, d);
        }
        Error vfmsubaddps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddps, a, b, c, d);
        }
        Error vfmsubaddps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddps, a, b, c, d);
        }
        Error vfmsubaddps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubaddps, a, b, c, d);
        }
        Error vfmsubpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubpd, a, b, c, d);
        }
        Error vfmsubpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubpd, a, b, c, d);
        }
        Error vfmsubpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubpd, a, b, c, d);
        }
        Error vfmsubpd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubpd, a, b, c, d);
        }
        Error vfmsubpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubpd, a, b, c, d);
        }
        Error vfmsubpd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubpd, a, b, c, d);
        }
        Error vfmsubps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubps, a, b, c, d);
        }
        Error vfmsubps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubps, a, b, c, d);
        }
        Error vfmsubps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubps, a, b, c, d);
        }
        Error vfmsubps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubps, a, b, c, d);
        }
        Error vfmsubps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmsubps, a, b, c, d);
        }
        Error vfmsubps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubps, a, b, c, d);
        }
        Error vfmsubsd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubsd, a, b, c, d);
        }
        Error vfmsubsd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubsd, a, b, c, d);
        }
        Error vfmsubsd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubsd, a, b, c, d);
        }
        Error vfmsubss(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubss, a, b, c, d);
        }
        Error vfmsubss(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmsubss, a, b, c, d);
        }
        Error vfmsubss(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmsubss, a, b, c, d);
        }
        Error vfmulcph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfmulcph, a, b, c, d);
        }
        Error vfmulcph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmulcph, a, b, c, d);
        }
        Error vfmulcph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfmulcph, a, b, c, d);
        }
        Error vfmulcph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmulcph, a, b, c, d);
        }
        Error vfmulcph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmulcph, a, b, c, d);
        }
        Error vfmulcph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmulcph, a, b, c, d);
        }
        Error vfmulcsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfmulcsh, a, b, c, d);
        }
        Error vfmulcsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfmulcsh, a, b, c, d);
        }
        Error vfnmadd132pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c);
        }
        Error vfnmadd132pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c);
        }
        Error vfnmadd132pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c);
        }
        Error vfnmadd132pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c);
        }
        Error vfnmadd132pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c, d);
        }
        Error vfnmadd132pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c, d);
        }
        Error vfnmadd132pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c, d);
        }
        Error vfnmadd132pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c, d);
        }
        Error vfnmadd132pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c, d);
        }
        Error vfnmadd132pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132pd, a, b, c, d);
        }
        Error vfnmadd132ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ph, a, b, c, d);
        }
        Error vfnmadd132ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ph, a, b, c, d);
        }
        Error vfnmadd132ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ph, a, b, c, d);
        }
        Error vfnmadd132ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ph, a, b, c, d);
        }
        Error vfnmadd132ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ph, a, b, c, d);
        }
        Error vfnmadd132ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ph, a, b, c, d);
        }
        Error vfnmadd132ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c);
        }
        Error vfnmadd132ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c);
        }
        Error vfnmadd132ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c);
        }
        Error vfnmadd132ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c);
        }
        Error vfnmadd132ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c, d);
        }
        Error vfnmadd132ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c, d);
        }
        Error vfnmadd132ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c, d);
        }
        Error vfnmadd132ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c, d);
        }
        Error vfnmadd132ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c, d);
        }
        Error vfnmadd132ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ps, a, b, c, d);
        }
        Error vfnmadd132sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132sd, a, b, c);
        }
        Error vfnmadd132sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132sd, a, b, c);
        }
        Error vfnmadd132sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132sd, a, b, c, d);
        }
        Error vfnmadd132sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132sd, a, b, c, d);
        }
        Error vfnmadd132sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132sh, a, b, c, d);
        }
        Error vfnmadd132sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132sh, a, b, c, d);
        }
        Error vfnmadd132ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132ss, a, b, c);
        }
        Error vfnmadd132ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd132ss, a, b, c);
        }
        Error vfnmadd132ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ss, a, b, c, d);
        }
        Error vfnmadd132ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd132ss, a, b, c, d);
        }
        Error vfnmadd213pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c);
        }
        Error vfnmadd213pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c);
        }
        Error vfnmadd213pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c);
        }
        Error vfnmadd213pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c);
        }
        Error vfnmadd213pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c, d);
        }
        Error vfnmadd213pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c, d);
        }
        Error vfnmadd213pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c, d);
        }
        Error vfnmadd213pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c, d);
        }
        Error vfnmadd213pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c, d);
        }
        Error vfnmadd213pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213pd, a, b, c, d);
        }
        Error vfnmadd213ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ph, a, b, c, d);
        }
        Error vfnmadd213ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ph, a, b, c, d);
        }
        Error vfnmadd213ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ph, a, b, c, d);
        }
        Error vfnmadd213ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ph, a, b, c, d);
        }
        Error vfnmadd213ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ph, a, b, c, d);
        }
        Error vfnmadd213ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ph, a, b, c, d);
        }
        Error vfnmadd213ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c);
        }
        Error vfnmadd213ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c);
        }
        Error vfnmadd213ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c);
        }
        Error vfnmadd213ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c);
        }
        Error vfnmadd213ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c, d);
        }
        Error vfnmadd213ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c, d);
        }
        Error vfnmadd213ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c, d);
        }
        Error vfnmadd213ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c, d);
        }
        Error vfnmadd213ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c, d);
        }
        Error vfnmadd213ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ps, a, b, c, d);
        }
        Error vfnmadd213sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213sd, a, b, c);
        }
        Error vfnmadd213sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213sd, a, b, c);
        }
        Error vfnmadd213sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213sd, a, b, c, d);
        }
        Error vfnmadd213sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213sd, a, b, c, d);
        }
        Error vfnmadd213sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213sh, a, b, c, d);
        }
        Error vfnmadd213sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213sh, a, b, c, d);
        }
        Error vfnmadd213ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213ss, a, b, c);
        }
        Error vfnmadd213ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd213ss, a, b, c);
        }
        Error vfnmadd213ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ss, a, b, c, d);
        }
        Error vfnmadd213ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd213ss, a, b, c, d);
        }
        Error vfnmadd231pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c);
        }
        Error vfnmadd231pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c);
        }
        Error vfnmadd231pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c);
        }
        Error vfnmadd231pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c);
        }
        Error vfnmadd231pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c, d);
        }
        Error vfnmadd231pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c, d);
        }
        Error vfnmadd231pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c, d);
        }
        Error vfnmadd231pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c, d);
        }
        Error vfnmadd231pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c, d);
        }
        Error vfnmadd231pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231pd, a, b, c, d);
        }
        Error vfnmadd231ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ph, a, b, c, d);
        }
        Error vfnmadd231ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ph, a, b, c, d);
        }
        Error vfnmadd231ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ph, a, b, c, d);
        }
        Error vfnmadd231ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ph, a, b, c, d);
        }
        Error vfnmadd231ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ph, a, b, c, d);
        }
        Error vfnmadd231ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ph, a, b, c, d);
        }
        Error vfnmadd231ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c);
        }
        Error vfnmadd231ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c);
        }
        Error vfnmadd231ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c);
        }
        Error vfnmadd231ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c);
        }
        Error vfnmadd231ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c, d);
        }
        Error vfnmadd231ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c, d);
        }
        Error vfnmadd231ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c, d);
        }
        Error vfnmadd231ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c, d);
        }
        Error vfnmadd231ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c, d);
        }
        Error vfnmadd231ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ps, a, b, c, d);
        }
        Error vfnmadd231sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231sd, a, b, c);
        }
        Error vfnmadd231sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231sd, a, b, c);
        }
        Error vfnmadd231sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231sd, a, b, c, d);
        }
        Error vfnmadd231sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231sd, a, b, c, d);
        }
        Error vfnmadd231sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231sh, a, b, c, d);
        }
        Error vfnmadd231sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231sh, a, b, c, d);
        }
        Error vfnmadd231ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231ss, a, b, c);
        }
        Error vfnmadd231ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmadd231ss, a, b, c);
        }
        Error vfnmadd231ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ss, a, b, c, d);
        }
        Error vfnmadd231ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmadd231ss, a, b, c, d);
        }
        Error vfnmaddpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddpd, a, b, c, d);
        }
        Error vfnmaddpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddpd, a, b, c, d);
        }
        Error vfnmaddpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddpd, a, b, c, d);
        }
        Error vfnmaddpd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmaddpd, a, b, c, d);
        }
        Error vfnmaddpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddpd, a, b, c, d);
        }
        Error vfnmaddpd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmaddpd, a, b, c, d);
        }
        Error vfnmaddps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddps, a, b, c, d);
        }
        Error vfnmaddps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddps, a, b, c, d);
        }
        Error vfnmaddps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddps, a, b, c, d);
        }
        Error vfnmaddps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmaddps, a, b, c, d);
        }
        Error vfnmaddps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddps, a, b, c, d);
        }
        Error vfnmaddps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmaddps, a, b, c, d);
        }
        Error vfnmaddsd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddsd, a, b, c, d);
        }
        Error vfnmaddsd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddsd, a, b, c, d);
        }
        Error vfnmaddsd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmaddsd, a, b, c, d);
        }
        Error vfnmaddss(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddss, a, b, c, d);
        }
        Error vfnmaddss(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmaddss, a, b, c, d);
        }
        Error vfnmaddss(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmaddss, a, b, c, d);
        }
        Error vfnmsub132pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c);
        }
        Error vfnmsub132pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c);
        }
        Error vfnmsub132pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c);
        }
        Error vfnmsub132pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c);
        }
        Error vfnmsub132pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c, d);
        }
        Error vfnmsub132pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c, d);
        }
        Error vfnmsub132pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c, d);
        }
        Error vfnmsub132pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c, d);
        }
        Error vfnmsub132pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c, d);
        }
        Error vfnmsub132pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132pd, a, b, c, d);
        }
        Error vfnmsub132ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ph, a, b, c, d);
        }
        Error vfnmsub132ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ph, a, b, c, d);
        }
        Error vfnmsub132ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ph, a, b, c, d);
        }
        Error vfnmsub132ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ph, a, b, c, d);
        }
        Error vfnmsub132ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ph, a, b, c, d);
        }
        Error vfnmsub132ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ph, a, b, c, d);
        }
        Error vfnmsub132ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c);
        }
        Error vfnmsub132ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c);
        }
        Error vfnmsub132ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c);
        }
        Error vfnmsub132ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c);
        }
        Error vfnmsub132ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c, d);
        }
        Error vfnmsub132ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c, d);
        }
        Error vfnmsub132ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c, d);
        }
        Error vfnmsub132ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c, d);
        }
        Error vfnmsub132ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c, d);
        }
        Error vfnmsub132ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ps, a, b, c, d);
        }
        Error vfnmsub132sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132sd, a, b, c);
        }
        Error vfnmsub132sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132sd, a, b, c);
        }
        Error vfnmsub132sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132sd, a, b, c, d);
        }
        Error vfnmsub132sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132sd, a, b, c, d);
        }
        Error vfnmsub132sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132sh, a, b, c, d);
        }
        Error vfnmsub132sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132sh, a, b, c, d);
        }
        Error vfnmsub132ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132ss, a, b, c);
        }
        Error vfnmsub132ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub132ss, a, b, c);
        }
        Error vfnmsub132ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ss, a, b, c, d);
        }
        Error vfnmsub132ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub132ss, a, b, c, d);
        }
        Error vfnmsub213pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c);
        }
        Error vfnmsub213pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c);
        }
        Error vfnmsub213pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c);
        }
        Error vfnmsub213pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c);
        }
        Error vfnmsub213pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c, d);
        }
        Error vfnmsub213pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c, d);
        }
        Error vfnmsub213pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c, d);
        }
        Error vfnmsub213pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c, d);
        }
        Error vfnmsub213pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c, d);
        }
        Error vfnmsub213pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213pd, a, b, c, d);
        }
        Error vfnmsub213ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ph, a, b, c, d);
        }
        Error vfnmsub213ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ph, a, b, c, d);
        }
        Error vfnmsub213ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ph, a, b, c, d);
        }
        Error vfnmsub213ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ph, a, b, c, d);
        }
        Error vfnmsub213ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ph, a, b, c, d);
        }
        Error vfnmsub213ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ph, a, b, c, d);
        }
        Error vfnmsub213ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c);
        }
        Error vfnmsub213ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c);
        }
        Error vfnmsub213ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c);
        }
        Error vfnmsub213ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c);
        }
        Error vfnmsub213ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c, d);
        }
        Error vfnmsub213ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c, d);
        }
        Error vfnmsub213ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c, d);
        }
        Error vfnmsub213ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c, d);
        }
        Error vfnmsub213ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c, d);
        }
        Error vfnmsub213ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ps, a, b, c, d);
        }
        Error vfnmsub213sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213sd, a, b, c);
        }
        Error vfnmsub213sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213sd, a, b, c);
        }
        Error vfnmsub213sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213sd, a, b, c, d);
        }
        Error vfnmsub213sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213sd, a, b, c, d);
        }
        Error vfnmsub213sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213sh, a, b, c, d);
        }
        Error vfnmsub213sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213sh, a, b, c, d);
        }
        Error vfnmsub213ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213ss, a, b, c);
        }
        Error vfnmsub213ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub213ss, a, b, c);
        }
        Error vfnmsub213ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ss, a, b, c, d);
        }
        Error vfnmsub213ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub213ss, a, b, c, d);
        }
        Error vfnmsub231pd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c);
        }
        Error vfnmsub231pd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c);
        }
        Error vfnmsub231pd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c);
        }
        Error vfnmsub231pd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c);
        }
        Error vfnmsub231pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c, d);
        }
        Error vfnmsub231pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c, d);
        }
        Error vfnmsub231pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c, d);
        }
        Error vfnmsub231pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c, d);
        }
        Error vfnmsub231pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c, d);
        }
        Error vfnmsub231pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231pd, a, b, c, d);
        }
        Error vfnmsub231ph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ph, a, b, c, d);
        }
        Error vfnmsub231ph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ph, a, b, c, d);
        }
        Error vfnmsub231ph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ph, a, b, c, d);
        }
        Error vfnmsub231ph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ph, a, b, c, d);
        }
        Error vfnmsub231ph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ph, a, b, c, d);
        }
        Error vfnmsub231ph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ph, a, b, c, d);
        }
        Error vfnmsub231ps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c);
        }
        Error vfnmsub231ps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c);
        }
        Error vfnmsub231ps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c);
        }
        Error vfnmsub231ps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c);
        }
        Error vfnmsub231ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c, d);
        }
        Error vfnmsub231ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c, d);
        }
        Error vfnmsub231ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c, d);
        }
        Error vfnmsub231ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c, d);
        }
        Error vfnmsub231ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c, d);
        }
        Error vfnmsub231ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ps, a, b, c, d);
        }
        Error vfnmsub231sd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231sd, a, b, c);
        }
        Error vfnmsub231sd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231sd, a, b, c);
        }
        Error vfnmsub231sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231sd, a, b, c, d);
        }
        Error vfnmsub231sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231sd, a, b, c, d);
        }
        Error vfnmsub231sh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231sh, a, b, c, d);
        }
        Error vfnmsub231sh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231sh, a, b, c, d);
        }
        Error vfnmsub231ss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231ss, a, b, c);
        }
        Error vfnmsub231ss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vfnmsub231ss, a, b, c);
        }
        Error vfnmsub231ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ss, a, b, c, d);
        }
        Error vfnmsub231ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsub231ss, a, b, c, d);
        }
        Error vfnmsubpd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubpd, a, b, c, d);
        }
        Error vfnmsubpd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubpd, a, b, c, d);
        }
        Error vfnmsubpd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubpd, a, b, c, d);
        }
        Error vfnmsubpd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsubpd, a, b, c, d);
        }
        Error vfnmsubpd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubpd, a, b, c, d);
        }
        Error vfnmsubpd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsubpd, a, b, c, d);
        }
        Error vfnmsubps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubps, a, b, c, d);
        }
        Error vfnmsubps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubps, a, b, c, d);
        }
        Error vfnmsubps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubps, a, b, c, d);
        }
        Error vfnmsubps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsubps, a, b, c, d);
        }
        Error vfnmsubps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubps, a, b, c, d);
        }
        Error vfnmsubps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsubps, a, b, c, d);
        }
        Error vfnmsubsd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubsd, a, b, c, d);
        }
        Error vfnmsubsd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubsd, a, b, c, d);
        }
        Error vfnmsubsd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsubsd, a, b, c, d);
        }
        Error vfnmsubss(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubss, a, b, c, d);
        }
        Error vfnmsubss(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vfnmsubss, a, b, c, d);
        }
        Error vfnmsubss(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vfnmsubss, a, b, c, d);
        }
        Error vfpclasspd(const Mask& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasspd, a, b, c, d);
        }
        Error vfpclasspd(const Mask& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasspd, a, b, c, d);
        }
        Error vfpclasspd(const Mask& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasspd, a, b, c, d);
        }
        Error vfpclasspd(const Mask& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasspd, a, b, c, d);
        }
        Error vfpclassph(const Mask& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassph, a, b, c, d);
        }
        Error vfpclassph(const Mask& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassph, a, b, c, d);
        }
        Error vfpclassph(const Mask& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassph, a, b, c, d);
        }
        Error vfpclassph(const Mask& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassph, a, b, c, d);
        }
        Error vfpclassps(const Mask& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassps, a, b, c, d);
        }
        Error vfpclassps(const Mask& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassps, a, b, c, d);
        }
        Error vfpclassps(const Mask& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassps, a, b, c, d);
        }
        Error vfpclassps(const Mask& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassps, a, b, c, d);
        }
        Error vfpclasssd(const Mask& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasssd, a, b, c, d);
        }
        Error vfpclasssd(const Mask& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasssd, a, b, c, d);
        }
        Error vfpclasssh(const Mask& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasssh, a, b, c, d);
        }
        Error vfpclasssh(const Mask& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclasssh, a, b, c, d);
        }
        Error vfpclassss(const Mask& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassss, a, b, c, d);
        }
        Error vfpclassss(const Mask& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vfpclassss, a, b, c, d);
        }
        Error vfrczpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vfrczpd, a, b);
        }
        Error vfrczpd(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vfrczpd, a, b);
        }
        Error vfrczpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vfrczpd, a, b);
        }
        Error vfrczpd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vfrczpd, a, b);
        }
        Error vfrczps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vfrczps, a, b);
        }
        Error vfrczps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vfrczps, a, b);
        }
        Error vfrczps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vfrczps, a, b);
        }
        Error vfrczps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vfrczps, a, b);
        }
        Error vfrczsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vfrczsd, a, b);
        }
        Error vfrczsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vfrczsd, a, b);
        }
        Error vfrczss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vfrczss, a, b);
        }
        Error vfrczss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vfrczss, a, b);
        }
        Error vgatherdpd(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgatherdpd, a, b, c);
        }
        Error vgatherdpd(const Ymm& a, const Mem& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgatherdpd, a, b, c);
        }
        Error vgatherdpd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherdpd, a, b, c);
        }
        Error vgatherdpd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherdpd, a, b, c);
        }
        Error vgatherdpd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherdpd, a, b, c);
        }
        Error vgatherdps(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgatherdps, a, b, c);
        }
        Error vgatherdps(const Ymm& a, const Mem& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgatherdps, a, b, c);
        }
        Error vgatherdps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherdps, a, b, c);
        }
        Error vgatherdps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherdps, a, b, c);
        }
        Error vgatherdps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherdps, a, b, c);
        }
        Error vgatherpf0dpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf0dpd, a, b);
        }
        Error vgatherpf0dps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf0dps, a, b);
        }
        Error vgatherpf0hintdpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf0hintdpd, a, b);
        }
        Error vgatherpf0hintdps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf0hintdps, a, b);
        }
        Error vgatherpf0qpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf0qpd, a, b);
        }
        Error vgatherpf0qps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf0qps, a, b);
        }
        Error vgatherpf1dpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf1dpd, a, b);
        }
        Error vgatherpf1dps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf1dps, a, b);
        }
        Error vgatherpf1qpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf1qpd, a, b);
        }
        Error vgatherpf1qps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vgatherpf1qps, a, b);
        }
        Error vgatherqpd(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgatherqpd, a, b, c);
        }
        Error vgatherqpd(const Ymm& a, const Mem& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgatherqpd, a, b, c);
        }
        Error vgatherqpd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherqpd, a, b, c);
        }
        Error vgatherqpd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherqpd, a, b, c);
        }
        Error vgatherqpd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherqpd, a, b, c);
        }
        Error vgatherqps(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgatherqps, a, b, c);
        }
        Error vgatherqps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherqps, a, b, c);
        }
        Error vgatherqps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgatherqps, a, b, c);
        }
        Error vgetexppd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vgetexppd, a, b, c);
        }
        Error vgetexppd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgetexppd, a, b, c);
        }
        Error vgetexppd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgetexppd, a, b, c);
        }
        Error vgetexppd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexppd, a, b, c);
        }
        Error vgetexppd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexppd, a, b, c);
        }
        Error vgetexppd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexppd, a, b, c);
        }
        Error vgetexpph(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vgetexpph, a, b, c);
        }
        Error vgetexpph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgetexpph, a, b, c);
        }
        Error vgetexpph(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgetexpph, a, b, c);
        }
        Error vgetexpph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexpph, a, b, c);
        }
        Error vgetexpph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexpph, a, b, c);
        }
        Error vgetexpph(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexpph, a, b, c);
        }
        Error vgetexpps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vgetexpps, a, b, c);
        }
        Error vgetexpps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgetexpps, a, b, c);
        }
        Error vgetexpps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgetexpps, a, b, c);
        }
        Error vgetexpps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexpps, a, b, c);
        }
        Error vgetexpps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexpps, a, b, c);
        }
        Error vgetexpps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgetexpps, a, b, c);
        }
        Error vgetexpsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vgetexpsd, a, b, c, d);
        }
        Error vgetexpsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgetexpsd, a, b, c, d);
        }
        Error vgetexpsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vgetexpsh, a, b, c, d);
        }
        Error vgetexpsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgetexpsh, a, b, c, d);
        }
        Error vgetexpss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vgetexpss, a, b, c, d);
        }
        Error vgetexpss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgetexpss, a, b, c, d);
        }
        Error vgetmantpd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantpd, a, b, c, d);
        }
        Error vgetmantpd(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantpd, a, b, c, d);
        }
        Error vgetmantpd(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantpd, a, b, c, d);
        }
        Error vgetmantpd(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantpd, a, b, c, d);
        }
        Error vgetmantpd(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantpd, a, b, c, d);
        }
        Error vgetmantpd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantpd, a, b, c, d);
        }
        Error vgetmantph(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantph, a, b, c, d);
        }
        Error vgetmantph(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantph, a, b, c, d);
        }
        Error vgetmantph(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantph, a, b, c, d);
        }
        Error vgetmantph(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantph, a, b, c, d);
        }
        Error vgetmantph(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantph, a, b, c, d);
        }
        Error vgetmantph(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantph, a, b, c, d);
        }
        Error vgetmantps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantps, a, b, c, d);
        }
        Error vgetmantps(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantps, a, b, c, d);
        }
        Error vgetmantps(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantps, a, b, c, d);
        }
        Error vgetmantps(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantps, a, b, c, d);
        }
        Error vgetmantps(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantps, a, b, c, d);
        }
        Error vgetmantps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgetmantps, a, b, c, d);
        }
        Error vgetmantsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgetmantsd, a, b, c, d, e);
        }
        Error vgetmantsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgetmantsd, a, b, c, d, e);
        }
        Error vgetmantsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgetmantsh, a, b, c, d, e);
        }
        Error vgetmantsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgetmantsh, a, b, c, d, e);
        }
        Error vgetmantss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgetmantss, a, b, c, d, e);
        }
        Error vgetmantss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgetmantss, a, b, c, d, e);
        }
        Error vgf2p8affineinvqb(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d);
        }
        Error vgf2p8affineinvqb(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d);
        }
        Error vgf2p8affineinvqb(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d);
        }
        Error vgf2p8affineinvqb(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d);
        }
        Error vgf2p8affineinvqb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d, e);
        }
        Error vgf2p8affineinvqb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d, e);
        }
        Error vgf2p8affineinvqb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d, e);
        }
        Error vgf2p8affineinvqb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d, e);
        }
        Error vgf2p8affineinvqb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d, e);
        }
        Error vgf2p8affineinvqb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineinvqb, a, b, c, d, e);
        }
        Error vgf2p8affineqb(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d);
        }
        Error vgf2p8affineqb(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d);
        }
        Error vgf2p8affineqb(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d);
        }
        Error vgf2p8affineqb(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d);
        }
        Error vgf2p8affineqb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d, e);
        }
        Error vgf2p8affineqb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d, e);
        }
        Error vgf2p8affineqb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d, e);
        }
        Error vgf2p8affineqb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d, e);
        }
        Error vgf2p8affineqb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d, e);
        }
        Error vgf2p8affineqb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vgf2p8affineqb, a, b, c, d, e);
        }
        Error vgf2p8mulb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c);
        }
        Error vgf2p8mulb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c);
        }
        Error vgf2p8mulb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c);
        }
        Error vgf2p8mulb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c);
        }
        Error vgf2p8mulb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c, d);
        }
        Error vgf2p8mulb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c, d);
        }
        Error vgf2p8mulb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c, d);
        }
        Error vgf2p8mulb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c, d);
        }
        Error vgf2p8mulb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c, d);
        }
        Error vgf2p8mulb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgf2p8mulb, a, b, c, d);
        }
        Error vgmaxabsps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vgmaxabsps, a, b, c, d);
        }
        Error vgmaxabsps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgmaxabsps, a, b, c, d);
        }
        Error vgmaxpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vgmaxpd, a, b, c, d);
        }
        Error vgmaxpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgmaxpd, a, b, c, d);
        }
        Error vgmaxps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vgmaxps, a, b, c, d);
        }
        Error vgmaxps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgmaxps, a, b, c, d);
        }
        Error vgminpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vgminpd, a, b, c, d);
        }
        Error vgminpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgminpd, a, b, c, d);
        }
        Error vgminps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vgminps, a, b, c, d);
        }
        Error vgminps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vgminps, a, b, c, d);
        }
        Error vhaddpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vhaddpd, a, b, c);
        }
        Error vhaddpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vhaddpd, a, b, c);
        }
        Error vhaddpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhaddpd, a, b, c);
        }
        Error vhaddpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhaddpd, a, b, c);
        }
        Error vhaddps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vhaddps, a, b, c);
        }
        Error vhaddps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vhaddps, a, b, c);
        }
        Error vhaddps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhaddps, a, b, c);
        }
        Error vhaddps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhaddps, a, b, c);
        }
        Error vhsubpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vhsubpd, a, b, c);
        }
        Error vhsubpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vhsubpd, a, b, c);
        }
        Error vhsubpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhsubpd, a, b, c);
        }
        Error vhsubpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhsubpd, a, b, c);
        }
        Error vhsubps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vhsubps, a, b, c);
        }
        Error vhsubps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vhsubps, a, b, c);
        }
        Error vhsubps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhsubps, a, b, c);
        }
        Error vhsubps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vhsubps, a, b, c);
        }
        Error vinsertf128(const Ymm& a, const Ymm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vinsertf128, a, b, c, d);
        }
        Error vinsertf128(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vinsertf128, a, b, c, d);
        }
        Error vinsertf32x4(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf32x4, a, b, c, d, e);
        }
        Error vinsertf32x4(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf32x4, a, b, c, d, e);
        }
        Error vinsertf32x4(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf32x4, a, b, c, d, e);
        }
        Error vinsertf32x4(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf32x4, a, b, c, d, e);
        }
        Error vinsertf32x8(const Zmm& a, const Mask& b, const Zmm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf32x8, a, b, c, d, e);
        }
        Error vinsertf32x8(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf32x8, a, b, c, d, e);
        }
        Error vinsertf64x2(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf64x2, a, b, c, d, e);
        }
        Error vinsertf64x2(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf64x2, a, b, c, d, e);
        }
        Error vinsertf64x2(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf64x2, a, b, c, d, e);
        }
        Error vinsertf64x2(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf64x2, a, b, c, d, e);
        }
        Error vinsertf64x4(const Zmm& a, const Mask& b, const Zmm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf64x4, a, b, c, d, e);
        }
        Error vinsertf64x4(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinsertf64x4, a, b, c, d, e);
        }
        Error vinserti128(const Ymm& a, const Ymm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vinserti128, a, b, c, d);
        }
        Error vinserti128(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vinserti128, a, b, c, d);
        }
        Error vinserti32x4(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti32x4, a, b, c, d, e);
        }
        Error vinserti32x4(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti32x4, a, b, c, d, e);
        }
        Error vinserti32x4(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti32x4, a, b, c, d, e);
        }
        Error vinserti32x4(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti32x4, a, b, c, d, e);
        }
        Error vinserti32x8(const Zmm& a, const Mask& b, const Zmm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti32x8, a, b, c, d, e);
        }
        Error vinserti32x8(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti32x8, a, b, c, d, e);
        }
        Error vinserti64x2(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti64x2, a, b, c, d, e);
        }
        Error vinserti64x2(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti64x2, a, b, c, d, e);
        }
        Error vinserti64x2(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti64x2, a, b, c, d, e);
        }
        Error vinserti64x2(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti64x2, a, b, c, d, e);
        }
        Error vinserti64x4(const Zmm& a, const Mask& b, const Zmm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti64x4, a, b, c, d, e);
        }
        Error vinserti64x4(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vinserti64x4, a, b, c, d, e);
        }
        Error vinsertps(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vinsertps, a, b, c, d);
        }
        Error vinsertps(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vinsertps, a, b, c, d);
        }
        Error vlddqu(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vlddqu, a, b);
        }
        Error vlddqu(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vlddqu, a, b);
        }
        Error vldmxcsr(const Mem& a)
        {
            return emit(x86::Mnemonic::Vldmxcsr, a);
        }
        Error vloadunpackhd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpackhd, a, b, c);
        }
        Error vloadunpackhpd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpackhpd, a, b, c);
        }
        Error vloadunpackhps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpackhps, a, b, c);
        }
        Error vloadunpackhq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpackhq, a, b, c);
        }
        Error vloadunpackld(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpackld, a, b, c);
        }
        Error vloadunpacklpd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpacklpd, a, b, c);
        }
        Error vloadunpacklps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpacklps, a, b, c);
        }
        Error vloadunpacklq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vloadunpacklq, a, b, c);
        }
        Error vlog2ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vlog2ps, a, b, c);
        }
        Error vlog2ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vlog2ps, a, b, c);
        }
        Error vmaskmovdqu(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmaskmovdqu, a, b);
        }
        Error vmaskmovpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaskmovpd, a, b, c);
        }
        Error vmaskmovpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaskmovpd, a, b, c);
        }
        Error vmaskmovpd(const Mem& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmaskmovpd, a, b, c);
        }
        Error vmaskmovpd(const Mem& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmaskmovpd, a, b, c);
        }
        Error vmaskmovps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaskmovps, a, b, c);
        }
        Error vmaskmovps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaskmovps, a, b, c);
        }
        Error vmaskmovps(const Mem& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmaskmovps, a, b, c);
        }
        Error vmaskmovps(const Mem& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmaskmovps, a, b, c);
        }
        Error vmaxpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c);
        }
        Error vmaxpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c);
        }
        Error vmaxpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c);
        }
        Error vmaxpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c);
        }
        Error vmaxpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c, d);
        }
        Error vmaxpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c, d);
        }
        Error vmaxpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c, d);
        }
        Error vmaxpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c, d);
        }
        Error vmaxpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c, d);
        }
        Error vmaxpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxpd, a, b, c, d);
        }
        Error vmaxph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vmaxph, a, b, c, d);
        }
        Error vmaxph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmaxph, a, b, c, d);
        }
        Error vmaxph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vmaxph, a, b, c, d);
        }
        Error vmaxph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxph, a, b, c, d);
        }
        Error vmaxph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxph, a, b, c, d);
        }
        Error vmaxph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxph, a, b, c, d);
        }
        Error vmaxps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c);
        }
        Error vmaxps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c);
        }
        Error vmaxps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c);
        }
        Error vmaxps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c);
        }
        Error vmaxps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c, d);
        }
        Error vmaxps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c, d);
        }
        Error vmaxps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c, d);
        }
        Error vmaxps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c, d);
        }
        Error vmaxps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c, d);
        }
        Error vmaxps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxps, a, b, c, d);
        }
        Error vmaxsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmaxsd, a, b, c);
        }
        Error vmaxsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaxsd, a, b, c);
        }
        Error vmaxsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmaxsd, a, b, c, d);
        }
        Error vmaxsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxsd, a, b, c, d);
        }
        Error vmaxsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmaxsh, a, b, c, d);
        }
        Error vmaxsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxsh, a, b, c, d);
        }
        Error vmaxss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmaxss, a, b, c);
        }
        Error vmaxss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmaxss, a, b, c);
        }
        Error vmaxss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmaxss, a, b, c, d);
        }
        Error vmaxss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmaxss, a, b, c, d);
        }
        Error vmcall()
        {
            return emit(x86::Mnemonic::Vmcall);
        }
        Error vmclear(const Mem& a)
        {
            return emit(x86::Mnemonic::Vmclear, a);
        }
        Error vmfunc()
        {
            return emit(x86::Mnemonic::Vmfunc);
        }
        Error vminpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c);
        }
        Error vminpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c);
        }
        Error vminpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c);
        }
        Error vminpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c);
        }
        Error vminpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c, d);
        }
        Error vminpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c, d);
        }
        Error vminpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c, d);
        }
        Error vminpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c, d);
        }
        Error vminpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c, d);
        }
        Error vminpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminpd, a, b, c, d);
        }
        Error vminph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vminph, a, b, c, d);
        }
        Error vminph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vminph, a, b, c, d);
        }
        Error vminph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vminph, a, b, c, d);
        }
        Error vminph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminph, a, b, c, d);
        }
        Error vminph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminph, a, b, c, d);
        }
        Error vminph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminph, a, b, c, d);
        }
        Error vminps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c);
        }
        Error vminps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c);
        }
        Error vminps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c);
        }
        Error vminps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c);
        }
        Error vminps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c, d);
        }
        Error vminps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c, d);
        }
        Error vminps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c, d);
        }
        Error vminps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c, d);
        }
        Error vminps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c, d);
        }
        Error vminps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminps, a, b, c, d);
        }
        Error vminsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vminsd, a, b, c);
        }
        Error vminsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vminsd, a, b, c);
        }
        Error vminsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vminsd, a, b, c, d);
        }
        Error vminsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminsd, a, b, c, d);
        }
        Error vminsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vminsh, a, b, c, d);
        }
        Error vminsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminsh, a, b, c, d);
        }
        Error vminss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vminss, a, b, c);
        }
        Error vminss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vminss, a, b, c);
        }
        Error vminss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vminss, a, b, c, d);
        }
        Error vminss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vminss, a, b, c, d);
        }
        Error vmlaunch()
        {
            return emit(x86::Mnemonic::Vmlaunch);
        }
        Error vmload(const Gp& a)
        {
            return emit(x86::Mnemonic::Vmload, a);
        }
        Error vmmcall()
        {
            return emit(x86::Mnemonic::Vmmcall);
        }
        Error vmovapd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b);
        }
        Error vmovapd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b);
        }
        Error vmovapd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b);
        }
        Error vmovapd(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b);
        }
        Error vmovapd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b);
        }
        Error vmovapd(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b);
        }
        Error vmovapd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        Error vmovapd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        Error vmovapd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        Error vmovapd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        Error vmovapd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        Error vmovapd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        Error vmovapd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        Error vmovapd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        Error vmovapd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovapd, a, b, c);
        }
        Error vmovaps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b);
        }
        Error vmovaps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b);
        }
        Error vmovaps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b);
        }
        Error vmovaps(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b);
        }
        Error vmovaps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b);
        }
        Error vmovaps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b);
        }
        Error vmovaps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        Error vmovaps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        Error vmovaps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        Error vmovaps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        Error vmovaps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        Error vmovaps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        Error vmovaps(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        Error vmovaps(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        Error vmovaps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovaps, a, b, c);
        }
        Error vmovd(const Xmm& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Vmovd, a, b);
        }
        Error vmovd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovd, a, b);
        }
        Error vmovd(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovd, a, b);
        }
        Error vmovd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovd, a, b);
        }
        Error vmovddup(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b);
        }
        Error vmovddup(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b);
        }
        Error vmovddup(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b);
        }
        Error vmovddup(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b);
        }
        Error vmovddup(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b, c);
        }
        Error vmovddup(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b, c);
        }
        Error vmovddup(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b, c);
        }
        Error vmovddup(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b, c);
        }
        Error vmovddup(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b, c);
        }
        Error vmovddup(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovddup, a, b, c);
        }
        Error vmovdqa(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovdqa, a, b);
        }
        Error vmovdqa(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovdqa, a, b);
        }
        Error vmovdqa(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovdqa, a, b);
        }
        Error vmovdqa(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovdqa, a, b);
        }
        Error vmovdqa(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovdqa, a, b);
        }
        Error vmovdqa(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovdqa, a, b);
        }
        Error vmovdqa32(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        Error vmovdqa32(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        Error vmovdqa32(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        Error vmovdqa32(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        Error vmovdqa32(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        Error vmovdqa32(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        Error vmovdqa32(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        Error vmovdqa32(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        Error vmovdqa32(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa32, a, b, c);
        }
        Error vmovdqa64(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        Error vmovdqa64(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        Error vmovdqa64(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        Error vmovdqa64(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        Error vmovdqa64(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        Error vmovdqa64(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        Error vmovdqa64(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        Error vmovdqa64(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        Error vmovdqa64(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqa64, a, b, c);
        }
        Error vmovdqu(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovdqu, a, b);
        }
        Error vmovdqu(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovdqu, a, b);
        }
        Error vmovdqu(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovdqu, a, b);
        }
        Error vmovdqu(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovdqu, a, b);
        }
        Error vmovdqu(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovdqu, a, b);
        }
        Error vmovdqu(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovdqu, a, b);
        }
        Error vmovdqu16(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        Error vmovdqu16(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        Error vmovdqu16(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        Error vmovdqu16(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        Error vmovdqu16(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        Error vmovdqu16(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        Error vmovdqu16(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        Error vmovdqu16(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        Error vmovdqu16(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu16, a, b, c);
        }
        Error vmovdqu32(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        Error vmovdqu32(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        Error vmovdqu32(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        Error vmovdqu32(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        Error vmovdqu32(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        Error vmovdqu32(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        Error vmovdqu32(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        Error vmovdqu32(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        Error vmovdqu32(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu32, a, b, c);
        }
        Error vmovdqu64(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        Error vmovdqu64(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        Error vmovdqu64(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        Error vmovdqu64(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        Error vmovdqu64(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        Error vmovdqu64(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        Error vmovdqu64(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        Error vmovdqu64(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        Error vmovdqu64(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu64, a, b, c);
        }
        Error vmovdqu8(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        Error vmovdqu8(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        Error vmovdqu8(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        Error vmovdqu8(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        Error vmovdqu8(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        Error vmovdqu8(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        Error vmovdqu8(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        Error vmovdqu8(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        Error vmovdqu8(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovdqu8, a, b, c);
        }
        Error vmovhlps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovhlps, a, b, c);
        }
        Error vmovhpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovhpd, a, b, c);
        }
        Error vmovhpd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovhpd, a, b);
        }
        Error vmovhps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovhps, a, b, c);
        }
        Error vmovhps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovhps, a, b);
        }
        Error vmovlhps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovlhps, a, b, c);
        }
        Error vmovlpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovlpd, a, b, c);
        }
        Error vmovlpd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovlpd, a, b);
        }
        Error vmovlps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovlps, a, b, c);
        }
        Error vmovlps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovlps, a, b);
        }
        Error vmovmskpd(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovmskpd, a, b);
        }
        Error vmovmskpd(const Gp32& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovmskpd, a, b);
        }
        Error vmovmskps(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovmskps, a, b);
        }
        Error vmovmskps(const Gp32& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovmskps, a, b);
        }
        Error vmovnrapd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovnrapd, a, b, c);
        }
        Error vmovnraps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovnraps, a, b, c);
        }
        Error vmovnrngoapd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovnrngoapd, a, b, c);
        }
        Error vmovnrngoaps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovnrngoaps, a, b, c);
        }
        Error vmovntdq(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovntdq, a, b);
        }
        Error vmovntdq(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovntdq, a, b);
        }
        Error vmovntdq(const Mem& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vmovntdq, a, b);
        }
        Error vmovntdqa(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovntdqa, a, b);
        }
        Error vmovntdqa(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovntdqa, a, b);
        }
        Error vmovntdqa(const Zmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovntdqa, a, b);
        }
        Error vmovntpd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovntpd, a, b);
        }
        Error vmovntpd(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovntpd, a, b);
        }
        Error vmovntpd(const Mem& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vmovntpd, a, b);
        }
        Error vmovntps(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovntps, a, b);
        }
        Error vmovntps(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovntps, a, b);
        }
        Error vmovntps(const Mem& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vmovntps, a, b);
        }
        Error vmovq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovq, a, b);
        }
        Error vmovq(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovq, a, b);
        }
        Error vmovq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovq, a, b);
        }
        Error vmovq(const Xmm& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Vmovq, a, b);
        }
        Error vmovq(const Gp64& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovq, a, b);
        }
        Error vmovsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovsd, a, b);
        }
        Error vmovsd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovsd, a, b);
        }
        Error vmovsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovsd, a, b, c);
        }
        Error vmovsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmovsd, a, b, c, d);
        }
        Error vmovsd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovsd, a, b, c);
        }
        Error vmovsd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovsd, a, b, c);
        }
        Error vmovsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmovsh, a, b, c, d);
        }
        Error vmovsh(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovsh, a, b, c);
        }
        Error vmovsh(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovsh, a, b, c);
        }
        Error vmovshdup(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b);
        }
        Error vmovshdup(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b);
        }
        Error vmovshdup(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b);
        }
        Error vmovshdup(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b);
        }
        Error vmovshdup(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b, c);
        }
        Error vmovshdup(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b, c);
        }
        Error vmovshdup(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b, c);
        }
        Error vmovshdup(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b, c);
        }
        Error vmovshdup(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b, c);
        }
        Error vmovshdup(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovshdup, a, b, c);
        }
        Error vmovsldup(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b);
        }
        Error vmovsldup(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b);
        }
        Error vmovsldup(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b);
        }
        Error vmovsldup(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b);
        }
        Error vmovsldup(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b, c);
        }
        Error vmovsldup(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b, c);
        }
        Error vmovsldup(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b, c);
        }
        Error vmovsldup(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b, c);
        }
        Error vmovsldup(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b, c);
        }
        Error vmovsldup(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovsldup, a, b, c);
        }
        Error vmovss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovss, a, b);
        }
        Error vmovss(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovss, a, b);
        }
        Error vmovss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovss, a, b, c);
        }
        Error vmovss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmovss, a, b, c, d);
        }
        Error vmovss(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovss, a, b, c);
        }
        Error vmovss(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovss, a, b, c);
        }
        Error vmovupd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b);
        }
        Error vmovupd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b);
        }
        Error vmovupd(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b);
        }
        Error vmovupd(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b);
        }
        Error vmovupd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b);
        }
        Error vmovupd(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b);
        }
        Error vmovupd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        Error vmovupd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        Error vmovupd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        Error vmovupd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        Error vmovupd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        Error vmovupd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        Error vmovupd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        Error vmovupd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        Error vmovupd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovupd, a, b, c);
        }
        Error vmovups(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovups, a, b);
        }
        Error vmovups(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovups, a, b);
        }
        Error vmovups(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovups, a, b);
        }
        Error vmovups(const Mem& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovups, a, b);
        }
        Error vmovups(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovups, a, b);
        }
        Error vmovups(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vmovups, a, b);
        }
        Error vmovups(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        Error vmovups(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        Error vmovups(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        Error vmovups(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        Error vmovups(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        Error vmovups(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        Error vmovups(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        Error vmovups(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        Error vmovups(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vmovups, a, b, c);
        }
        Error vmovw(const Xmm& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Vmovw, a, b);
        }
        Error vmovw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmovw, a, b);
        }
        Error vmovw(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovw, a, b);
        }
        Error vmovw(const Mem& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vmovw, a, b);
        }
        Error vmpsadbw(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vmpsadbw, a, b, c, d);
        }
        Error vmpsadbw(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vmpsadbw, a, b, c, d);
        }
        Error vmpsadbw(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vmpsadbw, a, b, c, d);
        }
        Error vmpsadbw(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vmpsadbw, a, b, c, d);
        }
        Error vmptrld(const Mem& a)
        {
            return emit(x86::Mnemonic::Vmptrld, a);
        }
        Error vmptrst(const Mem& a)
        {
            return emit(x86::Mnemonic::Vmptrst, a);
        }
        Error vmread(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Vmread, a, b);
        }
        Error vmread(const Mem& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Vmread, a, b);
        }
        Error vmread(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Vmread, a, b);
        }
        Error vmread(const Mem& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Vmread, a, b);
        }
        Error vmresume()
        {
            return emit(x86::Mnemonic::Vmresume);
        }
        Error vmrun(const Gp& a)
        {
            return emit(x86::Mnemonic::Vmrun, a);
        }
        Error vmsave(const Gp& a)
        {
            return emit(x86::Mnemonic::Vmsave, a);
        }
        Error vmulpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c);
        }
        Error vmulpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c);
        }
        Error vmulpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c);
        }
        Error vmulpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c);
        }
        Error vmulpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c, d);
        }
        Error vmulpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c, d);
        }
        Error vmulpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c, d);
        }
        Error vmulpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c, d);
        }
        Error vmulpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c, d);
        }
        Error vmulpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulpd, a, b, c, d);
        }
        Error vmulph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vmulph, a, b, c, d);
        }
        Error vmulph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmulph, a, b, c, d);
        }
        Error vmulph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vmulph, a, b, c, d);
        }
        Error vmulph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulph, a, b, c, d);
        }
        Error vmulph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulph, a, b, c, d);
        }
        Error vmulph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulph, a, b, c, d);
        }
        Error vmulps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c);
        }
        Error vmulps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c);
        }
        Error vmulps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c);
        }
        Error vmulps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c);
        }
        Error vmulps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c, d);
        }
        Error vmulps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c, d);
        }
        Error vmulps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c, d);
        }
        Error vmulps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c, d);
        }
        Error vmulps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c, d);
        }
        Error vmulps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulps, a, b, c, d);
        }
        Error vmulsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmulsd, a, b, c);
        }
        Error vmulsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmulsd, a, b, c);
        }
        Error vmulsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmulsd, a, b, c, d);
        }
        Error vmulsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulsd, a, b, c, d);
        }
        Error vmulsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmulsh, a, b, c, d);
        }
        Error vmulsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulsh, a, b, c, d);
        }
        Error vmulss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vmulss, a, b, c);
        }
        Error vmulss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vmulss, a, b, c);
        }
        Error vmulss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vmulss, a, b, c, d);
        }
        Error vmulss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vmulss, a, b, c, d);
        }
        Error vmwrite(const Gp64& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Vmwrite, a, b);
        }
        Error vmwrite(const Gp64& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmwrite, a, b);
        }
        Error vmwrite(const Gp32& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Vmwrite, a, b);
        }
        Error vmwrite(const Gp32& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vmwrite, a, b);
        }
        Error vmxoff()
        {
            return emit(x86::Mnemonic::Vmxoff);
        }
        Error vmxon(const Mem& a)
        {
            return emit(x86::Mnemonic::Vmxon, a);
        }
        Error vorpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c);
        }
        Error vorpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c);
        }
        Error vorpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c);
        }
        Error vorpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c);
        }
        Error vorpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c, d);
        }
        Error vorpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c, d);
        }
        Error vorpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c, d);
        }
        Error vorpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c, d);
        }
        Error vorpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c, d);
        }
        Error vorpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vorpd, a, b, c, d);
        }
        Error vorps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c);
        }
        Error vorps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c);
        }
        Error vorps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c);
        }
        Error vorps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c);
        }
        Error vorps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c, d);
        }
        Error vorps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c, d);
        }
        Error vorps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c, d);
        }
        Error vorps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c, d);
        }
        Error vorps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c, d);
        }
        Error vorps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vorps, a, b, c, d);
        }
        Error vp2intersectd(const Mask& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vp2intersectd, a, b, c);
        }
        Error vp2intersectd(const Mask& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vp2intersectd, a, b, c);
        }
        Error vp2intersectd(const Mask& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vp2intersectd, a, b, c);
        }
        Error vp2intersectd(const Mask& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vp2intersectd, a, b, c);
        }
        Error vp2intersectd(const Mask& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vp2intersectd, a, b, c);
        }
        Error vp2intersectd(const Mask& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vp2intersectd, a, b, c);
        }
        Error vp2intersectq(const Mask& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vp2intersectq, a, b, c);
        }
        Error vp2intersectq(const Mask& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vp2intersectq, a, b, c);
        }
        Error vp2intersectq(const Mask& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vp2intersectq, a, b, c);
        }
        Error vp2intersectq(const Mask& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vp2intersectq, a, b, c);
        }
        Error vp2intersectq(const Mask& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vp2intersectq, a, b, c);
        }
        Error vp2intersectq(const Mask& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vp2intersectq, a, b, c);
        }
        Error vp4dpwssd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vp4dpwssd, a, b, c, d);
        }
        Error vp4dpwssds(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vp4dpwssds, a, b, c, d);
        }
        Error vpabsb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b);
        }
        Error vpabsb(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b);
        }
        Error vpabsb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b);
        }
        Error vpabsb(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b);
        }
        Error vpabsb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b, c);
        }
        Error vpabsb(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b, c);
        }
        Error vpabsb(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b, c);
        }
        Error vpabsb(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b, c);
        }
        Error vpabsb(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b, c);
        }
        Error vpabsb(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsb, a, b, c);
        }
        Error vpabsd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b);
        }
        Error vpabsd(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b);
        }
        Error vpabsd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b);
        }
        Error vpabsd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b);
        }
        Error vpabsd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b, c);
        }
        Error vpabsd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b, c);
        }
        Error vpabsd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b, c);
        }
        Error vpabsd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b, c);
        }
        Error vpabsd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b, c);
        }
        Error vpabsd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsd, a, b, c);
        }
        Error vpabsq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpabsq, a, b, c);
        }
        Error vpabsq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpabsq, a, b, c);
        }
        Error vpabsq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpabsq, a, b, c);
        }
        Error vpabsq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsq, a, b, c);
        }
        Error vpabsq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsq, a, b, c);
        }
        Error vpabsq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsq, a, b, c);
        }
        Error vpabsw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b);
        }
        Error vpabsw(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b);
        }
        Error vpabsw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b);
        }
        Error vpabsw(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b);
        }
        Error vpabsw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b, c);
        }
        Error vpabsw(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b, c);
        }
        Error vpabsw(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b, c);
        }
        Error vpabsw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b, c);
        }
        Error vpabsw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b, c);
        }
        Error vpabsw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpabsw, a, b, c);
        }
        Error vpackssdw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c);
        }
        Error vpackssdw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c);
        }
        Error vpackssdw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c);
        }
        Error vpackssdw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c);
        }
        Error vpackssdw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c, d);
        }
        Error vpackssdw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c, d);
        }
        Error vpackssdw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c, d);
        }
        Error vpackssdw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c, d);
        }
        Error vpackssdw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c, d);
        }
        Error vpackssdw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackssdw, a, b, c, d);
        }
        Error vpacksswb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c);
        }
        Error vpacksswb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c);
        }
        Error vpacksswb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c);
        }
        Error vpacksswb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c);
        }
        Error vpacksswb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c, d);
        }
        Error vpacksswb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c, d);
        }
        Error vpacksswb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c, d);
        }
        Error vpacksswb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c, d);
        }
        Error vpacksswb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c, d);
        }
        Error vpacksswb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpacksswb, a, b, c, d);
        }
        Error vpackstorehd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorehd, a, b, c);
        }
        Error vpackstorehpd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorehpd, a, b, c);
        }
        Error vpackstorehps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorehps, a, b, c);
        }
        Error vpackstorehq(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorehq, a, b, c);
        }
        Error vpackstoreld(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstoreld, a, b, c);
        }
        Error vpackstorelpd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorelpd, a, b, c);
        }
        Error vpackstorelps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorelps, a, b, c);
        }
        Error vpackstorelq(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpackstorelq, a, b, c);
        }
        Error vpackusdw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c);
        }
        Error vpackusdw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c);
        }
        Error vpackusdw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c);
        }
        Error vpackusdw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c);
        }
        Error vpackusdw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c, d);
        }
        Error vpackusdw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c, d);
        }
        Error vpackusdw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c, d);
        }
        Error vpackusdw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c, d);
        }
        Error vpackusdw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c, d);
        }
        Error vpackusdw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackusdw, a, b, c, d);
        }
        Error vpackuswb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c);
        }
        Error vpackuswb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c);
        }
        Error vpackuswb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c);
        }
        Error vpackuswb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c);
        }
        Error vpackuswb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c, d);
        }
        Error vpackuswb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c, d);
        }
        Error vpackuswb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c, d);
        }
        Error vpackuswb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c, d);
        }
        Error vpackuswb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c, d);
        }
        Error vpackuswb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpackuswb, a, b, c, d);
        }
        Error vpadcd(const Zmm& a, const Mask& b, const Mask& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpadcd, a, b, c, d);
        }
        Error vpadcd(const Zmm& a, const Mask& b, const Mask& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpadcd, a, b, c, d);
        }
        Error vpaddb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c);
        }
        Error vpaddb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c);
        }
        Error vpaddb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c);
        }
        Error vpaddb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c);
        }
        Error vpaddb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c, d);
        }
        Error vpaddb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c, d);
        }
        Error vpaddb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c, d);
        }
        Error vpaddb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c, d);
        }
        Error vpaddb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c, d);
        }
        Error vpaddb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddb, a, b, c, d);
        }
        Error vpaddd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c);
        }
        Error vpaddd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c);
        }
        Error vpaddd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c);
        }
        Error vpaddd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c);
        }
        Error vpaddd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c, d);
        }
        Error vpaddd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c, d);
        }
        Error vpaddd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c, d);
        }
        Error vpaddd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c, d);
        }
        Error vpaddd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c, d);
        }
        Error vpaddd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddd, a, b, c, d);
        }
        Error vpaddq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c);
        }
        Error vpaddq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c);
        }
        Error vpaddq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c);
        }
        Error vpaddq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c);
        }
        Error vpaddq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c, d);
        }
        Error vpaddq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c, d);
        }
        Error vpaddq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c, d);
        }
        Error vpaddq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c, d);
        }
        Error vpaddq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c, d);
        }
        Error vpaddq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddq, a, b, c, d);
        }
        Error vpaddsb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c);
        }
        Error vpaddsb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c);
        }
        Error vpaddsb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c);
        }
        Error vpaddsb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c);
        }
        Error vpaddsb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c, d);
        }
        Error vpaddsb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c, d);
        }
        Error vpaddsb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c, d);
        }
        Error vpaddsb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c, d);
        }
        Error vpaddsb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c, d);
        }
        Error vpaddsb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsb, a, b, c, d);
        }
        Error vpaddsetcd(const Zmm& a, const Mask& b, const Mask& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddsetcd, a, b, c, d);
        }
        Error vpaddsetcd(const Zmm& a, const Mask& b, const Mask& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsetcd, a, b, c, d);
        }
        Error vpaddsetsd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddsetsd, a, b, c, d);
        }
        Error vpaddsetsd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsetsd, a, b, c, d);
        }
        Error vpaddsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c);
        }
        Error vpaddsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c);
        }
        Error vpaddsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c);
        }
        Error vpaddsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c);
        }
        Error vpaddsw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c, d);
        }
        Error vpaddsw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c, d);
        }
        Error vpaddsw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c, d);
        }
        Error vpaddsw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c, d);
        }
        Error vpaddsw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c, d);
        }
        Error vpaddsw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddsw, a, b, c, d);
        }
        Error vpaddusb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c);
        }
        Error vpaddusb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c);
        }
        Error vpaddusb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c);
        }
        Error vpaddusb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c);
        }
        Error vpaddusb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c, d);
        }
        Error vpaddusb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c, d);
        }
        Error vpaddusb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c, d);
        }
        Error vpaddusb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c, d);
        }
        Error vpaddusb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c, d);
        }
        Error vpaddusb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddusb, a, b, c, d);
        }
        Error vpaddusw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c);
        }
        Error vpaddusw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c);
        }
        Error vpaddusw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c);
        }
        Error vpaddusw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c);
        }
        Error vpaddusw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c, d);
        }
        Error vpaddusw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c, d);
        }
        Error vpaddusw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c, d);
        }
        Error vpaddusw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c, d);
        }
        Error vpaddusw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c, d);
        }
        Error vpaddusw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddusw, a, b, c, d);
        }
        Error vpaddw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c);
        }
        Error vpaddw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c);
        }
        Error vpaddw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c);
        }
        Error vpaddw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c);
        }
        Error vpaddw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c, d);
        }
        Error vpaddw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c, d);
        }
        Error vpaddw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c, d);
        }
        Error vpaddw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c, d);
        }
        Error vpaddw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c, d);
        }
        Error vpaddw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpaddw, a, b, c, d);
        }
        Error vpalignr(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d);
        }
        Error vpalignr(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d);
        }
        Error vpalignr(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d);
        }
        Error vpalignr(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d);
        }
        Error vpalignr(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d, e);
        }
        Error vpalignr(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d, e);
        }
        Error vpalignr(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d, e);
        }
        Error vpalignr(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d, e);
        }
        Error vpalignr(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d, e);
        }
        Error vpalignr(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpalignr, a, b, c, d, e);
        }
        Error vpand(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpand, a, b, c);
        }
        Error vpand(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpand, a, b, c);
        }
        Error vpand(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpand, a, b, c);
        }
        Error vpand(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpand, a, b, c);
        }
        Error vpandd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpandd, a, b, c, d);
        }
        Error vpandd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpandd, a, b, c, d);
        }
        Error vpandd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpandd, a, b, c, d);
        }
        Error vpandd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandd, a, b, c, d);
        }
        Error vpandd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandd, a, b, c, d);
        }
        Error vpandd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandd, a, b, c, d);
        }
        Error vpandn(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpandn, a, b, c);
        }
        Error vpandn(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpandn, a, b, c);
        }
        Error vpandn(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpandn, a, b, c);
        }
        Error vpandn(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpandn, a, b, c);
        }
        Error vpandnd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpandnd, a, b, c, d);
        }
        Error vpandnd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpandnd, a, b, c, d);
        }
        Error vpandnd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpandnd, a, b, c, d);
        }
        Error vpandnd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandnd, a, b, c, d);
        }
        Error vpandnd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandnd, a, b, c, d);
        }
        Error vpandnd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandnd, a, b, c, d);
        }
        Error vpandnq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpandnq, a, b, c, d);
        }
        Error vpandnq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpandnq, a, b, c, d);
        }
        Error vpandnq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpandnq, a, b, c, d);
        }
        Error vpandnq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandnq, a, b, c, d);
        }
        Error vpandnq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandnq, a, b, c, d);
        }
        Error vpandnq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandnq, a, b, c, d);
        }
        Error vpandq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpandq, a, b, c, d);
        }
        Error vpandq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpandq, a, b, c, d);
        }
        Error vpandq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpandq, a, b, c, d);
        }
        Error vpandq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandq, a, b, c, d);
        }
        Error vpandq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandq, a, b, c, d);
        }
        Error vpandq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpandq, a, b, c, d);
        }
        Error vpavgb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c);
        }
        Error vpavgb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c);
        }
        Error vpavgb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c);
        }
        Error vpavgb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c);
        }
        Error vpavgb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c, d);
        }
        Error vpavgb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c, d);
        }
        Error vpavgb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c, d);
        }
        Error vpavgb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c, d);
        }
        Error vpavgb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c, d);
        }
        Error vpavgb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpavgb, a, b, c, d);
        }
        Error vpavgw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c);
        }
        Error vpavgw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c);
        }
        Error vpavgw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c);
        }
        Error vpavgw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c);
        }
        Error vpavgw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c, d);
        }
        Error vpavgw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c, d);
        }
        Error vpavgw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c, d);
        }
        Error vpavgw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c, d);
        }
        Error vpavgw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c, d);
        }
        Error vpavgw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpavgw, a, b, c, d);
        }
        Error vpblendd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendd, a, b, c, d);
        }
        Error vpblendd(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendd, a, b, c, d);
        }
        Error vpblendd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendd, a, b, c, d);
        }
        Error vpblendd(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendd, a, b, c, d);
        }
        Error vpblendmb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmb, a, b, c, d);
        }
        Error vpblendmb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpblendmb, a, b, c, d);
        }
        Error vpblendmb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmb, a, b, c, d);
        }
        Error vpblendmb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmb, a, b, c, d);
        }
        Error vpblendmb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmb, a, b, c, d);
        }
        Error vpblendmb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmb, a, b, c, d);
        }
        Error vpblendmd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmd, a, b, c, d);
        }
        Error vpblendmd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpblendmd, a, b, c, d);
        }
        Error vpblendmd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmd, a, b, c, d);
        }
        Error vpblendmd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmd, a, b, c, d);
        }
        Error vpblendmd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmd, a, b, c, d);
        }
        Error vpblendmd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmd, a, b, c, d);
        }
        Error vpblendmq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmq, a, b, c, d);
        }
        Error vpblendmq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpblendmq, a, b, c, d);
        }
        Error vpblendmq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmq, a, b, c, d);
        }
        Error vpblendmq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmq, a, b, c, d);
        }
        Error vpblendmq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmq, a, b, c, d);
        }
        Error vpblendmq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmq, a, b, c, d);
        }
        Error vpblendmw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmw, a, b, c, d);
        }
        Error vpblendmw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpblendmw, a, b, c, d);
        }
        Error vpblendmw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpblendmw, a, b, c, d);
        }
        Error vpblendmw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmw, a, b, c, d);
        }
        Error vpblendmw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmw, a, b, c, d);
        }
        Error vpblendmw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpblendmw, a, b, c, d);
        }
        Error vpblendvb(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpblendvb, a, b, c, d);
        }
        Error vpblendvb(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpblendvb, a, b, c, d);
        }
        Error vpblendvb(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpblendvb, a, b, c, d);
        }
        Error vpblendvb(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpblendvb, a, b, c, d);
        }
        Error vpblendw(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendw, a, b, c, d);
        }
        Error vpblendw(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendw, a, b, c, d);
        }
        Error vpblendw(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendw, a, b, c, d);
        }
        Error vpblendw(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpblendw, a, b, c, d);
        }
        Error vpbroadcastb(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b);
        }
        Error vpbroadcastb(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b);
        }
        Error vpbroadcastb(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b);
        }
        Error vpbroadcastb(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b);
        }
        Error vpbroadcastb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        Error vpbroadcastb(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        Error vpbroadcastb(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        Error vpbroadcastb(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        Error vpbroadcastb(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        Error vpbroadcastb(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        Error vpbroadcastb(const Xmm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        Error vpbroadcastb(const Ymm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        Error vpbroadcastb(const Zmm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastb, a, b, c);
        }
        Error vpbroadcastd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b);
        }
        Error vpbroadcastd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b);
        }
        Error vpbroadcastd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b);
        }
        Error vpbroadcastd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b);
        }
        Error vpbroadcastd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        Error vpbroadcastd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        Error vpbroadcastd(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        Error vpbroadcastd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        Error vpbroadcastd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        Error vpbroadcastd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        Error vpbroadcastd(const Xmm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        Error vpbroadcastd(const Ymm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        Error vpbroadcastd(const Zmm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastd, a, b, c);
        }
        Error vpbroadcastmb2q(const Xmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastmb2q, a, b);
        }
        Error vpbroadcastmb2q(const Ymm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastmb2q, a, b);
        }
        Error vpbroadcastmb2q(const Zmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastmb2q, a, b);
        }
        Error vpbroadcastmw2d(const Xmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastmw2d, a, b);
        }
        Error vpbroadcastmw2d(const Ymm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastmw2d, a, b);
        }
        Error vpbroadcastmw2d(const Zmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastmw2d, a, b);
        }
        Error vpbroadcastq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b);
        }
        Error vpbroadcastq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b);
        }
        Error vpbroadcastq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b);
        }
        Error vpbroadcastq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b);
        }
        Error vpbroadcastq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        Error vpbroadcastq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        Error vpbroadcastq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        Error vpbroadcastq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        Error vpbroadcastq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        Error vpbroadcastq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        Error vpbroadcastq(const Xmm& a, const Mask& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        Error vpbroadcastq(const Ymm& a, const Mask& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        Error vpbroadcastq(const Zmm& a, const Mask& b, const Gp64& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastq, a, b, c);
        }
        Error vpbroadcastw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b);
        }
        Error vpbroadcastw(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b);
        }
        Error vpbroadcastw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b);
        }
        Error vpbroadcastw(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b);
        }
        Error vpbroadcastw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        Error vpbroadcastw(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        Error vpbroadcastw(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        Error vpbroadcastw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        Error vpbroadcastw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        Error vpbroadcastw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        Error vpbroadcastw(const Xmm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        Error vpbroadcastw(const Ymm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        Error vpbroadcastw(const Zmm& a, const Mask& b, const Gp32& c)
        {
            return emit(x86::Mnemonic::Vpbroadcastw, a, b, c);
        }
        Error vpclmulqdq(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpclmulqdq, a, b, c, d);
        }
        Error vpclmulqdq(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpclmulqdq, a, b, c, d);
        }
        Error vpclmulqdq(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpclmulqdq, a, b, c, d);
        }
        Error vpclmulqdq(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpclmulqdq, a, b, c, d);
        }
        Error vpclmulqdq(const Zmm& a, const Zmm& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpclmulqdq, a, b, c, d);
        }
        Error vpclmulqdq(const Zmm& a, const Zmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpclmulqdq, a, b, c, d);
        }
        Error vpcmov(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmov, a, b, c, d);
        }
        Error vpcmov(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmov, a, b, c, d);
        }
        Error vpcmov(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmov, a, b, c, d);
        }
        Error vpcmov(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmov, a, b, c, d);
        }
        Error vpcmov(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmov, a, b, c, d);
        }
        Error vpcmov(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmov, a, b, c, d);
        }
        Error vpcmpb(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpb, a, b, c, d, e);
        }
        Error vpcmpb(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpb, a, b, c, d, e);
        }
        Error vpcmpb(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpb, a, b, c, d, e);
        }
        Error vpcmpb(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpb, a, b, c, d, e);
        }
        Error vpcmpb(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpb, a, b, c, d, e);
        }
        Error vpcmpb(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpb, a, b, c, d, e);
        }
        Error vpcmpd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpd, a, b, c, d, e);
        }
        Error vpcmpd(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpd, a, b, c, d, e);
        }
        Error vpcmpd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpd, a, b, c, d, e);
        }
        Error vpcmpd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpd, a, b, c, d, e);
        }
        Error vpcmpd(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpd, a, b, c, d, e);
        }
        Error vpcmpd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpd, a, b, c, d, e);
        }
        Error vpcmpeqb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c);
        }
        Error vpcmpeqb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c);
        }
        Error vpcmpeqb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c);
        }
        Error vpcmpeqb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c);
        }
        Error vpcmpeqb(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c, d);
        }
        Error vpcmpeqb(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c, d);
        }
        Error vpcmpeqb(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c, d);
        }
        Error vpcmpeqb(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c, d);
        }
        Error vpcmpeqb(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c, d);
        }
        Error vpcmpeqb(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqb, a, b, c, d);
        }
        Error vpcmpeqd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c);
        }
        Error vpcmpeqd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c);
        }
        Error vpcmpeqd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c);
        }
        Error vpcmpeqd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c);
        }
        Error vpcmpeqd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c, d);
        }
        Error vpcmpeqd(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c, d);
        }
        Error vpcmpeqd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c, d);
        }
        Error vpcmpeqd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c, d);
        }
        Error vpcmpeqd(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c, d);
        }
        Error vpcmpeqd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqd, a, b, c, d);
        }
        Error vpcmpeqq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c);
        }
        Error vpcmpeqq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c);
        }
        Error vpcmpeqq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c);
        }
        Error vpcmpeqq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c);
        }
        Error vpcmpeqq(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c, d);
        }
        Error vpcmpeqq(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c, d);
        }
        Error vpcmpeqq(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c, d);
        }
        Error vpcmpeqq(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c, d);
        }
        Error vpcmpeqq(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c, d);
        }
        Error vpcmpeqq(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqq, a, b, c, d);
        }
        Error vpcmpeqw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c);
        }
        Error vpcmpeqw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c);
        }
        Error vpcmpeqw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c);
        }
        Error vpcmpeqw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c);
        }
        Error vpcmpeqw(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c, d);
        }
        Error vpcmpeqw(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c, d);
        }
        Error vpcmpeqw(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c, d);
        }
        Error vpcmpeqw(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c, d);
        }
        Error vpcmpeqw(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c, d);
        }
        Error vpcmpeqw(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpeqw, a, b, c, d);
        }
        Error vpcmpestri(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpestri, a, b, c);
        }
        Error vpcmpestri(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpestri, a, b, c);
        }
        Error vpcmpestrm(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpestrm, a, b, c);
        }
        Error vpcmpestrm(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpestrm, a, b, c);
        }
        Error vpcmpgtb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c);
        }
        Error vpcmpgtb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c);
        }
        Error vpcmpgtb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c);
        }
        Error vpcmpgtb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c);
        }
        Error vpcmpgtb(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c, d);
        }
        Error vpcmpgtb(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c, d);
        }
        Error vpcmpgtb(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c, d);
        }
        Error vpcmpgtb(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c, d);
        }
        Error vpcmpgtb(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c, d);
        }
        Error vpcmpgtb(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtb, a, b, c, d);
        }
        Error vpcmpgtd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c);
        }
        Error vpcmpgtd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c);
        }
        Error vpcmpgtd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c);
        }
        Error vpcmpgtd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c);
        }
        Error vpcmpgtd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c, d);
        }
        Error vpcmpgtd(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c, d);
        }
        Error vpcmpgtd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c, d);
        }
        Error vpcmpgtd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c, d);
        }
        Error vpcmpgtd(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c, d);
        }
        Error vpcmpgtd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtd, a, b, c, d);
        }
        Error vpcmpgtq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c);
        }
        Error vpcmpgtq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c);
        }
        Error vpcmpgtq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c);
        }
        Error vpcmpgtq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c);
        }
        Error vpcmpgtq(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c, d);
        }
        Error vpcmpgtq(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c, d);
        }
        Error vpcmpgtq(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c, d);
        }
        Error vpcmpgtq(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c, d);
        }
        Error vpcmpgtq(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c, d);
        }
        Error vpcmpgtq(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtq, a, b, c, d);
        }
        Error vpcmpgtw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c);
        }
        Error vpcmpgtw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c);
        }
        Error vpcmpgtw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c);
        }
        Error vpcmpgtw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c);
        }
        Error vpcmpgtw(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c, d);
        }
        Error vpcmpgtw(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c, d);
        }
        Error vpcmpgtw(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c, d);
        }
        Error vpcmpgtw(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c, d);
        }
        Error vpcmpgtw(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c, d);
        }
        Error vpcmpgtw(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpgtw, a, b, c, d);
        }
        Error vpcmpistri(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpistri, a, b, c);
        }
        Error vpcmpistri(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpistri, a, b, c);
        }
        Error vpcmpistrm(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpistrm, a, b, c);
        }
        Error vpcmpistrm(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpcmpistrm, a, b, c);
        }
        Error vpcmpltd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpcmpltd, a, b, c, d);
        }
        Error vpcmpltd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpcmpltd, a, b, c, d);
        }
        Error vpcmpq(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpq, a, b, c, d, e);
        }
        Error vpcmpq(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpq, a, b, c, d, e);
        }
        Error vpcmpq(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpq, a, b, c, d, e);
        }
        Error vpcmpq(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpq, a, b, c, d, e);
        }
        Error vpcmpq(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpq, a, b, c, d, e);
        }
        Error vpcmpq(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpq, a, b, c, d, e);
        }
        Error vpcmpub(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpub, a, b, c, d, e);
        }
        Error vpcmpub(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpub, a, b, c, d, e);
        }
        Error vpcmpub(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpub, a, b, c, d, e);
        }
        Error vpcmpub(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpub, a, b, c, d, e);
        }
        Error vpcmpub(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpub, a, b, c, d, e);
        }
        Error vpcmpub(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpub, a, b, c, d, e);
        }
        Error vpcmpud(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpud, a, b, c, d, e);
        }
        Error vpcmpud(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpud, a, b, c, d, e);
        }
        Error vpcmpud(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpud, a, b, c, d, e);
        }
        Error vpcmpud(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpud, a, b, c, d, e);
        }
        Error vpcmpud(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpud, a, b, c, d, e);
        }
        Error vpcmpud(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpud, a, b, c, d, e);
        }
        Error vpcmpuq(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuq, a, b, c, d, e);
        }
        Error vpcmpuq(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuq, a, b, c, d, e);
        }
        Error vpcmpuq(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuq, a, b, c, d, e);
        }
        Error vpcmpuq(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuq, a, b, c, d, e);
        }
        Error vpcmpuq(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuq, a, b, c, d, e);
        }
        Error vpcmpuq(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuq, a, b, c, d, e);
        }
        Error vpcmpuw(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuw, a, b, c, d, e);
        }
        Error vpcmpuw(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuw, a, b, c, d, e);
        }
        Error vpcmpuw(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuw, a, b, c, d, e);
        }
        Error vpcmpuw(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuw, a, b, c, d, e);
        }
        Error vpcmpuw(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuw, a, b, c, d, e);
        }
        Error vpcmpuw(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpuw, a, b, c, d, e);
        }
        Error vpcmpw(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpw, a, b, c, d, e);
        }
        Error vpcmpw(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpw, a, b, c, d, e);
        }
        Error vpcmpw(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpw, a, b, c, d, e);
        }
        Error vpcmpw(const Mask& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpw, a, b, c, d, e);
        }
        Error vpcmpw(const Mask& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpw, a, b, c, d, e);
        }
        Error vpcmpw(const Mask& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpcmpw, a, b, c, d, e);
        }
        Error vpcomb(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomb, a, b, c, d);
        }
        Error vpcomb(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomb, a, b, c, d);
        }
        Error vpcomd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomd, a, b, c, d);
        }
        Error vpcomd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomd, a, b, c, d);
        }
        Error vpcompressb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressb, a, b, c);
        }
        Error vpcompressb(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressb, a, b, c);
        }
        Error vpcompressb(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressb, a, b, c);
        }
        Error vpcompressb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressb, a, b, c);
        }
        Error vpcompressb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressb, a, b, c);
        }
        Error vpcompressb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressb, a, b, c);
        }
        Error vpcompressd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressd, a, b, c);
        }
        Error vpcompressd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressd, a, b, c);
        }
        Error vpcompressd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressd, a, b, c);
        }
        Error vpcompressd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressd, a, b, c);
        }
        Error vpcompressd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressd, a, b, c);
        }
        Error vpcompressd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressd, a, b, c);
        }
        Error vpcompressq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressq, a, b, c);
        }
        Error vpcompressq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressq, a, b, c);
        }
        Error vpcompressq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressq, a, b, c);
        }
        Error vpcompressq(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressq, a, b, c);
        }
        Error vpcompressq(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressq, a, b, c);
        }
        Error vpcompressq(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressq, a, b, c);
        }
        Error vpcompressw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressw, a, b, c);
        }
        Error vpcompressw(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressw, a, b, c);
        }
        Error vpcompressw(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressw, a, b, c);
        }
        Error vpcompressw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressw, a, b, c);
        }
        Error vpcompressw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpcompressw, a, b, c);
        }
        Error vpcompressw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpcompressw, a, b, c);
        }
        Error vpcomq(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomq, a, b, c, d);
        }
        Error vpcomq(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomq, a, b, c, d);
        }
        Error vpcomub(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomub, a, b, c, d);
        }
        Error vpcomub(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomub, a, b, c, d);
        }
        Error vpcomud(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomud, a, b, c, d);
        }
        Error vpcomud(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomud, a, b, c, d);
        }
        Error vpcomuq(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomuq, a, b, c, d);
        }
        Error vpcomuq(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomuq, a, b, c, d);
        }
        Error vpcomuw(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomuw, a, b, c, d);
        }
        Error vpcomuw(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomuw, a, b, c, d);
        }
        Error vpcomw(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomw, a, b, c, d);
        }
        Error vpcomw(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpcomw, a, b, c, d);
        }
        Error vpconflictd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpconflictd, a, b, c);
        }
        Error vpconflictd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpconflictd, a, b, c);
        }
        Error vpconflictd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpconflictd, a, b, c);
        }
        Error vpconflictd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpconflictd, a, b, c);
        }
        Error vpconflictd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpconflictd, a, b, c);
        }
        Error vpconflictd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpconflictd, a, b, c);
        }
        Error vpconflictq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpconflictq, a, b, c);
        }
        Error vpconflictq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpconflictq, a, b, c);
        }
        Error vpconflictq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpconflictq, a, b, c);
        }
        Error vpconflictq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpconflictq, a, b, c);
        }
        Error vpconflictq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpconflictq, a, b, c);
        }
        Error vpconflictq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpconflictq, a, b, c);
        }
        Error vpdpbusd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c);
        }
        Error vpdpbusd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c);
        }
        Error vpdpbusd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c);
        }
        Error vpdpbusd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c);
        }
        Error vpdpbusd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c, d);
        }
        Error vpdpbusd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c, d);
        }
        Error vpdpbusd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c, d);
        }
        Error vpdpbusd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c, d);
        }
        Error vpdpbusd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c, d);
        }
        Error vpdpbusd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpbusd, a, b, c, d);
        }
        Error vpdpbusds(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c);
        }
        Error vpdpbusds(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c);
        }
        Error vpdpbusds(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c);
        }
        Error vpdpbusds(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c);
        }
        Error vpdpbusds(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c, d);
        }
        Error vpdpbusds(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c, d);
        }
        Error vpdpbusds(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c, d);
        }
        Error vpdpbusds(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c, d);
        }
        Error vpdpbusds(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c, d);
        }
        Error vpdpbusds(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpbusds, a, b, c, d);
        }
        Error vpdpwssd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c);
        }
        Error vpdpwssd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c);
        }
        Error vpdpwssd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c);
        }
        Error vpdpwssd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c);
        }
        Error vpdpwssd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c, d);
        }
        Error vpdpwssd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c, d);
        }
        Error vpdpwssd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c, d);
        }
        Error vpdpwssd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c, d);
        }
        Error vpdpwssd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c, d);
        }
        Error vpdpwssd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpwssd, a, b, c, d);
        }
        Error vpdpwssds(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c);
        }
        Error vpdpwssds(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c);
        }
        Error vpdpwssds(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c);
        }
        Error vpdpwssds(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c);
        }
        Error vpdpwssds(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c, d);
        }
        Error vpdpwssds(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c, d);
        }
        Error vpdpwssds(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c, d);
        }
        Error vpdpwssds(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c, d);
        }
        Error vpdpwssds(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c, d);
        }
        Error vpdpwssds(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpdpwssds, a, b, c, d);
        }
        Error vperm2f128(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vperm2f128, a, b, c, d);
        }
        Error vperm2f128(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vperm2f128, a, b, c, d);
        }
        Error vperm2i128(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vperm2i128, a, b, c, d);
        }
        Error vperm2i128(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vperm2i128, a, b, c, d);
        }
        Error vpermb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermb, a, b, c, d);
        }
        Error vpermb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermb, a, b, c, d);
        }
        Error vpermb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermb, a, b, c, d);
        }
        Error vpermb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermb, a, b, c, d);
        }
        Error vpermb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermb, a, b, c, d);
        }
        Error vpermb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermb, a, b, c, d);
        }
        Error vpermd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpermd, a, b, c);
        }
        Error vpermd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpermd, a, b, c);
        }
        Error vpermd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermd, a, b, c, d);
        }
        Error vpermd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermd, a, b, c, d);
        }
        Error vpermd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermd, a, b, c, d);
        }
        Error vpermd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermd, a, b, c, d);
        }
        Error vpermf32x4(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermf32x4, a, b, c, d);
        }
        Error vpermf32x4(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermf32x4, a, b, c, d);
        }
        Error vpermi2b(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2b, a, b, c, d);
        }
        Error vpermi2b(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermi2b, a, b, c, d);
        }
        Error vpermi2b(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2b, a, b, c, d);
        }
        Error vpermi2b(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2b, a, b, c, d);
        }
        Error vpermi2b(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2b, a, b, c, d);
        }
        Error vpermi2b(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2b, a, b, c, d);
        }
        Error vpermi2d(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2d, a, b, c, d);
        }
        Error vpermi2d(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermi2d, a, b, c, d);
        }
        Error vpermi2d(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2d, a, b, c, d);
        }
        Error vpermi2d(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2d, a, b, c, d);
        }
        Error vpermi2d(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2d, a, b, c, d);
        }
        Error vpermi2d(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2d, a, b, c, d);
        }
        Error vpermi2pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2pd, a, b, c, d);
        }
        Error vpermi2pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermi2pd, a, b, c, d);
        }
        Error vpermi2pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2pd, a, b, c, d);
        }
        Error vpermi2pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2pd, a, b, c, d);
        }
        Error vpermi2pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2pd, a, b, c, d);
        }
        Error vpermi2pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2pd, a, b, c, d);
        }
        Error vpermi2ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2ps, a, b, c, d);
        }
        Error vpermi2ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermi2ps, a, b, c, d);
        }
        Error vpermi2ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2ps, a, b, c, d);
        }
        Error vpermi2ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2ps, a, b, c, d);
        }
        Error vpermi2ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2ps, a, b, c, d);
        }
        Error vpermi2ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2ps, a, b, c, d);
        }
        Error vpermi2q(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2q, a, b, c, d);
        }
        Error vpermi2q(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermi2q, a, b, c, d);
        }
        Error vpermi2q(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2q, a, b, c, d);
        }
        Error vpermi2q(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2q, a, b, c, d);
        }
        Error vpermi2q(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2q, a, b, c, d);
        }
        Error vpermi2q(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2q, a, b, c, d);
        }
        Error vpermi2w(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2w, a, b, c, d);
        }
        Error vpermi2w(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermi2w, a, b, c, d);
        }
        Error vpermi2w(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermi2w, a, b, c, d);
        }
        Error vpermi2w(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2w, a, b, c, d);
        }
        Error vpermi2w(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2w, a, b, c, d);
        }
        Error vpermi2w(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermi2w, a, b, c, d);
        }
        Error vpermil2pd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2pd, a, b, c, d, e);
        }
        Error vpermil2pd(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2pd, a, b, c, d, e);
        }
        Error vpermil2pd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2pd, a, b, c, d, e);
        }
        Error vpermil2pd(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2pd, a, b, c, d, e);
        }
        Error vpermil2pd(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2pd, a, b, c, d, e);
        }
        Error vpermil2pd(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2pd, a, b, c, d, e);
        }
        Error vpermil2ps(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2ps, a, b, c, d, e);
        }
        Error vpermil2ps(const Ymm& a, const Ymm& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2ps, a, b, c, d, e);
        }
        Error vpermil2ps(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2ps, a, b, c, d, e);
        }
        Error vpermil2ps(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2ps, a, b, c, d, e);
        }
        Error vpermil2ps(const Ymm& a, const Ymm& b, const Mem& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2ps, a, b, c, d, e);
        }
        Error vpermil2ps(const Ymm& a, const Ymm& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpermil2ps, a, b, c, d, e);
        }
        Error vpermilpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        Error vpermilpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        Error vpermilpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        Error vpermilpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        Error vpermilpd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        Error vpermilpd(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        Error vpermilpd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        Error vpermilpd(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c);
        }
        Error vpermilpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        Error vpermilpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        Error vpermilpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        Error vpermilpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        Error vpermilpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        Error vpermilpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        Error vpermilpd(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        Error vpermilpd(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        Error vpermilpd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        Error vpermilpd(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        Error vpermilpd(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        Error vpermilpd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilpd, a, b, c, d);
        }
        Error vpermilps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        Error vpermilps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        Error vpermilps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        Error vpermilps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        Error vpermilps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        Error vpermilps(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        Error vpermilps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        Error vpermilps(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c);
        }
        Error vpermilps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        Error vpermilps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        Error vpermilps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        Error vpermilps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        Error vpermilps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        Error vpermilps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        Error vpermilps(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        Error vpermilps(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        Error vpermilps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        Error vpermilps(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        Error vpermilps(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        Error vpermilps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermilps, a, b, c, d);
        }
        Error vpermpd(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c);
        }
        Error vpermpd(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c);
        }
        Error vpermpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        Error vpermpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        Error vpermpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        Error vpermpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        Error vpermpd(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        Error vpermpd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        Error vpermpd(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        Error vpermpd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermpd, a, b, c, d);
        }
        Error vpermps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpermps, a, b, c);
        }
        Error vpermps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpermps, a, b, c);
        }
        Error vpermps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermps, a, b, c, d);
        }
        Error vpermps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermps, a, b, c, d);
        }
        Error vpermps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermps, a, b, c, d);
        }
        Error vpermps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermps, a, b, c, d);
        }
        Error vpermq(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c);
        }
        Error vpermq(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c);
        }
        Error vpermq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        Error vpermq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        Error vpermq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        Error vpermq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        Error vpermq(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        Error vpermq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        Error vpermq(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        Error vpermq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpermq, a, b, c, d);
        }
        Error vpermt2b(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2b, a, b, c, d);
        }
        Error vpermt2b(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermt2b, a, b, c, d);
        }
        Error vpermt2b(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2b, a, b, c, d);
        }
        Error vpermt2b(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2b, a, b, c, d);
        }
        Error vpermt2b(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2b, a, b, c, d);
        }
        Error vpermt2b(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2b, a, b, c, d);
        }
        Error vpermt2d(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2d, a, b, c, d);
        }
        Error vpermt2d(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermt2d, a, b, c, d);
        }
        Error vpermt2d(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2d, a, b, c, d);
        }
        Error vpermt2d(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2d, a, b, c, d);
        }
        Error vpermt2d(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2d, a, b, c, d);
        }
        Error vpermt2d(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2d, a, b, c, d);
        }
        Error vpermt2pd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2pd, a, b, c, d);
        }
        Error vpermt2pd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermt2pd, a, b, c, d);
        }
        Error vpermt2pd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2pd, a, b, c, d);
        }
        Error vpermt2pd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2pd, a, b, c, d);
        }
        Error vpermt2pd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2pd, a, b, c, d);
        }
        Error vpermt2pd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2pd, a, b, c, d);
        }
        Error vpermt2ps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2ps, a, b, c, d);
        }
        Error vpermt2ps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermt2ps, a, b, c, d);
        }
        Error vpermt2ps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2ps, a, b, c, d);
        }
        Error vpermt2ps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2ps, a, b, c, d);
        }
        Error vpermt2ps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2ps, a, b, c, d);
        }
        Error vpermt2ps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2ps, a, b, c, d);
        }
        Error vpermt2q(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2q, a, b, c, d);
        }
        Error vpermt2q(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermt2q, a, b, c, d);
        }
        Error vpermt2q(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2q, a, b, c, d);
        }
        Error vpermt2q(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2q, a, b, c, d);
        }
        Error vpermt2q(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2q, a, b, c, d);
        }
        Error vpermt2q(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2q, a, b, c, d);
        }
        Error vpermt2w(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2w, a, b, c, d);
        }
        Error vpermt2w(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermt2w, a, b, c, d);
        }
        Error vpermt2w(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermt2w, a, b, c, d);
        }
        Error vpermt2w(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2w, a, b, c, d);
        }
        Error vpermt2w(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2w, a, b, c, d);
        }
        Error vpermt2w(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermt2w, a, b, c, d);
        }
        Error vpermw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpermw, a, b, c, d);
        }
        Error vpermw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpermw, a, b, c, d);
        }
        Error vpermw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpermw, a, b, c, d);
        }
        Error vpermw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermw, a, b, c, d);
        }
        Error vpermw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermw, a, b, c, d);
        }
        Error vpermw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpermw, a, b, c, d);
        }
        Error vpexpandb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandb, a, b, c);
        }
        Error vpexpandb(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpexpandb, a, b, c);
        }
        Error vpexpandb(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandb, a, b, c);
        }
        Error vpexpandb(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandb, a, b, c);
        }
        Error vpexpandb(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandb, a, b, c);
        }
        Error vpexpandb(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandb, a, b, c);
        }
        Error vpexpandd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandd, a, b, c);
        }
        Error vpexpandd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpexpandd, a, b, c);
        }
        Error vpexpandd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandd, a, b, c);
        }
        Error vpexpandd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandd, a, b, c);
        }
        Error vpexpandd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandd, a, b, c);
        }
        Error vpexpandd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandd, a, b, c);
        }
        Error vpexpandq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandq, a, b, c);
        }
        Error vpexpandq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpexpandq, a, b, c);
        }
        Error vpexpandq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandq, a, b, c);
        }
        Error vpexpandq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandq, a, b, c);
        }
        Error vpexpandq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandq, a, b, c);
        }
        Error vpexpandq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandq, a, b, c);
        }
        Error vpexpandw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandw, a, b, c);
        }
        Error vpexpandw(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpexpandw, a, b, c);
        }
        Error vpexpandw(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpexpandw, a, b, c);
        }
        Error vpexpandw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandw, a, b, c);
        }
        Error vpexpandw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandw, a, b, c);
        }
        Error vpexpandw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpexpandw, a, b, c);
        }
        Error vpextrb(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrb, a, b, c);
        }
        Error vpextrb(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrb, a, b, c);
        }
        Error vpextrd(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrd, a, b, c);
        }
        Error vpextrd(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrd, a, b, c);
        }
        Error vpextrq(const Gp64& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrq, a, b, c);
        }
        Error vpextrq(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrq, a, b, c);
        }
        Error vpextrw(const Gp32& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrw, a, b, c);
        }
        Error vpextrw(const Mem& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpextrw, a, b, c);
        }
        Error vpgatherdd(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpgatherdd, a, b, c);
        }
        Error vpgatherdd(const Ymm& a, const Mem& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpgatherdd, a, b, c);
        }
        Error vpgatherdd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherdd, a, b, c);
        }
        Error vpgatherdd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherdd, a, b, c);
        }
        Error vpgatherdd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherdd, a, b, c);
        }
        Error vpgatherdq(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpgatherdq, a, b, c);
        }
        Error vpgatherdq(const Ymm& a, const Mem& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpgatherdq, a, b, c);
        }
        Error vpgatherdq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherdq, a, b, c);
        }
        Error vpgatherdq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherdq, a, b, c);
        }
        Error vpgatherdq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherdq, a, b, c);
        }
        Error vpgatherqd(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpgatherqd, a, b, c);
        }
        Error vpgatherqd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherqd, a, b, c);
        }
        Error vpgatherqd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherqd, a, b, c);
        }
        Error vpgatherqq(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpgatherqq, a, b, c);
        }
        Error vpgatherqq(const Ymm& a, const Mem& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpgatherqq, a, b, c);
        }
        Error vpgatherqq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherqq, a, b, c);
        }
        Error vpgatherqq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherqq, a, b, c);
        }
        Error vpgatherqq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpgatherqq, a, b, c);
        }
        Error vphaddbd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddbd, a, b);
        }
        Error vphaddbd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddbd, a, b);
        }
        Error vphaddbq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddbq, a, b);
        }
        Error vphaddbq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddbq, a, b);
        }
        Error vphaddbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddbw, a, b);
        }
        Error vphaddbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddbw, a, b);
        }
        Error vphaddd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vphaddd, a, b, c);
        }
        Error vphaddd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vphaddd, a, b, c);
        }
        Error vphaddd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphaddd, a, b, c);
        }
        Error vphaddd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphaddd, a, b, c);
        }
        Error vphadddq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphadddq, a, b);
        }
        Error vphadddq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphadddq, a, b);
        }
        Error vphaddsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vphaddsw, a, b, c);
        }
        Error vphaddsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vphaddsw, a, b, c);
        }
        Error vphaddsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphaddsw, a, b, c);
        }
        Error vphaddsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphaddsw, a, b, c);
        }
        Error vphaddubd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddubd, a, b);
        }
        Error vphaddubd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddubd, a, b);
        }
        Error vphaddubq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddubq, a, b);
        }
        Error vphaddubq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddubq, a, b);
        }
        Error vphaddubw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddubw, a, b);
        }
        Error vphaddubw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddubw, a, b);
        }
        Error vphaddudq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddudq, a, b);
        }
        Error vphaddudq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddudq, a, b);
        }
        Error vphadduwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphadduwd, a, b);
        }
        Error vphadduwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphadduwd, a, b);
        }
        Error vphadduwq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphadduwq, a, b);
        }
        Error vphadduwq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphadduwq, a, b);
        }
        Error vphaddw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vphaddw, a, b, c);
        }
        Error vphaddw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vphaddw, a, b, c);
        }
        Error vphaddw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphaddw, a, b, c);
        }
        Error vphaddw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphaddw, a, b, c);
        }
        Error vphaddwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddwd, a, b);
        }
        Error vphaddwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddwd, a, b);
        }
        Error vphaddwq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphaddwq, a, b);
        }
        Error vphaddwq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphaddwq, a, b);
        }
        Error vphminposuw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphminposuw, a, b);
        }
        Error vphminposuw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphminposuw, a, b);
        }
        Error vphsubbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphsubbw, a, b);
        }
        Error vphsubbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphsubbw, a, b);
        }
        Error vphsubd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vphsubd, a, b, c);
        }
        Error vphsubd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vphsubd, a, b, c);
        }
        Error vphsubd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphsubd, a, b, c);
        }
        Error vphsubd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphsubd, a, b, c);
        }
        Error vphsubdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphsubdq, a, b);
        }
        Error vphsubdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphsubdq, a, b);
        }
        Error vphsubsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vphsubsw, a, b, c);
        }
        Error vphsubsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vphsubsw, a, b, c);
        }
        Error vphsubsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphsubsw, a, b, c);
        }
        Error vphsubsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphsubsw, a, b, c);
        }
        Error vphsubw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vphsubw, a, b, c);
        }
        Error vphsubw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vphsubw, a, b, c);
        }
        Error vphsubw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphsubw, a, b, c);
        }
        Error vphsubw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vphsubw, a, b, c);
        }
        Error vphsubwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vphsubwd, a, b);
        }
        Error vphsubwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vphsubwd, a, b);
        }
        Error vpinsrb(const Xmm& a, const Xmm& b, const Gp32& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrb, a, b, c, d);
        }
        Error vpinsrb(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrb, a, b, c, d);
        }
        Error vpinsrd(const Xmm& a, const Xmm& b, const Gp32& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrd, a, b, c, d);
        }
        Error vpinsrd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrd, a, b, c, d);
        }
        Error vpinsrq(const Xmm& a, const Xmm& b, const Gp64& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrq, a, b, c, d);
        }
        Error vpinsrq(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrq, a, b, c, d);
        }
        Error vpinsrw(const Xmm& a, const Xmm& b, const Gp32& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrw, a, b, c, d);
        }
        Error vpinsrw(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpinsrw, a, b, c, d);
        }
        Error vplzcntd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vplzcntd, a, b, c);
        }
        Error vplzcntd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vplzcntd, a, b, c);
        }
        Error vplzcntd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vplzcntd, a, b, c);
        }
        Error vplzcntd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vplzcntd, a, b, c);
        }
        Error vplzcntd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vplzcntd, a, b, c);
        }
        Error vplzcntd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vplzcntd, a, b, c);
        }
        Error vplzcntq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vplzcntq, a, b, c);
        }
        Error vplzcntq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vplzcntq, a, b, c);
        }
        Error vplzcntq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vplzcntq, a, b, c);
        }
        Error vplzcntq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vplzcntq, a, b, c);
        }
        Error vplzcntq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vplzcntq, a, b, c);
        }
        Error vplzcntq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vplzcntq, a, b, c);
        }
        Error vpmacsdd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsdd, a, b, c, d);
        }
        Error vpmacsdd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsdd, a, b, c, d);
        }
        Error vpmacsdqh(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsdqh, a, b, c, d);
        }
        Error vpmacsdqh(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsdqh, a, b, c, d);
        }
        Error vpmacsdql(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsdql, a, b, c, d);
        }
        Error vpmacsdql(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsdql, a, b, c, d);
        }
        Error vpmacssdd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssdd, a, b, c, d);
        }
        Error vpmacssdd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssdd, a, b, c, d);
        }
        Error vpmacssdqh(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssdqh, a, b, c, d);
        }
        Error vpmacssdqh(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssdqh, a, b, c, d);
        }
        Error vpmacssdql(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssdql, a, b, c, d);
        }
        Error vpmacssdql(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssdql, a, b, c, d);
        }
        Error vpmacsswd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsswd, a, b, c, d);
        }
        Error vpmacsswd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsswd, a, b, c, d);
        }
        Error vpmacssww(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssww, a, b, c, d);
        }
        Error vpmacssww(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacssww, a, b, c, d);
        }
        Error vpmacswd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacswd, a, b, c, d);
        }
        Error vpmacswd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacswd, a, b, c, d);
        }
        Error vpmacsww(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsww, a, b, c, d);
        }
        Error vpmacsww(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmacsww, a, b, c, d);
        }
        Error vpmadcsswd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmadcsswd, a, b, c, d);
        }
        Error vpmadcsswd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmadcsswd, a, b, c, d);
        }
        Error vpmadcswd(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmadcswd, a, b, c, d);
        }
        Error vpmadcswd(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmadcswd, a, b, c, d);
        }
        Error vpmadd231d(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmadd231d, a, b, c, d);
        }
        Error vpmadd231d(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd231d, a, b, c, d);
        }
        Error vpmadd233d(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmadd233d, a, b, c, d);
        }
        Error vpmadd233d(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd233d, a, b, c, d);
        }
        Error vpmadd52huq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmadd52huq, a, b, c, d);
        }
        Error vpmadd52huq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmadd52huq, a, b, c, d);
        }
        Error vpmadd52huq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmadd52huq, a, b, c, d);
        }
        Error vpmadd52huq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd52huq, a, b, c, d);
        }
        Error vpmadd52huq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd52huq, a, b, c, d);
        }
        Error vpmadd52huq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd52huq, a, b, c, d);
        }
        Error vpmadd52luq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmadd52luq, a, b, c, d);
        }
        Error vpmadd52luq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmadd52luq, a, b, c, d);
        }
        Error vpmadd52luq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmadd52luq, a, b, c, d);
        }
        Error vpmadd52luq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd52luq, a, b, c, d);
        }
        Error vpmadd52luq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd52luq, a, b, c, d);
        }
        Error vpmadd52luq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmadd52luq, a, b, c, d);
        }
        Error vpmaddubsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c);
        }
        Error vpmaddubsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c);
        }
        Error vpmaddubsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c);
        }
        Error vpmaddubsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c);
        }
        Error vpmaddubsw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c, d);
        }
        Error vpmaddubsw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c, d);
        }
        Error vpmaddubsw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c, d);
        }
        Error vpmaddubsw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c, d);
        }
        Error vpmaddubsw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c, d);
        }
        Error vpmaddubsw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaddubsw, a, b, c, d);
        }
        Error vpmaddwd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c);
        }
        Error vpmaddwd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c);
        }
        Error vpmaddwd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c);
        }
        Error vpmaddwd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c);
        }
        Error vpmaddwd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c, d);
        }
        Error vpmaddwd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c, d);
        }
        Error vpmaddwd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c, d);
        }
        Error vpmaddwd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c, d);
        }
        Error vpmaddwd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c, d);
        }
        Error vpmaddwd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaddwd, a, b, c, d);
        }
        Error vpmaskmovd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovd, a, b, c);
        }
        Error vpmaskmovd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovd, a, b, c);
        }
        Error vpmaskmovd(const Mem& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovd, a, b, c);
        }
        Error vpmaskmovd(const Mem& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovd, a, b, c);
        }
        Error vpmaskmovq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovq, a, b, c);
        }
        Error vpmaskmovq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovq, a, b, c);
        }
        Error vpmaskmovq(const Mem& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovq, a, b, c);
        }
        Error vpmaskmovq(const Mem& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaskmovq, a, b, c);
        }
        Error vpmaxsb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c);
        }
        Error vpmaxsb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c);
        }
        Error vpmaxsb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c);
        }
        Error vpmaxsb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c);
        }
        Error vpmaxsb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c, d);
        }
        Error vpmaxsb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c, d);
        }
        Error vpmaxsb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c, d);
        }
        Error vpmaxsb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c, d);
        }
        Error vpmaxsb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c, d);
        }
        Error vpmaxsb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsb, a, b, c, d);
        }
        Error vpmaxsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c);
        }
        Error vpmaxsd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c);
        }
        Error vpmaxsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c);
        }
        Error vpmaxsd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c);
        }
        Error vpmaxsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c, d);
        }
        Error vpmaxsd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c, d);
        }
        Error vpmaxsd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c, d);
        }
        Error vpmaxsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c, d);
        }
        Error vpmaxsd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c, d);
        }
        Error vpmaxsd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsd, a, b, c, d);
        }
        Error vpmaxsq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsq, a, b, c, d);
        }
        Error vpmaxsq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsq, a, b, c, d);
        }
        Error vpmaxsq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsq, a, b, c, d);
        }
        Error vpmaxsq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsq, a, b, c, d);
        }
        Error vpmaxsq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsq, a, b, c, d);
        }
        Error vpmaxsq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsq, a, b, c, d);
        }
        Error vpmaxsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c);
        }
        Error vpmaxsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c);
        }
        Error vpmaxsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c);
        }
        Error vpmaxsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c);
        }
        Error vpmaxsw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c, d);
        }
        Error vpmaxsw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c, d);
        }
        Error vpmaxsw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c, d);
        }
        Error vpmaxsw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c, d);
        }
        Error vpmaxsw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c, d);
        }
        Error vpmaxsw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxsw, a, b, c, d);
        }
        Error vpmaxub(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c);
        }
        Error vpmaxub(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c);
        }
        Error vpmaxub(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c);
        }
        Error vpmaxub(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c);
        }
        Error vpmaxub(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c, d);
        }
        Error vpmaxub(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c, d);
        }
        Error vpmaxub(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c, d);
        }
        Error vpmaxub(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c, d);
        }
        Error vpmaxub(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c, d);
        }
        Error vpmaxub(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxub, a, b, c, d);
        }
        Error vpmaxud(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c);
        }
        Error vpmaxud(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c);
        }
        Error vpmaxud(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c);
        }
        Error vpmaxud(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c);
        }
        Error vpmaxud(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c, d);
        }
        Error vpmaxud(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c, d);
        }
        Error vpmaxud(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c, d);
        }
        Error vpmaxud(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c, d);
        }
        Error vpmaxud(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c, d);
        }
        Error vpmaxud(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxud, a, b, c, d);
        }
        Error vpmaxuq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxuq, a, b, c, d);
        }
        Error vpmaxuq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxuq, a, b, c, d);
        }
        Error vpmaxuq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxuq, a, b, c, d);
        }
        Error vpmaxuq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxuq, a, b, c, d);
        }
        Error vpmaxuq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxuq, a, b, c, d);
        }
        Error vpmaxuq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxuq, a, b, c, d);
        }
        Error vpmaxuw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c);
        }
        Error vpmaxuw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c);
        }
        Error vpmaxuw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c);
        }
        Error vpmaxuw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c);
        }
        Error vpmaxuw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c, d);
        }
        Error vpmaxuw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c, d);
        }
        Error vpmaxuw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c, d);
        }
        Error vpmaxuw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c, d);
        }
        Error vpmaxuw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c, d);
        }
        Error vpmaxuw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmaxuw, a, b, c, d);
        }
        Error vpminsb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c);
        }
        Error vpminsb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c);
        }
        Error vpminsb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c);
        }
        Error vpminsb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c);
        }
        Error vpminsb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c, d);
        }
        Error vpminsb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c, d);
        }
        Error vpminsb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c, d);
        }
        Error vpminsb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c, d);
        }
        Error vpminsb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c, d);
        }
        Error vpminsb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsb, a, b, c, d);
        }
        Error vpminsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c);
        }
        Error vpminsd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c);
        }
        Error vpminsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c);
        }
        Error vpminsd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c);
        }
        Error vpminsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c, d);
        }
        Error vpminsd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c, d);
        }
        Error vpminsd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c, d);
        }
        Error vpminsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c, d);
        }
        Error vpminsd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c, d);
        }
        Error vpminsd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsd, a, b, c, d);
        }
        Error vpminsq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminsq, a, b, c, d);
        }
        Error vpminsq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminsq, a, b, c, d);
        }
        Error vpminsq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminsq, a, b, c, d);
        }
        Error vpminsq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsq, a, b, c, d);
        }
        Error vpminsq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsq, a, b, c, d);
        }
        Error vpminsq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsq, a, b, c, d);
        }
        Error vpminsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c);
        }
        Error vpminsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c);
        }
        Error vpminsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c);
        }
        Error vpminsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c);
        }
        Error vpminsw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c, d);
        }
        Error vpminsw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c, d);
        }
        Error vpminsw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c, d);
        }
        Error vpminsw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c, d);
        }
        Error vpminsw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c, d);
        }
        Error vpminsw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminsw, a, b, c, d);
        }
        Error vpminub(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c);
        }
        Error vpminub(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c);
        }
        Error vpminub(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c);
        }
        Error vpminub(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c);
        }
        Error vpminub(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c, d);
        }
        Error vpminub(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c, d);
        }
        Error vpminub(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c, d);
        }
        Error vpminub(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c, d);
        }
        Error vpminub(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c, d);
        }
        Error vpminub(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminub, a, b, c, d);
        }
        Error vpminud(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c);
        }
        Error vpminud(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c);
        }
        Error vpminud(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c);
        }
        Error vpminud(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c);
        }
        Error vpminud(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c, d);
        }
        Error vpminud(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c, d);
        }
        Error vpminud(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c, d);
        }
        Error vpminud(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c, d);
        }
        Error vpminud(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c, d);
        }
        Error vpminud(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminud, a, b, c, d);
        }
        Error vpminuq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminuq, a, b, c, d);
        }
        Error vpminuq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminuq, a, b, c, d);
        }
        Error vpminuq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminuq, a, b, c, d);
        }
        Error vpminuq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminuq, a, b, c, d);
        }
        Error vpminuq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminuq, a, b, c, d);
        }
        Error vpminuq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminuq, a, b, c, d);
        }
        Error vpminuw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c);
        }
        Error vpminuw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c);
        }
        Error vpminuw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c);
        }
        Error vpminuw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c);
        }
        Error vpminuw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c, d);
        }
        Error vpminuw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c, d);
        }
        Error vpminuw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c, d);
        }
        Error vpminuw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c, d);
        }
        Error vpminuw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c, d);
        }
        Error vpminuw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpminuw, a, b, c, d);
        }
        Error vpmovb2m(const Mask& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovb2m, a, b);
        }
        Error vpmovb2m(const Mask& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpmovb2m, a, b);
        }
        Error vpmovb2m(const Mask& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vpmovb2m, a, b);
        }
        Error vpmovd2m(const Mask& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovd2m, a, b);
        }
        Error vpmovd2m(const Mask& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpmovd2m, a, b);
        }
        Error vpmovd2m(const Mask& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vpmovd2m, a, b);
        }
        Error vpmovdb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdb, a, b, c);
        }
        Error vpmovdb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovdb, a, b, c);
        }
        Error vpmovdb(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdb, a, b, c);
        }
        Error vpmovdb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdb, a, b, c);
        }
        Error vpmovdb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovdb, a, b, c);
        }
        Error vpmovdb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdb, a, b, c);
        }
        Error vpmovdw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdw, a, b, c);
        }
        Error vpmovdw(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovdw, a, b, c);
        }
        Error vpmovdw(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdw, a, b, c);
        }
        Error vpmovdw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdw, a, b, c);
        }
        Error vpmovdw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovdw, a, b, c);
        }
        Error vpmovdw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovdw, a, b, c);
        }
        Error vpmovm2b(const Xmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2b, a, b);
        }
        Error vpmovm2b(const Ymm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2b, a, b);
        }
        Error vpmovm2b(const Zmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2b, a, b);
        }
        Error vpmovm2d(const Xmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2d, a, b);
        }
        Error vpmovm2d(const Ymm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2d, a, b);
        }
        Error vpmovm2d(const Zmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2d, a, b);
        }
        Error vpmovm2q(const Xmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2q, a, b);
        }
        Error vpmovm2q(const Ymm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2q, a, b);
        }
        Error vpmovm2q(const Zmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2q, a, b);
        }
        Error vpmovm2w(const Xmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2w, a, b);
        }
        Error vpmovm2w(const Ymm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2w, a, b);
        }
        Error vpmovm2w(const Zmm& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vpmovm2w, a, b);
        }
        Error vpmovmskb(const Gp32& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovmskb, a, b);
        }
        Error vpmovmskb(const Gp32& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpmovmskb, a, b);
        }
        Error vpmovq2m(const Mask& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovq2m, a, b);
        }
        Error vpmovq2m(const Mask& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpmovq2m, a, b);
        }
        Error vpmovq2m(const Mask& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vpmovq2m, a, b);
        }
        Error vpmovqb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqb, a, b, c);
        }
        Error vpmovqb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovqb, a, b, c);
        }
        Error vpmovqb(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqb, a, b, c);
        }
        Error vpmovqb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqb, a, b, c);
        }
        Error vpmovqb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovqb, a, b, c);
        }
        Error vpmovqb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqb, a, b, c);
        }
        Error vpmovqd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqd, a, b, c);
        }
        Error vpmovqd(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovqd, a, b, c);
        }
        Error vpmovqd(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqd, a, b, c);
        }
        Error vpmovqd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqd, a, b, c);
        }
        Error vpmovqd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovqd, a, b, c);
        }
        Error vpmovqd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqd, a, b, c);
        }
        Error vpmovqw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqw, a, b, c);
        }
        Error vpmovqw(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovqw, a, b, c);
        }
        Error vpmovqw(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqw, a, b, c);
        }
        Error vpmovqw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqw, a, b, c);
        }
        Error vpmovqw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovqw, a, b, c);
        }
        Error vpmovqw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovqw, a, b, c);
        }
        Error vpmovsdb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdb, a, b, c);
        }
        Error vpmovsdb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdb, a, b, c);
        }
        Error vpmovsdb(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdb, a, b, c);
        }
        Error vpmovsdb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdb, a, b, c);
        }
        Error vpmovsdb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdb, a, b, c);
        }
        Error vpmovsdb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdb, a, b, c);
        }
        Error vpmovsdw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdw, a, b, c);
        }
        Error vpmovsdw(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdw, a, b, c);
        }
        Error vpmovsdw(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdw, a, b, c);
        }
        Error vpmovsdw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdw, a, b, c);
        }
        Error vpmovsdw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdw, a, b, c);
        }
        Error vpmovsdw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsdw, a, b, c);
        }
        Error vpmovsqb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqb, a, b, c);
        }
        Error vpmovsqb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqb, a, b, c);
        }
        Error vpmovsqb(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqb, a, b, c);
        }
        Error vpmovsqb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqb, a, b, c);
        }
        Error vpmovsqb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqb, a, b, c);
        }
        Error vpmovsqb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqb, a, b, c);
        }
        Error vpmovsqd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqd, a, b, c);
        }
        Error vpmovsqd(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqd, a, b, c);
        }
        Error vpmovsqd(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqd, a, b, c);
        }
        Error vpmovsqd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqd, a, b, c);
        }
        Error vpmovsqd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqd, a, b, c);
        }
        Error vpmovsqd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqd, a, b, c);
        }
        Error vpmovsqw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqw, a, b, c);
        }
        Error vpmovsqw(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqw, a, b, c);
        }
        Error vpmovsqw(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqw, a, b, c);
        }
        Error vpmovsqw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqw, a, b, c);
        }
        Error vpmovsqw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqw, a, b, c);
        }
        Error vpmovsqw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsqw, a, b, c);
        }
        Error vpmovswb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovswb, a, b, c);
        }
        Error vpmovswb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovswb, a, b, c);
        }
        Error vpmovswb(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovswb, a, b, c);
        }
        Error vpmovswb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovswb, a, b, c);
        }
        Error vpmovswb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovswb, a, b, c);
        }
        Error vpmovswb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovswb, a, b, c);
        }
        Error vpmovsxbd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b);
        }
        Error vpmovsxbd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b);
        }
        Error vpmovsxbd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b);
        }
        Error vpmovsxbd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b);
        }
        Error vpmovsxbd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b, c);
        }
        Error vpmovsxbd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b, c);
        }
        Error vpmovsxbd(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b, c);
        }
        Error vpmovsxbd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b, c);
        }
        Error vpmovsxbd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b, c);
        }
        Error vpmovsxbd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbd, a, b, c);
        }
        Error vpmovsxbq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b);
        }
        Error vpmovsxbq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b);
        }
        Error vpmovsxbq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b);
        }
        Error vpmovsxbq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b);
        }
        Error vpmovsxbq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b, c);
        }
        Error vpmovsxbq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b, c);
        }
        Error vpmovsxbq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b, c);
        }
        Error vpmovsxbq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b, c);
        }
        Error vpmovsxbq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b, c);
        }
        Error vpmovsxbq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbq, a, b, c);
        }
        Error vpmovsxbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b);
        }
        Error vpmovsxbw(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b);
        }
        Error vpmovsxbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b);
        }
        Error vpmovsxbw(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b);
        }
        Error vpmovsxbw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b, c);
        }
        Error vpmovsxbw(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b, c);
        }
        Error vpmovsxbw(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b, c);
        }
        Error vpmovsxbw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b, c);
        }
        Error vpmovsxbw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b, c);
        }
        Error vpmovsxbw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxbw, a, b, c);
        }
        Error vpmovsxdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b);
        }
        Error vpmovsxdq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b);
        }
        Error vpmovsxdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b);
        }
        Error vpmovsxdq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b);
        }
        Error vpmovsxdq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b, c);
        }
        Error vpmovsxdq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b, c);
        }
        Error vpmovsxdq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b, c);
        }
        Error vpmovsxdq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b, c);
        }
        Error vpmovsxdq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b, c);
        }
        Error vpmovsxdq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxdq, a, b, c);
        }
        Error vpmovsxwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b);
        }
        Error vpmovsxwd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b);
        }
        Error vpmovsxwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b);
        }
        Error vpmovsxwd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b);
        }
        Error vpmovsxwd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b, c);
        }
        Error vpmovsxwd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b, c);
        }
        Error vpmovsxwd(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b, c);
        }
        Error vpmovsxwd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b, c);
        }
        Error vpmovsxwd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b, c);
        }
        Error vpmovsxwd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwd, a, b, c);
        }
        Error vpmovsxwq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b);
        }
        Error vpmovsxwq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b);
        }
        Error vpmovsxwq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b);
        }
        Error vpmovsxwq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b);
        }
        Error vpmovsxwq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b, c);
        }
        Error vpmovsxwq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b, c);
        }
        Error vpmovsxwq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b, c);
        }
        Error vpmovsxwq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b, c);
        }
        Error vpmovsxwq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b, c);
        }
        Error vpmovsxwq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovsxwq, a, b, c);
        }
        Error vpmovusdb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdb, a, b, c);
        }
        Error vpmovusdb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdb, a, b, c);
        }
        Error vpmovusdb(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdb, a, b, c);
        }
        Error vpmovusdb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdb, a, b, c);
        }
        Error vpmovusdb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdb, a, b, c);
        }
        Error vpmovusdb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdb, a, b, c);
        }
        Error vpmovusdw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdw, a, b, c);
        }
        Error vpmovusdw(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdw, a, b, c);
        }
        Error vpmovusdw(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdw, a, b, c);
        }
        Error vpmovusdw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdw, a, b, c);
        }
        Error vpmovusdw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdw, a, b, c);
        }
        Error vpmovusdw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusdw, a, b, c);
        }
        Error vpmovusqb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqb, a, b, c);
        }
        Error vpmovusqb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqb, a, b, c);
        }
        Error vpmovusqb(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqb, a, b, c);
        }
        Error vpmovusqb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqb, a, b, c);
        }
        Error vpmovusqb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqb, a, b, c);
        }
        Error vpmovusqb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqb, a, b, c);
        }
        Error vpmovusqd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqd, a, b, c);
        }
        Error vpmovusqd(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqd, a, b, c);
        }
        Error vpmovusqd(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqd, a, b, c);
        }
        Error vpmovusqd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqd, a, b, c);
        }
        Error vpmovusqd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqd, a, b, c);
        }
        Error vpmovusqd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqd, a, b, c);
        }
        Error vpmovusqw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqw, a, b, c);
        }
        Error vpmovusqw(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqw, a, b, c);
        }
        Error vpmovusqw(const Xmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqw, a, b, c);
        }
        Error vpmovusqw(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqw, a, b, c);
        }
        Error vpmovusqw(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqw, a, b, c);
        }
        Error vpmovusqw(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovusqw, a, b, c);
        }
        Error vpmovuswb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovuswb, a, b, c);
        }
        Error vpmovuswb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovuswb, a, b, c);
        }
        Error vpmovuswb(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovuswb, a, b, c);
        }
        Error vpmovuswb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovuswb, a, b, c);
        }
        Error vpmovuswb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovuswb, a, b, c);
        }
        Error vpmovuswb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovuswb, a, b, c);
        }
        Error vpmovw2m(const Mask& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovw2m, a, b);
        }
        Error vpmovw2m(const Mask& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vpmovw2m, a, b);
        }
        Error vpmovw2m(const Mask& a, const Zmm& b)
        {
            return emit(x86::Mnemonic::Vpmovw2m, a, b);
        }
        Error vpmovwb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovwb, a, b, c);
        }
        Error vpmovwb(const Xmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovwb, a, b, c);
        }
        Error vpmovwb(const Ymm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovwb, a, b, c);
        }
        Error vpmovwb(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovwb, a, b, c);
        }
        Error vpmovwb(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovwb, a, b, c);
        }
        Error vpmovwb(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpmovwb, a, b, c);
        }
        Error vpmovzxbd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b);
        }
        Error vpmovzxbd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b);
        }
        Error vpmovzxbd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b);
        }
        Error vpmovzxbd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b);
        }
        Error vpmovzxbd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b, c);
        }
        Error vpmovzxbd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b, c);
        }
        Error vpmovzxbd(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b, c);
        }
        Error vpmovzxbd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b, c);
        }
        Error vpmovzxbd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b, c);
        }
        Error vpmovzxbd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbd, a, b, c);
        }
        Error vpmovzxbq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b);
        }
        Error vpmovzxbq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b);
        }
        Error vpmovzxbq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b);
        }
        Error vpmovzxbq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b);
        }
        Error vpmovzxbq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b, c);
        }
        Error vpmovzxbq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b, c);
        }
        Error vpmovzxbq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b, c);
        }
        Error vpmovzxbq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b, c);
        }
        Error vpmovzxbq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b, c);
        }
        Error vpmovzxbq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbq, a, b, c);
        }
        Error vpmovzxbw(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b);
        }
        Error vpmovzxbw(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b);
        }
        Error vpmovzxbw(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b);
        }
        Error vpmovzxbw(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b);
        }
        Error vpmovzxbw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b, c);
        }
        Error vpmovzxbw(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b, c);
        }
        Error vpmovzxbw(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b, c);
        }
        Error vpmovzxbw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b, c);
        }
        Error vpmovzxbw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b, c);
        }
        Error vpmovzxbw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxbw, a, b, c);
        }
        Error vpmovzxdq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b);
        }
        Error vpmovzxdq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b);
        }
        Error vpmovzxdq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b);
        }
        Error vpmovzxdq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b);
        }
        Error vpmovzxdq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b, c);
        }
        Error vpmovzxdq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b, c);
        }
        Error vpmovzxdq(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b, c);
        }
        Error vpmovzxdq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b, c);
        }
        Error vpmovzxdq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b, c);
        }
        Error vpmovzxdq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxdq, a, b, c);
        }
        Error vpmovzxwd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b);
        }
        Error vpmovzxwd(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b);
        }
        Error vpmovzxwd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b);
        }
        Error vpmovzxwd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b);
        }
        Error vpmovzxwd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b, c);
        }
        Error vpmovzxwd(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b, c);
        }
        Error vpmovzxwd(const Zmm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b, c);
        }
        Error vpmovzxwd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b, c);
        }
        Error vpmovzxwd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b, c);
        }
        Error vpmovzxwd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwd, a, b, c);
        }
        Error vpmovzxwq(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b);
        }
        Error vpmovzxwq(const Ymm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b);
        }
        Error vpmovzxwq(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b);
        }
        Error vpmovzxwq(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b);
        }
        Error vpmovzxwq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b, c);
        }
        Error vpmovzxwq(const Ymm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b, c);
        }
        Error vpmovzxwq(const Zmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b, c);
        }
        Error vpmovzxwq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b, c);
        }
        Error vpmovzxwq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b, c);
        }
        Error vpmovzxwq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmovzxwq, a, b, c);
        }
        Error vpmuldq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c);
        }
        Error vpmuldq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c);
        }
        Error vpmuldq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c);
        }
        Error vpmuldq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c);
        }
        Error vpmuldq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c, d);
        }
        Error vpmuldq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c, d);
        }
        Error vpmuldq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c, d);
        }
        Error vpmuldq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c, d);
        }
        Error vpmuldq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c, d);
        }
        Error vpmuldq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmuldq, a, b, c, d);
        }
        Error vpmulhd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhd, a, b, c, d);
        }
        Error vpmulhd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhd, a, b, c, d);
        }
        Error vpmulhrsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c);
        }
        Error vpmulhrsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c);
        }
        Error vpmulhrsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c);
        }
        Error vpmulhrsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c);
        }
        Error vpmulhrsw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c, d);
        }
        Error vpmulhrsw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c, d);
        }
        Error vpmulhrsw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c, d);
        }
        Error vpmulhrsw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c, d);
        }
        Error vpmulhrsw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c, d);
        }
        Error vpmulhrsw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhrsw, a, b, c, d);
        }
        Error vpmulhud(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhud, a, b, c, d);
        }
        Error vpmulhud(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhud, a, b, c, d);
        }
        Error vpmulhuw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c);
        }
        Error vpmulhuw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c);
        }
        Error vpmulhuw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c);
        }
        Error vpmulhuw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c);
        }
        Error vpmulhuw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c, d);
        }
        Error vpmulhuw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c, d);
        }
        Error vpmulhuw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c, d);
        }
        Error vpmulhuw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c, d);
        }
        Error vpmulhuw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c, d);
        }
        Error vpmulhuw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhuw, a, b, c, d);
        }
        Error vpmulhw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c);
        }
        Error vpmulhw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c);
        }
        Error vpmulhw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c);
        }
        Error vpmulhw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c);
        }
        Error vpmulhw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c, d);
        }
        Error vpmulhw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c, d);
        }
        Error vpmulhw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c, d);
        }
        Error vpmulhw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c, d);
        }
        Error vpmulhw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c, d);
        }
        Error vpmulhw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulhw, a, b, c, d);
        }
        Error vpmulld(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c);
        }
        Error vpmulld(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c);
        }
        Error vpmulld(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c);
        }
        Error vpmulld(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c);
        }
        Error vpmulld(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c, d);
        }
        Error vpmulld(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c, d);
        }
        Error vpmulld(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c, d);
        }
        Error vpmulld(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c, d);
        }
        Error vpmulld(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c, d);
        }
        Error vpmulld(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmulld, a, b, c, d);
        }
        Error vpmullq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmullq, a, b, c, d);
        }
        Error vpmullq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmullq, a, b, c, d);
        }
        Error vpmullq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmullq, a, b, c, d);
        }
        Error vpmullq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmullq, a, b, c, d);
        }
        Error vpmullq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmullq, a, b, c, d);
        }
        Error vpmullq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmullq, a, b, c, d);
        }
        Error vpmullw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c);
        }
        Error vpmullw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c);
        }
        Error vpmullw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c);
        }
        Error vpmullw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c);
        }
        Error vpmullw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c, d);
        }
        Error vpmullw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c, d);
        }
        Error vpmullw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c, d);
        }
        Error vpmullw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c, d);
        }
        Error vpmullw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c, d);
        }
        Error vpmullw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmullw, a, b, c, d);
        }
        Error vpmultishiftqb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmultishiftqb, a, b, c, d);
        }
        Error vpmultishiftqb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmultishiftqb, a, b, c, d);
        }
        Error vpmultishiftqb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmultishiftqb, a, b, c, d);
        }
        Error vpmultishiftqb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmultishiftqb, a, b, c, d);
        }
        Error vpmultishiftqb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmultishiftqb, a, b, c, d);
        }
        Error vpmultishiftqb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmultishiftqb, a, b, c, d);
        }
        Error vpmuludq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c);
        }
        Error vpmuludq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c);
        }
        Error vpmuludq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c);
        }
        Error vpmuludq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c);
        }
        Error vpmuludq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c, d);
        }
        Error vpmuludq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c, d);
        }
        Error vpmuludq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c, d);
        }
        Error vpmuludq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c, d);
        }
        Error vpmuludq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c, d);
        }
        Error vpmuludq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpmuludq, a, b, c, d);
        }
        Error vpopcntb(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntb, a, b, c);
        }
        Error vpopcntb(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpopcntb, a, b, c);
        }
        Error vpopcntb(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntb, a, b, c);
        }
        Error vpopcntb(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntb, a, b, c);
        }
        Error vpopcntb(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntb, a, b, c);
        }
        Error vpopcntb(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntb, a, b, c);
        }
        Error vpopcntd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntd, a, b, c);
        }
        Error vpopcntd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpopcntd, a, b, c);
        }
        Error vpopcntd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntd, a, b, c);
        }
        Error vpopcntd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntd, a, b, c);
        }
        Error vpopcntd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntd, a, b, c);
        }
        Error vpopcntd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntd, a, b, c);
        }
        Error vpopcntq(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntq, a, b, c);
        }
        Error vpopcntq(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpopcntq, a, b, c);
        }
        Error vpopcntq(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntq, a, b, c);
        }
        Error vpopcntq(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntq, a, b, c);
        }
        Error vpopcntq(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntq, a, b, c);
        }
        Error vpopcntq(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntq, a, b, c);
        }
        Error vpopcntw(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntw, a, b, c);
        }
        Error vpopcntw(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpopcntw, a, b, c);
        }
        Error vpopcntw(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpopcntw, a, b, c);
        }
        Error vpopcntw(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntw, a, b, c);
        }
        Error vpopcntw(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntw, a, b, c);
        }
        Error vpopcntw(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpopcntw, a, b, c);
        }
        Error vpor(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpor, a, b, c);
        }
        Error vpor(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpor, a, b, c);
        }
        Error vpor(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpor, a, b, c);
        }
        Error vpor(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpor, a, b, c);
        }
        Error vpord(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpord, a, b, c, d);
        }
        Error vpord(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpord, a, b, c, d);
        }
        Error vpord(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpord, a, b, c, d);
        }
        Error vpord(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpord, a, b, c, d);
        }
        Error vpord(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpord, a, b, c, d);
        }
        Error vpord(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpord, a, b, c, d);
        }
        Error vporq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vporq, a, b, c, d);
        }
        Error vporq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vporq, a, b, c, d);
        }
        Error vporq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vporq, a, b, c, d);
        }
        Error vporq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vporq, a, b, c, d);
        }
        Error vporq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vporq, a, b, c, d);
        }
        Error vporq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vporq, a, b, c, d);
        }
        Error vpperm(const Xmm& a, const Xmm& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpperm, a, b, c, d);
        }
        Error vpperm(const Xmm& a, const Xmm& b, const Mem& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpperm, a, b, c, d);
        }
        Error vpperm(const Xmm& a, const Xmm& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpperm, a, b, c, d);
        }
        Error vprefetch0(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetch0, a);
        }
        Error vprefetch1(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetch1, a);
        }
        Error vprefetch2(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetch2, a);
        }
        Error vprefetche0(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetche0, a);
        }
        Error vprefetche1(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetche1, a);
        }
        Error vprefetche2(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetche2, a);
        }
        Error vprefetchenta(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetchenta, a);
        }
        Error vprefetchnta(const Mem& a)
        {
            return emit(x86::Mnemonic::Vprefetchnta, a);
        }
        Error vprold(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprold, a, b, c, d);
        }
        Error vprold(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprold, a, b, c, d);
        }
        Error vprold(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprold, a, b, c, d);
        }
        Error vprold(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprold, a, b, c, d);
        }
        Error vprold(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprold, a, b, c, d);
        }
        Error vprold(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprold, a, b, c, d);
        }
        Error vprolq(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprolq, a, b, c, d);
        }
        Error vprolq(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprolq, a, b, c, d);
        }
        Error vprolq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprolq, a, b, c, d);
        }
        Error vprolq(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprolq, a, b, c, d);
        }
        Error vprolq(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprolq, a, b, c, d);
        }
        Error vprolq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprolq, a, b, c, d);
        }
        Error vprolvd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vprolvd, a, b, c, d);
        }
        Error vprolvd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vprolvd, a, b, c, d);
        }
        Error vprolvd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vprolvd, a, b, c, d);
        }
        Error vprolvd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprolvd, a, b, c, d);
        }
        Error vprolvd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprolvd, a, b, c, d);
        }
        Error vprolvd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprolvd, a, b, c, d);
        }
        Error vprolvq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vprolvq, a, b, c, d);
        }
        Error vprolvq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vprolvq, a, b, c, d);
        }
        Error vprolvq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vprolvq, a, b, c, d);
        }
        Error vprolvq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprolvq, a, b, c, d);
        }
        Error vprolvq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprolvq, a, b, c, d);
        }
        Error vprolvq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprolvq, a, b, c, d);
        }
        Error vprord(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprord, a, b, c, d);
        }
        Error vprord(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprord, a, b, c, d);
        }
        Error vprord(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprord, a, b, c, d);
        }
        Error vprord(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprord, a, b, c, d);
        }
        Error vprord(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprord, a, b, c, d);
        }
        Error vprord(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprord, a, b, c, d);
        }
        Error vprorq(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprorq, a, b, c, d);
        }
        Error vprorq(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprorq, a, b, c, d);
        }
        Error vprorq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprorq, a, b, c, d);
        }
        Error vprorq(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprorq, a, b, c, d);
        }
        Error vprorq(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprorq, a, b, c, d);
        }
        Error vprorq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vprorq, a, b, c, d);
        }
        Error vprorvd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vprorvd, a, b, c, d);
        }
        Error vprorvd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vprorvd, a, b, c, d);
        }
        Error vprorvd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vprorvd, a, b, c, d);
        }
        Error vprorvd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprorvd, a, b, c, d);
        }
        Error vprorvd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprorvd, a, b, c, d);
        }
        Error vprorvd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprorvd, a, b, c, d);
        }
        Error vprorvq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vprorvq, a, b, c, d);
        }
        Error vprorvq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vprorvq, a, b, c, d);
        }
        Error vprorvq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vprorvq, a, b, c, d);
        }
        Error vprorvq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprorvq, a, b, c, d);
        }
        Error vprorvq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprorvq, a, b, c, d);
        }
        Error vprorvq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vprorvq, a, b, c, d);
        }
        Error vprotb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotb, a, b, c);
        }
        Error vprotb(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotb, a, b, c);
        }
        Error vprotb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vprotb, a, b, c);
        }
        Error vprotb(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotb, a, b, c);
        }
        Error vprotb(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotb, a, b, c);
        }
        Error vprotd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotd, a, b, c);
        }
        Error vprotd(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotd, a, b, c);
        }
        Error vprotd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vprotd, a, b, c);
        }
        Error vprotd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotd, a, b, c);
        }
        Error vprotd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotd, a, b, c);
        }
        Error vprotq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotq, a, b, c);
        }
        Error vprotq(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotq, a, b, c);
        }
        Error vprotq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vprotq, a, b, c);
        }
        Error vprotq(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotq, a, b, c);
        }
        Error vprotq(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotq, a, b, c);
        }
        Error vprotw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotw, a, b, c);
        }
        Error vprotw(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vprotw, a, b, c);
        }
        Error vprotw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vprotw, a, b, c);
        }
        Error vprotw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotw, a, b, c);
        }
        Error vprotw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vprotw, a, b, c);
        }
        Error vpsadbw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsadbw, a, b, c);
        }
        Error vpsadbw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsadbw, a, b, c);
        }
        Error vpsadbw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsadbw, a, b, c);
        }
        Error vpsadbw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsadbw, a, b, c);
        }
        Error vpsadbw(const Zmm& a, const Zmm& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpsadbw, a, b, c);
        }
        Error vpsadbw(const Zmm& a, const Zmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsadbw, a, b, c);
        }
        Error vpsbbd(const Zmm& a, const Mask& b, const Mask& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsbbd, a, b, c, d);
        }
        Error vpsbbd(const Zmm& a, const Mask& b, const Mask& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsbbd, a, b, c, d);
        }
        Error vpsbbrd(const Zmm& a, const Mask& b, const Mask& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsbbrd, a, b, c, d);
        }
        Error vpsbbrd(const Zmm& a, const Mask& b, const Mask& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsbbrd, a, b, c, d);
        }
        Error vpscatterdd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterdd, a, b, c);
        }
        Error vpscatterdd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpscatterdd, a, b, c);
        }
        Error vpscatterdd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterdd, a, b, c);
        }
        Error vpscatterdq(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterdq, a, b, c);
        }
        Error vpscatterdq(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpscatterdq, a, b, c);
        }
        Error vpscatterdq(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterdq, a, b, c);
        }
        Error vpscatterqd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterqd, a, b, c);
        }
        Error vpscatterqd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpscatterqd, a, b, c);
        }
        Error vpscatterqq(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterqq, a, b, c);
        }
        Error vpscatterqq(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpscatterqq, a, b, c);
        }
        Error vpscatterqq(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vpscatterqq, a, b, c);
        }
        Error vpshab(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshab, a, b, c);
        }
        Error vpshab(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshab, a, b, c);
        }
        Error vpshab(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshab, a, b, c);
        }
        Error vpshad(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshad, a, b, c);
        }
        Error vpshad(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshad, a, b, c);
        }
        Error vpshad(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshad, a, b, c);
        }
        Error vpshaq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshaq, a, b, c);
        }
        Error vpshaq(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshaq, a, b, c);
        }
        Error vpshaq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshaq, a, b, c);
        }
        Error vpshaw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshaw, a, b, c);
        }
        Error vpshaw(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshaw, a, b, c);
        }
        Error vpshaw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshaw, a, b, c);
        }
        Error vpshlb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshlb, a, b, c);
        }
        Error vpshlb(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshlb, a, b, c);
        }
        Error vpshlb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshlb, a, b, c);
        }
        Error vpshld(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshld, a, b, c);
        }
        Error vpshld(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshld, a, b, c);
        }
        Error vpshld(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshld, a, b, c);
        }
        Error vpshldd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldd, a, b, c, d, e);
        }
        Error vpshldd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldd, a, b, c, d, e);
        }
        Error vpshldd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldd, a, b, c, d, e);
        }
        Error vpshldd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldd, a, b, c, d, e);
        }
        Error vpshldd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldd, a, b, c, d, e);
        }
        Error vpshldd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldd, a, b, c, d, e);
        }
        Error vpshldq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldq, a, b, c, d, e);
        }
        Error vpshldq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldq, a, b, c, d, e);
        }
        Error vpshldq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldq, a, b, c, d, e);
        }
        Error vpshldq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldq, a, b, c, d, e);
        }
        Error vpshldq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldq, a, b, c, d, e);
        }
        Error vpshldq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldq, a, b, c, d, e);
        }
        Error vpshldvd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshldvd, a, b, c, d);
        }
        Error vpshldvd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshldvd, a, b, c, d);
        }
        Error vpshldvd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshldvd, a, b, c, d);
        }
        Error vpshldvd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvd, a, b, c, d);
        }
        Error vpshldvd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvd, a, b, c, d);
        }
        Error vpshldvd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvd, a, b, c, d);
        }
        Error vpshldvq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshldvq, a, b, c, d);
        }
        Error vpshldvq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshldvq, a, b, c, d);
        }
        Error vpshldvq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshldvq, a, b, c, d);
        }
        Error vpshldvq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvq, a, b, c, d);
        }
        Error vpshldvq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvq, a, b, c, d);
        }
        Error vpshldvq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvq, a, b, c, d);
        }
        Error vpshldvw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshldvw, a, b, c, d);
        }
        Error vpshldvw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshldvw, a, b, c, d);
        }
        Error vpshldvw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshldvw, a, b, c, d);
        }
        Error vpshldvw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvw, a, b, c, d);
        }
        Error vpshldvw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvw, a, b, c, d);
        }
        Error vpshldvw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshldvw, a, b, c, d);
        }
        Error vpshldw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldw, a, b, c, d, e);
        }
        Error vpshldw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldw, a, b, c, d, e);
        }
        Error vpshldw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldw, a, b, c, d, e);
        }
        Error vpshldw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldw, a, b, c, d, e);
        }
        Error vpshldw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldw, a, b, c, d, e);
        }
        Error vpshldw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshldw, a, b, c, d, e);
        }
        Error vpshlq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshlq, a, b, c);
        }
        Error vpshlq(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshlq, a, b, c);
        }
        Error vpshlq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshlq, a, b, c);
        }
        Error vpshlw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshlw, a, b, c);
        }
        Error vpshlw(const Xmm& a, const Mem& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshlw, a, b, c);
        }
        Error vpshlw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshlw, a, b, c);
        }
        Error vpshrdd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdd, a, b, c, d, e);
        }
        Error vpshrdd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdd, a, b, c, d, e);
        }
        Error vpshrdd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdd, a, b, c, d, e);
        }
        Error vpshrdd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdd, a, b, c, d, e);
        }
        Error vpshrdd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdd, a, b, c, d, e);
        }
        Error vpshrdd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdd, a, b, c, d, e);
        }
        Error vpshrdq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdq, a, b, c, d, e);
        }
        Error vpshrdq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdq, a, b, c, d, e);
        }
        Error vpshrdq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdq, a, b, c, d, e);
        }
        Error vpshrdq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdq, a, b, c, d, e);
        }
        Error vpshrdq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdq, a, b, c, d, e);
        }
        Error vpshrdq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdq, a, b, c, d, e);
        }
        Error vpshrdvd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvd, a, b, c, d);
        }
        Error vpshrdvd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvd, a, b, c, d);
        }
        Error vpshrdvd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvd, a, b, c, d);
        }
        Error vpshrdvd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvd, a, b, c, d);
        }
        Error vpshrdvd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvd, a, b, c, d);
        }
        Error vpshrdvd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvd, a, b, c, d);
        }
        Error vpshrdvq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvq, a, b, c, d);
        }
        Error vpshrdvq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvq, a, b, c, d);
        }
        Error vpshrdvq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvq, a, b, c, d);
        }
        Error vpshrdvq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvq, a, b, c, d);
        }
        Error vpshrdvq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvq, a, b, c, d);
        }
        Error vpshrdvq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvq, a, b, c, d);
        }
        Error vpshrdvw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvw, a, b, c, d);
        }
        Error vpshrdvw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvw, a, b, c, d);
        }
        Error vpshrdvw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshrdvw, a, b, c, d);
        }
        Error vpshrdvw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvw, a, b, c, d);
        }
        Error vpshrdvw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvw, a, b, c, d);
        }
        Error vpshrdvw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshrdvw, a, b, c, d);
        }
        Error vpshrdw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdw, a, b, c, d, e);
        }
        Error vpshrdw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdw, a, b, c, d, e);
        }
        Error vpshrdw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdw, a, b, c, d, e);
        }
        Error vpshrdw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdw, a, b, c, d, e);
        }
        Error vpshrdw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdw, a, b, c, d, e);
        }
        Error vpshrdw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpshrdw, a, b, c, d, e);
        }
        Error vpshufb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c);
        }
        Error vpshufb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c);
        }
        Error vpshufb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c);
        }
        Error vpshufb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c);
        }
        Error vpshufb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c, d);
        }
        Error vpshufb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c, d);
        }
        Error vpshufb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c, d);
        }
        Error vpshufb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c, d);
        }
        Error vpshufb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c, d);
        }
        Error vpshufb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshufb, a, b, c, d);
        }
        Error vpshufbitqmb(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpshufbitqmb, a, b, c, d);
        }
        Error vpshufbitqmb(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpshufbitqmb, a, b, c, d);
        }
        Error vpshufbitqmb(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpshufbitqmb, a, b, c, d);
        }
        Error vpshufbitqmb(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshufbitqmb, a, b, c, d);
        }
        Error vpshufbitqmb(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshufbitqmb, a, b, c, d);
        }
        Error vpshufbitqmb(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpshufbitqmb, a, b, c, d);
        }
        Error vpshufd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c);
        }
        Error vpshufd(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c);
        }
        Error vpshufd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c);
        }
        Error vpshufd(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c);
        }
        Error vpshufd(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c, d);
        }
        Error vpshufd(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c, d);
        }
        Error vpshufd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c, d);
        }
        Error vpshufd(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c, d);
        }
        Error vpshufd(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c, d);
        }
        Error vpshufd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufd, a, b, c, d);
        }
        Error vpshufhw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c);
        }
        Error vpshufhw(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c);
        }
        Error vpshufhw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c);
        }
        Error vpshufhw(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c);
        }
        Error vpshufhw(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c, d);
        }
        Error vpshufhw(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c, d);
        }
        Error vpshufhw(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c, d);
        }
        Error vpshufhw(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c, d);
        }
        Error vpshufhw(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c, d);
        }
        Error vpshufhw(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshufhw, a, b, c, d);
        }
        Error vpshuflw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c);
        }
        Error vpshuflw(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c);
        }
        Error vpshuflw(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c);
        }
        Error vpshuflw(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c);
        }
        Error vpshuflw(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c, d);
        }
        Error vpshuflw(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c, d);
        }
        Error vpshuflw(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c, d);
        }
        Error vpshuflw(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c, d);
        }
        Error vpshuflw(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c, d);
        }
        Error vpshuflw(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpshuflw, a, b, c, d);
        }
        Error vpsignb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsignb, a, b, c);
        }
        Error vpsignb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsignb, a, b, c);
        }
        Error vpsignb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsignb, a, b, c);
        }
        Error vpsignb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsignb, a, b, c);
        }
        Error vpsignd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsignd, a, b, c);
        }
        Error vpsignd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsignd, a, b, c);
        }
        Error vpsignd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsignd, a, b, c);
        }
        Error vpsignd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsignd, a, b, c);
        }
        Error vpsignw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsignw, a, b, c);
        }
        Error vpsignw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsignw, a, b, c);
        }
        Error vpsignw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsignw, a, b, c);
        }
        Error vpsignw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsignw, a, b, c);
        }
        Error vpslld(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c);
        }
        Error vpslld(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c);
        }
        Error vpslld(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c);
        }
        Error vpslld(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c);
        }
        Error vpslld(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c);
        }
        Error vpslld(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c);
        }
        Error vpslld(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        Error vpslld(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        Error vpslld(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        Error vpslld(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        Error vpslld(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        Error vpslld(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        Error vpslld(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        Error vpslld(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        Error vpslld(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        Error vpslld(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        Error vpslld(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        Error vpslld(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpslld, a, b, c, d);
        }
        Error vpslldq(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslldq, a, b, c);
        }
        Error vpslldq(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslldq, a, b, c);
        }
        Error vpslldq(const Zmm& a, const Zmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslldq, a, b, c);
        }
        Error vpslldq(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslldq, a, b, c);
        }
        Error vpslldq(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslldq, a, b, c);
        }
        Error vpslldq(const Zmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpslldq, a, b, c);
        }
        Error vpsllq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c);
        }
        Error vpsllq(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c);
        }
        Error vpsllq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c);
        }
        Error vpsllq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c);
        }
        Error vpsllq(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c);
        }
        Error vpsllq(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c);
        }
        Error vpsllq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        Error vpsllq(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        Error vpsllq(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        Error vpsllq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        Error vpsllq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        Error vpsllq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        Error vpsllq(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        Error vpsllq(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        Error vpsllq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        Error vpsllq(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        Error vpsllq(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        Error vpsllq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllq, a, b, c, d);
        }
        Error vpsllvd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c);
        }
        Error vpsllvd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c);
        }
        Error vpsllvd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c);
        }
        Error vpsllvd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c);
        }
        Error vpsllvd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c, d);
        }
        Error vpsllvd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c, d);
        }
        Error vpsllvd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c, d);
        }
        Error vpsllvd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c, d);
        }
        Error vpsllvd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c, d);
        }
        Error vpsllvd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvd, a, b, c, d);
        }
        Error vpsllvq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c);
        }
        Error vpsllvq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c);
        }
        Error vpsllvq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c);
        }
        Error vpsllvq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c);
        }
        Error vpsllvq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c, d);
        }
        Error vpsllvq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c, d);
        }
        Error vpsllvq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c, d);
        }
        Error vpsllvq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c, d);
        }
        Error vpsllvq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c, d);
        }
        Error vpsllvq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvq, a, b, c, d);
        }
        Error vpsllvw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllvw, a, b, c, d);
        }
        Error vpsllvw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsllvw, a, b, c, d);
        }
        Error vpsllvw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsllvw, a, b, c, d);
        }
        Error vpsllvw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvw, a, b, c, d);
        }
        Error vpsllvw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvw, a, b, c, d);
        }
        Error vpsllvw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllvw, a, b, c, d);
        }
        Error vpsllw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c);
        }
        Error vpsllw(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c);
        }
        Error vpsllw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c);
        }
        Error vpsllw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c);
        }
        Error vpsllw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c);
        }
        Error vpsllw(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c);
        }
        Error vpsllw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        Error vpsllw(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        Error vpsllw(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        Error vpsllw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        Error vpsllw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        Error vpsllw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        Error vpsllw(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        Error vpsllw(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        Error vpsllw(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        Error vpsllw(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        Error vpsllw(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        Error vpsllw(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsllw, a, b, c, d);
        }
        Error vpsrad(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c);
        }
        Error vpsrad(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c);
        }
        Error vpsrad(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c);
        }
        Error vpsrad(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c);
        }
        Error vpsrad(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c);
        }
        Error vpsrad(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c);
        }
        Error vpsrad(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        Error vpsrad(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        Error vpsrad(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        Error vpsrad(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        Error vpsrad(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        Error vpsrad(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        Error vpsrad(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        Error vpsrad(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        Error vpsrad(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        Error vpsrad(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        Error vpsrad(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        Error vpsrad(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrad, a, b, c, d);
        }
        Error vpsraq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        Error vpsraq(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        Error vpsraq(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        Error vpsraq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        Error vpsraq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        Error vpsraq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        Error vpsraq(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        Error vpsraq(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        Error vpsraq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        Error vpsraq(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        Error vpsraq(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        Error vpsraq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraq, a, b, c, d);
        }
        Error vpsravd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c);
        }
        Error vpsravd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c);
        }
        Error vpsravd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c);
        }
        Error vpsravd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c);
        }
        Error vpsravd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c, d);
        }
        Error vpsravd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c, d);
        }
        Error vpsravd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c, d);
        }
        Error vpsravd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c, d);
        }
        Error vpsravd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c, d);
        }
        Error vpsravd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravd, a, b, c, d);
        }
        Error vpsravq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsravq, a, b, c, d);
        }
        Error vpsravq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsravq, a, b, c, d);
        }
        Error vpsravq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsravq, a, b, c, d);
        }
        Error vpsravq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravq, a, b, c, d);
        }
        Error vpsravq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravq, a, b, c, d);
        }
        Error vpsravq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravq, a, b, c, d);
        }
        Error vpsravw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsravw, a, b, c, d);
        }
        Error vpsravw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsravw, a, b, c, d);
        }
        Error vpsravw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsravw, a, b, c, d);
        }
        Error vpsravw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravw, a, b, c, d);
        }
        Error vpsravw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravw, a, b, c, d);
        }
        Error vpsravw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsravw, a, b, c, d);
        }
        Error vpsraw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c);
        }
        Error vpsraw(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c);
        }
        Error vpsraw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c);
        }
        Error vpsraw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c);
        }
        Error vpsraw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c);
        }
        Error vpsraw(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c);
        }
        Error vpsraw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        Error vpsraw(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        Error vpsraw(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        Error vpsraw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        Error vpsraw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        Error vpsraw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        Error vpsraw(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        Error vpsraw(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        Error vpsraw(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        Error vpsraw(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        Error vpsraw(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        Error vpsraw(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsraw, a, b, c, d);
        }
        Error vpsrld(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c);
        }
        Error vpsrld(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c);
        }
        Error vpsrld(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c);
        }
        Error vpsrld(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c);
        }
        Error vpsrld(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c);
        }
        Error vpsrld(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c);
        }
        Error vpsrld(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        Error vpsrld(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        Error vpsrld(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        Error vpsrld(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        Error vpsrld(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        Error vpsrld(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        Error vpsrld(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        Error vpsrld(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        Error vpsrld(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        Error vpsrld(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        Error vpsrld(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        Error vpsrld(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrld, a, b, c, d);
        }
        Error vpsrldq(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrldq, a, b, c);
        }
        Error vpsrldq(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrldq, a, b, c);
        }
        Error vpsrldq(const Zmm& a, const Zmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrldq, a, b, c);
        }
        Error vpsrldq(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrldq, a, b, c);
        }
        Error vpsrldq(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrldq, a, b, c);
        }
        Error vpsrldq(const Zmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrldq, a, b, c);
        }
        Error vpsrlq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c);
        }
        Error vpsrlq(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c);
        }
        Error vpsrlq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c);
        }
        Error vpsrlq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c);
        }
        Error vpsrlq(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c);
        }
        Error vpsrlq(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c);
        }
        Error vpsrlq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        Error vpsrlq(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        Error vpsrlq(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        Error vpsrlq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        Error vpsrlq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        Error vpsrlq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        Error vpsrlq(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        Error vpsrlq(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        Error vpsrlq(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        Error vpsrlq(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        Error vpsrlq(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        Error vpsrlq(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlq, a, b, c, d);
        }
        Error vpsrlvd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c);
        }
        Error vpsrlvd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c);
        }
        Error vpsrlvd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c);
        }
        Error vpsrlvd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c);
        }
        Error vpsrlvd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c, d);
        }
        Error vpsrlvd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c, d);
        }
        Error vpsrlvd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c, d);
        }
        Error vpsrlvd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c, d);
        }
        Error vpsrlvd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c, d);
        }
        Error vpsrlvd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvd, a, b, c, d);
        }
        Error vpsrlvq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c);
        }
        Error vpsrlvq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c);
        }
        Error vpsrlvq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c);
        }
        Error vpsrlvq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c);
        }
        Error vpsrlvq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c, d);
        }
        Error vpsrlvq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c, d);
        }
        Error vpsrlvq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c, d);
        }
        Error vpsrlvq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c, d);
        }
        Error vpsrlvq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c, d);
        }
        Error vpsrlvq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvq, a, b, c, d);
        }
        Error vpsrlvw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvw, a, b, c, d);
        }
        Error vpsrlvw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvw, a, b, c, d);
        }
        Error vpsrlvw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlvw, a, b, c, d);
        }
        Error vpsrlvw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvw, a, b, c, d);
        }
        Error vpsrlvw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvw, a, b, c, d);
        }
        Error vpsrlvw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlvw, a, b, c, d);
        }
        Error vpsrlw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c);
        }
        Error vpsrlw(const Ymm& a, const Ymm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c);
        }
        Error vpsrlw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c);
        }
        Error vpsrlw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c);
        }
        Error vpsrlw(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c);
        }
        Error vpsrlw(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c);
        }
        Error vpsrlw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        Error vpsrlw(const Ymm& a, const Mask& b, const Ymm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        Error vpsrlw(const Zmm& a, const Mask& b, const Zmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        Error vpsrlw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        Error vpsrlw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        Error vpsrlw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        Error vpsrlw(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        Error vpsrlw(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        Error vpsrlw(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        Error vpsrlw(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        Error vpsrlw(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        Error vpsrlw(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vpsrlw, a, b, c, d);
        }
        Error vpsubb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c);
        }
        Error vpsubb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c);
        }
        Error vpsubb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c);
        }
        Error vpsubb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c);
        }
        Error vpsubb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c, d);
        }
        Error vpsubb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c, d);
        }
        Error vpsubb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c, d);
        }
        Error vpsubb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c, d);
        }
        Error vpsubb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c, d);
        }
        Error vpsubb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubb, a, b, c, d);
        }
        Error vpsubd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c);
        }
        Error vpsubd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c);
        }
        Error vpsubd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c);
        }
        Error vpsubd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c);
        }
        Error vpsubd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c, d);
        }
        Error vpsubd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c, d);
        }
        Error vpsubd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c, d);
        }
        Error vpsubd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c, d);
        }
        Error vpsubd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c, d);
        }
        Error vpsubd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubd, a, b, c, d);
        }
        Error vpsubq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c);
        }
        Error vpsubq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c);
        }
        Error vpsubq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c);
        }
        Error vpsubq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c);
        }
        Error vpsubq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c, d);
        }
        Error vpsubq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c, d);
        }
        Error vpsubq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c, d);
        }
        Error vpsubq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c, d);
        }
        Error vpsubq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c, d);
        }
        Error vpsubq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubq, a, b, c, d);
        }
        Error vpsubrd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubrd, a, b, c, d);
        }
        Error vpsubrd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubrd, a, b, c, d);
        }
        Error vpsubrsetbd(const Zmm& a, const Mask& b, const Mask& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubrsetbd, a, b, c, d);
        }
        Error vpsubrsetbd(const Zmm& a, const Mask& b, const Mask& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubrsetbd, a, b, c, d);
        }
        Error vpsubsb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c);
        }
        Error vpsubsb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c);
        }
        Error vpsubsb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c);
        }
        Error vpsubsb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c);
        }
        Error vpsubsb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c, d);
        }
        Error vpsubsb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c, d);
        }
        Error vpsubsb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c, d);
        }
        Error vpsubsb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c, d);
        }
        Error vpsubsb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c, d);
        }
        Error vpsubsb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsb, a, b, c, d);
        }
        Error vpsubsetbd(const Zmm& a, const Mask& b, const Mask& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubsetbd, a, b, c, d);
        }
        Error vpsubsetbd(const Zmm& a, const Mask& b, const Mask& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsetbd, a, b, c, d);
        }
        Error vpsubsw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c);
        }
        Error vpsubsw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c);
        }
        Error vpsubsw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c);
        }
        Error vpsubsw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c);
        }
        Error vpsubsw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c, d);
        }
        Error vpsubsw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c, d);
        }
        Error vpsubsw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c, d);
        }
        Error vpsubsw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c, d);
        }
        Error vpsubsw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c, d);
        }
        Error vpsubsw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubsw, a, b, c, d);
        }
        Error vpsubusb(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c);
        }
        Error vpsubusb(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c);
        }
        Error vpsubusb(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c);
        }
        Error vpsubusb(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c);
        }
        Error vpsubusb(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c, d);
        }
        Error vpsubusb(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c, d);
        }
        Error vpsubusb(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c, d);
        }
        Error vpsubusb(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c, d);
        }
        Error vpsubusb(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c, d);
        }
        Error vpsubusb(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubusb, a, b, c, d);
        }
        Error vpsubusw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c);
        }
        Error vpsubusw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c);
        }
        Error vpsubusw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c);
        }
        Error vpsubusw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c);
        }
        Error vpsubusw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c, d);
        }
        Error vpsubusw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c, d);
        }
        Error vpsubusw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c, d);
        }
        Error vpsubusw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c, d);
        }
        Error vpsubusw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c, d);
        }
        Error vpsubusw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubusw, a, b, c, d);
        }
        Error vpsubw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c);
        }
        Error vpsubw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c);
        }
        Error vpsubw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c);
        }
        Error vpsubw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c);
        }
        Error vpsubw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c, d);
        }
        Error vpsubw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c, d);
        }
        Error vpsubw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c, d);
        }
        Error vpsubw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c, d);
        }
        Error vpsubw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c, d);
        }
        Error vpsubw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpsubw, a, b, c, d);
        }
        Error vpternlogd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogd, a, b, c, d, e);
        }
        Error vpternlogd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogd, a, b, c, d, e);
        }
        Error vpternlogd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogd, a, b, c, d, e);
        }
        Error vpternlogd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogd, a, b, c, d, e);
        }
        Error vpternlogd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogd, a, b, c, d, e);
        }
        Error vpternlogd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogd, a, b, c, d, e);
        }
        Error vpternlogq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogq, a, b, c, d, e);
        }
        Error vpternlogq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogq, a, b, c, d, e);
        }
        Error vpternlogq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogq, a, b, c, d, e);
        }
        Error vpternlogq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogq, a, b, c, d, e);
        }
        Error vpternlogq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogq, a, b, c, d, e);
        }
        Error vpternlogq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vpternlogq, a, b, c, d, e);
        }
        Error vptest(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vptest, a, b);
        }
        Error vptest(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vptest, a, b);
        }
        Error vptest(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vptest, a, b);
        }
        Error vptest(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vptest, a, b);
        }
        Error vptestmb(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestmb, a, b, c, d);
        }
        Error vptestmb(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestmb, a, b, c, d);
        }
        Error vptestmb(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestmb, a, b, c, d);
        }
        Error vptestmb(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmb, a, b, c, d);
        }
        Error vptestmb(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmb, a, b, c, d);
        }
        Error vptestmb(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmb, a, b, c, d);
        }
        Error vptestmd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestmd, a, b, c, d);
        }
        Error vptestmd(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestmd, a, b, c, d);
        }
        Error vptestmd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestmd, a, b, c, d);
        }
        Error vptestmd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmd, a, b, c, d);
        }
        Error vptestmd(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmd, a, b, c, d);
        }
        Error vptestmd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmd, a, b, c, d);
        }
        Error vptestmq(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestmq, a, b, c, d);
        }
        Error vptestmq(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestmq, a, b, c, d);
        }
        Error vptestmq(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestmq, a, b, c, d);
        }
        Error vptestmq(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmq, a, b, c, d);
        }
        Error vptestmq(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmq, a, b, c, d);
        }
        Error vptestmq(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmq, a, b, c, d);
        }
        Error vptestmw(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestmw, a, b, c, d);
        }
        Error vptestmw(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestmw, a, b, c, d);
        }
        Error vptestmw(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestmw, a, b, c, d);
        }
        Error vptestmw(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmw, a, b, c, d);
        }
        Error vptestmw(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmw, a, b, c, d);
        }
        Error vptestmw(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestmw, a, b, c, d);
        }
        Error vptestnmb(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmb, a, b, c, d);
        }
        Error vptestnmb(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestnmb, a, b, c, d);
        }
        Error vptestnmb(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmb, a, b, c, d);
        }
        Error vptestnmb(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmb, a, b, c, d);
        }
        Error vptestnmb(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmb, a, b, c, d);
        }
        Error vptestnmb(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmb, a, b, c, d);
        }
        Error vptestnmd(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmd, a, b, c, d);
        }
        Error vptestnmd(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestnmd, a, b, c, d);
        }
        Error vptestnmd(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmd, a, b, c, d);
        }
        Error vptestnmd(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmd, a, b, c, d);
        }
        Error vptestnmd(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmd, a, b, c, d);
        }
        Error vptestnmd(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmd, a, b, c, d);
        }
        Error vptestnmq(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmq, a, b, c, d);
        }
        Error vptestnmq(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestnmq, a, b, c, d);
        }
        Error vptestnmq(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmq, a, b, c, d);
        }
        Error vptestnmq(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmq, a, b, c, d);
        }
        Error vptestnmq(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmq, a, b, c, d);
        }
        Error vptestnmq(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmq, a, b, c, d);
        }
        Error vptestnmw(const Mask& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmw, a, b, c, d);
        }
        Error vptestnmw(const Mask& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vptestnmw, a, b, c, d);
        }
        Error vptestnmw(const Mask& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vptestnmw, a, b, c, d);
        }
        Error vptestnmw(const Mask& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmw, a, b, c, d);
        }
        Error vptestnmw(const Mask& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmw, a, b, c, d);
        }
        Error vptestnmw(const Mask& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vptestnmw, a, b, c, d);
        }
        Error vpunpckhbw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c);
        }
        Error vpunpckhbw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c);
        }
        Error vpunpckhbw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c);
        }
        Error vpunpckhbw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c);
        }
        Error vpunpckhbw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c, d);
        }
        Error vpunpckhbw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c, d);
        }
        Error vpunpckhbw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c, d);
        }
        Error vpunpckhbw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c, d);
        }
        Error vpunpckhbw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c, d);
        }
        Error vpunpckhbw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhbw, a, b, c, d);
        }
        Error vpunpckhdq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c);
        }
        Error vpunpckhdq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c);
        }
        Error vpunpckhdq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c);
        }
        Error vpunpckhdq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c);
        }
        Error vpunpckhdq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c, d);
        }
        Error vpunpckhdq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c, d);
        }
        Error vpunpckhdq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c, d);
        }
        Error vpunpckhdq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c, d);
        }
        Error vpunpckhdq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c, d);
        }
        Error vpunpckhdq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhdq, a, b, c, d);
        }
        Error vpunpckhqdq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c);
        }
        Error vpunpckhqdq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c);
        }
        Error vpunpckhqdq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c);
        }
        Error vpunpckhqdq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c);
        }
        Error vpunpckhqdq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c, d);
        }
        Error vpunpckhqdq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c, d);
        }
        Error vpunpckhqdq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c, d);
        }
        Error vpunpckhqdq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c, d);
        }
        Error vpunpckhqdq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c, d);
        }
        Error vpunpckhqdq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhqdq, a, b, c, d);
        }
        Error vpunpckhwd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c);
        }
        Error vpunpckhwd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c);
        }
        Error vpunpckhwd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c);
        }
        Error vpunpckhwd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c);
        }
        Error vpunpckhwd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c, d);
        }
        Error vpunpckhwd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c, d);
        }
        Error vpunpckhwd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c, d);
        }
        Error vpunpckhwd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c, d);
        }
        Error vpunpckhwd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c, d);
        }
        Error vpunpckhwd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckhwd, a, b, c, d);
        }
        Error vpunpcklbw(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c);
        }
        Error vpunpcklbw(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c);
        }
        Error vpunpcklbw(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c);
        }
        Error vpunpcklbw(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c);
        }
        Error vpunpcklbw(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c, d);
        }
        Error vpunpcklbw(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c, d);
        }
        Error vpunpcklbw(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c, d);
        }
        Error vpunpcklbw(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c, d);
        }
        Error vpunpcklbw(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c, d);
        }
        Error vpunpcklbw(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklbw, a, b, c, d);
        }
        Error vpunpckldq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c);
        }
        Error vpunpckldq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c);
        }
        Error vpunpckldq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c);
        }
        Error vpunpckldq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c);
        }
        Error vpunpckldq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c, d);
        }
        Error vpunpckldq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c, d);
        }
        Error vpunpckldq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c, d);
        }
        Error vpunpckldq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c, d);
        }
        Error vpunpckldq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c, d);
        }
        Error vpunpckldq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpckldq, a, b, c, d);
        }
        Error vpunpcklqdq(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c);
        }
        Error vpunpcklqdq(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c);
        }
        Error vpunpcklqdq(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c);
        }
        Error vpunpcklqdq(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c);
        }
        Error vpunpcklqdq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c, d);
        }
        Error vpunpcklqdq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c, d);
        }
        Error vpunpcklqdq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c, d);
        }
        Error vpunpcklqdq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c, d);
        }
        Error vpunpcklqdq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c, d);
        }
        Error vpunpcklqdq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklqdq, a, b, c, d);
        }
        Error vpunpcklwd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c);
        }
        Error vpunpcklwd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c);
        }
        Error vpunpcklwd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c);
        }
        Error vpunpcklwd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c);
        }
        Error vpunpcklwd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c, d);
        }
        Error vpunpcklwd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c, d);
        }
        Error vpunpcklwd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c, d);
        }
        Error vpunpcklwd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c, d);
        }
        Error vpunpcklwd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c, d);
        }
        Error vpunpcklwd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpunpcklwd, a, b, c, d);
        }
        Error vpxor(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vpxor, a, b, c);
        }
        Error vpxor(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vpxor, a, b, c);
        }
        Error vpxor(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpxor, a, b, c);
        }
        Error vpxor(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vpxor, a, b, c);
        }
        Error vpxord(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpxord, a, b, c, d);
        }
        Error vpxord(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpxord, a, b, c, d);
        }
        Error vpxord(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpxord, a, b, c, d);
        }
        Error vpxord(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpxord, a, b, c, d);
        }
        Error vpxord(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpxord, a, b, c, d);
        }
        Error vpxord(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpxord, a, b, c, d);
        }
        Error vpxorq(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vpxorq, a, b, c, d);
        }
        Error vpxorq(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vpxorq, a, b, c, d);
        }
        Error vpxorq(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vpxorq, a, b, c, d);
        }
        Error vpxorq(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpxorq, a, b, c, d);
        }
        Error vpxorq(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpxorq, a, b, c, d);
        }
        Error vpxorq(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vpxorq, a, b, c, d);
        }
        Error vrangepd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangepd, a, b, c, d, e);
        }
        Error vrangepd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangepd, a, b, c, d, e);
        }
        Error vrangepd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangepd, a, b, c, d, e);
        }
        Error vrangepd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangepd, a, b, c, d, e);
        }
        Error vrangepd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangepd, a, b, c, d, e);
        }
        Error vrangepd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangepd, a, b, c, d, e);
        }
        Error vrangeps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangeps, a, b, c, d, e);
        }
        Error vrangeps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangeps, a, b, c, d, e);
        }
        Error vrangeps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangeps, a, b, c, d, e);
        }
        Error vrangeps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangeps, a, b, c, d, e);
        }
        Error vrangeps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangeps, a, b, c, d, e);
        }
        Error vrangeps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangeps, a, b, c, d, e);
        }
        Error vrangesd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangesd, a, b, c, d, e);
        }
        Error vrangesd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangesd, a, b, c, d, e);
        }
        Error vrangess(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangess, a, b, c, d, e);
        }
        Error vrangess(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrangess, a, b, c, d, e);
        }
        Error vrcp14pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrcp14pd, a, b, c);
        }
        Error vrcp14pd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vrcp14pd, a, b, c);
        }
        Error vrcp14pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrcp14pd, a, b, c);
        }
        Error vrcp14pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp14pd, a, b, c);
        }
        Error vrcp14pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp14pd, a, b, c);
        }
        Error vrcp14pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp14pd, a, b, c);
        }
        Error vrcp14ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrcp14ps, a, b, c);
        }
        Error vrcp14ps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vrcp14ps, a, b, c);
        }
        Error vrcp14ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrcp14ps, a, b, c);
        }
        Error vrcp14ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp14ps, a, b, c);
        }
        Error vrcp14ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp14ps, a, b, c);
        }
        Error vrcp14ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp14ps, a, b, c);
        }
        Error vrcp14sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrcp14sd, a, b, c, d);
        }
        Error vrcp14sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrcp14sd, a, b, c, d);
        }
        Error vrcp14ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrcp14ss, a, b, c, d);
        }
        Error vrcp14ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrcp14ss, a, b, c, d);
        }
        Error vrcp23ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrcp23ps, a, b, c);
        }
        Error vrcp23ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp23ps, a, b, c);
        }
        Error vrcp28pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrcp28pd, a, b, c);
        }
        Error vrcp28pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp28pd, a, b, c);
        }
        Error vrcp28ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrcp28ps, a, b, c);
        }
        Error vrcp28ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcp28ps, a, b, c);
        }
        Error vrcp28sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrcp28sd, a, b, c, d);
        }
        Error vrcp28sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrcp28sd, a, b, c, d);
        }
        Error vrcp28ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrcp28ss, a, b, c, d);
        }
        Error vrcp28ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrcp28ss, a, b, c, d);
        }
        Error vrcpph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrcpph, a, b, c);
        }
        Error vrcpph(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vrcpph, a, b, c);
        }
        Error vrcpph(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrcpph, a, b, c);
        }
        Error vrcpph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcpph, a, b, c);
        }
        Error vrcpph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcpph, a, b, c);
        }
        Error vrcpph(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcpph, a, b, c);
        }
        Error vrcpps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vrcpps, a, b);
        }
        Error vrcpps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vrcpps, a, b);
        }
        Error vrcpps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vrcpps, a, b);
        }
        Error vrcpps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vrcpps, a, b);
        }
        Error vrcpsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrcpsh, a, b, c, d);
        }
        Error vrcpsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrcpsh, a, b, c, d);
        }
        Error vrcpss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrcpss, a, b, c);
        }
        Error vrcpss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrcpss, a, b, c);
        }
        Error vreducepd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreducepd, a, b, c, d);
        }
        Error vreducepd(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreducepd, a, b, c, d);
        }
        Error vreducepd(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreducepd, a, b, c, d);
        }
        Error vreducepd(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreducepd, a, b, c, d);
        }
        Error vreducepd(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreducepd, a, b, c, d);
        }
        Error vreducepd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreducepd, a, b, c, d);
        }
        Error vreduceph(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceph, a, b, c, d);
        }
        Error vreduceph(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceph, a, b, c, d);
        }
        Error vreduceph(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceph, a, b, c, d);
        }
        Error vreduceph(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceph, a, b, c, d);
        }
        Error vreduceph(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceph, a, b, c, d);
        }
        Error vreduceph(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceph, a, b, c, d);
        }
        Error vreduceps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceps, a, b, c, d);
        }
        Error vreduceps(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceps, a, b, c, d);
        }
        Error vreduceps(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceps, a, b, c, d);
        }
        Error vreduceps(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceps, a, b, c, d);
        }
        Error vreduceps(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceps, a, b, c, d);
        }
        Error vreduceps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vreduceps, a, b, c, d);
        }
        Error vreducesd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vreducesd, a, b, c, d, e);
        }
        Error vreducesd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vreducesd, a, b, c, d, e);
        }
        Error vreducesh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vreducesh, a, b, c, d, e);
        }
        Error vreducesh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vreducesh, a, b, c, d, e);
        }
        Error vreducess(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vreducess, a, b, c, d, e);
        }
        Error vreducess(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vreducess, a, b, c, d, e);
        }
        Error vrndfxpntpd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndfxpntpd, a, b, c, d);
        }
        Error vrndfxpntpd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndfxpntpd, a, b, c, d);
        }
        Error vrndfxpntps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndfxpntps, a, b, c, d);
        }
        Error vrndfxpntps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndfxpntps, a, b, c, d);
        }
        Error vrndscalepd(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscalepd, a, b, c, d);
        }
        Error vrndscalepd(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscalepd, a, b, c, d);
        }
        Error vrndscalepd(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscalepd, a, b, c, d);
        }
        Error vrndscalepd(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscalepd, a, b, c, d);
        }
        Error vrndscalepd(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscalepd, a, b, c, d);
        }
        Error vrndscalepd(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscalepd, a, b, c, d);
        }
        Error vrndscaleph(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleph, a, b, c, d);
        }
        Error vrndscaleph(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleph, a, b, c, d);
        }
        Error vrndscaleph(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleph, a, b, c, d);
        }
        Error vrndscaleph(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleph, a, b, c, d);
        }
        Error vrndscaleph(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleph, a, b, c, d);
        }
        Error vrndscaleph(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleph, a, b, c, d);
        }
        Error vrndscaleps(const Zmm& a, const Mask& b, const Zmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleps, a, b, c, d);
        }
        Error vrndscaleps(const Xmm& a, const Mask& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleps, a, b, c, d);
        }
        Error vrndscaleps(const Ymm& a, const Mask& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleps, a, b, c, d);
        }
        Error vrndscaleps(const Xmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleps, a, b, c, d);
        }
        Error vrndscaleps(const Ymm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleps, a, b, c, d);
        }
        Error vrndscaleps(const Zmm& a, const Mask& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vrndscaleps, a, b, c, d);
        }
        Error vrndscalesd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrndscalesd, a, b, c, d, e);
        }
        Error vrndscalesd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrndscalesd, a, b, c, d, e);
        }
        Error vrndscalesh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrndscalesh, a, b, c, d, e);
        }
        Error vrndscalesh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrndscalesh, a, b, c, d, e);
        }
        Error vrndscaless(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrndscaless, a, b, c, d, e);
        }
        Error vrndscaless(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vrndscaless, a, b, c, d, e);
        }
        Error vroundpd(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundpd, a, b, c);
        }
        Error vroundpd(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundpd, a, b, c);
        }
        Error vroundpd(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundpd, a, b, c);
        }
        Error vroundpd(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundpd, a, b, c);
        }
        Error vroundps(const Xmm& a, const Xmm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundps, a, b, c);
        }
        Error vroundps(const Ymm& a, const Ymm& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundps, a, b, c);
        }
        Error vroundps(const Xmm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundps, a, b, c);
        }
        Error vroundps(const Ymm& a, const Mem& b, const Imm& c)
        {
            return emit(x86::Mnemonic::Vroundps, a, b, c);
        }
        Error vroundsd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vroundsd, a, b, c, d);
        }
        Error vroundsd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vroundsd, a, b, c, d);
        }
        Error vroundss(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vroundss, a, b, c, d);
        }
        Error vroundss(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vroundss, a, b, c, d);
        }
        Error vrsqrt14pd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14pd, a, b, c);
        }
        Error vrsqrt14pd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14pd, a, b, c);
        }
        Error vrsqrt14pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14pd, a, b, c);
        }
        Error vrsqrt14pd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14pd, a, b, c);
        }
        Error vrsqrt14pd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14pd, a, b, c);
        }
        Error vrsqrt14pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14pd, a, b, c);
        }
        Error vrsqrt14ps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14ps, a, b, c);
        }
        Error vrsqrt14ps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14ps, a, b, c);
        }
        Error vrsqrt14ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14ps, a, b, c);
        }
        Error vrsqrt14ps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14ps, a, b, c);
        }
        Error vrsqrt14ps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14ps, a, b, c);
        }
        Error vrsqrt14ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt14ps, a, b, c);
        }
        Error vrsqrt14sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrsqrt14sd, a, b, c, d);
        }
        Error vrsqrt14sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrsqrt14sd, a, b, c, d);
        }
        Error vrsqrt14ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrsqrt14ss, a, b, c, d);
        }
        Error vrsqrt14ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrsqrt14ss, a, b, c, d);
        }
        Error vrsqrt23ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt23ps, a, b, c);
        }
        Error vrsqrt23ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt23ps, a, b, c);
        }
        Error vrsqrt28pd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt28pd, a, b, c);
        }
        Error vrsqrt28pd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt28pd, a, b, c);
        }
        Error vrsqrt28ps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrt28ps, a, b, c);
        }
        Error vrsqrt28ps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrt28ps, a, b, c);
        }
        Error vrsqrt28sd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrsqrt28sd, a, b, c, d);
        }
        Error vrsqrt28sd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrsqrt28sd, a, b, c, d);
        }
        Error vrsqrt28ss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrsqrt28ss, a, b, c, d);
        }
        Error vrsqrt28ss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrsqrt28ss, a, b, c, d);
        }
        Error vrsqrtph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrtph, a, b, c);
        }
        Error vrsqrtph(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vrsqrtph, a, b, c);
        }
        Error vrsqrtph(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrtph, a, b, c);
        }
        Error vrsqrtph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrtph, a, b, c);
        }
        Error vrsqrtph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrtph, a, b, c);
        }
        Error vrsqrtph(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrtph, a, b, c);
        }
        Error vrsqrtps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vrsqrtps, a, b);
        }
        Error vrsqrtps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vrsqrtps, a, b);
        }
        Error vrsqrtps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vrsqrtps, a, b);
        }
        Error vrsqrtps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vrsqrtps, a, b);
        }
        Error vrsqrtsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vrsqrtsh, a, b, c, d);
        }
        Error vrsqrtsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vrsqrtsh, a, b, c, d);
        }
        Error vrsqrtss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vrsqrtss, a, b, c);
        }
        Error vrsqrtss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vrsqrtss, a, b, c);
        }
        Error vscalefpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vscalefpd, a, b, c, d);
        }
        Error vscalefpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vscalefpd, a, b, c, d);
        }
        Error vscalefpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vscalefpd, a, b, c, d);
        }
        Error vscalefpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefpd, a, b, c, d);
        }
        Error vscalefpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefpd, a, b, c, d);
        }
        Error vscalefpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefpd, a, b, c, d);
        }
        Error vscalefph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vscalefph, a, b, c, d);
        }
        Error vscalefph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vscalefph, a, b, c, d);
        }
        Error vscalefph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vscalefph, a, b, c, d);
        }
        Error vscalefph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefph, a, b, c, d);
        }
        Error vscalefph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefph, a, b, c, d);
        }
        Error vscalefph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefph, a, b, c, d);
        }
        Error vscalefps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vscalefps, a, b, c, d);
        }
        Error vscalefps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vscalefps, a, b, c, d);
        }
        Error vscalefps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vscalefps, a, b, c, d);
        }
        Error vscalefps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefps, a, b, c, d);
        }
        Error vscalefps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefps, a, b, c, d);
        }
        Error vscalefps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefps, a, b, c, d);
        }
        Error vscalefsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vscalefsd, a, b, c, d);
        }
        Error vscalefsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefsd, a, b, c, d);
        }
        Error vscalefsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vscalefsh, a, b, c, d);
        }
        Error vscalefsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefsh, a, b, c, d);
        }
        Error vscalefss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vscalefss, a, b, c, d);
        }
        Error vscalefss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscalefss, a, b, c, d);
        }
        Error vscaleps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vscaleps, a, b, c, d);
        }
        Error vscaleps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vscaleps, a, b, c, d);
        }
        Error vscatterdpd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vscatterdpd, a, b, c);
        }
        Error vscatterdpd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vscatterdpd, a, b, c);
        }
        Error vscatterdpd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vscatterdpd, a, b, c);
        }
        Error vscatterdps(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vscatterdps, a, b, c);
        }
        Error vscatterdps(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vscatterdps, a, b, c);
        }
        Error vscatterdps(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vscatterdps, a, b, c);
        }
        Error vscatterpf0dpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf0dpd, a, b);
        }
        Error vscatterpf0dps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf0dps, a, b);
        }
        Error vscatterpf0hintdpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf0hintdpd, a, b);
        }
        Error vscatterpf0hintdps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf0hintdps, a, b);
        }
        Error vscatterpf0qpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf0qpd, a, b);
        }
        Error vscatterpf0qps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf0qps, a, b);
        }
        Error vscatterpf1dpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf1dpd, a, b);
        }
        Error vscatterpf1dps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf1dps, a, b);
        }
        Error vscatterpf1qpd(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf1qpd, a, b);
        }
        Error vscatterpf1qps(const Mem& a, const Mask& b)
        {
            return emit(x86::Mnemonic::Vscatterpf1qps, a, b);
        }
        Error vscatterqpd(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vscatterqpd, a, b, c);
        }
        Error vscatterqpd(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vscatterqpd, a, b, c);
        }
        Error vscatterqpd(const Mem& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vscatterqpd, a, b, c);
        }
        Error vscatterqps(const Mem& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vscatterqps, a, b, c);
        }
        Error vscatterqps(const Mem& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vscatterqps, a, b, c);
        }
        Error vshuff32x4(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff32x4, a, b, c, d, e);
        }
        Error vshuff32x4(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff32x4, a, b, c, d, e);
        }
        Error vshuff32x4(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff32x4, a, b, c, d, e);
        }
        Error vshuff32x4(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff32x4, a, b, c, d, e);
        }
        Error vshuff64x2(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff64x2, a, b, c, d, e);
        }
        Error vshuff64x2(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff64x2, a, b, c, d, e);
        }
        Error vshuff64x2(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff64x2, a, b, c, d, e);
        }
        Error vshuff64x2(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshuff64x2, a, b, c, d, e);
        }
        Error vshufi32x4(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi32x4, a, b, c, d, e);
        }
        Error vshufi32x4(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi32x4, a, b, c, d, e);
        }
        Error vshufi32x4(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi32x4, a, b, c, d, e);
        }
        Error vshufi32x4(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi32x4, a, b, c, d, e);
        }
        Error vshufi64x2(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi64x2, a, b, c, d, e);
        }
        Error vshufi64x2(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi64x2, a, b, c, d, e);
        }
        Error vshufi64x2(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi64x2, a, b, c, d, e);
        }
        Error vshufi64x2(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufi64x2, a, b, c, d, e);
        }
        Error vshufpd(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d);
        }
        Error vshufpd(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d);
        }
        Error vshufpd(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d);
        }
        Error vshufpd(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d);
        }
        Error vshufpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d, e);
        }
        Error vshufpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d, e);
        }
        Error vshufpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d, e);
        }
        Error vshufpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d, e);
        }
        Error vshufpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d, e);
        }
        Error vshufpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufpd, a, b, c, d, e);
        }
        Error vshufps(const Xmm& a, const Xmm& b, const Xmm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d);
        }
        Error vshufps(const Ymm& a, const Ymm& b, const Ymm& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d);
        }
        Error vshufps(const Xmm& a, const Xmm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d);
        }
        Error vshufps(const Ymm& a, const Ymm& b, const Mem& c, const Imm& d)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d);
        }
        Error vshufps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d, e);
        }
        Error vshufps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d, e);
        }
        Error vshufps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d, e);
        }
        Error vshufps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d, e);
        }
        Error vshufps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d, e);
        }
        Error vshufps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d, const Imm& e)
        {
            return emit(x86::Mnemonic::Vshufps, a, b, c, d, e);
        }
        Error vsqrtpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b);
        }
        Error vsqrtpd(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b);
        }
        Error vsqrtpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b);
        }
        Error vsqrtpd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b);
        }
        Error vsqrtpd(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b, c);
        }
        Error vsqrtpd(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b, c);
        }
        Error vsqrtpd(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b, c);
        }
        Error vsqrtpd(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b, c);
        }
        Error vsqrtpd(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b, c);
        }
        Error vsqrtpd(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtpd, a, b, c);
        }
        Error vsqrtph(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtph, a, b, c);
        }
        Error vsqrtph(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtph, a, b, c);
        }
        Error vsqrtph(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vsqrtph, a, b, c);
        }
        Error vsqrtph(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtph, a, b, c);
        }
        Error vsqrtph(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtph, a, b, c);
        }
        Error vsqrtph(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtph, a, b, c);
        }
        Error vsqrtps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b);
        }
        Error vsqrtps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b);
        }
        Error vsqrtps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b);
        }
        Error vsqrtps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b);
        }
        Error vsqrtps(const Zmm& a, const Mask& b, const Zmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b, c);
        }
        Error vsqrtps(const Xmm& a, const Mask& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b, c);
        }
        Error vsqrtps(const Ymm& a, const Mask& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b, c);
        }
        Error vsqrtps(const Xmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b, c);
        }
        Error vsqrtps(const Ymm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b, c);
        }
        Error vsqrtps(const Zmm& a, const Mask& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtps, a, b, c);
        }
        Error vsqrtsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtsd, a, b, c);
        }
        Error vsqrtsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtsd, a, b, c);
        }
        Error vsqrtsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsqrtsd, a, b, c, d);
        }
        Error vsqrtsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsqrtsd, a, b, c, d);
        }
        Error vsqrtsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsqrtsh, a, b, c, d);
        }
        Error vsqrtsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsqrtsh, a, b, c, d);
        }
        Error vsqrtss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsqrtss, a, b, c);
        }
        Error vsqrtss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsqrtss, a, b, c);
        }
        Error vsqrtss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsqrtss, a, b, c, d);
        }
        Error vsqrtss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsqrtss, a, b, c, d);
        }
        Error vstmxcsr(const Mem& a)
        {
            return emit(x86::Mnemonic::Vstmxcsr, a);
        }
        Error vsubpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c);
        }
        Error vsubpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c);
        }
        Error vsubpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c);
        }
        Error vsubpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c);
        }
        Error vsubpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c, d);
        }
        Error vsubpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c, d);
        }
        Error vsubpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c, d);
        }
        Error vsubpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c, d);
        }
        Error vsubpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c, d);
        }
        Error vsubpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubpd, a, b, c, d);
        }
        Error vsubph(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vsubph, a, b, c, d);
        }
        Error vsubph(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsubph, a, b, c, d);
        }
        Error vsubph(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vsubph, a, b, c, d);
        }
        Error vsubph(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubph, a, b, c, d);
        }
        Error vsubph(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubph, a, b, c, d);
        }
        Error vsubph(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubph, a, b, c, d);
        }
        Error vsubps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c);
        }
        Error vsubps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c);
        }
        Error vsubps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c);
        }
        Error vsubps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c);
        }
        Error vsubps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c, d);
        }
        Error vsubps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c, d);
        }
        Error vsubps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c, d);
        }
        Error vsubps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c, d);
        }
        Error vsubps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c, d);
        }
        Error vsubps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubps, a, b, c, d);
        }
        Error vsubrpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vsubrpd, a, b, c, d);
        }
        Error vsubrpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubrpd, a, b, c, d);
        }
        Error vsubrps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vsubrps, a, b, c, d);
        }
        Error vsubrps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubrps, a, b, c, d);
        }
        Error vsubsd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsubsd, a, b, c);
        }
        Error vsubsd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsubsd, a, b, c);
        }
        Error vsubsd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsubsd, a, b, c, d);
        }
        Error vsubsd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubsd, a, b, c, d);
        }
        Error vsubsh(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsubsh, a, b, c, d);
        }
        Error vsubsh(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubsh, a, b, c, d);
        }
        Error vsubss(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vsubss, a, b, c);
        }
        Error vsubss(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vsubss, a, b, c);
        }
        Error vsubss(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vsubss, a, b, c, d);
        }
        Error vsubss(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vsubss, a, b, c, d);
        }
        Error vtestpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vtestpd, a, b);
        }
        Error vtestpd(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vtestpd, a, b);
        }
        Error vtestpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vtestpd, a, b);
        }
        Error vtestpd(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vtestpd, a, b);
        }
        Error vtestps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vtestps, a, b);
        }
        Error vtestps(const Ymm& a, const Ymm& b)
        {
            return emit(x86::Mnemonic::Vtestps, a, b);
        }
        Error vtestps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vtestps, a, b);
        }
        Error vtestps(const Ymm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vtestps, a, b);
        }
        Error vucomisd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vucomisd, a, b);
        }
        Error vucomisd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vucomisd, a, b);
        }
        Error vucomish(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vucomish, a, b);
        }
        Error vucomish(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vucomish, a, b);
        }
        Error vucomiss(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Vucomiss, a, b);
        }
        Error vucomiss(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Vucomiss, a, b);
        }
        Error vunpckhpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c);
        }
        Error vunpckhpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c);
        }
        Error vunpckhpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c);
        }
        Error vunpckhpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c);
        }
        Error vunpckhpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c, d);
        }
        Error vunpckhpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c, d);
        }
        Error vunpckhpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c, d);
        }
        Error vunpckhpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c, d);
        }
        Error vunpckhpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c, d);
        }
        Error vunpckhpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpckhpd, a, b, c, d);
        }
        Error vunpckhps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c);
        }
        Error vunpckhps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c);
        }
        Error vunpckhps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c);
        }
        Error vunpckhps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c);
        }
        Error vunpckhps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c, d);
        }
        Error vunpckhps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c, d);
        }
        Error vunpckhps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c, d);
        }
        Error vunpckhps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c, d);
        }
        Error vunpckhps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c, d);
        }
        Error vunpckhps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpckhps, a, b, c, d);
        }
        Error vunpcklpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c);
        }
        Error vunpcklpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c);
        }
        Error vunpcklpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c);
        }
        Error vunpcklpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c);
        }
        Error vunpcklpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c, d);
        }
        Error vunpcklpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c, d);
        }
        Error vunpcklpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c, d);
        }
        Error vunpcklpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c, d);
        }
        Error vunpcklpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c, d);
        }
        Error vunpcklpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpcklpd, a, b, c, d);
        }
        Error vunpcklps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c);
        }
        Error vunpcklps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c);
        }
        Error vunpcklps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c);
        }
        Error vunpcklps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c);
        }
        Error vunpcklps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c, d);
        }
        Error vunpcklps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c, d);
        }
        Error vunpcklps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c, d);
        }
        Error vunpcklps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c, d);
        }
        Error vunpcklps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c, d);
        }
        Error vunpcklps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vunpcklps, a, b, c, d);
        }
        Error vxorpd(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c);
        }
        Error vxorpd(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c);
        }
        Error vxorpd(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c);
        }
        Error vxorpd(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c);
        }
        Error vxorpd(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c, d);
        }
        Error vxorpd(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c, d);
        }
        Error vxorpd(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c, d);
        }
        Error vxorpd(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c, d);
        }
        Error vxorpd(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c, d);
        }
        Error vxorpd(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vxorpd, a, b, c, d);
        }
        Error vxorps(const Xmm& a, const Xmm& b, const Xmm& c)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c);
        }
        Error vxorps(const Ymm& a, const Ymm& b, const Ymm& c)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c);
        }
        Error vxorps(const Xmm& a, const Xmm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c);
        }
        Error vxorps(const Ymm& a, const Ymm& b, const Mem& c)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c);
        }
        Error vxorps(const Xmm& a, const Mask& b, const Xmm& c, const Xmm& d)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c, d);
        }
        Error vxorps(const Ymm& a, const Mask& b, const Ymm& c, const Ymm& d)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c, d);
        }
        Error vxorps(const Zmm& a, const Mask& b, const Zmm& c, const Zmm& d)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c, d);
        }
        Error vxorps(const Xmm& a, const Mask& b, const Xmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c, d);
        }
        Error vxorps(const Ymm& a, const Mask& b, const Ymm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c, d);
        }
        Error vxorps(const Zmm& a, const Mask& b, const Zmm& c, const Mem& d)
        {
            return emit(x86::Mnemonic::Vxorps, a, b, c, d);
        }
        Error vzeroall()
        {
            return emit(x86::Mnemonic::Vzeroall);
        }
        Error vzeroupper()
        {
            return emit(x86::Mnemonic::Vzeroupper);
        }
        Error wbinvd()
        {
            return emit(x86::Mnemonic::Wbinvd);
        }
        Error wrfsbase(const Gp& a)
        {
            return emit(x86::Mnemonic::Wrfsbase, a);
        }
        Error wrgsbase(const Gp& a)
        {
            return emit(x86::Mnemonic::Wrgsbase, a);
        }
        Error wrmsr()
        {
            return emit(x86::Mnemonic::Wrmsr);
        }
        Error wrpkru()
        {
            return emit(x86::Mnemonic::Wrpkru);
        }
        Error wrssd(const Mem& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Wrssd, a, b);
        }
        Error wrssq(const Mem& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Wrssq, a, b);
        }
        Error wrussd(const Mem& a, const Gp32& b)
        {
            return emit(x86::Mnemonic::Wrussd, a, b);
        }
        Error wrussq(const Mem& a, const Gp64& b)
        {
            return emit(x86::Mnemonic::Wrussq, a, b);
        }
        Error xabort(const Imm& a)
        {
            return emit(x86::Mnemonic::Xabort, a);
        }
        Error xadd(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Xadd, a, b);
        }
        Error xadd(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Xadd, a, b);
        }
        Error xadd(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Xadd, a, b);
        }
        Error xadd(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Xadd, a, b);
        }
        Error xbegin(const Imm& a)
        {
            return emit(x86::Mnemonic::Xbegin, a);
        }
        Error xchg(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Xchg, a, b);
        }
        Error xchg(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Xchg, a, b);
        }
        Error xchg(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Xchg, a, b);
        }
        Error xchg(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Xchg, a, b);
        }
        Error xchg(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Xchg, b, a);
        }
        Error xcrypt_cbc()
        {
            return emit(x86::Mnemonic::Xcrypt_cbc);
        }
        Error xcrypt_cfb()
        {
            return emit(x86::Mnemonic::Xcrypt_cfb);
        }
        Error xcrypt_ctr()
        {
            return emit(x86::Mnemonic::Xcrypt_ctr);
        }
        Error xcrypt_ecb()
        {
            return emit(x86::Mnemonic::Xcrypt_ecb);
        }
        Error xcrypt_ofb()
        {
            return emit(x86::Mnemonic::Xcrypt_ofb);
        }
        Error xend()
        {
            return emit(x86::Mnemonic::Xend);
        }
        Error xgetbv()
        {
            return emit(x86::Mnemonic::Xgetbv);
        }
        Error xlat()
        {
            return emit(x86::Mnemonic::Xlat);
        }
        Error xor_(const Gp8& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        Error xor_(const Mem& a, const Gp8& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        Error xor_(const Gp& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        Error xor_(const Mem& a, const Gp& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        Error xor_(const Gp8& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        Error xor_(const Gp& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        Error xor_(const Gp& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        Error xor_(const Gp8& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        Error xor_(const Mem& a, const Imm& b)
        {
            return emit(x86::Mnemonic::Xor, a, b);
        }
        Error xorpd(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Xorpd, a, b);
        }
        Error xorpd(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Xorpd, a, b);
        }
        Error xorps(const Xmm& a, const Xmm& b)
        {
            return emit(x86::Mnemonic::Xorps, a, b);
        }
        Error xorps(const Xmm& a, const Mem& b)
        {
            return emit(x86::Mnemonic::Xorps, a, b);
        }
        Error xresldtrk()
        {
            return emit(x86::Mnemonic::Xresldtrk);
        }
        Error xrstor(const Mem& a)
        {
            return emit(x86::Mnemonic::Xrstor, a);
        }
        Error xrstor64(const Mem& a)
        {
            return emit(x86::Mnemonic::Xrstor64, a);
        }
        Error xrstors(const Mem& a)
        {
            return emit(x86::Mnemonic::Xrstors, a);
        }
        Error xrstors64(const Mem& a)
        {
            return emit(x86::Mnemonic::Xrstors64, a);
        }
        Error xsave(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsave, a);
        }
        Error xsave64(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsave64, a);
        }
        Error xsavec(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsavec, a);
        }
        Error xsavec64(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsavec64, a);
        }
        Error xsaveopt(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsaveopt, a);
        }
        Error xsaveopt64(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsaveopt64, a);
        }
        Error xsaves(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsaves, a);
        }
        Error xsaves64(const Mem& a)
        {
            return emit(x86::Mnemonic::Xsaves64, a);
        }
        Error xsetbv()
        {
            return emit(x86::Mnemonic::Xsetbv);
        }
        Error xsha1()
        {
            return emit(x86::Mnemonic::Xsha1);
        }
        Error xsha256()
        {
            return emit(x86::Mnemonic::Xsha256);
        }
        Error xstore()
        {
            return emit(x86::Mnemonic::Xstore);
        }
        Error xsusldtrk()
        {
            return emit(x86::Mnemonic::Xsusldtrk);
        }
        Error xtest()
        {
            return emit(x86::Mnemonic::Xtest);
        }
    };

} // namespace zasm::x86
