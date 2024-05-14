#pragma once

namespace zasm
{
    /// <summary>
    /// Placeholder type that represents an empty node.
    /// This type can be useful for scenarios where the user wants to keep track
    /// of a volatile range by having this at the start and end as markers.
    /// </summary>
    struct Sentinel final
    {
    };

} // namespace zasm
