#pragma once

#include "register.hpp"

#include <zasm/base/memory.hpp>

namespace zasm::x86
{
    using Mem = zasm::Mem;

    // ptr [base]
    // ex.: mov eax, ptr [edx]
    static constexpr Mem ptr(BitSize bitSize, const Gp& base) noexcept
    {
        return Mem(bitSize, Seg{}, base, {}, 0, 0);
    }

    // ptr [base + disp]
    // ex.: mov eax, ptr [edx+0xC]
    static constexpr Mem ptr(BitSize bitSize, const Gp& base, int64_t disp) noexcept
    {
        return Mem(bitSize, Seg{}, base, {}, 0, disp);
    }

    // ptr [base + index]
    // ex.: mov eax, ptr [ecx+edx]
    static constexpr Mem ptr(BitSize bitSize, const Gp& base, const Gp& index) noexcept
    {
        return Mem(bitSize, Seg{}, base, index, 1, 0);
    }

    // ptr [base + index * scale]
    // ex.: mov eax, ptr [ecx+edx]
    static constexpr Mem ptr(BitSize bitSize, const Gp& base, const Gp& index, int32_t scale) noexcept
    {
        return Mem(bitSize, Seg{}, base, index, scale, 0);
    }

    // ptr [base + index * scale + disp]
    // ex.: mov eax, ptr [ecx+edx*2+0xC]
    static constexpr Mem ptr(BitSize bitSize, const Gp& base, const Gp& index, int32_t scale, int64_t disp) noexcept
    {
        return Mem(bitSize, Seg{}, base, index, scale, disp);
    }

    // ptr [label]
    // ex.: mov eax, ptr [label]
    static constexpr Mem ptr(BitSize bitSize, const Label& base) noexcept
    {
        return Mem(bitSize, Seg{}, base, Reg{}, Reg{}, 0, 0);
    }

    // ptr [label + disp]
    // ex.: mov eax, ptr [label + 0xC]
    static constexpr Mem ptr(BitSize bitSize, const Label& base, int64_t disp) noexcept
    {
        return Mem(bitSize, Seg{}, base, Reg{}, Reg{}, 0, disp);
    }

    // ptr [rel label]
    // ex.: mov eax, ptr [rel label]
    static constexpr Mem ptr(BitSize bitSize, const Rip& rip, const Label& base) noexcept
    {
        return Mem(bitSize, Seg{}, base, rip, Reg{}, 0, 0);
    }

    // ptr [rel address]
    // ex.: mov eax, ptr [rel 0x00400000]
    static constexpr Mem ptr(BitSize bitSize, const Rip& rip, int64_t disp) noexcept
    {
        return Mem(bitSize, Seg{}, Label{}, rip, Reg{}, 0, disp);
    }

    // ptr [rel label + disp]
    // ex.: mov eax, ptr [rel label+0xC]
    static constexpr Mem ptr(BitSize bitSize, const Rip& rip, const Label& base, int64_t disp) noexcept
    {
        return Mem(bitSize, Seg{}, base, rip, Reg{}, 0, disp);
    }

    // ptr [disp]
    // ex.: mov eax, ptr [0x123456]
    static constexpr Mem ptr(BitSize bitSize, int64_t base) noexcept
    {
        return Mem(bitSize, Seg{}, Reg{}, Reg{}, 0, base);
    }

    // ptr : seg [base]
    // ex.: mov eax, ptr:ds [edx]
    static constexpr Mem ptr(BitSize bitSize, const Seg& seg, const Gp& base) noexcept
    {
        return Mem(bitSize, seg, base, {}, 0, 0);
    }

    // ptr : seg [base + disp]
    // ex.: mov eax, ptr:ds [edx+0xC]
    static constexpr Mem ptr(BitSize bitSize, const Seg& seg, const Gp& base, int64_t disp) noexcept
    {
        return Mem(bitSize, seg, base, {}, 0, disp);
    }

    // ptr : seg [base + index]
    // ex.: mov eax, ptr:ds [edx+ecx]
    static constexpr Mem ptr(BitSize bitSize, const Seg& seg, const Gp& base, const Gp& index) noexcept
    {
        return Mem(bitSize, seg, base, index, 1, 0);
    }

    // ptr : seg [base + index * scale]
    // ex.: mov eax, ptr:ds [edx+ecx*2+0xC]
    static constexpr Mem ptr(BitSize bitSize, const Seg& seg, const Gp& base, const Gp& index, int32_t scale) noexcept
    {
        return Mem(bitSize, seg, base, index, scale, 0);
    }

    // ptr : seg [base + index * scale + disp]
    // ex.: mov eax, ptr:ds [edx+ecx*2+0xC]
    static constexpr Mem ptr(
        BitSize bitSize, const Seg& seg, const Gp& base, const Gp& index, int32_t scale, int64_t disp) noexcept
    {
        return Mem(bitSize, seg, base, index, scale, disp);
    }

    // ptr : seg [label + disp]
    // ex.: mov eax, ptr:ds [label+0xC]
    static constexpr Mem ptr(BitSize bitSize, const Seg& seg, const Label& base, int64_t disp) noexcept
    {
        return Mem(bitSize, seg, base, Reg{}, Reg{}, 0, disp);
    }

    // ptr : seg [rel label]
    // ex.: mov eax, ptr:ds [rel label]
    static constexpr Mem ptr(BitSize bitSize, const Seg& seg, const Rip& rip, const Label& base) noexcept
    {
        return Mem(bitSize, seg, base, rip, Reg{}, 0, 0);
    }

    // ptr : seg [rel label + disp]
    // ex.: mov eax, ptr:ds [rel label+0xC]
    static constexpr Mem ptr(BitSize bitSize, const Seg& seg, const Rip& rip, const Label& base, int64_t disp) noexcept
    {
        return Mem(bitSize, seg, base, rip, Reg{}, 0, disp);
    }

    // ptr : seg [disp]
    // ex.: mov eax, ptr:fs [0]
    static constexpr Mem ptr(BitSize bitSize, const Seg& seg, int64_t disp) noexcept
    {
        return Mem(bitSize, seg, Reg{}, Reg{}, 0, disp);
    }

    // Generic helper functions that specify size
    // See the ptr overloads for all valid forms.
    template<typename... TArgs> static Mem byte_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_8, std::forward<TArgs>(args)...);
    };
    template<typename... TArgs> static Mem word_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_16, std::forward<TArgs>(args)...);
    };
    template<typename... TArgs> static Mem dword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_32, std::forward<TArgs>(args)...);
    };
    template<typename... TArgs> static Mem fword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_48, std::forward<TArgs>(args)...);
    };
    template<typename... TArgs> static Mem qword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_64, std::forward<TArgs>(args)...);
    };
    template<typename... TArgs> static Mem tbyte_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_80, std::forward<TArgs>(args)...);
    };
    template<typename... TArgs> static Mem tword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_80, std::forward<TArgs>(args)...);
    };
    template<typename... TArgs> static Mem oword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_128, std::forward<TArgs>(args)...);
    };
    template<typename... TArgs> static Mem xmmword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_128, std::forward<TArgs>(args)...);
    };
    template<typename... TArgs> static Mem ymmword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_256, std::forward<TArgs>(args)...);
    };
    template<typename... TArgs> static Mem zmmword_ptr(TArgs&&... args) noexcept
    {
        return ptr(BitSize::_512, std::forward<TArgs>(args)...);
    };

} // namespace zasm::x86
