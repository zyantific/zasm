#pragma once

#include "errors.hpp"
#include "instruction.hpp"
#include "operand.hpp"

namespace zasm
{
    class Program;
    class Node;

    class Assembler
    {
        Program& _program;
        const Node* _cursor{};

    public:
        Assembler(Program& _program);

        void setCursor(const Node* pos);
        const Node* getCursor() const;

    public:
        Label createLabel(const char* name = nullptr);
        Error bind(const Label& label);

    public:
        // Data emitter.
        Error db(uint8_t val);
        Error dw(uint16_t val);
        Error dd(uint32_t val);
        Error dq(uint64_t val);
        Error embed(const void* data, size_t len);

    public:
        template<typename... TArgs> Error emit(Instruction::Prefix prefixes, ZydisMnemonic id, TArgs&&... args)
        {
            Instruction::Operands ops{ args... };
            std::fill(std::begin(ops) + sizeof...(TArgs), std::end(ops), operands::None{});
            return emit_(prefixes, id, ops);
        }

        template<typename... TArgs> Error emit(ZydisMnemonic id, TArgs&&... args)
        {
            return emit(Instruction::Prefix{}, id, std::forward<TArgs&&>(args)...);
        }

    private:
        Error emit_(Instruction::Prefix prefixes, ZydisMnemonic id, const Instruction::Operands& ops);

