#pragma once

#include "data.hpp"
#include "embeddedlabel.hpp"
#include "instruction.hpp"
#include "label.hpp"
#include "section.hpp"

#include <variant>

namespace zasm
{
    // Placeholder type that represents an empty node.
    // This type can be useful for scenarios where the user wants to keep track
    // of a volatile range by having this at the start and end as markers.
    struct NodePoint
    {
    };

    class Node
    {
    protected:
        const Node* _prev{};
        const Node* _next{};
        const std::variant<NodePoint, Instruction, Label, EmbeddedLabel, Data, Section> _data{};

    protected:
        template<typename T>
        constexpr Node(T&& val) noexcept
            : _data{ std::forward<T>(val) }
        {
        }

    public:
        constexpr Node() = default;

        const Node* getPrev() const noexcept
        {
            return _prev;
        }

        const Node* getNext() const noexcept
        {
            return _next;
        }

        template<typename T> bool holds() const noexcept
        {
            return std::holds_alternative<T>(_data);
        }

        template<typename T> const T& get() const
        {
            return std::get<T>(_data);
        }

        template<typename T> const T* getIf() const noexcept
        {
            return std::get_if<T>(&_data);
        }

        template<typename F> auto visit(F&& f) const
        {
            return std::visit([f = std::move(f)](auto&& data) { return f(data); }, _data);
        }
    };

} // namespace zasm