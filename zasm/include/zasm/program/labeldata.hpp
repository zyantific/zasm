#pragma once

#include <cstdint>
#include <zasm/base/label.hpp>
#include <zasm/core/enumflags.hpp>

namespace zasm
{
    class Node;

    enum class LabelFlags : uint32_t
    {
        // Normal label.
        None = 0,
        // Label is used for externals.
        External = (1U << 0),
        // Label is used for imports, this is typically accompanied with External.
        Import = (1U << 1),
    };
    ZASM_ENABLE_ENUM_OPERATORS(LabelFlags);

    struct LabelData
    {
        // The id of the label.
        Label::Id id{ Label::Id::Invalid };

        // See LabelFlags
        LabelFlags flags{ LabelFlags::None };

        // For normal labels this is the optional name, for imports this is the import name.
        const char* name{};

        // If the label is for imports this will hold the module name, otherwise nullptr.
        const char* moduleName{};

        // The node that holds/binds the label in the list, external labels will never have a valid node.
        const Node* node{};
    };

} // namespace zasm
