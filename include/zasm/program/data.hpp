#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>

namespace zasm
{
    class Data
    {
        static constexpr auto kInlineStorageSize = 32;
        static constexpr size_t kInlineDataFlag = size_t(1) << (std::numeric_limits<size_t>::digits - 1);

    private:
        union
        {
            void* ptr;
            uint8_t u8;
            uint16_t u16;
            uint32_t u32;
            uint64_t u64;
            uint8_t bytes[kInlineStorageSize];

        } _storage{};

        // NOTE: The highest bit is used to determine if we have inline data or
        // use the heap, getSize() will mask this out.
        size_t _size{};

    public:
        constexpr Data() noexcept = default;

        constexpr Data(uint8_t val) noexcept
        {
            _storage.u8 = val;
            _size = kInlineDataFlag | sizeof(val);
        }

        constexpr Data(uint16_t val) noexcept
        {
            _storage.u16 = val;
            _size = kInlineDataFlag | sizeof(val);
        }

        constexpr Data(uint32_t val) noexcept
        {
            _storage.u32 = val;
            _size = kInlineDataFlag | sizeof(val);
        }

        constexpr Data(uint64_t val) noexcept
        {
            _storage.u64 = val;
            _size = kInlineDataFlag | sizeof(val);
        }

        Data(const void* ptr, size_t len);
        Data(const Data& other);
        Data(Data&& other) noexcept;
        ~Data();

        const void* getData() const noexcept;
        size_t getSize() const noexcept;

        Data& operator=(const Data& other);
        Data& operator=(Data&& other) noexcept;
    };

} // namespace zasm