#pragma once

#include "zasm/base/mode.hpp"
#include "zasm/core/enumflags.hpp"
#include "zasm/core/objectpool.hpp"
#include "zasm/core/stringpool.hpp"
#include "zasm/encoder/encoder.hpp"
#include "zasm/program/data.hpp"
#include "zasm/program/label.hpp"
#include "zasm/program/labeldata.hpp"
#include "zasm/program/node.hpp"
#include "zasm/program/section.hpp"

#include <Zydis/Zydis.h>
#include <cstddef>
#include <vector>

namespace zasm
{
    class Observer;
}

namespace zasm::detail
{
    constexpr std::size_t PoolSize = 1U << 10;

    struct LabelData
    {
        Label::Id id{ Label::Id::Invalid };
        LabelFlags flags{ LabelFlags::None };
        StringPool::Id nameId{ StringPool::Id::Invalid };
        StringPool::Id moduleId{ StringPool::Id::Invalid };

        // The node that holds/binds the label in the list.
        const zasm::Node* node{};
    };

    struct SectionData
    {
        Section::Id id{ Section::Id::Invalid };
        StringPool::Id nameId{ StringPool::Id::Invalid };
        Section::Attribs attribs{};
        std::int32_t physicalIndex{ -1 };
        std::int32_t align{};

        // The node that holds/binds the label in the list.
        const zasm::Node* node{};
    };

    struct NodeStorage
    {
        ObjectPool<Node, PoolSize> nodePool;
        Node::Id nextNodeId{};
    };

    struct NodeList
    {
        Node* head{};
        Node* tail{};
        std::size_t nodeCount{};
    };

    struct Symbols
    {
        StringPool symbolNames;
    };

    struct ProgramState : NodeStorage, NodeList, Symbols
    {
        MachineMode mode{};

        std::vector<LabelData> labels;
        std::vector<SectionData> sections;
        std::vector<Observer*> observer;

        Label entryPoint{ Label::Id::Invalid };

        ProgramState(MachineMode m)
            : mode(m)
        {
        }
    };

} // namespace zasm::detail
