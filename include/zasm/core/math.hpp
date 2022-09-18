#pragma once

#include <type_traits>

namespace zasm::math
{

    template<typename T> static constexpr T alignTo(T val, T align) noexcept
    {
        if (val % align == 0)
            return val;
        return val + (align - (val % align));
    }

    template<typename T> static constexpr T abs(T value) noexcept
    {
        if constexpr (std::is_integral_v<std::decay_t<T>>)
            return value < static_cast<T>(0) ? -value : value;
        else if constexpr (std::is_floating_point_v<std::decay<T>>)
            return value < static_cast<T>(0.0) ? -value : value;
    }

} // namespace zasm::math
