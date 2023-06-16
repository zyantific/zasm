#pragma once

#include <filesystem>
#include <zasm/core/errors.hpp>
#include <zasm/core/stream.hpp>

namespace zasm
{
    namespace detail
    {
        struct FileStreamState;
    }

    class FileStream final : public IStream
    {
        detail::FileStreamState* _state{};

    public:
        FileStream();
        FileStream(const std::filesystem::path& path, StreamMode mode);
        ~FileStream();
        FileStream(const FileStream& other) = delete;
        FileStream(FileStream&& other) noexcept;

        StreamMode mode() const override;

        bool isEnd() const override;

        Error open(const std::filesystem::path& path, StreamMode mode);

        bool isOpen() const;

        void close();

        std::size_t read(void* buf, size_t length) override;

        std::size_t write(const void* buf, size_t length) override;

        std::size_t size() const override;

        std::size_t offset() const override;

        void reserve(std::size_t size) override;

        std::size_t capacity() const override;

        void seek(std::size_t offset, SeekType seek) override;

        void clear() override;
    };

} // namespace zasm
