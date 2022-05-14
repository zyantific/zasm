#pragma once

#include "label.hpp"
#include "register.hpp"
#include "zasm/core/bitsize.hpp"

namespace zasm::operands
{
#pragma pack(push, 1)
    class Mem
    {
        BitSize _bitSize{};
        Seg::Id _seg{};
        Reg::Id _base{};
        Reg::Id _index{};
        uint8_t _scale{};
        int64_t _disp{};
        Label::Id _label{ Label::Id::Invalid };

    public:
        constexpr Mem(BitSize bitSize, const Seg& seg, const Reg& base, const Reg& index, int32_t scale, int64_t disp) noexcept
            : _bitSize{ bitSize }
            , _seg{ static_cast<Seg::Id>(seg.getId()) }
            , _base{ static_cast<Reg::Id>(base.getId()) }
            , _index{ static_cast<Reg::Id>(index.getId()) }
            , _scale{ static_cast<uint8_t>(scale) }
            , _disp{ disp }
            , _label{ Label::Id::Invalid }
        {
        }

        constexpr Mem(
            BitSize bitSize, const Seg& seg, const Label& label, const Reg& base, const Reg& index, int32_t scale, int64_t disp) noexcept
            : _bitSize{ bitSize }
            , _seg{ static_cast<Seg::Id>(seg.getId()) }
            , _base{ static_cast<Reg::Id>(base.getId()) }
            , _index{ static_cast<Reg::Id>(index.getId()) }
            , _scale{ static_cast<uint8_t>(scale) }
            , _disp{ disp }
            , _label{ label.getId() }
        {
        }

        constexpr Seg getSegment() const noexcept
        {
            return Seg{ _seg };
        }

        constexpr Reg getBase() const noexcept
        {
            return Reg{ _base };
        }

        constexpr Reg getIndex() const noexcept
        {
            return Reg{ _index };
        }

        constexpr uint8_t getScale() const noexcept
        {
            // In case no index is assigned scale has to be zero.
            if (_index == static_cast<Reg::Id>(ZYDIS_REGISTER_NONE))
                return 0;

            return _scale;
        }

        constexpr int64_t getDisplacement() const noexcept
        {
            return _disp;
        }

        constexpr BitSize getBitSize() const noexcept
        {
            return _bitSize;
        }

        constexpr int32_t getByteSize() const noexcept
        {
            return ::zasm::getBitSize(_bitSize) / 8;
        }

        constexpr Label getLabel() const noexcept
        {
            return Label{ _label };
        }

        constexpr Label::Id getLabelId() const noexcept
        {
            return _label;
        }

        constexpr bool hasLabel() const noexcept
        {
            return _label != Label::Id::Invalid;
        }
    };
#pragma pack(pop)

    static constexpr auto SizeOfMem = sizeof(Mem);

    static constexpr Mem ptr(BitSize bitSize, const Reg& base, int32_t offset = 0) noexcept
    {
        return Mem(bitSize, Seg{}, base, {}, 0, offset);
    }

    static constexpr Mem ptr(BitSize bitSize, const Reg& base, const Reg& index, int32_t scale, int32_t offset) noexcept
    {
        return Mem(bitSize, Seg{}, base, index, scale, offset);
    }

    static constexpr Mem ptr(BitSize bitSize, const Label& base, int32_t offset = 0) noexcept
    {
        return Mem(bitSize, Seg{}, base, Reg{}, Reg{}, 0, offset);
    }

    static constexpr Mem ptr(BitSize bitSize, const Rip& rip_, const Label& base, int32_t offset = 0) noexcept
    {
        return Mem(bitSize, Seg{}, base, rip_, Reg{}, 0, offset);
    }

    static constexpr Mem ptr(BitSize bitSize, int64_t base) noexcept
    {
        return Mem(bitSize, Seg{}, Reg{}, Reg{}, 0, base);
    }

    static constexpr Mem ptr(BitSize bitSize, int64_t base, const Reg& index, int32_t scale) noexcept
    {
        return Mem(bitSize, Seg{}, Reg{}, index, scale, base);
    }

    template<typename... TArgs> static Mem byte_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_8, args...);
    };
    template<typename... TArgs> static Mem word_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_16, args...);
    };
    template<typename... TArgs> static Mem dword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_32, args...);
    };
    template<typename... TArgs> static Mem fword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_48, args...);
    };
    template<typename... TArgs> static Mem qword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_64, args...);
    };
    template<typename... TArgs> static Mem tbyte_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_80, args...);
    };
    template<typename... TArgs> static Mem tword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_80, args...);
    };
    template<typename... TArgs> static Mem oword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_128, args...);
    };
    template<typename... TArgs> static Mem xmmword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_128, args...);
    };
    template<typename... TArgs> static Mem ymmword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_256, args...);
    };
    template<typename... TArgs> static Mem zmmword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_512, args...);
    };

} // namespace zasm::operands