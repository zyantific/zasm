#include <zasm/x86/register.hpp>

namespace zasm::x86
{
    Gp Gp::r8lo() const noexcept
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

    Gp Gp::r8() const noexcept
    {
        return r8lo();
    }

    Gp Gp::r8hi() const noexcept
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

    Gp Gp::r16() const noexcept
    {
        auto regIndex = getPhysicalIndex();
        auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR16, regIndex);
        return Gp{ reg };
    }

    Gp Gp::r32() const noexcept
    {
        auto regIndex = getPhysicalIndex();
        auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR32, regIndex);
        return Gp{ reg };
    }

    Gp Gp::r64() const noexcept
    {
        auto regIndex = getPhysicalIndex();
        auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR64, regIndex);
        return Gp{ reg };
    }

} // namespace zasm::x86