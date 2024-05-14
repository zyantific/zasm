#include "zasm/program/data.hpp"

#include <cstdlib>
#include <cstring>
#include <limits>
#include <utility>

namespace zasm
{
    Data::Data(const void* ptr, std::size_t len) noexcept
    {
        if (len <= kInlineStorageSize)
        {
            std::memcpy(_storage.bytes.data(), ptr, len);
            _size = kInlineDataFlag | len;
        }
        else
        {
            // NOLINTNEXTLINE
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
                _storage.ptr = nullptr;
                _size = 0;
            }
        }
        _repeatCount = 1;
    }

    Data::Data(Data&& other) noexcept
    {
        *this = std::move(other);
    }

    Data::Data(const Data& other) noexcept
    {
        *this = other;
    }

    Data::~Data()
    {
        if (_size == 0 || isDataInline())
        {
            return;
        }

        // NOLINTNEXTLINE
        std::free(const_cast<void*>(_storage.ptr));

        _storage.ptr = nullptr;
    }

    const void* Data::getData() const noexcept
    {
        if (_size == 0)
        {
            return nullptr;
        }

        if (isDataInline())
        {
            return _storage.bytes.data();
        }

        return _storage.ptr;
    }

    std::size_t Data::getSize() const noexcept
    {
        return (_size & ~kInlineDataFlag);
    }

    std::size_t Data::getTotalSize() const noexcept
    {
        return getSize() * _repeatCount;
    }

    Data& Data::operator=(const Data& other) noexcept
    {
        _size = other._size;
        _repeatCount = other._repeatCount;
        if (isDataInline())
        {
            _storage.bytes = other._storage.bytes;
        }
        else
        {
            // NOLINTNEXTLINE
            void* data = malloc(other.getSize());
            if (data != nullptr)
            {
                std::memcpy(data, other.getData(), other.getSize());
                _storage.ptr = data;
            }
            else
            {
                // TODO: Handle out of memory.
                _storage.ptr = nullptr;
                _size = 0;
            }
        }
        return *this;
    }

    Data& Data::operator=(Data&& other) noexcept
    {
        _size = other._size;
        _repeatCount = other._repeatCount;
        if (isDataInline())
        {
            _storage.bytes = other._storage.bytes;
        }
        else
        {
            _storage.ptr = other._storage.ptr;
        }

        other._size = 0;
        other._repeatCount = 1;
        other._storage.ptr = nullptr;

        return *this;
    }

} // namespace zasm
