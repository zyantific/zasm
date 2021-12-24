#include "zasm/program/program.hpp"

#include "../encoder/encoder.context.hpp"
#include "program.node.hpp"
#include "program.state.hpp"

#include <algorithm>

namespace zasm
{
    Program::Program(ZydisMachineMode mode)
        : _state{ new detail::ProgramState(mode) }
    {
    }
    Program::~Program()
    {
        delete _state;
    }

    ZydisMachineMode Program::getMode() const
    {
        return _state->mode;
    }

    const Node* Program::getHead() const
    {
        return _state->head;
    }

    const Node* Program::getTail() const
    {
        return _state->tail;
    }

    const Node* Program::prepend(const Node* n)
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

    const Node* Program::append(const Node* n)
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

    const Node* Program::insertBefore(const Node* p, const Node* n)
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

    const Node* Program::insertAfter(const Node* p, const Node* n)
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

    size_t Program::size() const
    {
        return _state->nodeCount;
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

    const Node* Program::createNode(const Label& label)
    {
        return createNode_(_state->nodePool, label);
    }

    const Node* Program::createNode(const Data& data)
    {
        return createNode_(_state->nodePool, data);
    }

    const Label Program::createLabel(const char* name /*= nullptr*/)
    {
        const auto labelId = static_cast<Label::Id>(_state->labels.size());

        auto& entry = _state->labels.emplace_back();
        entry.id = labelId;
        if (name != nullptr)
        {
            entry.nameId = _state->labelNames.aquire(name);
        }

        return Label{ labelId };
    }

    const Node* Program::bindLabel(const Label& label)
    {
        const auto entryIdx = static_cast<size_t>(label.getId());
        if (entryIdx >= _state->labels.size())
        {
            return nullptr;
        }

        const auto* node = createNode(label);

        auto& entry = _state->labels[entryIdx];
        entry.labelNode = node;

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

    size_t Program::getCodeSize() const
    {
        return _state->codeBuffer.size();
    }

    const uint8_t* Program::getCode() const
    {
        return _state->codeBuffer.data();
    }

} // namespace zasm