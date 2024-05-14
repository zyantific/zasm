#pragma once

#include "zasm/program/node.hpp"

namespace zasm
{
    namespace detail
    {
        // Internal node type to access protected members by Program.
        class Node : public zasm::Node
        {
        public:
            template<typename T>
            constexpr Node(zasm::Node::Id id, T&& val) noexcept
                : ::zasm::Node(id, std::forward<T>(val))
            {
            }
            void setPrev(::zasm::Node* node) noexcept
            {
                _prev = node;
            }
            void setNext(::zasm::Node* node) noexcept
            {
                _next = node;
            }
            void setId(Node::Id id)
            {
                _id = id;
            }

            void setAttached(bool attached) noexcept
            {
                if (attached)
                    _flags = _flags | NodeFlags::Attached;
                else
                    _flags = _flags & ~NodeFlags::Attached;
            }
        };

        static_assert(sizeof(Node) == sizeof(::zasm::Node));

        static detail::Node* toInternal(zasm::Node* node) noexcept
        {
            return static_cast<Node*>(node);
        }

        static const detail::Node* toInternal(const zasm::Node* node) noexcept
        {
            return static_cast<const Node*>(node);
        }

    } // namespace detail

} // namespace zasm
