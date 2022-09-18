#pragma once

#include "emitter.hpp"

#include <cstddef>
#include <memory>
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
        std::unique_ptr<InstrGenerator> _generator{};

    public:
        Assembler(Program& _program);
        ~Assembler();

        /// <summary>
        /// Sets the node at where the next node will be inserted after.
        /// </summary>
        /// <param name="pos">The position to insert the next node after</param>
        void setCursor(const Node* pos) noexcept;

        /// <summary>
        /// Returns the current node, this is typically the last node created.
        /// </summary>
        /// <returns>Position in Program</returns>
        const Node* getCursor() const noexcept;

    public:
        /// <summary>
        /// See Program::createLabel
        /// </summary>
        Label createLabel(const char* name = nullptr);

        /// <summary>
        /// See Program::getOrCreateImportLabel
        /// </summary>
        Label getOrCreateImportLabel(const char* moduleName, const char* entryName);

        /// <summary>
        /// Binds the label to a node and inserts it at the current position.
        /// </summary>
        /// <param name="label">The label to bind</param>
        /// <returns>Error</returns>
        Error bind(const Label& label);

    public:
        /// <summary>
        /// Inserts a new section at the current cursor.
        /// </summary>
        /// <param name="name">Name of the section</param>
        /// <param name="attribs">Section attributes</param>
        /// <param name="align">Section alignment</param>
        /// <returns>Error</returns>
        Error section(
            const char* name, Section::Attribs attribs = Section::kDefaultAttribs, std::int32_t align = Section::kDefaultAlign);

    public:
        // Data emitter.
        Error db(std::uint8_t val, std::size_t repeatCount = 1);
        Error dw(std::uint16_t val, std::size_t repeatCount = 1);
        Error dd(std::uint32_t val, std::size_t repeatCount = 1);
        Error dq(std::uint64_t val, std::size_t repeatCount = 1);

        /// <summary>
        /// Creates a data node which stores the binary data passed by arguments.
        /// The data will be copied and will not store the pointer.
        /// </summary>
        /// <param name="data">Pointer to the data</param>
        /// <param name="len">Size in bytes of the data</param>
        /// <returns>Error</returns>
        Error embed(const void* ptr, std::size_t len);

        // NOLINTNEXTLINE
        template<std::size_t N> Error embed(const char (&str)[N])
        {
            return embed(str, N);
        }

        // NOLINTNEXTLINE
        template<std::size_t N> Error embed(const wchar_t (&str)[N])
        {
            return embed(str, N * sizeof(wchar_t));
        }

        Error embedLabel(Label label);
        Error embedLabelRel(Label label, Label relativeTo, BitSize size);

    public:
        template<typename... TArgs> Error emit(Mnemonic mnemonic, TArgs&&... args)
        {
            const auto attribs = _attribState;
            _attribState = Attribs::None;
            return emit(attribs, mnemonic, sizeof...(TArgs), { args... });
        }

        Error emit(
            Attribs attribs, Mnemonic mnemonic, std::size_t numOps, std::array<Operand, ZYDIS_ENCODER_MAX_OPERANDS>&& ops);
        Error emit(const Instruction& instr);

    private:
        void addAttrib(Attribs attrib) noexcept
        {
            _attribState = _attribState | attrib;
        }

    public: // Attribs/State modifier.
        Assembler& o8() noexcept
        {
            addAttrib(Attribs::OperandSize8);
            return *this;
        }

        Assembler& o16() noexcept
        {
            addAttrib(Attribs::OperandSize16);
            return *this;
        }

        Assembler& o32() noexcept
        {
            addAttrib(Attribs::OperandSize32);
            return *this;
        }

        Assembler& o64() noexcept
        {
            addAttrib(Attribs::OperandSize64);
            return *this;
        }

        Assembler& lock() noexcept
        {
            addAttrib(Attribs::Lock);
            return *this;
        }

    private:
        /// <summary>
        /// Observer events, this ensures the cursor remains valid.
        /// </summary>
        /// <param name="node"></param>
        void onNodeDetach(const Node* node) noexcept override;
        void onNodeDestroy(const Node* node) noexcept override;
    };

} // namespace zasm::x86
