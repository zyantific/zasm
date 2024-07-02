#include "zasm/program/program.hpp"

#include "../encoder/encoder.context.hpp"
#include "program.node.hpp"
#include "program.state.hpp"
#include "zasm/program/observer.hpp"

#include <algorithm>
#include <cassert>
#include <cstring>
#include <functional>

namespace zasm
{
    Program::Program(MachineMode mode)
        : _state{ std::make_unique<detail::ProgramState>(mode) }
    {
    }

    Program::Program()
        : Program(MachineMode::Invalid)
    {
    }

    Program::Program(Program&& other) noexcept
    {
        _state = std::move(other._state);
        other._state = std::make_unique<detail::ProgramState>(MachineMode::Invalid);
    }

    Program::~Program()
    {
        clear();
    }

    Program& Program::operator=(Program&& other) noexcept
    {
        clear();

        _state = std::move(other._state);
        other._state = std::make_unique<detail::ProgramState>(MachineMode::Invalid);

        return *this;
    }

    MachineMode Program::getMode() const noexcept
    {
        return _state->mode;
    }

    void Program::setMode(MachineMode mode) noexcept
    {
        _state->mode = mode;
    }

    detail::ProgramState& Program::getState() const noexcept
    {
        return *_state;
    }

    bool Program::addObserver(Observer& observer)
    {
        auto itObserver = std::find(_state->observer.begin(), _state->observer.end(), &observer);
        if (itObserver == _state->observer.end())
        {
            _state->observer.push_back(&observer);
            return true;
        }
        return false;
    }

    bool Program::removeObserver(Observer& observer) noexcept
    {
        auto itObserver = std::find(_state->observer.begin(), _state->observer.end(), &observer);
        if (itObserver == _state->observer.end())
        {
            return false;
        }
        _state->observer.erase(itObserver);
        return true;
    }

    Node* Program::getNodeById(Node::Id id) const noexcept
    {
        auto& nodeMap = _state->nodeMap;

        const auto nodeIdx = static_cast<std::underlying_type_t<Node::Id>>(id);
        if (nodeIdx >= nodeMap.size())
        {
            return nullptr;
        }

        return nodeMap[nodeIdx];
    }

    Node* Program::getNodeForLabel(const Label& label)
    {
        if (!label.isValid())
        {
            return nullptr;
        }

        const auto entryIdx = static_cast<std::size_t>(label.getId());
        if (entryIdx >= _state->labels.size())
        {
            return nullptr;
        }

        auto& entry = _state->labels[entryIdx];
        return entry.node;
    }

    Node* Program::getNodeForSection(const Section& section)
    {
        if (!section.isValid())
        {
            return nullptr;
        }

        const auto entryIdx = static_cast<std::size_t>(section.getId());
        if (entryIdx >= _state->sections.size())
        {
            return nullptr;
        }

        auto& entry = _state->sections[entryIdx];
        return entry.node;
    }

    template<bool TNotify, typename F, typename... TArgs>
    static void notifyObservers(const F&& func, const std::vector<Observer*>& observers, TArgs&&... args) noexcept
    {
        if constexpr (TNotify)
        {
            for (auto* observer : observers)
            {
                std::invoke(func, *observer, std::forward<TArgs>(args)...);
            }
        }
    }

    Node* Program::getHead() const noexcept
    {
        return _state->head;
    }

    Node* Program::getTail() const noexcept
    {
        return _state->tail;
    }

    static void attachNode(detail::Node* node) noexcept
    {
        // Can not attach a node twice.
        assert(node->isAttached() == false);

        // Mark attached.
        node->setAttached(true);
    }

    template<bool TNotify> Node* prepend_(Node* n, detail::ProgramState& state) noexcept
    {
        auto* head = detail::toInternal(state.head);

        auto* node = detail::toInternal(n);
        attachNode(node);

        node->setNext(state.head);
        node->setPrev(nullptr);

        if (head != nullptr)
        {
            head->setPrev(node);
        }
        else
        {
            state.tail = node;
        }

        state.head = node;
        state.nodeCount++;

        notifyObservers<TNotify>(&Observer::onNodeInserted, state.observer, node);

        return state.head;
    }

