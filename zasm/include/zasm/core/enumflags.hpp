#pragma once

#include <cstdint>
#include <type_traits>

namespace zasm
{

    /// <summary>
    /// Enables enum operators for the given enum type.
    /// </summary>
    /// <typeparam name="ENM">Enum type</typeparam>
#define ZASM_ENABLE_ENUM_OPERATORS(ENM)                                                                                        \
    static_assert(std::is_unsigned_v<std::underlying_type_t<ENM>> == true, "Underlying enum type must be unsigned");           \
    inline constexpr ENM operator|(const ENM a, const ENM b) noexcept                                                          \
    {                                                                                                                          \
        return static_cast<ENM>(static_cast<std::underlying_type_t<ENM>>(a) | static_cast<std::underlying_type_t<ENM>>(b));    \
    }                                                                                                                          \
    inline constexpr ENM operator|=(ENM& a, const ENM b) noexcept                                                              \
    {                                                                                                                          \
        a = static_cast<ENM>(static_cast<std::underlying_type_t<ENM>>(a) | static_cast<std::underlying_type_t<ENM>>(b));       \
        return a;                                                                                                              \
    }                                                                                                                          \
    inline constexpr ENM operator^(const ENM a, const ENM b) noexcept                                                          \
    {                                                                                                                          \
        return static_cast<ENM>(static_cast<std::underlying_type_t<ENM>>(a) ^ static_cast<std::underlying_type_t<ENM>>(b));    \
    }                                                                                                                          \
    inline constexpr ENM operator^=(ENM& a, const ENM b) noexcept                                                              \
    {                                                                                                                          \
        a = static_cast<ENM>(static_cast<std::underlying_type_t<ENM>>(a) ^ static_cast<std::underlying_type_t<ENM>>(b));       \
        return a;                                                                                                              \
    }                                                                                                                          \
    inline constexpr ENM operator&(const ENM a, const ENM b) noexcept                                                          \
    {                                                                                                                          \
        return static_cast<ENM>(static_cast<std::underlying_type_t<ENM>>(a) & static_cast<std::underlying_type_t<ENM>>(b));    \
    }                                                                                                                          \
    inline constexpr ENM operator&=(ENM& a, const ENM b) noexcept                                                              \
    {                                                                                                                          \
        a = static_cast<ENM>(static_cast<std::underlying_type_t<ENM>>(a) & static_cast<std::underlying_type_t<ENM>>(b));       \
        return a;                                                                                                              \
    }                                                                                                                          \
    inline constexpr ENM operator~(const ENM a) noexcept                                                                       \
    {                                                                                                                          \
        return static_cast<ENM>(~static_cast<std::underlying_type_t<ENM>>(a));                                                 \
    }

} // namespace zasm
