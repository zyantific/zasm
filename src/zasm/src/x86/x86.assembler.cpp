#include <algorithm>
#include <chrono>
#include <zasm/program/program.hpp>
#include <zasm/x86/assembler.hpp>

namespace zasm::x86
{
    Assembler::Assembler(Program& program)
        : _program(program)
    {
        _program.addObserver(*this);
    }

    Assembler::~Assembler()
    {
        _program.removeObserver(*this);
    }

    void Assembler::setCursor(Node* pos) noexcept
    {
        _cursor = pos;
    }

    Node* Assembler::getCursor() const noexcept
    {
        return _cursor;
    }

    Label Assembler::createLabel(const char* name /*= nullptr*/)
    {
        return _program.createLabel(name);
    }

    Label Assembler::getOrCreateImportLabel(const char* moduleName, const char* entryName)
    {
        return _program.getOrCreateImportLabel(moduleName, entryName);
    }

    Error Assembler::bind(const Label& label)
    {
        const auto labelNode = _program.bindLabel(label);
        if (!labelNode)
        {
            return labelNode.error();
        }

        _cursor = _program.insertAfter(_cursor, labelNode.value());

        return ErrorCode::None;
    }

    Error Assembler::section(
        const char* name, Section::Attribs attribs /*= Section::Attribs::Code*/, std::int32_t align /*= 0x1000*/)
    {
        const auto newSect = _program.createSection(name, attribs, align);

        const auto sectNode = _program.bindSection(newSect);
        if (!sectNode.hasValue())
        {
            return sectNode.error();
        }

        _cursor = _program.insertAfter(_cursor, sectNode.value());

        return ErrorCode::None;
    }

    Error Assembler::db(std::uint8_t val, std::size_t repeatCount /*= 1*/)
    {
        Data data(val, repeatCount);

        auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return ErrorCode::None;
    }

    Error Assembler::dw(std::uint16_t val, std::size_t repeatCount /*= 1*/)
    {
        Data data(val, repeatCount);

        auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return ErrorCode::None;
    }

    Error Assembler::dd(std::uint32_t val, std::size_t repeatCount /*= 1*/)
    {
        Data data(val, repeatCount);

        auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return ErrorCode::None;
    }

    Error Assembler::dq(std::uint64_t val, std::size_t repeatCount /*= 1*/)
    {
        Data data(val, repeatCount);

        auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return ErrorCode::None;
    }

    Error Assembler::embed(const void* ptr, std::size_t len)
    {
        Data data(ptr, len);

        auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return ErrorCode::None;
    }

    Error Assembler::align(Align::Type type, std::uint32_t align)
    {
        Align data(type, align);

        auto* node = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, node);

        return ErrorCode::None;
    }

    Error Assembler::emit(Instruction::Attribs attribs, Instruction::Mnemonic mnemonic, std::size_t numOps, const Operand* ops)
    {
        auto instr = Instruction().addAttribs(attribs).setMnemonic(mnemonic);
        for (std::size_t i = 0; i < numOps; ++i)
        {
            instr.addOperand(ops[i]);
        }

        auto* node = _program.createNode(std::move(instr));
        _cursor = _program.insertAfter(_cursor, node);

        return ErrorCode::None;
    }

    Error Assembler::emit(const Instruction& instr)
    {
        const auto& ops = instr.getOperands();
        return emit(instr.getAttribs(), instr.getMnemonic(), instr.getOperandCount(), ops.data());
    }

    Error Assembler::embedLabel(Label label)
    {
        BitSize size = BitSize::_0;
        if (_program.getMode() == MachineMode::AMD64)
        {
            size = BitSize::_64;
        }
        else if (_program.getMode() == MachineMode::I386)
        {
            size = BitSize::_32;
        }
        else
        {
            return ErrorCode::InvalidMode;
        }

        auto* node = _program.createNode(EmbeddedLabel(label, size));
        _cursor = _program.insertAfter(_cursor, node);

        return ErrorCode::None;
    }

    Error Assembler::embedLabelRel(Label label, Label relativeTo, BitSize size)
    {
        auto* node = _program.createNode(EmbeddedLabel(label, relativeTo, size));
        _cursor = _program.insertAfter(_cursor, node);

        return ErrorCode::None;
    }

    void Assembler::onNodeDetach(Node* node) noexcept
    {
        if (node != _cursor)
        {
            return;
        }
        _cursor = node->getPrev();
    }

    void Assembler::onNodeDestroy(Node* node) noexcept
    {
        if (node != _cursor)
        {
            return;
        }
        _cursor = node->getPrev();
    }

} // namespace zasm::x86
