#include "zasm/program/program.hpp"

#include "../encoder/encoder.context.hpp"
#include "program.state.hpp"

#include <algorithm>

namespace zasm
{
    struct SerializeState
    {
        EncoderContext& ctx;
        std::vector<uint8_t> buffer;
    };

    static Error serializeNode(detail::ProgramState&, SerializeState&, const NodePoint&)
    {
        return Error::None;
    }

    static Error serializeNode(detail::ProgramState& prog, SerializeState& state, const Instruction& instr)
    {
        auto& ctx = state.ctx;

        EncoderBuffer buf{};

        auto status = encodeFull(buf, state.ctx, prog.mode, instr);
        if (status != Error::None)
        {
            return status;
        }

        if (ctx.nodeIndex >= ctx.nodes.size())
        {
            ctx.nodes.push_back({ ctx.offset, buf.length });
        }
        else
        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            if (buf.length < nodeEntry.length)
            {
                ctx.drift += nodeEntry.length - buf.length;
            }
            else if (buf.length > nodeEntry.length)
            {
                ctx.drift -= buf.length - nodeEntry.length;
            }
            nodeEntry.length = buf.length;
            nodeEntry.offset = ctx.offset;
        }

        ctx.nodeIndex++;

        ctx.va += buf.length;
        ctx.offset += buf.length;

        auto& buffer = state.buffer;
        buffer.insert(buffer.end(), std::begin(buf.data), std::begin(buf.data) + buf.length);

        return Error::None;
    }

    static Error serializeNode(detail::ProgramState& prog, SerializeState& state, const Label& label)
    {
        auto& ctx = state.ctx;

        if (ctx.nodeIndex >= ctx.nodes.size())
        {
            ctx.nodes.push_back({ ctx.offset, 0 });
        }
        else
        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            nodeEntry.offset = ctx.offset;
        }
        ctx.nodeIndex++;

        const auto labelIdx = static_cast<size_t>(label.getId());
        if (labelIdx >= prog.labels.size())
        {
            return Error::LabelNotFound;
        }

        if (labelIdx >= ctx.labelLinks.size())
        {
            ctx.labelLinks.resize(labelIdx + 1);
        }

        auto& linkEntry = ctx.labelLinks[labelIdx];
        linkEntry.id = label.getId();
        linkEntry.boundOffset = ctx.offset;

        return Error::None;
    }

    static Error serializeNode(detail::ProgramState& prog, SerializeState& state, const Data& data)
    {
        auto& ctx = state.ctx;

        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(data.getData());
        const auto len = static_cast<int32_t>(data.getSize());

        if (ctx.nodeIndex >= ctx.nodes.size())
        {
            ctx.nodes.push_back({ ctx.offset, static_cast<int32_t>(len) });
        }
        else
        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            nodeEntry.offset = ctx.offset;
            nodeEntry.length = static_cast<int32_t>(len);
        }
        ctx.nodeIndex++;

        ctx.va += len;
        ctx.offset += len;

        auto& buffer = state.buffer;
        buffer.insert(buffer.end(), ptr, ptr + len);

        return Error::None;
    }

    Error Program::serialize(int64_t newBase)
    {
        EncoderContext encoderCtx{};
        encoderCtx.nodes.reserve(_state->nodeCount);
        encoderCtx.baseVA = newBase;

        SerializeState state{ encoderCtx };

        int32_t codeDiff = 0;
        int32_t codeSize = 0;

        const auto serializePass = [&]() {
            state.buffer.clear();

            encoderCtx.pass++;
            encoderCtx.offset = 0;
            encoderCtx.va = newBase;
            encoderCtx.nodeIndex = 0;
            encoderCtx.drift = 0;

            for (const auto* node = _state->head; node != nullptr; node = node->getNext())
            {
                auto status = node->visit([&](auto&& n) { return serializeNode(*_state, state, n); });
                if (status != Error::None)
                {
                    return status;
                }
            }

            const auto newSize = static_cast<int32_t>(state.buffer.size());
            codeDiff = newSize - codeSize;
            codeSize = newSize;

            return Error::None;
        };

        // Initial.
        if (auto status = serializePass(); status != Error::None)
        {
            return status;
        }

        // Second or more passes.
        do
        {
            if (auto status = serializePass(); status != Error::None)
            {
                return status;
            }

        } while (encoderCtx.drift > 0);

        // Check if all labels were bound, a link entry is added when it encounters a label.
        const bool hasUnresolvedLinks = std::any_of(
            std::begin(encoderCtx.labelLinks), std::end(encoderCtx.labelLinks),
            [](auto&& link) { return link.id != Label::Id::Invalid && link.boundOffset == -1; });
        if (hasUnresolvedLinks)
        {
            return Error::UnresolvedLabel;
        }

        // Update all label informations.
        for (auto& labelLink : encoderCtx.labelLinks)
        {
            if (labelLink.id == Label::Id::Invalid)
                continue;

            const auto labelIdx = static_cast<size_t>(labelLink.id);
            if (labelIdx >= _state->labels.size())
            {
                return Error::InvalidLabel;
            }
            auto& labelEntry = _state->labels[labelIdx];
            labelEntry.boundOffset = labelLink.boundOffset;
            labelEntry.boundVA = newBase + labelLink.boundOffset;
        }

        _state->codeBuffer = std::move(state.buffer);

        return Error::None;
    }
} // namespace zasm