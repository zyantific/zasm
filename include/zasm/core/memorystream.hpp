#pragma once

#include <cstddef>
#include <zasm/core/stream.hpp>

namespace zasm
{
    namespace detail
    {
        struct MemoryStreamState;
    }

    class MemoryStream final : public IStream
    {
        detail::MemoryStreamState* _state{};

    public:
        MemoryStream();
        ~MemoryStream();
        MemoryStream(const MemoryStream& other) = delete;
        MemoryStream(MemoryStream&& other) noexcept;

        StreamMode mode() const override;

        bool isEnd() const override;

        std::size_t read(void* buf, size_t length) override;

        std::size_t write(const void* buf, size_t length) override;

        std::size_t size() const override;

        std::size_t offset() const override;

        void reserve(std::size_t size) override;

        std::size_t capacity() const override;

        void seek(std::size_t offset, SeekType seek) override;

        void clear() override;

        std::byte* data();

        const std::byte* data() const;
    };

} // namespace zasm
