#include "zasm/program/data.hpp"

#include <cstring>
#include <limits>

namespace zasm
{
    Data::Data(const void* ptr, size_t len)
    {
        if (len < kInlineStorageSize)
        {
            std::memcpy(_storage.bytes, ptr, len);
            _size = kInlineDataFlag | len;
        }
        else
        {
            void* data = malloc(len);
            std::memcpy(data, ptr, len);

            _storage.ptr = data;
            _size = len;
        }
    }

    Data::~Data()
    {
        if (_size & kInlineDataFlag)
            return;

        free(const_cast<void*>(_storage.ptr));
        _storage.ptr = nullptr;
    }

    const void* Data::getData() const
    {
        if (_size & kInlineDataFlag)
            return _storage.bytes;

        return _storage.ptr;
    }

    size_t Data::getSize() const
    {
        return (_size & ~kInlineDataFlag);
    }

} // namespace zasm