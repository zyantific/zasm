#include "../encoder/generator.hpp"

#include <zasm/program/program.hpp>
#include <zasm/x86/assembler.hpp>

namespace zasm::x86
{
    Assembler::Assembler(Program& program)
        : _program(program)
        , _generator(new InstrGenerator(program.getMode()))
    {
        _program.addObserver(*this);
    }

    Assembler::~Assembler()
    {
        _program.removeObserver(*this);
        delete _generator;
    }

    void Assembler::setCursor(const Node* pos)
    {
        _cursor = pos;
    }

    const Node* Assembler::getCursor() const
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
        auto labelNode = _program.bindLabel(label);
        if (!labelNode)
        {
            return labelNode.error();
        }

        _cursor = _program.insertAfter(_cursor, labelNode.value());

        return Error::None;
    }

    Error Assembler::section(
        const char* name, Section::Attribs attribs /*= Section::Attribs::Code*/, std::int32_t align /*= 0x1000*/)
    {
        auto newSect = _program.createSection(name, attribs, align);

        auto sectNode = _program.bindSection(newSect);
        if (!sectNode.hasValue())
        {
            return sectNode.error();
        }

        _cursor = _program.insertAfter(_cursor, sectNode.value());

        return Error::None;
    }

    Error Assembler::db(std::uint8_t val, std::size_t repeatCount /*= 1*/)
    {
        Data data(val, repeatCount);

        auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return Error::None;
    }

    Error Assembler::dw(std::uint16_t val, std::size_t repeatCount /*= 1*/)
    {
        Data data(val, repeatCount);

        auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return Error::None;
    }

    Error Assembler::dd(std::uint32_t val, std::size_t repeatCount /*= 1*/)
    {
        Data data(val, repeatCount);

        auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return Error::None;
    }

    Error Assembler::dq(std::uint64_t val, std::size_t repeatCount /*= 1*/)
    {
        Data data(val, repeatCount);

        auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return Error::None;
    }

    Error Assembler::embed(const void* ptr, std::size_t len)
    {
        Data data(ptr, len);

        auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return Error::None;
    }

    Error Assembler::emit(
        Attribs attribs, Mnemonic id, std::size_t numOps, std::array<Operand, ZYDIS_ENCODER_MAX_OPERANDS>&& ops)
    {
        auto genResult = _generator->generate(
            static_cast<Instruction::Attribs>(attribs), static_cast<Instruction::Mnemonic>(id), numOps, std::move(ops));
        if (!genResult)
        {
            return genResult.error();
        }

        auto* instrNode = _program.createNode(std::move(*genResult));
        _cursor = _program.insertAfter(_cursor, instrNode);

        return Error::None;
    }

    Error Assembler::emit(const Instruction& instr)
    {
        std::array<Operand, ZYDIS_ENCODER_MAX_OPERANDS> ops;

        const auto numOps = std::min<std::size_t>(ZYDIS_ENCODER_MAX_OPERANDS, instr.getOperandCount());
        for (size_t i = 0; i < numOps; i++)
        {
            ops[i] = instr.getOperand(i);
        }

        return emit(
            static_cast<x86::Attribs>(instr.getAttribs()), static_cast<x86::Mnemonic>(instr.getMnemonic()), numOps,
            std::move(ops));
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
            return Error::InvalidMode;
        }

        auto* node = _program.createNode(EmbeddedLabel(label, size));
        _cursor = _program.insertAfter(_cursor, node);

        return Error::None;
    }

    Error Assembler::embedLabelRel(Label label, Label relativeTo, BitSize size)
    {
        auto* node = _program.createNode(EmbeddedLabel(label, relativeTo, size));
        _cursor = _program.insertAfter(_cursor, node);

        return Error::None;
    }

    void Assembler::onNodeDetach(const Node* node)
    {
        if (node != _cursor)
            return;

        _cursor = node->getPrev();
    }

    void Assembler::onNodeDestroy(const Node* node)
    {
        if (node != _cursor)
            return;

        _cursor = node->getPrev();
    }

} // namespace zasm::x86