    public:
        // Instruction emitter.
        Error adc(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ADC, a, b);
        }
        Error adc(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ADC, a, b);
        }
        Error adc(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_ADC, a, b);
        }
        Error adc(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ADC, a, b);
        }
        Error adc(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_ADC, a, b);
        }
        Error add(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ADD, a, b);
        }
        Error add(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ADD, a, b);
        }
        Error add(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_ADD, a, b);
        }
        Error add(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ADD, a, b);
        }
        Error add(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_ADD, a, b);
        }
        Error and_(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_AND, a, b);
        }
        Error and_(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_AND, a, b);
        }
        Error and_(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_AND, a, b);
        }
        Error and_(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_AND, a, b);
        }
        Error and_(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_AND, a, b);
        }
        Error arpl(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ARPL, a, b);
        }
        Error arpl(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ARPL, a, b);
        }
        Error bound(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BOUND, a, b);
        }
        Error bsf(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BSF, a, b);
        }
        Error bsf(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BSF, a, b);
        }
        Error bsr(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BSR, a, b);
        }
        Error bsr(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BSR, a, b);
        }
        Error bswap(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_BSWAP, a);
        }
        Error bt(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BT, a, b);
        }
        Error bt(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_BT, a, b);
        }
        Error bt(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BT, a, b);
        }
        Error bt(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_BT, a, b);
        }
        Error btc(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BTC, a, b);
        }
        Error btc(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_BTC, a, b);
        }
        Error btc(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BTC, a, b);
        }
        Error btc(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_BTC, a, b);
        }
        Error btr(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BTR, a, b);
        }
        Error btr(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_BTR, a, b);
        }
        Error btr(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BTR, a, b);
        }
        Error btr(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_BTR, a, b);
        }
        Error bts(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BTS, a, b);
        }
        Error bts(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_BTS, a, b);
        }
        Error bts(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BTS, a, b);
        }
        Error bts(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_BTS, a, b);
        }
        Error clc()
        {
            return emit(ZYDIS_MNEMONIC_CLC);
        }
        Error cld()
        {
            return emit(ZYDIS_MNEMONIC_CLD);
        }
        Error cli()
        {
            return emit(ZYDIS_MNEMONIC_CLI);
        }
        Error clts()
        {
            return emit(ZYDIS_MNEMONIC_CLTS);
        }
        Error cmc()
        {
            return emit(ZYDIS_MNEMONIC_CMC);
        }
        Error cmp(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CMP, a, b);
        }
        Error cmp(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CMP, a, b);
        }
        Error cmp(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_CMP, a, b);
        }
        Error cmp(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CMP, a, b);
        }
        Error cmp(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_CMP, a, b);
        }
        Error dec(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_DEC, a);
        }
        Error dec(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_DEC, a);
        }
        Error emms()
        {
            return emit(ZYDIS_MNEMONIC_EMMS);
        }
        Error enter(const operands::Imm& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_ENTER, a, b);
        }
        Error hlt()
        {
            return emit(ZYDIS_MNEMONIC_HLT);
        }
        Error imul(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_IMUL, a, b);
        }
        Error imul(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_IMUL, a, b, c);
        }
        Error imul(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_IMUL, a, b, c);
        }
        Error inc(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_INC, a);
        }
        Error inc(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_INC, a);
        }
        Error insb()
        {
            return emit(ZYDIS_MNEMONIC_INSB);
        }
        Error insw()
        {
            return emit(ZYDIS_MNEMONIC_INSW);
        }
        Error insd()
        {
            return emit(ZYDIS_MNEMONIC_INSD);
        }
        Error int_(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_INT, a);
        }
        Error int3()
        {
            return emit(ZYDIS_MNEMONIC_INT3);
        }
        Error into()
        {
            return emit(ZYDIS_MNEMONIC_INTO);
        }
        Error invd()
        {
            return emit(ZYDIS_MNEMONIC_INVD);
        }
        Error invlpg(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_INVLPG, a);
        }
        Error invpcid(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_INVPCID, a, b);
        }

        Error lar(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_LAR, a, b);
        }
        Error lar(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_LAR, a, b);
        }
        Error ldmxcsr(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_LDMXCSR, a);
        }
        Error lds(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_LDS, a, b);
        }
        Error lea(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_LEA, a, b);
        }
        Error leave()
        {
            return emit(ZYDIS_MNEMONIC_LEAVE);
        }
        Error les(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_LES, a, b);
        }
        Error lfence()
        {
            return emit(ZYDIS_MNEMONIC_LFENCE);
        }
        Error lfs(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_LFS, a, b);
        }
        Error lgdt(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_LGDT, a);
        }
        Error lgs(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_LGS, a, b);
        }
        Error lidt(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_LIDT, a);
        }
        Error lldt(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_LLDT, a);
        }
        Error lldt(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_LLDT, a);
        }
        Error lmsw(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_LMSW, a);
        }
        Error lmsw(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_LMSW, a);
        }
        Error lsl(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_LSL, a, b);
        }
        Error lsl(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_LSL, a, b);
        }
        Error lss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_LSS, a, b);
        }
        Error ltr(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_LTR, a);
        }
        Error ltr(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_LTR, a);
        }
        Error mfence()
        {
            return emit(ZYDIS_MNEMONIC_MFENCE);
        }
        Error mov(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOV, a, b);
        }
        Error mov(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOV, a, b);
        }
        Error mov(const operands::Reg& a, const operands::Label& b)
        {
            return emit(ZYDIS_MNEMONIC_MOV, a, b);
        }
        Error mov(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_MOV, a, b);
        }
        Error mov(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOV, a, b);
        }
        Error mov(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_MOV, a, b);
        }
        Error movnti(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVNTI, a, b);
        }
        Error movsx(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSX, a, b);
        }
        Error movsx(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSX, a, b);
        }
        Error movsxd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSXD, a, b);
        }
        Error movsxd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSXD, a, b);
        }
        Error movzx(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVZX, a, b);
        }
        Error movzx(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVZX, a, b);
        }
        Error neg(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_NEG, a);
        }
        Error neg(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_NEG, a);
        }
        Error nop()
        {
            return emit(ZYDIS_MNEMONIC_NOP);
        }
        Error nop(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_NOP, a);
        }
        Error nop(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_NOP, a);
        }
        Error not_(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_NOT, a);
        }
        Error not_(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_NOT, a);
        }
        Error or_(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_OR, a, b);
        }
        Error or_(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_OR, a, b);
        }
        Error or_(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_OR, a, b);
        }
        Error or_(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_OR, a, b);
        }
        Error or_(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_OR, a, b);
        }
        Error out(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_OUT, a);
        }
        Error out()
        {
            return emit(ZYDIS_MNEMONIC_OUT);
        }
        Error outsb()
        {
            return emit(ZYDIS_MNEMONIC_OUTSB);
        }
        Error outsw()
        {
            return emit(ZYDIS_MNEMONIC_OUTSW);
        }
        Error outsd()
        {
            return emit(ZYDIS_MNEMONIC_OUTSD);
        }
        Error pause()
        {
            return emit(ZYDIS_MNEMONIC_PAUSE);
        }
        Error pop(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_POP, a);
        }
        Error pop(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_POP, a);
        }
        Error popa()
        {
            return emit(ZYDIS_MNEMONIC_POPA);
        }
        Error popad()
        {
            return emit(ZYDIS_MNEMONIC_POPAD);
        }
        Error popf()
        {
            return emit(ZYDIS_MNEMONIC_POPF);
        }
        Error popfd()
        {
            return emit(ZYDIS_MNEMONIC_POPFD);
        }
        Error popfq()
        {
            return emit(ZYDIS_MNEMONIC_POPFQ);
        }
        Error prefetch(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_PREFETCH, a);
        }
        Error prefetchnta(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_PREFETCHNTA, a);
        }
        Error prefetcht0(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_PREFETCHT0, a);
        }
        Error prefetcht1(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_PREFETCHT1, a);
        }
        Error prefetcht2(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_PREFETCHT2, a);
        }
        Error prefetchw(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_PREFETCHW, a);
        }
        Error prefetchwt1(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_PREFETCHWT1, a);
        }
        Error push(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_PUSH, a);
        }
        Error push(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_PUSH, a);
        }
        Error push(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_PUSH, a);
        }
        Error pusha()
        {
            return emit(ZYDIS_MNEMONIC_PUSHA);
        }
        Error pushad()
        {
            return emit(ZYDIS_MNEMONIC_PUSHAD);
        }
        Error pushf()
        {
            return emit(ZYDIS_MNEMONIC_PUSHF);
        }
        Error pushfd()
        {
            return emit(ZYDIS_MNEMONIC_PUSHFD);
        }
        Error pushfq()
        {
            return emit(ZYDIS_MNEMONIC_PUSHFQ);
        }
        Error rcl(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_RCL, a, b);
        }
        Error rcl(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_RCL, a, b);
        }
        Error rcr(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_RCR, a, b);
        }
        Error rcr(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_RCR, a, b);
        }
        Error rol(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_ROL, a, b);
        }
        Error rol(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_ROL, a, b);
        }
        Error ror(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_ROR, a, b);
        }
        Error ror(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_ROR, a, b);
        }
        Error rsm()
        {
            return emit(ZYDIS_MNEMONIC_RSM);
        }
        Error sbb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SBB, a, b);
        }
        Error sbb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SBB, a, b);
        }
        Error sbb(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_SBB, a, b);
        }
        Error sbb(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SBB, a, b);
        }
        Error sbb(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_SBB, a, b);
        }
        Error salc(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_SALC, a);
        }
        Error salc(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_SALC, a);
        }
        Error salc(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_SALC, a, b);
        }
        Error salc(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_SALC, a, b);
        }
        Error sar(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_SAR, a);
        }
        Error sar(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_SAR, a);
        }
        Error sar(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_SAR, a, b);
        }
        Error sar(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_SAR, a, b);
        }
        Error sfence()
        {
            return emit(ZYDIS_MNEMONIC_SFENCE);
        }
        Error sgdt(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_SGDT, a);
        }
        Error shl(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_SHL, a, b);
        }
        Error shl(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_SHL, a, b);
        }
        Error shr(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_SHR, a, b);
        }
        Error shr(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_SHR, a, b);
        }
        Error shld(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SHLD, a, b);
        }
        Error shld(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SHLD, a, b);
        }
        Error shld(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_SHLD, a, b, c);
        }
        Error shld(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_SHLD, a, b, c);
        }
        Error shrd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SHRD, a, b);
        }
        Error shrd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SHRD, a, b);
        }
        Error shrd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_SHRD, a, b, c);
        }
        Error shrd(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_SHRD, a, b, c);
        }
        Error sidt(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_SIDT, a);
        }
        Error sldt(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_SLDT, a);
        }
        Error sldt(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_SLDT, a);
        }
        Error smsw(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_SMSW, a);
        }
        Error smsw(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_SMSW, a);
        }
        Error stc()
        {
            return emit(ZYDIS_MNEMONIC_STC);
        }
        Error std()
        {
            return emit(ZYDIS_MNEMONIC_STD);
        }
        Error sti()
        {
            return emit(ZYDIS_MNEMONIC_STI);
        }
        Error stmxcsr(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_STMXCSR, a);
        }
        Error str(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_STR, a);
        }
        Error str(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_STR, a);
        }
        Error sub(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SUB, a, b);
        }
        Error sub(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SUB, a, b);
        }
        Error sub(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_SUB, a, b);
        }
        Error sub(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SUB, a, b);
        }
        Error sub(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_SUB, a, b);
        }
        Error swapgs()
        {
            return emit(ZYDIS_MNEMONIC_SWAPGS);
        }
        Error test(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_TEST, a, b);
        }
        Error test(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_TEST, a, b);
        }
        Error test(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_TEST, a, b);
        }
        Error test(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_TEST, a, b);
        }
        Error ud2()
        {
            return emit(ZYDIS_MNEMONIC_UD2);
        }
        Error verr(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_VERR, a);
        }
        Error verr(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VERR, a);
        }
        Error verw(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_VERW, a);
        }
        Error verw(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VERW, a);
        }
        Error xadd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_XADD, a, b);
        }
        Error xadd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_XADD, a, b);
        }
        Error xchg(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_XCHG, a, b);
        }
        Error xchg(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_XCHG, a, b);
        }
        Error xchg(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_XCHG, a, b);
        }
        Error xor_(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_XOR, a, b);
        }
        Error xor_(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_XOR, a, b);
        }
        Error xor_(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_XOR, a, b);
        }
        Error xor_(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_XOR, a, b);
        }
        Error xor_(const operands::Mem& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_XOR, a, b);
        }
        Error adcx(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ADCX, a, b);
        }
        Error adcx(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ADCX, a, b);
        }
        Error adox(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ADOX, a, b);
        }
        Error adox(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ADOX, a, b);
        }
        Error andn(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_ANDN, a, b, c);
        }
        Error andn(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_ANDN, a, b, c);
        }
        Error bextr(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_BEXTR, a, b, c);
        }
        Error bextr(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_BEXTR, a, b, c);
        }
        Error blsi(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BLSI, a, b);
        }
        Error blsi(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BLSI, a, b);
        }
        Error blsmsk(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BLSMSK, a, b);
        }
        Error blsmsk(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BLSMSK, a, b);
        }
        Error blsr(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BLSR, a, b);
        }
        Error blsr(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BLSR, a, b);
        }
        Error tzcnt(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_TZCNT, a, b);
        }
        Error tzcnt(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_TZCNT, a, b);
        }
        Error bzhi(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_BZHI, a, b, c);
        }
        Error bzhi(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_BZHI, a, b, c);
        }
        Error pdep(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_PDEP, a, b, c);
        }
        Error pdep(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_PDEP, a, b, c);
        }
        Error pext(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_PEXT, a, b, c);
        }
        Error pext(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_PEXT, a, b, c);
        }
        Error rorx(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_RORX, a, b, c);
        }
        Error rorx(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_RORX, a, b, c);
        }
        Error sarx(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_SARX, a, b, c);
        }
        Error sarx(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_SARX, a, b, c);
        }
        Error shlx(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_SHLX, a, b, c);
        }
        Error shlx(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_SHLX, a, b, c);
        }
        Error shrx(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_SHRX, a, b, c);
        }
        Error shrx(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_SHRX, a, b, c);
        }
        Error cldemote(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_CLDEMOTE, a);
        }
        Error clflush(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_CLFLUSH, a);
        }
        Error clflushopt(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_CLFLUSHOPT, a);
        }
        Error clwb(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_CLWB, a);
        }
        Error crc32(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CRC32, a, b);
        }
        Error crc32(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CRC32, a, b);
        }
        Error enqcmd(const operands::Mem& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ENQCMD, a, b);
        }
        Error enqcmds(const operands::Mem& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ENQCMDS, a, b);
        }
        Error rdfsbase(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_RDFSBASE, a);
        }
        Error rdgsbase(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_RDGSBASE, a);
        }
        Error wrfsbase(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_WRFSBASE, a);
        }
        Error wrgsbase(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_WRGSBASE, a);
        }
        Error fxrstor(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FXRSTOR, a);
        }
        Error fxrstor64(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FXRSTOR64, a);
        }
        Error fxsave(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FXSAVE, a);
        }
        Error fxsave64(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FXSAVE64, a);
        }
        Error llwpcb(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_LLWPCB, a);
        }
        Error lwpins(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_LWPINS, a, b, c);
        }
        Error lwpins(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_LWPINS, a, b, c);
        }
        Error lwpval(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_LWPVAL, a, b, c);
        }
        Error lwpval(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_LWPVAL, a, b, c);
        }
        Error slwpcb(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_SLWPCB, a);
        }
        Error lzcnt(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_LZCNT, a, b);
        }
        Error lzcnt(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_LZCNT, a, b);
        }
        Error movbe(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVBE, a, b);
        }
        Error movbe(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVBE, a, b);
        }
        Error movdiri(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVDIRI, a, b);
        }
        Error movdir64b(const operands::Mem& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVDIR64B, a, b);
        }
        Error bndcl(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BNDCL, a, b);
        }
        Error bndcl(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BNDCL, a, b);
        }
        Error bndcn(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BNDCN, a, b);
        }
        Error bndcn(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BNDCN, a, b);
        }
        Error bndcu(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BNDCU, a, b);
        }
        Error bndcu(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BNDCU, a, b);
        }
        Error bndldx(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BNDLDX, a, b);
        }
        Error bndmk(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BNDMK, a, b);
        }
        Error bndmov(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BNDMOV, a, b);
        }
        Error bndmov(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BNDMOV, a, b);
        }
        Error bndmov(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BNDMOV, a, b);
        }
        Error bndstx(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BNDSTX, a, b);
        }
        Error popcnt(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_POPCNT, a, b);
        }
        Error popcnt(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_POPCNT, a, b);
        }
        Error rdrand(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_RDRAND, a);
        }
        Error rdseed(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_RDSEED, a);
        }
        Error xabort()
        {
            return emit(ZYDIS_MNEMONIC_XABORT);
        }
        Error xbegin(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_XBEGIN, a);
        }
        Error xend()
        {
            return emit(ZYDIS_MNEMONIC_XEND);
        }
        Error xtest()
        {
            return emit(ZYDIS_MNEMONIC_XTEST);
        }
        Error clac()
        {
            return emit(ZYDIS_MNEMONIC_CLAC);
        }
        Error stac()
        {
            return emit(ZYDIS_MNEMONIC_STAC);
        }
        Error clgi()
        {
            return emit(ZYDIS_MNEMONIC_CLGI);
        }
        Error stgi()
        {
            return emit(ZYDIS_MNEMONIC_STGI);
        }
        Error vmmcall()
        {
            return emit(ZYDIS_MNEMONIC_VMMCALL);
        }
        Error blcfill(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BLCFILL, a, b);
        }
        Error blcfill(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BLCFILL, a, b);
        }
        Error blci(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BLCI, a, b);
        }
        Error blci(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BLCI, a, b);
        }
        Error blcic(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BLCIC, a, b);
        }
        Error blcic(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BLCIC, a, b);
        }
        Error blcmsk(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BLCMSK, a, b);
        }
        Error blcmsk(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BLCMSK, a, b);
        }
        Error blcs(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BLCS, a, b);
        }
        Error blcs(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BLCS, a, b);
        }
        Error blsfill(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BLSFILL, a, b);
        }
        Error blsfill(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BLSFILL, a, b);
        }
        Error blsic(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BLSIC, a, b);
        }
        Error blsic(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BLSIC, a, b);
        }
        Error t1mskc(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_T1MSKC, a, b);
        }
        Error t1mskc(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_T1MSKC, a, b);
        }
        Error tzmsk(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_TZMSK, a, b);
        }
        Error tzmsk(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_TZMSK, a, b);
        }
        Error invept(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_INVEPT, a, b);
        }
        Error invvpid(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_INVVPID, a, b);
        }
        Error vmcall()
        {
            return emit(ZYDIS_MNEMONIC_VMCALL);
        }
        Error vmclear(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VMCLEAR, a);
        }
        Error vmfunc()
        {
            return emit(ZYDIS_MNEMONIC_VMFUNC);
        }
        Error vmlaunch()
        {
            return emit(ZYDIS_MNEMONIC_VMLAUNCH);
        }
        Error vmptrld(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VMPTRLD, a);
        }
        Error vmptrst(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VMPTRST, a);
        }
        Error vmread(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMREAD, a, b);
        }
        Error vmresume()
        {
            return emit(ZYDIS_MNEMONIC_VMRESUME);
        }
        Error vmwrite(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMWRITE, a, b);
        }
        Error vmxon(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VMXON, a);
        }
        Error getsec()
        {
            return emit(ZYDIS_MNEMONIC_GETSEC);
        }
        Error rdpid(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_RDPID, a);
        }
        Error f2xm1()
        {
            return emit(ZYDIS_MNEMONIC_F2XM1);
        }
        Error fabs()
        {
            return emit(ZYDIS_MNEMONIC_FABS);
        }
        Error fadd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_FADD, a, b);
        }
        Error fadd(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FADD, a);
        }
        Error faddp(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FADDP, a);
        }
        Error faddp()
        {
            return emit(ZYDIS_MNEMONIC_FADDP);
        }
        Error fbld(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FBLD, a);
        }
        Error fbstp(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FBSTP, a);
        }
        Error fchs()
        {
            return emit(ZYDIS_MNEMONIC_FCHS);
        }
        Error fcmovb(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FCMOVB, a);
        }
        Error fcmovbe(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FCMOVBE, a);
        }
        Error fcmove(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FCMOVE, a);
        }
        Error fcmovnb(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FCMOVNB, a);
        }
        Error fcmovnbe(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FCMOVNBE, a);
        }
        Error fcmovne(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FCMOVNE, a);
        }
        Error fcmovnu(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FCMOVNU, a);
        }
        Error fcmovu(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FCMOVU, a);
        }
        Error fcom(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FCOM, a);
        }
        Error fcom()
        {
            return emit(ZYDIS_MNEMONIC_FCOM);
        }
        Error fcom(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FCOM, a);
        }
        Error fcomp(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FCOMP, a);
        }
        Error fcomp()
        {
            return emit(ZYDIS_MNEMONIC_FCOMP);
        }
        Error fcomp(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FCOMP, a);
        }
        Error fcompp()
        {
            return emit(ZYDIS_MNEMONIC_FCOMPP);
        }
        Error fcomi(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FCOMI, a);
        }
        Error fcomip(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FCOMIP, a);
        }
        Error fcos()
        {
            return emit(ZYDIS_MNEMONIC_FCOS);
        }
        Error fdecstp()
        {
            return emit(ZYDIS_MNEMONIC_FDECSTP);
        }
        Error fdiv(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_FDIV, a, b);
        }
        Error fdiv(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FDIV, a);
        }
        Error fdivp(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FDIVP, a);
        }
        Error fdivp()
        {
            return emit(ZYDIS_MNEMONIC_FDIVP);
        }
        Error fdivr(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_FDIVR, a, b);
        }
        Error fdivr(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FDIVR, a);
        }
        Error fdivrp(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FDIVRP, a);
        }
        Error fdivrp()
        {
            return emit(ZYDIS_MNEMONIC_FDIVRP);
        }
        Error ffree(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FFREE, a);
        }
        Error fiadd(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FIADD, a);
        }
        Error ficom(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FICOM, a);
        }
        Error ficomp(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FICOMP, a);
        }
        Error fidiv(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FIDIV, a);
        }
        Error fidivr(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FIDIVR, a);
        }
        Error fild(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FILD, a);
        }
        Error fimul(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FIMUL, a);
        }
        Error fincstp()
        {
            return emit(ZYDIS_MNEMONIC_FINCSTP);
        }
        Error fisub(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FISUB, a);
        }
        Error fisubr(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FISUBR, a);
        }
        Error fninit()
        {
            return emit(ZYDIS_MNEMONIC_FNINIT);
        }
        Error fist(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FIST, a);
        }
        Error fistp(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FISTP, a);
        }
        Error fisttp(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FISTTP, a);
        }
        Error fld(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FLD, a);
        }
        Error fld(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FLD, a);
        }
        Error fld1()
        {
            return emit(ZYDIS_MNEMONIC_FLD1);
        }
        Error fldl2t()
        {
            return emit(ZYDIS_MNEMONIC_FLDL2T);
        }
        Error fldl2e()
        {
            return emit(ZYDIS_MNEMONIC_FLDL2E);
        }
        Error fldpi()
        {
            return emit(ZYDIS_MNEMONIC_FLDPI);
        }
        Error fldlg2()
        {
            return emit(ZYDIS_MNEMONIC_FLDLG2);
        }
        Error fldln2()
        {
            return emit(ZYDIS_MNEMONIC_FLDLN2);
        }
        Error fldz()
        {
            return emit(ZYDIS_MNEMONIC_FLDZ);
        }
        Error fldcw(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FLDCW, a);
        }
        Error fldenv(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FLDENV, a);
        }
        Error fmul(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_FMUL, a, b);
        }
        Error fmul(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FMUL, a);
        }
        Error fmulp(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FMULP, a);
        }
        Error fmulp()
        {
            return emit(ZYDIS_MNEMONIC_FMULP);
        }
        Error fnclex()
        {
            return emit(ZYDIS_MNEMONIC_FNCLEX);
        }
        Error fnop()
        {
            return emit(ZYDIS_MNEMONIC_FNOP);
        }
        Error fnsave(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FNSAVE, a);
        }
        Error fnstenv(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FNSTENV, a);
        }
        Error fnstcw(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FNSTCW, a);
        }
        Error fpatan()
        {
            return emit(ZYDIS_MNEMONIC_FPATAN);
        }
        Error fprem()
        {
            return emit(ZYDIS_MNEMONIC_FPREM);
        }
        Error fprem1()
        {
            return emit(ZYDIS_MNEMONIC_FPREM1);
        }
        Error fptan()
        {
            return emit(ZYDIS_MNEMONIC_FPTAN);
        }
        Error frndint()
        {
            return emit(ZYDIS_MNEMONIC_FRNDINT);
        }
        Error frstor(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FRSTOR, a);
        }
        Error fscale()
        {
            return emit(ZYDIS_MNEMONIC_FSCALE);
        }
        Error fsin()
        {
            return emit(ZYDIS_MNEMONIC_FSIN);
        }
        Error fsincos()
        {
            return emit(ZYDIS_MNEMONIC_FSINCOS);
        }
        Error fsqrt()
        {
            return emit(ZYDIS_MNEMONIC_FSQRT);
        }
        Error fst(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FST, a);
        }
        Error fst(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FST, a);
        }
        Error fstp(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FSTP, a);
        }
        Error fstp(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FSTP, a);
        }
        Error fsub(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_FSUB, a, b);
        }
        Error fsub(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FSUB, a);
        }
        Error fsubp(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FSUBP, a);
        }
        Error fsubp()
        {
            return emit(ZYDIS_MNEMONIC_FSUBP);
        }
        Error fsubr(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_FSUBR, a, b);
        }
        Error fsubr(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FSUBR, a);
        }
        Error fsubrp(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FSUBRP, a);
        }
        Error fsubrp()
        {
            return emit(ZYDIS_MNEMONIC_FSUBRP);
        }
        Error ftst()
        {
            return emit(ZYDIS_MNEMONIC_FTST);
        }
        Error fucom(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FUCOM, a);
        }
        Error fucom()
        {
            return emit(ZYDIS_MNEMONIC_FUCOM);
        }
        Error fucomi(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FUCOMI, a);
        }
        Error fucomip(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FUCOMIP, a);
        }
        Error fucomp(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FUCOMP, a);
        }
        Error fucomp()
        {
            return emit(ZYDIS_MNEMONIC_FUCOMP);
        }
        Error fucompp()
        {
            return emit(ZYDIS_MNEMONIC_FUCOMPP);
        }
        Error fwait()
        {
            return emit(ZYDIS_MNEMONIC_FWAIT);
        }
        Error fxam()
        {
            return emit(ZYDIS_MNEMONIC_FXAM);
        }
        Error fxch(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FXCH, a);
        }
        Error fxtract()
        {
            return emit(ZYDIS_MNEMONIC_FXTRACT);
        }
        Error fyl2x()
        {
            return emit(ZYDIS_MNEMONIC_FYL2X);
        }
        Error fyl2xp1()
        {
            return emit(ZYDIS_MNEMONIC_FYL2XP1);
        }
        Error fnstsw(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_FNSTSW, a);
        }
        Error fnstsw(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_FNSTSW, a);
        }
        Error addpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ADDPD, a, b);
        }
        Error addpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ADDPD, a, b);
        }
        Error addps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ADDPS, a, b);
        }
        Error addps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ADDPS, a, b);
        }
        Error addsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ADDSD, a, b);
        }
        Error addsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ADDSD, a, b);
        }
        Error addss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ADDSS, a, b);
        }
        Error addss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ADDSS, a, b);
        }
        Error addsubpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ADDSUBPD, a, b);
        }
        Error addsubpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ADDSUBPD, a, b);
        }
        Error addsubps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ADDSUBPS, a, b);
        }
        Error addsubps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ADDSUBPS, a, b);
        }
        Error andnpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ANDNPD, a, b);
        }
        Error andnpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ANDNPD, a, b);
        }
        Error andnps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ANDNPS, a, b);
        }
        Error andnps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ANDNPS, a, b);
        }
        Error andpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ANDPD, a, b);
        }
        Error andpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ANDPD, a, b);
        }
        Error andps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ANDPS, a, b);
        }
        Error andps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ANDPS, a, b);
        }
        Error blendpd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_BLENDPD, a, b, c);
        }
        Error blendpd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_BLENDPD, a, b, c);
        }
        Error blendps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_BLENDPS, a, b, c);
        }
        Error blendps(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_BLENDPS, a, b, c);
        }
        Error cmppd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_CMPPD, a, b, c);
        }
        Error cmppd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_CMPPD, a, b, c);
        }
        Error cmpps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_CMPPS, a, b, c);
        }
        Error cmpps(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_CMPPS, a, b, c);
        }
        Error cmpsd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_CMPSD, a, b, c);
        }
        Error cmpsd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_CMPSD, a, b, c);
        }
        Error cmpss(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_CMPSS, a, b, c);
        }
        Error cmpss(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_CMPSS, a, b, c);
        }
        Error comisd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_COMISD, a, b);
        }
        Error comisd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_COMISD, a, b);
        }
        Error comiss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_COMISS, a, b);
        }
        Error comiss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_COMISS, a, b);
        }
        Error cvtdq2pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTDQ2PD, a, b);
        }
        Error cvtdq2pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTDQ2PD, a, b);
        }
        Error cvtdq2ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTDQ2PS, a, b);
        }
        Error cvtdq2ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTDQ2PS, a, b);
        }
        Error cvtpd2dq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPD2DQ, a, b);
        }
        Error cvtpd2dq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPD2DQ, a, b);
        }
        Error cvtpd2pi(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPD2PI, a, b);
        }
        Error cvtpd2pi(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPD2PI, a, b);
        }
        Error cvtpd2ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPD2PS, a, b);
        }
        Error cvtpd2ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPD2PS, a, b);
        }
        Error cvtpi2pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPI2PD, a, b);
        }
        Error cvtpi2pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPI2PD, a, b);
        }
        Error cvtpi2ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPI2PS, a, b);
        }
        Error cvtpi2ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPI2PS, a, b);
        }
        Error cvtps2dq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPS2DQ, a, b);
        }
        Error cvtps2dq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPS2DQ, a, b);
        }
        Error cvtps2pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPS2PD, a, b);
        }
        Error cvtps2pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPS2PD, a, b);
        }
        Error cvtps2pi(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPS2PI, a, b);
        }
        Error cvtps2pi(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTPS2PI, a, b);
        }
        Error cvtsd2si(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTSD2SI, a, b);
        }
        Error cvtsd2si(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTSD2SI, a, b);
        }
        Error cvtsd2ss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTSD2SS, a, b);
        }
        Error cvtsd2ss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTSD2SS, a, b);
        }
        Error cvtsi2sd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTSI2SD, a, b);
        }
        Error cvtsi2sd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTSI2SD, a, b);
        }
        Error cvtsi2ss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTSI2SS, a, b);
        }
        Error cvtsi2ss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTSI2SS, a, b);
        }
        Error cvtss2sd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTSS2SD, a, b);
        }
        Error cvtss2sd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTSS2SD, a, b);
        }
        Error cvtss2si(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTSS2SI, a, b);
        }
        Error cvtss2si(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTSS2SI, a, b);
        }
        Error cvttpd2pi(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTTPD2PI, a, b);
        }
        Error cvttpd2pi(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTTPD2PI, a, b);
        }
        Error cvttpd2dq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTTPD2DQ, a, b);
        }
        Error cvttpd2dq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTTPD2DQ, a, b);
        }
        Error cvttps2dq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTTPS2DQ, a, b);
        }
        Error cvttps2dq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTTPS2DQ, a, b);
        }
        Error cvttps2pi(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTTPS2PI, a, b);
        }
        Error cvttps2pi(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTTPS2PI, a, b);
        }
        Error cvttsd2si(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTTSD2SI, a, b);
        }
        Error cvttsd2si(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTTSD2SI, a, b);
        }
        Error cvttss2si(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTTSS2SI, a, b);
        }
        Error cvttss2si(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_CVTTSS2SI, a, b);
        }
        Error divpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_DIVPD, a, b);
        }
        Error divpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_DIVPD, a, b);
        }
        Error divps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_DIVPS, a, b);
        }
        Error divps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_DIVPS, a, b);
        }
        Error divsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_DIVSD, a, b);
        }
        Error divsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_DIVSD, a, b);
        }
        Error divss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_DIVSS, a, b);
        }
        Error divss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_DIVSS, a, b);
        }
        Error dppd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_DPPD, a, b, c);
        }
        Error dppd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_DPPD, a, b, c);
        }
        Error dpps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_DPPS, a, b, c);
        }
        Error dpps(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_DPPS, a, b, c);
        }
        Error extractps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_EXTRACTPS, a, b, c);
        }
        Error extractps(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_EXTRACTPS, a, b, c);
        }
        Error extrq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_EXTRQ, a, b);
        }
        Error gf2p8affineinvqb(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_GF2P8AFFINEINVQB, a, b, c);
        }
        Error gf2p8affineinvqb(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_GF2P8AFFINEINVQB, a, b, c);
        }
        Error gf2p8affineqb(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_GF2P8AFFINEQB, a, b, c);
        }
        Error gf2p8affineqb(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_GF2P8AFFINEQB, a, b, c);
        }
        Error gf2p8mulb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_GF2P8MULB, a, b);
        }
        Error gf2p8mulb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_GF2P8MULB, a, b);
        }
        Error haddpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_HADDPD, a, b);
        }
        Error haddpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_HADDPD, a, b);
        }
        Error haddps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_HADDPS, a, b);
        }
        Error haddps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_HADDPS, a, b);
        }
        Error hsubpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_HSUBPD, a, b);
        }
        Error hsubpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_HSUBPD, a, b);
        }
        Error hsubps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_HSUBPS, a, b);
        }
        Error hsubps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_HSUBPS, a, b);
        }
        Error insertps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_INSERTPS, a, b, c);
        }
        Error insertps(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_INSERTPS, a, b, c);
        }
        Error insertq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_INSERTQ, a, b);
        }
        Error lddqu(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_LDDQU, a, b);
        }
        Error maxpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MAXPD, a, b);
        }
        Error maxpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MAXPD, a, b);
        }
        Error maxps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MAXPS, a, b);
        }
        Error maxps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MAXPS, a, b);
        }
        Error maxsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MAXSD, a, b);
        }
        Error maxsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MAXSD, a, b);
        }
        Error maxss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MAXSS, a, b);
        }
        Error maxss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MAXSS, a, b);
        }
        Error minpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MINPD, a, b);
        }
        Error minpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MINPD, a, b);
        }
        Error minps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MINPS, a, b);
        }
        Error minps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MINPS, a, b);
        }
        Error minsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MINSD, a, b);
        }
        Error minsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MINSD, a, b);
        }
        Error minss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MINSS, a, b);
        }
        Error minss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MINSS, a, b);
        }
        Error movapd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVAPD, a, b);
        }
        Error movapd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVAPD, a, b);
        }
        Error movapd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVAPD, a, b);
        }
        Error movaps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVAPS, a, b);
        }
        Error movaps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVAPS, a, b);
        }
        Error movaps(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVAPS, a, b);
        }
        Error movd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVD, a, b);
        }
        Error movd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVD, a, b);
        }
        Error movd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVD, a, b);
        }
        Error movddup(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVDDUP, a, b);
        }
        Error movddup(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVDDUP, a, b);
        }
        Error movdq2q(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVDQ2Q, a, b);
        }
        Error movdqa(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVDQA, a, b);
        }
        Error movdqa(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVDQA, a, b);
        }
        Error movdqa(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVDQA, a, b);
        }
        Error movdqu(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVDQU, a, b);
        }
        Error movdqu(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVDQU, a, b);
        }
        Error movdqu(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVDQU, a, b);
        }
        Error movhlps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVHLPS, a, b);
        }
        Error movhpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVHPD, a, b);
        }
        Error movhpd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVHPD, a, b);
        }
        Error movhps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVHPS, a, b);
        }
        Error movhps(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVHPS, a, b);
        }
        Error movlhps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVLHPS, a, b);
        }
        Error movlpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVLPD, a, b);
        }
        Error movlpd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVLPD, a, b);
        }
        Error movlps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVLPS, a, b);
        }
        Error movlps(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVLPS, a, b);
        }
        Error movmskps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVMSKPS, a, b);
        }
        Error movmskpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVMSKPD, a, b);
        }
        Error movntdq(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVNTDQ, a, b);
        }
        Error movntdqa(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVNTDQA, a, b);
        }
        Error movntpd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVNTPD, a, b);
        }
        Error movntps(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVNTPS, a, b);
        }
        Error movntsd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVNTSD, a, b);
        }
        Error movntss(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVNTSS, a, b);
        }
        Error movntq(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVNTQ, a, b);
        }
        Error movq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVQ, a, b);
        }
        Error movq(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVQ, a, b);
        }
        Error movq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVQ, a, b);
        }
        Error movq2dq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVQ2DQ, a, b);
        }
        Error movsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSD, a, b);
        }
        Error movsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSD, a, b);
        }
        Error movsd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSD, a, b);
        }
        Error movshdup(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSHDUP, a, b);
        }
        Error movshdup(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSHDUP, a, b);
        }
        Error movsldup(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSLDUP, a, b);
        }
        Error movsldup(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSLDUP, a, b);
        }
        Error movss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSS, a, b);
        }
        Error movss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSS, a, b);
        }
        Error movss(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVSS, a, b);
        }
        Error movupd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVUPD, a, b);
        }
        Error movupd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVUPD, a, b);
        }
        Error movupd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVUPD, a, b);
        }
        Error movups(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVUPS, a, b);
        }
        Error movups(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVUPS, a, b);
        }
        Error movups(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MOVUPS, a, b);
        }
        Error mpsadbw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_MPSADBW, a, b, c);
        }
        Error mpsadbw(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_MPSADBW, a, b, c);
        }
        Error mulpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MULPD, a, b);
        }
        Error mulpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MULPD, a, b);
        }
        Error mulps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MULPS, a, b);
        }
        Error mulps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MULPS, a, b);
        }
        Error mulsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MULSD, a, b);
        }
        Error mulsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MULSD, a, b);
        }
        Error mulss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MULSS, a, b);
        }
        Error mulss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_MULSS, a, b);
        }
        Error orpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ORPD, a, b);
        }
        Error orpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ORPD, a, b);
        }
        Error orps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_ORPS, a, b);
        }
        Error orps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_ORPS, a, b);
        }
        Error packssdw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PACKSSDW, a, b);
        }
        Error packssdw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PACKSSDW, a, b);
        }
        Error packsswb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PACKSSWB, a, b);
        }
        Error packsswb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PACKSSWB, a, b);
        }
        Error packusdw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PACKUSDW, a, b);
        }
        Error packusdw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PACKUSDW, a, b);
        }
        Error packuswb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PACKUSWB, a, b);
        }
        Error packuswb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PACKUSWB, a, b);
        }
        Error pabsb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PABSB, a, b);
        }
        Error pabsb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PABSB, a, b);
        }
        Error pabsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PABSD, a, b);
        }
        Error pabsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PABSD, a, b);
        }
        Error pabsw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PABSW, a, b);
        }
        Error pabsw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PABSW, a, b);
        }
        Error paddb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDB, a, b);
        }
        Error paddb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDB, a, b);
        }
        Error paddd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDD, a, b);
        }
        Error paddd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDD, a, b);
        }
        Error paddq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDQ, a, b);
        }
        Error paddq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDQ, a, b);
        }
        Error paddsb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDSB, a, b);
        }
        Error paddsb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDSB, a, b);
        }
        Error paddsw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDSW, a, b);
        }
        Error paddsw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDSW, a, b);
        }
        Error paddusb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDUSB, a, b);
        }
        Error paddusb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDUSB, a, b);
        }
        Error paddusw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDUSW, a, b);
        }
        Error paddusw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDUSW, a, b);
        }
        Error paddw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDW, a, b);
        }
        Error paddw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PADDW, a, b);
        }
        Error palignr(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PALIGNR, a, b, c);
        }
        Error palignr(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PALIGNR, a, b, c);
        }
        Error pand(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PAND, a, b);
        }
        Error pand(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PAND, a, b);
        }
        Error pandn(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PANDN, a, b);
        }
        Error pandn(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PANDN, a, b);
        }
        Error pavgb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PAVGB, a, b);
        }
        Error pavgb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PAVGB, a, b);
        }
        Error pavgw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PAVGW, a, b);
        }
        Error pavgw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PAVGW, a, b);
        }
        Error pblendw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PBLENDW, a, b, c);
        }
        Error pblendw(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PBLENDW, a, b, c);
        }
        Error pclmulqdq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PCLMULQDQ, a, b, c);
        }
        Error pclmulqdq(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PCLMULQDQ, a, b, c);
        }
        Error pcmpeqb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPEQB, a, b);
        }
        Error pcmpeqb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPEQB, a, b);
        }
        Error pcmpeqd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPEQD, a, b);
        }
        Error pcmpeqd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPEQD, a, b);
        }
        Error pcmpeqq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPEQQ, a, b);
        }
        Error pcmpeqq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPEQQ, a, b);
        }
        Error pcmpeqw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPEQW, a, b);
        }
        Error pcmpeqw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPEQW, a, b);
        }
        Error pcmpgtb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPGTB, a, b);
        }
        Error pcmpgtb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPGTB, a, b);
        }
        Error pcmpgtd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPGTD, a, b);
        }
        Error pcmpgtd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPGTD, a, b);
        }
        Error pcmpgtq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPGTQ, a, b);
        }
        Error pcmpgtq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPGTQ, a, b);
        }
        Error pcmpgtw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPGTW, a, b);
        }
        Error pcmpgtw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PCMPGTW, a, b);
        }
        Error pextrb(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PEXTRB, a, b, c);
        }
        Error pextrb(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PEXTRB, a, b, c);
        }
        Error pextrd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PEXTRD, a, b, c);
        }
        Error pextrd(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PEXTRD, a, b, c);
        }
        Error pextrq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PEXTRQ, a, b, c);
        }
        Error pextrq(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PEXTRQ, a, b, c);
        }
        Error pextrw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PEXTRW, a, b, c);
        }
        Error pextrw(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PEXTRW, a, b, c);
        }
        Error phaddd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PHADDD, a, b);
        }
        Error phaddd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PHADDD, a, b);
        }
        Error phaddsw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PHADDSW, a, b);
        }
        Error phaddsw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PHADDSW, a, b);
        }
        Error phaddw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PHADDW, a, b);
        }
        Error phaddw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PHADDW, a, b);
        }
        Error phminposuw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PHMINPOSUW, a, b);
        }
        Error phminposuw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PHMINPOSUW, a, b);
        }
        Error phsubd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PHSUBD, a, b);
        }
        Error phsubd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PHSUBD, a, b);
        }
        Error phsubsw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PHSUBSW, a, b);
        }
        Error phsubsw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PHSUBSW, a, b);
        }
        Error phsubw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PHSUBW, a, b);
        }
        Error phsubw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PHSUBW, a, b);
        }
        Error pinsrb(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PINSRB, a, b, c);
        }
        Error pinsrb(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PINSRB, a, b, c);
        }
        Error pinsrd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PINSRD, a, b, c);
        }
        Error pinsrd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PINSRD, a, b, c);
        }
        Error pinsrq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PINSRQ, a, b, c);
        }
        Error pinsrq(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PINSRQ, a, b, c);
        }
        Error pinsrw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PINSRW, a, b, c);
        }
        Error pinsrw(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PINSRW, a, b, c);
        }
        Error pmaddubsw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMADDUBSW, a, b);
        }
        Error pmaddubsw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMADDUBSW, a, b);
        }
        Error pmaddwd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMADDWD, a, b);
        }
        Error pmaddwd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMADDWD, a, b);
        }
        Error pmaxsb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMAXSB, a, b);
        }
        Error pmaxsb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMAXSB, a, b);
        }
        Error pmaxsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMAXSD, a, b);
        }
        Error pmaxsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMAXSD, a, b);
        }
        Error pmaxsw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMAXSW, a, b);
        }
        Error pmaxsw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMAXSW, a, b);
        }
        Error pmaxub(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMAXUB, a, b);
        }
        Error pmaxub(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMAXUB, a, b);
        }
        Error pmaxud(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMAXUD, a, b);
        }
        Error pmaxud(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMAXUD, a, b);
        }
        Error pmaxuw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMAXUW, a, b);
        }
        Error pmaxuw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMAXUW, a, b);
        }
        Error pminsb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMINSB, a, b);
        }
        Error pminsb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMINSB, a, b);
        }
        Error pminsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMINSD, a, b);
        }
        Error pminsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMINSD, a, b);
        }
        Error pminsw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMINSW, a, b);
        }
        Error pminsw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMINSW, a, b);
        }
        Error pminub(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMINUB, a, b);
        }
        Error pminub(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMINUB, a, b);
        }
        Error pminud(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMINUD, a, b);
        }
        Error pminud(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMINUD, a, b);
        }
        Error pminuw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMINUW, a, b);
        }
        Error pminuw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMINUW, a, b);
        }
        Error pmovmskb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVMSKB, a, b);
        }
        Error pmovsxbd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVSXBD, a, b);
        }
        Error pmovsxbd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVSXBD, a, b);
        }
        Error pmovsxbq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVSXBQ, a, b);
        }
        Error pmovsxbq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVSXBQ, a, b);
        }
        Error pmovsxbw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVSXBW, a, b);
        }
        Error pmovsxbw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVSXBW, a, b);
        }
        Error pmovsxdq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVSXDQ, a, b);
        }
        Error pmovsxdq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVSXDQ, a, b);
        }
        Error pmovsxwd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVSXWD, a, b);
        }
        Error pmovsxwd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVSXWD, a, b);
        }
        Error pmovsxwq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVSXWQ, a, b);
        }
        Error pmovsxwq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVSXWQ, a, b);
        }
        Error pmovzxbd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVZXBD, a, b);
        }
        Error pmovzxbd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVZXBD, a, b);
        }
        Error pmovzxbq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVZXBQ, a, b);
        }
        Error pmovzxbq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVZXBQ, a, b);
        }
        Error pmovzxbw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVZXBW, a, b);
        }
        Error pmovzxbw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVZXBW, a, b);
        }
        Error pmovzxdq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVZXDQ, a, b);
        }
        Error pmovzxdq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVZXDQ, a, b);
        }
        Error pmovzxwd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVZXWD, a, b);
        }
        Error pmovzxwd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVZXWD, a, b);
        }
        Error pmovzxwq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVZXWQ, a, b);
        }
        Error pmovzxwq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMOVZXWQ, a, b);
        }
        Error pmuldq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULDQ, a, b);
        }
        Error pmuldq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULDQ, a, b);
        }
        Error pmulhrsw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULHRSW, a, b);
        }
        Error pmulhrsw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULHRSW, a, b);
        }
        Error pmulhw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULHW, a, b);
        }
        Error pmulhw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULHW, a, b);
        }
        Error pmulhuw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULHUW, a, b);
        }
        Error pmulhuw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULHUW, a, b);
        }
        Error pmulld(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULLD, a, b);
        }
        Error pmulld(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULLD, a, b);
        }
        Error pmullw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULLW, a, b);
        }
        Error pmullw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULLW, a, b);
        }
        Error pmuludq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULUDQ, a, b);
        }
        Error pmuludq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULUDQ, a, b);
        }
        Error por(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_POR, a, b);
        }
        Error por(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_POR, a, b);
        }
        Error psadbw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSADBW, a, b);
        }
        Error psadbw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSADBW, a, b);
        }
        Error pslld(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSLLD, a, b);
        }
        Error pslld(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSLLD, a, b);
        }
        Error pslld(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_PSLLD, a, b);
        }
        Error pslldq(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_PSLLDQ, a, b);
        }
        Error psllq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSLLQ, a, b);
        }
        Error psllq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSLLQ, a, b);
        }
        Error psllq(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_PSLLQ, a, b);
        }
        Error psllw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSLLW, a, b);
        }
        Error psllw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSLLW, a, b);
        }
        Error psllw(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_PSLLW, a, b);
        }
        Error psrad(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRAD, a, b);
        }
        Error psrad(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRAD, a, b);
        }
        Error psrad(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRAD, a, b);
        }
        Error psraw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRAW, a, b);
        }
        Error psraw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRAW, a, b);
        }
        Error psraw(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRAW, a, b);
        }
        Error pshufb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSHUFB, a, b);
        }
        Error pshufb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSHUFB, a, b);
        }
        Error pshufd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PSHUFD, a, b, c);
        }
        Error pshufd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PSHUFD, a, b, c);
        }
        Error pshufhw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PSHUFHW, a, b, c);
        }
        Error pshufhw(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PSHUFHW, a, b, c);
        }
        Error pshuflw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PSHUFLW, a, b, c);
        }
        Error pshuflw(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PSHUFLW, a, b, c);
        }
        Error pshufw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PSHUFW, a, b, c);
        }
        Error pshufw(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PSHUFW, a, b, c);
        }
        Error psignb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSIGNB, a, b);
        }
        Error psignb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSIGNB, a, b);
        }
        Error psignd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSIGND, a, b);
        }
        Error psignd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSIGND, a, b);
        }
        Error psignw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSIGNW, a, b);
        }
        Error psignw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSIGNW, a, b);
        }
        Error psrld(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRLD, a, b);
        }
        Error psrld(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRLD, a, b);
        }
        Error psrld(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRLD, a, b);
        }
        Error psrldq(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRLDQ, a, b);
        }
        Error psrlq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRLQ, a, b);
        }
        Error psrlq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRLQ, a, b);
        }
        Error psrlq(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRLQ, a, b);
        }
        Error psrlw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRLW, a, b);
        }
        Error psrlw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRLW, a, b);
        }
        Error psrlw(const operands::Reg& a, const operands::Imm& b)
        {
            return emit(ZYDIS_MNEMONIC_PSRLW, a, b);
        }
        Error psubb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBB, a, b);
        }
        Error psubb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBB, a, b);
        }
        Error psubd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBD, a, b);
        }
        Error psubd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBD, a, b);
        }
        Error psubq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBQ, a, b);
        }
        Error psubq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBQ, a, b);
        }
        Error psubsb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBSB, a, b);
        }
        Error psubsb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBSB, a, b);
        }
        Error psubsw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBSW, a, b);
        }
        Error psubsw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBSW, a, b);
        }
        Error psubusb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBUSB, a, b);
        }
        Error psubusb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBUSB, a, b);
        }
        Error psubusw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBUSW, a, b);
        }
        Error psubusw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBUSW, a, b);
        }
        Error psubw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBW, a, b);
        }
        Error psubw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSUBW, a, b);
        }
        Error ptest(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PTEST, a, b);
        }
        Error ptest(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PTEST, a, b);
        }
        Error punpckhbw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKHBW, a, b);
        }
        Error punpckhbw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKHBW, a, b);
        }
        Error punpckhdq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKHDQ, a, b);
        }
        Error punpckhdq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKHDQ, a, b);
        }
        Error punpckhqdq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKHQDQ, a, b);
        }
        Error punpckhqdq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKHQDQ, a, b);
        }
        Error punpckhwd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKHWD, a, b);
        }
        Error punpckhwd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKHWD, a, b);
        }
        Error punpcklbw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKLBW, a, b);
        }
        Error punpcklbw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKLBW, a, b);
        }
        Error punpckldq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKLDQ, a, b);
        }
        Error punpckldq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKLDQ, a, b);
        }
        Error punpcklqdq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKLQDQ, a, b);
        }
        Error punpcklqdq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKLQDQ, a, b);
        }
        Error punpcklwd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKLWD, a, b);
        }
        Error punpcklwd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PUNPCKLWD, a, b);
        }
        Error pxor(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PXOR, a, b);
        }
        Error pxor(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PXOR, a, b);
        }
        Error rcpps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_RCPPS, a, b);
        }
        Error rcpps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_RCPPS, a, b);
        }
        Error rcpss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_RCPSS, a, b);
        }
        Error rcpss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_RCPSS, a, b);
        }
        Error roundpd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_ROUNDPD, a, b, c);
        }
        Error roundpd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_ROUNDPD, a, b, c);
        }
        Error roundps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_ROUNDPS, a, b, c);
        }
        Error roundps(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_ROUNDPS, a, b, c);
        }
        Error roundsd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_ROUNDSD, a, b, c);
        }
        Error roundsd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_ROUNDSD, a, b, c);
        }
        Error roundss(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_ROUNDSS, a, b, c);
        }
        Error roundss(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_ROUNDSS, a, b, c);
        }
        Error rsqrtps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_RSQRTPS, a, b);
        }
        Error rsqrtps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_RSQRTPS, a, b);
        }
        Error rsqrtss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_RSQRTSS, a, b);
        }
        Error rsqrtss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_RSQRTSS, a, b);
        }
        Error shufpd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_SHUFPD, a, b, c);
        }
        Error shufpd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_SHUFPD, a, b, c);
        }
        Error shufps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_SHUFPS, a, b, c);
        }
        Error shufps(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_SHUFPS, a, b, c);
        }
        Error sqrtpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SQRTPD, a, b);
        }
        Error sqrtpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SQRTPD, a, b);
        }
        Error sqrtps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SQRTPS, a, b);
        }
        Error sqrtps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SQRTPS, a, b);
        }
        Error sqrtsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SQRTSD, a, b);
        }
        Error sqrtsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SQRTSD, a, b);
        }
        Error sqrtss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SQRTSS, a, b);
        }
        Error sqrtss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SQRTSS, a, b);
        }
        Error subpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SUBPD, a, b);
        }
        Error subpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SUBPD, a, b);
        }
        Error subps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SUBPS, a, b);
        }
        Error subps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SUBPS, a, b);
        }
        Error subsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SUBSD, a, b);
        }
        Error subsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SUBSD, a, b);
        }
        Error subss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SUBSS, a, b);
        }
        Error subss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SUBSS, a, b);
        }
        Error ucomisd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_UCOMISD, a, b);
        }
        Error ucomisd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_UCOMISD, a, b);
        }
        Error ucomiss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_UCOMISS, a, b);
        }
        Error ucomiss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_UCOMISS, a, b);
        }
        Error unpckhpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_UNPCKHPD, a, b);
        }
        Error unpckhpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_UNPCKHPD, a, b);
        }
        Error unpckhps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_UNPCKHPS, a, b);
        }
        Error unpckhps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_UNPCKHPS, a, b);
        }
        Error unpcklpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_UNPCKLPD, a, b);
        }
        Error unpcklpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_UNPCKLPD, a, b);
        }
        Error unpcklps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_UNPCKLPS, a, b);
        }
        Error unpcklps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_UNPCKLPS, a, b);
        }
        Error xorpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_XORPD, a, b);
        }
        Error xorpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_XORPD, a, b);
        }
        Error xorps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_XORPS, a, b);
        }
        Error xorps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_XORPS, a, b);
        }
        Error pavgusb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PAVGUSB, a, b);
        }
        Error pavgusb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PAVGUSB, a, b);
        }
        Error pf2id(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PF2ID, a, b);
        }
        Error pf2id(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PF2ID, a, b);
        }
        Error pf2iw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PF2IW, a, b);
        }
        Error pf2iw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PF2IW, a, b);
        }
        Error pfacc(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFACC, a, b);
        }
        Error pfacc(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFACC, a, b);
        }
        Error pfadd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFADD, a, b);
        }
        Error pfadd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFADD, a, b);
        }
        Error pfcmpeq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFCMPEQ, a, b);
        }
        Error pfcmpeq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFCMPEQ, a, b);
        }
        Error pfcmpge(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFCMPGE, a, b);
        }
        Error pfcmpge(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFCMPGE, a, b);
        }
        Error pfcmpgt(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFCMPGT, a, b);
        }
        Error pfcmpgt(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFCMPGT, a, b);
        }
        Error pfmax(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFMAX, a, b);
        }
        Error pfmax(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFMAX, a, b);
        }
        Error pfmin(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFMIN, a, b);
        }
        Error pfmin(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFMIN, a, b);
        }
        Error pfmul(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFMUL, a, b);
        }
        Error pfmul(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFMUL, a, b);
        }
        Error pfnacc(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFNACC, a, b);
        }
        Error pfnacc(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFNACC, a, b);
        }
        Error pfpnacc(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFPNACC, a, b);
        }
        Error pfpnacc(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFPNACC, a, b);
        }
        Error pfrcp(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFRCP, a, b);
        }
        Error pfrcp(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFRCP, a, b);
        }
        Error pfrcpit2(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFRCPIT2, a, b);
        }
        Error pfrcpit2(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFRCPIT2, a, b);
        }
        Error pfrsqit1(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFRSQIT1, a, b);
        }
        Error pfrsqit1(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFRSQIT1, a, b);
        }
        Error pfsub(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFSUB, a, b);
        }
        Error pfsub(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFSUB, a, b);
        }
        Error pfsubr(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PFSUBR, a, b);
        }
        Error pfsubr(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PFSUBR, a, b);
        }
        Error pi2fd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PI2FD, a, b);
        }
        Error pi2fd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PI2FD, a, b);
        }
        Error pi2fw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PI2FW, a, b);
        }
        Error pi2fw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PI2FW, a, b);
        }
        Error pmulhrw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULHRW, a, b);
        }
        Error pmulhrw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PMULHRW, a, b);
        }
        Error pswapd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PSWAPD, a, b);
        }
        Error pswapd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PSWAPD, a, b);
        }
        Error femms()
        {
            return emit(ZYDIS_MNEMONIC_FEMMS);
        }
        Error aesdec(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_AESDEC, a, b);
        }
        Error aesdec(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_AESDEC, a, b);
        }
        Error aesdeclast(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_AESDECLAST, a, b);
        }
        Error aesdeclast(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_AESDECLAST, a, b);
        }
        Error aesenc(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_AESENC, a, b);
        }
        Error aesenc(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_AESENC, a, b);
        }
        Error aesenclast(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_AESENCLAST, a, b);
        }
        Error aesenclast(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_AESENCLAST, a, b);
        }
        Error aesimc(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_AESIMC, a, b);
        }
        Error aesimc(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_AESIMC, a, b);
        }
        Error aeskeygenassist(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_AESKEYGENASSIST, a, b, c);
        }
        Error aeskeygenassist(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_AESKEYGENASSIST, a, b, c);
        }
        Error sha1msg1(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SHA1MSG1, a, b);
        }
        Error sha1msg1(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SHA1MSG1, a, b);
        }
        Error sha1msg2(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SHA1MSG2, a, b);
        }
        Error sha1msg2(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SHA1MSG2, a, b);
        }
        Error sha1nexte(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SHA1NEXTE, a, b);
        }
        Error sha1nexte(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SHA1NEXTE, a, b);
        }
        Error sha1rnds4(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_SHA1RNDS4, a, b, c);
        }
        Error sha1rnds4(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_SHA1RNDS4, a, b, c);
        }
        Error sha256msg1(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SHA256MSG1, a, b);
        }
        Error sha256msg1(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SHA256MSG1, a, b);
        }
        Error sha256msg2(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SHA256MSG2, a, b);
        }
        Error sha256msg2(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SHA256MSG2, a, b);
        }
        Error kaddb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KADDB, a, b, c);
        }
        Error kaddd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KADDD, a, b, c);
        }
        Error kaddq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KADDQ, a, b, c);
        }
        Error kaddw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KADDW, a, b, c);
        }
        Error kandb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KANDB, a, b, c);
        }
        Error kandd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KANDD, a, b, c);
        }
        Error kandnb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KANDNB, a, b, c);
        }
        Error kandnd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KANDND, a, b, c);
        }
        Error kandnq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KANDNQ, a, b, c);
        }
        Error kandnw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KANDNW, a, b, c);
        }
        Error kandq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KANDQ, a, b, c);
        }
        Error kandw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KANDW, a, b, c);
        }
        Error kmovb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_KMOVB, a, b);
        }
        Error kmovb(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KMOVB, a, b);
        }
        Error kmovb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KMOVB, a, b);
        }
        Error kmovd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_KMOVD, a, b);
        }
        Error kmovd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KMOVD, a, b);
        }
        Error kmovd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KMOVD, a, b);
        }
        Error kmovq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_KMOVQ, a, b);
        }
        Error kmovq(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KMOVQ, a, b);
        }
        Error kmovq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KMOVQ, a, b);
        }
        Error kmovw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_KMOVW, a, b);
        }
        Error kmovw(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KMOVW, a, b);
        }
        Error kmovw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KMOVW, a, b);
        }
        Error knotb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KNOTB, a, b);
        }
        Error knotd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KNOTD, a, b);
        }
        Error knotq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KNOTQ, a, b);
        }
        Error knotw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KNOTW, a, b);
        }
        Error korb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KORB, a, b, c);
        }
        Error kord(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KORD, a, b, c);
        }
        Error korq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KORQ, a, b, c);
        }
        Error kortestb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KORTESTB, a, b);
        }
        Error kortestd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KORTESTD, a, b);
        }
        Error kortestq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KORTESTQ, a, b);
        }
        Error kortestw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KORTESTW, a, b);
        }
        Error korw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KORW, a, b, c);
        }
        Error kshiftlb(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_KSHIFTLB, a, b, c);
        }
        Error kshiftld(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_KSHIFTLD, a, b, c);
        }
        Error kshiftlq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_KSHIFTLQ, a, b, c);
        }
        Error kshiftlw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_KSHIFTLW, a, b, c);
        }
        Error kshiftrb(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_KSHIFTRB, a, b, c);
        }
        Error kshiftrd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_KSHIFTRD, a, b, c);
        }
        Error kshiftrq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_KSHIFTRQ, a, b, c);
        }
        Error kshiftrw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_KSHIFTRW, a, b, c);
        }
        Error ktestb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KTESTB, a, b);
        }
        Error ktestd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KTESTD, a, b);
        }
        Error ktestq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KTESTQ, a, b);
        }
        Error ktestw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_KTESTW, a, b);
        }
        Error kunpckbw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KUNPCKBW, a, b, c);
        }
        Error kunpckdq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KUNPCKDQ, a, b, c);
        }
        Error kunpckwd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KUNPCKWD, a, b, c);
        }
        Error kxnorb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KXNORB, a, b, c);
        }
        Error kxnord(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KXNORD, a, b, c);
        }
        Error kxnorq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KXNORQ, a, b, c);
        }
        Error kxnorw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KXNORW, a, b, c);
        }
        Error kxorb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KXORB, a, b, c);
        }
        Error kxord(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KXORD, a, b, c);
        }
        Error kxorq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KXORQ, a, b, c);
        }
        Error kxorw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_KXORW, a, b, c);
        }
        Error vaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VADDPD, a, b, c);
        }
        Error vaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VADDPD, a, b, c);
        }
        Error vaddps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VADDPS, a, b, c);
        }
        Error vaddps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VADDPS, a, b, c);
        }
        Error vaddsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VADDSD, a, b, c);
        }
        Error vaddsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VADDSD, a, b, c);
        }
        Error vaddss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VADDSS, a, b, c);
        }
        Error vaddss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VADDSS, a, b, c);
        }
        Error vaddsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VADDSUBPD, a, b, c);
        }
        Error vaddsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VADDSUBPD, a, b, c);
        }
        Error vaddsubps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VADDSUBPS, a, b, c);
        }
        Error vaddsubps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VADDSUBPS, a, b, c);
        }
        Error vaesdec(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VAESDEC, a, b, c);
        }
        Error vaesdec(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VAESDEC, a, b, c);
        }
        Error vaesdeclast(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VAESDECLAST, a, b, c);
        }
        Error vaesdeclast(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VAESDECLAST, a, b, c);
        }
        Error vaesenc(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VAESENC, a, b, c);
        }
        Error vaesenc(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VAESENC, a, b, c);
        }
        Error vaesenclast(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VAESENCLAST, a, b, c);
        }
        Error vaesenclast(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VAESENCLAST, a, b, c);
        }
        Error vaesimc(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VAESIMC, a, b);
        }
        Error vaesimc(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VAESIMC, a, b);
        }
        Error vaeskeygenassist(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VAESKEYGENASSIST, a, b, c);
        }
        Error vaeskeygenassist(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VAESKEYGENASSIST, a, b, c);
        }
        Error valignd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VALIGND, a, b, c, d);
        }
        Error valignd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VALIGND, a, b, c, d);
        }
        Error valignq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VALIGNQ, a, b, c, d);
        }
        Error valignq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VALIGNQ, a, b, c, d);
        }
        Error vandnpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VANDNPD, a, b, c);
        }
        Error vandnpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VANDNPD, a, b, c);
        }
        Error vandnps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VANDNPS, a, b, c);
        }
        Error vandnps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VANDNPS, a, b, c);
        }
        Error vandpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VANDPD, a, b, c);
        }
        Error vandpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VANDPD, a, b, c);
        }
        Error vandps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VANDPS, a, b, c);
        }
        Error vandps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VANDPS, a, b, c);
        }
        Error vblendmpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VBLENDMPD, a, b, c);
        }
        Error vblendmpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VBLENDMPD, a, b, c);
        }
        Error vblendmps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VBLENDMPS, a, b, c);
        }
        Error vblendmps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VBLENDMPS, a, b, c);
        }
        Error vblendpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VBLENDPD, a, b, c, d);
        }
        Error vblendpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VBLENDPD, a, b, c, d);
        }
        Error vblendps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VBLENDPS, a, b, c, d);
        }
        Error vblendps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VBLENDPS, a, b, c, d);
        }
        Error vblendvpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VBLENDVPD, a, b, c, d);
        }
        Error vblendvpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VBLENDVPD, a, b, c, d);
        }
        Error vblendvps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VBLENDVPS, a, b, c, d);
        }
        Error vblendvps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VBLENDVPS, a, b, c, d);
        }
        Error vbroadcastf128(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTF128, a, b);
        }
        Error vbroadcastf32x2(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTF32X2, a, b);
        }
        Error vbroadcastf32x2(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTF32X2, a, b);
        }
        Error vbroadcastf32x4(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTF32X4, a, b);
        }
        Error vbroadcastf32x8(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTF32X8, a, b);
        }
        Error vbroadcastf64x2(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTF64X2, a, b);
        }
        Error vbroadcastf64x4(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTF64X4, a, b);
        }
        Error vbroadcasti128(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTI128, a, b);
        }
        Error vbroadcasti32x2(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTI32X2, a, b);
        }
        Error vbroadcasti32x2(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTI32X2, a, b);
        }
        Error vbroadcasti32x4(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTI32X4, a, b);
        }
        Error vbroadcasti32x8(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTI32X8, a, b);
        }
        Error vbroadcasti64x2(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTI64X2, a, b);
        }
        Error vbroadcasti64x2(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTI64X2, a, b);
        }
        Error vbroadcasti64x4(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTI64X4, a, b);
        }
        Error vbroadcasti64x4(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTI64X4, a, b);
        }
        Error vbroadcastsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTSD, a, b);
        }
        Error vbroadcastsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTSD, a, b);
        }
        Error vbroadcastss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTSS, a, b);
        }
        Error vbroadcastss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VBROADCASTSS, a, b);
        }
        Error vcmppd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VCMPPD, a, b, c, d);
        }
        Error vcmppd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VCMPPD, a, b, c, d);
        }
        Error vcmpps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VCMPPS, a, b, c, d);
        }
        Error vcmpps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VCMPPS, a, b, c, d);
        }
        Error vcmpsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VCMPSD, a, b, c, d);
        }
        Error vcmpsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VCMPSD, a, b, c, d);
        }
        Error vcmpss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VCMPSS, a, b, c, d);
        }
        Error vcmpss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VCMPSS, a, b, c, d);
        }
        Error vcomisd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCOMISD, a, b);
        }
        Error vcomisd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCOMISD, a, b);
        }
        Error vcomiss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCOMISS, a, b);
        }
        Error vcomiss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCOMISS, a, b);
        }
        Error vcompresspd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCOMPRESSPD, a, b);
        }
        Error vcompresspd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCOMPRESSPD, a, b);
        }
        Error vcompressps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCOMPRESSPS, a, b);
        }
        Error vcompressps(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCOMPRESSPS, a, b);
        }
        Error vcvtdq2pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTDQ2PD, a, b);
        }
        Error vcvtdq2pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTDQ2PD, a, b);
        }
        Error vcvtdq2ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTDQ2PS, a, b);
        }
        Error vcvtdq2ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTDQ2PS, a, b);
        }
        Error vcvtne2ps2bf16(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTNE2PS2BF16, a, b, c);
        }
        Error vcvtne2ps2bf16(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTNE2PS2BF16, a, b, c);
        }
        Error vcvtneps2bf16(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTNEPS2BF16, a, b);
        }
        Error vcvtneps2bf16(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTNEPS2BF16, a, b);
        }
        Error vcvtpd2dq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPD2DQ, a, b);
        }
        Error vcvtpd2dq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPD2DQ, a, b);
        }
        Error vcvtpd2ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPD2PS, a, b);
        }
        Error vcvtpd2ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPD2PS, a, b);
        }
        Error vcvtpd2qq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPD2QQ, a, b);
        }
        Error vcvtpd2qq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPD2QQ, a, b);
        }
        Error vcvtpd2udq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPD2UDQ, a, b);
        }
        Error vcvtpd2udq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPD2UDQ, a, b);
        }
        Error vcvtpd2uqq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPD2UQQ, a, b);
        }
        Error vcvtpd2uqq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPD2UQQ, a, b);
        }
        Error vcvtph2ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPH2PS, a, b);
        }
        Error vcvtph2ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPH2PS, a, b);
        }
        Error vcvtps2dq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPS2DQ, a, b);
        }
        Error vcvtps2dq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPS2DQ, a, b);
        }
        Error vcvtps2pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPS2PD, a, b);
        }
        Error vcvtps2pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPS2PD, a, b);
        }
        Error vcvtps2ph(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPS2PH, a, b, c);
        }
        Error vcvtps2ph(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPS2PH, a, b, c);
        }
        Error vcvtps2qq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPS2QQ, a, b);
        }
        Error vcvtps2qq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPS2QQ, a, b);
        }
        Error vcvtps2udq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPS2UDQ, a, b);
        }
        Error vcvtps2udq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPS2UDQ, a, b);
        }
        Error vcvtps2uqq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPS2UQQ, a, b);
        }
        Error vcvtps2uqq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTPS2UQQ, a, b);
        }
        Error vcvtqq2pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTQQ2PD, a, b);
        }
        Error vcvtqq2pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTQQ2PD, a, b);
        }
        Error vcvtqq2ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTQQ2PS, a, b);
        }
        Error vcvtqq2ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTQQ2PS, a, b);
        }
        Error vcvtsd2si(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSD2SI, a, b);
        }
        Error vcvtsd2si(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSD2SI, a, b);
        }
        Error vcvtsd2ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSD2SS, a, b, c);
        }
        Error vcvtsd2ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSD2SS, a, b, c);
        }
        Error vcvtsd2usi(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSD2USI, a, b);
        }
        Error vcvtsd2usi(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSD2USI, a, b);
        }
        Error vcvtsi2sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSI2SD, a, b, c);
        }
        Error vcvtsi2sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSI2SD, a, b, c);
        }
        Error vcvtsi2ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSI2SS, a, b, c);
        }
        Error vcvtsi2ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSI2SS, a, b, c);
        }
        Error vcvtss2sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSS2SD, a, b, c);
        }
        Error vcvtss2sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSS2SD, a, b, c);
        }
        Error vcvtss2si(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSS2SI, a, b);
        }
        Error vcvtss2si(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSS2SI, a, b);
        }
        Error vcvtss2usi(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSS2USI, a, b);
        }
        Error vcvtss2usi(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTSS2USI, a, b);
        }
        Error vcvttpd2dq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPD2DQ, a, b);
        }
        Error vcvttpd2dq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPD2DQ, a, b);
        }
        Error vcvttpd2qq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPD2QQ, a, b);
        }
        Error vcvttpd2qq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPD2QQ, a, b);
        }
        Error vcvttpd2udq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPD2UDQ, a, b);
        }
        Error vcvttpd2udq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPD2UDQ, a, b);
        }
        Error vcvttpd2uqq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPD2UQQ, a, b);
        }
        Error vcvttpd2uqq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPD2UQQ, a, b);
        }
        Error vcvttps2dq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPS2DQ, a, b);
        }
        Error vcvttps2dq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPS2DQ, a, b);
        }
        Error vcvttps2qq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPS2QQ, a, b);
        }
        Error vcvttps2qq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPS2QQ, a, b);
        }
        Error vcvttps2udq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPS2UDQ, a, b);
        }
        Error vcvttps2udq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPS2UDQ, a, b);
        }
        Error vcvttps2uqq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPS2UQQ, a, b);
        }
        Error vcvttps2uqq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTPS2UQQ, a, b);
        }
        Error vcvttsd2si(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTSD2SI, a, b);
        }
        Error vcvttsd2si(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTSD2SI, a, b);
        }
        Error vcvttsd2usi(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTSD2USI, a, b);
        }
        Error vcvttsd2usi(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTSD2USI, a, b);
        }
        Error vcvttss2si(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTSS2SI, a, b);
        }
        Error vcvttss2si(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTSS2SI, a, b);
        }
        Error vcvttss2usi(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTSS2USI, a, b);
        }
        Error vcvttss2usi(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTTSS2USI, a, b);
        }
        Error vcvtudq2pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTUDQ2PD, a, b);
        }
        Error vcvtudq2pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTUDQ2PD, a, b);
        }
        Error vcvtudq2ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTUDQ2PS, a, b);
        }
        Error vcvtudq2ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTUDQ2PS, a, b);
        }
        Error vcvtuqq2pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTUQQ2PD, a, b);
        }
        Error vcvtuqq2pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTUQQ2PD, a, b);
        }
        Error vcvtuqq2ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTUQQ2PS, a, b);
        }
        Error vcvtuqq2ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VCVTUQQ2PS, a, b);
        }
        Error vcvtusi2sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTUSI2SD, a, b, c);
        }
        Error vcvtusi2sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTUSI2SD, a, b, c);
        }
        Error vcvtusi2ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTUSI2SS, a, b, c);
        }
        Error vcvtusi2ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VCVTUSI2SS, a, b, c);
        }
        Error vdbpsadbw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VDBPSADBW, a, b, c, d);
        }
        Error vdbpsadbw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VDBPSADBW, a, b, c, d);
        }
        Error vdivpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VDIVPD, a, b, c);
        }
        Error vdivpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VDIVPD, a, b, c);
        }
        Error vdivps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VDIVPS, a, b, c);
        }
        Error vdivps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VDIVPS, a, b, c);
        }
        Error vdivsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VDIVSD, a, b, c);
        }
        Error vdivsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VDIVSD, a, b, c);
        }
        Error vdivss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VDIVSS, a, b, c);
        }
        Error vdivss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VDIVSS, a, b, c);
        }
        Error vdpbf16ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VDPBF16PS, a, b, c);
        }
        Error vdpbf16ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VDPBF16PS, a, b, c);
        }
        Error vdppd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VDPPD, a, b, c, d);
        }
        Error vdppd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VDPPD, a, b, c, d);
        }
        Error vdpps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VDPPS, a, b, c, d);
        }
        Error vdpps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VDPPS, a, b, c, d);
        }
        Error vexp2pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VEXP2PD, a, b);
        }
        Error vexp2pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VEXP2PD, a, b);
        }
        Error vexp2ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VEXP2PS, a, b);
        }
        Error vexp2ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VEXP2PS, a, b);
        }
        Error vexpandpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VEXPANDPD, a, b);
        }
        Error vexpandpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VEXPANDPD, a, b);
        }
        Error vexpandps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VEXPANDPS, a, b);
        }
        Error vexpandps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VEXPANDPS, a, b);
        }
        Error vextractf128(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTF128, a, b, c);
        }
        Error vextractf128(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTF128, a, b, c);
        }
        Error vextractf32x4(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTF32X4, a, b, c);
        }
        Error vextractf32x4(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTF32X4, a, b, c);
        }
        Error vextractf32x8(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTF32X8, a, b, c);
        }
        Error vextractf32x8(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTF32X8, a, b, c);
        }
        Error vextractf64x2(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTF64X2, a, b, c);
        }
        Error vextractf64x2(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTF64X2, a, b, c);
        }
        Error vextractf64x4(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTF64X4, a, b, c);
        }
        Error vextractf64x4(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTF64X4, a, b, c);
        }
        Error vextracti128(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTI128, a, b, c);
        }
        Error vextracti128(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTI128, a, b, c);
        }
        Error vextracti32x4(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTI32X4, a, b, c);
        }
        Error vextracti32x4(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTI32X4, a, b, c);
        }
        Error vextracti32x8(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTI32X8, a, b, c);
        }
        Error vextracti32x8(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTI32X8, a, b, c);
        }
        Error vextracti64x2(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTI64X2, a, b, c);
        }
        Error vextracti64x2(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTI64X2, a, b, c);
        }
        Error vextracti64x4(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTI64X4, a, b, c);
        }
        Error vextracti64x4(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTI64X4, a, b, c);
        }
        Error vextractps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTPS, a, b, c);
        }
        Error vextractps(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VEXTRACTPS, a, b, c);
        }
        Error vfmadd132pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD132PD, a, b, c);
        }
        Error vfmadd132pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD132PD, a, b, c);
        }
        Error vfmadd132ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD132PS, a, b, c);
        }
        Error vfmadd132ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD132PS, a, b, c);
        }
        Error vfmadd132sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD132SD, a, b, c);
        }
        Error vfmadd132sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD132SD, a, b, c);
        }
        Error vfmadd132ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD132SS, a, b, c);
        }
        Error vfmadd132ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD132SS, a, b, c);
        }
        Error vfmadd213pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD213PD, a, b, c);
        }
        Error vfmadd213pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD213PD, a, b, c);
        }
        Error vfmadd213ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD213PS, a, b, c);
        }
        Error vfmadd213ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD213PS, a, b, c);
        }
        Error vfmadd213sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD213SD, a, b, c);
        }
        Error vfmadd213sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD213SD, a, b, c);
        }
        Error vfmadd213ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD213SS, a, b, c);
        }
        Error vfmadd213ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD213SS, a, b, c);
        }
        Error vfmadd231pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD231PD, a, b, c);
        }
        Error vfmadd231pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD231PD, a, b, c);
        }
        Error vfmadd231ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD231PS, a, b, c);
        }
        Error vfmadd231ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD231PS, a, b, c);
        }
        Error vfmadd231sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD231SD, a, b, c);
        }
        Error vfmadd231sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD231SD, a, b, c);
        }
        Error vfmadd231ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD231SS, a, b, c);
        }
        Error vfmadd231ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADD231SS, a, b, c);
        }
        Error vfmaddsub132pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUB132PD, a, b, c);
        }
        Error vfmaddsub132pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUB132PD, a, b, c);
        }
        Error vfmaddsub132ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUB132PS, a, b, c);
        }
        Error vfmaddsub132ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUB132PS, a, b, c);
        }
        Error vfmaddsub213pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUB213PD, a, b, c);
        }
        Error vfmaddsub213pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUB213PD, a, b, c);
        }
        Error vfmaddsub213ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUB213PS, a, b, c);
        }
        Error vfmaddsub213ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUB213PS, a, b, c);
        }
        Error vfmaddsub231pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUB231PD, a, b, c);
        }
        Error vfmaddsub231pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUB231PD, a, b, c);
        }
        Error vfmaddsub231ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUB231PS, a, b, c);
        }
        Error vfmaddsub231ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUB231PS, a, b, c);
        }
        Error vfmsub132pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB132PD, a, b, c);
        }
        Error vfmsub132pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB132PD, a, b, c);
        }
        Error vfmsub132ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB132PS, a, b, c);
        }
        Error vfmsub132ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB132PS, a, b, c);
        }
        Error vfmsub132sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB132SD, a, b, c);
        }
        Error vfmsub132sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB132SD, a, b, c);
        }
        Error vfmsub132ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB132SS, a, b, c);
        }
        Error vfmsub132ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB132SS, a, b, c);
        }
        Error vfmsub213pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB213PD, a, b, c);
        }
        Error vfmsub213pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB213PD, a, b, c);
        }
        Error vfmsub213ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB213PS, a, b, c);
        }
        Error vfmsub213ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB213PS, a, b, c);
        }
        Error vfmsub213sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB213SD, a, b, c);
        }
        Error vfmsub213sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB213SD, a, b, c);
        }
        Error vfmsub213ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB213SS, a, b, c);
        }
        Error vfmsub213ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB213SS, a, b, c);
        }
        Error vfmsub231pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB231PD, a, b, c);
        }
        Error vfmsub231pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB231PD, a, b, c);
        }
        Error vfmsub231ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB231PS, a, b, c);
        }
        Error vfmsub231ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB231PS, a, b, c);
        }
        Error vfmsub231sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB231SD, a, b, c);
        }
        Error vfmsub231sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB231SD, a, b, c);
        }
        Error vfmsub231ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB231SS, a, b, c);
        }
        Error vfmsub231ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUB231SS, a, b, c);
        }
        Error vfmsubadd132pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADD132PD, a, b, c);
        }
        Error vfmsubadd132pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADD132PD, a, b, c);
        }
        Error vfmsubadd132ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADD132PS, a, b, c);
        }
        Error vfmsubadd132ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADD132PS, a, b, c);
        }
        Error vfmsubadd213pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADD213PD, a, b, c);
        }
        Error vfmsubadd213pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADD213PD, a, b, c);
        }
        Error vfmsubadd213ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADD213PS, a, b, c);
        }
        Error vfmsubadd213ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADD213PS, a, b, c);
        }
        Error vfmsubadd231pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADD231PD, a, b, c);
        }
        Error vfmsubadd231pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADD231PD, a, b, c);
        }
        Error vfmsubadd231ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADD231PS, a, b, c);
        }
        Error vfmsubadd231ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADD231PS, a, b, c);
        }
        Error vfnmadd132pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD132PD, a, b, c);
        }
        Error vfnmadd132pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD132PD, a, b, c);
        }
        Error vfnmadd132ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD132PS, a, b, c);
        }
        Error vfnmadd132ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD132PS, a, b, c);
        }
        Error vfnmadd132sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD132SD, a, b, c);
        }
        Error vfnmadd132sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD132SD, a, b, c);
        }
        Error vfnmadd132ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD132SS, a, b, c);
        }
        Error vfnmadd132ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD132SS, a, b, c);
        }
        Error vfnmadd213pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD213PD, a, b, c);
        }
        Error vfnmadd213pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD213PD, a, b, c);
        }
        Error vfnmadd213ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD213PS, a, b, c);
        }
        Error vfnmadd213ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD213PS, a, b, c);
        }
        Error vfnmadd213sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD213SD, a, b, c);
        }
        Error vfnmadd213sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD213SD, a, b, c);
        }
        Error vfnmadd213ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD213SS, a, b, c);
        }
        Error vfnmadd213ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD213SS, a, b, c);
        }
        Error vfnmadd231pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD231PD, a, b, c);
        }
        Error vfnmadd231pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD231PD, a, b, c);
        }
        Error vfnmadd231ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD231PS, a, b, c);
        }
        Error vfnmadd231ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD231PS, a, b, c);
        }
        Error vfnmadd231sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD231SD, a, b, c);
        }
        Error vfnmadd231sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD231SD, a, b, c);
        }
        Error vfnmadd231ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD231SS, a, b, c);
        }
        Error vfnmadd231ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADD231SS, a, b, c);
        }
        Error vfnmsub132pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB132PD, a, b, c);
        }
        Error vfnmsub132pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB132PD, a, b, c);
        }
        Error vfnmsub132ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB132PS, a, b, c);
        }
        Error vfnmsub132ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB132PS, a, b, c);
        }
        Error vfnmsub132sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB132SD, a, b, c);
        }
        Error vfnmsub132sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB132SD, a, b, c);
        }
        Error vfnmsub132ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB132SS, a, b, c);
        }
        Error vfnmsub132ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB132SS, a, b, c);
        }
        Error vfnmsub213pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB213PD, a, b, c);
        }
        Error vfnmsub213pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB213PD, a, b, c);
        }
        Error vfnmsub213ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB213PS, a, b, c);
        }
        Error vfnmsub213ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB213PS, a, b, c);
        }
        Error vfnmsub213sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB213SD, a, b, c);
        }
        Error vfnmsub213sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB213SD, a, b, c);
        }
        Error vfnmsub213ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB213SS, a, b, c);
        }
        Error vfnmsub213ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB213SS, a, b, c);
        }
        Error vfnmsub231pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB231PD, a, b, c);
        }
        Error vfnmsub231pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB231PD, a, b, c);
        }
        Error vfnmsub231ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB231PS, a, b, c);
        }
        Error vfnmsub231ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB231PS, a, b, c);
        }
        Error vfnmsub231sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB231SD, a, b, c);
        }
        Error vfnmsub231sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB231SD, a, b, c);
        }
        Error vfnmsub231ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB231SS, a, b, c);
        }
        Error vfnmsub231ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUB231SS, a, b, c);
        }
        Error vfpclasspd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VFPCLASSPD, a, b, c);
        }
        Error vfpclasspd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VFPCLASSPD, a, b, c);
        }
        Error vfpclassps(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VFPCLASSPS, a, b, c);
        }
        Error vfpclassps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VFPCLASSPS, a, b, c);
        }
        Error vfpclasssd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VFPCLASSSD, a, b, c);
        }
        Error vfpclasssd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VFPCLASSSD, a, b, c);
        }
        Error vfpclassss(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VFPCLASSSS, a, b, c);
        }
        Error vfpclassss(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VFPCLASSSS, a, b, c);
        }
        Error vgatherdpd(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERDPD, a, b, c);
        }
        Error vgatherdpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERDPD, a, b);
        }
        Error vgatherdps(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERDPS, a, b, c);
        }
        Error vgatherdps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERDPS, a, b);
        }
        Error vgatherpf0dpd(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERPF0DPD, a);
        }
        Error vgatherpf0dps(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERPF0DPS, a);
        }
        Error vgatherpf0qpd(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERPF0QPD, a);
        }
        Error vgatherpf0qps(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERPF0QPS, a);
        }
        Error vgatherpf1dpd(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERPF1DPD, a);
        }
        Error vgatherpf1dps(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERPF1DPS, a);
        }
        Error vgatherpf1qpd(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERPF1QPD, a);
        }
        Error vgatherpf1qps(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERPF1QPS, a);
        }
        Error vgatherqpd(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERQPD, a, b, c);
        }
        Error vgatherqpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERQPD, a, b);
        }
        Error vgatherqps(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERQPS, a, b, c);
        }
        Error vgatherqps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VGATHERQPS, a, b);
        }
        Error vgetexppd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VGETEXPPD, a, b);
        }
        Error vgetexppd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VGETEXPPD, a, b);
        }
        Error vgetexpps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VGETEXPPS, a, b);
        }
        Error vgetexpps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VGETEXPPS, a, b);
        }
        Error vgetexpsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VGETEXPSD, a, b, c);
        }
        Error vgetexpsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VGETEXPSD, a, b, c);
        }
        Error vgetexpss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VGETEXPSS, a, b, c);
        }
        Error vgetexpss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VGETEXPSS, a, b, c);
        }
        Error vgetmantpd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VGETMANTPD, a, b, c);
        }
        Error vgetmantpd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VGETMANTPD, a, b, c);
        }
        Error vgetmantps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VGETMANTPS, a, b, c);
        }
        Error vgetmantps(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VGETMANTPS, a, b, c);
        }
        Error vgetmantsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VGETMANTSD, a, b, c, d);
        }
        Error vgetmantsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VGETMANTSD, a, b, c, d);
        }
        Error vgetmantss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VGETMANTSS, a, b, c, d);
        }
        Error vgetmantss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VGETMANTSS, a, b, c, d);
        }
        Error vgf2p8affineinvqb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VGF2P8AFFINEINVQB, a, b, c, d);
        }
        Error vgf2p8affineinvqb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VGF2P8AFFINEINVQB, a, b, c, d);
        }
        Error vgf2p8affineqb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VGF2P8AFFINEQB, a, b, c, d);
        }
        Error vgf2p8affineqb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VGF2P8AFFINEQB, a, b, c, d);
        }
        Error vgf2p8mulb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VGF2P8MULB, a, b, c);
        }
        Error vgf2p8mulb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VGF2P8MULB, a, b, c);
        }
        Error vhaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VHADDPD, a, b, c);
        }
        Error vhaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VHADDPD, a, b, c);
        }
        Error vhaddps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VHADDPS, a, b, c);
        }
        Error vhaddps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VHADDPS, a, b, c);
        }
        Error vhsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VHSUBPD, a, b, c);
        }
        Error vhsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VHSUBPD, a, b, c);
        }
        Error vhsubps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VHSUBPS, a, b, c);
        }
        Error vhsubps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VHSUBPS, a, b, c);
        }
        Error vinsertf128(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTF128, a, b, c, d);
        }
        Error vinsertf128(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTF128, a, b, c, d);
        }
        Error vinsertf32x4(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTF32X4, a, b, c, d);
        }
        Error vinsertf32x4(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTF32X4, a, b, c, d);
        }
        Error vinsertf32x8(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTF32X8, a, b, c, d);
        }
        Error vinsertf32x8(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTF32X8, a, b, c, d);
        }
        Error vinsertf64x2(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTF64X2, a, b, c, d);
        }
        Error vinsertf64x2(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTF64X2, a, b, c, d);
        }
        Error vinsertf64x4(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTF64X4, a, b, c, d);
        }
        Error vinsertf64x4(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTF64X4, a, b, c, d);
        }
        Error vinserti128(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTI128, a, b, c, d);
        }
        Error vinserti128(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTI128, a, b, c, d);
        }
        Error vinserti32x4(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTI32X4, a, b, c, d);
        }
        Error vinserti32x4(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTI32X4, a, b, c, d);
        }
        Error vinserti32x8(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTI32X8, a, b, c, d);
        }
        Error vinserti32x8(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTI32X8, a, b, c, d);
        }
        Error vinserti64x2(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTI64X2, a, b, c, d);
        }
        Error vinserti64x2(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTI64X2, a, b, c, d);
        }
        Error vinserti64x4(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTI64X4, a, b, c, d);
        }
        Error vinserti64x4(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTI64X4, a, b, c, d);
        }
        Error vinsertps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTPS, a, b, c, d);
        }
        Error vinsertps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VINSERTPS, a, b, c, d);
        }
        Error vlddqu(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VLDDQU, a, b);
        }
        Error vldmxcsr(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VLDMXCSR, a);
        }
        Error vmaskmovpd(const operands::Mem& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMASKMOVPD, a, b, c);
        }
        Error vmaskmovpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMASKMOVPD, a, b, c);
        }
        Error vmaskmovps(const operands::Mem& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMASKMOVPS, a, b, c);
        }
        Error vmaskmovps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMASKMOVPS, a, b, c);
        }
        Error vmaxpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMAXPD, a, b, c);
        }
        Error vmaxpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMAXPD, a, b, c);
        }
        Error vmaxps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMAXPS, a, b, c);
        }
        Error vmaxps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMAXPS, a, b, c);
        }
        Error vmaxsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMAXSD, a, b, c);
        }
        Error vmaxsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMAXSD, a, b, c);
        }
        Error vmaxss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMAXSS, a, b, c);
        }
        Error vmaxss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMAXSS, a, b, c);
        }
        Error vminpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMINPD, a, b, c);
        }
        Error vminpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMINPD, a, b, c);
        }
        Error vminps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMINPS, a, b, c);
        }
        Error vminps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMINPS, a, b, c);
        }
        Error vminsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMINSD, a, b, c);
        }
        Error vminsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMINSD, a, b, c);
        }
        Error vminss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMINSS, a, b, c);
        }
        Error vminss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMINSS, a, b, c);
        }
        Error vmovapd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVAPD, a, b);
        }
        Error vmovapd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVAPD, a, b);
        }
        Error vmovapd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVAPD, a, b);
        }
        Error vmovaps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVAPS, a, b);
        }
        Error vmovaps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVAPS, a, b);
        }
        Error vmovaps(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVAPS, a, b);
        }
        Error vmovd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVD, a, b);
        }
        Error vmovd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVD, a, b);
        }
        Error vmovd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVD, a, b);
        }
        Error vmovddup(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDDUP, a, b);
        }
        Error vmovddup(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDDUP, a, b);
        }
        Error vmovdqa(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQA, a, b);
        }
        Error vmovdqa(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQA, a, b);
        }
        Error vmovdqa(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQA, a, b);
        }
        Error vmovdqa32(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQA32, a, b);
        }
        Error vmovdqa32(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQA32, a, b);
        }
        Error vmovdqa32(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQA32, a, b);
        }
        Error vmovdqa64(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQA64, a, b);
        }
        Error vmovdqa64(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQA64, a, b);
        }
        Error vmovdqa64(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQA64, a, b);
        }
        Error vmovdqu(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU, a, b);
        }
        Error vmovdqu(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU, a, b);
        }
        Error vmovdqu(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU, a, b);
        }
        Error vmovdqu16(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU16, a, b);
        }
        Error vmovdqu16(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU16, a, b);
        }
        Error vmovdqu16(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU16, a, b);
        }
        Error vmovdqu32(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU32, a, b);
        }
        Error vmovdqu32(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU32, a, b);
        }
        Error vmovdqu32(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU32, a, b);
        }
        Error vmovdqu64(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU64, a, b);
        }
        Error vmovdqu64(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU64, a, b);
        }
        Error vmovdqu64(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU64, a, b);
        }
        Error vmovdqu8(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU8, a, b);
        }
        Error vmovdqu8(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU8, a, b);
        }
        Error vmovdqu8(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVDQU8, a, b);
        }
        Error vmovhlps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMOVHLPS, a, b, c);
        }
        Error vmovhpd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVHPD, a, b);
        }
        Error vmovhpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMOVHPD, a, b, c);
        }
        Error vmovhps(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVHPS, a, b);
        }
        Error vmovhps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMOVHPS, a, b, c);
        }
        Error vmovlhps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMOVLHPS, a, b, c);
        }
        Error vmovlpd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVLPD, a, b);
        }
        Error vmovlpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMOVLPD, a, b, c);
        }
        Error vmovlps(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVLPS, a, b);
        }
        Error vmovlps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMOVLPS, a, b, c);
        }
        Error vmovmskpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVMSKPD, a, b);
        }
        Error vmovmskps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVMSKPS, a, b);
        }
        Error vmovntdq(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVNTDQ, a, b);
        }
        Error vmovntdqa(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVNTDQA, a, b);
        }
        Error vmovntpd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVNTPD, a, b);
        }
        Error vmovntps(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVNTPS, a, b);
        }
        Error vmovq(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVQ, a, b);
        }
        Error vmovq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVQ, a, b);
        }
        Error vmovq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVQ, a, b);
        }
        Error vmovsd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVSD, a, b);
        }
        Error vmovsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVSD, a, b);
        }
        Error vmovsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMOVSD, a, b, c);
        }
        Error vmovshdup(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVSHDUP, a, b);
        }
        Error vmovshdup(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVSHDUP, a, b);
        }
        Error vmovsldup(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVSLDUP, a, b);
        }
        Error vmovsldup(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVSLDUP, a, b);
        }
        Error vmovss(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVSS, a, b);
        }
        Error vmovss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVSS, a, b);
        }
        Error vmovss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMOVSS, a, b, c);
        }
        Error vmovupd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVUPD, a, b);
        }
        Error vmovupd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVUPD, a, b);
        }
        Error vmovupd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVUPD, a, b);
        }
        Error vmovups(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVUPS, a, b);
        }
        Error vmovups(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVUPS, a, b);
        }
        Error vmovups(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMOVUPS, a, b);
        }
        Error vmpsadbw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VMPSADBW, a, b, c, d);
        }
        Error vmpsadbw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VMPSADBW, a, b, c, d);
        }
        Error vmulpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMULPD, a, b, c);
        }
        Error vmulpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMULPD, a, b, c);
        }
        Error vmulps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMULPS, a, b, c);
        }
        Error vmulps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMULPS, a, b, c);
        }
        Error vmulsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMULSD, a, b, c);
        }
        Error vmulsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMULSD, a, b, c);
        }
        Error vmulss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VMULSS, a, b, c);
        }
        Error vmulss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VMULSS, a, b, c);
        }
        Error vorpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VORPD, a, b, c);
        }
        Error vorpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VORPD, a, b, c);
        }
        Error vorps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VORPS, a, b, c);
        }
        Error vorps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VORPS, a, b, c);
        }
        Error vpabsb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPABSB, a, b);
        }
        Error vpabsb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPABSB, a, b);
        }
        Error vpabsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPABSD, a, b);
        }
        Error vpabsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPABSD, a, b);
        }
        Error vpabsq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPABSQ, a, b);
        }
        Error vpabsq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPABSQ, a, b);
        }
        Error vpabsw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPABSW, a, b);
        }
        Error vpabsw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPABSW, a, b);
        }
        Error vpackssdw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPACKSSDW, a, b, c);
        }
        Error vpackssdw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPACKSSDW, a, b, c);
        }
        Error vpacksswb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPACKSSWB, a, b, c);
        }
        Error vpacksswb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPACKSSWB, a, b, c);
        }
        Error vpackusdw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPACKUSDW, a, b, c);
        }
        Error vpackusdw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPACKUSDW, a, b, c);
        }
        Error vpackuswb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPACKUSWB, a, b, c);
        }
        Error vpackuswb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPACKUSWB, a, b, c);
        }
        Error vpaddb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDB, a, b, c);
        }
        Error vpaddb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDB, a, b, c);
        }
        Error vpaddd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDD, a, b, c);
        }
        Error vpaddd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDD, a, b, c);
        }
        Error vpaddq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDQ, a, b, c);
        }
        Error vpaddq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDQ, a, b, c);
        }
        Error vpaddsb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDSB, a, b, c);
        }
        Error vpaddsb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDSB, a, b, c);
        }
        Error vpaddsw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDSW, a, b, c);
        }
        Error vpaddsw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDSW, a, b, c);
        }
        Error vpaddusb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDUSB, a, b, c);
        }
        Error vpaddusb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDUSB, a, b, c);
        }
        Error vpaddusw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDUSW, a, b, c);
        }
        Error vpaddusw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDUSW, a, b, c);
        }
        Error vpaddw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDW, a, b, c);
        }
        Error vpaddw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPADDW, a, b, c);
        }
        Error vpalignr(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPALIGNR, a, b, c, d);
        }
        Error vpalignr(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPALIGNR, a, b, c, d);
        }
        Error vpand(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPAND, a, b, c);
        }
        Error vpand(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPAND, a, b, c);
        }
        Error vpandd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPANDD, a, b, c);
        }
        Error vpandd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPANDD, a, b, c);
        }
        Error vpandn(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPANDN, a, b, c);
        }
        Error vpandn(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPANDN, a, b, c);
        }
        Error vpandnd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPANDND, a, b, c);
        }
        Error vpandnd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPANDND, a, b, c);
        }
        Error vpandnq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPANDNQ, a, b, c);
        }
        Error vpandnq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPANDNQ, a, b, c);
        }
        Error vpandq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPANDQ, a, b, c);
        }
        Error vpandq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPANDQ, a, b, c);
        }
        Error vpavgb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPAVGB, a, b, c);
        }
        Error vpavgb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPAVGB, a, b, c);
        }
        Error vpavgw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPAVGW, a, b, c);
        }
        Error vpavgw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPAVGW, a, b, c);
        }
        Error vpblendd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPBLENDD, a, b, c, d);
        }
        Error vpblendd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPBLENDD, a, b, c, d);
        }
        Error vpblendvb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPBLENDVB, a, b, c, d);
        }
        Error vpblendvb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPBLENDVB, a, b, c, d);
        }
        Error vpblendw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPBLENDW, a, b, c, d);
        }
        Error vpblendw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPBLENDW, a, b, c, d);
        }
        Error vpbroadcastb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPBROADCASTB, a, b);
        }
        Error vpbroadcastb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPBROADCASTB, a, b);
        }
        Error vpbroadcastd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPBROADCASTD, a, b);
        }
        Error vpbroadcastd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPBROADCASTD, a, b);
        }
        Error vpbroadcastmb2q(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPBROADCASTMB2Q, a, b);
        }
        Error vpbroadcastq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPBROADCASTQ, a, b);
        }
        Error vpbroadcastq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPBROADCASTQ, a, b);
        }
        Error vpbroadcastw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPBROADCASTW, a, b);
        }
        Error vpbroadcastw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPBROADCASTW, a, b);
        }
        Error vpclmulqdq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCLMULQDQ, a, b, c, d);
        }
        Error vpclmulqdq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCLMULQDQ, a, b, c, d);
        }
        Error vpcmpb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPB, a, b, c, d);
        }
        Error vpcmpb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPB, a, b, c, d);
        }
        Error vpcmpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPD, a, b, c, d);
        }
        Error vpcmpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPD, a, b, c, d);
        }
        Error vpcmpeqb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPEQB, a, b, c);
        }
        Error vpcmpeqb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPEQB, a, b, c);
        }
        Error vpcmpeqd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPEQD, a, b, c);
        }
        Error vpcmpeqd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPEQD, a, b, c);
        }
        Error vpcmpeqq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPEQQ, a, b, c);
        }
        Error vpcmpeqq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPEQQ, a, b, c);
        }
        Error vpcmpeqw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPEQW, a, b, c);
        }
        Error vpcmpeqw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPEQW, a, b, c);
        }
        Error vpcmpgtb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPGTB, a, b, c);
        }
        Error vpcmpgtb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPGTB, a, b, c);
        }
        Error vpcmpgtd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPGTD, a, b, c);
        }
        Error vpcmpgtd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPGTD, a, b, c);
        }
        Error vpcmpgtq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPGTQ, a, b, c);
        }
        Error vpcmpgtq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPGTQ, a, b, c);
        }
        Error vpcmpgtw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPGTW, a, b, c);
        }
        Error vpcmpgtw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPGTW, a, b, c);
        }
        Error vpcmpq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPQ, a, b, c, d);
        }
        Error vpcmpq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPQ, a, b, c, d);
        }
        Error vpcmpub(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPUB, a, b, c, d);
        }
        Error vpcmpub(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPUB, a, b, c, d);
        }
        Error vpcmpud(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPUD, a, b, c, d);
        }
        Error vpcmpud(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPUD, a, b, c, d);
        }
        Error vpcmpuq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPUQ, a, b, c, d);
        }
        Error vpcmpuq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPUQ, a, b, c, d);
        }
        Error vpcmpuw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPUW, a, b, c, d);
        }
        Error vpcmpuw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPUW, a, b, c, d);
        }
        Error vpcmpw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPW, a, b, c, d);
        }
        Error vpcmpw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPW, a, b, c, d);
        }
        Error vpcompressb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMPRESSB, a, b);
        }
        Error vpcompressb(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMPRESSB, a, b);
        }
        Error vpcompressd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMPRESSD, a, b);
        }
        Error vpcompressd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMPRESSD, a, b);
        }
        Error vpcompressq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMPRESSQ, a, b);
        }
        Error vpcompressq(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMPRESSQ, a, b);
        }
        Error vpcompressw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMPRESSW, a, b);
        }
        Error vpcompressw(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMPRESSW, a, b);
        }
        Error vpconflictd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPCONFLICTD, a, b);
        }
        Error vpconflictd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPCONFLICTD, a, b);
        }
        Error vpconflictq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPCONFLICTQ, a, b);
        }
        Error vpconflictq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPCONFLICTQ, a, b);
        }
        Error vpdpbusd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPDPBUSD, a, b, c);
        }
        Error vpdpbusd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPDPBUSD, a, b, c);
        }
        Error vpdpbusds(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPDPBUSDS, a, b, c);
        }
        Error vpdpbusds(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPDPBUSDS, a, b, c);
        }
        Error vpdpwssd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPDPWSSD, a, b, c);
        }
        Error vpdpwssd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPDPWSSD, a, b, c);
        }
        Error vpdpwssds(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPDPWSSDS, a, b, c);
        }
        Error vpdpwssds(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPDPWSSDS, a, b, c);
        }
        Error vperm2f128(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPERM2F128, a, b, c, d);
        }
        Error vperm2f128(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPERM2F128, a, b, c, d);
        }
        Error vperm2i128(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPERM2I128, a, b, c, d);
        }
        Error vperm2i128(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPERM2I128, a, b, c, d);
        }
        Error vpermb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMB, a, b, c);
        }
        Error vpermb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMB, a, b, c);
        }
        Error vpermd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMD, a, b, c);
        }
        Error vpermd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMD, a, b, c);
        }
        Error vpermi2b(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMI2B, a, b, c);
        }
        Error vpermi2b(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMI2B, a, b, c);
        }
        Error vpermi2d(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMI2D, a, b, c);
        }
        Error vpermi2d(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMI2D, a, b, c);
        }
        Error vpermi2pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMI2PD, a, b, c);
        }
        Error vpermi2pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMI2PD, a, b, c);
        }
        Error vpermi2ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMI2PS, a, b, c);
        }
        Error vpermi2ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMI2PS, a, b, c);
        }
        Error vpermi2q(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMI2Q, a, b, c);
        }
        Error vpermi2q(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMI2Q, a, b, c);
        }
        Error vpermi2w(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMI2W, a, b, c);
        }
        Error vpermi2w(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMI2W, a, b, c);
        }
        Error vpermilpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMILPD, a, b, c);
        }
        Error vpermilpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMILPD, a, b, c);
        }
        Error vpermilpd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMILPD, a, b, c);
        }
        Error vpermilpd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMILPD, a, b, c);
        }
        Error vpermilps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMILPS, a, b, c);
        }
        Error vpermilps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMILPS, a, b, c);
        }
        Error vpermilps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMILPS, a, b, c);
        }
        Error vpermilps(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMILPS, a, b, c);
        }
        Error vpermpd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMPD, a, b, c);
        }
        Error vpermpd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMPD, a, b, c);
        }
        Error vpermps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMPS, a, b, c);
        }
        Error vpermps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMPS, a, b, c);
        }
        Error vpermq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMQ, a, b, c);
        }
        Error vpermq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMQ, a, b, c);
        }
        Error vpermq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMQ, a, b, c);
        }
        Error vpermq(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMQ, a, b, c);
        }
        Error vpermt2b(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMT2B, a, b, c);
        }
        Error vpermt2b(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMT2B, a, b, c);
        }
        Error vpermt2d(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMT2D, a, b, c);
        }
        Error vpermt2d(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMT2D, a, b, c);
        }
        Error vpermt2pd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMT2PD, a, b, c);
        }
        Error vpermt2pd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMT2PD, a, b, c);
        }
        Error vpermt2ps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMT2PS, a, b, c);
        }
        Error vpermt2ps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMT2PS, a, b, c);
        }
        Error vpermt2q(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMT2Q, a, b, c);
        }
        Error vpermt2q(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMT2Q, a, b, c);
        }
        Error vpermt2w(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMT2W, a, b, c);
        }
        Error vpermt2w(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMT2W, a, b, c);
        }
        Error vpermw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMW, a, b, c);
        }
        Error vpermw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPERMW, a, b, c);
        }
        Error vpexpandb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPEXPANDB, a, b);
        }
        Error vpexpandb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPEXPANDB, a, b);
        }
        Error vpexpandd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPEXPANDD, a, b);
        }
        Error vpexpandd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPEXPANDD, a, b);
        }
        Error vpexpandq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPEXPANDQ, a, b);
        }
        Error vpexpandq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPEXPANDQ, a, b);
        }
        Error vpexpandw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPEXPANDW, a, b);
        }
        Error vpexpandw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPEXPANDW, a, b);
        }
        Error vpextrb(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPEXTRB, a, b, c);
        }
        Error vpextrb(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPEXTRB, a, b, c);
        }
        Error vpextrd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPEXTRD, a, b, c);
        }
        Error vpextrd(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPEXTRD, a, b, c);
        }
        Error vpextrq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPEXTRQ, a, b, c);
        }
        Error vpextrq(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPEXTRQ, a, b, c);
        }
        Error vpextrw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPEXTRW, a, b, c);
        }
        Error vpextrw(const operands::Mem& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPEXTRW, a, b, c);
        }
        Error vpgatherdd(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPGATHERDD, a, b, c);
        }
        Error vpgatherdd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPGATHERDD, a, b);
        }
        Error vpgatherdq(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPGATHERDQ, a, b, c);
        }
        Error vpgatherdq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPGATHERDQ, a, b);
        }
        Error vpgatherqd(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPGATHERQD, a, b, c);
        }
        Error vpgatherqd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPGATHERQD, a, b);
        }
        Error vpgatherqq(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPGATHERQQ, a, b, c);
        }
        Error vpgatherqq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPGATHERQQ, a, b);
        }
        Error vphaddd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDD, a, b, c);
        }
        Error vphaddd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDD, a, b, c);
        }
        Error vphaddsw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDSW, a, b, c);
        }
        Error vphaddsw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDSW, a, b, c);
        }
        Error vphaddw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDW, a, b, c);
        }
        Error vphaddw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDW, a, b, c);
        }
        Error vphminposuw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHMINPOSUW, a, b);
        }
        Error vphminposuw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHMINPOSUW, a, b);
        }
        Error vphsubd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPHSUBD, a, b, c);
        }
        Error vphsubd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPHSUBD, a, b, c);
        }
        Error vphsubsw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPHSUBSW, a, b, c);
        }
        Error vphsubsw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPHSUBSW, a, b, c);
        }
        Error vphsubw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPHSUBW, a, b, c);
        }
        Error vphsubw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPHSUBW, a, b, c);
        }
        Error vpinsrb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPINSRB, a, b, c, d);
        }
        Error vpinsrb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPINSRB, a, b, c, d);
        }
        Error vpinsrd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPINSRD, a, b, c, d);
        }
        Error vpinsrd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPINSRD, a, b, c, d);
        }
        Error vpinsrq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPINSRQ, a, b, c, d);
        }
        Error vpinsrq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPINSRQ, a, b, c, d);
        }
        Error vpinsrw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPINSRW, a, b, c, d);
        }
        Error vpinsrw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPINSRW, a, b, c, d);
        }
        Error vplzcntd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPLZCNTD, a, b);
        }
        Error vplzcntd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPLZCNTD, a, b);
        }
        Error vplzcntq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPLZCNTQ, a, b);
        }
        Error vplzcntq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPLZCNTQ, a, b);
        }
        Error vpmadd52huq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMADD52HUQ, a, b, c);
        }
        Error vpmadd52huq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMADD52HUQ, a, b, c);
        }
        Error vpmadd52luq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMADD52LUQ, a, b, c);
        }
        Error vpmadd52luq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMADD52LUQ, a, b, c);
        }
        Error vpmaddubsw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMADDUBSW, a, b, c);
        }
        Error vpmaddubsw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMADDUBSW, a, b, c);
        }
        Error vpmaddwd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMADDWD, a, b, c);
        }
        Error vpmaddwd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMADDWD, a, b, c);
        }
        Error vpmaskmovd(const operands::Mem& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMASKMOVD, a, b, c);
        }
        Error vpmaskmovd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMASKMOVD, a, b, c);
        }
        Error vpmaskmovq(const operands::Mem& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMASKMOVQ, a, b, c);
        }
        Error vpmaskmovq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMASKMOVQ, a, b, c);
        }
        Error vpmaxsb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXSB, a, b, c);
        }
        Error vpmaxsb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXSB, a, b, c);
        }
        Error vpmaxsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXSD, a, b, c);
        }
        Error vpmaxsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXSD, a, b, c);
        }
        Error vpmaxsq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXSQ, a, b, c);
        }
        Error vpmaxsq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXSQ, a, b, c);
        }
        Error vpmaxsw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXSW, a, b, c);
        }
        Error vpmaxsw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXSW, a, b, c);
        }
        Error vpmaxub(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXUB, a, b, c);
        }
        Error vpmaxub(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXUB, a, b, c);
        }
        Error vpmaxud(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXUD, a, b, c);
        }
        Error vpmaxud(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXUD, a, b, c);
        }
        Error vpmaxuq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXUQ, a, b, c);
        }
        Error vpmaxuq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXUQ, a, b, c);
        }
        Error vpmaxuw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXUW, a, b, c);
        }
        Error vpmaxuw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMAXUW, a, b, c);
        }
        Error vpminsb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINSB, a, b, c);
        }
        Error vpminsb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINSB, a, b, c);
        }
        Error vpminsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINSD, a, b, c);
        }
        Error vpminsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINSD, a, b, c);
        }
        Error vpminsq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINSQ, a, b, c);
        }
        Error vpminsq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINSQ, a, b, c);
        }
        Error vpminsw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINSW, a, b, c);
        }
        Error vpminsw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINSW, a, b, c);
        }
        Error vpminub(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINUB, a, b, c);
        }
        Error vpminub(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINUB, a, b, c);
        }
        Error vpminud(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINUD, a, b, c);
        }
        Error vpminud(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINUD, a, b, c);
        }
        Error vpminuq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINUQ, a, b, c);
        }
        Error vpminuq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINUQ, a, b, c);
        }
        Error vpminuw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINUW, a, b, c);
        }
        Error vpminuw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMINUW, a, b, c);
        }
        Error vpmovb2m(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVB2M, a, b);
        }
        Error vpmovd2m(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVD2M, a, b);
        }
        Error vpmovdb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVDB, a, b);
        }
        Error vpmovdb(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVDB, a, b);
        }
        Error vpmovdw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVDW, a, b);
        }
        Error vpmovdw(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVDW, a, b);
        }
        Error vpmovm2b(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVM2B, a, b);
        }
        Error vpmovm2d(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVM2D, a, b);
        }
        Error vpmovm2q(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVM2Q, a, b);
        }
        Error vpmovm2w(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVM2W, a, b);
        }
        Error vpmovmskb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVMSKB, a, b);
        }
        Error vpmovq2m(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVQ2M, a, b);
        }
        Error vpmovqb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVQB, a, b);
        }
        Error vpmovqb(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVQB, a, b);
        }
        Error vpmovqd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVQD, a, b);
        }
        Error vpmovqd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVQD, a, b);
        }
        Error vpmovqw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVQW, a, b);
        }
        Error vpmovqw(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVQW, a, b);
        }
        Error vpmovsdb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSDB, a, b);
        }
        Error vpmovsdb(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSDB, a, b);
        }
        Error vpmovsdw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSDW, a, b);
        }
        Error vpmovsdw(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSDW, a, b);
        }
        Error vpmovsqb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSQB, a, b);
        }
        Error vpmovsqb(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSQB, a, b);
        }
        Error vpmovsqd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSQD, a, b);
        }
        Error vpmovsqd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSQD, a, b);
        }
        Error vpmovsqw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSQW, a, b);
        }
        Error vpmovsqw(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSQW, a, b);
        }
        Error vpmovswb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSWB, a, b);
        }
        Error vpmovswb(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSWB, a, b);
        }
        Error vpmovsxbd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSXBD, a, b);
        }
        Error vpmovsxbd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSXBD, a, b);
        }
        Error vpmovsxbq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSXBQ, a, b);
        }
        Error vpmovsxbq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSXBQ, a, b);
        }
        Error vpmovsxbw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSXBW, a, b);
        }
        Error vpmovsxbw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSXBW, a, b);
        }
        Error vpmovsxdq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSXDQ, a, b);
        }
        Error vpmovsxdq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSXDQ, a, b);
        }
        Error vpmovsxwd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSXWD, a, b);
        }
        Error vpmovsxwd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSXWD, a, b);
        }
        Error vpmovsxwq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSXWQ, a, b);
        }
        Error vpmovsxwq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVSXWQ, a, b);
        }
        Error vpmovusdb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVUSDB, a, b);
        }
        Error vpmovusdb(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVUSDB, a, b);
        }
        Error vpmovusdw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVUSDW, a, b);
        }
        Error vpmovusdw(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVUSDW, a, b);
        }
        Error vpmovusqb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVUSQB, a, b);
        }
        Error vpmovusqb(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVUSQB, a, b);
        }
        Error vpmovusqd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVUSQD, a, b);
        }
        Error vpmovusqd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVUSQD, a, b);
        }
        Error vpmovusqw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVUSQW, a, b);
        }
        Error vpmovusqw(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVUSQW, a, b);
        }
        Error vpmovuswb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVUSWB, a, b);
        }
        Error vpmovuswb(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVUSWB, a, b);
        }
        Error vpmovw2m(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVW2M, a, b);
        }
        Error vpmovwb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVWB, a, b);
        }
        Error vpmovwb(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVWB, a, b);
        }
        Error vpmovzxbd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVZXBD, a, b);
        }
        Error vpmovzxbd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVZXBD, a, b);
        }
        Error vpmovzxbq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVZXBQ, a, b);
        }
        Error vpmovzxbq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVZXBQ, a, b);
        }
        Error vpmovzxbw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVZXBW, a, b);
        }
        Error vpmovzxbw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVZXBW, a, b);
        }
        Error vpmovzxdq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVZXDQ, a, b);
        }
        Error vpmovzxdq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVZXDQ, a, b);
        }
        Error vpmovzxwd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVZXWD, a, b);
        }
        Error vpmovzxwd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVZXWD, a, b);
        }
        Error vpmovzxwq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVZXWQ, a, b);
        }
        Error vpmovzxwq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPMOVZXWQ, a, b);
        }
        Error vpmuldq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULDQ, a, b, c);
        }
        Error vpmuldq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULDQ, a, b, c);
        }
        Error vpmulhrsw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULHRSW, a, b, c);
        }
        Error vpmulhrsw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULHRSW, a, b, c);
        }
        Error vpmulhuw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULHUW, a, b, c);
        }
        Error vpmulhuw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULHUW, a, b, c);
        }
        Error vpmulhw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULHW, a, b, c);
        }
        Error vpmulhw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULHW, a, b, c);
        }
        Error vpmulld(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULLD, a, b, c);
        }
        Error vpmulld(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULLD, a, b, c);
        }
        Error vpmullq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULLQ, a, b, c);
        }
        Error vpmullq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULLQ, a, b, c);
        }
        Error vpmullw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULLW, a, b, c);
        }
        Error vpmullw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULLW, a, b, c);
        }
        Error vpmultishiftqb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULTISHIFTQB, a, b, c);
        }
        Error vpmultishiftqb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULTISHIFTQB, a, b, c);
        }
        Error vpmuludq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULUDQ, a, b, c);
        }
        Error vpmuludq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPMULUDQ, a, b, c);
        }
        Error vpopcntb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPOPCNTB, a, b);
        }
        Error vpopcntb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPOPCNTB, a, b);
        }
        Error vpopcntd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPOPCNTD, a, b);
        }
        Error vpopcntd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPOPCNTD, a, b);
        }
        Error vpopcntq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPOPCNTQ, a, b);
        }
        Error vpopcntq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPOPCNTQ, a, b);
        }
        Error vpopcntw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPOPCNTW, a, b);
        }
        Error vpopcntw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPOPCNTW, a, b);
        }
        Error vpor(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPOR, a, b, c);
        }
        Error vpor(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPOR, a, b, c);
        }
        Error vpord(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPORD, a, b, c);
        }
        Error vpord(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPORD, a, b, c);
        }
        Error vporq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPORQ, a, b, c);
        }
        Error vporq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPORQ, a, b, c);
        }
        Error vprold(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROLD, a, b, c);
        }
        Error vprold(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROLD, a, b, c);
        }
        Error vprolq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROLQ, a, b, c);
        }
        Error vprolq(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROLQ, a, b, c);
        }
        Error vprolvd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROLVD, a, b, c);
        }
        Error vprolvd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROLVD, a, b, c);
        }
        Error vprolvq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROLVQ, a, b, c);
        }
        Error vprolvq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROLVQ, a, b, c);
        }
        Error vprord(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPRORD, a, b, c);
        }
        Error vprord(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPRORD, a, b, c);
        }
        Error vprorq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPRORQ, a, b, c);
        }
        Error vprorq(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPRORQ, a, b, c);
        }
        Error vprorvd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPRORVD, a, b, c);
        }
        Error vprorvd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPRORVD, a, b, c);
        }
        Error vprorvq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPRORVQ, a, b, c);
        }
        Error vprorvq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPRORVQ, a, b, c);
        }
        Error vpsadbw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSADBW, a, b, c);
        }
        Error vpsadbw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSADBW, a, b, c);
        }
        Error vpscatterdd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPSCATTERDD, a, b);
        }
        Error vpscatterdq(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPSCATTERDQ, a, b);
        }
        Error vpscatterqd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPSCATTERQD, a, b);
        }
        Error vpscatterqq(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPSCATTERQQ, a, b);
        }
        Error vpshldd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLDD, a, b, c, d);
        }
        Error vpshldd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLDD, a, b, c, d);
        }
        Error vpshldvd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLDVD, a, b, c);
        }
        Error vpshldvd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLDVD, a, b, c);
        }
        Error vpshldvq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLDVQ, a, b, c);
        }
        Error vpshldvq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLDVQ, a, b, c);
        }
        Error vpshldvw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLDVW, a, b, c);
        }
        Error vpshldvw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLDVW, a, b, c);
        }
        Error vpshrdd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPSHRDD, a, b, c, d);
        }
        Error vpshrdd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPSHRDD, a, b, c, d);
        }
        Error vpshrdvd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHRDVD, a, b, c);
        }
        Error vpshrdvd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHRDVD, a, b, c);
        }
        Error vpshrdvq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHRDVQ, a, b, c);
        }
        Error vpshrdvq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHRDVQ, a, b, c);
        }
        Error vpshrdvw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHRDVW, a, b, c);
        }
        Error vpshrdvw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHRDVW, a, b, c);
        }
        Error vpshrdw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPSHRDW, a, b, c, d);
        }
        Error vpshrdw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPSHRDW, a, b, c, d);
        }
        Error vpshufb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHUFB, a, b, c);
        }
        Error vpshufb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHUFB, a, b, c);
        }
        Error vpshufbitqmb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHUFBITQMB, a, b, c);
        }
        Error vpshufbitqmb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHUFBITQMB, a, b, c);
        }
        Error vpshufd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHUFD, a, b, c);
        }
        Error vpshufd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHUFD, a, b, c);
        }
        Error vpshufhw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHUFHW, a, b, c);
        }
        Error vpshufhw(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHUFHW, a, b, c);
        }
        Error vpshuflw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHUFLW, a, b, c);
        }
        Error vpshuflw(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHUFLW, a, b, c);
        }
        Error vpsignb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSIGNB, a, b, c);
        }
        Error vpsignb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSIGNB, a, b, c);
        }
        Error vpsignd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSIGND, a, b, c);
        }
        Error vpsignd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSIGND, a, b, c);
        }
        Error vpsignw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSIGNW, a, b, c);
        }
        Error vpsignw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSIGNW, a, b, c);
        }
        Error vpslld(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLD, a, b, c);
        }
        Error vpslld(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLD, a, b, c);
        }
        Error vpslld(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLD, a, b, c);
        }
        Error vpslld(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLD, a, b, c);
        }
        Error vpslldq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLDQ, a, b, c);
        }
        Error vpslldq(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLDQ, a, b, c);
        }
        Error vpsllq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLQ, a, b, c);
        }
        Error vpsllq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLQ, a, b, c);
        }
        Error vpsllq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLQ, a, b, c);
        }
        Error vpsllq(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLQ, a, b, c);
        }
        Error vpsllvd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLVD, a, b, c);
        }
        Error vpsllvd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLVD, a, b, c);
        }
        Error vpsllvq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLVQ, a, b, c);
        }
        Error vpsllvq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLVQ, a, b, c);
        }
        Error vpsllvw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLVW, a, b, c);
        }
        Error vpsllvw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLVW, a, b, c);
        }
        Error vpsllw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLW, a, b, c);
        }
        Error vpsllw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLW, a, b, c);
        }
        Error vpsllw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLW, a, b, c);
        }
        Error vpsllw(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSLLW, a, b, c);
        }
        Error vpsrad(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAD, a, b, c);
        }
        Error vpsrad(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAD, a, b, c);
        }
        Error vpsrad(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAD, a, b, c);
        }
        Error vpsrad(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAD, a, b, c);
        }
        Error vpsraq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAQ, a, b, c);
        }
        Error vpsraq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAQ, a, b, c);
        }
        Error vpsraq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAQ, a, b, c);
        }
        Error vpsraq(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAQ, a, b, c);
        }
        Error vpsravd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAVD, a, b, c);
        }
        Error vpsravd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAVD, a, b, c);
        }
        Error vpsravq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAVQ, a, b, c);
        }
        Error vpsravq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAVQ, a, b, c);
        }
        Error vpsravw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAVW, a, b, c);
        }
        Error vpsravw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAVW, a, b, c);
        }
        Error vpsraw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAW, a, b, c);
        }
        Error vpsraw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAW, a, b, c);
        }
        Error vpsraw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAW, a, b, c);
        }
        Error vpsraw(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRAW, a, b, c);
        }
        Error vpsrld(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLD, a, b, c);
        }
        Error vpsrld(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLD, a, b, c);
        }
        Error vpsrld(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLD, a, b, c);
        }
        Error vpsrld(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLD, a, b, c);
        }
        Error vpsrldq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLDQ, a, b, c);
        }
        Error vpsrldq(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLDQ, a, b, c);
        }
        Error vpsrlq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLQ, a, b, c);
        }
        Error vpsrlq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLQ, a, b, c);
        }
        Error vpsrlq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLQ, a, b, c);
        }
        Error vpsrlq(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLQ, a, b, c);
        }
        Error vpsrlvd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLVD, a, b, c);
        }
        Error vpsrlvd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLVD, a, b, c);
        }
        Error vpsrlvq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLVQ, a, b, c);
        }
        Error vpsrlvq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLVQ, a, b, c);
        }
        Error vpsrlvw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLVW, a, b, c);
        }
        Error vpsrlvw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLVW, a, b, c);
        }
        Error vpsrlw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLW, a, b, c);
        }
        Error vpsrlw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLW, a, b, c);
        }
        Error vpsrlw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLW, a, b, c);
        }
        Error vpsrlw(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSRLW, a, b, c);
        }
        Error vpsubb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBB, a, b, c);
        }
        Error vpsubb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBB, a, b, c);
        }
        Error vpsubd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBD, a, b, c);
        }
        Error vpsubd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBD, a, b, c);
        }
        Error vpsubq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBQ, a, b, c);
        }
        Error vpsubq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBQ, a, b, c);
        }
        Error vpsubsb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBSB, a, b, c);
        }
        Error vpsubsb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBSB, a, b, c);
        }
        Error vpsubsw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBSW, a, b, c);
        }
        Error vpsubsw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBSW, a, b, c);
        }
        Error vpsubusb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBUSB, a, b, c);
        }
        Error vpsubusb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBUSB, a, b, c);
        }
        Error vpsubusw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBUSW, a, b, c);
        }
        Error vpsubusw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBUSW, a, b, c);
        }
        Error vpsubw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBW, a, b, c);
        }
        Error vpsubw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSUBW, a, b, c);
        }
        Error vpternlogd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPTERNLOGD, a, b, c, d);
        }
        Error vpternlogd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPTERNLOGD, a, b, c, d);
        }
        Error vpternlogq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPTERNLOGQ, a, b, c, d);
        }
        Error vpternlogq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPTERNLOGQ, a, b, c, d);
        }
        Error vptest(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPTEST, a, b);
        }
        Error vptest(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPTEST, a, b);
        }
        Error vptestmb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTMB, a, b, c);
        }
        Error vptestmb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTMB, a, b, c);
        }
        Error vptestmd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTMD, a, b, c);
        }
        Error vptestmd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTMD, a, b, c);
        }
        Error vptestmq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTMQ, a, b, c);
        }
        Error vptestmq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTMQ, a, b, c);
        }
        Error vptestmw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTMW, a, b, c);
        }
        Error vptestmw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTMW, a, b, c);
        }
        Error vptestnmb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTNMB, a, b, c);
        }
        Error vptestnmb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTNMB, a, b, c);
        }
        Error vptestnmd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTNMD, a, b, c);
        }
        Error vptestnmd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTNMD, a, b, c);
        }
        Error vptestnmq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTNMQ, a, b, c);
        }
        Error vptestnmq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTNMQ, a, b, c);
        }
        Error vptestnmw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTNMW, a, b, c);
        }
        Error vptestnmw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPTESTNMW, a, b, c);
        }
        Error vpunpckhbw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKHBW, a, b, c);
        }
        Error vpunpckhbw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKHBW, a, b, c);
        }
        Error vpunpckhdq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKHDQ, a, b, c);
        }
        Error vpunpckhdq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKHDQ, a, b, c);
        }
        Error vpunpckhqdq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKHQDQ, a, b, c);
        }
        Error vpunpckhqdq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKHQDQ, a, b, c);
        }
        Error vpunpckhwd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKHWD, a, b, c);
        }
        Error vpunpckhwd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKHWD, a, b, c);
        }
        Error vpunpcklbw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKLBW, a, b, c);
        }
        Error vpunpcklbw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKLBW, a, b, c);
        }
        Error vpunpckldq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKLDQ, a, b, c);
        }
        Error vpunpckldq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKLDQ, a, b, c);
        }
        Error vpunpcklqdq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKLQDQ, a, b, c);
        }
        Error vpunpcklqdq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKLQDQ, a, b, c);
        }
        Error vpunpcklwd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKLWD, a, b, c);
        }
        Error vpunpcklwd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPUNPCKLWD, a, b, c);
        }
        Error vpxor(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPXOR, a, b, c);
        }
        Error vpxor(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPXOR, a, b, c);
        }
        Error vpxord(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPXORD, a, b, c);
        }
        Error vpxord(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPXORD, a, b, c);
        }
        Error vpxorq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPXORQ, a, b, c);
        }
        Error vpxorq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPXORQ, a, b, c);
        }
        Error vrangepd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VRANGEPD, a, b, c, d);
        }
        Error vrangepd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VRANGEPD, a, b, c, d);
        }
        Error vrangeps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VRANGEPS, a, b, c, d);
        }
        Error vrangeps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VRANGEPS, a, b, c, d);
        }
        Error vrangesd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VRANGESD, a, b, c, d);
        }
        Error vrangesd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VRANGESD, a, b, c, d);
        }
        Error vrangess(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VRANGESS, a, b, c, d);
        }
        Error vrangess(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VRANGESS, a, b, c, d);
        }
        Error vrcp14pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VRCP14PD, a, b);
        }
        Error vrcp14pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VRCP14PD, a, b);
        }
        Error vrcp14ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VRCP14PS, a, b);
        }
        Error vrcp14ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VRCP14PS, a, b);
        }
        Error vrcp14sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VRCP14SD, a, b, c);
        }
        Error vrcp14sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VRCP14SD, a, b, c);
        }
        Error vrcp14ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VRCP14SS, a, b, c);
        }
        Error vrcp14ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VRCP14SS, a, b, c);
        }
        Error vrcp28pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VRCP28PD, a, b);
        }
        Error vrcp28pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VRCP28PD, a, b);
        }
        Error vrcp28ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VRCP28PS, a, b);
        }
        Error vrcp28ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VRCP28PS, a, b);
        }
        Error vrcp28sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VRCP28SD, a, b, c);
        }
        Error vrcp28sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VRCP28SD, a, b, c);
        }
        Error vrcp28ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VRCP28SS, a, b, c);
        }
        Error vrcp28ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VRCP28SS, a, b, c);
        }
        Error vrcpps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VRCPPS, a, b);
        }
        Error vrcpps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VRCPPS, a, b);
        }
        Error vrcpss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VRCPSS, a, b, c);
        }
        Error vrcpss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VRCPSS, a, b, c);
        }
        Error vreducepd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VREDUCEPD, a, b, c);
        }
        Error vreducepd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VREDUCEPD, a, b, c);
        }
        Error vreduceps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VREDUCEPS, a, b, c);
        }
        Error vreduceps(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VREDUCEPS, a, b, c);
        }
        Error vreducesd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VREDUCESD, a, b, c, d);
        }
        Error vreducesd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VREDUCESD, a, b, c, d);
        }
        Error vreducess(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VREDUCESS, a, b, c, d);
        }
        Error vreducess(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VREDUCESS, a, b, c, d);
        }
        Error vrndscalepd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VRNDSCALEPD, a, b, c);
        }
        Error vrndscalepd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VRNDSCALEPD, a, b, c);
        }
        Error vrndscaleps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VRNDSCALEPS, a, b, c);
        }
        Error vrndscaleps(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VRNDSCALEPS, a, b, c);
        }
        Error vrndscalesd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VRNDSCALESD, a, b, c, d);
        }
        Error vrndscalesd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VRNDSCALESD, a, b, c, d);
        }
        Error vrndscaless(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VRNDSCALESS, a, b, c, d);
        }
        Error vrndscaless(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VRNDSCALESS, a, b, c, d);
        }
        Error vroundpd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VROUNDPD, a, b, c);
        }
        Error vroundpd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VROUNDPD, a, b, c);
        }
        Error vroundps(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VROUNDPS, a, b, c);
        }
        Error vroundps(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VROUNDPS, a, b, c);
        }
        Error vroundsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VROUNDSD, a, b, c, d);
        }
        Error vroundsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VROUNDSD, a, b, c, d);
        }
        Error vroundss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VROUNDSS, a, b, c, d);
        }
        Error vroundss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VROUNDSS, a, b, c, d);
        }
        Error vrsqrt14pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT14PD, a, b);
        }
        Error vrsqrt14pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT14PD, a, b);
        }
        Error vrsqrt14ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT14PS, a, b);
        }
        Error vrsqrt14ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT14PS, a, b);
        }
        Error vrsqrt14sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT14SD, a, b, c);
        }
        Error vrsqrt14sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT14SD, a, b, c);
        }
        Error vrsqrt14ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT14SS, a, b, c);
        }
        Error vrsqrt14ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT14SS, a, b, c);
        }
        Error vrsqrt28pd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT28PD, a, b);
        }
        Error vrsqrt28pd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT28PD, a, b);
        }
        Error vrsqrt28ps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT28PS, a, b);
        }
        Error vrsqrt28ps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT28PS, a, b);
        }
        Error vrsqrt28sd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT28SD, a, b, c);
        }
        Error vrsqrt28sd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT28SD, a, b, c);
        }
        Error vrsqrt28ss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT28SS, a, b, c);
        }
        Error vrsqrt28ss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRT28SS, a, b, c);
        }
        Error vrsqrtps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRTPS, a, b);
        }
        Error vrsqrtps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRTPS, a, b);
        }
        Error vrsqrtss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRTSS, a, b, c);
        }
        Error vrsqrtss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VRSQRTSS, a, b, c);
        }
        Error vscalefpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VSCALEFPD, a, b, c);
        }
        Error vscalefpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VSCALEFPD, a, b, c);
        }
        Error vscalefps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VSCALEFPS, a, b, c);
        }
        Error vscalefps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VSCALEFPS, a, b, c);
        }
        Error vscalefsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VSCALEFSD, a, b, c);
        }
        Error vscalefsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VSCALEFSD, a, b, c);
        }
        Error vscalefss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VSCALEFSS, a, b, c);
        }
        Error vscalefss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VSCALEFSS, a, b, c);
        }
        Error vscatterdpd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VSCATTERDPD, a, b);
        }
        Error vscatterdps(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VSCATTERDPS, a, b);
        }
        Error vscatterpf0dpd(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VSCATTERPF0DPD, a);
        }
        Error vscatterpf0dps(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VSCATTERPF0DPS, a);
        }
        Error vscatterpf0qpd(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VSCATTERPF0QPD, a);
        }
        Error vscatterpf0qps(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VSCATTERPF0QPS, a);
        }
        Error vscatterpf1dpd(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VSCATTERPF1DPD, a);
        }
        Error vscatterpf1dps(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VSCATTERPF1DPS, a);
        }
        Error vscatterpf1qpd(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VSCATTERPF1QPD, a);
        }
        Error vscatterpf1qps(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VSCATTERPF1QPS, a);
        }
        Error vscatterqpd(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VSCATTERQPD, a, b);
        }
        Error vscatterqps(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VSCATTERQPS, a, b);
        }
        Error vshuff32x4(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VSHUFF32X4, a, b, c, d);
        }
        Error vshuff32x4(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VSHUFF32X4, a, b, c, d);
        }
        Error vshuff64x2(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VSHUFF64X2, a, b, c, d);
        }
        Error vshuff64x2(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VSHUFF64X2, a, b, c, d);
        }
        Error vshufi32x4(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VSHUFI32X4, a, b, c, d);
        }
        Error vshufi32x4(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VSHUFI32X4, a, b, c, d);
        }
        Error vshufi64x2(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VSHUFI64X2, a, b, c, d);
        }
        Error vshufi64x2(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VSHUFI64X2, a, b, c, d);
        }
        Error vshufpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VSHUFPD, a, b, c, d);
        }
        Error vshufpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VSHUFPD, a, b, c, d);
        }
        Error vshufps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VSHUFPS, a, b, c, d);
        }
        Error vshufps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VSHUFPS, a, b, c, d);
        }
        Error vsqrtpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VSQRTPD, a, b);
        }
        Error vsqrtpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VSQRTPD, a, b);
        }
        Error vsqrtps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VSQRTPS, a, b);
        }
        Error vsqrtps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VSQRTPS, a, b);
        }
        Error vsqrtsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VSQRTSD, a, b, c);
        }
        Error vsqrtsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VSQRTSD, a, b, c);
        }
        Error vsqrtss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VSQRTSS, a, b, c);
        }
        Error vsqrtss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VSQRTSS, a, b, c);
        }
        Error vstmxcsr(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_VSTMXCSR, a);
        }
        Error vsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VSUBPD, a, b, c);
        }
        Error vsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VSUBPD, a, b, c);
        }
        Error vsubps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VSUBPS, a, b, c);
        }
        Error vsubps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VSUBPS, a, b, c);
        }
        Error vsubsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VSUBSD, a, b, c);
        }
        Error vsubsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VSUBSD, a, b, c);
        }
        Error vsubss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VSUBSS, a, b, c);
        }
        Error vsubss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VSUBSS, a, b, c);
        }
        Error vtestpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VTESTPD, a, b);
        }
        Error vtestpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VTESTPD, a, b);
        }
        Error vtestps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VTESTPS, a, b);
        }
        Error vtestps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VTESTPS, a, b);
        }
        Error vucomisd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VUCOMISD, a, b);
        }
        Error vucomisd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VUCOMISD, a, b);
        }
        Error vucomiss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VUCOMISS, a, b);
        }
        Error vucomiss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VUCOMISS, a, b);
        }
        Error vunpckhpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VUNPCKHPD, a, b, c);
        }
        Error vunpckhpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VUNPCKHPD, a, b, c);
        }
        Error vunpckhps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VUNPCKHPS, a, b, c);
        }
        Error vunpckhps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VUNPCKHPS, a, b, c);
        }
        Error vunpcklpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VUNPCKLPD, a, b, c);
        }
        Error vunpcklpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VUNPCKLPD, a, b, c);
        }
        Error vunpcklps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VUNPCKLPS, a, b, c);
        }
        Error vunpcklps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VUNPCKLPS, a, b, c);
        }
        Error vxorpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VXORPD, a, b, c);
        }
        Error vxorpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VXORPD, a, b, c);
        }
        Error vxorps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VXORPS, a, b, c);
        }
        Error vxorps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VXORPS, a, b, c);
        }
        Error vzeroall()
        {
            return emit(ZYDIS_MNEMONIC_VZEROALL);
        }
        Error vzeroupper()
        {
            return emit(ZYDIS_MNEMONIC_VZEROUPPER);
        }
        Error vfmaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDPD, a, b, c, d);
        }
        Error vfmaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDPD, a, b, c, d);
        }
        Error vfmaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDPD, a, b, c, d);
        }
        Error vfmaddps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDPS, a, b, c, d);
        }
        Error vfmaddps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDPS, a, b, c, d);
        }
        Error vfmaddps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDPS, a, b, c, d);
        }
        Error vfmaddsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSD, a, b, c, d);
        }
        Error vfmaddsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSD, a, b, c, d);
        }
        Error vfmaddsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSD, a, b, c, d);
        }
        Error vfmaddss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSS, a, b, c, d);
        }
        Error vfmaddss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSS, a, b, c, d);
        }
        Error vfmaddss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSS, a, b, c, d);
        }
        Error vfmaddsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUBPD, a, b, c, d);
        }
        Error vfmaddsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUBPD, a, b, c, d);
        }
        Error vfmaddsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUBPD, a, b, c, d);
        }
        Error vfmaddsubps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUBPS, a, b, c, d);
        }
        Error vfmaddsubps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUBPS, a, b, c, d);
        }
        Error vfmaddsubps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMADDSUBPS, a, b, c, d);
        }
        Error vfmsubaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADDPD, a, b, c, d);
        }
        Error vfmsubaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADDPD, a, b, c, d);
        }
        Error vfmsubaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADDPD, a, b, c, d);
        }
        Error vfmsubaddps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADDPS, a, b, c, d);
        }
        Error vfmsubaddps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADDPS, a, b, c, d);
        }
        Error vfmsubaddps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBADDPS, a, b, c, d);
        }
        Error vfmsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBPD, a, b, c, d);
        }
        Error vfmsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBPD, a, b, c, d);
        }
        Error vfmsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBPD, a, b, c, d);
        }
        Error vfmsubps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBPS, a, b, c, d);
        }
        Error vfmsubps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBPS, a, b, c, d);
        }
        Error vfmsubps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBPS, a, b, c, d);
        }
        Error vfmsubsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBSD, a, b, c, d);
        }
        Error vfmsubsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBSD, a, b, c, d);
        }
        Error vfmsubsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBSD, a, b, c, d);
        }
        Error vfmsubss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBSS, a, b, c, d);
        }
        Error vfmsubss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBSS, a, b, c, d);
        }
        Error vfmsubss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFMSUBSS, a, b, c, d);
        }
        Error vfnmaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADDPD, a, b, c, d);
        }
        Error vfnmaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADDPD, a, b, c, d);
        }
        Error vfnmaddpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADDPD, a, b, c, d);
        }
        Error vfnmaddps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADDPS, a, b, c, d);
        }
        Error vfnmaddps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADDPS, a, b, c, d);
        }
        Error vfnmaddps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADDPS, a, b, c, d);
        }
        Error vfnmaddsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADDSD, a, b, c, d);
        }
        Error vfnmaddsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADDSD, a, b, c, d);
        }
        Error vfnmaddsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADDSD, a, b, c, d);
        }
        Error vfnmaddss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADDSS, a, b, c, d);
        }
        Error vfnmaddss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADDSS, a, b, c, d);
        }
        Error vfnmaddss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMADDSS, a, b, c, d);
        }
        Error vfnmsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUBPD, a, b, c, d);
        }
        Error vfnmsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUBPD, a, b, c, d);
        }
        Error vfnmsubpd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUBPD, a, b, c, d);
        }
        Error vfnmsubps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUBPS, a, b, c, d);
        }
        Error vfnmsubps(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUBPS, a, b, c, d);
        }
        Error vfnmsubps(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUBPS, a, b, c, d);
        }
        Error vfnmsubsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUBSD, a, b, c, d);
        }
        Error vfnmsubsd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUBSD, a, b, c, d);
        }
        Error vfnmsubsd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUBSD, a, b, c, d);
        }
        Error vfnmsubss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUBSS, a, b, c, d);
        }
        Error vfnmsubss(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUBSS, a, b, c, d);
        }
        Error vfnmsubss(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VFNMSUBSS, a, b, c, d);
        }
        Error vfrczpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VFRCZPD, a, b);
        }
        Error vfrczpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VFRCZPD, a, b);
        }
        Error vfrczps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VFRCZPS, a, b);
        }
        Error vfrczps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VFRCZPS, a, b);
        }
        Error vfrczsd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VFRCZSD, a, b);
        }
        Error vfrczsd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VFRCZSD, a, b);
        }
        Error vfrczss(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VFRCZSS, a, b);
        }
        Error vfrczss(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VFRCZSS, a, b);
        }
        Error vpcmov(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMOV, a, b, c, d);
        }
        Error vpcmov(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMOV, a, b, c, d);
        }
        Error vpcmov(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCMOV, a, b, c, d);
        }
        Error vpcomb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMB, a, b, c, d);
        }
        Error vpcomb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMB, a, b, c, d);
        }
        Error vpcomd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMD, a, b, c, d);
        }
        Error vpcomd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMD, a, b, c, d);
        }
        Error vpcomq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMQ, a, b, c, d);
        }
        Error vpcomq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMQ, a, b, c, d);
        }
        Error vpcomw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMW, a, b, c, d);
        }
        Error vpcomw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMW, a, b, c, d);
        }
        Error vpcomub(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMUB, a, b, c, d);
        }
        Error vpcomub(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMUB, a, b, c, d);
        }
        Error vpcomud(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMUD, a, b, c, d);
        }
        Error vpcomud(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMUD, a, b, c, d);
        }
        Error vpcomuq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMUQ, a, b, c, d);
        }
        Error vpcomuq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMUQ, a, b, c, d);
        }
        Error vpcomuw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMUW, a, b, c, d);
        }
        Error vpcomuw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Imm& d)
        {
            return emit(ZYDIS_MNEMONIC_VPCOMUW, a, b, c, d);
        }
        Error vphaddbd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDBD, a, b);
        }
        Error vphaddbd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDBD, a, b);
        }
        Error vphaddbq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDBQ, a, b);
        }
        Error vphaddbq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDBQ, a, b);
        }
        Error vphaddbw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDBW, a, b);
        }
        Error vphaddbw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDBW, a, b);
        }
        Error vphadddq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDDQ, a, b);
        }
        Error vphadddq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDDQ, a, b);
        }
        Error vphaddwd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDWD, a, b);
        }
        Error vphaddwd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDWD, a, b);
        }
        Error vphaddwq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDWQ, a, b);
        }
        Error vphaddwq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDWQ, a, b);
        }
        Error vphaddubd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDUBD, a, b);
        }
        Error vphaddubd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDUBD, a, b);
        }
        Error vphaddubq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDUBQ, a, b);
        }
        Error vphaddubq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDUBQ, a, b);
        }
        Error vphaddubw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDUBW, a, b);
        }
        Error vphaddubw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDUBW, a, b);
        }
        Error vphaddudq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDUDQ, a, b);
        }
        Error vphaddudq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDUDQ, a, b);
        }
        Error vphadduwd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDUWD, a, b);
        }
        Error vphadduwd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDUWD, a, b);
        }
        Error vphadduwq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDUWQ, a, b);
        }
        Error vphadduwq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHADDUWQ, a, b);
        }
        Error vphsubbw(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHSUBBW, a, b);
        }
        Error vphsubbw(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHSUBBW, a, b);
        }
        Error vphsubdq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHSUBDQ, a, b);
        }
        Error vphsubdq(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHSUBDQ, a, b);
        }
        Error vphsubwd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHSUBWD, a, b);
        }
        Error vphsubwd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_VPHSUBWD, a, b);
        }
        Error vpmacsdd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSDD, a, b, c, d);
        }
        Error vpmacsdd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSDD, a, b, c, d);
        }
        Error vpmacsdqh(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSDQH, a, b, c, d);
        }
        Error vpmacsdqh(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSDQH, a, b, c, d);
        }
        Error vpmacsdql(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSDQL, a, b, c, d);
        }
        Error vpmacsdql(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSDQL, a, b, c, d);
        }
        Error vpmacswd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSWD, a, b, c, d);
        }
        Error vpmacswd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSWD, a, b, c, d);
        }
        Error vpmacsww(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSWW, a, b, c, d);
        }
        Error vpmacsww(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSWW, a, b, c, d);
        }
        Error vpmacssdd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSSDD, a, b, c, d);
        }
        Error vpmacssdd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSSDD, a, b, c, d);
        }
        Error vpmacssdqh(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSSDQH, a, b, c, d);
        }
        Error vpmacssdqh(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSSDQH, a, b, c, d);
        }
        Error vpmacssdql(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSSDQL, a, b, c, d);
        }
        Error vpmacssdql(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSSDQL, a, b, c, d);
        }
        Error vpmacsswd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSSWD, a, b, c, d);
        }
        Error vpmacsswd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSSWD, a, b, c, d);
        }
        Error vpmacssww(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSSWW, a, b, c, d);
        }
        Error vpmacssww(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMACSSWW, a, b, c, d);
        }
        Error vpmadcsswd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMADCSSWD, a, b, c, d);
        }
        Error vpmadcsswd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMADCSSWD, a, b, c, d);
        }
        Error vpmadcswd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMADCSWD, a, b, c, d);
        }
        Error vpmadcswd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPMADCSWD, a, b, c, d);
        }
        Error vpperm(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPPERM, a, b, c, d);
        }
        Error vpperm(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c, const operands::Reg& d)
        {
            return emit(ZYDIS_MNEMONIC_VPPERM, a, b, c, d);
        }
        Error vpperm(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c, const operands::Mem& d)
        {
            return emit(ZYDIS_MNEMONIC_VPPERM, a, b, c, d);
        }
        Error vprotb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTB, a, b, c);
        }
        Error vprotb(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTB, a, b, c);
        }
        Error vprotb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTB, a, b, c);
        }
        Error vprotb(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTB, a, b, c);
        }
        Error vprotb(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTB, a, b, c);
        }
        Error vprotd(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTD, a, b, c);
        }
        Error vprotd(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTD, a, b, c);
        }
        Error vprotd(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTD, a, b, c);
        }
        Error vprotd(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTD, a, b, c);
        }
        Error vprotd(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTD, a, b, c);
        }
        Error vprotq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTQ, a, b, c);
        }
        Error vprotq(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTQ, a, b, c);
        }
        Error vprotq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTQ, a, b, c);
        }
        Error vprotq(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTQ, a, b, c);
        }
        Error vprotq(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTQ, a, b, c);
        }
        Error vprotw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTW, a, b, c);
        }
        Error vprotw(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTW, a, b, c);
        }
        Error vprotw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTW, a, b, c);
        }
        Error vprotw(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTW, a, b, c);
        }
        Error vprotw(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPROTW, a, b, c);
        }
        Error vpshab(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHAB, a, b, c);
        }
        Error vpshab(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHAB, a, b, c);
        }
        Error vpshab(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHAB, a, b, c);
        }
        Error vpshad(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHAD, a, b, c);
        }
        Error vpshad(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHAD, a, b, c);
        }
        Error vpshad(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHAD, a, b, c);
        }
        Error vpshaq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHAQ, a, b, c);
        }
        Error vpshaq(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHAQ, a, b, c);
        }
        Error vpshaq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHAQ, a, b, c);
        }
        Error vpshaw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHAW, a, b, c);
        }
        Error vpshaw(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHAW, a, b, c);
        }
        Error vpshaw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHAW, a, b, c);
        }
        Error vpshlb(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLB, a, b, c);
        }
        Error vpshlb(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLB, a, b, c);
        }
        Error vpshlb(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLB, a, b, c);
        }
        Error vpshld(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLD, a, b, c);
        }
        Error vpshld(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLD, a, b, c);
        }
        Error vpshld(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLD, a, b, c);
        }
        Error vpshlq(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLQ, a, b, c);
        }
        Error vpshlq(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLQ, a, b, c);
        }
        Error vpshlq(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLQ, a, b, c);
        }
        Error vpshlw(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLW, a, b, c);
        }
        Error vpshlw(const operands::Reg& a, const operands::Mem& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLW, a, b, c);
        }
        Error vpshlw(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_VPSHLW, a, b, c);
        }
        Error cbw()
        {
            return emit(ZYDIS_MNEMONIC_CBW);
        }
        Error cdq()
        {
            return emit(ZYDIS_MNEMONIC_CDQ);
        }
        Error cdqe()
        {
            return emit(ZYDIS_MNEMONIC_CDQE);
        }
        Error cmpxchg(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CMPXCHG, a, b);
        }
        Error cmpxchg(const operands::Mem& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_CMPXCHG, a, b);
        }
        Error cmpxchg16b(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_CMPXCHG16B, a);
        }
        Error cmpxchg8b(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_CMPXCHG8B, a);
        }
        Error cpuid()
        {
            return emit(ZYDIS_MNEMONIC_CPUID);
        }
        Error cqo()
        {
            return emit(ZYDIS_MNEMONIC_CQO);
        }
        Error cwd()
        {
            return emit(ZYDIS_MNEMONIC_CWD);
        }
        Error cwde()
        {
            return emit(ZYDIS_MNEMONIC_CWDE);
        }
        Error daa()
        {
            return emit(ZYDIS_MNEMONIC_DAA);
        }
        Error das()
        {
            return emit(ZYDIS_MNEMONIC_DAS);
        }
        Error div(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_DIV, a);
        }
        Error div(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_DIV, a);
        }
        Error idiv(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_IDIV, a);
        }
        Error idiv(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_IDIV, a);
        }
        Error imul(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_IMUL, a);
        }
        Error imul(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_IMUL, a);
        }
        Error iret()
        {
            return emit(ZYDIS_MNEMONIC_IRET);
        }
        Error iretd()
        {
            return emit(ZYDIS_MNEMONIC_IRETD);
        }
        Error iretq()
        {
            return emit(ZYDIS_MNEMONIC_IRETQ);
        }
        Error jecxz(const operands::Label& a)
        {
            return emit(ZYDIS_MNEMONIC_JECXZ, a);
        }
        Error jecxz(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_JECXZ, a);
        }
        Error lahf()
        {
            return emit(ZYDIS_MNEMONIC_LAHF);
        }
        Error loop(const operands::Label& a)
        {
            return emit(ZYDIS_MNEMONIC_LOOP, a);
        }
        Error loop(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_LOOP, a);
        }
        Error loope(const operands::Label& a)
        {
            return emit(ZYDIS_MNEMONIC_LOOPE, a);
        }
        Error loope(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_LOOPE, a);
        }
        Error loopne(const operands::Label& a)
        {
            return emit(ZYDIS_MNEMONIC_LOOPNE, a);
        }
        Error loopne(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_LOOPNE, a);
        }
        Error mul(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_MUL, a);
        }
        Error mul(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_MUL, a);
        }
        Error rdmsr()
        {
            return emit(ZYDIS_MNEMONIC_RDMSR);
        }
        Error rdpmc()
        {
            return emit(ZYDIS_MNEMONIC_RDPMC);
        }
        Error rdtsc()
        {
            return emit(ZYDIS_MNEMONIC_RDTSC);
        }
        Error rdtscp()
        {
            return emit(ZYDIS_MNEMONIC_RDTSCP);
        }
        Error ret()
        {
            return emit(ZYDIS_MNEMONIC_RET);
        }
        Error ret(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_RET, a);
        }
        Error sahf()
        {
            return emit(ZYDIS_MNEMONIC_SAHF);
        }
        Error syscall()
        {
            return emit(ZYDIS_MNEMONIC_SYSCALL);
        }
        Error sysenter()
        {
            return emit(ZYDIS_MNEMONIC_SYSENTER);
        }
        Error sysexit()
        {
            return emit(ZYDIS_MNEMONIC_SYSEXIT);
        }
        Error sysexit64()
        {
            return emit(ZYDIS_MNEMONIC_SYSEXIT);
        }
        Error sysret()
        {
            return emit(ZYDIS_MNEMONIC_SYSRET);
        }
        Error sysret64()
        {
            return emit(ZYDIS_MNEMONIC_SYSRET);
        }
        Error wrmsr()
        {
            return emit(ZYDIS_MNEMONIC_WRMSR);
        }
        Error xlatb()
        {
            return emit(ZYDIS_MNEMONIC_XLAT);
        }
        Error clzero()
        {
            return emit(ZYDIS_MNEMONIC_CLZERO);
        }
        Error mulx(const operands::Reg& a, const operands::Reg& b, const operands::Reg& c)
        {
            return emit(ZYDIS_MNEMONIC_MULX, a, b, c);
        }
        Error mulx(const operands::Reg& a, const operands::Reg& b, const operands::Mem& c)
        {
            return emit(ZYDIS_MNEMONIC_MULX, a, b, c);
        }
        Error xgetbv()
        {
            return emit(ZYDIS_MNEMONIC_XGETBV);
        }
        Error xrstor(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_XRSTOR, a);
        }
        Error xrstor64(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_XRSTOR64, a);
        }
        Error xrstors(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_XRSTORS, a);
        }
        Error xrstors64(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_XRSTORS64, a);
        }
        Error xsave(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_XSAVE, a);
        }
        Error xsave64(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_XSAVE64, a);
        }
        Error xsavec(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_XSAVEC, a);
        }
        Error xsavec64(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_XSAVEC64, a);
        }
        Error xsaveopt(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_XSAVEOPT, a);
        }
        Error xsaveopt64(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_XSAVEOPT64, a);
        }
        Error xsaves(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_XSAVES, a);
        }
        Error xsaves64(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_XSAVES64, a);
        }
        Error xsetbv()
        {
            return emit(ZYDIS_MNEMONIC_XSETBV);
        }
        Error monitor()
        {
            return emit(ZYDIS_MNEMONIC_MONITOR);
        }
        Error monitorx()
        {
            return emit(ZYDIS_MNEMONIC_MONITORX);
        }
        Error mwait()
        {
            return emit(ZYDIS_MNEMONIC_MWAIT);
        }
        Error mwaitx()
        {
            return emit(ZYDIS_MNEMONIC_MWAITX);
        }
        Error blendvpd(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BLENDVPD, a, b);
        }
        Error blendvpd(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BLENDVPD, a, b);
        }
        Error blendvps(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_BLENDVPS, a, b);
        }
        Error blendvps(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_BLENDVPS, a, b);
        }
        Error pblendvb(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_PBLENDVB, a, b);
        }
        Error pblendvb(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_PBLENDVB, a, b);
        }
        Error maskmovq(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MASKMOVQ, a, b);
        }
        Error maskmovdqu(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_MASKMOVDQU, a, b);
        }
        Error pcmpestri(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PCMPESTRI, a, b, c);
        }
        Error pcmpestri(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PCMPESTRI, a, b, c);
        }
        Error pcmpestrm(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PCMPESTRM, a, b, c);
        }
        Error pcmpestrm(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PCMPESTRM, a, b, c);
        }
        Error pcmpistri(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PCMPISTRI, a, b, c);
        }
        Error pcmpistri(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PCMPISTRI, a, b, c);
        }
        Error pcmpistrm(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PCMPISTRM, a, b, c);
        }
        Error pcmpistrm(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_PCMPISTRM, a, b, c);
        }
        Error sha256rnds2(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_SHA256RNDS2, a, b);
        }
        Error sha256rnds2(const operands::Reg& a, const operands::Mem& b)
        {
            return emit(ZYDIS_MNEMONIC_SHA256RNDS2, a, b);
        }
        Error vmaskmovdqu(const operands::Reg& a, const operands::Reg& b)
        {
            return emit(ZYDIS_MNEMONIC_VMASKMOVDQU, a, b);
        }
        Error vpcmpestri(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPESTRI, a, b, c);
        }
        Error vpcmpestri(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPESTRI, a, b, c);
        }
        Error vpcmpestrm(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPESTRM, a, b, c);
        }
        Error vpcmpestrm(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPESTRM, a, b, c);
        }
        Error vpcmpistri(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPISTRI, a, b, c);
        }
        Error vpcmpistri(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPISTRI, a, b, c);
        }
        Error vpcmpistrm(const operands::Reg& a, const operands::Reg& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPISTRM, a, b, c);
        }
        Error vpcmpistrm(const operands::Reg& a, const operands::Mem& b, const operands::Imm& c)
        {
            return emit(ZYDIS_MNEMONIC_VPCMPISTRM, a, b, c);
        }
        Error jmp(const operands::Label& a)
        {
            return emit(ZYDIS_MNEMONIC_JMP, a);
        }
        Error jmp(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_JMP, a);
        }
        Error jmp(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_JMP, a);
        }
        Error jmp(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_JMP, a);
        }
        Error jnz(const operands::Label& a)
        {
            return emit(ZYDIS_MNEMONIC_JNZ, a);
        }
        Error jnz(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_JNZ, a);
        }
        Error jz(const operands::Label& a)
        {
            return emit(ZYDIS_MNEMONIC_JZ, a);
        }
        Error jz(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_JZ, a);
        }
        Error jnb(const operands::Label& a)
        {
            return emit(ZYDIS_MNEMONIC_JNB, a);
        }
        Error jnb(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_JNB, a);
        }
        Error jno(const operands::Label& a)
        {
            return emit(ZYDIS_MNEMONIC_JNO, a);
        }
        Error jno(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_JNO, a);
        }
        Error js(const operands::Label& a)
        {
            return emit(ZYDIS_MNEMONIC_JS, a);
        }
        Error js(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_JS, a);
        }
        Error jp(const operands::Label& a)
        {
            return emit(ZYDIS_MNEMONIC_JP, a);
        }
        Error jp(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_JP, a);
        }
        Error call(const operands::Reg& a)
        {
            return emit(ZYDIS_MNEMONIC_CALL, a);
        }
        Error call(const operands::Mem& a)
        {
            return emit(ZYDIS_MNEMONIC_CALL, a);
        }
        Error call(const operands::Label& a)
        {
            return emit(ZYDIS_MNEMONIC_CALL, a);
        }
        Error call(const operands::Imm& a)
        {
            return emit(ZYDIS_MNEMONIC_CALL, a);
        }
    };

} // namespace zasm