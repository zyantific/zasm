#include "zasm/assembler.hpp"

#include "generator.hpp"
#include "zasm/program.hpp"

namespace zasm
{

    Assembler::Assembler(Program& _program)
        : _program(_program)
    {
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

    Error Assembler::bind(const Label& label)
    {
        auto* labelNode = _program.bindLabel(label);

        _cursor = _program.insertAfter(_cursor, labelNode);

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

        auto* dataNode = _program.createNode(data);
        _cursor = _program.insertAfter(_cursor, dataNode);

        return Error::None;
    }

    Error Assembler::emit_(Instruction::Prefix prefixes, ZydisMnemonic id, const Instruction::Operands& ops)
    {
        auto genResult = generator(_program.getMode(), prefixes, id, ops);
        if (!genResult)
        {
            return genResult.error();
        }

        auto* instrNode = _program.createNode(*genResult);
        _cursor = _program.insertAfter(_cursor, instrNode);

        return Error::None;
    }

} // namespace zasm