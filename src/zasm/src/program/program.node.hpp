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
            void setPrev(const ::zasm::Node* node) noexcept
            {
                _prev = node;
            }
            void setNext(const ::zasm::Node* node) noexcept
            {
                _next = node;
            }
        };

        static_assert(sizeof(Node) == sizeof(::zasm::Node));

        static Node* toInternal(const zasm::Node* node) noexcept
        {
            return static_cast<Node*>(const_cast<zasm::Node*>(node));
        }

    } // namespace detail

} // namespace zasm