    Node* Program::prepend(Node* n) noexcept
    {
        return prepend_<true>(n, *_state);
    }

    template<bool TNotify> Node* append_(Node* n, detail::ProgramState& state) noexcept
    {
        auto* tail = detail::toInternal(state.tail);

        auto* node = detail::toInternal(n);
        attachNode(node);

        node->setNext(nullptr);
        if (tail == nullptr)
        {
            node->setPrev(nullptr);
            state.head = state.tail = node;
        }
        else
        {
            tail->setNext(node);
            node->setPrev(tail);
            state.tail = node;
        }

        state.nodeCount++;

        notifyObservers<TNotify>(&Observer::onNodeInserted, state.observer, node);

        return node;
    }

    Node* Program::append(Node* n) noexcept
    {
        return append_<true>(n, *_state);
    }

    template<bool TNotify> Node* insertBefore_(Node* nodePos, Node* nodeToInsert, detail::ProgramState& state) noexcept
    {
        auto* pos = detail::toInternal(nodePos);
        if (pos == nullptr)
        {
            assert(false);
            return nullptr; // Impossible placement.
        }
        if (pos == state.head)
        {
            return prepend_<TNotify>(nodeToInsert, state);
        }

        assert(pos->isAttached());
        auto* pre = detail::toInternal(pos->getPrev());

        auto* node = detail::toInternal(nodeToInsert);
        attachNode(node);

        node->setPrev(pre);
        node->setNext(pos);

        pre->setNext(node);
        pos->setPrev(node);

        state.nodeCount++;

        notifyObservers<TNotify>(&Observer::onNodeInserted, state.observer, node);

        return node;
    }

    Node* Program::insertBefore(Node* pos, Node* node) noexcept
    {
        return insertBefore_<true>(pos, node, *_state);
    }

    template<bool TNotify> Node* insertAfter_(Node* nodePos, Node* nodeToInsert, detail::ProgramState& state) noexcept
    {
        auto* pos = detail::toInternal(nodePos);
        if (pos == nullptr)
        {
            return prepend_<TNotify>(nodeToInsert, state);
        }
        if (pos == state.tail)
        {
            return append_<TNotify>(nodeToInsert, state);
        }

        assert(pos->isAttached());

        auto* next = detail::toInternal(pos->getNext());

        auto* node = detail::toInternal(nodeToInsert);
        attachNode(node);

        pos->setNext(node);

        if (next != nullptr)
        {
            next->setPrev(node);
        }

        node->setPrev(pos);
        node->setNext(next);

        state.nodeCount++;

        notifyObservers<TNotify>(&Observer::onNodeInserted, state.observer, node);

        return node;
    }

    Node* Program::insertAfter(Node* pos, Node* node) noexcept
    {
        return insertAfter_<true>(pos, node, *_state);
    }

    template<bool TNotify> static Node* detach_(Node* nodeToDetach, detail::ProgramState& state) noexcept
    {
        auto* node = detail::toInternal(nodeToDetach);
        if (!node->isAttached())
        {
            // Can't detach a node twice.
            return nullptr;
        }

        node->setAttached(false);

        auto* pre = detail::toInternal(node->getPrev());
        auto* post = detail::toInternal(node->getNext());

        notifyObservers<TNotify>(&Observer::onNodeDetach, state.observer, nodeToDetach);

        if (pre != nullptr)
        {
            pre->setNext(post);
        }
        if (post != nullptr)
        {
            post->setPrev(pre);
        }
        if (node == state.head)
        {
            state.head = post;
        }
        if (node == state.tail)
        {
            state.tail = pre;
        }

        node->setPrev(nullptr);
        node->setNext(nullptr);

        state.nodeCount--;

        return post;
    }

