#pragma once

#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <limits>
#include <type_traits>

namespace zasm
{
    template<typename TUnderlying, typename TElement, std::size_t TElementBitSize> class Packed
    {
        static_assert(std::is_signed_v<TUnderlying> == false, "Underlying type must be unsigned");

        static constexpr std::size_t kElementMask = (TUnderlying{ 1u } << TElementBitSize) - TUnderlying{ 1u };
        static constexpr std::size_t kStorageBitSize = std::numeric_limits<TUnderlying>::digits;
        static constexpr std::size_t kCapacity = kStorageBitSize / TElementBitSize;

        TUnderlying _data{};

    public:
        constexpr Packed() noexcept = default;

        constexpr Packed(std::initializer_list<TElement>&& elements) noexcept
        {
            std::size_t idx = 0;
            for (auto&& elem : elements)
            {
                set(idx, elem);
                idx++;
            }
        }

        template<std::size_t TIndex> constexpr void set(const TElement& val) noexcept
        {
            constexpr auto bitIndex = (TIndex * TElementBitSize);
            static_assert(bitIndex + TElementBitSize < kStorageBitSize);

            const auto newVal = (static_cast<TUnderlying>(val) & kElementMask) << bitIndex;

            _data &= ~(kElementMask << bitIndex);
            _data |= newVal;
        }

        constexpr void set(std::size_t index, const TElement& val) noexcept
        {
            const auto bitIndex = (index * TElementBitSize);

            assert(bitIndex + TElementBitSize < kStorageBitSize);
            if (bitIndex + TElementBitSize > kStorageBitSize)
                return;

            const auto newVal = (static_cast<TUnderlying>(val) & kElementMask) << bitIndex;

            _data &= ~(kElementMask << bitIndex);
            _data |= newVal;
        }

        template<std::size_t TIndex> constexpr TElement get() const noexcept
        {
            constexpr auto bitIndex = (TIndex * TElementBitSize);
            static_assert(bitIndex + TElementBitSize < kStorageBitSize);

            const auto res = (_data >> bitIndex) & kElementMask;
            return static_cast<TElement>(res);
        }

        constexpr TElement get(std::size_t index) const noexcept
        {
            const auto bitIndex = (index * TElementBitSize);

            assert(bitIndex + TElementBitSize < kStorageBitSize);
            if (bitIndex + TElementBitSize > kStorageBitSize)
                return TElement{};

            const auto res = (_data >> bitIndex) & kElementMask;
            return static_cast<TElement>(res);
        }

        constexpr std::size_t capacity() const noexcept
        {
            return kCapacity;
        }

        constexpr std::size_t size() const noexcept
        {
            return capacity();
        }
    };
} // namespace zasm
