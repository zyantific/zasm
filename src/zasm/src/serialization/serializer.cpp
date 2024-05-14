#include "zasm/serialization/serializer.hpp"

#include "../encoder/encoder.context.hpp"
#include "../program/program.state.hpp"
#include "zasm/core/math.hpp"
#include "zasm/encoder/encoder.hpp"
#include "zasm/formatter/formatter.hpp"

#include <Zydis/Decoder.h>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <functional>
#include <iterator>

namespace zasm
{
    namespace detail
    {
        struct LabelInfo
        {
            static constexpr std::int32_t kUnboundOffset = -1;
            static constexpr std::int64_t kUnboundAddress = -1;

            Label::Id labelId{ Label::Id::Invalid };
            std::int32_t boundOffset{ kUnboundOffset };
            std::int64_t boundAddress{ kUnboundAddress };
        };

        struct SerializerState
        {
            std::int64_t base{};
            std::vector<SectionInfo> sections;
            std::vector<std::uint8_t> code;
            std::vector<RelocationInfo> relocations;
            std::vector<RelocationInfo> externalRelocations;
            std::vector<LabelInfo> labels;
        };

    } // namespace detail

    struct SerializeContext
    {
        EncoderContext& ctx;
        std::vector<std::uint8_t> buffer;
    };

    static bool isLabelExternal(const detail::ProgramState& prog, Label::Id labelId) noexcept
    {
        const auto labelIdx = static_cast<std::size_t>(labelId);
        if (labelIdx >= prog.labels.size())
        {
            return false;
        }

        const auto& entry = prog.labels[labelIdx];
        return (entry.flags & LabelFlags::External) != LabelFlags::None;
    }

    static Error serializeNode(
        [[maybe_unused]] detail::ProgramState& program, SerializeContext& state, [[maybe_unused]] const Sentinel& node)
    {
        auto& ctx = state.ctx;

        auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
        nodeEntry.offset = ctx.offset;
        nodeEntry.address = ctx.va;
        ctx.nodeIndex++;

        return ErrorCode::None;
    }

    static constexpr auto kX86NopTable = std::array<std::array<std::uint8_t, 8>, 9>{ {
        {},
        { 0x90 },
        { 0x66, 0x90 },
        { 0x0f, 0x1f, 0x00 },
        { 0x0f, 0x1f, 0x40, 0x00 },
        { 0x0f, 0x1f, 0x44, 0x00, 0x00 },
        { 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00 },
        { 0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00 },
        { 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 },
    } };

    static constexpr auto kX86AlignTable = std::array<std::array<std::uint8_t, 8>, 9>{ {
        {},
        { 0xCC },
        { 0xCC, 0xCC },
        { 0xCC, 0xCC, 0xCC },
        { 0xCC, 0xCC, 0xCC, 0xCC },
        { 0xCC, 0xCC, 0xCC, 0xCC, 0xCC },
        { 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC },
        { 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC },
        { 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC },
    } };

    static Error serializeNode([[maybe_unused]] detail::ProgramState& program, SerializeContext& state, const Align& node)
    {
        auto& ctx = state.ctx;

        auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
        ctx.nodeIndex++;

        nodeEntry.offset = ctx.offset;
        nodeEntry.address = ctx.va;

        const auto& table = std::invoke([&]() {
            // TODO: Add support for different modes one day.
            if (node.getType() == Align::Type::Code)
                return kX86NopTable;
            else
                return kX86AlignTable;
        });

        const auto alignedVA = math::alignTo<std::int64_t>(ctx.va, node.getAlign());

        assert(alignedVA - ctx.va < std::numeric_limits<std::int32_t>::max());
        const auto alignSize = static_cast<std::int32_t>(alignedVA - ctx.va);

        for (auto alignBytesMissing = alignSize; alignBytesMissing > 0;)
        {
            const auto tableSize = static_cast<std::int32_t>(table.size());
            const auto dataIndex = std::min<std::int32_t>(tableSize - 1, alignBytesMissing);
            const auto& dataEntry = table[dataIndex];

            auto& buffer = state.buffer;
            buffer.insert(buffer.end(), std::begin(dataEntry), std::begin(dataEntry) + dataIndex);

            alignBytesMissing -= dataIndex;
        }

        if (nodeEntry.length != 0 && nodeEntry.length != alignSize)
        {
            ctx.needsExtraPass = true;
        }
        nodeEntry.length = alignSize;

        auto& sect = ctx.sections[ctx.sectionIndex];
        sect.rawSize += alignSize;

        ctx.va += alignSize;
        ctx.offset += alignSize;

        return ErrorCode::None;
    }