    Node* Program::detach(Node* node) noexcept
    {
        return detach_<true>(node, *_state);
    }

    Node* Program::moveAfter(Node* pos, Node* node) noexcept
    {
        detach_<false>(node, *_state);
        return insertAfter_<false>(pos, node, *_state);
    }

    Node* Program::moveBefore(Node* pos, Node* node) noexcept
    {
        detach_<false>(node, *_state);
        return insertBefore_<false>(pos, node, *_state);
    }

    static void destroyNode(detail::ProgramState& state, Node* node, bool quickDestroy)
    {
        // Keep index before destroying the object.
        const auto nodeIdx = static_cast<std::size_t>(node->getId());

        notifyObservers<true>(&Observer::onNodeDestroy, state.observer, node);

        // If this is called from clear or from destructor we can skip unlinking.
        if (!quickDestroy)
        {
            // Ensure node is not in the list anymore.
            detach_<false>(node, state);
        }

        // Release.
        auto* nodeToDestroy = detail::toInternal(node);
        state.nodePool.destroy(nodeToDestroy);

        if (!quickDestroy)
        {
            // Release memory, when quickDestroy is true the entire pool will be cleared at once.
            state.nodePool.deallocate(nodeToDestroy, 1);

            // Remove mapping.
            auto& nodeMap = state.nodeMap;
            assert(nodeIdx < nodeMap.size());

            // Null out the slot.
            nodeMap[nodeIdx] = nullptr;

            while (!nodeMap.empty() && nodeMap.back() == nullptr)
            {
                nodeMap.pop_back();
            }
        }
    }

    void Program::destroy(Node* node)
    {
        destroyNode(*_state, node, false);
    }

    std::size_t Program::size() const noexcept
    {
        return _state->nodeCount;
    }

    void Program::clear() noexcept
    {
        Node* node = _state->head;
        while (node != nullptr)
        {
            auto* next = node->getNext();
            destroyNode(*_state, node, true);
            node = next;
        }

        _state->head = nullptr;
        _state->tail = nullptr;
        _state->nextNodeId = {};
        _state->nodeCount = 0;

        _state->nodeMap.clear();
        _state->sections.clear();
        _state->labels.clear();
        _state->symbolNames.clear();
        _state->nodePool.reset();
    }

    void Program::setEntryPoint(const Label& label)
    {
        _state->entryPoint = label;
    }

    Label Program::getEntryPoint() const noexcept
    {
        return _state->entryPoint;
    }

    template<typename... TArgs> Node* createNode_(detail::ProgramState& state, TArgs&&... args)
    {
        const auto nextId = state.nextNodeId;
        state.nextNodeId = static_cast<Node::Id>(static_cast<std::underlying_type_t<Node::Id>>(nextId) + 1U);

        auto& pool = state.nodePool;
        auto* node = detail::toInternal(pool.allocate(1));
        if (node == nullptr)
        {
            return nullptr;
        }

        ::new ((void*)node) detail::Node(nextId, std::forward<TArgs&&>(args)...);

        notifyObservers<true>(&Observer::onNodeCreated, state.observer, node);

        const auto nodeIdx = static_cast<std::size_t>(nextId);
        auto& nodeMap = state.nodeMap;
        if (nodeIdx == nodeMap.size())
        {
            nodeMap.push_back(node);
        }
        else if (nodeIdx > nodeMap.size())
        {
            nodeMap.resize(nodeIdx + 1U);
            nodeMap[nodeIdx] = node;
        }

        return node;
    }

    Node* Program::createNode(const Section& section)
    {
        return createNode_(*_state, section);
    }

    Node* Program::createNode(const Label& label)
    {
        return createNode_(*_state, label);
    }

    Node* Program::createNode(const Sentinel& sentinel)
    {
        return createNode_(*_state, sentinel);
    }

    Node* Program::createNode(const Instruction& instr)
    {
        return createNode_(*_state, instr);
    }

