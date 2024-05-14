#pragma once

#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <limits>
#include <type_traits>

namespace zasm
{
    /// <summary>
    /// Container to tightly pack multiple elements with a given bit size to store
    /// in the provided underlying type.
    /// Example: Specifying the underlying type as uint32_t and element bit size of 10 allows you to store 3 elements.
    /// </summary>
    /// <typeparam name="TUnderlying">The underlying storage type</typeparam>
    /// <typeparam name="TElement">Value type of each element packed</typeparam>
    /// <typeparam name="TElementBitSize">The amount of bits to store TElement in TUnderlying</typeparam>
    template<typename TUnderlying, typename TElement, std::size_t TElementBitSize> class Packed
    {
        static_assert(!std::is_signed_v<TUnderlying>, "Underlying type must be unsigned");

        static constexpr std::size_t kElementMask = (TUnderlying{ 1U } << TElementBitSize) - TUnderlying{ 1U };
        static constexpr std::size_t kStorageBitSize = std::numeric_limits<TUnderlying>::digits;
        static constexpr std::size_t kCapacity = kStorageBitSize / TElementBitSize;

        static_assert(kCapacity * TElementBitSize <= kStorageBitSize, "Storage type is too small to store all elements");

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

        constexpr bool operator==(const Packed& other) const noexcept
        {
            return _data == other._data;
        }

        constexpr bool operator!=(const Packed& other) const noexcept
        {
            return _data == other._data;
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
            {
                return;
            }

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
            {
                return TElement{};
            }

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
