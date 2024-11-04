#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstring>
#include <iterator>
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
        static constexpr std::size_t kUnspecifiedSize = ~std::size_t{ 0 };

        // 16 bit prime number.
        static constexpr std::size_t kMaxHashBuckets = 39119;

    private:
        struct Entry
        {
            std::size_t hash{};
            std::size_t blockIndex{};
            std::size_t sortedIndex{};
            std::int32_t offsetInBlock{};
            std::int32_t len{};
            std::int32_t capacity{};
            std::int32_t refCount{};
        };

        std::vector<Entry> _entries;
        std::vector<Id> _freeEntries;
        std::vector<std::vector<Id>> _hashBuckets;

        struct Block
        {
            std::size_t index{};
            std::size_t used{};
            std::array<char, kBlockSize> data{};
        };

        std::vector<std::unique_ptr<Block>> _blocks;

    public:
        StringPool()
        {
            _hashBuckets.resize(kMaxHashBuckets);
        }

        Id aquire(const char* value, std::size_t size = kUnspecifiedSize)
        {
            if (size == kUnspecifiedSize)
            {
                size = std::strlen(value);
            }
            return aquire_(value, size);
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
            assert(newRefCount >= 0);

            if (newRefCount == 0)
            {
                _freeEntries.push_back(stringId);

                const auto bucketIndex = entry->hash % kMaxHashBuckets;
                auto& bucket = _hashBuckets[bucketIndex];

                bucket.erase(bucket.begin() + entry->sortedIndex);
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
            _blocks.clear();
        }

        std::size_t size() const noexcept
        {
            return _entries.size();
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
                if (auto len = stream.write(entry.sortedIndex); len == 0)
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
            }

            // Serialize free entries.
            const auto freeEntryCount = static_cast<std::uint32_t>(_freeEntries.size());
            if (auto len = stream.write(&freeEntryCount, sizeof(freeEntryCount)); len == 0)
            {
                return ErrorCode::InvalidParameter;
            }

            for (const auto& freeEntry : _freeEntries)
            {
                if (auto len = stream.write(freeEntry); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
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
                if (auto len = stream.read(entry.sortedIndex); len == 0)
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
            }

            // Deserialize free entries.
            std::uint32_t freeEntryCount{};
            if (auto len = stream.read(&freeEntryCount, sizeof(freeEntryCount)); len == 0)
            {
                return ErrorCode::InvalidParameter;
            }

            auto freeEntries = std::vector<Id>();
            freeEntries.resize(freeEntryCount);
            for (auto& freeEntry : freeEntries)
            {
                if (auto len = stream.read(freeEntry); len == 0)
                {
                    return ErrorCode::InvalidParameter;
                }
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
            _freeEntries = std::move(freeEntries);
            _hashBuckets = std::move(hashBuckets);
            _blocks = std::move(blocks);

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

        Id find_(const char* buf, std::size_t len, std::size_t hash) const noexcept
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
            newBlock->index = _blocks.size();
            _blocks.emplace_back(std::move(newBlock));

            return *_blocks.back();
        }

        Id aquire_(const char* inputStr, std::size_t len)
        {
            const auto hash = getHash(inputStr, len);
            return aquire_(inputStr, len, hash);
        }

        Id aquire_(const char* inputStr, std::size_t len, std::size_t hash)
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

            const auto len2 = static_cast<std::int32_t>(len);
            constexpr std::int32_t kTerminatorLength = 1;

            // Use empty entry if any exist.
            // TODO: Optimize this, we should prioritize finding entries at the end of the list.
            //       This would mean shrinking the vector has less to copy.
            auto itEntry = std::find_if(_freeEntries.begin(), _freeEntries.end(), [&](Id id) {
                auto& entry = _entries[static_cast<std::size_t>(id)];
                return entry.refCount <= 0 && entry.capacity >= len2 + kTerminatorLength;
            });

            const auto insertToHashBucket = [&](Entry& entry, Id id) {
                const auto bucketIndex = entry.hash % kMaxHashBuckets;
                auto& bucket = _hashBuckets[bucketIndex];

                auto sortedIt = std::lower_bound(bucket.begin(), bucket.end(), id, [&](Id id, Id id2) {
                    return _entries[static_cast<std::size_t>(id)].hash < _entries[static_cast<std::size_t>(id2)].hash;
                });

                const auto sortedIndex = static_cast<std::size_t>(std::distance(bucket.begin(), sortedIt));
                bucket.insert(sortedIt, id);

                return sortedIndex;
            };

            const auto writeStringToBlock = [&](std::size_t blockOffset, Block& block) {
                std::memcpy(block.data.data() + blockOffset, inputStr, len2);
                // Ensure null termination.
                block.data[blockOffset + len2] = '\0';
            };

            if (itEntry != _freeEntries.end())
            {
                // Found empty space.
                stringId = *itEntry;
                auto& entry = _entries[static_cast<std::size_t>(stringId)];

                auto& block = _blocks[entry.blockIndex];
                writeStringToBlock(entry.offsetInBlock, *block);

                entry.hash = hash;
                entry.len = len2;
                entry.refCount = 1;
                entry.sortedIndex = insertToHashBucket(entry, stringId);

                _freeEntries.erase(itEntry);

                return stringId;
            }

            // New entry.
            auto& block = getBlock(len2 + kTerminatorLength);
            const auto offset = static_cast<std::int32_t>(block.used);

            writeStringToBlock(offset, block);
            block.used += len2 + kTerminatorLength;

            stringId = static_cast<Id>(_entries.size());

            auto& entry = _entries.emplace_back();
            entry.hash = hash;
            entry.blockIndex = block.index;
            entry.offsetInBlock = offset;
            entry.len = len2;
            entry.capacity = len2 + kTerminatorLength;
            entry.refCount = 1;
            entry.sortedIndex = insertToHashBucket(entry, stringId);

            return stringId;
        }

        static constexpr std::size_t getHash(const char* buf, size_t len) noexcept
        {
            assert(buf != nullptr);
            assert(len > 0);

            if (buf == nullptr || len == 0)
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
