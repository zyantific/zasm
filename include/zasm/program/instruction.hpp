#pragma once

#include "operand.hpp"

#include <Zydis/Zydis.h>
#include <array>
#include <zasm/core/enumflags.hpp>

namespace zasm
{
    namespace detail
    {
        enum class InstructionAttribs : uint16_t
        {
            None = 0,
            Lock = (1u << 0),
            Rep = (1u << 1),
            Repe = (1u << 2),
            Repne = (1u << 3),
            Bnd = (1u << 4),
            Xacquire = (1u << 5),
            Xrelease = (1u << 6),
            OperandSize8 = (1u << 7),
            OperandSize16 = (1u << 8),
            OperandSize32 = (1u << 9),
            OperandSize64 = (1u << 10),
        };
        ZASM_ENABLE_ENUM_OPERATORS(InstructionAttribs);

        enum class InstructionEncoding : uint8_t
        {
            Legacy = ZYDIS_INSTRUCTION_ENCODING_LEGACY,
            _3DNow = ZYDIS_INSTRUCTION_ENCODING_3DNOW,
            XOP = ZYDIS_INSTRUCTION_ENCODING_XOP,
            VEX = ZYDIS_INSTRUCTION_ENCODING_VEX,
            EVEX = ZYDIS_INSTRUCTION_ENCODING_EVEX,
            MVEX = ZYDIS_INSTRUCTION_ENCODING_MVEX,
        };

