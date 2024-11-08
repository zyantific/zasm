#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstring>
#include <memory>
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
    public:
        enum class Id : std::int32_t
        {
            Invalid = -1,
        };

        static constexpr std::size_t kMaxStringSize = 0xFFFF;
        static constexpr std::size_t kAverageStringSize = 24;
        static constexpr std::size_t kStringsPerBlock = 4096;
        static constexpr std::size_t kBlockSize = kAverageStringSize * kStringsPerBlock;
        static constexpr std::size_t kMinStringCapacity = 16;
        static constexpr std::size_t kUnspecifiedSize = ~std::size_t{ 0 };

        static_assert(kBlockSize >= kMaxStringSize, "Block size must be bigger than max string size.");

        // 16 bit prime number.
        static constexpr std::size_t kMaxHashBuckets = 39119;

    private:
        using StringSize = std::conditional_t<
            kMaxStringSize <= std::numeric_limits<std::uint16_t>::max(), std::uint16_t, std::uint32_t>;

        using BlockOffset = std::conditional_t<
            kBlockSize <= std::numeric_limits<std::uint32_t>::max(), std::uint32_t, std::uint64_t>;

        using BlockIndex = std::uint32_t;

        struct Entry
        {
            std::uint64_t hash{};
            BlockIndex blockIndex{};
            BlockOffset offsetInBlock{};
            StringSize len{};
            StringSize capacity{};
            std::int32_t refCount{};
            Id nextFreeId{ Id::Invalid };
        };

        std::vector<Entry> _entries;
        std::vector<std::vector<Id>> _hashBuckets;
        Id _nextFreeId{ Id::Invalid };
        std::size_t _numFree{};

        struct Block
        {
            BlockIndex index{};
            std::uint32_t used{};
            std::array<char, kBlockSize> data{};
        };

        std::vector<std::unique_ptr<Block>> _blocks;

    public:
        StringPool()
        {
            _hashBuckets.resize(kMaxHashBuckets);
        }

        Id acquire(const char* value, std::size_t size = kUnspecifiedSize)
        {
            if (size == kUnspecifiedSize)
            {
                size = std::strlen(value);
            }
            return aquire_(value, size);
        }

        Id acquire(std::string_view str)
        {
            return aquire_(str.data(), str.size());
        }

        Id acquire(const std::string& val)
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
            assert(newRefCount >= 0);

            if (newRefCount == 0)
            {
                entry->nextFreeId = _nextFreeId;
                _nextFreeId = stringId;
                _numFree++;

                const auto bucketIndex = entry->hash % kMaxHashBuckets;
                auto& bucket = _hashBuckets[bucketIndex];

                bucket.erase(std::remove(bucket.begin(), bucket.end(), stringId), bucket.end());
            }

            return newRefCount;
        }

        Id find(const char* str) const noexcept
        {
            const auto len = std::strlen(str);
            const auto hash = getHash(str, len);
            return find_(str, len, hash);
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

            return _blocks[entry->blockIndex]->data.data() + entry->offsetInBlock;
        }

        std::size_t getLength(Id stringId) const noexcept
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
            if (_entries.empty())
            {
                // Because clearing the buckets is expensive do nothing if already empty.
                return;
            }
            _entries.clear();
            if (_blocks.size() > 1)
            {
                _blocks.resize(1);
                _blocks[0]->used = 0;
            }
            _nextFreeId = Id::Invalid;
            _numFree = 0;
            for (auto& bucket : _hashBuckets)
            {
                bucket.clear();
            }
        }

        std::size_t size() const noexcept
        {
            return _entries.size() - _numFree;
        }

        Error save(IStream& stream) const
        {
            // Serialize entries.
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
                if (auto len = stream.write(entry.blockIndex); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.write(entry.offsetInBlock); len == 0)
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
                if (auto len = stream.write(entry.nextFreeId); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
            }

            // Serialize free entries.
            if (auto len = stream.write(&_nextFreeId, sizeof(_nextFreeId)); len == 0)
            {
                return ErrorCode::InvalidParameter;
            }

            // Serialize hash buckets.
            for (const auto& bucket : _hashBuckets)
            {
                const auto bucketSize = static_cast<std::uint32_t>(bucket.size());
                if (auto len = stream.write(&bucketSize, sizeof(bucketSize)); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }

                for (const auto& id : bucket)
                {
                    if (auto len = stream.write(id); len == 0)
                    {
                        return ErrorCode::InvalidParameter;
                    }
                }
            }

            // Serialize blocks.
            const auto blockCount = static_cast<std::uint32_t>(_blocks.size());
            if (auto len = stream.write(&blockCount, sizeof(blockCount)); len == 0)
            {
                return ErrorCode::InvalidParameter;
            }

            for (const auto& block : _blocks)
            {
                if (auto len = stream.write(block->index); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.write(block->used); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.write(block->data.data(), block->used); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
            }

            return ErrorCode::None;
        }

        Error load(IStream& stream)
        {
            // Deserialize entries.
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
                if (auto len = stream.read(entry.blockIndex); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.read(entry.offsetInBlock); len == 0)
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
                if (auto len = stream.read(entry.nextFreeId); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
            }

            // Deserialize free entries.
            Id nextFreeEntry{ Id::Invalid };
            if (auto len = stream.read(&nextFreeEntry, sizeof(nextFreeEntry)); len == 0)
            {
                return ErrorCode::InvalidParameter;
            }

            // Deserialize hash buckets.
            auto hashBuckets = std::vector<std::vector<Id>>();
            hashBuckets.resize(kMaxHashBuckets);
            for (auto& bucket : hashBuckets)
            {
                std::uint32_t bucketSize{};
                if (auto len = stream.read(&bucketSize, sizeof(bucketSize)); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }

                bucket.resize(bucketSize);
                for (auto& id : bucket)
                {
                    if (auto len = stream.read(id); len == 0)
                    {
                        return ErrorCode::InvalidParameter;
                    }
                }
            }

            // Deserialize blocks.
            std::uint32_t blockCount{};
            if (auto len = stream.read(&blockCount, sizeof(blockCount)); len == 0)
            {
                return ErrorCode::InvalidParameter;
            }

            auto blocks = std::vector<std::unique_ptr<Block>>();
            blocks.resize(blockCount);
            for (auto& block : blocks)
            {
                block = std::make_unique<Block>();

                if (auto len = stream.read(block->index); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.read(block->used); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
                if (auto len = stream.read(block->data.data(), block->used); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
            }

            // Swap state.
            _entries = std::move(loadedEntries);
            _hashBuckets = std::move(hashBuckets);
            _blocks = std::move(blocks);
            _nextFreeId = nextFreeEntry;

            // Compute free count.
            _numFree = 0;
            for (auto freeId = _nextFreeId; freeId != Id::Invalid;
                 freeId = _entries[static_cast<std::size_t>(freeId)].nextFreeId)
            {
                _numFree++;
            }

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

            const auto refCount = self._entries[idx].refCount;
#ifndef IN_TESTS
            assert(refCount > 0);
#endif

            if (refCount <= 0)
            {
                return nullptr;
            }

            return &self._entries[idx];
        }

        Id find_(const char* buf, std::size_t len, std::uint64_t hash) const noexcept
        {
            const auto bucketIndex = hash % kMaxHashBuckets;
            const auto& bucket = _hashBuckets[bucketIndex];

            // Find the lowest hash.
            auto itLowest = std::lower_bound(bucket.begin(), bucket.end(), Id::Invalid, [&](Id id, Id) {
                return _entries[static_cast<std::size_t>(id)].hash < hash;
            });

            // Iterate all matching hashes and compare the string.
            for (auto it = itLowest; it != bucket.end(); ++it)
            {
                const auto id = *it;
                const auto& entry = _entries[static_cast<std::size_t>(id)];
                if (entry.hash != hash)
                {
                    break;
                }

                if (entry.len != len)
                {
                    continue;
                }

                const auto* str = _blocks[entry.blockIndex]->data.data() + entry.offsetInBlock;
                if (std::memcmp(str, buf, len) == 0)
                {
                    return id;
                }
            }

            return Id::Invalid;
        }

        Block& getBlock(std::size_t len)
        {
            // If there are no blocks create a new one.
            if (_blocks.empty())
            {
                _blocks.emplace_back(std::make_unique<Block>());
                return *_blocks.back();
            }

            // See if the last block has enough space.
            auto& lastBlock = *_blocks.back();
            if (lastBlock.used + len < kBlockSize)
            {
                return lastBlock;
            }

            // Create a new block.
            auto newBlock = std::make_unique<Block>();
            newBlock->index = static_cast<BlockIndex>(_blocks.size());
            _blocks.emplace_back(std::move(newBlock));

            return *_blocks.back();
        }

        Id getFreeEntry(std::size_t requiredLength)
        {
            if (_nextFreeId == Id::Invalid)
            {
                return Id::Invalid;
            }

            auto nextFreeId = _nextFreeId;
            auto parentId = Id::Invalid;

            while (nextFreeId != Id::Invalid)
            {
                const auto& entry = _entries[static_cast<std::size_t>(nextFreeId)];
                if (entry.capacity >= requiredLength)
                {
                    if (parentId != Id::Invalid)
                    {
                        // Update the next free id of the parent.
                        auto& parentEntry = _entries[static_cast<std::size_t>(parentId)];
                        parentEntry.nextFreeId = entry.nextFreeId;
                    }
                    else
                    {
                        // Update the head of the free list.
                        _nextFreeId = entry.nextFreeId;
                    }
                    _numFree--;
                    return nextFreeId;
                }
                parentId = nextFreeId;
                nextFreeId = entry.nextFreeId;
            }

            return Id::Invalid;
        }

        Id aquire_(const char* inputStr, std::size_t len)
        {
            const auto hash = getHash(inputStr, len);
            return aquire_(inputStr, len, hash);
        }

        Id aquire_(const char* inputStr, std::size_t len, std::uint64_t hash)
        {
            // Strings can not be larger than kMaxStringSize.
            if (len >= kMaxStringSize)
            {
                assert(len < kMaxStringSize);
                return Id::Invalid;
            }

            // Find existing string and increase ref count.
            auto stringId = find_(inputStr, len, hash);
            if (stringId != Id::Invalid)
            {
                auto& entry = _entries[static_cast<std::size_t>(stringId)];
                entry.refCount++;
                return stringId;
            }

            const auto actualLength = static_cast<std::int32_t>(len);
            const auto requiredLength = static_cast<std::int32_t>(len) + 1;

            const auto insertToHashBucket = [&](Entry& entry, Id id) {
                const auto bucketIndex = entry.hash % kMaxHashBuckets;
                auto& bucket = _hashBuckets[bucketIndex];

                auto sortedIt = std::lower_bound(bucket.begin(), bucket.end(), id, [&](Id id, Id id2) {
                    return _entries[static_cast<std::size_t>(id)].hash < _entries[static_cast<std::size_t>(id2)].hash;
                });

                bucket.insert(sortedIt, id);
            };

            const auto writeStringToBlock = [&](std::size_t blockOffset, Block& block) {
                std::memcpy(block.data.data() + blockOffset, inputStr, actualLength);
                // Ensure null termination.
                block.data[blockOffset + actualLength] = '\0';
            };

            // Use empty entry if any exist.
            stringId = getFreeEntry(requiredLength);
            if (stringId != Id::Invalid)
            {
                // Found empty space.
                auto& entry = _entries[static_cast<std::size_t>(stringId)];
                assert(entry.refCount == 0);

                auto& block = _blocks[entry.blockIndex];
                writeStringToBlock(entry.offsetInBlock, *block);

                entry.hash = hash;
                entry.len = actualLength;
                entry.refCount = 1;
                entry.nextFreeId = Id::Invalid;

                insertToHashBucket(entry, stringId);

                return stringId;
            }

            // New entry.

            // We align the capacity to 8 bytes.
            const auto capacity = std::max<std::int32_t>(kMinStringCapacity, (requiredLength + 7) & ~7);

            auto& block = getBlock(capacity);
            const auto offset = static_cast<std::int32_t>(block.used);

            writeStringToBlock(offset, block);
            block.used += capacity;

            stringId = static_cast<Id>(_entries.size());

            auto& entry = _entries.emplace_back();
            entry.hash = hash;
            entry.blockIndex = block.index;
            entry.offsetInBlock = offset;
            entry.len = actualLength;
            entry.capacity = capacity;
            entry.refCount = 1;

            insertToHashBucket(entry, stringId);

            return stringId;
        }

        static constexpr std::uint64_t getHash(const char* buf, size_t len) noexcept
        {
            assert(buf != nullptr);
            assert(len > 0);

            if (buf == nullptr || len == 0)
            {
                return 0;
            }

            constexpr std::uint64_t offset = 0xcbf29ce484222325ULL;
            constexpr std::uint64_t prime = 0x00000100000001B3ULL;

            std::uint64_t result = offset;
            for (std::size_t i = 0; i < len; ++i)
            {
                result ^= static_cast<unsigned char>(buf[i]);
                result *= prime;
            }

            return result;
        }
    };

} // namespace zasm
