#pragma once

#include <Zydis/Zydis.h>
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
        constexpr Label() = default;
        constexpr Label(const Id id)
            : _id{ id }
        {
        }

        constexpr Id getId() const
        {
            return _id;
        }
    };

    namespace operands
    {
        using Label = ::zasm::Label;
    }

} // namespace zasm::operands