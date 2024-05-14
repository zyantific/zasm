#include "zasm/core/filestream.hpp"

#include <cstdio>
#include <vector>

#ifndef _WIN32
// TODO: Define this only for 64 bit architectures.
#    define _FILE_OFFSET_BITS 64
#    include <stdio.h>
#endif

namespace zasm
{
    namespace detail
    {
        struct FileStreamState
        {
            StreamMode mode{};
            std::FILE* file{};
            std::size_t length{};
        };

        static void seekImpl(FILE* fp, std::size_t pos, int whence)
        {
#ifdef _WIN32
            _fseeki64(fp, pos, whence);
#else
            fseeko(fp, pos, whence);
#endif
        }

        static std::size_t tellImpl(FILE* fp)
        {
#ifdef _WIN32
            return _ftelli64(fp);
#else
            const auto res = ftello(fp);
            if (res == -1)
                return 0;
            return static_cast<std::size_t>(res);
#endif
        }

    } // namespace detail

    FileStream::FileStream()
    {
        _state = nullptr;
    }

    FileStream::FileStream(FileStream&& other) noexcept
    {
        _state = other._state;
        other._state = nullptr;
    }

    FileStream::FileStream(const std::filesystem::path& path, StreamMode mode)
    {
        open(path, mode);
    }

    FileStream::~FileStream()
    {
        close();
    }

    StreamMode FileStream::mode() const
    {
        if (_state == nullptr)
        {
            return StreamMode::None;
        }
        return _state->mode;
    }

    bool FileStream::isEnd() const
    {
        if (_state == nullptr)
        {
            return true;
        }
        return feof(_state->file) != 0;
    }

    Error FileStream::open(const std::filesystem::path& path, StreamMode mode)
    {
        close();

        FILE* fp = nullptr;
#ifdef _WIN32
        _wfopen_s(&fp, path.wstring().c_str(), mode == StreamMode::Read ? L"rb" : mode == StreamMode::Write ? L"wb" : L"r+b");
#else
        fp = fopen(path.string().c_str(), mode == StreamMode::Read ? "rb" : mode == StreamMode::Write ? "wb" : "r+b");
#endif
        if (fp == nullptr)
        {
            return ErrorCode::AccessDenied;
        }

        // Adjust the buffer size
        setvbuf(fp, nullptr, _IOFBF, 1'048'576U);

        _state = new detail::FileStreamState();
        _state->file = fp;

        seek(0, SeekType::End);
        _state->length = offset();
        seek(0, SeekType::Begin);

        _state->mode = mode;
        return ErrorCode::None;
    }

    bool FileStream::isOpen() const
    {
        return _state != nullptr && _state->file != nullptr;
    }

    void FileStream::close()
    {
        if (_state == nullptr)
            return;

        if (_state->file != nullptr)
        {
            fclose(_state->file);
        }

        delete _state;
        _state = nullptr;
    }

    std::size_t FileStream::read(void* buf, size_t length)
    {
        if (!isOpen())
        {
            return 0;
        }

#ifdef _MSC_VER
        return _fread_nolock(buf, 1, length, _state->file);
#else
        return fread(buf, 1, length, _state->file);
#endif
    }

    std::size_t FileStream::write(const void* buf, size_t length)
    {
        if (!isOpen())
        {
            return 0;
        }

#ifdef _MSC_VER
        return _fwrite_nolock(buf, 1, length, _state->file);
#else
        return fwrite(buf, 1, length, _state->file);
#endif
    }

    std::size_t FileStream::size() const
    {
        if (!isOpen())
        {
            return 0;
        }

        return _state->length;
    }

    std::size_t FileStream::offset() const
    {
        if (!isOpen())
        {
            return 0;
        }
        return detail::tellImpl(_state->file);
    }

    void FileStream::reserve([[maybe_unused]] std::size_t newCapacity)
    {
        // Stub.
    }

    std::size_t FileStream::capacity() const
    {
        if (!isOpen())
        {
            return 0;
        }
        return _state->length;
    }

    void FileStream::seek(std::size_t offset, SeekType seek)
    {
        if (!isOpen())
        {
            return;
        }
        if (seek == SeekType::Begin)
        {
            detail::seekImpl(_state->file, offset, SEEK_SET);
        }
        else if (seek == SeekType::Cur)
        {
            detail::seekImpl(_state->file, offset, SEEK_CUR);
        }
        else if (seek == SeekType::End)
        {
            detail::seekImpl(_state->file, offset, SEEK_END);
        }
    }

    void FileStream::clear()
    {
        // Stub
    }

} // namespace zasm
