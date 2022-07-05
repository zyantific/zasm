#pragma once

#include "data.hpp"
#include "embeddedlabel.hpp"
#include "instruction.hpp"
#include "label.hpp"
#include "section.hpp"

#include <climits>
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
    public:
        enum class Id : uint32_t
        {
            Invalid = std::numeric_limits<uint32_t>::max(),
        };

    protected:
        const Id _id{ Id::Invalid };
        const Node* _prev{};
        const Node* _next{};
        const std::variant<NodePoint, Instruction, Label, EmbeddedLabel, Data, Section> _data{};

    protected:
        template<typename T>
        constexpr Node(Id id, T&& val) noexcept
            : _id{ id }
            , _data{ std::forward<T>(val) }
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

        template<typename T> constexpr bool holds() const noexcept
        {
            return std::holds_alternative<T>(_data);
        }

        template<typename T> constexpr const T& get() const
        {
            return std::get<T>(_data);
        }

        template<typename T> constexpr const T* getIf() const noexcept
        {
            return std::get_if<T>(&_data);
        }

        template<typename F> constexpr auto visit(F&& f) const
        {
            return std::visit([f = std::move(f)](auto&& data) { return f(data); }, _data);
        }

        /// <summary>
        /// Returns a unique identifier for this node.
        /// </summary>
        /// <returns>Id of node or Id::Invalid if this node is not valid</returns>
        constexpr Id getId() const noexcept
        {
            return _id;
        }

        constexpr bool operator<(const Node& other) const noexcept
        {
            return static_cast<std::underlying_type_t<Node::Id>>(_id)
                < static_cast<std::underlying_type_t<Node::Id>>(other._id);
        }

        constexpr bool operator>(const Node& other) const noexcept
        {
            return static_cast<std::underlying_type_t<Node::Id>>(_id)
                > static_cast<std::underlying_type_t<Node::Id>>(other._id);
        }
    };

} // namespace zasm
