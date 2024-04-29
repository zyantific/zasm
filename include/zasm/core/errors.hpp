#pragma once

#include <cassert>
#include <cstdint>

namespace zasm
{
    namespace detail
    {
        struct ErrorData;
    }

    enum class ErrorCode : std::uint32_t
    {
        None = 0,
        // Generic.
        InvalidMode,
        NotInitialized,
        InvalidOperation,
        InvalidParameter,
        FileNotFound,
        AccessDenied,
        OutOfMemory,
        // Program
        LabelNotFound,
        UnresolvedLabel,
        InvalidLabel,
        LabelAlreadyBound,
        ExternalLabelNotBindable,
        SectionNotFound,
        SectionAlreadyBound,
        SignatureMismatch,
        // Decoder.
        InvalidInstruction,
        OutOfBounds,
        // Encoder.
        ImpossibleInstruction,
        // Serialization.
        EmptyState,
        ImpossibleRelocation,
    };

    class Error
    {
        std::uint64_t _data{};

    public:
        constexpr Error() noexcept = default;

        Error(ErrorCode code) noexcept;
        ~Error() noexcept;

        bool operator==(ErrorCode code) const noexcept;
        bool operator!=(ErrorCode code) const noexcept;

        ErrorCode getCode() const noexcept;

        const char* getErrorName() const noexcept;

        const char* getErrorMessage() const noexcept;
    };

} // namespace zasm
