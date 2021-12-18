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
            constexpr Node()
                : ::zasm::Node()
            {
            }

            template<typename T>
            constexpr Node(const T& val)
                : ::zasm::Node(val)
            {
            }
            void setPrev(const ::zasm::Node* node)
            {
                _prev = node;
            }
            void setNext(const ::zasm::Node* node)
            {
                _next = node;
            }
        };

        static_assert(sizeof(Node) == sizeof(::zasm::Node));

        static Node* toInternal(const zasm::Node* node)
        {
            return static_cast<Node*>(const_cast<zasm::Node*>(node));
        }

    } // namespace detail

} // namespace zasm