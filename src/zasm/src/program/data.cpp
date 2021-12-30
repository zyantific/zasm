#include "zasm/program/data.hpp"

#include <cstdlib>
#include <cstring>
#include <limits>
#include <utility>

namespace zasm
{
    Data::Data(const void* ptr, size_t len)
    {
        if (len <= kInlineStorageSize)
        {
            std::memcpy(_storage.bytes, ptr, len);
            _size = kInlineDataFlag | len;
        }
        else
        {
            void* data = std::malloc(len);
            if (data != nullptr)
            {
                std::memcpy(data, ptr, len);
                _storage.ptr = data;
                _size = len;
            }
            else
            {
                // TODO: Handle out of memory.
                _size = 0;
            }
        }
    }

    Data::Data(Data&& other) noexcept
    {
        *this = std::move(other);
    }

    Data::Data(const Data& other)
    {
        *this = other;
    }

    Data::~Data()
    {
        if (_size == 0)
            return;

        if (_size & kInlineDataFlag)
            return;

        std::free(const_cast<void*>(_storage.ptr));
        _storage.ptr = nullptr;
    }

    const void* Data::getData() const noexcept
    {
        if (_size == 0)
            return nullptr;

        if (_size & kInlineDataFlag)
            return _storage.bytes;

        return _storage.ptr;
    }

    size_t Data::getSize() const noexcept
    {
        return (_size & ~kInlineDataFlag);
    }

    // When kInlineDataFlag is set this function is used to copy the data.
    // Copying the entire buffer is done on purpose since the size is known the compiler
    // can generate specific code instead of calling the external memcpy function.
    template<size_t N> static void copyInlineData(uint8_t (&buf)[N], const uint8_t (&src)[N])
    {
        std::memcpy(buf, src, N);
    }

    Data& Data::operator=(const Data& other)
    {
        _size = other._size;
        if (_size & kInlineDataFlag)
        {
            copyInlineData(_storage.bytes, other._storage.bytes);
        }
        else
        {
            void* data = malloc(other.getSize());
            if (data != nullptr)
            {
                std::memcpy(data, other.getData(), other.getSize());
                _storage.ptr = data;
            }
            else
            {
                // TODO: Handle out of memory.
                _size = 0;
            }
        }
        return *this;
    }

    Data& Data::operator=(Data&& other) noexcept
    {
        _size = other._size;
        if (_size & kInlineDataFlag)
        {
            copyInlineData(_storage.bytes, other._storage.bytes);
        }
        else
        {
            _storage.ptr = other._storage.ptr;
        }

        other._size = 0;
        other._storage.ptr = nullptr;

        return *this;
    }

} // namespace zasm