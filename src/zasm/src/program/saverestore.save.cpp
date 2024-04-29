#include "zasm/program/saverestore.hpp"

#include "program.node.hpp"
#include "program.state.hpp"
#include "saverestorehelper.hpp"
#include "saverestoretypes.hpp"
#include "zasm/program/program.hpp"

#include <fstream>
#include <zasm/core/filestream.hpp>

namespace zasm
{
    static Node::Id getNodeId(const Node* node)
    {
        if (node == nullptr)
            return Node::Id::Invalid;
        else
            return node->getId();
    }

    static Error saveNode_(SaveRestore& helper, const Program& program, const Sentinel& data)
    {
        helper << NodeType::Sentinel;

        return ErrorCode::None;
    }

    static Error saveNode_(SaveRestore& helper, const Program& program, const Label& data)
    {
        helper << NodeType::Label;

        helper << data.getId();

        return ErrorCode::None;
    }

    static Error saveNode_(SaveRestore& helper, const Program& program, const EmbeddedLabel& data)
    {
        helper << NodeType::EmbeddedLabel;

        helper << data.getLabel().getId();
        helper << data.getRelativeLabel().getId();
        helper << data.getSize();

        return ErrorCode::None;
    }

    static Error saveNode_(SaveRestore& helper, const Program& program, const Data& data)
    {
        helper << NodeType::Data;

        helper << static_cast<std::uint64_t>(data.getSize());
        helper << static_cast<std::uint64_t>(data.getRepeatCount());
        helper.write(data.getData(), data.getSize());

        return ErrorCode::None;
    }

    static Error saveNode_(SaveRestore& helper, const Program& program, const Section& data)
    {
        helper << NodeType::Section;

        helper << data.getId();

        return ErrorCode::None;
    }

    static Error saveNode_(SaveRestore& helper, const Program& program, const Align& data)
    {
        helper << NodeType::Align;

        helper << data.getType();
        helper << data.getAlign();

        return ErrorCode::None;
    }

    static Error saveOperand_(SaveRestore& helper, const Operand::None&)
    {
        helper << OperandType::None;

        return ErrorCode::None;
    }

    static Error saveOperand_(SaveRestore& helper, const Reg& data)
    {
        helper << OperandType::Register;

        helper << data.getId();

        return ErrorCode::None;
    }

    static Error saveOperand_(SaveRestore& helper, const Mem& data)
    {
        helper << OperandType::Memory;

        helper << data.getBitSize();
        helper << data.getSegment().getId();
        helper << data.getBase().getId();
        helper << data.getIndex().getId();
        helper << data.getScale();
        helper << data.getDisplacement();
        helper << data.getLabelId();

        return ErrorCode::None;
    }

    static Error saveOperand_(SaveRestore& helper, const Imm& data)
    {
        helper << OperandType::Immediate;

        helper << data.value<std::int64_t>();

        return ErrorCode::None;
    }

    static Error saveOperand_(SaveRestore& helper, const Label& data)
    {
        helper << OperandType::Label;

        helper << data.getId();

        return ErrorCode::None;
    }

    static Error saveOperand(SaveRestore& helper, const Operand& op)
    {
        return op.visit([&](const auto& value) { return saveOperand_(helper, value); });
    }

    static Error saveNode_(SaveRestore& helper, const Program& program, const Instruction& data)
    {
        helper << NodeType::Instruction;
        helper << data.getMnemonic().value();
        helper << data.getAttribs().value();

        helper << static_cast<std::uint8_t>(data.getOperandCount());
        for (std::size_t i = 0; i < data.getOperandCount(); ++i)
        {
            const auto& op = data.getOperand(i);
            if (auto err = saveOperand(helper, op); err != ErrorCode::None)
            {
                return err;
            }
        }

        return ErrorCode::None;
    }

    static Error saveNode(SaveRestore& helper, const Program& program, const Node* node)
    {
        const auto* nodeInt = detail::toInternal(node);

        helper << node->getId();
        helper << nodeInt->getUserDataU64();

        auto err = nodeInt->visit([&](const auto& nodeData) { return saveNode_(helper, program, nodeData); });
        if (err != ErrorCode::None)
        {
            return err;
        }

        return ErrorCode::None;
    }

    static Error saveNodes(SaveRestore& helper, const Program& program)
    {
        std::uint64_t nodeCount = program.size();

        helper << nodeCount;

        const auto* node = program.getHead();
        while (node != nullptr)
        {
            if (auto err = saveNode(helper, program, node); err != ErrorCode::None)
            {
                return err;
            }
            node = node->getNext();
        }

        return ErrorCode::None;
    }

    static Error saveLabels(SaveRestore& helper, const Program& program)
    {
        const auto& programState = program.getState();
        const auto& labels = programState.labels;

        helper << static_cast<std::uint64_t>(labels.size());

        for (const detail::LabelData& labelData : labels)
        {
            helper << labelData.flags;
            helper << labelData.id;
            helper << labelData.moduleId;
            helper << labelData.nameId;
            helper << getNodeId(labelData.node);
        }

        return ErrorCode::None;
    }

    static Error saveSections(SaveRestore& helper, const Program& program)
    {
        const auto& programState = program.getState();
        const auto& sections = programState.sections;

        helper << static_cast<std::uint64_t>(sections.size());

        for (const detail::SectionData& sectionData : sections)
        {
            helper << sectionData.align;
            helper << sectionData.attribs;
            helper << sectionData.id;
            helper << sectionData.nameId;
            helper << getNodeId(sectionData.node);
        }

        return ErrorCode::None;
    }

    static Error saveSymbols(SaveRestore& helper, const Program& program)
    {
        auto& stream = helper.getStream();
        const auto& programState = program.getState();
        const auto& symbols = programState.symbolNames;

        if (auto err = symbols.save(stream); err != ErrorCode::None)
        {
            return err;
        }

        return ErrorCode::None;
    }

    static Error saveProgram(SaveRestore& helper, const Program& program)
    {
        // Don't variable length encode this.
        helper.write(&kZasmSignature, sizeof(kZasmSignature));

        helper << program.getMode();

        auto& programState = program.getState();
        helper << programState.nextNodeId;

        if (auto err = saveNodes(helper, program); err != ErrorCode::None)
        {
            return err;
        }

        if (auto err = saveSections(helper, program); err != ErrorCode::None)
        {
            return err;
        }

        if (auto err = saveLabels(helper, program); err != ErrorCode::None)
        {
            return err;
        }

        if (auto err = saveSymbols(helper, program); err != ErrorCode::None)
        {
            return err;
        }

        return ErrorCode::None;
    }

    Error save(const Program& program, IStream& stream)
    {
        try
        {
            SaveRestore helper(stream, false);

            if (auto err = saveProgram(helper, program); err != ErrorCode::None)
            {
                return err;
            }

            return ErrorCode::None;
        }
        catch (Error err)
        {
            return err;
        }
    }

    Error save(const Program& program, std::filesystem::path outputFilePath)
    {
        FileStream fs(outputFilePath, StreamMode::Write);
        if (!fs.isOpen())
        {
            return ErrorCode::AccessDenied;
        }

        return save(program, fs);
    }

} // namespace zasm
