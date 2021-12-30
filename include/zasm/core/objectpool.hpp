#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <memory>
#include <vector>

namespace zasm
{
    template<typename _Ty, size_t _TBlockSize = 0xFFFF> class ObjectPool
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
            std::byte data[sizeof(_Ty)];
        };
#pragma pack(pop)

        struct Block
        {
            Entry storage[_TBlockSize];
            BlockId id;
            size_t slot;
            size_t used;
        };

        std::vector<std::unique_ptr<Block>> _blocks;
        Entry* _freeItem = nullptr;

    public:
        typedef ObjectPool<_Ty> other;

        typedef _Ty value_type;

        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef void* void_pointer;
        typedef const void* const_void_pointer;

        typedef value_type& reference;
        typedef const value_type& const_reference;

        typedef size_t size_type;

        ObjectPool<_Ty> select_on_container_copy_construction() const
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

        template<class _Other> ObjectPool(const ObjectPool<_Other>&)
        {
        }

        template<class _Other> ObjectPool<_Ty>& operator=(const ObjectPool<_Other>&)
        {
            return (*this);
        }

        void deallocate(pointer _Ptr, size_type)
        {
            Entry* entry = reinterpret_cast<Entry*>(reinterpret_cast<std::byte*>(_Ptr) - sizeof(EntryHead));
            entry->prev = _freeItem;

            auto* block = _blocks[entry->blockId].get();
            block->used--;

            _freeItem = entry;
        }

        pointer allocate(size_type _Count)
        {
            assert(_Count == 1);

            if (_freeItem != nullptr)
            {
                auto* entry = _freeItem;
                _freeItem = entry->prev;

                auto* block = _blocks[entry->blockId].get();
                block->used++;

                return reinterpret_cast<pointer>(entry->data);
            }

            auto* block = _blocks.back().get();
            if (block->slot >= _TBlockSize)
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

            return reinterpret_cast<pointer>(entry.data);
        }

        pointer allocate(size_type _Count, const void*)
        {
            return (allocate(_Count));
        }

        void construct(_Ty* _Ptr)
        {
            ::new ((void*)_Ptr) _Ty();
        }

        void construct(_Ty* _Ptr, const _Ty& _Val)
        {
            ::new ((void*)_Ptr) _Ty(_Val);
        }

        template<class _Objty, class... _Types> void construct(_Objty* _Ptr, _Types&&... _Args)
        {
            ::new ((void*)_Ptr) _Objty(std::forward<_Types>(_Args)...);
        }

        template<class _Uty> void destroy(_Uty* _Ptr)
        {
            _Ptr->~_Uty();
        }

        size_t max_size() const noexcept
        {
            return ((size_t)(-1) / sizeof(_Ty));
        }
    };
} // namespace zasm
