#pragma once

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iterator>
#include <string.h>
#include <string>
#include <string_view>
#include <vector>
#include <zasm/core/errors.hpp>
#include <zasm/core/stream.hpp>

namespace zasm
{

    class StringPool
    {
        struct Entry
        {
            std::size_t hash{};
            std::int32_t offset{};
            std::int32_t len{};
            std::int32_t capacity{};
            std::int32_t refCount{};
        };

        std::vector<Entry> _entries;
        std::vector<char> _data;

    public:
        enum class Id : std::int32_t
        {
            Invalid = -1,
        };

    public:
        // NOLINTNEXTLINE
        template<size_t N> Id aquire(const char (&value)[N])
        {
            return aquire_(value, N);
        }

        Id aquire(const char* value)
        {
            return aquire_(value, strlen(value));
        }

        Id aquire(const std::string& val)
        {
            return aquire_(val.c_str(), val.size());
        }

        int32_t release(Id stringId) noexcept
        {
            Entry* entry = getEntry(*this, stringId);
            if (entry == nullptr)
            {
                return 0;
            }

            const auto newRefCount = --entry->refCount;
            return newRefCount;
        }

        // NOLINTNEXTLINE
        template<std::size_t N> Id find(const char (&value)[N]) const noexcept
        {
            const auto hash = getHash(value, N);
            return find(value, N, hash);
        }

        bool isValid(Id stringId) const noexcept
        {
            const auto* entry = getEntry(*this, stringId);
            return entry != nullptr;
        }

        const char* get(Id stringId) const noexcept
        {
            const auto* entry = getEntry(*this, stringId);
            if (entry == nullptr)
            {
                return nullptr;
            }

            return _data.data() + entry->offset;
        }

        int32_t getLength(Id stringId) const noexcept
        {
            const auto* entry = getEntry(*this, stringId);
            if (entry == nullptr)
            {
                return 0;
            }
            return entry->len;
        }

        int32_t getRefCount(Id stringId) const noexcept
        {
            const auto* entry = getEntry(*this, stringId);
            if (entry == nullptr)
            {
                return 0;
            }

            return entry->refCount;
        }

        void clear() noexcept
        {
            _entries.clear();
            _data.clear();
        }

        const char* data() const noexcept
        {
            return _data.data();
        }

        std::size_t size() const noexcept
        {
            return _entries.size();
        }

        Error save(IStream& stream) const
        {
            const auto entryCount = static_cast<std::uint32_t>(_entries.size());
            if (auto len = stream.write(&entryCount, sizeof(entryCount)); len == 0)
            {
                return ErrorCode::InvalidParameter;
            }

            for (const auto& entry : _entries)
            {
                if (auto len = stream.write(entry.hash); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.write(entry.offset); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.write(entry.len); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.write(entry.capacity); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.write(entry.refCount); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
            }

            const auto dataSize = static_cast<std::uint32_t>(_data.size());
            if (auto len = stream.write(dataSize); len == 0)
            {
                return ErrorCode::InvalidParameter;
            }

            if (dataSize > 0)
            {
                if (auto len = stream.write(_data.data(), dataSize); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
            }

            return ErrorCode::None;
        }

        Error load(IStream& stream)
        {
            clear();

            std::uint32_t entryCount{};
            if (auto len = stream.read(&entryCount, sizeof(entryCount)); len == 0)
            {
                return ErrorCode::InvalidParameter;
            }

            std::vector<Entry> loadedEntries;
            loadedEntries.resize(entryCount);
            for (auto& entry : loadedEntries)
            {
                if (auto len = stream.read(entry.hash); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.read(entry.offset); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.read(entry.len); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.read(entry.capacity); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.read(entry.refCount); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
            }

            std::uint32_t dataSize{};
            if (auto len = stream.read(&dataSize, sizeof(dataSize)); len == 0)
            {
                return ErrorCode::InvalidParameter;
            }

            std::vector<char> loadedData;
            if (dataSize > 0)
            {
                loadedData.resize(dataSize);
                if (auto len = stream.read(loadedData.data(), dataSize); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
            }

            _entries = std::move(loadedEntries);
            _data = std::move(loadedData);

            return ErrorCode::None;
        }

    private:
        template<typename TSelf>
        static auto getEntry(TSelf&& self, Id stringId) noexcept
            -> std::conditional_t<std::is_const_v<std::remove_reference_t<TSelf>>, const Entry*, Entry*>
        {
            const auto idx = static_cast<std::size_t>(stringId);
            if (idx >= self._entries.size())
            {
                return nullptr;
            }
            if (self._entries[idx].refCount <= 0)
            {
                return nullptr;
            }

            return &self._entries[idx];
        }

        Id find_(const char* buf, std::size_t len, std::size_t hash) const noexcept
        {
            auto it = std::find_if(std::begin(_entries), std::end(_entries), [&](const auto& entry) noexcept {
                if (entry.refCount == 0 || entry.hash != hash || entry.len != len)
                {
                    return false;
                }
                const char* str = _data.data() + entry.offset;
                return memcmp(buf, str, len) == 0;
            });
            if (it != std::end(_entries))
            {
                const auto index = std::distance(_entries.begin(), it);
                return static_cast<Id>(index);
            }
            return Id::Invalid;
        }

        Id aquire_(const char* buf, std::size_t len)
        {
            constexpr std::int32_t kTerminatorLength = 1;

            const auto hash = getHash(buf, len);

            auto stringId = find_(buf, len, hash);
            if (stringId != Id::Invalid)
            {
                auto& entry = _entries[static_cast<std::size_t>(stringId)];
                entry.refCount++;
                return stringId;
            }

            const auto len2 = static_cast<std::int32_t>(len);

            // Use empty entry if any exist.
            auto itEntry = std::find_if(_entries.begin(), _entries.end(), [&](auto&& entry) {
                return entry.refCount <= 0 && entry.capacity >= len2 + kTerminatorLength;
            });

            if (itEntry != _entries.end())
            {
                // Found empty space.
                auto& entry = *itEntry;

                stringId = static_cast<Id>(std::distance(_entries.begin(), itEntry));
                std::memcpy(_data.data() + entry.offset, buf, len2);

                // Ensure null termination.
                const auto termOffset = static_cast<std::size_t>(entry.offset) + len2;
                _data[termOffset] = '\0';

                entry.hash = hash;
                entry.len = len2;
                entry.refCount = 1;

                return stringId;
            }

            // New entry.
            const auto offset = static_cast<std::int32_t>(_data.size());
            std::copy_n(buf, len, std::back_insert_iterator(_data));

            // Ensure null termination.
            _data.push_back('\0');

            stringId = static_cast<Id>(_entries.size());

            _entries.push_back({ hash, offset, len2, len2 + kTerminatorLength, 1 });

            return stringId;
        }

        static constexpr std::size_t getHash(const char* buf, size_t len) noexcept
        {
            if (buf == nullptr)
            {
                return 0;
            }
#ifdef _M_AMD64
            constexpr std::size_t offset = 0xcbf29ce484222325ULL;
            constexpr std::size_t prime = 0x00000100000001B3ULL;
#else
            constexpr std::size_t offset = 0x811c9dc5U;
            constexpr std::size_t prime = 0x01000193U;
#endif
            std::size_t result = offset;
            for (std::size_t i = 0; i < len; ++i)
            {
                result ^= static_cast<unsigned char>(buf[i]);
                result *= prime;
            }
            return result;
        }
    };

} // namespace zasm
