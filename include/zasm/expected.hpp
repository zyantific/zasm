#pragma once

#include <variant>

/// <summary>
/// Small wrapper that implements some sort of version of std::expected, it may or may not
/// adhere the STL standard.
/// </summary>
namespace xstd
{
    namespace detail
    {
        template<typename T> struct unexpected
        {
            const T failure;

            constexpr unexpected(const T& val)
                : failure{ val }
            {
            }
        };
    } // namespace detail

    template<typename TSuccess, typename TFailure> class expected
    {
        std::variant<TSuccess, detail::unexpected<TFailure>> data;

    public:
        constexpr expected(const TSuccess& val)
            : data{ val }
        {
        }
        constexpr expected(TSuccess&& val)
            : data{ std::move(val) }
        {
        }
        constexpr expected(const detail::unexpected<TFailure>& val)
            : data{ val }
        {
        }
        constexpr expected(detail::unexpected<TFailure>&& val)
            : data{ std::move(val) }
        {
        }
        constexpr operator bool() const
        {
            return data.index() == 0;
        }
        constexpr const TFailure& error() const
        {
            return std::get<detail::unexpected<TFailure>>(data).failure;
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

    template<typename T> constexpr detail::unexpected<T> make_unexpected(const T& val)
    {
        return detail::unexpected<T>(val);
    }

} // namespace xstd