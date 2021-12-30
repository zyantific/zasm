#pragma once

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <string.h>
#include <string>
#include <vector>

namespace zasm
{

    class StringPool
    {
        struct Entry
        {
            size_t hash{};
            int32_t offset{};
            int32_t len{};
            int32_t capacity{};
            int32_t refCount{};
        };

        std::vector<Entry> _entries;
        std::vector<char> _data;

    public:
        enum class Id : int32_t
        {
            Invalid = -1,
        };

    public:
        template<size_t N> Id aquire(const char (&value)[N])
        {
            return aquire_(value, N);
        }

        Id aquire(const char* value)
        {
            return aquire_(value, strlen(value) + 1);
        }

        Id aquire(const std::string& val)
        {
            return aquire_(val.c_str(), val.size() + 1);
        }

        size_t release(Id id)
        {
            const auto idx = static_cast<size_t>(id);
            if (idx >= _entries.size())
                return 0;

            const auto oldRefCount = _entries[idx].refCount--;
            return oldRefCount - 1;
        }

        template<size_t N> Id find(const char (&value)[N]) const noexcept
        {
            const auto hash = getHash(value, N);
            return find(value, N, hash);
        }

        bool isValid(Id id) const noexcept
        {
            const auto idx = static_cast<size_t>(id);
            if (idx >= _entries.size())
            {
                return false;
            }
            return true;
        }

        const char* get(Id id) const noexcept
        {
            if (!isValid(id))
            {
                return nullptr;
            }
            const auto& entry = _entries[static_cast<size_t>(id)];
            if (entry.refCount == 0)
                return nullptr;
            return _data.data() + entry.offset;
        }

        int32_t getLength(Id id) const noexcept
        {
            if (!isValid(id))
            {
                return 0;
            }
            const auto& entry = _entries[static_cast<size_t>(id)];
            return entry.len;
        }

        int32_t getRefCount(Id id) const noexcept
        {
            if (!isValid(id))
            {
                return 0;
            }
            const auto& entry = _entries[static_cast<size_t>(id)];
            return entry.refCount;
        }

        void clear() noexcept
        {
            _entries.clear();
            _data.clear();
        }

    private:
        Id find_(const char* buf, size_t len, size_t hash) const noexcept
        {
            auto it = std::find_if(std::begin(_entries), std::end(_entries), [&](const auto& entry) {
                if (entry.refCount == 0)
                    return false;
                if (entry.hash != hash)
                    return false;
                if (entry.len != len)
                    return false;
                const char* str = _data.data() + entry.offset;
                return memcmp(buf, str, len) == 0;
            });
            if (it != std::end(_entries))
            {
                auto index = std::distance(_entries.begin(), it);
                return static_cast<Id>(index);
            }
            return Id::Invalid;
        }

        Id aquire_(const char* buf, size_t len)
        {
            const auto hash = getHash(buf, len);

            auto id = find_(buf, len, hash);
            if (id != Id::Invalid)
            {
                auto& entry = _entries[static_cast<size_t>(id)];
                entry.refCount++;
                return id;
            }

            const auto len2 = static_cast<int32_t>(len);

            // Use empty entry if any exist.
            auto it = std::find_if(
                _entries.begin(), _entries.end(), [&](auto&& entry) { return entry.refCount == 0 && entry.capacity >= len2; });

            if (it != _entries.end())
            {
                // Found empty space.
                auto& entry = *it;

                id = static_cast<Id>(std::distance(_entries.begin(), it));
                std::memcpy(_data.data() + entry.offset, buf, len2);

                entry.hash = hash;
                entry.len = len2;
                entry.refCount = 1;
            }
            else
            {
                // New entry.
                const int32_t offset = static_cast<int32_t>(_data.size());
                _data.insert(_data.end(), buf, buf + len);

                id = static_cast<Id>(_entries.size());

                _entries.push_back({ hash, offset, len2, len2, 1 });
            }

            return id;
        }

    private:
        constexpr size_t getHash(const char* buf, size_t len) const noexcept
        {
#ifdef _M_AMD64
            constexpr size_t offset = 0xcbf29ce484222325ULL;
            constexpr size_t prime = 0x00000100000001B3ULL;
#else
            constexpr size_t offset = 0x811c9dc5U;
            constexpr size_t prime = 0x01000193U;
#endif
            size_t result = offset;
            for (size_t i = 0; i < len; ++i)
            {
                result ^= static_cast<unsigned char>(buf[i]);
                result *= prime;
            }
            return result;
        }
    };

} // namespace zasm