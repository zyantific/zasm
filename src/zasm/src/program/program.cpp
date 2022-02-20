#include "zasm/program/program.hpp"

#include "../encoder/encoder.context.hpp"
#include "program.node.hpp"
#include "program.state.hpp"

#include <algorithm>
#include <cstring>

namespace zasm
{
    Program::Program(ZydisMachineMode mode)
        : _state{ new detail::ProgramState(mode) }
    {
    }

    Program::~Program()
    {
        const zasm::Node* n = _state->head;
        // Ensure the destructor is called of each object.
        while (n != nullptr)
        {
            const auto* next = n->getNext();
            _state->nodePool.destroy(n);
            n = next;
        }
        delete _state;
    }

    ZydisMachineMode Program::getMode() const noexcept
    {
        return _state->mode;
    }

    const Node* Program::getHead() const noexcept
    {
        return _state->head;
    }

    const Node* Program::getTail() const noexcept
    {
        return _state->tail;
    }

    const Node* Program::prepend(const Node* n) noexcept
    {
        auto* head = detail::toInternal(_state->head);
        auto* tail = detail::toInternal(_state->tail);

        auto* node = detail::toInternal(n);
        node->setNext(_state->head);
        node->setPrev(nullptr);

        if (head != nullptr)
            head->setPrev(node);
        else
            tail = node;

        _state->head = node;
        _state->nodeCount++;

        return _state->head;
    }

    const Node* Program::append(const Node* n) noexcept
    {
        auto* tail = detail::toInternal(_state->tail);
        auto* node = detail::toInternal(n);

        node->setNext(nullptr);
        if (tail == nullptr)
        {
            node->setPrev(nullptr);
            _state->head = _state->tail = node;
        }
        else
        {
            tail->setNext(node);
            node->setPrev(tail);
            _state->tail = node;
        }

        _state->nodeCount++;

        return node;
    }

    const Node* Program::insertBefore(const Node* p, const Node* n) noexcept
    {
        auto* pos = detail::toInternal(p);
        if (pos == _state->head || pos == nullptr)
            return prepend(n);

        auto* pre = detail::toInternal(pos->getPrev());
        auto* node = detail::toInternal(n);

        node->setPrev(pre);
        node->setNext(pos);

        pre->setNext(node);
        pos->setPrev(node);

        _state->nodeCount++;

        return node;
    }

    const Node* Program::insertAfter(const Node* p, const Node* n) noexcept
    {
        auto* pos = detail::toInternal(p);
        if (pos == _state->tail || pos == nullptr)
            return append(n);

        auto* next = detail::toInternal(pos->getNext());
        auto* node = detail::toInternal(n);

        pos->setNext(node);

        if (next != nullptr)
        {
            next->setPrev(node);
        }

        node->setPrev(pos);
        node->setNext(next);

        _state->nodeCount++;

        return node;
    }

    const Node* Program::detach(const Node* node) noexcept
    {
        auto* n = detail::toInternal(node);
        auto* pre = detail::toInternal(n->getPrev());
        auto* post = detail::toInternal(n->getNext());

        if (pre == nullptr && post == nullptr)
            return nullptr;

        if (n == _state->head)
        {
            _state->head = post;

            if (pre != nullptr)
            {
                pre->setPrev(nullptr);
            }

            if (_state->head == nullptr)
            {
                _state->tail = nullptr;
            }
        }
        else if (node == _state->tail)
        {
            _state->tail = post;

            if (post != nullptr)
            {
                post->setNext(nullptr);
            }

            if (_state->tail == nullptr)
            {
                _state->head = nullptr;
            }
        }
        else
        {
            if (pre)
                pre->setNext(post);
            if (post)
                post->setPrev(pre);
        }

        n->setPrev(nullptr);
        n->setNext(nullptr);

        _state->nodeCount--;

        return post;
    }

    const Node* Program::moveAfter(const Node* pos, const Node* node) noexcept
    {
        detach(node);
        return insertAfter(pos, node);
    }

    const Node* Program::moveBefore(const Node* pos, const Node* node) noexcept
    {
        detach(node);
        return insertBefore(pos, node);
    }

    void Program::destroy(const Node* node)
    {
        auto* n = detail::toInternal(node);

        // Ensure node is not in the list anymore.
        detach(node);

        // Release.
        _state->nodePool.destroy(n);
        _state->nodePool.deallocate(n, 1);
    }

    size_t Program::size() const noexcept
    {
        return _state->nodeCount;
    }

