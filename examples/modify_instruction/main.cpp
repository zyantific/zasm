#include "examples.common.hpp"

#include <iostream>

int main()
{
    using namespace zasm;

    Program program(MachineMode::AMD64);

    x86::Assembler a(program);

    a.mov(x86::rax, Imm(1));
    auto* nodeInstr1 = a.getCursor();

    std::cout << "Program Before:\n" << formatter::toString(program) << "\n";
    
    // Modify the instruction.
    Instruction& instr = nodeInstr1->get<Instruction>();
    Imm& imm = instr.getOperand<Imm>(1);
    imm.setValue(-1);

    std::cout << "Program After:\n" << formatter::toString(program) << "\n";
}
