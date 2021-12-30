#pragma once

#include <cstdint>
#include <vector>
#include <zasm/core/stringpool.hpp>
#include <zasm/program/label.hpp>
#include <zasm/program/section.hpp>

namespace zasm
{
    // Encoder context used for serialization by the Program.
    struct EncoderSection
    {
        StringPool::Id nameId{};
        int32_t index{};
        int32_t offset{};
        int64_t va{};
        int32_t rawSize{};
        int32_t virtualSize{};
        int32_t align{};
        Section::Attribs attribs{};
    };

    struct EncoderContext
    {
        size_t nodeIndex{};
        size_t sectionIndex{};
        int32_t pass{};
        int64_t baseVA{};
        int64_t va{};
        int32_t offset{};
        int32_t instrSize{};
        int32_t drift{};

        struct LabelLink
        {
            Label::Id id{ Label::Id::Invalid };
            int32_t boundOffset{ -1 };
            int64_t boundVA{ -1 };
        };

        struct SectionLink
        {
            Section::Id id{ Section::Id::Invalid };
            int32_t sectionIndex{ -1 };
            int64_t boundVA{ -1 };
        };

        struct Node
        {
            int64_t va;
            int32_t offset;
            int32_t length;
        };

        std::vector<EncoderSection> sections;
        std::vector<LabelLink> labelLinks;
        std::vector<Node> nodes;
    };
} // namespace zasm