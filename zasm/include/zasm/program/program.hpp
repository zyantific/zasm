#pragma once

#include "data.hpp"
#include "embeddedlabel.hpp"
#include "node.hpp"
#include "section.hpp"

#include <cstddef>
#include <cstdint>
#include <memory>
#include <zasm/base/label.hpp>
#include <zasm/base/mode.hpp>
#include <zasm/core/errors.hpp>
#include <zasm/core/expected.hpp>
#include <zasm/program/labeldata.hpp>

namespace zasm
{
    namespace detail
    {
        struct ProgramState;
    }

    class Observer;

    class Program final
    {
        std::unique_ptr<detail::ProgramState> _state;

    public:
        /// <summary>
        /// Constructs an empty program with no machine mode assigned. It is important
        /// that a machine mode is set before operating with instructions otherwise it may
        /// lead to undefined behavior. This constructor is useful for save/restore situations.
        /// </summary>
        Program();

        /// <summary>
        /// Constructs an empty program with the specified machine mode.
        /// </summary>
        /// <param name="mode">Machine Mode</param>
        Program(MachineMode mode);

        Program(const Program&) = delete;
        Program(Program&& other) noexcept;
        ~Program();

        Program& operator=(const Program&) = delete;
        Program& operator=(Program&& other) noexcept;

        /// <summary>
        /// Gets the current machine mode.
        /// </summary>
        /// <returns>Machine mode</returns>
        MachineMode getMode() const noexcept;

        /// <summary>
        /// Sets the current machine mode.
        /// </summary>
        /// <param name="mode">New mode</param>
        void setMode(MachineMode mode) noexcept;

        /// <summary>
        /// This is primarily used by other components, this should not be directly used.
        /// </summary>
        detail::ProgramState& getState() const noexcept;

        /// <summary>
        /// Adds the observer to the program state, see the observer for the list of events.
        /// The same instance can be only registered once.
        /// </summary>
        /// <param name="observer">The observer instance</param>
        /// <returns>True if the observer was added</returns>
        bool addObserver(Observer& observer);

        /// <summary>
        /// Removes the observer instance from the program state.
        /// </summary>
        /// <param name="observer">The observer instance</param>
        /// <returns>True if the observer was removed</returns>
        bool removeObserver(Observer& observer) noexcept;

    public:
        /// <summary>
        /// Returns the first node in the Program, if none exists it will return null.
        /// </summary>
        Node* getHead() const noexcept;

        /// <summary>
        /// Returns the last node in the Program, if none exists it will return null.
        /// </summary>
        Node* getTail() const noexcept;

        /// <summary>
        /// Prepends the specified node to the start of the Program.
        /// </summary>
        /// <param name="node">The node to prepend</param>
        /// <returns>The newly inserted node</returns>
        Node* prepend(Node* node) noexcept;

        /// <summary>
        /// Appends the specified node to the end of the Program.
        /// </summary>
        /// <param name="node">The node to append</param>
        /// <returns>The newly inserted node</returns>
        Node* append(Node* node) noexcept;

        /// <summary>
        /// Inserts the node into the Program before the specified position.
        /// </summary>
        /// <param name="pos">Position of insertion</param>
        /// <param name="node">The node to insert</param>
        /// <returns>The newly inserted node</returns>
        Node* insertBefore(Node* pos, Node* node) noexcept;

        /// <summary>
        /// Inserts the node into the program after the specified position.
        /// </summary>
        /// <param name="pos">Position of insertion</param>
        /// <param name="node">The node to insert</param>
        /// <returns>The newly inserted node</returns>
        Node* insertAfter(Node* pos, Node* node) noexcept;

        /// <summary>
        /// Detaches the node from the program, the node will be not destroyed this just unlinks it from the
        /// program.
        /// </summary>
        /// <param name="node">The node to detach</param>
        /// <returns>The next node</returns>
        /// <note>Nodes that are detached are not tracked, make sure they don't get lost to avoid memory leaks</note>
        Node* detach(Node* node) noexcept;

        /// <summary>
        /// Moves the node after the specified position, if the node is unlinked it will act as insert.
        /// </summary>
        /// <param name="pos">Position of node to move after</param>
        /// <param name="node">The node to move</param>
        /// <returns>The moved node</returns>
        Node* moveAfter(Node* pos, Node* node) noexcept;

        /// <summary>
        /// Moves the node before the specified position, if the node is unlinked it will act as insert.
        /// </summary>
        /// <param name="pos">Position of node to move before</param>
        /// <param name="node">The node to move</param>
        /// <returns>The moved node</returns>
        Node* moveBefore(Node* pos, Node* node) noexcept;

        /// <summary>
        /// Releases the memory of node back into the pool, the memory is considered invalid after the
        /// call.
        /// </summary>
        /// <param name="node">The node to destroy</param>
        void destroy(Node* node);

        /// <summary>
        /// Returns the current amount of nodes in the list.
        /// </summary>
        /// <returns>Node count</returns>
        std::size_t size() const noexcept;

        /// <summary>
        /// Clears the entire program state, pools will keep their
        /// capacity.
        /// </summary>
        void clear() noexcept;

        /// <summary>
        /// Sets the optional entry point.
        /// </summary>
        /// <param name="label">Entry Point</param>
        void setEntryPoint(const Label& label);

        /// <summary>
        /// Gets the current set entry point.
        /// </summary>
        /// <returns>Label</returns>
        Label getEntryPoint() const noexcept;

