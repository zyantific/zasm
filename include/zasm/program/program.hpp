  #pragma once
  
  #include "data.hpp"
  #include "embeddedlabel.hpp"
  #include "label.hpp"
  #include "node.hpp"
  #include "section.hpp"
  
  #include <cstdint>
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
          detail::ProgramState* _state;
  
      public:
          Program(MachineMode mode);
          ~Program();
  
          MachineMode getMode() const noexcept;
  
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
          bool removeObserver(Observer& observer);
  
      public:
          /// <summary>
          /// Returns the first node in the Program, if none exists it will return null.
          /// </summary>
          const Node* getHead() const noexcept;
  
          /// <summary>
          /// Returns the last node in the Program, if none exists it will return null.
          /// </summary>
          const Node* getTail() const noexcept;
  
          /// <summary>
          /// Prepends the specified node to the start of the Program.
          /// </summary>
          /// <param name="node">The node to prepend</param>
          /// <returns>The newly inserted node</returns>
          const Node* prepend(const Node* node) noexcept;
  
          /// <summary>
          /// Appends the specified node to the end of the Program.
          /// </summary>
          /// <param name="node">The node to append</param>
          /// <returns>The newly inserted node</returns>
          const Node* append(const Node* node) noexcept;
  
          /// <summary>
          /// Inserts the node into the Program before the specified position.
          /// </summary>
          /// <param name="pos">Position of insertion</param>
          /// <param name="node">The node to insert</param>
          /// <returns>The newly inserted node</returns>
          const Node* insertBefore(const Node* pos, const Node* node) noexcept;
  
          /// <summary>
          /// Inserts the node into the program after the specified position.
          /// </summary>
          /// <param name="pos">Position of insertion</param>
          /// <param name="node">The node to insert</param>
          /// <returns>The newly inserted node</returns>
          const Node* insertAfter(const Node* pos, const Node* node) noexcept;
  
          /// <summary>
          /// Detaches the node from the program, the node will be not destroyed this just unlinks it from the
          /// program.
          /// </summary>
          /// <param name="node">The node to detach</param>
          /// <returns>The next node</returns>
          /// <note>Nodes that are detached are not tracked, make sure they don't get lost to avoid memory leaks</note>
          const Node* detach(const Node* node) noexcept;
  
          /// <summary>
          /// Moves the node after the specified position, if the node is unlinked it will act as insert.
          /// </summary>
          /// <param name="pos">Position of node to move after</param>
          /// <param name="node">The node to move</param>
          /// <returns>The moved node</returns>
          const Node* moveAfter(const Node* pos, const Node* node) noexcept;
  
          /// <summary>
          /// Moves the node before the specified position, if the node is unlinked it will act as insert.
          /// </summary>
          /// <param name="pos">Position of node to move before</param>
          /// <param name="node">The node to move</param>
          /// <returns>The moved node</returns>
          const Node* moveBefore(const Node* pos, const Node* node) noexcept;
  
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
          size_t size() const noexcept;
  
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
  
      public:
          /// <summary>
          /// Allocates a new unlinked node with containing the specified value.
          /// </summary>
          /// <param name="value">The data to place inside the node</param>
          /// <returns>Newly allocated node containing value</returns>
          const Node* createNode(const Instruction& value);
          const Node* createNode(const Data& value);
          const Node* createNode(Data&& value);
          const Node* createNode(const EmbeddedLabel& value);
  
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
          Expected<const Node*, Error> bindLabel(const Label& label);
  
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
          /// Creates a Data object that can be stored in a Node. The data object
          /// can hold up to 32 bytes of data before it will use the heap.
          /// </summary>
          /// <param name="ptr">A pointer to the input data</param>
          /// <param name="len">Size of the data in bytes</param>
          /// <returns>Data object containing a copy of the specified data</returns>
          const Data createData(const void* ptr, size_t len);
  
      public:
          /// <summary>
          /// Creates a new section that can be used to segment code and data.
          /// The section should be bound with bindSection to specify the position.
          /// </summary>
          /// <param name="name">The name of the new section</param>
          /// <param name="attribs">One or multiple Section::Attribs</param>
          /// <param name="align">Specifies the size the section is aligned to, this should be ideally one memory page.</param>
          /// <returns>Section</returns>
          const Section createSection(const char* name, Section::Attribs attribs, int32_t align);
  
          /// <summary>
          /// Binds the section to a new unlinked node. A section can be only bound once.
          /// </summary>
          /// <param name="label">The label to bind</param>
          /// <returns>The new node which contains the section or Error</returns>
          Expected<const Node*, Error> bindSection(const Section& section);
  
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
          int32_t getSectionAlign(const Section& section);
  
          /// <summary>
          /// Sets the section alignment.
          /// </summary>
          /// <param name="section">Section to set align for</param>
          /// <param name="align">The new alignment</param>
          /// <returns>Error::None on success otherwise see Error</returns>
          Error setSectionAlign(const Section& section, int32_t align);
      };
  
  } // namespace zasm
