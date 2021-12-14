#include "zasm/program.hpp"

#include "encoder.context.hpp"

#include <algorithm>

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

    ZydisMachineMode Program::getMode() const
    {
        return _mode;
    }

    const Node* Program::getHead() const
    {
        return _head;
    }

    const Node* Program::getTail() const
    {
        return _tail;
    }

    const Node* Program::prepend(const Node* n)
    {
        auto* head = detail::toInternal(_head);
        auto* tail = detail::toInternal(_tail);

        auto* node = detail::toInternal(n);
        node->setNext(_head);
        node->setPrev(nullptr);

        if (head != nullptr)
            head->setPrev(node);
        else
            tail = node;

        _head = node;
        _nodeCount++;

        return _head;
    }

    const Node* Program::append(const Node* n)
    {
        auto* head = detail::toInternal(_head);
        auto* tail = detail::toInternal(_tail);

        auto* node = detail::toInternal(n);

        node->setNext(nullptr);
        if (tail == nullptr)
        {
            node->setPrev(nullptr);
            _head = _tail = node;
        }
        else
        {
            tail->setNext(node);
            node->setPrev(tail);
            _tail = node;
        }

        _nodeCount++;

        return node;
    }

    const Node* Program::insertBefore(const Node* p, const Node* n)
    {
        auto* pos = detail::toInternal(p);
        if (pos == _head || pos == nullptr)
            return prepend(n);

        auto* pre = detail::toInternal(pos->getPrev());
        auto* node = detail::toInternal(n);

        node->setPrev(pre);
        node->setNext(pos);

        pre->setNext(node);
        pos->setPrev(node);

        _nodeCount++;

        return node;
    }

    const Node* Program::insertAfter(const Node* p, const Node* n)
    {
        auto* pos = detail::toInternal(p);
        if (pos == _tail || pos == nullptr)
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

        _nodeCount++;

        return node;
    }

    size_t Program::size() const
    {
        return _nodeCount;
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
        return createNode_(_nodes, instr);
    }

    const Node* Program::createNode(const Label& label)
    {
        return createNode_(_nodes, label);
    }

    const Node* Program::createNode(const Data& data)
    {
        return createNode_(_nodes, data);
    }

    const Label Program::createLabel(const char* name /*= nullptr*/)
    {
        const auto labelId = static_cast<Label::Id>(_labels.size());

        auto& entry = _labels.emplace_back();
        entry.id = labelId;
        if (name != nullptr)
        {
            entry.nameId = _labelNames.aquire(name);
        }

        return Label{ labelId };
    }

    const Node* Program::bindLabel(const Label& label)
    {
        const auto entryIdx = static_cast<size_t>(label.getId());
        if (entryIdx >= _labels.size())
        {
            return nullptr;
        }

        const auto* node = createNode(label);

        auto& entry = _labels[entryIdx];
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

    Error Program::serialize(int64_t newBase)
    {
        EncoderContext encoderCtx{};
        encoderCtx.nodes.reserve(_nodeCount);
        encoderCtx.baseVA = newBase;

        SerializeState state{ encoderCtx };

        int32_t codeDiff = 0;
        int32_t codeSize = 0;

        auto serializePass = [&]() {
            state.buffer.clear();

            encoderCtx.pass++;
            encoderCtx.offset = 0;
            encoderCtx.va = newBase;
            encoderCtx.nodeIndex = 0;
            encoderCtx.drift = 0;

            for (const auto* node = _head; node != nullptr; node = node->getNext())
            {
                auto status = node->visit([&](auto&& n) { return serialize(state, n); });
                if (status != Error::None)
                {
                    return status;
                }
            }

            const auto newSize = static_cast<int32_t>(state.buffer.size());
            codeDiff = newSize - codeSize;
            codeSize = newSize;

            return Error::None;
        };

        // Initial.
        if (auto status = serializePass(); status != Error::None)
        {
            return status;
        }

        // Second or more passes.
        do
        {
            if (auto status = serializePass(); status != Error::None)
            {
                return status;
            }

        } while (encoderCtx.drift > 0);

        // Check if all labels were bound, a link entry is added when it encounters a label.
        bool hasUnresolvedLinks = std::any_of(
            std::begin(encoderCtx.labelLinks), std::end(encoderCtx.labelLinks),
            [](auto&& link) { return link.id != Label::Id::Invalid && link.boundOffset == -1; });
        if (hasUnresolvedLinks)
        {
            return Error::UnresolvedLabel;
        }

        // Update all label informations.
        for (auto& labelLink : encoderCtx.labelLinks)
        {
            if (labelLink.id == Label::Id::Invalid)
                continue;

            const auto labelIdx = static_cast<size_t>(labelLink.id);
            if (labelIdx >= _labels.size())
            {
                return Error::InvalidLabel;
            }
            auto& labelEntry = _labels[labelIdx];
            labelEntry.boundOffset = labelLink.boundOffset;
            labelEntry.boundVA = newBase + labelLink.boundOffset;
        }

        _outputBuffer = std::move(state.buffer);

        return Error::None;
    }

    Error Program::serialize(SerializeState&, const NodePoint&)
    {
        return Error::None;
    }

    Error Program::serialize(SerializeState& state, const Instruction& instr)
    {
        auto& ctx = state.ctx;

        EncoderBuffer buf{};

        auto status = encodeFull(buf, state.ctx, _mode, instr);
        if (status != Error::None)
        {
            return status;
        }

        if (ctx.nodeIndex >= ctx.nodes.size())
        {
            ctx.nodes.push_back({ ctx.offset, buf.length });
        }
        else
        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            if (buf.length < nodeEntry.length)
            {
                ctx.drift += nodeEntry.length - buf.length;
            }
            else if (buf.length > nodeEntry.length)
            {
                ctx.drift -= buf.length - nodeEntry.length;
            }
            nodeEntry.length = buf.length;
            nodeEntry.offset = ctx.offset;
        }

        ctx.nodeIndex++;

        ctx.va += buf.length;
        ctx.offset += buf.length;

        auto& buffer = state.buffer;
        buffer.insert(buffer.end(), std::begin(buf.data), std::begin(buf.data) + buf.length);

        return Error::None;
    }

    Error Program::serialize(SerializeState& state, const Label& label)
    {
        auto& ctx = state.ctx;

        if (ctx.nodeIndex >= ctx.nodes.size())
        {
            ctx.nodes.push_back({ ctx.offset, 0 });
        }
        else
        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            nodeEntry.offset = ctx.offset;
        }
        ctx.nodeIndex++;

        const auto labelIdx = static_cast<size_t>(label.getId());
        if (labelIdx >= _labels.size())
        {
            return Error::LabelNotFound;
        }

        if (labelIdx >= ctx.labelLinks.size())
        {
            ctx.labelLinks.resize(labelIdx + 1);
        }

        auto& linkEntry = ctx.labelLinks[labelIdx];
        linkEntry.id = label.getId();
        linkEntry.boundOffset = ctx.offset;

        return Error::None;
    }

    Error Program::serialize(SerializeState& state, const Data& data)
    {
        auto& ctx = state.ctx;

        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(data.getData());
        const auto len = static_cast<int32_t>(data.getSize());

        if (ctx.nodeIndex >= ctx.nodes.size())
        {
            ctx.nodes.push_back({ ctx.offset, static_cast<int32_t>(len) });
        }
        else
        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            nodeEntry.offset = ctx.offset;
            nodeEntry.length = static_cast<int32_t>(len);
        }
        ctx.nodeIndex++;

        ctx.va += len;
        ctx.offset += len;

        auto& buffer = state.buffer;
        buffer.insert(buffer.end(), ptr, ptr + len);

        return Error::None;
    }

    size_t Program::getCodeSize() const
    {
        return _outputBuffer.size();
    }

    const uint8_t* Program::getCode() const
    {
        return _outputBuffer.data();
    }

} // namespace zasm