    void Program::clear() noexcept
    {
        const Node* node = _state->head;
        while (node != nullptr)
        {
            auto* next = node->getNext();
            destroy(node);
            node = next;
        }

        _state->sections.clear();
        _state->sectionInfo.clear();
        _state->labels.clear();
        _state->codeBuffer.clear();
        _state->symbolNames.clear();
    }

    template<typename TPool, typename... TArgs> const Node* createNode_(TPool& pool, TArgs&&... args)
    {
        auto* node = detail::toInternal(pool.allocate(1));
        if (node == nullptr)
            return nullptr;

        ::new ((void*)node) detail::Node(std::forward<TArgs&&>(args)...);

        return node;
    }

    const Node* Program::createNode(const Instruction& instr)
    {
        return createNode_(_state->nodePool, instr);
    }

    const Node* Program::createNode(const Data& data)
    {
        return createNode_(_state->nodePool, data);
    }

    const Node* Program::createNode(Data&& data)
    {
        return createNode_(_state->nodePool, std::move(data));
    }

    const Label Program::createLabel(const char* name /*= nullptr*/)
    {
        const auto labelId = static_cast<Label::Id>(_state->labels.size());

        auto& entry = _state->labels.emplace_back();
        entry.id = labelId;
        if (name != nullptr)
        {
            entry.nameId = _state->symbolNames.aquire(name);
        }

        return Label{ labelId };
    }

    Expected<const Node*, Error> Program::bindLabel(const Label& label)
    {
        const auto entryIdx = static_cast<size_t>(label.getId());
        if (entryIdx >= _state->labels.size())
        {
            return makeUnexpected(Error::InvalidLabel);
        }

        auto& entry = _state->labels[entryIdx];
        if (entry.node != nullptr)
        {
            return makeUnexpected(Error::LabelAlreadyBound);
        }

        const auto* node = createNode_(_state->nodePool, label);
        entry.node = node;

        return node;
    }

    template<typename T> Data createDataInline(const void* ptr)
    {
        T temp;
        std::memcpy(&temp, ptr, sizeof(T));
        return Data(temp);
    }

    const Data Program::createData(const void* ptr, size_t len)
    {
        if (len == 1)
            return createDataInline<uint8_t>(ptr);
        if (len == 2)
            return createDataInline<uint16_t>(ptr);
        if (len == 4)
            return createDataInline<uint32_t>(ptr);
        if (len == 8)
            return createDataInline<uint64_t>(ptr);
        return Data(ptr, len);
    }

    const Section Program::createSection(const char* name, Section::Attribs attribs, int32_t align)
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

    static Expected<detail::SectionData*, Error> getSectionData(detail::ProgramState& prog, Section::Id id)
    {
        const auto entryIdx = static_cast<size_t>(id);
        if (entryIdx >= prog.sections.size())
        {
            return makeUnexpected(Error::SectionNotFound);
        }
        return &prog.sections[entryIdx];
    }

    Expected<const Node*, Error> Program::bindSection(const Section& section)
    {
        auto sectEntry = getSectionData(*_state, section.getId());
        if (!sectEntry.hasValue())
        {
            return makeUnexpected(sectEntry.error());
        }

        auto& entry = sectEntry.value();
        if (entry->node != nullptr)
        {
            return makeUnexpected(Error::SectionAlreadyBound);
        }

        const auto* node = createNode_(_state->nodePool, section);
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
            return Error::InvalidParameter;
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
        return Error::None;
    }

    int32_t Program::getSectionAlign(const Section& section)
    {
        auto sectEntry = getSectionData(*_state, section.getId());
        if (!sectEntry.hasValue())
        {
            return -1;
        }

        const auto* entry = sectEntry.value();
        return entry->align;
    }

    Error Program::setSectionAlign(const Section& section, int32_t align)
    {
        if (align <= 0)
            return Error::InvalidParameter;

        auto sectEntry = getSectionData(*_state, section.getId());
        if (!sectEntry.hasValue())
        {
            return sectEntry.error();
        }

        auto* entry = sectEntry.value();
        entry->align = align;

        return Error::None;
    }

    size_t Program::getCodeSize() const
    {
        return _state->codeBuffer.size();
    }

    const uint8_t* Program::getCode() const
    {
        if (_state->codeBuffer.empty())
            return nullptr;

        return _state->codeBuffer.data();
    }

    size_t Program::getSectionCount() const
    {
        return _state->sectionInfo.size();
    }

    const SectionInfo* Program::getSectionInfo(size_t sectionIndex) const
    {
        if (sectionIndex >= _state->sectionInfo.size())
            return nullptr;

        return &_state->sectionInfo[sectionIndex];
    }

} // namespace zasm