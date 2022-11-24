#include "../encoder/generator.hpp"

#include <algorithm>
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
        _generator = nullptr;
    }

    void Assembler::setCursor(const Node* pos) noexcept
    {
        _cursor = pos;
    }

    const Node* Assembler::getCursor() const noexcept
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

        return Error::None;
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

        return Error::None;
    }

    Error Assembler::db(std::uint8_t val, std::size_t repeatCount /*= 1*/)
    {
        Data data(val, repeatCount);

        const auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return Error::None;
    }

    Error Assembler::dw(std::uint16_t val, std::size_t repeatCount /*= 1*/)
    {
        Data data(val, repeatCount);

        const auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return Error::None;
    }

    Error Assembler::dd(std::uint32_t val, std::size_t repeatCount /*= 1*/)
    {
        Data data(val, repeatCount);

        const auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return Error::None;
    }

    Error Assembler::dq(std::uint64_t val, std::size_t repeatCount /*= 1*/)
    {
        Data data(val, repeatCount);

        const auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return Error::None;
    }

    Error Assembler::embed(const void* ptr, std::size_t len)
    {
        Data data(ptr, len);

        const auto* dataNode = _program.createNode(std::move(data));
        _cursor = _program.insertAfter(_cursor, dataNode);

        return Error::None;
    }

    Error Assembler::emit(Attribs attribs, Mnemonic mnemonic, std::size_t numOps, const Operand* ops)
    {
        auto genResult = _generator->generate(
            static_cast<Instruction::Attribs>(attribs), static_cast<Instruction::Mnemonic>(mnemonic), numOps, ops);
        if (!genResult)
        {
            return genResult.error();
        }

        const auto* node = _program.createNode(std::move(*genResult));
        _cursor = _program.insertAfter(_cursor, node);

        return Error::None;
    }

    Error Assembler::emit(const Instruction& instr)
    {
        const auto& ops = instr.getOperands();
        const auto numOps = std::min<std::size_t>(ZYDIS_ENCODER_MAX_OPERANDS, instr.getExplicitOperandCount());

        return emit(
            static_cast<x86::Attribs>(instr.getAttribs()), static_cast<x86::Mnemonic>(instr.getMnemonic()), numOps, ops.data());
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

        const auto* node = _program.createNode(EmbeddedLabel(label, size));
        _cursor = _program.insertAfter(_cursor, node);

        return Error::None;
    }

    Error Assembler::embedLabelRel(Label label, Label relativeTo, BitSize size)
    {
        const auto* node = _program.createNode(EmbeddedLabel(label, relativeTo, size));
        _cursor = _program.insertAfter(_cursor, node);

        return Error::None;
    }

    void Assembler::onNodeDetach(const Node* node) noexcept
    {
        if (node != _cursor)
        {
            return;
        }
        _cursor = node->getPrev();
    }

    void Assembler::onNodeDestroy(const Node* node) noexcept
    {
        if (node != _cursor)
        {
            return;
        }
        _cursor = node->getPrev();
    }

} // namespace zasm::x86
