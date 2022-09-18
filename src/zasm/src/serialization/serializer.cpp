#include "zasm/serialization/serializer.hpp"

#include "../encoder/encoder.context.hpp"
#include "../program/program.state.hpp"
#include "zasm/core/math.hpp"
#include "zasm/encoder/encoder.hpp"

#include <Zydis/Decoder.h>
#include <cassert>

namespace zasm
{
    namespace detail
    {
        struct LabelInfo
        {
            static constexpr int32_t kUnboundOffset = -1;
            static constexpr int64_t kUnboundAddress = -1;

            Label::Id labelId{ Label::Id::Invalid };
            int32_t boundOffset{ kUnboundOffset };
            int64_t boundAddress{ kUnboundAddress };
        };

        struct SerializerState
        {
            int64_t base{};
            std::vector<SectionInfo> sections;
            std::vector<uint8_t> code;
            std::vector<RelocationInfo> relocations;
            std::vector<RelocationInfo> externalRelocations;
            std::vector<LabelInfo> labels;
        };

    } // namespace detail

    struct SerializeContext
    {
        EncoderContext& ctx;
        std::vector<uint8_t> buffer;
    };

    static bool isLabelExternal(detail::ProgramState& prog, Label::Id id)
    {
        const auto idx = static_cast<size_t>(id);
        if (idx >= prog.labels.size())
            return false;

        const auto& entry = prog.labels[idx];
        if ((entry.flags & LabelFlags::External) != LabelFlags::None)
            return true;

        return false;
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
            nodeEntry.address = ctx.va;
        }
        ctx.nodeIndex++;