        enum class InstructionCategory : uint8_t
        {
            Invalid = ZYDIS_CATEGORY_INVALID,
            AdoxAdcx = ZYDIS_CATEGORY_ADOX_ADCX,
            Aes = ZYDIS_CATEGORY_AES,
            Amd3DNow = ZYDIS_CATEGORY_AMD3DNOW,
            AMXTile = ZYDIS_CATEGORY_AMX_TILE,
            AVX = ZYDIS_CATEGORY_AVX,
            AVX2 = ZYDIS_CATEGORY_AVX2,
            AVX2Gather = ZYDIS_CATEGORY_AVX2GATHER,
            AVX512 = ZYDIS_CATEGORY_AVX512,
            AVX5124FMAPS = ZYDIS_CATEGORY_AVX512_4FMAPS,
            AVX5124VNIW = ZYDIS_CATEGORY_AVX512_4VNNIW,
            AVX512BITALG = ZYDIS_CATEGORY_AVX512_BITALG,
            AVX512VBMI = ZYDIS_CATEGORY_AVX512_VBMI,
            AVX512VP2INTERSECT = ZYDIS_CATEGORY_AVX512_VP2INTERSECT,
            Binary = ZYDIS_CATEGORY_BINARY,
            BitByte = ZYDIS_CATEGORY_BITBYTE,
            Blend = ZYDIS_CATEGORY_BLEND,
            BMI1 = ZYDIS_CATEGORY_BMI1,
            BMI2 = ZYDIS_CATEGORY_BMI2,
            Broadcast = ZYDIS_CATEGORY_BROADCAST,
            Call = ZYDIS_CATEGORY_CALL,
            Cet = ZYDIS_CATEGORY_CET,
            CldEmote = ZYDIS_CATEGORY_CLDEMOTE,
            CLFlushOpt = ZYDIS_CATEGORY_CLFLUSHOPT,
            ClWb = ZYDIS_CATEGORY_CLWB,
            ClZero = ZYDIS_CATEGORY_CLZERO,
            Cmov = ZYDIS_CATEGORY_CMOV,
            Compress = ZYDIS_CATEGORY_COMPRESS,
            CondBr = ZYDIS_CATEGORY_COND_BR,
            Conflict = ZYDIS_CATEGORY_CONFLICT,
            Convert = ZYDIS_CATEGORY_CONVERT,
            DataXfer = ZYDIS_CATEGORY_DATAXFER,
            Decimal = ZYDIS_CATEGORY_DECIMAL,
            EnqCmd = ZYDIS_CATEGORY_ENQCMD,
            Expand = ZYDIS_CATEGORY_EXPAND,
            FCmov = ZYDIS_CATEGORY_FCMOV,
            FlagOp = ZYDIS_CATEGORY_FLAGOP,
            FMA4 = ZYDIS_CATEGORY_FMA4,
            FP16 = ZYDIS_CATEGORY_FP16,
            Gather = ZYDIS_CATEGORY_GATHER,
            GFNI = ZYDIS_CATEGORY_GFNI,
            HReset = ZYDIS_CATEGORY_HRESET,
            IFMA = ZYDIS_CATEGORY_IFMA,
            Interrupt = ZYDIS_CATEGORY_INTERRUPT,
            IO = ZYDIS_CATEGORY_IO,
            IOStringOp = ZYDIS_CATEGORY_IOSTRINGOP,
            KeyLocker = ZYDIS_CATEGORY_KEYLOCKER,
            KeyLockerWide = ZYDIS_CATEGORY_KEYLOCKER_WIDE,
            KMask = ZYDIS_CATEGORY_KMASK,
            KNC = ZYDIS_CATEGORY_KNC,
            KNCMask = ZYDIS_CATEGORY_KNCMASK,
            KNCScalar = ZYDIS_CATEGORY_KNCSCALAR,
            Legacy = ZYDIS_CATEGORY_LEGACY,
            Logical = ZYDIS_CATEGORY_LOGICAL,
            LogicalFP = ZYDIS_CATEGORY_LOGICAL_FP,
            LZCNT = ZYDIS_CATEGORY_LZCNT,
            Misc = ZYDIS_CATEGORY_MISC,
            MMX = ZYDIS_CATEGORY_MMX,
            MovDir = ZYDIS_CATEGORY_MOVDIR,
            MPX = ZYDIS_CATEGORY_MPX,
            NOP = ZYDIS_CATEGORY_NOP,
            PadLock = ZYDIS_CATEGORY_PADLOCK,
            PCLMulqDq = ZYDIS_CATEGORY_PCLMULQDQ,
            PConfig = ZYDIS_CATEGORY_PCONFIG,
            PKU = ZYDIS_CATEGORY_PKU,
            Pop = ZYDIS_CATEGORY_POP,
            Prefetch = ZYDIS_CATEGORY_PREFETCH,
            PrefetchWt1 = ZYDIS_CATEGORY_PREFETCHWT1,
            Pt = ZYDIS_CATEGORY_PT,
            Push = ZYDIS_CATEGORY_PUSH,
            Rdpid = ZYDIS_CATEGORY_RDPID,
            Rdpru = ZYDIS_CATEGORY_RDPRU,
            Rdrand = ZYDIS_CATEGORY_RDRAND,
            Rdseed = ZYDIS_CATEGORY_RDSEED,
            RdWrFsGs = ZYDIS_CATEGORY_RDWRFSGS,
            Ret = ZYDIS_CATEGORY_RET,
            Rotate = ZYDIS_CATEGORY_ROTATE,
            Scatter = ZYDIS_CATEGORY_SCATTER,
            SegOp = ZYDIS_CATEGORY_SEGOP,
            Semaphore = ZYDIS_CATEGORY_SEMAPHORE,
            Serialize = ZYDIS_CATEGORY_SERIALIZE,
            SetCC = ZYDIS_CATEGORY_SETCC,
            SGX = ZYDIS_CATEGORY_SGX,
            SHA = ZYDIS_CATEGORY_SHA,
            Shift = ZYDIS_CATEGORY_SHIFT,
            Smap = ZYDIS_CATEGORY_SMAP,
            SSE = ZYDIS_CATEGORY_SSE,
            StringOp = ZYDIS_CATEGORY_STRINGOP,
            STTNI = ZYDIS_CATEGORY_STTNI,
            Syscall = ZYDIS_CATEGORY_SYSCALL,
            Sysret = ZYDIS_CATEGORY_SYSRET,
            System = ZYDIS_CATEGORY_SYSTEM,
            TBM = ZYDIS_CATEGORY_TBM,
            TSXLdtrk = ZYDIS_CATEGORY_TSX_LDTRK,
            UFMA = ZYDIS_CATEGORY_UFMA,
            UINTR = ZYDIS_CATEGORY_UINTR,
            UncondBR = ZYDIS_CATEGORY_UNCOND_BR,
            VAES = ZYDIS_CATEGORY_VAES,
            VBMI2 = ZYDIS_CATEGORY_VBMI2,
            VEX = ZYDIS_CATEGORY_VEX,
            VFMA = ZYDIS_CATEGORY_VFMA,
            VPCLMulqDq = ZYDIS_CATEGORY_VPCLMULQDQ,
            VTX = ZYDIS_CATEGORY_VTX,
            WaitPkg = ZYDIS_CATEGORY_WAITPKG,
            WideNop = ZYDIS_CATEGORY_WIDENOP,
            X86ALU = ZYDIS_CATEGORY_X87_ALU,
            XOP = ZYDIS_CATEGORY_XOP,
            XSAVE = ZYDIS_CATEGORY_XSAVE,
            XSAVEOPT = ZYDIS_CATEGORY_XSAVEOPT,
        };

    } // namespace detail

#pragma pack(push, 1)
    class Instruction
    {
    public:
        // For debug builds this makes inspection easier.
        // For release builds size matters more.
#ifdef _DEBUG
        using Mnemonic = ZydisMnemonic;
#else
        using Mnemonic = uint16_t;
#endif
        using Operands = std::array<Operand, ZYDIS_MAX_OPERAND_COUNT>;
        using Access = std::array<ZydisOperandActions, ZYDIS_MAX_OPERAND_COUNT>;
        using OperandsVisibility = std::array<Operand::Visibility, ZYDIS_MAX_OPERAND_COUNT>;
        using OperandsEncoding = std::array<Operand::Encoding, ZYDIS_MAX_OPERAND_COUNT>;
        using Encoding = detail::InstructionEncoding;
        using Length = uint8_t;
        using Attribs = detail::InstructionAttribs;
        using Category = detail::InstructionCategory;

