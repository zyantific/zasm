#pragma once

#include <cstdint>
#include <zasm/base/mode.hpp>
#include <zasm/core/bitsize.hpp>

namespace zasm
{
    class Reg
    {
    public:
        // For debug builds this makes inspection easier.
        // For release builds size matters more.
        enum class Id : std::int16_t
        {
            None = 0,
            Invalid = -1,
        };

        enum class Class : std::uint8_t
        {
            Invalid = 0,
        };

    protected:
        Id _reg{ Id::None };

    public:
        constexpr Reg() noexcept = default;
        constexpr explicit Reg(const Id reg) noexcept
            : _reg{ reg }
        {
        }

        BitSize getBitSize(MachineMode mode) const noexcept;

        Class getClass() const noexcept;

        /// <summary>
        /// Returns the index per register class
        /// NOTE: For Gp8 there are 20 registers, hi/lo regs are in the same class.
        /// </summary>
        std::int8_t getIndex() const noexcept;

        /// <summary>
        /// Returns the physical index which is also used for the encoding.
        /// </summary>
        /// <returns>Physical index, typically 0 to 31. Returns -1 if it has no index.</returns>
        std::int8_t getPhysicalIndex() const noexcept;

        /// <summary>
        /// Returns the root register for registers that are lower size, ex.: root of ax
        /// would be eax on 32 bit mode and rax on 64 bit.
        /// In case the register has no root it will return Reg::None.
        /// </summary>
        Reg getRoot(MachineMode mode) const noexcept;

        /// <summary>
        /// Returns the offset in the space of the root register as bytes.
        /// This is typically 0 except for Gp8Hi registers.
        /// </summary>
        std::int8_t getOffset() const noexcept;

        bool isIP() const noexcept;
        bool isGp8() const noexcept;
        bool isGp8Lo() const noexcept;
        bool isGp8Hi() const noexcept;
        bool isGp16() const noexcept;
        bool isGp32() const noexcept;
        bool isGp64() const noexcept;
        bool isGp() const noexcept;
        bool isSeg() const noexcept;
        bool isXmm() const noexcept;
        bool isYmm() const noexcept;
        bool isZmm() const noexcept;
        bool isBnd() const noexcept;
        bool isControl() const noexcept;
        bool isDebug() const noexcept;
        bool isMask() const noexcept;
        bool isMmx() const noexcept;
        bool isTmm() const noexcept;
        
        constexpr Id getId() const noexcept
        {
            return _reg;
        }

        constexpr bool isValid() const noexcept
        {
            return getId() != Id::None;
        }

        constexpr bool operator==(const Reg& other) const noexcept
        {
            return _reg == other._reg;
        }

        constexpr bool operator!=(const Reg& other) const noexcept
        {
            return _reg != other._reg;
        }

        constexpr bool operator<(const Reg& other) const noexcept
        {
            return _reg < other._reg;
        }

        constexpr bool operator>(const Reg& other) const noexcept
        {
            return _reg > other._reg;
        }

        template<typename T> constexpr T& as() noexcept
        {
            return static_cast<T&>(*this);
        }

        template<typename T> constexpr const T& as() const noexcept
        {
            return static_cast<T&>(*this);
        }
    };

} // namespace zasm
