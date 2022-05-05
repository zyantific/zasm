#include "zasm/serialization/serializer.hpp"

#include "../encoder/encoder.context.hpp"
#include "../program/program.state.hpp"
#include "zasm/core/math.hpp"
#include "zasm/encoder/encoder.hpp"

#include <Zydis/Decoder.h>
#include <cassert>

namespace zasm
{
    struct SerializeContext
    {
        EncoderContext& ctx;
        std::vector<uint8_t> buffer;
    };

    struct LabelInfo
    {
        Label::Id labelId{ Label::Id::Invalid };
        size_t boundOffset{};
        size_t boundAddress{};
    };

    namespace detail
    {
        struct SerializerState
        {
            int64_t base{};
            std::vector<SectionInfo> sections;
            std::vector<uint8_t> code;
            std::vector<RelocationInfo> relocations;
            std::vector<LabelInfo> labels;
        };

    } // namespace detail

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

        EncoderResult res{};

        auto status = encodeFull(res, state.ctx, prog.mode, instr);
        if (status != Error::None)
        {
            return status;
        }

        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            if (nodeEntry.length != 0)
            {
                if (res.length < nodeEntry.length)
                {
                    ctx.drift += nodeEntry.length - res.length;
                }
                else if (res.length > nodeEntry.length)
                {
                    ctx.drift -= res.length - nodeEntry.length;
                }
            }
            nodeEntry.length = res.length;
            nodeEntry.offset = ctx.offset;
            nodeEntry.va = ctx.va;
            nodeEntry.relocKind = res.relocKind;

