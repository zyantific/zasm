#pragma once

#include <vector>
#include <string.h>
#include <string>

namespace zasm
{

    class StringPool
    {
        struct Entry
        {
            size_t hash;
            size_t offset;
            size_t len;
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

        template<size_t N> Id find(const char (&value)[N]) const
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
            return _data.data() + entry.offset;
        }

        void clear() noexcept
        {
            _entries.clear();
            _data.clear();
        }

    private:
        Id find_(const char* buf, size_t len, size_t hash) const
        {
            auto it = std::find_if(std::begin(_entries), std::end(_entries), [&](const auto& entry) {
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
                return id;
            }

            const size_t offset = _data.size();
            _data.insert(_data.end(), buf, buf + len);

            id = static_cast<Id>(_entries.size());
            _entries.push_back({ hash, offset, len });

            return id;
        }

    private:
        constexpr size_t getHash(const char* buf, size_t len) const
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