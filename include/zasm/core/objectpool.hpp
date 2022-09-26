#pragma once

#include <array>
#include <cassert>
#include <cstddef>
#include <memory>
#include <vector>

namespace zasm
{
    namespace detail
    {
        constexpr std::size_t kDefaultBlockCount = 0xFFFF;
    }

    template<typename T, std::size_t TBlockCount = detail::kDefaultBlockCount> class ObjectPool
    {
#pragma pack(push, 1)
        union Entry
        {
            Entry* prev;

            alignas(alignof(T)) std::array<std::byte, sizeof(T)> object;

            T* data() noexcept
            {
                // NOLINTNEXTLINE
                return reinterpret_cast<T*>(object.data());
            }
        };
#pragma pack(pop)

        struct Block
        {
            std::array<Entry, TBlockCount> storage;
            std::size_t slot;
        };

        std::vector<std::unique_ptr<Block>> _blocks;
        Entry* _freeItem = nullptr;

    public:
        using other = ObjectPool<T>;

        using value_type = T;

        using pointer = value_type*;
        using const_pointer = const value_type*;
        using void_pointer = void*;
        using const_void_pointer = const void*;

        using reference = value_type&;
        using const_reference = const value_type&;

        using size_type = std::size_t;

        ObjectPool<T> select_on_container_copy_construction() const
        {
            return (*this);
        }

        template<class TOther> struct rebind
        {
            using other = ObjectPool<TOther>;
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

        template<class TOther> ObjectPool([[maybe_unused]] const ObjectPool<TOther>& other)
        {
        }

        template<class TOther> ObjectPool& operator=([[maybe_unused]] const ObjectPool<TOther>& other)
        {
            return (*this);
        }

        void deallocate(pointer ptr, [[maybe_unused]] size_type count)
        {
            // NOLINTNEXTLINE
            Entry* entry = reinterpret_cast<Entry*>(ptr);
            entry->prev = _freeItem;

            _freeItem = entry;
        }

        pointer allocate([[maybe_unused]] size_type count)
        {
            assert(count == 1);

            if (_freeItem != nullptr)
            {
                auto* entry = _freeItem;
                _freeItem = entry->prev;

                return entry->data();
            }

            auto* block = _blocks.back().get();
            if (block->slot >= TBlockCount)
            {
                block = _blocks.emplace_back(std::make_unique<Block>()).get();
            }

            auto& entry = block->storage[block->slot];
            block->slot++;

            return entry.data();
        }

        pointer allocate(size_type count, [[maybe_unused]] const void* hint)
        {
            return (allocate(count));
        }

        void construct(T* ptr)
        {
            ::new (static_cast<void*>(ptr)) T();
        }

        void construct(T* ptr, const T& val)
        {
            ::new (static_cast<void*>(ptr)) T(val);
        }

        template<class TObjty, class... TArgs> void construct(TObjty* ptr, TArgs&&... args)
        {
            ::new (static_cast<void*>(ptr)) TObjty(std::forward<TArgs>(args)...);
        }

        template<class TUty> void destroy(TUty* ptr) noexcept
        {
            ptr->~TUty();
        }

        std::size_t max_size() const noexcept
        {
            return (~static_cast<std::size_t>(0U) / sizeof(T));
        }
    };
} // namespace zasm
