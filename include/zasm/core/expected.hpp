#pragma once

#include <cassert>
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

        constexpr const TFailure& error() const noexcept
        {
            assert(!hasValue());
            return std::get_if<::zasm::detail::Unexpected<TFailure>>(&data)->failure;
        }

        constexpr TSuccess& value() noexcept
        {
            assert(hasValue());
            return *std::get_if<TSuccess>(&data);
        }

        constexpr const TSuccess& value() const noexcept
        {
            assert(hasValue());
            return *std::get_if<TSuccess>(&data);
        }

        constexpr TSuccess& operator*() noexcept
        {
            return value();
        }

        constexpr const TSuccess& operator*() const noexcept
        {
            return value();
        }

        constexpr TSuccess* operator->() noexcept
        {
            assert(hasValue());
            return std::get_if<TSuccess>(&data);
        }

        constexpr const TSuccess* operator->() const noexcept
        {
            assert(hasValue());
            return std::get_if<TSuccess>(&data);
        }
    };

    template<typename T> inline constexpr ::zasm::detail::Unexpected<T> makeUnexpected(const T& val) noexcept
    {
        return ::zasm::detail::Unexpected<T>(val);
    }

} // namespace zasm
