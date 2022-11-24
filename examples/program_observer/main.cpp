#include "examples.common.hpp"

#include <iostream>

class ProgramObserver final : public zasm::Observer
{
public:
    void onNodeCreated(const zasm::Node* node)
    {
        std::cout << "Node:" << static_cast<uint32_t>(node->getId()) << " created\n";
    }

    void onNodeDestroy(const zasm::Node* node)
    {
        std::cout << "Node:" << static_cast<uint32_t>(node->getId()) << " destroyed\n";
    }

    void onNodeDetach(const zasm::Node* node)
    {
        std::cout << "Node:" << static_cast<uint32_t>(node->getId()) << " detached\n";
    }

    void onNodeInserted(const zasm::Node* node)
    {
        std::cout << "Node:" << static_cast<uint32_t>(node->getId()) << " inserted\n";
    }
};

int main()
{
    using namespace zasm;
    
    Program program(MachineMode::AMD64);

    ProgramObserver observer;
    program.addObserver(observer);
    
    auto* nodeInstr = program.createNode(zasm::Instruction{});
    program.append(nodeInstr);

    program.destroy(nodeInstr);

    x86::Assembler assembler(program);
    assembler.mov(x86::rax, x86::rdx);

    auto testLabel = assembler.createLabel();
    assembler.bind(testLabel);

    return 0;
}
