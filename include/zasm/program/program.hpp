#pragma once

#include "data.hpp"
#include "label.hpp"
#include "node.hpp"

#include <cstdint>
#include <zasm/core/errors.hpp>

namespace zasm
{
    namespace detail
    {
        struct ProgramState;
    }

    class Program
    {
        detail::ProgramState* _state;

    public:
        Program(ZydisMachineMode mode);
        ~Program();

        ZydisMachineMode getMode() const;

    public:
        /// <summary>
        /// Returns the first node in the Program, if none exists it will return null.
        /// </summary>
        const Node* getHead() const;

        /// <summary>
        /// Returns the last node in the Program, if none exists it will return null.
        /// </summary>
        const Node* getTail() const;

        /// <summary>
        /// Prepends the specified node to the start of the Program.
        /// </summary>
        /// <param name="node">The node to prepend</param>
        /// <returns>The newly inserted node</returns>
        const Node* prepend(const Node* node);

        /// <summary>
        /// Appends the specified node to the end of the Program.
        /// </summary>
        /// <param name="node">The node to append</param>
        /// <returns>The newly inserted node</returns>
        const Node* append(const Node* node);

        /// <summary>
        /// Inserts the node into the Program before the specified position.
        /// </summary>
        /// <param name="pos">Position of insertion</param>
        /// <param name="node">The node to insert</param>
        /// <returns>The newly inserted node</returns>
        const Node* insertBefore(const Node* pos, const Node* node);

        /// <summary>
        /// Inserts the node into the program after the specified position.
        /// </summary>
        /// <param name="pos">Position of insertion</param>
        /// <param name="node">The node to insert</param>
        /// <returns>The newly inserted node</returns>
        const Node* insertAfter(const Node* pos, const Node* node);

        /// <summary>
        /// Detaches the node from the program, the node will be not destroyed this just unlinks it from the
        /// program. 
        /// </summary>
        /// <param name="node">The node to detach</param>
        /// <returns>The next node</returns>
        /// <note>Nodes that are detached are not tracked, make sure they don't get lost to avoid memory leaks</note>
        const Node* detach(const Node* node);

        /// <summary>
        /// Moves the node after the specified position, if the node is unlinked it will act as insert.
        /// </summary>
        /// <param name="pos">Position of node to move after</param>
        /// <param name="node">The node to move</param>
        /// <returns>The moved node</returns>
        const Node* moveAfter(const Node* pos, const Node* node);

        /// <summary>
        /// Moves the node before the specified position, if the node is unlinked it will act as insert.
        /// </summary>
        /// <param name="pos">Position of node to move before</param>
        /// <param name="node">The node to move</param>
        /// <returns>The moved node</returns>
        const Node* moveBefore(const Node* pos, const Node* node);

        /// <summary>
        /// Releases the memory of node back into the pool, the memory is considered invalid after the
        /// call.
        /// </summary>
        /// <param name="node">The node to destroy</param>
        void destroy(const Node* node);

        /// <summary>
        /// Returns the current amount of nodes in the list.
        /// </summary>
        /// <returns>Node count</returns>
        size_t size() const;

    public:
        /// <summary>
        /// Allocates a new unlinked node with containing the specified value.
        /// </summary>
        /// <param name="value">The data to place inside the node</param>
        /// <returns>Newly allocated node containing value</returns>
        const Node* createNode(const Instruction& value);
        const Node* createNode(const Data& value);
        const Node* createNode(Data&& value);

    public:
        /// <summary>
        /// Creates a new label to be used for operands. A label should be bound with
        /// bindLabel to specify the position of the label.
        /// </summary>
        /// <param name="name">Optional label name, pass null for none.</param>
        /// <returns>Label</returns>
        const Label createLabel(const char* name = nullptr);

        /// <summary>
        /// Binds the label to a new unlinked node. A label can be only bound once.
        /// </summary>
        /// <param name="label">The label to bind</param>
        /// <returns>The new node which contains the label</returns>
        const Node* bindLabel(const Label& label);

        /// <summary>
        /// Creates a Data object that can be stored in a Node. The data object
        /// can hold up to 32 bytes of data before it will use the heap.
        /// </summary>
        /// <param name="ptr">A pointer to the input data</param>
        /// <param name="len">Size of the data in bytes</param>
        /// <returns>Data object containing a copy of the specified data</returns>
        const Data createData(const void* ptr, size_t len);

    public:
        /// <summary>
        /// Serializes the all the nodes in the Program to the encoder and
        /// resolves the address of each label.
        /// </summary>
        /// <param name="newBase">The starting address of the program</param>
        /// <returns>If successful returns Error::None otherwise check Error value.</returns>
        Error serialize(int64_t newBase);

        /// <summary>
        /// After a successful serialization this will return the total size of all encoded nodes.
        /// </summary>
        /// <returns>Size of code in bytes</returns>
        size_t getCodeSize() const;

        /// <summary>
        /// After a successful serialization this returns pointer to the current code buffer.
        /// </summary>
        /// <returns>Pointer to code buffer</returns>
        const uint8_t* getCode() const;
    };

} // namespace zasm