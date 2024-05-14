#pragma once

#include "align.hpp"
#include "data.hpp"
#include "embeddedlabel.hpp"
#include "instruction.hpp"
#include "section.hpp"
#include "sentinel.hpp"

#include <climits>
#include <cstddef>
#include <variant>
#include <zasm/base/label.hpp>
#include <zasm/core/enumflags.hpp>

namespace zasm
{
    enum class NodeFlags : std::uint32_t
    {
        None = 0,
        Attached = 1U << 0,
    };
    ZASM_ENABLE_ENUM_OPERATORS(NodeFlags);

    /// <summary>
    /// A type to hold data such as Instruction, Label, Data etc. within a doubly
    /// linked list managed by the Program. The data is internally stored as a variant
    /// of the possible types a node can hold.
    /// </summary>
    class Node
    {
    public:
        enum class Id : uint32_t
        {
            Invalid = std::numeric_limits<uint32_t>::max(),
        };

    protected:
        Id _id{ Id::Invalid };
        NodeFlags _flags{};
        Node* _prev{};
        Node* _next{};
        std::variant<Sentinel, Instruction, Label, EmbeddedLabel, Data, Section, Align> _data{};

        union
        {
            std::uint64_t userdataU64;
            void* userdataPtr;
        } _extraData{};

    protected:
        // Internal use only.
        template<typename T>
        constexpr Node(Id nodeId, T&& val) noexcept
            : _id{ nodeId }
            , _data{ std::forward<T>(val) }
        {
        }

    public:
        constexpr Node() = default;

        /// <summary>
        /// Returns the previous node.
        /// </summary>
        /// <returns>Previous node or null</returns>
        Node* getPrev() const noexcept
        {
            return _prev;
        }

        /// <see cref="getPrev"/>
        Node* getPrev() noexcept
        {
            return _prev;
        }

        /// <summary>
        /// Returns the next node.
        /// </summary>
        /// <returns>Next node or null</returns>
        Node* getNext() const noexcept
        {
            return _next;
        }

        /// <see cref="getNext"/>
        Node* getNext() noexcept
        {
            return _next;
        }

        /// <summary>
        /// Returns if the current node holds the type specified by T.
        /// </summary>
        /// <typeparam name="T">Type</typeparam>
        /// <returns>True if the T is the current type</returns>
        template<typename T> constexpr bool holds() const noexcept
        {
            return std::holds_alternative<T>(_data);
        }

        /// <summary>
        /// Returns a reference of type T, throws std::bad_variant_access if the current
        /// type is not T.
        /// </summary>
        /// <typeparam name="T">Type</typeparam>
        /// <returns>Returns a reference to the data with the type of T</returns>
        template<typename T> constexpr const T& get() const
        {
            return std::get<T>(_data);
        }

        /// <see cref="get"/>
        template<typename T> constexpr T& get()
        {
            return std::get<T>(_data);
        }

        /// <summary>
        /// Returns a pointer of type T, if the current type is not T it will result
        /// nullptr instead.
        /// </summary>
        /// <typeparam name="T">Type</typeparam>
        /// <returns>Pointer of type T</returns>
        template<typename T> constexpr const T* getIf() const noexcept
        {
            return std::get_if<T>(&_data);
        }

        /// <see cref="getIf"/>
        template<typename T> constexpr T* getIf() noexcept
        {
            return std::get_if<T>(&_data);
        }

        /// <summary>
        /// This is the same as std::visit. This will call the provided function
        /// with the active type as the parameter.
        /// </summary>
        /// <typeparam name="F">Function type</typeparam>
        /// <param name="func">Visitor function</param>
        /// <returns>The result of the visitor function</returns>
        template<typename F> constexpr auto visit(F&& func) const
        {
            return std::visit(std::forward<F>(func), _data);
        }

        /// <see cref="visit"/>
        template<typename F> constexpr auto visit(F&& func)
        {
            return std::visit(std::forward<F>(func), _data);
        }

