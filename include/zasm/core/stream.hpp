#pragma once

#include "enumflags.hpp"

#include <cstdint>
#include <cstdio>

namespace zasm
{
    enum class StreamMode : uint32_t
    {
        None = 0,
        Read = (1U << 0),
        Write = (1U << 1),
        ReadWrite = (Read | Write),
    };

    ZASM_ENABLE_ENUM_OPERATORS(StreamMode);

    enum class SeekType : uint32_t
    {
        Begin,
        Cur,
        End,
    };

    class IStream
    {
    public:
        virtual ~IStream() = default;

        virtual StreamMode mode() const = 0;

        virtual bool isEnd() const = 0;

        virtual std::size_t read(void* buf, size_t length) = 0;

        template<typename T> std::size_t read(T& value)
        {
            return read(&value, sizeof(T));
        }

        virtual std::size_t write(const void* buf, size_t length) = 0;

        template<typename T> std::size_t write(const T& value)
        {
            return write(&value, sizeof(T));
        }

        virtual std::size_t size() const = 0;

        virtual std::size_t offset() const = 0;

        virtual void reserve(std::size_t size) = 0;

        virtual std::size_t capacity() const = 0;

        virtual void seek(std::size_t offset, SeekType seek) = 0;

        virtual void clear() = 0;
    };

} // namespace zasm
