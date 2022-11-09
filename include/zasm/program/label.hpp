#pragma once

#include <cstdint>
#include <zasm/base/mode.hpp>
#include <zasm/core/bitsize.hpp>

namespace zasm
{

    class Label final
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
        constexpr explicit Label(const Id id) noexcept
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

        static BitSize getBitSize() noexcept
        {
            return BitSize::_0;
        }

        BitSize getBitSize(MachineMode /*unused*/) const noexcept
        {
            return getBitSize();
        }
    };

} // namespace zasm