        struct Flags
        {
            uint32_t read;
            uint32_t write;
            uint32_t undefined;
        };

    private:
        const Operands _operands{};
        const size_t _opCount{};
        const Mnemonic _id{};
        const Access _access{};
        const OperandsVisibility _opsVisibility{};
        const OperandsEncoding _opsEncoding{};
        const Encoding _encoding{};
        const Flags _flags{};
        const Category _category{};
        const Attribs _attribs{};
        const Length _length{};

    public:
        constexpr Instruction() noexcept = default;
        constexpr Instruction(
            Attribs attribs, ZydisMnemonic mnemonic, size_t opCount, const Operands& operands, const Access& access,
            const OperandsVisibility& opsVisibility, const OperandsEncoding& opsEncoding, const Flags& flags,
            const Encoding& encoding, const Category& category, Length length = 0) noexcept
            : _operands{ operands }
            , _opCount{ opCount }
            , _id{ static_cast<Mnemonic>(mnemonic) }
            , _access{ access }
            , _opsVisibility{ opsVisibility }
            , _opsEncoding{ opsEncoding }
            , _encoding{ encoding }
            , _flags{ flags }
            , _category{ category }
            , _attribs{ attribs }
            , _length{ length }
        {
        }

        constexpr ZydisMnemonic getId() const noexcept
        {
            return static_cast<ZydisMnemonic>(_id);
        }

        constexpr Attribs getAttribs() const noexcept
        {
            return _attribs;
        }

        constexpr Encoding getEncoding() const noexcept
        {
            return _encoding;
        }

        constexpr Category getCategory() const noexcept
        {
            return _category;
        }

        constexpr bool hasAttrib(Attribs attrib) const noexcept
        {
            return (_attribs & attrib) != Attribs::None;
        }

        constexpr Length getLength() const noexcept
        {
            return _length;
        }

        constexpr const Operands& getOperands() const noexcept
        {
            return _operands;
        }

        constexpr size_t getOperandCount() const noexcept
        {
            return _opCount;
        }

        template<size_t TIndex, typename T = Operand> constexpr const T& getOperand() const
        {
            if constexpr (std::is_same_v<T, Operand>)
            {
                return std::get<TIndex>(_operands);
            }
            else
            {
                auto& op = std::get<TIndex>(_operands);
                return op.template as<T>();
            }
        }

        constexpr const Operand& getOperand(size_t index) const noexcept
        {
            return _operands[index];
        }

        template<typename T> constexpr const T* tryGetOperandAs(size_t index) const noexcept
        {
            if (index >= _operands.size())
                return nullptr;

            auto& op = _operands[index];
            return op.template tryAs<T>();
        }

        constexpr const OperandsVisibility& getOperandsVisibility() const noexcept
        {
            return _opsVisibility;
        }

        constexpr const Operand::Visibility getOperandVisibility(size_t index) const noexcept
        {
            if (index >= _opsVisibility.size())
                return Operand::Visibility::Invalid;
            return _opsVisibility[index];
        }

        constexpr bool isOperandHidden(size_t index) const noexcept
        {
            if (index >= _opCount)
                return true;
            return _opsVisibility[index] == Operand::Visibility::Hidden;
        }

        constexpr bool isOperandExplicit(size_t index) const noexcept
        {
            if (index >= _opCount)
                return false;
            return _opsVisibility[index] == Operand::Visibility::Explicit;
        }

        constexpr bool isOperandImplicit(size_t index) const noexcept
        {
            if (index >= _opCount)
                return false;
            return _opsVisibility[index] == Operand::Visibility::Implicit;
        }

        constexpr const OperandsEncoding& getOperandsEncoding() const noexcept
        {
            return _opsEncoding;
        }

        constexpr const Operand::Encoding getOperandEncoding(size_t index) const noexcept
        {
            if (index >= _opCount)
                return Operand::Encoding::None;
            return _opsEncoding[index];
        }

        constexpr const Access& getAccess() const noexcept
        {
            return _access;
        }

        constexpr const Flags& getFlags() const noexcept
        {
            return _flags;
        }
    };
#pragma pack(pop)

} // namespace zasm