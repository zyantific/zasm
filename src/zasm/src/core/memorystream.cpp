#include "zasm/core/memorystream.hpp"

#include "zasm/core/math.hpp"

#include <algorithm>
#include <cstdlib>
#include <cstring>

namespace zasm
{
    namespace detail
    {
        struct MemoryStreamState
        {
            std::byte* data{};
            std::size_t size{};
            std::size_t offset{};
            std::size_t capacity{};
        };

    } // namespace detail

    MemoryStream::MemoryStream()
    {
        _state = new detail::MemoryStreamState();
    }

    MemoryStream::MemoryStream(MemoryStream&& other) noexcept
    {
        _state = other._state;
        other._state = new detail::MemoryStreamState();
    }

    MemoryStream::~MemoryStream()
    {
        if (_state->data)
        {
            free(_state->data);
            _state->data = nullptr;
        }
        delete _state;
    }

    StreamMode MemoryStream::mode() const
    {
        return StreamMode::ReadWrite;
    }

    bool MemoryStream::isEnd() const
    {
        return _state->offset == _state->size;
    }

    std::size_t MemoryStream::read(void* buf, size_t length)
    {
        const auto maxReadLength = std::min(length, _state->size - _state->offset);
        if (maxReadLength > 0)
        {
            std::memcpy(buf, _state->data + _state->offset, maxReadLength);
            _state->offset += maxReadLength;
        }
        return maxReadLength;
    }

    std::size_t MemoryStream::write(const void* buf, size_t length)
    {
        const auto spaceLeft = _state->capacity - _state->offset;
        if (length > spaceLeft)
        {
            constexpr float growthFactor = 2.0f;

            const std::size_t currentCapacity = _state->capacity;
            const std::size_t newCapacity = _state->capacity + length;
            const std::size_t newCapacityWithGrowth = static_cast<std::size_t>(currentCapacity * growthFactor);
            const std::size_t finalCapacity = math::alignTo<std::size_t>(std::max(newCapacity, newCapacityWithGrowth), 0x1000U);

            auto* newData = static_cast<std::byte*>(realloc(_state->data, finalCapacity));
            if (newData == nullptr)
            {
                return 0;
            }
            _state->data = newData;
            _state->capacity = finalCapacity;
        }

        std::memcpy(_state->data + _state->offset, buf, length);

        const auto spaceAvailable = _state->size - _state->offset;
        if (length > spaceAvailable)
        {
            _state->size += length - spaceAvailable;
        }

        _state->offset += length;

        return length;
    }

    std::size_t MemoryStream::size() const
    {
        return _state->size;
    }

    std::size_t MemoryStream::offset() const
    {
        return _state->offset;
    }

    void MemoryStream::reserve(std::size_t newCapacity)
    {
        const auto finalCapacity = std::max(newCapacity, _state->capacity);
        auto* newData = static_cast<std::byte*>(realloc(_state->data, finalCapacity));
        if (newData == nullptr)
        {
            return;
        }
        _state->data = newData;
        _state->capacity = finalCapacity;
    }

    std::size_t MemoryStream::capacity() const
    {
        return _state->capacity;
    }

    void MemoryStream::seek(std::size_t offset, SeekType seek)
    {
        if (seek == SeekType::Begin)
        {
            _state->offset = std::min(offset, _state->size);
        }
        else if (seek == SeekType::Cur)
        {
            _state->offset = std::min(_state->offset + offset, _state->size);
        }
        else if (seek == SeekType::End)
        {
            _state->offset = _state->size - std::min(offset, _state->size);
        }
    }

    void MemoryStream::clear()
    {
        _state->size = 0;
        _state->offset = 0;
    }

    std::byte* MemoryStream::data()
    {
        return _state->data;
    }

    const std::byte* MemoryStream::data() const
    {
        return _state->data;
    }

} // namespace zasm
