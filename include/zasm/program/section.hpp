#pragma once

#include <cstdint>
#include <string_view>
#include <zasm/core/enumflags.hpp>

namespace zasm
{

    namespace detail
    {
        enum class SectionAttribs : uint32_t
        {
            None = 0,
            Read = (1u << 0),
            Write = (1u << 1),
            Exec = (1u << 2),

            // Pre-defined typical attributes for a section.
            // .text
            Code = Read | Exec,
            // .data (Read and write access)
            Data = Read | Write,
            // .rdata
            RData = Read,
        };
        ZASM_ENABLE_ENUM_OPERATORS(SectionAttribs);
    } // namespace detail

    class Section
    {
    public:
        enum class Id : int32_t
        {
            Invalid = -1,
        };

        using Attribs = detail::SectionAttribs;

    private:
        Id _id{ Id::Invalid };

    public:
        constexpr Section() noexcept = default;
        constexpr Section(const Id id) noexcept
            : _id{ id }
        {
        }

        constexpr Id getId() const noexcept
        {
            return _id;
        }

        constexpr bool isValid() const noexcept
        {
            return _id != Id::Invalid;
        }
    };

    struct SectionInfo
    {
        size_t index{};
        const char* name{};
        Section::Attribs attribs{};
        int64_t va{};
        const uint8_t* buffer{};
        size_t physicalSize{};
        size_t virtualSize{};
    };

} // namespace zasm