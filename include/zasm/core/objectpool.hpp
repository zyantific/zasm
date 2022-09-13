#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <memory>
#include <vector>
#include <cstddef>

namespace zasm
{
    namespace detail
    {
        constexpr size_t kDefaultBlockCount = 0xFFFF;
    }

    template<typename T, size_t TBlockCount = detail::kDefaultBlockCount> class ObjectPool
    {
        using BlockId = uint16_t;

#pragma pack(push, 1)
        struct Entry;

        struct EntryHead
        {
            BlockId blockId;
            Entry* prev;
        };

        struct Entry : EntryHead
        {
            std::array<std::byte, sizeof(T)> data;
        };
#pragma pack(pop)

        struct Block
        {
            Entry storage[TBlockCount];
            BlockId id;
            std::size_t slot;
            std::size_t used;
        };

        std::vector<std::unique_ptr<Block>> _blocks;
        Entry* _freeItem = nullptr;

    public:
        typedef ObjectPool<T> other;

        typedef T value_type;

        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef void* void_pointer;
        typedef const void* const_void_pointer;

        typedef value_type& reference;
        typedef const value_type& const_reference;

        typedef std::size_t size_type;

        ObjectPool<T> select_on_container_copy_construction() const
        {
            return (*this);
        }

        template<class _Other> struct rebind
        {
            typedef ObjectPool<_Other> other;
        };

        ObjectPool()
        {
            _blocks.push_back(std::make_unique<Block>());
        }

        pointer address(reference _Val) const noexcept
        {
            return std::addressof(_Val);
        }

        const_pointer address(const_reference _Val) const noexcept
        {
            return std::addressof(_Val);
        }

        template<class TOther> ObjectPool(const ObjectPool<TOther>&)
        {
        }

        template<class TOther> ObjectPool<T>& operator=(const ObjectPool<TOther>&)
        {
            return (*this);
        }

        void deallocate(pointer ptr, [[maybe_unused]] size_type count)
        {
            Entry* entry = reinterpret_cast<Entry*>(reinterpret_cast<std::byte*>(ptr) - sizeof(EntryHead));
            entry->prev = _freeItem;

            auto* block = _blocks[entry->blockId].get();
            block->used--;

            _freeItem = entry;
        }

        pointer allocate([[maybe_unused]] size_type count)
        {
            assert(count == 1);

            if (_freeItem != nullptr)
            {
                auto* entry = _freeItem;
                _freeItem = entry->prev;

                auto* block = _blocks[entry->blockId].get();
                block->used++;

                return reinterpret_cast<pointer>(entry->data.data());
            }

            auto* block = _blocks.back().get();
            if (block->slot >= TBlockCount)
            {
                const BlockId id = static_cast<BlockId>(_blocks.size());

                _blocks.push_back(std::make_unique<Block>());

                block = _blocks.back().get();
                block->id = id;
            }

            auto& entry = block->storage[block->slot];
            entry.blockId = block->id;

            block->slot++;
            block->used++;

            return reinterpret_cast<pointer>(entry.data.data());
        }

        pointer allocate(size_type count, [[maybe_unused]] const void* hint)
        {
            return (allocate(count));
        }

        void construct(T* ptr)
        {
            ::new ((void*)ptr) T();
        }

        void construct(T* ptr, const T& val)
        {
            ::new ((void*)ptr) T(val);
        }

        template<class TObjty, class... TArgs> void construct(TObjty* ptr, TArgs&&... args)
        {
            ::new ((void*)ptr) TObjty(std::forward<TArgs>(args)...);
        }

        template<class TUty> void destroy(TUty* ptr)
        {
            ptr->~TUty();
        }

        size_t max_size() const noexcept
        {
            return (~static_cast<size_t>(0U) / sizeof(T));
        }
    };
} // namespace zasm
