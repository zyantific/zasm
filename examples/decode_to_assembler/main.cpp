#include "examples.common.hpp"

#include <iostream>

int main()
{
    using namespace zasm;

    const uint64_t baseAddr = 0x00007FF6BC738ED4;
    const std::array<uint8_t, 24> code = {
        0x40, 0x53,             // push rbx
        0x45, 0x8B, 0x18,       // mov r11d, dword ptr ds:[r8]
        0x48, 0x8B, 0xDA,       // mov rbx, rdx
        0x41, 0x83, 0xE3, 0xF8, // and r11d, 0xFFFFFFF8
        0x4C, 0x8B, 0xC9,       // mov r9, rcx
        0x41, 0xF6, 0x00, 0x04, // test byte ptr ds:[r8], 0x4
        0x4C, 0x8B, 0xD1,       // mov r10, rcx
        0x74, 0x13,             // je 0x00007FF6BC738EFF
    };

    Program program(MachineMode::AMD64);

    Decoder decoder(program.getMode());

    x86::Assembler assembler(program);

    size_t bytesDecoded = 0;

    while (bytesDecoded < code.size())
    {
        const auto curAddress = baseAddr + bytesDecoded;

        const auto decoderRes = decoder.decode(code.data() + bytesDecoded, code.size() - bytesDecoded, curAddress);
        if (!decoderRes)
        {
            std::cout << "Failed to decode at " << std::hex << curAddress << ", " << decoderRes.error().getErrorName() << "\n";
            return EXIT_FAILURE;
        }

        const auto& instrInfo = *decoderRes;
        
        const auto instr = instrInfo.getInstruction();
        if (auto res = assembler.emit(instr); res != zasm::ErrorCode::None)
        {
            std::cout << "Failed to emit instruction " << std::hex << curAddress << ", " << res.getErrorName() << "\n";
        }

        bytesDecoded += instrInfo.getLength();
    }

    Serializer serializer;
    serializer.serialize(program, baseAddr);

    const auto codeDump = examples::utils::getDisassemblyDump(serializer, program.getMode());
    std::cout << codeDump << "\n";
}
