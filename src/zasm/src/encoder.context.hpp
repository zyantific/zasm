#pragma once

#include "zasm/label.hpp"

#include <cstdint>
#include <vector>

namespace zasm
{
    // Encoder context used for serialization by the Program.
    struct EncoderContext
    {
        int32_t pass{};
        int32_t nodeIndex{};
        int64_t baseVA{};
        int64_t va{};
        int32_t offset{};
        int32_t instrSize{};
        int32_t drift{};

        struct LabelLink
        {
            Label::Id id{ Label::Id::Invalid };
            int32_t boundOffset{ -1 };
        };

        struct Node
        {
            int32_t offset;
            int32_t length;
        };

        std::vector<LabelLink> labelLinks;
        std::vector<Node> nodes;
    };
} // namespace zasm