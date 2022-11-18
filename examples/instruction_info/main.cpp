#include "examples.common.hpp"

#include <iostream>

static void printInstructionInfo(const zasm::Program& program, const zasm::Instruction& instr)
{
    using namespace zasm;

    std::cout << "Instruction: " << formatter::toString(&instr) << "\n";
    for (size_t i = 0; i < instr.getOperandCount(); ++i)
    {
        const Operand& op = instr.getOperand(i);

        std::cout << "  Operand[" << i << "] = {\n";

        if (auto* opMem = op.getIf<Mem>(); opMem != nullptr)
        {
            std::cout << "    Type = Mem(\n";
            std::cout << "      Segment: " << formatter::toString(opMem->getSegment()) << "\n";
            std::cout << "      Base: " << formatter::toString(opMem->getBase()) << "\n";
            std::cout << "      Index: " << formatter::toString(opMem->getIndex()) << "\n";
            std::cout << "      Scale: " << (int)opMem->getScale() << "\n";
            std::cout << "      Displacement: " << opMem->getDisplacement() << "\n";
            std::cout << "    ),\n";
        }
        else if (auto* opReg = op.getIf<Reg>(); opReg != nullptr)
        {
            std::cout << "    Type = Reg(\n";
            std::cout << "      " << formatter::toString(*opReg) << "\n";
            std::cout << "    ),\n";
        }
        else if (auto* opImm = op.getIf<Imm>(); opReg != nullptr)
        {
            std::cout << "    Imm(\n";
            std::cout << "      " << opImm->value<int64_t>() << "\n";
            std::cout << "    ),\n";
        }
        else if (auto* opLabel = op.getIf<Label>(); opLabel != nullptr)
        {
            std::cout << "    Label(\n";
            std::cout << "      " << static_cast<int32_t>(opLabel->getId()) << "\n";
            std::cout << "    ),\n";
        }

        std::cout << "    Access = ";
        const auto opAccess = instr.getOperandAccess(i);
        if (opAccess == Operand::Access::None)
            std::cout << "none\n";
        else
        {
            if ((opAccess & Operand::Access::CondRead) != Operand::Access::None)
                std::cout << "CondRead ";
            else if ((opAccess & Operand::Access::Read) != Operand::Access::None)
                std::cout << "Read ";

            if ((opAccess & Operand::Access::CondWrite) != Operand::Access::None)
                std::cout << "CondWrite ";
            else if ((opAccess & Operand::Access::Write) != Operand::Access::None)
                std::cout << "Write ";

            std::cout << "\n";
        }

        std::cout << "    Visibility = ";
        const Operand::Visibility opVis = instr.getOperandVisibility(i);
        switch (opVis)
        {
            case Operand::Visibility::Invalid:
                std::cout << "Invalid";
                break;
            case Operand::Visibility::Explicit:
                std::cout << "Explicit";
                break;
            case Operand::Visibility::Implicit:
                std::cout << "Implicit";
                break;
            case Operand::Visibility::Hidden:
                std::cout << "Hidden";
                break;
        }
        std::cout << "\n";

        std::cout << "    Size = " << getBitSize(instr.getOperand(i).getBitSize(program.getMode())) << "b\n";
        
        std::cout << "  }\n";
    }
}

int main()
{
    using namespace zasm;

    Program program(MachineMode::AMD64);

    Decoder decoder(program.getMode());

    x86::Assembler assembler(program);

    {
        assembler.call(Imm(0));
        auto& instr = assembler.getCursor()->get<Instruction>();
        printInstructionInfo(program, instr);
    }

    {
        assembler.ret();
        auto& instr = assembler.getCursor()->get<Instruction>();
        printInstructionInfo(program, instr);
    }

    {
        auto lbl = assembler.createLabel();
        assembler.jmp(lbl);
        auto& instr = assembler.getCursor()->get<Instruction>();
        printInstructionInfo(program, instr);
    }
}
