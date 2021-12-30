#pragma once

#include <cstdint>
#include <type_traits>

namespace zasm
{

#define ZASM_ENABLE_ENUM_OPERATORS(ENM)                                                                                        \
    static_assert(std::is_unsigned_v<std::underlying_type_t<ENM>> == true, "Underlying enum type must be unsignd");            \
    inline constexpr ENM operator|(const ENM a, const ENM b) noexcept                                                          \
    {                                                                                                                          \
        return static_cast<ENM>(static_cast<std::underlying_type_t<ENM>>(a) | static_cast<std::underlying_type_t<ENM>>(b));    \
    }                                                                                                                          \
    inline constexpr ENM operator^(const ENM a, const ENM b) noexcept                                                          \
    {                                                                                                                          \
        return static_cast<ENM>(static_cast<std::underlying_type_t<ENM>>(a) ^ static_cast<std::underlying_type_t<ENM>>(b));    \
    }                                                                                                                          \
    inline constexpr ENM operator&(const ENM a, const ENM b) noexcept                                                          \
    {                                                                                                                          \
        return static_cast<ENM>(static_cast<std::underlying_type_t<ENM>>(a) & static_cast<std::underlying_type_t<ENM>>(b));    \
    }                                                                                                                          \
    inline constexpr ENM operator~(const ENM a) noexcept                                                                       \
    {                                                                                                                          \
        return static_cast<ENM>(~static_cast<std::underlying_type_t<ENM>>(a));                                                 \
    }

} // namespace zasm