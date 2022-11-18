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

    a.mov(x86::rax, Imm(2));
    const auto* nodeInstr2 = a.getCursor();

    a.mov(x86::rax, Imm(3));
    const auto* nodeInstr3 = a.getCursor();

    a.mov(x86::rax, Imm(4));
    const auto* nodeInstr4 = a.getCursor();

    a.mov(x86::rax, Imm(5));
    const auto* nodeInstr5 = a.getCursor();

    a.mov(x86::rax, Imm(6));
    const auto* nodeInstr6 = a.getCursor();

    a.mov(x86::rax, Imm(7));
    const auto* nodeInstr7 = a.getCursor();

    std::cout << "Program Before:\n" << formatter::toString(program) << "\n";
    
    // Delete the node, also means unlinking from the Program.
    program.destroy(nodeInstr1);

    // Move nodeInstr7 to the start
    program.detach(nodeInstr7);
    program.insertBefore(nodeInstr2, nodeInstr7);

    std::cout << "Program After:\n" << formatter::toString(program) << "\n";
}
