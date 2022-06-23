#pragma once

#include "immediate.hpp"
#include "label.hpp"
#include "register.hpp"
#include "zasm/core/bitsize.hpp"

namespace zasm
{
#pragma pack(push, 1)
    class Mem
    {
        BitSize _bitSize{};
        Reg::Id _seg{};
        Reg::Id _base{};
        Reg::Id _index{};
        uint8_t _scale{};
        int64_t _disp{};
        Label::Id _label{ Label::Id::Invalid };

    public:
        constexpr explicit Mem(
            BitSize bitSize, const Reg& seg, const Reg& base, const Reg& index, int32_t scale, int64_t disp) noexcept
            : _bitSize{ bitSize }
            , _seg{ static_cast<Reg::Id>(seg.getId()) }
            , _base{ static_cast<Reg::Id>(base.getId()) }
            , _index{ static_cast<Reg::Id>(index.getId()) }
            , _scale{ static_cast<uint8_t>(scale) }
            , _disp{ disp }
            , _label{ Label::Id::Invalid }
        {
        }

        constexpr explicit Mem(
            BitSize bitSize, const Reg& seg, const Label& label, const Reg& base, const Reg& index, int32_t scale,
            int64_t disp) noexcept
            : _bitSize{ bitSize }
            , _seg{ static_cast<Reg::Id>(seg.getId()) }
            , _base{ static_cast<Reg::Id>(base.getId()) }
            , _index{ static_cast<Reg::Id>(index.getId()) }
            , _scale{ static_cast<uint8_t>(scale) }
            , _disp{ disp }
            , _label{ label.getId() }
        {
        }

        constexpr Reg getSegment() const noexcept
        {
            return Reg{ _seg };
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
            if (_index == Reg::Id::None)
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
    static constexpr auto size = sizeof(Mem);

#pragma pack(pop)

} // namespace zasm