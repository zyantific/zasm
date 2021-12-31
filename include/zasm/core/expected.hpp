#pragma once

#include <variant>

namespace zasm
{
    namespace detail
    {
        template<typename T> struct Unexpected
        {
            const T failure;

            constexpr Unexpected(const T& val) noexcept
                : failure{ val }
            {
            }
        };
    } // namespace detail

    template<typename TSuccess, typename TFailure> class Expected
    {
        std::variant<TSuccess, ::zasm::detail::Unexpected<TFailure>> data;

    public:
        constexpr Expected(const TSuccess& val) noexcept
            : data{ val }
        {
        }
        constexpr Expected(TSuccess&& val) noexcept
            : data{ std::move(val) }
        {
        }
        constexpr Expected(const ::zasm::detail::Unexpected<TFailure>& val) noexcept
            : data{ val }
        {
        }
        constexpr Expected(::zasm::detail::Unexpected<TFailure>&& val) noexcept
            : data{ std::move(val) }
        {
        }
        constexpr operator bool() const noexcept
        {
            return hasValue();
        }
        constexpr bool hasValue() const noexcept
        {
            return std::holds_alternative<TSuccess>(data);
        }
        constexpr const TFailure& error() const
        {
            return std::get<::zasm::detail::Unexpected<TFailure>>(data).failure;
        }
        constexpr TSuccess& value()
        {
            return std::get<TSuccess>(data);
        }
        constexpr const TSuccess& value() const
        {
            return std::get<TSuccess>(data);
        }
        constexpr TSuccess& operator*()
        {
            return std::get<TSuccess>(data);
        }
        constexpr const TSuccess& operator*() const
        {
            return std::get<TSuccess>(data);
        }
    };

    template<typename T> constexpr ::zasm::detail::Unexpected<T> makeUnexpected(const T& val) noexcept
    {
        return ::zasm::detail::Unexpected<T>(val);
    }

} // namespace xstd