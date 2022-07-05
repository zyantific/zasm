#include "../encoder/generator.hpp"

#include <zasm/program/program.hpp>
#include <zasm/x86/assembler.hpp>

namespace zasm::x86
{
    Assembler::Assembler(Program& program)
        : _program(program)
        , _generator(new InstrGenerator(program.getMode()))
    {
    }

    Assembler::~Assembler()
    {
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
        const char* name, Section::Attribs attribs /*= Section::Attribs::Code*/, int32_t align /*= 0x1000*/)
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

    Error Assembler::db(uint8_t val)
    {
        return embed(&val, sizeof(val));
    }

    Error Assembler::dw(uint16_t val)
    {
        return embed(&val, sizeof(val));
    }

    Error Assembler::dd(uint32_t val)
    {
        return embed(&val, sizeof(val));
    }

    Error Assembler::dq(uint64_t val)
    {
        return embed(&val, sizeof(val));
    }

    Error Assembler::embed(const void* ptr, size_t len)
    {
        auto data = _program.createData(ptr, len);

        auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return Error::None;
    }

    Error Assembler::emit_(
        Attribs attribs, Mnemonic id, size_t numOps, std::array<Operand, ZYDIS_ENCODER_MAX_OPERANDS>&& ops)
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

    Error Assembler::fromInstruction(const zasm::Instruction& instr)
    {
        auto* instrNode = _program.createNode(static_cast<const zasm::Instruction&>(instr));
        _cursor = _program.insertAfter(_cursor, instrNode);

        return Error::None;
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

} // namespace zasm::x86
