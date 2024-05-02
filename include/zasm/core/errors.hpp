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
        InstructionTooLong,
        // Encoder.
        ImpossibleInstruction,
        AddressOutOfRange,
        // Serialization.
        EmptyState,
        ImpossibleRelocation,
    };

    /// <summary>
    /// The Error class represents an error code and can have additionally a message attached.
    /// If the object is constructed with an error message additional memory will be allocated.
    /// If the object is constructed only with an error code there will be no extra allocation.
    /// </summary>
    class Error
    {
        std::uintptr_t _data{};

    public:
        constexpr Error() noexcept = default;

        Error(const Error& other);

        Error(Error&& other) noexcept;

        /// <summary>
        /// Construct an Error object with the given error code.
        /// </summary>
        /// <param name="code">Error Code</param>
        Error(ErrorCode code) noexcept;

        /// <summary>
        /// Construct an Error object with the given error code and an additional message.
        /// The message will be copied so it is safe to pass a temporary string.
        /// </summary>
        /// <param name="code">Error Code</param>
        /// <param name="message">Additional information</param>
        Error(ErrorCode code, const char* message);

        ~Error() noexcept;

        bool operator==(ErrorCode code) const noexcept;
        bool operator!=(ErrorCode code) const noexcept;
        Error& operator=(Error&& other) noexcept;

        ErrorCode getCode() const noexcept;

        const char* getErrorName() const noexcept;

        const char* getErrorMessage() const noexcept;
    };

} // namespace zasm
