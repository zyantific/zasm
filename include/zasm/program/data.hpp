#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <limits>

namespace zasm
{
    // TODO: Store the current data type and try to eliminate the C union.
    class Data final
    {
        static constexpr std::size_t kInlineStorageSize = 32;
        static constexpr std::size_t kInlineDataFlag = std::size_t{ 1U } << (std::numeric_limits<std::size_t>::digits - 1);

    private:
        // NOTE: The highest bit is used to determine if we have inline data or
        // use the heap, getSize() will mask this out.
        std::size_t _size{};
        std::size_t _repeatCount{ 1 };

#pragma pack(push, 1)
        union
        {
            void* ptr;
            std::uint8_t u8;
            std::uint16_t u16;
            std::uint32_t u32;
            std::uint64_t u64;
            std::array<std::uint8_t, kInlineStorageSize> bytes;
        } _storage{};
#pragma pack(pop)

        constexpr bool isDataInline() const noexcept
        {
            return (_size & kInlineDataFlag) != 0;
        }

    public:
        constexpr Data() noexcept = default;

        constexpr Data(std::uint8_t val, std::size_t repeatCount = 1) noexcept
            : _size{ kInlineDataFlag | sizeof(val) }
            , _repeatCount{ repeatCount == 0 ? 1 : repeatCount }
        {
            _storage.u8 = val;
        }

        constexpr Data(std::uint16_t val, std::size_t repeatCount = 1) noexcept
            : _size{ kInlineDataFlag | sizeof(val) }
            , _repeatCount{ repeatCount == 0 ? 1 : repeatCount }
        {
            _storage.u16 = val;
        }

        constexpr Data(std::uint32_t val, std::size_t repeatCount = 1) noexcept
            : _size{ kInlineDataFlag | sizeof(val) }
            , _repeatCount{ repeatCount == 0 ? 1 : repeatCount }
        {
            _storage.u32 = val;
        }

        constexpr Data(std::uint64_t val, std::size_t repeatCount = 1) noexcept
            : _size{ kInlineDataFlag | sizeof(val) }
            , _repeatCount{ repeatCount == 0 ? 1 : repeatCount }
        {
            _storage.u64 = val;
        }

        Data(const void* ptr, std::size_t len) noexcept;
        Data(const Data& other) noexcept;
        Data(Data&& other) noexcept;
        ~Data();

        /// <summary>
        /// Returns a pointer to the current data held.
        /// </summary>
        /// <returns>Pointer to the raw data</returns>
        const void* getData() const noexcept;

        /// <summary>
        /// Returns the current data size not including the repeat count.
        /// </summary>
        /// <returns>Size of data</returns>
        std::size_t getSize() const noexcept;

        /// <summary>
        /// For single value data this is sizeof(value) * repeat
        /// </summary>
        std::size_t getTotalSize() const noexcept;

        /// <summary>
        /// Returns the amount of times the data should be repeated.
        /// </summary>
        /// <returns></returns>
        constexpr std::size_t getRepeatCount() const noexcept
        {
            return _repeatCount;
        }

        void setRepeatCount(std::size_t repeats)
        {
            _repeatCount = repeats;
        }

        Data& operator=(const Data& other) noexcept;
        Data& operator=(Data&& other) noexcept;

        constexpr bool operator==(const Data& other) const noexcept
        {
            if (_size != other._size)
            {
                return false;
            }

            if (getRepeatCount() != other.getRepeatCount())
            {
                return false;
            }

            return std::memcmp(getData(), other.getData(), getSize()) == 0;
        }

        constexpr bool operator!=(const Data& other) const noexcept
        {
            return !(*this == other);
        }

        constexpr bool isU8() const noexcept
        {
            if (!isDataInline())
            {
                return false;
            }

            return getSize() == sizeof(std::uint8_t);
        }

        constexpr std::uint8_t valueAsU8() const noexcept
        {
            return _storage.u8;
        }

        constexpr bool isU16() const noexcept
        {
            if (!isDataInline())
            {
                return false;
            }

            return getSize() == sizeof(std::uint16_t);
        }

        constexpr std::uint16_t valueAsU16() const noexcept
        {
            return _storage.u16;
        }

        constexpr bool isU32() const noexcept
        {
            if (!isDataInline())
            {
                return false;
            }

            return getSize() == sizeof(std::uint32_t);
        }

        constexpr std::uint32_t valueAsU32() const noexcept
        {
            return _storage.u32;
        }

        constexpr bool isU64() const noexcept
        {
            if (!isDataInline())
            {
                return false;
            }

            return getSize() == sizeof(std::uint64_t);
        }

        constexpr std::uint64_t valueAsU64() const noexcept
        {
            return _storage.u64;
        }
    };

} // namespace zasm