        /// <summary>
        /// This stores the provided value in this node, the previous
        /// value will be overwritten.
        /// </summary>
        /// <typeparam name="T">Type</typeparam>
        /// <param name="ptr">Value to store</param>
        template<typename T> void setUserData(T* ptr)
        {
            _extraData.userdataPtr = ptr;
        }

        /// <see cref="setUserData(T*)"/>
        void setUserData(std::uint64_t value)
        {
            _extraData.userdataU64 = value;
        }

        /// <see cref="setUserData(T*)"/>
        void setUserData(std::int64_t value)
        {
            _extraData.userdataU64 = static_cast<std::uint64_t>(value);
        }

        /// <summary>
        /// Returns the current value stored and casts it to T*.
        /// Using the wrong type here will lead to undefined behavior when
        /// accessing the memory.
        /// </summary>
        /// <typeparam name="T">The type</typeparam>
        /// <returns>Pointer of type T</returns>
        template<typename T> T* getUserData() const noexcept
        {
            return static_cast<T*>(_extraData.userdataPtr);
        }

        /// <summary>
        /// Returns the current value stored as std::uint64_t.
        /// If the current value stored is a pointer it would return
        /// the value of the pointer.
        /// </summary>
        /// <returns>Current value as std::uint64_t</returns>
        std::uint64_t getUserDataU64() const noexcept
        {
            return _extraData.userdataU64;
        }

        /// <summary>
        /// Returns the current value stored as std::int64_t.
        /// If the current value stored is a pointer it would return
        /// the value of the pointer.
        /// </summary>
        /// <returns>Current value as std::int64_t</returns>
        std::int64_t getUserDataI64() const noexcept
        {
            return static_cast<std::int64_t>(_extraData.userdataU64);
        }

        /// <summary>
        /// Returns a unique identifier for this node.
        /// </summary>
        /// <returns>Id of node or Id::Invalid if this node is not valid</returns>
        constexpr Id getId() const noexcept
        {
            return _id;
        }

        /// <summary>
        /// Returns if the node is equal, this only compares the id due to
        /// nodes being unique in general and can be only created by Program.
        /// </summary>
        /// <param name="other">Other node</param>
        /// <returns>True if equal, false otherwise</returns>
        constexpr bool operator==(const Node& other) const noexcept
        {
            return _id == other._id;
        }

        /// <summary>
        /// Returns if the node is not equal, this only compares the id due to
        /// nodes being unique in general and can be only created by Program.
        /// </summary>
        /// <param name="other">Other node</param>
        /// <returns>True if equal, false otherwise</returns>
        constexpr bool operator!=(const Node& other) const noexcept
        {
            return _id != other._id;
        }

        /// <summary>
        /// Compares if this id is less than the other nodes id.
        /// </summary>
        /// <param name="other">Other node</param>
        /// <returns>True if id is less, false otherwise</returns>
        constexpr bool operator<(const Node& other) const noexcept
        {
            return static_cast<std::underlying_type_t<Node::Id>>(_id)
                < static_cast<std::underlying_type_t<Node::Id>>(other._id);
        }

        /// <summary>
        /// Compares if this id is greater than the other nodes id.
        /// </summary>
        /// <param name="other">Other node</param>
        /// <returns>True if id is greater, false otherwise</returns>
        constexpr bool operator>(const Node& other) const noexcept
        {
            return static_cast<std::underlying_type_t<Node::Id>>(_id)
                > static_cast<std::underlying_type_t<Node::Id>>(other._id);
        }

        /// <summary>
        /// If the node is not attached to a program it will return false. By default
        /// nodes are not attached to a program when created. A call like Program::insetBefore
        /// or Program::insertAfter will attach the node to the program.
        /// </summary>
        /// <returns>True if attached, false otherwise</returns>
        bool isAttached() const noexcept
        {
            return (_flags & NodeFlags::Attached) != NodeFlags::None;
        }
    };

} // namespace zasm
