#pragma once

#include <cstdint>

namespace zasm
{

    class Label
    {
    public:
        enum class Id : int32_t
        {
            Invalid = -1,
        };

    private:
        Id _id{ Id::Invalid };

    public:
        constexpr Label() noexcept = default;
        constexpr Label(const Id id) noexcept
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

    namespace operands
    {
        using Label = ::zasm::Label;
    }

} // namespace zasm