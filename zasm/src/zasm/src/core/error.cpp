#include <cassert>
#include <string>
#include <zasm/core/errors.hpp>

namespace zasm
{
    static constexpr std::uint64_t kErrorExtBit = 0x8000000000000000ULL;

    struct ErrorExt
    {
        ErrorCode code;
        std::string message;
    };
	static bool isExtError(std::uint64_t data) noexcept
    {
        return (data & kErrorExtBit) != 0;
    }

    // TODO: This is not fully portable so we should check for systems where
    // we have to use a different approach.
    static ErrorExt* toErrorExt(std::uint64_t data) noexcept
    {
        assert(isExtError(data));

        auto* ext = reinterpret_cast<ErrorExt*>(data & ~kErrorExtBit);
        return ext;
    }

    static std::uint64_t toInternalErrorData(const ErrorExt* ext) noexcept
    {
        return static_cast<std::uint64_t>(reinterpret_cast<std::uintptr_t>(ext)) | kErrorExtBit;
    }

    Error::Error(const Error& other)
    {
        if (isExtError(other._data))
        {
            const auto* ext = toErrorExt(other._data);

            auto* newExt = new ErrorExt(*ext);
            _data = toInternalErrorData(newExt);
        }
        else
        {
            _data = other._data;
        }
    }

    Error::Error(Error&& other) noexcept
    {
        _data = other._data;
        other._data = 0;
    }

    Error::Error(ErrorCode code) noexcept
    {
        std::uint64_t data = static_cast<std::uint64_t>(code);
        _data = data;
    }

    Error::Error(ErrorCode code, const char* message)
    {
        assert(message != nullptr);

        auto* ext = new ErrorExt();
        ext->code = code;
        ext->message = message;

        _data = toInternalErrorData(ext);
    }

    Error::~Error() noexcept
    {
        clear();
    }

    void Error::clear()
    {
        if (isExtError(_data))
        {
            const auto* ext = toErrorExt(_data);
            delete ext;
        }
        _data = 0;
    }

    bool Error::empty() const noexcept
    {
        return _data == 0;
    }

    bool Error::operator==(ErrorCode code) const noexcept
    {
        return getCode() == code;
    }

    bool Error::operator!=(ErrorCode code) const noexcept
    {
        return !(*this == code);
    }

    Error& Error::operator=(Error&& other) noexcept
    {
        clear();

        _data = other._data;
        other._data = 0;

        return *this;
    }

    Error& Error::operator=(const Error& other) noexcept
    {
        clear();

        if (isExtError(other._data))
        {
            const auto* ext = toErrorExt(other._data);

            auto* newExt = new ErrorExt(*ext);
            _data = toInternalErrorData(newExt);
        }
        else
        {
            _data = other._data;
        }

        return *this;
    }

    static ErrorCode getErrorCode(std::uint64_t data) noexcept
    {
        if (data == 0)
        {
            return ErrorCode::None;
        }

        if (isExtError(data))
        {
            const auto* ext = toErrorExt(data);
            return ext->code;
        }
        else
        {
            return static_cast<ErrorCode>(data);
        }
    }

    ErrorCode Error::getCode() const noexcept
    {
        return getErrorCode(_data);
    }

    static constexpr const char* getErrorCodeName(ErrorCode err) noexcept
    {
#define ERROR_STRING(e)                                                                                                        \
    case e:                                                                                                                    \
        return #e

        switch (err)
        {
            ERROR_STRING(ErrorCode::None);
            ERROR_STRING(ErrorCode::InvalidMode);
            ERROR_STRING(ErrorCode::NotInitialized);
            ERROR_STRING(ErrorCode::InvalidOperation);
            ERROR_STRING(ErrorCode::InvalidParameter);
            ERROR_STRING(ErrorCode::FileNotFound);
            ERROR_STRING(ErrorCode::AccessDenied);
            ERROR_STRING(ErrorCode::OutOfMemory);
            ERROR_STRING(ErrorCode::LabelNotFound);
            ERROR_STRING(ErrorCode::UnresolvedLabel);
            ERROR_STRING(ErrorCode::InvalidLabel);
            ERROR_STRING(ErrorCode::LabelAlreadyBound);
            ERROR_STRING(ErrorCode::SectionNotFound);
            ERROR_STRING(ErrorCode::SectionAlreadyBound);
            ERROR_STRING(ErrorCode::SignatureMismatch);
            ERROR_STRING(ErrorCode::InvalidInstruction);
            ERROR_STRING(ErrorCode::OutOfBounds);
            ERROR_STRING(ErrorCode::ImpossibleInstruction);
            ERROR_STRING(ErrorCode::EmptyState);
            ERROR_STRING(ErrorCode::ImpossibleRelocation);
            ERROR_STRING(ErrorCode::AddressOutOfRange);
            ERROR_STRING(ErrorCode::InstructionTooLong);
            ERROR_STRING(ErrorCode::ExternalLabelNotBindable);
            default:
                assert(false);
                break;
        }
#undef ERROR_STRING
        return nullptr;
    }

    const char* Error::getErrorName() const noexcept
    {
        return getErrorCodeName(getCode());
    }

    static const char* getErrorCodeMessage(ErrorCode err) noexcept
    {
        // Give a default message for known error codes.
        switch (err)
        {
            case ErrorCode::None:
                return "No error";
            case ErrorCode::InvalidMode:
                return "Invalid mode";
            case ErrorCode::NotInitialized:
                return "Not initialized";
            case ErrorCode::InvalidOperation:
                return "Invalid operation";
            case ErrorCode::InvalidParameter:
                return "Invalid parameter";
            case ErrorCode::FileNotFound:
                return "File not found";
            case ErrorCode::AccessDenied:
                return "Access denied";
            case ErrorCode::OutOfMemory:
                return "Out of memory";
            case ErrorCode::LabelNotFound:
                return "Label not found";
            case ErrorCode::UnresolvedLabel:
                return "Unresolved label";
            case ErrorCode::InvalidLabel:
                return "Invalid label";
            case ErrorCode::LabelAlreadyBound:
                return "Label already bound";
            case ErrorCode::SectionNotFound:
                return "Section not found";
            case ErrorCode::SectionAlreadyBound:
                return "Section already bound";
            case ErrorCode::SignatureMismatch:
                return "Signature mismatch";
            case ErrorCode::InvalidInstruction:
                return "Invalid instruction";
            case ErrorCode::OutOfBounds:
                return "Out of bounds";
            case ErrorCode::ImpossibleInstruction:
                return "Impossible instruction";
            case ErrorCode::EmptyState:
                return "Empty state";
            case ErrorCode::ImpossibleRelocation:
                return "Impossible relocation";
            case ErrorCode::ExternalLabelNotBindable:
                return "External label can not be bound";
            case ErrorCode::InstructionTooLong:
                return "Instruction too long";
            case ErrorCode::AddressOutOfRange:
                return "Address out of range";
            default:
                break;
        }
        return "<invalid error code>";
    }

    const char* Error::getErrorMessage() const noexcept
    {
        if (isExtError(_data))
        {
            const auto* ext = toErrorExt(_data);
            return ext->message.c_str();
        }
        else
        {
            return getErrorCodeMessage(getCode());
        }
    }

} // namespace zasm
