#pragma once

#include "emitter.hpp"

#include <zasm/core/errors.hpp>
#include <zasm/program/instruction.hpp>
#include <zasm/program/observer.hpp>
#include <zasm/program/operand.hpp>
#include <zasm/program/section.hpp>
#include <zasm/x86/instruction.hpp>

namespace zasm
{
    class Program;
    class Node;
    class InstrGenerator;
} // namespace zasm

namespace zasm::x86
{
    class Assembler final : public Emitter<Assembler>, public Observer
    {
        Program& _program;
        const Node* _cursor{};
        Attribs _attribState{};
        InstrGenerator* _generator{};

    public:
        Assembler(Program& _program);
        ~Assembler();

        void setCursor(const Node* pos);
        const Node* getCursor() const;

    public:
        /// <summary>
        /// See Program::createLabel
        /// </summary>
        Label createLabel(const char* name = nullptr);

        /// <summary>
        /// See Program::getOrCreateImportLabel
        /// </summary>
        Label getOrCreateImportLabel(const char* moduleName, const char* entryName);

        Error bind(const Label& label);

    public:
        Error section(const char* name, Section::Attribs attribs = Section::Attribs::Code, int32_t align = 0x1000);

    public:
        // Data emitter.
        Error db(uint8_t val);
        Error dw(uint16_t val);
        Error dd(uint32_t val);
        Error dq(uint64_t val);
        Error embed(const void* data, size_t len);

        template<size_t N> Error embed(const char (&str)[N])
        {
            return embed(str, N);
        }

        template<size_t N> Error embed(const wchar_t (&str)[N])
        {
            return embed(str, N * sizeof(wchar_t));
        }

        Error embedLabel(Label label);
        Error embedLabelRel(Label label, Label relativeTo, BitSize size);

    public:
        template<typename... TArgs> Error emit(Mnemonic id, TArgs&&... args)
        {
            const auto attribs = _attribState;
            _attribState = Attribs::None;
            return emit_(attribs, id, sizeof...(TArgs), { args... });
        }

    private:
        Error emit_(Attribs attribs, Mnemonic id, size_t numOps, std::array<Operand, ZYDIS_ENCODER_MAX_OPERANDS>&& ops);

        void addAttrib(Attribs attrib) noexcept
        {
            _attribState = _attribState | attrib;
        }

    public: // Attribs/State modifier.
        Assembler& o8()
        {
            addAttrib(Attribs::OperandSize8);
            return *this;
        }

        Assembler& o16()
        {
            addAttrib(Attribs::OperandSize16);
            return *this;
        }

        Assembler& o32()
        {
            addAttrib(Attribs::OperandSize32);
            return *this;
        }

        Assembler& o64()
        {
            addAttrib(Attribs::OperandSize64);
            return *this;
        }

        Assembler& lock()
        {
            addAttrib(Attribs::Lock);
            return *this;
        }

    public:
        Error fromInstruction(const zasm::Instruction& instr);

    private:
        /// <summary>
        /// Observer events, this ensures the cursor remains valid.
        /// </summary>
        /// <param name="node"></param>
        void onNodeDetach(const Node* node) override;
        void onNodeDestroy(const Node* node) override;
    };


} // namespace zasm::x86
