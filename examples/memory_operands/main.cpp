#include "examples.common.hpp"

#include <iostream>

int main()
{
    using namespace zasm;

    Program program(MachineMode::AMD64);

    x86::Assembler a(program);

    auto labelTest = a.createLabel();

    a.mov(x86::eax, x86::dword_ptr(x86::edx));

    a.mov(x86::eax, x86::dword_ptr(x86::edx, 0xC));

    a.mov(x86::eax, x86::dword_ptr(x86::ecx, x86::edx));

    a.mov(x86::eax, x86::dword_ptr(x86::ecx, x86::edx, 2, 0xC));

    a.mov(x86::eax, x86::dword_ptr(labelTest));

    a.mov(x86::eax, x86::dword_ptr(labelTest, 0xC));

    a.mov(x86::eax, x86::dword_ptr(x86::rip, labelTest));

    a.mov(x86::eax, x86::dword_ptr(x86::rip, labelTest, 0xC));

    a.mov(x86::eax, x86::dword_ptr(0x123456));

    a.mov(x86::eax, x86::dword_ptr(x86::ds, x86::edx, 0xC));

    a.mov(x86::eax, x86::dword_ptr(x86::ds, x86::edx, 0xC));

    a.mov(x86::eax, x86::dword_ptr(x86::ds, x86::edx, x86::ecx));

    a.mov(x86::eax, x86::dword_ptr(x86::ds, x86::edx, x86::ecx, 2, 0xC));

    a.mov(x86::eax, x86::dword_ptr(x86::ds, labelTest, 0xC));

    a.mov(x86::eax, x86::dword_ptr(x86::ds, x86::rip, labelTest));

    a.mov(x86::eax, x86::dword_ptr(x86::ds, x86::rip, labelTest, 0xC));

    a.mov(x86::eax, x86::dword_ptr(x86::fs, 0));

    a.bind(labelTest);

    Serializer serializer{};

    auto res = serializer.serialize(program, 0x00400000);
    assert(res == ErrorCode::None);

    std::cout << examples::utils::getDisassemblyDump(serializer, program.getMode()) << "\n";
}
