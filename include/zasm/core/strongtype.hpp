#pragma once

namespace zasm
{
    template<typename T> class StrongType
    {
        T _value{};

    public:
        constexpr StrongType() = default;
        constexpr StrongType(T value)
            : _value{ value }
        {
        }

        constexpr const T& value() const noexcept
        {
            return _value;
        }
        
        constexpr T& value() noexcept
        {
            return _value;
        }
                
        constexpr operator T() const
        {
            return _value;
        }

        constexpr bool operator==(const StrongType& other) const
        {
            return _value == other._value;
        }

        constexpr bool operator!=(const StrongType& other) const
        {
            return _value != other._value;
        }

        constexpr bool operator<(const StrongType& other) const
        {
            return _value < other._value;
        }

        constexpr bool operator>(const StrongType& other) const
        {
            return _value > other._value;
        }

        constexpr StrongType operator&(const StrongType& other) const
        {
            return StrongType{ _value & other._value };
        }

        constexpr StrongType operator^(const StrongType& other) const
        {
            return StrongType{ _value ^ other._value };
        }

        constexpr StrongType operator|(const StrongType& other) const
        {
            return StrongType{ _value | other._value };
        }

        constexpr StrongType operator~() const
        {
            return StrongType{ ~_value };
        }
    };
} // namespace zasm