    static Error serializeNode(const detail::ProgramState& prog, SerializeContext& state, const Instruction& instr)
    {
        auto& ctx = state.ctx;

        auto res = encode(state.ctx, prog.mode, instr);
        if (!res)
        {
            return res.error();
        }

        {
            auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
            ctx.nodeIndex++;

            if (nodeEntry.length != 0 && res->buffer.length != nodeEntry.length)
            {
                ctx.needsExtraPass = true;
            }
            nodeEntry.length = res->buffer.length;
            nodeEntry.offset = ctx.offset;
            nodeEntry.address = ctx.va;
            nodeEntry.relocKind = res->relocKind;
            nodeEntry.relocData = res->relocData;
            nodeEntry.relocLabel = res->relocLabel;
        }

        auto& sect = ctx.sections[ctx.sectionIndex];
        sect.rawSize += res->buffer.length;

        ctx.va += res->buffer.length;
        ctx.offset += res->buffer.length;

        auto& buffer = state.buffer;
        buffer.insert(buffer.end(), std::begin(res->buffer.data), std::begin(res->buffer.data) + res->buffer.length);

        return ErrorCode::None;
    }

    static Error serializeNode(const detail::ProgramState& prog, SerializeContext& state, const Label& label)
    {
        if (!label.isValid())
        {
            return ErrorCode::InvalidLabel;
        }

        auto& ctx = state.ctx;

        auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
        ctx.nodeIndex++;

        nodeEntry.length = 0;
        nodeEntry.offset = ctx.offset;
        nodeEntry.address = ctx.va;

        const auto labelIdx = static_cast<std::size_t>(label.getId());
        if (labelIdx >= prog.labels.size())
        {
            return ErrorCode::LabelNotFound;
        }

        auto& linkEntry = state.ctx.getOrCreateLabelLink(label.getId());
        linkEntry.boundOffset = ctx.offset;
        linkEntry.boundVA = ctx.va;

        return ErrorCode::None;
    }

    static bool isSameSection(const EncoderSection& lhs, const EncoderSection& rhs) noexcept
    {
        return lhs.nameId == rhs.nameId && lhs.attribs == rhs.attribs && lhs.align == rhs.align;
    }

    static void finalizeCurSection(SerializeContext& state) noexcept
    {
        auto& ctx = state.ctx;

        auto& curSection = ctx.sections[ctx.sectionIndex];

        // Final virtual size.
        curSection.virtualSize = math::alignTo<std::int64_t>(curSection.rawSize, curSection.align);

        // Align current address.
        ctx.va = math::alignTo<int64_t>(ctx.va, curSection.align);
    }

    static Error serializeNode(const detail::ProgramState& prog, SerializeContext& state, const Section& section)
    {
        auto& ctx = state.ctx;

        const auto sectionIndex = static_cast<std::size_t>(section.getId());
        if (sectionIndex >= prog.sections.size())
        {
            return ErrorCode::SectionNotFound;
        }

        const auto& sectionData = prog.sections[sectionIndex];

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

        auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
        ctx.nodeIndex++;

        nodeEntry.length = 0;
        nodeEntry.offset = ctx.offset;
        nodeEntry.address = ctx.va;

        return ErrorCode::None;
    }

