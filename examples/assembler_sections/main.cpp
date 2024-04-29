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

    a.section(".text");
    {
        a.lea(x86::rax, x86::qword_ptr(labelA));
        a.lea(x86::rbx, x86::qword_ptr(labelB));
        a.lea(x86::rdx, x86::qword_ptr(labelC));
    }

    a.section(".data", Section::Attribs::Data);
    {
        a.bind(labelA);
        a.dq(0x123456789);
        a.bind(labelB);
        a.dq(0x987654321);
        a.bind(labelC);
        a.dq(0xABCDEF123);
    }

    Serializer serializer{};

    auto res = serializer.serialize(program, 0x00400000);
    assert(res == ErrorCode::None);

    std::cout << examples::utils::getDisassemblyDump(serializer, program.getMode()) << "\n";
}
