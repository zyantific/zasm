 #pragma once
 
 #include "register.hpp"
 
 #include <zasm/program/memory.hpp>
 
 namespace zasm::x86
 {
     using Mem = zasm::Mem;
 
     // Default Segment.
     static constexpr Mem ptr(BitSize bitSize, const Gp& base, int64_t disp = 0) noexcept
     {
         return Mem(bitSize, Seg{}, base, {}, 0, disp);
     }
 
     static constexpr Mem ptr(BitSize bitSize, const Gp& base, const Gp& index, int32_t scale, int64_t disp) noexcept
     {
         return Mem(bitSize, Seg{}, base, index, scale, disp);
     }
 
     static constexpr Mem ptr(BitSize bitSize, const Label& base, int64_t disp = 0) noexcept
     {
         return Mem(bitSize, Seg{}, base, Reg{}, Reg{}, 0, disp);
     }
 
     static constexpr Mem ptr(BitSize bitSize, const Rip& rip_, const Label& base, int64_t disp = 0) noexcept
     {
         return Mem(bitSize, Seg{}, base, rip_, Reg{}, 0, disp);
     }
 
     static constexpr Mem ptr(BitSize bitSize, int64_t base) noexcept
     {
         return Mem(bitSize, Seg{}, Reg{}, Reg{}, 0, base);
     }
 
     static constexpr Mem ptr(BitSize bitSize, int64_t base, const Gp& index, int32_t scale) noexcept
     {
         return Mem(bitSize, Seg{}, Reg{}, index, scale, base);
     }
 
     // Explicit Segment
     static constexpr Mem ptr(BitSize bitSize, const Seg& seg, const Gp& base, int64_t disp = 0) noexcept
     {
         return Mem(bitSize, seg, base, {}, 0, disp);
     }
 
     static constexpr Mem ptr(
         BitSize bitSize, const Seg& seg, const Gp& base, const Gp& index, int32_t scale, int64_t disp) noexcept
     {
         return Mem(bitSize, seg, base, index, scale, disp);
     }
 
     static constexpr Mem ptr(BitSize bitSize, const Seg& seg, const Label& base, int64_t disp = 0) noexcept
     {
         return Mem(bitSize, seg, base, Reg{}, Reg{}, 0, disp);
     }
 
     static constexpr Mem ptr(BitSize bitSize, const Seg& seg, const Rip& rip_, const Label& base, int64_t disp = 0) noexcept
     {
         return Mem(bitSize, seg, base, rip_, Reg{}, 0, disp);
     }
 
     static constexpr Mem ptr(BitSize bitSize, const Seg& seg, int64_t disp) noexcept
     {
         return Mem(bitSize, seg, Reg{}, Reg{}, 0, disp);
     }
 
     static constexpr Mem ptr(BitSize bitSize, const Seg& seg, int64_t base, const Gp& index, int32_t scale) noexcept
     {
         return Mem(bitSize, seg, Reg{}, index, scale, base);
     }
 
     // Generic.
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