    static Error serializeNode([[maybe_unused]] const detail::ProgramState& program, SerializeContext& state, const Data& data)
    {
        auto& ctx = state.ctx;

        const auto* ptr = static_cast<const uint8_t*>(data.getData());
        const auto totalSize = static_cast<int32_t>(data.getTotalSize());

        auto& nodeEntry = ctx.nodes[ctx.nodeIndex];
        ctx.nodeIndex++;

        nodeEntry.offset = ctx.offset;
        nodeEntry.address = ctx.va;
        nodeEntry.length = totalSize;

        ctx.va += totalSize;
        ctx.offset += totalSize;

        auto& sect = ctx.sections[ctx.sectionIndex];
        sect.rawSize += totalSize;

        auto& buffer = state.buffer;
        buffer.reserve(buffer.size() + totalSize);

        const auto dataSize = data.getSize();
        for (std::size_t i = 0; i < data.getRepeatCount(); ++i)
        {
            std::copy_n(ptr, dataSize, std::back_inserter(buffer));
        }

        return ErrorCode::None;
    }

    static Error serializeNode(const detail::ProgramState& program, SerializeContext& state, const EmbeddedLabel& data)
    {
        auto& ctx = state.ctx;

        std::int32_t byteSize = 0;
        std::int64_t labelAddr = 0;

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

        std::array<std::uint8_t, sizeof(std::uint64_t)> tempBuf{};
        RelocationType relocKind = RelocationType::Abs;

        const auto absValue = std::abs(labelAddr);
        if (data.getSize() == BitSize::_8)
        {
            if (!ctx.needsExtraPass && absValue >= std::numeric_limits<std::uint8_t>::max())
            {
                return ErrorCode::InvalidLabel;
            }
            const auto rawValue = static_cast<std::int8_t>(labelAddr);
            std::memcpy(tempBuf.data(), &rawValue, sizeof(rawValue));
            byteSize = sizeof(rawValue);
        }
        else if (data.getSize() == BitSize::_16)
        {
            if (!ctx.needsExtraPass && absValue >= std::numeric_limits<std::uint16_t>::max())
            {
                return ErrorCode::InvalidLabel;
            }
            const auto rawValue = static_cast<std::int16_t>(labelAddr);
            std::memcpy(tempBuf.data(), &rawValue, sizeof(rawValue));
            byteSize = sizeof(rawValue);
        }
        else if (data.getSize() == BitSize::_32)
        {
            if (!ctx.needsExtraPass && absValue >= std::numeric_limits<std::uint32_t>::max())
            {
                return ErrorCode::InvalidLabel;
            }
            const auto rawValue = static_cast<std::int32_t>(labelAddr);
            std::memcpy(tempBuf.data(), &rawValue, sizeof(rawValue));
            byteSize = sizeof(rawValue);
        }
        else if (data.getSize() == BitSize::_64)
        {
            const auto rawValue = static_cast<std::int64_t>(labelAddr);
            std::memcpy(tempBuf.data(), &rawValue, sizeof(rawValue));
            byteSize = sizeof(rawValue);
        }
        else
        {
            return ErrorCode::InvalidOperation;
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
        buffer.insert(buffer.end(), std::begin(tempBuf), std::begin(tempBuf) + byteSize);

        return ErrorCode::None;
    }

    Serializer::Serializer()
        : _state(new detail::SerializerState())
    {
    }

    Serializer::Serializer(Serializer&& other) noexcept
    {
        *this = std::move(other);
    }

    Serializer::~Serializer()
    {
        delete _state;
        _state = nullptr;
    }

    Serializer& Serializer::operator=(Serializer&& other) noexcept
    {
        _state = other._state;
        other._state = nullptr;

        return *this;
    }

    Error Serializer::serialize(const Program& program, std::int64_t newBase)
    {
        return serialize(program, newBase, program.getHead(), program.getTail());
    }

    Error Serializer::serialize(const Program& program, std::int64_t newBase, const Node* first, const Node* last)
    {
        detail::ProgramState& programState = program.getState();

        const auto* lastNode = last != nullptr ? last->getNext() : nullptr;

        const auto nodeCount = [&]() noexcept -> size_t {
            // If the entire program is serialized the size is known.
            if (first == program.getHead() && last == program.getTail())
            {
                return program.size();
            }
            // else count nodes in range.
            std::size_t count = 0;
            for (const auto* node = first; node != lastNode; node = node->getNext())
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

        std::int32_t codeDiff = 0;
        std::int32_t codeSize = 0;

        EncoderSection defaultSect{};
        defaultSect.index = 0;
        defaultSect.attribs = Section::kDefaultAttribs;
        defaultSect.align = Section::kDefaultAlign;
        defaultSect.address = newBase;
        defaultSect.nameId = programState.symbolNames.aquire(".text");

        const auto serializePass = [&]() -> Error {
            state.buffer.clear();

            encoderCtx.needsExtraPass = false;
            encoderCtx.pass++;
            encoderCtx.offset = 0;
            encoderCtx.va = newBase;
            encoderCtx.nodeIndex = 0;
            encoderCtx.sectionIndex = 0;

            // Setup default section.
            encoderCtx.sections.clear();
            encoderCtx.sections.push_back(defaultSect);

            for (const auto* node = first; node != lastNode; node = node->getNext())
            {
                const auto status = node->visit([&](auto&& n) { return serializeNode(programState, state, n); });
                if (status != ErrorCode::None)
                {
                    const auto fmtOptions = formatter::Options::HexImmediates | formatter::Options::HexOffsets;
                    const auto nodeString = formatter::toString(program, node, fmtOptions);

                    char msg[256];
                    std::snprintf(
                        msg, sizeof(msg), "Error at node \"%s\" with id %u: %s", nodeString.c_str(),
                        static_cast<std::uint32_t>(node->getId()), status.getErrorMessage());

                    return Error(status.getCode(), msg);
                }
            }

            const auto newSize = static_cast<int32_t>(state.buffer.size());
            codeDiff = newSize - codeSize;
            codeSize = newSize;

            return ErrorCode::None;
        };

        // Initial.
        if (const auto status = serializePass(); status != ErrorCode::None)
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
            return ErrorCode::UnresolvedLabel;
        }

        // Second or more passes.
        while (encoderCtx.needsExtraPass)
        {
            if (const auto status = serializePass(); status != ErrorCode::None)
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
            const auto labelIdx = static_cast<std::size_t>(labelLink.id);
            if (labelIdx >= programState.labels.size())
            {
                return ErrorCode::InvalidLabel;
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
                return ErrorCode::InvalidParameter;
        }
        if (decoderStatus != ZYAN_STATUS_SUCCESS)
        {
            // FIXME: Make this a better error.
            return ErrorCode::InvalidMode;
        }

        _state->relocations.clear();
        for (auto& node : encoderCtx.nodes)
        {
            if (node.relocKind == RelocationType::None)
            {
                continue;
            }

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
                reloc.size = toBitSize(node.length * std::numeric_limits<std::uint8_t>::digits);
            }
            else
            {
                const std::uint8_t* data = state.buffer.data() + node.offset;

                ZydisDecodedInstruction instr{};

                decoderStatus = ZydisDecoderDecodeInstruction(&decoder, nullptr, data, node.length, &instr);
                if (decoderStatus != ZYAN_STATUS_SUCCESS)
                {
                    // FIXME: Properly translate the error.
                    return ErrorCode::ImpossibleRelocation;
                }

                if (node.relocData == RelocationData::Immediate)
                {
                    if (instr.raw.imm[0].is_relative == ZYAN_TRUE)
                    {
                        continue;
                    }

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
                if (reloc.size == BitSize::_8)
                {
                    std::fill_n(std::begin(state.buffer) + reloc.offset, sizeof(std::uint8_t), 0U);
                }
                else if (reloc.size == BitSize::_16)
                {
                    std::fill_n(std::begin(state.buffer) + reloc.offset, sizeof(std::uint16_t), 0U);
                }
                else if (reloc.size == BitSize::_32)
                {
                    std::fill_n(std::begin(state.buffer) + reloc.offset, sizeof(std::uint32_t), 0U);
                }
                else if (reloc.size == BitSize::_64)
                {
                    std::fill_n(std::begin(state.buffer) + reloc.offset, sizeof(std::uint64_t), 0U);
                }

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
            const auto idx = _state->sections.size();

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

        return ErrorCode::None;
    }

    Error Serializer::relocate(std::int64_t newBase)
    {
        if (_state->code.empty())
        {
            return ErrorCode::EmptyState;
        }

        const auto oldBase = _state->base;

        // Make a copy of the code buffer to avoid corrupting the
        // state in case one of the relocations fail.
        std::vector<std::uint8_t> code = _state->code;

        std::vector<RelocationInfo> relocs = _state->relocations;
        for (auto& reloc : relocs)
        {
            if (reloc.size == BitSize::_32)
            {
                std::uint32_t value{};
                std::memcpy(&value, code.data() + reloc.offset, sizeof(value));

                std::uint64_t newValue = value;
                newValue -= oldBase;
                newValue += newBase;

                if (newValue > std::numeric_limits<std::uint32_t>::max())
                {
                    return ErrorCode::ImpossibleRelocation;
                }

                value = static_cast<std::uint32_t>(newValue);
                std::memcpy(code.data() + reloc.offset, &value, sizeof(value));
            }
            else if (reloc.size == BitSize::_64)
            {
                std::uint64_t value{};
                std::memcpy(&value, code.data() + reloc.offset, sizeof(value));

                std::uint64_t newValue = value;
                newValue -= oldBase;
                newValue += newBase;

                value = static_cast<std::uint64_t>(newValue);
                std::memcpy(code.data() + reloc.offset, &value, sizeof(value));
            }

            reloc.address -= oldBase;
            reloc.address += newBase;
        }

        // Adjust external relocations.
        std::vector<RelocationInfo> externalRelocs = _state->externalRelocations;
        for (auto& reloc : externalRelocs)
        {
            reloc.address -= oldBase;
            reloc.address += newBase;
        }

        // Adjust label addresses.
        std::vector<detail::LabelInfo> labels = _state->labels;
        for (auto& label : labels)
        {
            label.boundAddress -= oldBase;
            label.boundAddress += newBase;
        }

        // Adjust sections
        std::vector<SectionInfo> sections = _state->sections;
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

        return ErrorCode::None;
    }

    std::int64_t Serializer::getBase() const noexcept
    {
        return _state->base;
    }

    std::size_t Serializer::getCodeSize() const noexcept
    {
        return _state->code.size();
    }

    const std::uint8_t* Serializer::getCode() const noexcept
    {
        if (_state->code.empty())
        {
            return nullptr;
        }
        return _state->code.data();
    }

    std::size_t Serializer::getSectionCount() const noexcept
    {
        return _state->sections.size();
    }

    const SectionInfo* Serializer::getSectionInfo(std::size_t sectionIndex) const noexcept
    {
        if (sectionIndex >= _state->sections.size())
        {
            return nullptr;
        }
        return &_state->sections[sectionIndex];
    }

    std::int32_t Serializer::getLabelOffset(const Label::Id labelId) const noexcept
    {
        const auto idx = static_cast<std::size_t>(labelId);
        if (idx >= _state->labels.size())
        {
            return -1;
        }

        assert(_state->labels[idx].labelId == labelId);

        return _state->labels[idx].boundOffset;
    }

    std::int64_t Serializer::getLabelAddress(const Label::Id labelId) const noexcept
    {
        const auto idx = static_cast<std::size_t>(labelId);
        if (idx >= _state->labels.size())
        {
            return -1;
        }

        assert(_state->labels[idx].labelId == labelId);
        return _state->labels[idx].boundAddress;
    }

    std::size_t Serializer::getRelocationCount() const noexcept
    {
        return _state->relocations.size();
    }

    const RelocationInfo* Serializer::getRelocation(const std::size_t index) const noexcept
    {
        if (index >= _state->relocations.size())
        {
            return nullptr;
        }
        return &_state->relocations[index];
    }

    std::size_t Serializer::getExternalRelocationCount() const noexcept
    {
        return _state->externalRelocations.size();
    }

    const zasm::RelocationInfo* Serializer::getExternalRelocation(const std::size_t index) const noexcept
    {
        if (index >= _state->externalRelocations.size())
        {
            return nullptr;
        }
        return &_state->externalRelocations[index];
    }

    void Serializer::clear() noexcept
    {
        _state->base = 0;
        _state->code.clear();
        _state->sections.clear();
        _state->labels.clear();
    }

} // namespace zasm
