#pragma once

namespace zasm
{
    template<typename T>
    class StrongType
    {
        T _value{};

    public:
        constexpr StrongType() = default;
        constexpr StrongType(T value)
            : _value{ value }
        {
        }

        constexpr operator T() const
        {
            return _value;
        }
    };
}