            ctx.nodeIndex++;
        }

        auto& sect = ctx.sections[ctx.sectionIndex];
        sect.rawSize += res.length;

        ctx.va += res.length;
        ctx.offset += res.length;

        auto& buffer = state.buffer;
        buffer.insert(buffer.end(), std::begin(res.data), std::begin(res.data) + res.length);

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

    static Error serializeNode(detail::ProgramState&, SerializeContext& state, const EmbeddedLabel& data)
    {
        auto& ctx = state.ctx;

        int32_t byteSize = 0;
        int64_t labelAddr = 0;

        const auto label = data.getLabel();
        if (auto addr = state.ctx.getLabelAddress(label.getId()); addr.has_value())
        {
            labelAddr = *addr;
        }
        else
        {
            ctx.needsExtraPass = true;
        }

        if (data.isRelative() && !ctx.needsExtraPass)
        {
            const auto relLabel = data.getRelativeLabel();
            if (auto addr = ctx.getLabelAddress(relLabel.getId()); addr.has_value())
            {
                labelAddr -= *addr;
            }
            else
            {
                ctx.needsExtraPass = true;
            }
        }

        uint8_t tempBuf[8]{};

        const auto absValue = std::abs(labelAddr);
        if (data.getSize() == BitSize::_8)
        {
            if (!ctx.needsExtraPass && absValue >= std::numeric_limits<uint8_t>::max())
                return Error::InvalidLabel;

            const auto rawValue = static_cast<int8_t>(labelAddr);
            std::memcpy(tempBuf, &rawValue, sizeof(rawValue));
            byteSize = 1;
        }
        else if (data.getSize() == BitSize::_16)
        {
            if (!ctx.needsExtraPass && absValue >= std::numeric_limits<uint16_t>::max())
                return Error::InvalidLabel;

            const auto rawValue = static_cast<int16_t>(labelAddr);
            std::memcpy(tempBuf, &rawValue, sizeof(rawValue));
            byteSize = 2;
        }
        else if (data.getSize() == BitSize::_32)
        {
            if (!ctx.needsExtraPass && absValue >= std::numeric_limits<uint32_t>::max())
                return Error::InvalidLabel;

            const auto rawValue = static_cast<int32_t>(labelAddr);
            std::memcpy(tempBuf, &rawValue, sizeof(rawValue));
            byteSize = 4;
        }
        else if (data.getSize() == BitSize::_64)
        {
            const auto rawValue = static_cast<int64_t>(labelAddr);
            std::memcpy(tempBuf, &rawValue, sizeof(rawValue));
            byteSize = 8;
        }
        else
        {
            return Error::InvalidOperation;
        }

        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            nodeEntry.offset = ctx.offset;
            nodeEntry.va = ctx.va;
            nodeEntry.length = byteSize;

            if (!data.isRelative())
            {
                // Needs to be relocatable if this is an absolute label.
                nodeEntry.relocKind = RelocationKind::Data;
            }

            ctx.nodeIndex++;
        }

        ctx.va += byteSize;
        ctx.offset += byteSize;

        auto& sect = ctx.sections[ctx.sectionIndex];
        sect.rawSize += byteSize;

        auto& buffer = state.buffer;
        buffer.insert(buffer.end(), tempBuf, tempBuf + byteSize);

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
        _state->labels.clear();
        for (auto& labelLink : encoderCtx.labelLinks)
        {
            if (labelLink.id == Label::Id::Invalid)
                continue;

            const auto labelIdx = static_cast<size_t>(labelLink.id);
            if (labelIdx >= programState.labels.size())
            {
                return Error::InvalidLabel;
            }

            auto& labelEntry = _state->labels.emplace_back();
            labelEntry.labelId = labelLink.id;
            labelEntry.boundOffset = labelLink.boundOffset;
            labelEntry.boundAddress = newBase + labelLink.boundOffset;
        }

        // Generate relocation data.
        ZydisDecoder decoder;
        ZyanStatus decoderStatus{};
        switch (program.getMode())
        {
            case ZYDIS_MACHINE_MODE_LONG_64:
                decoderStatus = ZydisDecoderInit(&decoder, program.getMode(), ZydisStackWidth::ZYDIS_STACK_WIDTH_64);
                break;
            case ZYDIS_MACHINE_MODE_LONG_COMPAT_32:
            case ZYDIS_MACHINE_MODE_LEGACY_32:
                decoderStatus = ZydisDecoderInit(&decoder, program.getMode(), ZydisStackWidth::ZYDIS_STACK_WIDTH_32);
                break;
            case ZYDIS_MACHINE_MODE_LONG_COMPAT_16:
            case ZYDIS_MACHINE_MODE_LEGACY_16:
            case ZYDIS_MACHINE_MODE_REAL_16:
                decoderStatus = ZydisDecoderInit(&decoder, program.getMode(), ZydisStackWidth::ZYDIS_STACK_WIDTH_16);
                break;
            default:
                break;
        }

        ZydisDecodedOperand instrOps[ZYDIS_MAX_OPERAND_COUNT];
        ZydisDecodedInstruction instr;

        _state->relocations.clear();
        for (auto& node : encoderCtx.nodes)
        {
            if (node.relocKind == RelocationKind::None)
                continue;

            RelocationInfo reloc;
            reloc.kind = node.relocKind;

            if (node.relocKind == RelocationKind::Data)
            {
                reloc.offset = node.offset;
                reloc.size = toBitSize(node.length * 8);
            }
            else
            {
                const uint8_t* data = state.buffer.data() + node.offset;

                decoderStatus = ZydisDecoderDecodeFull(
                    &decoder, data, node.length, &instr, instrOps, static_cast<ZyanU8>(std::size(instrOps)), 0);

                if (node.relocKind == RelocationKind::Immediate)
                {
                    if (instr.raw.imm[0].is_relative)
                        continue;

                    reloc.offset = node.offset + instr.raw.imm[0].offset;
                    reloc.size = toBitSize(instr.raw.imm[0].size);
                }
                else if (node.relocKind == RelocationKind::Displacement)
                {
                    reloc.offset = node.offset + instr.raw.disp.offset;
                    reloc.size = toBitSize(instr.raw.disp.size);
                }
            }

            _state->relocations.push_back(reloc);
        }

        _state->code = std::move(state.buffer);

        _state->sections.clear();
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

        _state->base = newBase;

        return Error::None;
    }

    Error Serializer::relocate(int64_t newBase)
    {
        if (_state->code.empty())
            return Error::EmptyState;

        // Make a copy of the code buffer to avoid corrupting the
        // state in case one of the relocations fail.
        auto code = _state->code;

        for (auto& reloc : _state->relocations)
        {
            if (reloc.size == BitSize::_32)
            {
                uint32_t value{};
                std::memcpy(&value, code.data() + reloc.offset, sizeof(value));

                uint64_t newValue = value;
                newValue -= _state->base;
                newValue += newBase;

                if (newValue > std::numeric_limits<uint32_t>::max())
                {
                    return Error::ImpossibleRelocation;
                }

                value = static_cast<uint32_t>(newValue);
                std::memcpy(code.data() + reloc.offset, &value, sizeof(value));
            }
            else if (reloc.size == BitSize::_64)
            {
                uint64_t value{};
                std::memcpy(&value, code.data() + reloc.offset, sizeof(value));

                uint64_t newValue = value;
                newValue -= _state->base;
                newValue += newBase;

                value = static_cast<uint64_t>(newValue);
                std::memcpy(code.data() + reloc.offset, &value, sizeof(value));
            }
        }

        // After relocating assign updated state.
        _state->code = std::move(code);
        _state->base = newBase;

        return Error::None;
    }

    int64_t Serializer::getBase() const noexcept
    {
        return _state->base;
    }

    size_t Serializer::getCodeSize() const noexcept
    {
        return _state->code.size();
    }

    const uint8_t* Serializer::getCode() const noexcept
    {
        if (_state->code.empty())
            return nullptr;

        return _state->code.data();
    }

    size_t Serializer::getSectionCount() const noexcept
    {
        return _state->sections.size();
    }

    const SectionInfo* Serializer::getSectionInfo(size_t sectionIndex) const noexcept
    {
        if (sectionIndex >= _state->sections.size())
            return nullptr;

        return &_state->sections[sectionIndex];
    }

    int64_t Serializer::getLabelOffset(const Label::Id labelId) const noexcept
    {
        const auto idx = static_cast<size_t>(labelId);
        if (idx >= _state->labels.size())
            return -1;

        assert(_state->labels[idx].labelId == labelId);

        return _state->labels[idx].boundOffset;
    }

    int64_t Serializer::getLabelAddress(const Label::Id labelId) const noexcept
    {
        const auto idx = static_cast<size_t>(labelId);
        if (idx >= _state->labels.size())
            return -1;

        assert(_state->labels[idx].labelId == labelId);

        return _state->labels[idx].boundAddress;
    }

    size_t Serializer::getRelocationCount() const noexcept
    {
        return _state->relocations.size();
    }

    const RelocationInfo* Serializer::getRelocation(const size_t index) const noexcept
    {
        if (index >= _state->relocations.size())
            return nullptr;

        return &_state->relocations[index];
    }

    void Serializer::clear()
    {
        _state->base = 0;
        _state->code.clear();
        _state->sections.clear();
        _state->labels.clear();
    }

} // namespace zasm