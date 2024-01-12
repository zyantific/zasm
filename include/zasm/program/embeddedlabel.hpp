#pragma once

#include <cstddef>
#include <cstdint>
#include <zasm/base/label.hpp>
#include <zasm/core/bitsize.hpp>

namespace zasm
{
    class EmbeddedLabel final
    {
        Label::Id _label{ Label::Id::Invalid };
        Label::Id _relativeLabel{ Label::Id::Invalid };
        BitSize _size{ BitSize::_0 };

    public:
        constexpr EmbeddedLabel() noexcept = default;

        constexpr EmbeddedLabel(const Label& label, BitSize size)
            : _label{ label.getId() }
            , _relativeLabel{ Label::Id::Invalid }
            , _size{ size }
        {
        }

        constexpr EmbeddedLabel(const Label& label, const Label& relativeLabel, BitSize size)
            : _label{ label.getId() }
            , _relativeLabel{ relativeLabel.getId() }
            , _size{ size }
        {
        }

        constexpr bool operator==(const EmbeddedLabel& other) const noexcept
        {
            return _label == other._label && _relativeLabel == other._relativeLabel && _size == other._size;
        }

        constexpr bool operator!=(const EmbeddedLabel& other) const noexcept
        {
            return !(*this == other);
        }

        constexpr Label getLabel() const noexcept
        {
            return Label{ _label };
        }

        constexpr bool isRelative() const noexcept
        {
            return _relativeLabel != Label::Id::Invalid;
        }

        constexpr Label getRelativeLabel() const noexcept
        {
            return Label{ _relativeLabel };
        }

        constexpr BitSize getSize() const noexcept
        {
            return _size;
        }
    };

} // namespace zasm
