#pragma once

namespace zasm
{
    /// <summary>
    /// A wrapper to provide a stronger type than just a primitive. The wrapper
    /// still has an implicit conversion to the underlying type in order to work
    /// for switch statements and other cases where the underlying type is needed.
    /// </summary>
    /// <typeparam name="T">Underlying type</typeparam>
    template<typename T> class StrongType
    {
    public:
        using ValueType = T;

        constexpr StrongType() = default;
        constexpr StrongType(T value)
            : _value{ value }
        {
        }

        constexpr const ValueType& value() const noexcept
        {
            return _value;
        }

        constexpr ValueType& value() noexcept
        {
            return _value;
        }

        constexpr operator ValueType() const
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

    private:
        ValueType _value;
    };
    
} // namespace zasm
