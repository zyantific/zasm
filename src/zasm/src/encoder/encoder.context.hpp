#pragma once

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <vector>
#include <zasm/base/label.hpp>
#include <zasm/core/stringpool.hpp>
#include <zasm/program/section.hpp>

namespace zasm
{
    enum class RelocationType : std::uint8_t;
    enum class RelocationData : std::uint8_t;

    namespace detail
    {
        struct ProgramState;
    }

    // Encoder context used for serialization by the Program.
    struct EncoderSection
    {
    public:
        StringPool::Id nameId{};
        std::int32_t index{};
        std::int32_t offset{};
        std::int64_t address{};
        std::int64_t rawSize{};
        std::int64_t virtualSize{};
        std::int32_t align{};
        Section::Attribs attribs{};
    };

    struct EncoderContext
    {
    public:
        detail::ProgramState* program{};
        bool needsExtraPass{};
        std::size_t nodeIndex{};
        std::size_t sectionIndex{};
        std::int32_t pass{};
        std::int64_t baseVA{};
        std::int64_t va{};
        std::int32_t offset{};
        std::int32_t instrSize{};
   

        struct LabelLink
        {
        public:
            static constexpr std::int32_t kUnboundOffset = -1;
            static constexpr std::int64_t kUnboundVA = -1;

            Label::Id id{ Label::Id::Invalid };
            std::int32_t boundOffset{ kUnboundOffset };
            std::int64_t boundVA{ kUnboundVA };

            constexpr bool isBound() const noexcept
            {
                return boundOffset != kUnboundOffset;
            }
        };

        struct Node
        {
        public:
            std::int64_t address{};
            std::int32_t offset{};
            std::int32_t length{};
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

            const auto labelIdx = static_cast<std::size_t>(id);
            if (labelIdx >= labelLinks.size())
            {
                const auto resizeStartIndex = labelLinks.size();
                labelLinks.resize(labelIdx + 1);

                // Ensure each entry has a valid id assigned.
                for (std::size_t i = resizeStartIndex; i < labelLinks.size(); i++)
                {
                    labelLinks[i].id = static_cast<Label::Id>(i);
                }

                auto& entry = labelLinks[labelIdx];
                return entry;
            }

            return labelLinks[labelIdx];
        }

        std::optional<std::int64_t> getLabelAddress(Label::Id id)
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
