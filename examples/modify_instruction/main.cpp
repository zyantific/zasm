#include "examples.common.hpp"

#include <iostream>

int main()
{
    using namespace zasm;

    Program program(MachineMode::AMD64);

    x86::Assembler a(program);

    auto labelA = a.createLabel();
    auto labelB = a.createLabel();
    auto labelC = a.createLabel();

    a.mov(x86::rax, Imm(1));
    const auto* nodeInstr1 = a.getCursor();

    std::cout << "Program Before:\n" << formatter::toString(program) << "\n";
    
    // Copy the instruction, can not be modified in-place.
    Instruction instr = nodeInstr1->get<Instruction>();
    Imm& op1 = instr.getOperand<Imm>(1);
    op1.setValue(-1);

    // Request new instruction node.
    a.emit(instr);
    
    // Delete old
    program.destroy(nodeInstr1);

    std::cout << "Program After:\n" << formatter::toString(program) << "\n";
}