    Node* Program::createNode(Instruction&& instr)
    {
        return createNode_(*_state, std::move(instr));
    }

    Node* Program::createNode(const Data& data)
    {
        return createNode_(*_state, data);
    }

    Node* Program::createNode(Data&& data)
    {
        return createNode_(*_state, std::move(data));
    }

    Node* Program::createNode(const Align& align)
    {
        return createNode_(*_state, align);
    }

    Node* Program::createNode(Align&& data)
    {
        return createNode_(*_state, std::move(data));
    }

    Node* Program::createNode(const EmbeddedLabel& label)
    {
        return createNode_(*_state, label);
    }

    static StringPool::Id getStringId(detail::ProgramState& state, const char* str)
    {
        if (str == nullptr)
        {
            return StringPool::Id::Invalid;
        }
        return state.symbolNames.aquire(str);
    }

    static Label createLabel_(detail::ProgramState& state, StringPool::Id nameId, StringPool::Id modId, LabelFlags flags)
    {
        const auto labelId = static_cast<Label::Id>(state.labels.size());

        auto& entry = state.labels.emplace_back();
        entry.id = labelId;
        entry.flags = flags;
        entry.nameId = nameId;
        entry.moduleId = modId;

        return Label{ labelId };
    }

    static bool hasLabelFlags(detail::ProgramState& state, const Label::Id labelId, const LabelFlags flags) noexcept
    {
        const auto entryIdx = static_cast<std::size_t>(labelId);
        if (entryIdx >= state.labels.size())
        {
            return false;
        }

        auto& entry = state.labels[entryIdx];
        return (entry.flags & flags) != LabelFlags::None;
    }

    Label Program::createLabel(const char* name /*= nullptr*/)
    {
        return createLabel_(*_state, getStringId(*_state, name), StringPool::Id::Invalid, LabelFlags::None);
    }

    Expected<Node*, Error> Program::bindLabel(const Label& label)
    {
        const auto entryIdx = static_cast<std::size_t>(label.getId());
        if (entryIdx >= _state->labels.size())
        {
            return makeUnexpected(Error{ ErrorCode::InvalidLabel });
        }

        auto& entry = _state->labels[entryIdx];
        if ((entry.flags & LabelFlags::External) != LabelFlags::None)
        {
            return makeUnexpected(Error{ ErrorCode::ExternalLabelNotBindable });
        }

        if (entry.node != nullptr)
        {
            return makeUnexpected(Error{ ErrorCode::LabelAlreadyBound });
        }

        auto* node = createNode_(*_state, label);
        entry.node = node;

        return node;
    }

    Label Program::createExternalLabel(const char* name /*= nullptr*/)
    {
        return createLabel_(*_state, getStringId(*_state, name), StringPool::Id::Invalid, LabelFlags::External);
    }

    bool Program::isLabelExternal(const Label& label) const noexcept
    {
        if (!label.isValid())
        {
            return false;
        }
        return hasLabelFlags(*_state, label.getId(), LabelFlags::External);
    }

    Label Program::getOrCreateImportLabel(const char* moduleName, const char* importName)
    {
        if (moduleName == nullptr || importName == nullptr)
        {
            return Label{};
        }

        // Allow imports only once.
        const auto modId = getStringId(*_state, moduleName);
        const auto nameId = getStringId(*_state, importName);
        const auto labelFlags = LabelFlags::External | LabelFlags::Import;
        for (std::size_t id = 0; id < _state->labels.size(); ++id)
        {
            auto& entry = _state->labels[id];
            if (entry.flags == labelFlags && entry.moduleId == modId && entry.nameId == nameId)
            {
                return Label{ static_cast<Label::Id>(id) };
            }
        }

        // Create new one.
        return createLabel_(*_state, nameId, modId, labelFlags);
    }

    bool Program::isLabelImport(const Label& label) const noexcept
    {
        return hasLabelFlags(*_state, label.getId(), LabelFlags::Import);
    }

