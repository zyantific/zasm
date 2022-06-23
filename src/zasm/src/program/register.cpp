#include <zasm/program/register.hpp>

namespace zasm::operands
{
    BitSize Reg::getSize(ZydisMachineMode mode) const noexcept
    {
        return toBitSize(ZydisRegisterGetWidth(mode, getId()));
    }

    ZydisRegisterClass Reg::getClass() const noexcept
    {
        return ZydisRegisterGetClass(getId());
    }

    int8_t Reg::getIndex() const noexcept
    {
        return ZydisRegisterGetId(getId());
    }

    int8_t Reg::getPhysicalIndex() const noexcept
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

    Reg Reg::getRoot(ZydisMachineMode mode) const noexcept
    {
        return Reg{ ZydisRegisterGetLargestEnclosing(mode, getId()) };
    }

    bool Reg::isGp8() const noexcept
    {
        return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_GPR8;
    }

    bool Reg::isGp8Lo() const noexcept
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

    bool Reg::isGp8Hi() const noexcept
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

    bool Reg::isGp16() const noexcept
    {
        return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_GPR16;
    }

    bool Reg::isGp32() const noexcept
    {
        return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_GPR32;
    }

    bool Reg::isGp64() const noexcept
    {
        return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_GPR64;
    }

    bool Reg::isGp() const noexcept
    {
        return isGp8() || isGp16() || isGp32() || isGp64();
    }

    bool Reg::isXmm() const noexcept
    {
        return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_XMM;
    }

    bool Reg::isYmm() const noexcept
    {
        return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_YMM;
    }

    bool Reg::isZmm() const noexcept
    {
        return getClass() == ZydisRegisterClass::ZYDIS_REGCLASS_ZMM;
    }

} // namespace zasm::operands