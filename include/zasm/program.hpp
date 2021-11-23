#pragma once

#include "data.hpp"
#include "encoder.hpp"
#include "label.hpp"
#include "node.hpp"
#include "objectpool.hpp"
#include "stringpool.hpp"

#include <cstdint>
#include <string>
#include <vector>

namespace zasm
{
    class Program
    {
        ZydisMachineMode _mode{};
        Node* _head{};
        Node* _tail{};
        size_t _nodeCount{};
        std::vector<uint8_t> _outputBuffer{};
        ObjectPool<Node, 1u << 16> _nodes;

    private:
        struct LabelData
        {
            Label::Id id{ Label::Id::Invalid };

            StringPool::Id nameId{ StringPool::Id::Invalid };

            // The physical offset of the label in the buffer.
            int64_t boundOffset{ -1 };

            // Virtual address of label, the base address passed in serialize is used here.
            int64_t boundVA{ -1 };

            // The node that holds/binds the label in the list.
            const Node* labelNode{};
        };

        StringPool _labelNames;
        std::vector<LabelData> _labels;

    public:
        Program(ZydisMachineMode mode)
            : _mode{ mode }
            , _head{}
            , _tail{}
            , _nodeCount{}
        {
        }

    public:
        ZydisMachineMode getMode() const;

    public:
        const Node* getHead() const;
        const Node* getTail() const;

        const Node* prepend(const Node* node);
        const Node* append(const Node* node);

        const Node* insertBefore(const Node* pos, const Node* node);
        const Node* insertAfter(const Node* pos, const Node* node);

        size_t size() const;

    public:
        const Node* createNode(const Instruction& instr);
        const Node* createNode(const Label& label);
        const Node* createNode(const Data& data);

    public:
        const Label createLabel(const char* name = nullptr);
        const Node* bindLabel(const Label& label);

        const Data createData(const void* ptr, size_t len);

    public:
        Error serialize(int64_t newBase);

        size_t getCodeSize() const;
        const uint8_t* getCode() const;

    private:
        struct SerializeState
        {
            EncoderContext& ctx;
            std::vector<uint8_t> buffer;
        };

        Error serialize(SerializeState& state, const NodePoint&);
        Error serialize(SerializeState& state, const Instruction& instr);
        Error serialize(SerializeState& state, const Label& label);
        Error serialize(SerializeState& state, const Data& data);
    };

} // namespace zasm