        return Error::None;
    }

    static Error serializeNode(detail::ProgramState& prog, SerializeContext& state, const Instruction& instr)
    {
        auto& ctx = state.ctx;

        auto res = encode(state.ctx, prog.mode, instr);
        if (!res)
        {
            return res.error();
        }

        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            if (nodeEntry.length != 0)
            {
                if (res->length < nodeEntry.length)
                {
                    ctx.drift += nodeEntry.length - res->length;
                }
                else if (res->length > nodeEntry.length)
                {
                    ctx.drift -= res->length - nodeEntry.length;
                }
            }
            nodeEntry.length = res->length;
            nodeEntry.offset = ctx.offset;
            nodeEntry.address = ctx.va;
            nodeEntry.relocKind = res->relocKind;
            nodeEntry.relocData = res->relocData;
            nodeEntry.relocLabel = res->relocLabel;

            ctx.nodeIndex++;
        }

        auto& sect = ctx.sections[ctx.sectionIndex];
        sect.rawSize += res->length;

        ctx.va += res->length;
        ctx.offset += res->length;

        auto& buffer = state.buffer;
        buffer.insert(buffer.end(), std::begin(res->data), std::begin(res->data) + res->length);

        return Error::None;
    }

    static Error serializeNode(detail::ProgramState& prog, SerializeContext& state, const Label& label)
    {
        if (!label.isValid())
            return Error::InvalidLabel;

        auto& ctx = state.ctx;

        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            nodeEntry.length = 0;
            nodeEntry.offset = ctx.offset;
            nodeEntry.address = ctx.va;
            ctx.nodeIndex++;
        }

        const auto labelIdx = static_cast<size_t>(label.getId());
        if (labelIdx >= prog.labels.size())
        {
            return Error::LabelNotFound;
        }

        auto& linkEntry = state.ctx.getOrCreateLabelLink(label.getId());
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
            newSect.address = ctx.va;

            ctx.sections.push_back(newSect);
            ctx.sectionIndex++;
        }

        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            nodeEntry.length = 0;
            nodeEntry.offset = ctx.offset;
            nodeEntry.address = ctx.va;
            ctx.nodeIndex++;
        }

        return Error::None;
    }

    static Error serializeNode(detail::ProgramState&, SerializeContext& state, const Data& data)
    {
        auto& ctx = state.ctx;

        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(data.getData());
        const auto totalSize = data.getTotalSize();

        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            nodeEntry.offset = ctx.offset;
            nodeEntry.address = ctx.va;
            nodeEntry.length = totalSize;
            ctx.nodeIndex++;
        }

        ctx.va += totalSize;
        ctx.offset += totalSize;

        auto& sect = ctx.sections[ctx.sectionIndex];
        sect.rawSize += totalSize;

        auto& buffer = state.buffer;
        buffer.reserve(buffer.size() + totalSize);
        
        const auto dataSize = data.getSize();
        for (std::size_t i = 0; i < data.getRepeatCount(); ++i)
        {
            buffer.insert(buffer.end(), ptr, ptr + dataSize);
        }

        return Error::None;
    }

    static Error serializeNode(detail::ProgramState& program, SerializeContext& state, const EmbeddedLabel& data)
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
            if (!isLabelExternal(program, label.getId()))
            {
                ctx.needsExtraPass = true;
            }
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
        RelocationType relocKind = RelocationType::Abs;

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

        auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
        ctx.nodeIndex++;

        nodeEntry.offset = ctx.offset;
        nodeEntry.address = ctx.va;
        nodeEntry.length = byteSize;

        if (!data.isRelative())
        {
            // Needs to be relocatable if this is an absolute label.
            nodeEntry.relocKind = relocKind;
            nodeEntry.relocData = RelocationData::Data;
            nodeEntry.relocLabel = label.getId();
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
        return serialize(program, newBase, program.getHead(), program.getTail());
    }

    Error Serializer::serialize(const Program& program, int64_t newBase, const Node* first, const Node* last)
    {
        detail::ProgramState& programState = program.getState();

        const auto* lastNode = last != nullptr ? last->getNext() : nullptr;

        const auto nodeCount = [&]() -> size_t {
            // If the entire program is serialized the size is known.
            if (first == program.getHead() && last == program.getTail())
                return program.size();
            // else count nodes in range.
            size_t count = 0;
            for (auto* node = first; node != lastNode; node = node->getNext())
            {
                count++;
            }
            return count;
        }();

        EncoderContext encoderCtx{};
        encoderCtx.program = &program.getState();
        encoderCtx.nodes.resize(nodeCount);
        encoderCtx.baseVA = newBase;

        SerializeContext state{ encoderCtx, {} };

        int32_t codeDiff = 0;
        int32_t codeSize = 0;

        EncoderSection defaultSect{};
        defaultSect.index = 0;
        defaultSect.attribs = Section::Attribs::Code;
        defaultSect.address = newBase;
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

            for (const auto* node = first; node != lastNode; node = node->getNext())
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
        const auto isUnresolvedLabel = [&programState](auto&& link) {
            return !link.isBound() && !isLabelExternal(programState, link.id);
        };
        const bool hasUnresolvedLinks = std::any_of(
            std::begin(encoderCtx.labelLinks), std::end(encoderCtx.labelLinks), isUnresolvedLabel);
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
            const auto labelIdx = static_cast<size_t>(labelLink.id);
            if (labelIdx >= programState.labels.size())
            {
                return Error::InvalidLabel;
            }

            auto& labelEntry = _state->labels.emplace_back();
            labelEntry.labelId = labelLink.id;
            labelEntry.boundOffset = labelLink.boundOffset;
            labelEntry.boundAddress = labelLink.boundVA;
        }

        // Generate relocation data.
        ZydisDecoder decoder;
        ZyanStatus decoderStatus{};
        switch (program.getMode())
        {
            case MachineMode::I386:
                decoderStatus = ZydisDecoderInit(
                    &decoder, ZYDIS_MACHINE_MODE_LONG_COMPAT_32, ZydisStackWidth::ZYDIS_STACK_WIDTH_32);
                break;
            case MachineMode::AMD64:
                decoderStatus = ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZydisStackWidth::ZYDIS_STACK_WIDTH_64);
                break;
            default:
                return Error::InvalidParameter;
        }

        ZydisDecodedOperand instrOps[ZYDIS_MAX_OPERAND_COUNT];
        ZydisDecodedInstruction instr;

        _state->relocations.clear();
        for (auto& node : encoderCtx.nodes)
        {
            if (node.relocKind == RelocationType::None)
                continue;

            RelocationInfo reloc;
            reloc.kind = node.relocKind;
            reloc.label = node.relocLabel;

            bool isExternal = false;
            if (reloc.label != Label::Id::Invalid)
            {
                isExternal = isLabelExternal(programState, reloc.label);
            }

            if (node.relocData == RelocationData::Data)
            {
                reloc.offset = node.offset;
                reloc.address = node.address;
                reloc.size = toBitSize(node.length * 8);
            }
            else
            {
                const uint8_t* data = state.buffer.data() + node.offset;

                decoderStatus = ZydisDecoderDecodeFull(
                    &decoder, data, node.length, &instr, instrOps, static_cast<ZyanU8>(std::size(instrOps)), 0);

                if (node.relocData == RelocationData::Immediate)
                {
                    if (instr.raw.imm[0].is_relative)
                        continue;

                    reloc.offset = node.offset + instr.raw.imm[0].offset;
                    reloc.address = node.address + instr.raw.imm[0].offset;
                    reloc.size = toBitSize(instr.raw.imm[0].size);
                }
                else if (node.relocData == RelocationData::Memory)
                {
                    reloc.offset = node.offset + instr.raw.disp.offset;
                    reloc.address = node.address + instr.raw.disp.offset;
                    reloc.size = toBitSize(instr.raw.disp.size);
                }
            }

            if (isExternal)
            {
                // Zero out the temporary value to make it easier to spot unpatched values.
                constexpr const uint8_t temp[sizeof(uint64_t)]{};
                if (reloc.size == BitSize::_8)
                    std::memcpy(state.buffer.data() + reloc.offset, temp, sizeof(uint8_t));
                else if (reloc.size == BitSize::_16)
                    std::memcpy(state.buffer.data() + reloc.offset, temp, sizeof(uint16_t));
                else if (reloc.size == BitSize::_32)
                    std::memcpy(state.buffer.data() + reloc.offset, temp, sizeof(uint32_t));
                else if (reloc.size == BitSize::_64)
                    std::memcpy(state.buffer.data() + reloc.offset, temp, sizeof(uint64_t));

                _state->externalRelocations.push_back(reloc);
            }
            else
            {
                _state->relocations.push_back(reloc);
            }
        }

        _state->code = std::move(state.buffer);

        _state->sections.clear();
        for (auto& sectionLink : encoderCtx.sections)
        {
            const size_t idx = _state->sections.size();

            auto& sect = _state->sections.emplace_back();
            sect.name = programState.symbolNames.get(sectionLink.nameId);
            sect.attribs = sectionLink.attribs;
            sect.offset = sectionLink.offset;
            sect.physicalSize = sectionLink.rawSize;
            sect.virtualSize = sectionLink.virtualSize;
            sect.address = sectionLink.address;
            sect.index = idx;
        }

        _state->base = newBase;

        return Error::None;
    }

    Error Serializer::relocate(int64_t newBase)
    {
        if (_state->code.empty())
            return Error::EmptyState;

        const auto oldBase = _state->base;

        // Make a copy of the code buffer to avoid corrupting the
        // state in case one of the relocations fail.
        auto code = _state->code;

        auto relocs = _state->relocations;
        for (auto& reloc : relocs)
        {
            if (reloc.size == BitSize::_32)
            {
                uint32_t value{};
                std::memcpy(&value, code.data() + reloc.offset, sizeof(value));

                uint64_t newValue = value;
                newValue -= oldBase;
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
                newValue -= oldBase;
                newValue += newBase;

                value = static_cast<uint64_t>(newValue);
                std::memcpy(code.data() + reloc.offset, &value, sizeof(value));
            }

            reloc.address -= oldBase;
            reloc.address += newBase;
        }

        // Adjust external relocations.
        auto externalRelocs = _state->externalRelocations;
        for (auto& reloc : externalRelocs)
        {
            reloc.address -= oldBase;
            reloc.address += newBase;
        }

        // Adjust label addresses.
        auto labels = _state->labels;
        for (auto& label : labels)
        {
            label.boundAddress -= oldBase;
            label.boundAddress += newBase;
        }

        // Adjust sections
        auto sections = _state->sections;
        for (auto& sect : sections)
        {
            sect.address -= oldBase;
            sect.address += newBase;
        }

        // Update state.
        _state->code = std::move(code);
        _state->labels = std::move(labels);
        _state->sections = std::move(sections);
        _state->relocations = std::move(relocs);
        _state->externalRelocations = std::move(externalRelocs);
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

    size_t Serializer::getExternalRelocationCount() const noexcept
    {
        return _state->externalRelocations.size();
    }

    const zasm::RelocationInfo* Serializer::getExternalRelocation(const size_t index) const noexcept
    {
        if (index >= _state->externalRelocations.size())
            return nullptr;

        return &_state->externalRelocations[index];
    }

    void Serializer::clear()
    {
        _state->base = 0;
        _state->code.clear();
        _state->sections.clear();
        _state->labels.clear();
    }

} // namespace zasm
