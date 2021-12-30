#pragma once

#include "data.hpp"
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
        const std::variant<NodePoint, Instruction, Label, Data, Section> _data{};

    protected:
        constexpr Node(const NodePoint& val) noexcept
            : _data{ val }
        {
        }
        constexpr Node(NodePoint&& val) noexcept
            : _data{ val }
        {
        }
        constexpr Node(const Instruction& val) noexcept
            : _data{ val }
        {
        }
        constexpr Node(Instruction&& val) noexcept
            : _data{ val }
        {
        }
        constexpr Node(const Label& val) noexcept
            : _data{ val }
        {
        }
        constexpr Node(const Section& val) noexcept
            : _data{ val }
        {
        }
        constexpr Node(const Data& val) noexcept
            : _data{ val }
        {
        }
        constexpr Node(Data&& val) noexcept
            : _data{ val }
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

        template<typename T> bool is() const noexcept
        {
            return std::holds_alternative<T>(_data);
        }

        template<typename T> const T& as() const
        {
            return std::get<T>(_data);
        }

        template<typename T> const T* tryAs() const noexcept
        {
            return std::get_if<T>(&_data);
        }

        template<typename F> auto visit(F&& f) const
        {
            return std::visit([f = std::move(f)](auto&& data) { return f(data); }, _data);
        }
    };

    constexpr size_t SizeOfNode = sizeof(Node);

} // namespace zasm