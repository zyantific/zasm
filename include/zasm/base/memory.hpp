#pragma once

#include <cstdint>
#include <limits>
#include <zasm/base/label.hpp>
#include <zasm/base/mode.hpp>
#include <zasm/base/register.hpp>
#include <zasm/core/bitsize.hpp>
#include <zasm/core/packed.hpp>

namespace zasm
{
    class Mem final
    {
        using RegisterPack = Packed<std::uint32_t, Reg::Id, 10>;

        BitSize _bitSize{};
        RegisterPack _segBaseIndex{};
        std::uint8_t _scale{};
        std::int64_t _disp{};
        Label::Id _label{ Label::Id::Invalid };

    public:
        constexpr explicit Mem(
            BitSize bitSize, const Reg& seg, const Reg& base, const Reg& index, std::int32_t scale, std::int64_t disp) noexcept
            : _bitSize{ bitSize }
            , _segBaseIndex{ seg.getId(), base.getId(), index.getId() }
            , _scale{ static_cast<std::uint8_t>(scale) }
            , _disp{ disp }
        {
        }

        constexpr explicit Mem(
            BitSize bitSize, const Reg& seg, const Label& label, const Reg& base, const Reg& index, std::int32_t scale,
            std::int64_t disp) noexcept
            : _bitSize{ bitSize }
            , _segBaseIndex{ seg.getId(), base.getId(), index.getId() }
            , _scale{ static_cast<std::uint8_t>(scale) }
            , _disp{ disp }
            , _label{ label.getId() }
        {
        }

        constexpr bool operator==(const Mem& other) const noexcept
        {
            return _bitSize == other._bitSize && _segBaseIndex == other._segBaseIndex && _scale == other._scale
                && _disp == other._disp && _label == other._label;
        }

        constexpr bool operator!=(const Mem& other) const noexcept
        {
            return !(*this == other);
        }

        constexpr Reg getSegment() const noexcept
        {
            return Reg{ _segBaseIndex.get<0>() };
        }

        Mem& setSegment(const Reg& reg) noexcept
        {
            _segBaseIndex.set<0>(reg.getId());
            return *this;
        }

        constexpr Reg getBase() const noexcept
        {
            return Reg{ _segBaseIndex.get<1>() };
        }

        Mem& setBase(const Reg& reg) noexcept
        {
            _segBaseIndex.set<1>(reg.getId());
            return *this;
        }

        constexpr Reg getIndex() const noexcept
        {
            return Reg{ _segBaseIndex.get<2>() };
        }

        Mem& setIndex(const Reg& reg) noexcept
        {
            _segBaseIndex.set<2>(reg.getId());
            return *this;
        }

        constexpr uint8_t getScale() const noexcept
        {
            return _scale;
        }

        Mem& setScale(std::uint8_t scale) noexcept
        {
            _scale = scale;
            return *this;
        }

        constexpr std::int64_t getDisplacement() const noexcept
        {
            return _disp;
        }

        Mem& setDisplacement(std::int64_t disp) noexcept
        {
            _disp = disp;
            return *this;
        }

        constexpr BitSize getBitSize() const noexcept
        {
            return _bitSize;
        }

        Mem& setBitSize(BitSize bitSize) noexcept
        {
            _bitSize = bitSize;
            return *this;
        }

        BitSize getBitSize([[maybe_unused]] MachineMode mode) const noexcept
        {
            return getBitSize();
        }

        int32_t getByteSize() const noexcept
        {
            return ::zasm::getBitSize(_bitSize) / std::numeric_limits<uint8_t>::digits;
        }

        constexpr Label getLabel() const noexcept
        {
            return Label{ _label };
        }

        Mem& setLabel(const Label& label) noexcept
        {
            _label = label.getId();
            return *this;
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

} // namespace zasm
