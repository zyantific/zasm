#pragma once

#include <cstdint>
#include <zasm/base/mode.hpp>
#include <zasm/core/bitsize.hpp>

namespace zasm
{

    class Align final
    {
    public:
        enum class Type : uint32_t
        {
            Code = 0,
            Data,
        };

    private:
        Type _type{ Type::Code };
        std::uint32_t _align{ 0U };

    public:
        constexpr Align() noexcept = default;
        constexpr explicit Align(Type type, std::uint32_t align) noexcept
            : _type{ type }
            , _align{ align }
        {
        }

        constexpr bool operator==(const Align& other) const noexcept
        {
            return _type == other._type && _align == other._align;
        }

        constexpr bool operator!=(const Align& other) const noexcept
        {
            return !(*this == other);
        }

        constexpr Type getType() const noexcept
        {
            return _type;
        }

        constexpr Align& setType(Type type) noexcept
        {
            _type = type;
            return *this;
        }

        constexpr std::uint32_t getAlign() const noexcept
        {
            return _align;
        }

        constexpr Align& setAlign(std::uint32_t align) noexcept
        {
            _align = align;
            return *this;
        }

        static constexpr BitSize getBitSize() noexcept
        {
            return BitSize::_0;
        }

        BitSize getBitSize(MachineMode /*unused*/) const noexcept
        {
            return getBitSize();
        }
    };

} // namespace zasm
