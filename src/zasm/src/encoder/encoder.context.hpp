#pragma once

#include <cassert>
#include <cstdint>
#include <optional>
#include <vector>
#include <zasm/core/stringpool.hpp>
#include <zasm/program/label.hpp>
#include <zasm/program/section.hpp>

namespace zasm
{
    enum class RelocationType : uint8_t;
    enum class RelocationData : uint8_t;

    namespace detail
    {
        class ProgramState;
    }

    // Encoder context used for serialization by the Program.
    struct EncoderSection
    {
        StringPool::Id nameId{};
        int32_t index{};
        int32_t offset{};
        int64_t address{};
        int32_t rawSize{};
        int32_t virtualSize{};
        int32_t align{};
        Section::Attribs attribs{};
    };

    struct EncoderContext
    {
        detail::ProgramState* program{};
        bool needsExtraPass{};
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

        struct Node
        {
            int64_t address{};
            int32_t offset{};
            int32_t length{};
            RelocationType relocKind{};
            RelocationData relocData{};
            Label::Id relocLabel{ Label::Id::Invalid };
        };

        std::vector<EncoderSection> sections;
        std::vector<LabelLink> labelLinks;
        std::vector<Node> nodes;

        LabelLink& getOrCreateLabelLink(Label::Id id)
        {
            assert(id != Label::Id::Invalid);

            const auto labelIdx = static_cast<size_t>(id);
            if (labelIdx >= labelLinks.size())
            {
                const size_t resizeStartIndex = labelLinks.size();
                labelLinks.resize(labelIdx + 1);

                // Ensure each entry has a valid id assigned.
                for (size_t i = resizeStartIndex; i < labelLinks.size(); i++)
                {
                    labelLinks[i].id = static_cast<Label::Id>(i);
                }

                auto& entry = labelLinks[labelIdx];
                return entry;
            }

            return labelLinks[labelIdx];
        }

        std::optional<int64_t> getLabelAddress(Label::Id id)
        {
            assert(id != Label::Id::Invalid);

            const auto& entry = getOrCreateLabelLink(id);
            if (entry.boundVA == -1)
            {
                return std::nullopt;
            }

            return entry.boundVA;
        }
    };
} // namespace zasm