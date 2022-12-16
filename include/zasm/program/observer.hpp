#pragma once

namespace zasm
{
    class Node;

    /// <summary>
    /// Observer interface to be implemented by classes that want to be notified of changes in the Program.
    /// </summary>
    class Observer
    {
    public:
        virtual ~Observer() = default;

        /// <summary>
        /// This is called after a node has been created.
        /// </summary>
        /// <param name="node">The node which has been created</param>
        virtual void onNodeCreated(Node* node)
        {
        }

        /// <summary>
        /// This is called before the node is destroyed.
        /// </summary>
        /// <param name="node">The node which will be destroyed</param>
        virtual void onNodeDestroy(Node* node)
        {
        }

        /// <summary>
        /// This is called before a node is detached.
        /// </summary>
        /// <param name="node">The node which will be detached</param>
        virtual void onNodeDetach(Node* node)
        {
        }

        /// <summary>
        /// This is called after a node has been inserted.
        /// </summary>
        /// <param name="node">The node which was inserted</param>
        virtual void onNodeInserted(Node* node)
        {
        }
    };

} // namespace zasm
