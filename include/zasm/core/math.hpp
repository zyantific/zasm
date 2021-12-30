#pragma once

namespace zasm::math
{

    template<typename T> T alignTo(T val, T align) noexcept
    {
        if (val % align == 0)
            return val;
        return val + (align - (val % align));
    }

} // namespace zasm::math