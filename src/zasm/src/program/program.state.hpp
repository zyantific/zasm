#pragma once

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

    struct LabelData
    {
        Label::Id id{ Label::Id::Invalid };

        StringPool::Id nameId{ StringPool::Id::Invalid };

        // The physical offset of the label in the buffer.
        int64_t boundOffset{ -1 };

        // Virtual address of label, the base address passed in serialize is used here.
        int64_t boundVA{ -1 };

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

    struct PhysicalSection
    {
        StringPool::Id nameId{ StringPool::Id::Invalid };
        Section::Attribs attribs;
        int64_t va;
        size_t index;
        size_t bufferOffset;
        size_t rawSize;
        size_t virtualSize;
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

        std::vector<SectionInfo> sectionInfo;
        std::vector<uint8_t> codeBuffer;

        ProgramState(ZydisMachineMode m)
            : mode(m)
        {
        }
    };

} // namespace zasm::detail