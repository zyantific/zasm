#include <zasm/x86/register.hpp>

namespace zasm::x86
{
    static_assert(ZYDIS_REGISTER_AL < ZYDIS_REGISTER_AH);
    static constexpr int8_t kGp8HiStartIndex = ZYDIS_REGISTER_AH - ZYDIS_REGISTER_AL;
    static_assert(kGp8HiStartIndex == 4, "This should be 4, if this triggers the definition probably changed");

    Gp Gp::r8lo() const noexcept
    {
        auto regIndex = getPhysicalIndex();
        if (regIndex >= kGp8HiStartIndex)
        {
            // Skip the hi ones.
            regIndex += kGp8HiStartIndex;
        }
        const auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR8, regIndex);
        return Gp{ static_cast<Reg::Id>(reg) };
    }

    Gp Gp::r8() const noexcept
    {
        return r8lo();
    }

    Gp Gp::r8hi() const noexcept
    {
        const auto regIndex = getPhysicalIndex();
        if (regIndex >= kGp8HiStartIndex)
        {
            // Unsupported.
            return Gp{};
        }
        const auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR8, regIndex + kGp8HiStartIndex);
        return Gp{ static_cast<Reg::Id>(reg) };
    }

    Gp Gp::r16() const noexcept
    {
        const auto regIndex = getPhysicalIndex();
        const auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR16, regIndex);
        return Gp{ static_cast<Reg::Id>(reg) };
    }

    Gp Gp::r32() const noexcept
    {
        const auto regIndex = getPhysicalIndex();
        const auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR32, regIndex);
        return Gp{ static_cast<Reg::Id>(reg) };
    }

    Gp Gp::r64() const noexcept
    {
        const auto regIndex = getPhysicalIndex();
        const auto reg = ZydisRegisterEncode(ZYDIS_REGCLASS_GPR64, regIndex);
        return Gp{ static_cast<Reg::Id>(reg) };
    }

} // namespace zasm::x86