        /// <summary>
        /// Looks for a node with the specified id in the program and returns it.
        /// </summary>
        /// <param name="id">Id of the node</param>
        /// <returns>Node with the id or null when not found</returns>
        Node* getNodeById(Node::Id id) const noexcept;

    public:
        /// <summary>
        /// Allocates a new unlinked node with containing the specified value.
        /// </summary>
        /// <param name="value">The data to place inside the node</param>
        /// <returns>Newly allocated node containing value</returns>
        Node* createNode(const Label& label);
        Node* createNode(const Section& section);
        Node* createNode(const Sentinel& sentinel);
        Node* createNode(const Instruction& instr);
        Node* createNode(Instruction&& instr);
        Node* createNode(const Data& data);
        Node* createNode(Data&& data);
        Node* createNode(const Align& align);
        Node* createNode(Align&& data);
        Node* createNode(const EmbeddedLabel& label);

    public:
        /// <summary>
        /// Creates a new label to be used for operands.
        /// The label should be bound with bindLabel to specify the position.
        /// </summary>
        /// <param name="name">Optional label name, pass null for none.</param>
        /// <returns>Label</returns>
        Label createLabel(const char* name = nullptr);

        /// <summary>
        /// Binds the label to a new unlinked node. A label can be only bound once.
        /// </summary>
        /// <param name="label">The label to bind</param>
        /// <returns>The new node which contains the label</returns>
        Expected<Node*, Error> bindLabel(const Label& label);

        /// <summary>
        /// Creates a new named external label that can be referenced and later
        /// patched by relocation items to modify the address.
        /// </summary>
        /// <param name="name">Optional label name, pass null for none.</param>
        /// <returns>Label</returns>
        Label createExternalLabel(const char* name = nullptr);

        /// <summary>
        /// Returns if the specified label is an external label.
        /// </summary>
        /// <param name="label">Label to check</param>
        /// <returns>True if label is external</returns>
        bool isLabelExternal(const Label& label) const noexcept;

        /// <summary>
        /// Gets or creates a new import label, this label can not be bound and is considered an external label.
        /// Import labels are unique per module name and import name so calling this twice with the same parameters
        /// returns the same label.
        /// This label provides a way to post-patch import addresses after serialization.
        /// </summary>
        /// <param name="moduleName">Name of the module to import.</param>
        /// <returns>Label</returns>
        Label getOrCreateImportLabel(const char* moduleName, const char* importName);

        /// <summary>
        /// Returns if the specified label is an import label.
        /// </summary>
        /// <param name="label">Label to check</param>
        /// <returns>True if label is external</returns>
        bool isLabelImport(const Label& label) const noexcept;

        /// <summary>
        /// Returns a structure containing all the data stored for a label.
        /// </summary>
        /// <param name="label">The label to query the data for</param>
        /// <returns>Returns LabelData on success, Error on failure.</returns>
        Expected<LabelData, Error> getLabelData(const Label& label) const noexcept;

        /// <summary>
        /// Returns the node for which the label is bound to. The node holds the Label.
        /// </summary>
        /// <param name="label">Label</param>
        /// <returns>Node for which the label is bound to or null if the label is invalid or not bound</returns>
        Node* getNodeForLabel(const Label& label);

    public:
        /// <summary>
        /// Creates a new section that can be used to segment code and data.
        /// The section should be bound with bindSection to specify the position.
        /// </summary>
        /// <param name="name">The name of the new section</param>
        /// <param name="attribs">One or multiple Section::Attribs</param>
        /// <param name="align">Specifies the size the section is aligned to, this should be ideally one memory page.</param>
        /// <returns>Section</returns>
        Section createSection(const char* name, Section::Attribs attribs, std::int32_t align);

        /// <summary>
        /// Binds the section to a new unlinked node. A section can be only bound once.
        /// </summary>
        /// <param name="label">The label to bind</param>
        /// <returns>The new node which contains the section or Error</returns>
        Expected<Node*, Error> bindSection(const Section& section);

        /// <summary>
        /// Gets the section name.
        /// </summary>
        /// <param name="section">Section to set name for</param>
        /// <returns>Name of the section, nullptr if invalid section</returns>
        const char* getSectionName(const Section& section) const noexcept;

        /// <summary>
        /// Sets the section name.
        /// </summary>
        /// <param name="section">Section to set name for</param>
        /// <param name="name">The new name</param>
        /// <returns>Error::None on success otherwise see Error</returns>
        Error setSectionName(const Section& section, const char* name);

        /// <summary>
        /// Gets the section alignment.
        /// </summary>
        /// <param name="section">Section to set align for</param>
        /// <param name="align">The new alignment</param>
        /// <returns>Section align, -1 if an invalid section was supplied.</returns>
        std::int32_t getSectionAlign(const Section& section) noexcept;

        /// <summary>
        /// Sets the section alignment.
        /// </summary>
        /// <param name="section">Section to set align for</param>
        /// <param name="align">The new alignment</param>
        /// <returns>Error::None on success otherwise see Error</returns>
        Error setSectionAlign(const Section& section, std::int32_t align) noexcept;

        /// <summary>
        /// Returns the node for which the section is bound to. The node holds the Section.
        /// </summary>
        /// <param name="section">Section</param>
        /// <returns>Node for which the section is bound to or null if the section is invalid or not bound</returns>
        Node* getNodeForSection(const Section& section);
    };

} // namespace zasm
