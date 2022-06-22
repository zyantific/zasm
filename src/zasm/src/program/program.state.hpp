#pragma once

#include "zasm/core/enumflags.hpp"
#include "zasm/core/objectpool.hpp"
#include "zasm/core/stringpool.hpp"
#include "zasm/encoder/encoder.hpp"
#include "zasm/program/data.hpp"
#include "zasm/program/label.hpp"
#include "zasm/program/node.hpp"
#include "zasm/program/section.hpp"

#include <Zydis/Zydis.h>

namespace zasm::detail
{
    constexpr size_t PoolSize = 1u << 10;

    enum class LabelFlags : uint32_t
    {
        None = 0,
        External = (1u << 0),
    };
    ZASM_ENABLE_ENUM_OPERATORS(LabelFlags);

    struct LabelData
    {
        Label::Id id{ Label::Id::Invalid };
        LabelFlags flags{ LabelFlags::None };
        StringPool::Id nameId{ StringPool::Id::Invalid };

        // The node that holds/binds the label in the list.
        const zasm::Node* node{};
    };

    struct SectionData
    {
        Section::Id id{ Section::Id::Invalid };
        StringPool::Id nameId{ StringPool::Id::Invalid };
        Section::Attribs attribs{};
        int32_t physicalIndex{ -1 };
        int32_t align{};

        // The node that holds/binds the label in the list.
        const zasm::Node* node{};
    };

    struct NodeList
    {
        ObjectPool<Node, PoolSize> nodePool;
        Node* head{};
        Node* tail{};
        size_t nodeCount{};
    };

    struct Symbols
    {
        StringPool symbolNames;
    };

    struct ProgramState : NodeList, Symbols
    {
        ZydisMachineMode mode{};

        std::vector<LabelData> labels;
        std::vector<SectionData> sections;

        ProgramState(ZydisMachineMode m)
            : mode(m)
        {
        }
    };

} // namespace zasm::detail