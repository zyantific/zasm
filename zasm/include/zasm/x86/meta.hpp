#pragma once

#include <Zydis/Zydis.h>
#include <zasm/core/errors.hpp>
#include <zasm/core/expected.hpp>
#include <zasm/program/instruction.hpp>

namespace zasm::x86
{
    namespace Category
    {
        namespace detail
        {
            template<std::uint32_t TID> class Category : public zasm::InstrCategory
            {
            public:
                constexpr Category()
                    : zasm::InstrCategory{ TID }
                {
                }
            };
        } // namespace detail

        static constexpr detail::Category<ZYDIS_CATEGORY_INVALID> Invalid{};
        static constexpr detail::Category<ZYDIS_CATEGORY_ADOX_ADCX> AdoxAdcx{};
        static constexpr detail::Category<ZYDIS_CATEGORY_AES> Aes{};
        static constexpr detail::Category<ZYDIS_CATEGORY_AMD3DNOW> Amd3DNow{};
        static constexpr detail::Category<ZYDIS_CATEGORY_AMX_TILE> AMXTile{};
        static constexpr detail::Category<ZYDIS_CATEGORY_AVX> AVX{};
        static constexpr detail::Category<ZYDIS_CATEGORY_AVX2> AVX2{};
        static constexpr detail::Category<ZYDIS_CATEGORY_AVX2GATHER> AVX2Gather{};
        static constexpr detail::Category<ZYDIS_CATEGORY_AVX512> AVX512{};
        static constexpr detail::Category<ZYDIS_CATEGORY_AVX512_4FMAPS> AVX5124FMAPS{};
        static constexpr detail::Category<ZYDIS_CATEGORY_AVX512_4VNNIW> AVX5124VNIW{};
        static constexpr detail::Category<ZYDIS_CATEGORY_AVX512_BITALG> AVX512BITALG{};
        static constexpr detail::Category<ZYDIS_CATEGORY_AVX512_VBMI> AVX512VBMI{};
        static constexpr detail::Category<ZYDIS_CATEGORY_AVX512_VP2INTERSECT> AVX512VP2INTERSECT{};
        static constexpr detail::Category<ZYDIS_CATEGORY_BINARY> Binary{};
        static constexpr detail::Category<ZYDIS_CATEGORY_BITBYTE> BitByte{};
        static constexpr detail::Category<ZYDIS_CATEGORY_BLEND> Blend{};
        static constexpr detail::Category<ZYDIS_CATEGORY_BMI1> BMI1{};
        static constexpr detail::Category<ZYDIS_CATEGORY_BMI2> BMI2{};
        static constexpr detail::Category<ZYDIS_CATEGORY_BROADCAST> Broadcast{};
        static constexpr detail::Category<ZYDIS_CATEGORY_CALL> Call{};
        static constexpr detail::Category<ZYDIS_CATEGORY_CET> Cet{};
        static constexpr detail::Category<ZYDIS_CATEGORY_CLDEMOTE> CldEmote{};
        static constexpr detail::Category<ZYDIS_CATEGORY_CLFLUSHOPT> CLFlushOpt{};
        static constexpr detail::Category<ZYDIS_CATEGORY_CLWB> ClWb{};
        static constexpr detail::Category<ZYDIS_CATEGORY_CLZERO> ClZero{};
        static constexpr detail::Category<ZYDIS_CATEGORY_CMOV> Cmov{};
        static constexpr detail::Category<ZYDIS_CATEGORY_COMPRESS> Compress{};
        static constexpr detail::Category<ZYDIS_CATEGORY_COND_BR> CondBr{};
        static constexpr detail::Category<ZYDIS_CATEGORY_CONFLICT> Conflict{};
        static constexpr detail::Category<ZYDIS_CATEGORY_CONVERT> Convert{};
        static constexpr detail::Category<ZYDIS_CATEGORY_DATAXFER> DataXfer{};
        static constexpr detail::Category<ZYDIS_CATEGORY_DECIMAL> Decimal{};
        static constexpr detail::Category<ZYDIS_CATEGORY_ENQCMD> EnqCmd{};
        static constexpr detail::Category<ZYDIS_CATEGORY_EXPAND> Expand{};
        static constexpr detail::Category<ZYDIS_CATEGORY_FCMOV> FCmov{};
        static constexpr detail::Category<ZYDIS_CATEGORY_FLAGOP> FlagOp{};
        static constexpr detail::Category<ZYDIS_CATEGORY_FMA4> FMA4{};
        static constexpr detail::Category<ZYDIS_CATEGORY_FP16> FP16{};
        static constexpr detail::Category<ZYDIS_CATEGORY_GATHER> Gather{};
        static constexpr detail::Category<ZYDIS_CATEGORY_GFNI> GFNI{};
        static constexpr detail::Category<ZYDIS_CATEGORY_HRESET> HReset{};
        static constexpr detail::Category<ZYDIS_CATEGORY_IFMA> IFMA{};
        static constexpr detail::Category<ZYDIS_CATEGORY_INTERRUPT> Interrupt{};
        static constexpr detail::Category<ZYDIS_CATEGORY_IO> IO{};
        static constexpr detail::Category<ZYDIS_CATEGORY_IOSTRINGOP> IOStringOp{};
        static constexpr detail::Category<ZYDIS_CATEGORY_KEYLOCKER> KeyLocker{};
        static constexpr detail::Category<ZYDIS_CATEGORY_KEYLOCKER_WIDE> KeyLockerWide{};
        static constexpr detail::Category<ZYDIS_CATEGORY_KMASK> KMask{};
        static constexpr detail::Category<ZYDIS_CATEGORY_KNC> KNC{};
        static constexpr detail::Category<ZYDIS_CATEGORY_KNCMASK> KNCMask{};
        static constexpr detail::Category<ZYDIS_CATEGORY_KNCSCALAR> KNCScalar{};
        static constexpr detail::Category<ZYDIS_CATEGORY_LEGACY> Legacy{};
        static constexpr detail::Category<ZYDIS_CATEGORY_LOGICAL> Logical{};
        static constexpr detail::Category<ZYDIS_CATEGORY_LOGICAL_FP> LogicalFP{};
        static constexpr detail::Category<ZYDIS_CATEGORY_LZCNT> LZCNT{};
        static constexpr detail::Category<ZYDIS_CATEGORY_MISC> Misc{};
        static constexpr detail::Category<ZYDIS_CATEGORY_MMX> MMX{};
        static constexpr detail::Category<ZYDIS_CATEGORY_MOVDIR> MovDir{};
        static constexpr detail::Category<ZYDIS_CATEGORY_MPX> MPX{};
        static constexpr detail::Category<ZYDIS_CATEGORY_NOP> NOP{};
        static constexpr detail::Category<ZYDIS_CATEGORY_PADLOCK> PadLock{};
        static constexpr detail::Category<ZYDIS_CATEGORY_PCLMULQDQ> PCLMulqDq{};
        static constexpr detail::Category<ZYDIS_CATEGORY_PCONFIG> PConfig{};
        static constexpr detail::Category<ZYDIS_CATEGORY_PKU> PKU{};
        static constexpr detail::Category<ZYDIS_CATEGORY_POP> Pop{};
        static constexpr detail::Category<ZYDIS_CATEGORY_PREFETCH> Prefetch{};
        static constexpr detail::Category<ZYDIS_CATEGORY_PREFETCHWT1> PrefetchWt1{};
        static constexpr detail::Category<ZYDIS_CATEGORY_PT> Pt{};
        static constexpr detail::Category<ZYDIS_CATEGORY_PUSH> Push{};
        static constexpr detail::Category<ZYDIS_CATEGORY_RDPID> Rdpid{};
        static constexpr detail::Category<ZYDIS_CATEGORY_RDPRU> Rdpru{};
        static constexpr detail::Category<ZYDIS_CATEGORY_RDRAND> Rdrand{};
        static constexpr detail::Category<ZYDIS_CATEGORY_RDSEED> Rdseed{};
        static constexpr detail::Category<ZYDIS_CATEGORY_RDWRFSGS> RdWrFsGs{};
        static constexpr detail::Category<ZYDIS_CATEGORY_RET> Ret{};
        static constexpr detail::Category<ZYDIS_CATEGORY_ROTATE> Rotate{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SCATTER> Scatter{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SEGOP> SegOp{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SEMAPHORE> Semaphore{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SERIALIZE> Serialize{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SETCC> SetCC{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SGX> SGX{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SHA> SHA{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SHIFT> Shift{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SMAP> Smap{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SSE> SSE{};
        static constexpr detail::Category<ZYDIS_CATEGORY_STRINGOP> StringOp{};
        static constexpr detail::Category<ZYDIS_CATEGORY_STTNI> STTNI{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SYSCALL> Syscall{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SYSRET> Sysret{};
        static constexpr detail::Category<ZYDIS_CATEGORY_SYSTEM> System{};
        static constexpr detail::Category<ZYDIS_CATEGORY_TBM> TBM{};
        static constexpr detail::Category<ZYDIS_CATEGORY_TSX_LDTRK> TSXLdtrk{};
        static constexpr detail::Category<ZYDIS_CATEGORY_UFMA> UFMA{};
        static constexpr detail::Category<ZYDIS_CATEGORY_UINTR> UINTR{};
        static constexpr detail::Category<ZYDIS_CATEGORY_UNCOND_BR> UncondBR{};
        static constexpr detail::Category<ZYDIS_CATEGORY_VAES> VAES{};
        static constexpr detail::Category<ZYDIS_CATEGORY_VBMI2> VBMI2{};
        static constexpr detail::Category<ZYDIS_CATEGORY_VEX> VEX{};
        static constexpr detail::Category<ZYDIS_CATEGORY_VFMA> VFMA{};
        static constexpr detail::Category<ZYDIS_CATEGORY_VPCLMULQDQ> VPCLMulqDq{};
        static constexpr detail::Category<ZYDIS_CATEGORY_VTX> VTX{};
        static constexpr detail::Category<ZYDIS_CATEGORY_WAITPKG> WaitPkg{};
        static constexpr detail::Category<ZYDIS_CATEGORY_WIDENOP> WideNop{};
        static constexpr detail::Category<ZYDIS_CATEGORY_X87_ALU> X86ALU{};
        static constexpr detail::Category<ZYDIS_CATEGORY_XOP> XOP{};
        static constexpr detail::Category<ZYDIS_CATEGORY_XSAVE> XSAVE{};
        static constexpr detail::Category<ZYDIS_CATEGORY_XSAVEOPT> XSAVEOPT{};

    } // namespace Category

    namespace Attribs
    {
        namespace detail
        {
            template<std::uint32_t TID> class Attribs : public zasm::InstrAttribs
            {
            public:
                constexpr Attribs()
                    : zasm::InstrAttribs{ TID }
                {
                }
            };
        } // namespace detail

        static constexpr detail::Attribs<0U> None{};
        static constexpr detail::Attribs<1U << 0U> Lock{};
        static constexpr detail::Attribs<1U << 1U> Rep{};
        static constexpr detail::Attribs<1U << 2U> Repe{};
        static constexpr detail::Attribs<1U << 3U> Repne{};
        static constexpr detail::Attribs<1U << 4U> Bnd{};
        static constexpr detail::Attribs<1U << 5U> Xacquire{};
        static constexpr detail::Attribs<1U << 6U> Xrelease{};
        static constexpr detail::Attribs<1U << 7U> OperandSize8{};
        static constexpr detail::Attribs<1U << 8U> OperandSize16{};
        static constexpr detail::Attribs<1U << 9U> OperandSize32{};
        static constexpr detail::Attribs<1U << 10U> OperandSize64{};

    } // namespace Attribs

    namespace CPUFlags
    {
        namespace detail
        {
            template<std::uint32_t TID> class CPUFlags : public zasm::InstrCPUFlags
            {
            public:
                constexpr CPUFlags()
                    : zasm::InstrCPUFlags{ TID }
                {
                }
            };
        } // namespace detail

        static constexpr detail::CPUFlags<0U> None{};
        static constexpr detail::CPUFlags<1U << 0U> CF{};
        static constexpr detail::CPUFlags<1U << 1U> Reserved0{};
        static constexpr detail::CPUFlags<1U << 2U> PF{};
        static constexpr detail::CPUFlags<1U << 3U> Reserved1{};
        static constexpr detail::CPUFlags<1U << 4U> AF{};
        static constexpr detail::CPUFlags<1U << 5U> Reserved2{};
        static constexpr detail::CPUFlags<1U << 6U> ZF{};
        static constexpr detail::CPUFlags<1U << 7U> SF{};
        static constexpr detail::CPUFlags<1U << 8U> TF{};
        static constexpr detail::CPUFlags<1U << 9U> IF{};
        static constexpr detail::CPUFlags<1U << 10U> DF{};
        static constexpr detail::CPUFlags<1U << 11U> OF{};
        static constexpr detail::CPUFlags<1U << 12U> IOPL1{};
        static constexpr detail::CPUFlags<1U << 13U> IOPL2{};
        static constexpr detail::CPUFlags<1U << 14U> NT{};
        static constexpr detail::CPUFlags<1U << 15U> MD{};
        static constexpr detail::CPUFlags<1U << 16U> RF{};
        static constexpr detail::CPUFlags<1U << 17U> VM{};
        static constexpr detail::CPUFlags<1U << 18U> AC{};
        static constexpr detail::CPUFlags<1U << 19U> VIF{};
        static constexpr detail::CPUFlags<1U << 20U> VIP{};
        static constexpr detail::CPUFlags<1U << 21U> ID{};
        static constexpr detail::CPUFlags<1U << 22U> Reserved3{};
        static constexpr detail::CPUFlags<1U << 23U> Reserved4{};
        static constexpr detail::CPUFlags<1U << 24U> Reserved5{};
        static constexpr detail::CPUFlags<1U << 25U> Reserved6{};
        static constexpr detail::CPUFlags<1U << 26U> Reserved7{};
        static constexpr detail::CPUFlags<1U << 27U> Reserved8{};
        static constexpr detail::CPUFlags<1U << 28U> Reserved9{};
        static constexpr detail::CPUFlags<1U << 29U> Reserved10{};
        static constexpr detail::CPUFlags<1U << 30U> AES{};
        static constexpr detail::CPUFlags<1U << 31U> Reserved11{};
    }

} // namespace zasm::x86