    Expected<LabelData, Error> Program::getLabelData(const Label& label) const noexcept
    {
        if (!label.isValid())
        {
            return zasm::makeUnexpected(Error{ ErrorCode::InvalidLabel });
        }

        const auto entryIdx = static_cast<std::size_t>(label.getId());
        if (entryIdx >= _state->labels.size())
        {
            return makeUnexpected(Error{ ErrorCode::InvalidLabel });
        }

        const auto& entry = _state->labels[entryIdx];

        auto res = LabelData{};
        res.flags = entry.flags;
        res.id = entry.id;
        res.moduleName = entry.moduleId != StringPool::Id::Invalid ? _state->symbolNames.get(entry.moduleId) : nullptr;
        res.name = entry.nameId != StringPool::Id::Invalid ? _state->symbolNames.get(entry.nameId) : nullptr;
        res.node = entry.node;

        return res;
    }

    Section Program::createSection(const char* name, Section::Attribs attribs, std::int32_t align)
    {
        const auto sectId = static_cast<Section::Id>(_state->sections.size());

        auto& entry = _state->sections.emplace_back();
        entry.id = sectId;
        entry.attribs = attribs;
        entry.align = align;

        if (name != nullptr)
        {
            entry.nameId = _state->symbolNames.aquire(name);
        }

        return Section{ sectId };
    }

    static Expected<detail::SectionData*, Error> getSectionData(detail::ProgramState& prog, Section::Id sectionId) noexcept
    {
        const auto entryIdx = static_cast<std::size_t>(sectionId);
        if (entryIdx >= prog.sections.size())
        {
            return makeUnexpected(Error{ ErrorCode::SectionNotFound });
        }
        return &prog.sections[entryIdx];
    }

    Expected<Node*, Error> Program::bindSection(const Section& section)
    {
        auto sectEntry = getSectionData(*_state, section.getId());
        if (!sectEntry.hasValue())
        {
            return makeUnexpected(sectEntry.error());
        }

        auto& entry = sectEntry.value();
        if (entry->node != nullptr)
        {
            return makeUnexpected(Error{ ErrorCode::SectionAlreadyBound });
        }

        auto* node = createNode_(*_state, section);
        entry->node = node;

        return node;
    }

    const char* Program::getSectionName(const Section& section) const noexcept
    {
        auto sectEntry = getSectionData(*_state, section.getId());
        if (!sectEntry.hasValue())
        {
            return nullptr;
        }

        const auto* entry = sectEntry.value();
        return _state->symbolNames.get(entry->nameId);
    }

    Error Program::setSectionName(const Section& section, const char* name)
    {
        if (name == nullptr)
        {
            return ErrorCode::InvalidParameter;
        }

        auto sectEntry = getSectionData(*_state, section.getId());
        if (!sectEntry.hasValue())
        {
            return sectEntry.error();
        }

        auto* entry = sectEntry.value();

        if (entry->nameId != StringPool::Id::Invalid)
        {
            _state->symbolNames.release(entry->nameId);
            entry->nameId = StringPool::Id::Invalid;
        }

        entry->nameId = _state->symbolNames.aquire(name);
        return ErrorCode::None;
    }

    std::int32_t Program::getSectionAlign(const Section& section) noexcept
    {
        auto sectEntry = getSectionData(*_state, section.getId());
        if (!sectEntry.hasValue())
        {
            return -1;
        }

        const auto* entry = sectEntry.value();
        return entry->align;
    }

    Error Program::setSectionAlign(const Section& section, std::int32_t align) noexcept
    {
        if (align <= 0)
        {
            return ErrorCode::InvalidParameter;
        }

        auto sectEntry = getSectionData(*_state, section.getId());
        if (!sectEntry.hasValue())
        {
            return sectEntry.error();
        }

        auto* entry = sectEntry.value();
        entry->align = align;

        return ErrorCode::None;
    }

} // namespace zasm
