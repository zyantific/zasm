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
        InvalidOperation,
        // Program
        LabelNotFound,
        UnresolvedLabel,
        InvalidLabel,
        // Decoder.
        InvalidInstruction,
        OutOfBounds,
        // Encoder.
        ImpossibleInstruction,
    };

    inline constexpr const char* getErrorName(Error err)
    {
#define ERROR_STRING(e)                                                                                                        \
    case e:                                                                                                                    \
        return #e

        switch (err)
        {
            ERROR_STRING(Error::None);
            ERROR_STRING(Error::InvalidMode);
            ERROR_STRING(Error::InvalidOperation);
            ERROR_STRING(Error::LabelNotFound);
            ERROR_STRING(Error::UnresolvedLabel);
            ERROR_STRING(Error::InvalidLabel);
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

} // namespace zasm

inline std::ostream& operator<<(std::ostream& os, const zasm::Error err)
{
    return os << zasm::getErrorName(err);
}