# Zasm : x86-64 Assembler based on [Zydis](https://github.com/zyantific/zydis)

## Why?
Some of my projects were using Zydis and AsmJit where instructions where were first decoded with Zydis and then put into AsmJit's Builder to allow processing/analysing of the instructions/branches before re-encoding/relocating the modified code, there are a couple of downsides to this approach which will be explained further down. Zydis recently introduced a way to use the same structures/data it already has to encode instructions which lead to Zasm. This library aims to be a higher level assembler/decoder which can be used for various things like the previously mentioned example.

A strong difference between Zasm and AsmJit is the focus on accurate instruction data such as operand access, hidden register use, correct cpu flags all of which can be either missing or wrong in AsmJit with some exceptions of course, AsmJit aims to a friendly way to generate code on the fly for lets say scripting or high performance computing. So Zasm is not trying to replace AsmJit in any way, it has a different goals.

The second reason for Zasm is that Zydis Encoder being extremly low level which means you don't have things like labels, Zasm provides a high level class for assembling instructions and provides labels like an ordinary assembler would.

## Design
Zasm is composed of three components ```Program```, ```Decoder```, ```Assembler```. While Zasm uses Zydis as the framework a lot of structures do not match that of Zydis that is primarily due to Zasm storing instructions in nodes, storing the raw ZydisDecodedInstruction would be extremly heavy on the memory usage, so in some cases I made the choice to only store what I consider relevant, storing 10'000'000 instructions currently uses about 4~ GiB memory. The instruction stores just about enough information for most analysis to work out of the box.

```Program``` is the container that holds all the data and also serves as a doubly linked list, instructions labels and data are stored as nodes which allows the user to remove/insert/re-order quite easily. This container is also responsible for generating the final output by serializing each node in one or multiple passes, it will never take more than 3 passes at most and in most cases its just two, this is driven by how labels are used, this is something that can be improved in the future.

```Decoder``` is a wrapper class for the Zydis Decoder. Decodes instructions from data.


```Assembler``` is a wrapper class that has specialized overloads for all supported instructions that adds new nodes to the ```Program``` being attached to. It also allows to directly add instructions from the ```Decoder```

## Examples
Generate a basic function for x64.
```cpp
using namespace zasm;
using namespace zasm::operands;

Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);
Assembler assembler(program);

assembler.mov(rax, Imm(0xF00B444));
assembler.ret();

// Encodes all the nodes.
program.serialize(0x00400000);

const auto codeDump = getHexDump(program.getCode(), program.getCodeSize());
std::cout << codeDump << "\n";
```

Feeding instructions from the decoder and re-encode.
```cpp
using namespace zasm;
using namespace zasm::operands;

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

Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);
Assembler assembler(program);

Decoder decoder(program.getMode());

size_t bytesDecoded = 0;

while (bytesDecoded < code.size())
{
    const auto curAddress = baseAddr + bytesDecoded;

    auto decoderRes = decoder.decode(code.data() + bytesDecoded, code.size() - bytesDecoded, curAddress);
    if (!decoderRes)
    {
        std::cout << "Failed to decode at " << std::hex << curAddress << ", " << decoderRes.error() << "\n";
        return;
    }

    const auto& instr = decoderRes.value();
    assembler.fromInstruction(instr);

    bytesDecoded += instr.getLength();
}

program.serialize(baseAddr);

const auto codeDump = getHexDump(program.getCode(), program.getCodeSize());
std::cout << codeDump << "\n";
```
