#include "zasm/serialization/serializer.hpp"

#include "../encoder/encoder.context.hpp"
#include "../program/program.state.hpp"
#include "zasm/core/math.hpp"

namespace zasm
{
    struct SerializeContext
    {
        EncoderContext& ctx;
        std::vector<uint8_t> buffer;
    };

    namespace detail {

        struct SerializerState
        {
            std::vector<SectionInfo> sections;
            std::vector<uint8_t> code;
        };

    }

    static Error serializeNode(detail::ProgramState&, SerializeContext& state, const NodePoint&)
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
            nodeEntry.va = ctx.va;
        }
        ctx.nodeIndex++;

        return Error::None;
    }

    static Error serializeNode(detail::ProgramState& prog, SerializeContext& state, const Instruction& instr)
    {
        auto& ctx = state.ctx;

        EncoderBuffer buf{};

        auto status = encodeFull(buf, state.ctx, prog.mode, instr);
        if (status != Error::None)
        {
            return status;
        }

        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            if (nodeEntry.length != 0)
            {
                if (buf.length < nodeEntry.length)
                {
                    ctx.drift += nodeEntry.length - buf.length;
                }
                else if (buf.length > nodeEntry.length)
                {
                    ctx.drift -= buf.length - nodeEntry.length;
                }
            }
            nodeEntry.length = buf.length;
            nodeEntry.offset = ctx.offset;
            nodeEntry.va = ctx.va;

            ctx.nodeIndex++;
        }

        auto& sect = ctx.sections[ctx.sectionIndex];
        sect.rawSize += buf.length;

        ctx.va += buf.length;
        ctx.offset += buf.length;

        auto& buffer = state.buffer;
        buffer.insert(buffer.end(), std::begin(buf.data), std::begin(buf.data) + buf.length);

        return Error::None;
    }

    static Error serializeNode(detail::ProgramState& prog, SerializeContext& state, const Label& label)
    {
        auto& ctx = state.ctx;

        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            nodeEntry.length = 0;
            nodeEntry.offset = ctx.offset;
            nodeEntry.va = ctx.va;
            ctx.nodeIndex++;
        }

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
        linkEntry.boundVA = ctx.va;

        return Error::None;
    }

    static bool isSameSection(const EncoderSection& a, const EncoderSection& b)
    {
        return a.nameId == b.nameId && a.attribs == b.attribs && a.align == b.align;
    }

    static void finalizeCurSection(SerializeContext& state)
    {
        auto& ctx = state.ctx;

        auto& curSection = ctx.sections[ctx.sectionIndex];

        // Final virtual size.
        curSection.virtualSize = math::alignTo<int32_t>(curSection.rawSize, curSection.align);

        // Align current address.
        ctx.va = math::alignTo<int64_t>(ctx.va, curSection.align);
    }

    static Error serializeNode(detail::ProgramState& prog, SerializeContext& state, const Section& section)
    {
        auto& ctx = state.ctx;

        const auto sectionIndex = static_cast<size_t>(section.getId());
        if (sectionIndex >= prog.sections.size())
        {
            return Error::SectionNotFound;
        }

        auto& sectionData = prog.sections[sectionIndex];

        auto& curSection = ctx.sections[ctx.sectionIndex];

        // Check if sections should be merged.
        EncoderSection newSect{};
        newSect.attribs = sectionData.attribs;
        newSect.nameId = sectionData.nameId;
        newSect.align = sectionData.align;

        if (!isSameSection(curSection, newSect))
        {
            // Finish this section.
            finalizeCurSection(state);

            // Add new section.
            newSect.index = static_cast<int32_t>(ctx.sections.size());
            newSect.offset = ctx.offset;
            newSect.va = ctx.va;

            ctx.sections.push_back(newSect);
            ctx.sectionIndex++;
        }

        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            nodeEntry.length = 0;
            nodeEntry.offset = ctx.offset;
            nodeEntry.va = ctx.va;
            ctx.nodeIndex++;
        }

        return Error::None;
    }

    static Error serializeNode(detail::ProgramState&, SerializeContext& state, const Data& data)
    {
        auto& ctx = state.ctx;

        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(data.getData());
        const auto len = static_cast<int32_t>(data.getSize());

        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            nodeEntry.offset = ctx.offset;
            nodeEntry.va = ctx.va;
            nodeEntry.length = static_cast<int32_t>(len);
            ctx.nodeIndex++;
        }

        ctx.va += len;
        ctx.offset += len;

        auto& sect = ctx.sections[ctx.sectionIndex];
        sect.rawSize += len;

        auto& buffer = state.buffer;
        buffer.insert(buffer.end(), ptr, ptr + len);

        return Error::None;
    }

    Serializer::Serializer()
        : _state(new detail::SerializerState())
    {
    }

    Serializer::~Serializer()
    {
        delete _state;
    }

    void Serializer::clear()
    {
        _state->code.clear();
        _state->sections.clear();
    }

    Error Serializer::serialize(const Program& program, int64_t newBase)
    {
        detail::ProgramState& programState = program.getState();

        EncoderContext encoderCtx{};
        encoderCtx.nodes.resize(program.size());
        encoderCtx.baseVA = newBase;

        SerializeContext state{ encoderCtx, {} };

        int32_t codeDiff = 0;
        int32_t codeSize = 0;

        EncoderSection defaultSect{};
        defaultSect.index = 0;
        defaultSect.attribs = Section::Attribs::Code;
        defaultSect.va = newBase;
        defaultSect.nameId = programState.symbolNames.aquire(".text");
        defaultSect.align = 0x1000;

        const auto serializePass = [&]() {
            state.buffer.clear();

            encoderCtx.needsExtraPass = false;
            encoderCtx.pass++;
            encoderCtx.offset = 0;
            encoderCtx.va = newBase;
            encoderCtx.nodeIndex = 0;
            encoderCtx.sectionIndex = 0;
            encoderCtx.drift = 0;

            // Setup default section.
            encoderCtx.sections.clear();
            encoderCtx.sections.push_back(defaultSect);

            for (const auto* node = program.getHead(); node != nullptr; node = node->getNext())
            {
                auto status = node->visit([&](auto&& n) { return serializeNode(programState, state, n); });
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

        // Check if all labels were bound, a link entry is added when it encounters a label.
        const bool hasUnresolvedLinks = std::any_of(
            std::begin(encoderCtx.labelLinks), std::end(encoderCtx.labelLinks),
            [](auto&& link) { return link.id != Label::Id::Invalid && link.boundOffset == -1; });
        if (hasUnresolvedLinks)
        {
            return Error::UnresolvedLabel;
        }

        // Second or more passes.
        while (encoderCtx.needsExtraPass || encoderCtx.drift != 0)
        {
            if (auto status = serializePass(); status != Error::None)
            {
                return status;
            }
        }

        // Finalize last section.
        finalizeCurSection(state);

        // Update all label information.
        for (auto& labelLink : encoderCtx.labelLinks)
        {
            if (labelLink.id == Label::Id::Invalid)
                continue;

            const auto labelIdx = static_cast<size_t>(labelLink.id);
            if (labelIdx >= programState.labels.size())
            {
                return Error::InvalidLabel;
            }
            auto& labelEntry = programState.labels[labelIdx];
            labelEntry.boundOffset = labelLink.boundOffset;
            labelEntry.boundVA = newBase + labelLink.boundOffset;
        }

        _state->code = std::move(state.buffer);

        for (auto& sectionLink : encoderCtx.sections)
        {
            const size_t idx = _state->sections.size();

            auto& sect = _state->sections.emplace_back();
            sect.name = programState.symbolNames.get(sectionLink.nameId);
            sect.attribs = sectionLink.attribs;
            sect.buffer = _state->code.data() + sectionLink.offset;
            sect.physicalSize = sectionLink.rawSize;
            sect.virtualSize = sectionLink.virtualSize;
            sect.va = sectionLink.va;
            sect.index = idx;
        }

        return Error::None;
    }

    size_t Serializer::getCodeSize() const
    {
        return _state->code.size();
    }

    const uint8_t* Serializer::getCode() const
    {
        if (_state->code.empty())
            return nullptr;

        return _state->code.data();
    }

    size_t Serializer::getSectionCount() const
    {
        return _state->sections.size();
    }

    const SectionInfo* Serializer::getSectionInfo(size_t sectionIndex) const
    {
        if (sectionIndex >= _state->sections.size())
            return nullptr;

        return &_state->sections[sectionIndex];
    }

} // namespace zasm