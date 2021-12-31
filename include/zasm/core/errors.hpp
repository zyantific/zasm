#pragma once

#include <cassert>
#include <ostream>

namespace zasm
{
    enum class Error
    {
        None = 0,
        // Generic.
        InvalidMode,
        NotInitialized,
        InvalidOperation,
        InvalidParameter,
        // Program
        LabelNotFound,
        UnresolvedLabel,
        InvalidLabel,
        LabelAlreadyBound,
        SectionNotFound,
        SectionAlreadyBound,
        // Decoder.
        InvalidInstruction,
        OutOfBounds,
        // Encoder.
        ImpossibleInstruction,
    };

    inline constexpr const char* getErrorName(Error err) noexcept
    {
#define ERROR_STRING(e)                                                                                                        \
    case e:                                                                                                                    \
        return #e

        switch (err)
        {
            ERROR_STRING(Error::None);
            ERROR_STRING(Error::InvalidMode);
            ERROR_STRING(Error::NotInitialized);
            ERROR_STRING(Error::InvalidOperation);
            ERROR_STRING(Error::InvalidParameter);
            ERROR_STRING(Error::LabelNotFound);
            ERROR_STRING(Error::UnresolvedLabel);
            ERROR_STRING(Error::InvalidLabel);
            ERROR_STRING(Error::LabelAlreadyBound);
            ERROR_STRING(Error::SectionNotFound);
            ERROR_STRING(Error::SectionAlreadyBound);
            ERROR_STRING(Error::InvalidInstruction);
            ERROR_STRING(Error::OutOfBounds);
            ERROR_STRING(Error::ImpossibleInstruction);
            default:
                assert(false);
                break;
        }
#undef ERROR_STRING
        return nullptr;
    }

    // gtest support.
    inline std::ostream& operator<<(std::ostream& os, const Error& err)
    {
        return os << zasm::getErrorName(err);
    }

} // namespace zasm

