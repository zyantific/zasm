<!-- markdownlint-disable -->
## Project Status[![](./docs/img/pin.svg)](#project-status)
[![CMake](https://github.com/ZehMatt/zasm/actions/workflows/build.yml/badge.svg)](https://github.com/ZehMatt/zasm/actions/workflows/build.yml)

## Introduction[![](./docs/img/pin.svg)](#introduction)

**Zasm** provides a very flexible and lightweight library to manipulate and generate x86-64 code using Zydis as the backend. Zasm stores everything as nodes such as instructions, data, labels, sections, etc. which provides a way to easily manipulate/transform the code before serializing it into binary. The API is inspired by AsmJit so if you have used AsmJit before this should feel very familiar.

---

## Table of contents[![](./docs/img/pin.svg)](#table-of-contents)
1. [Motivation](#motivation)
2. [Building](#building)
5. [Design](#design)
   - [Program](#program)
   - [Assembler](#assembler)
   - [Serializer](#serializer)
   - [Decoder](#decoder)
6. [Examples](#examples)

---

## Motivation[![](./docs/img/pin.svg)](#motivation)

Some of my projects were using Zydis and AsmJit where instructions where were first decoded with Zydis and then put into AsmJit's Builder to allow processing/analysing of the instructions/branches before re-encoding/relocating the modified code, there are a couple of downsides to this approach which will be explained further down. Zydis recently introduced a way to use the same structures/data it already has to encode instructions which lead to Zasm. This library aims to be a higher level assembler/decoder which can be used for various things like the previously mentioned example.

A strong difference between Zasm and AsmJit is the focus on accurate instruction data such as operand access, hidden register use, correct CPU flags all of which can be either missing or wrong in AsmJit with some exceptions of course, AsmJit aims to a friendly way to generate code on the fly for lets say scripting or high performance computing. Zasm is not trying to replace AsmJit in any way, it has different goals.

The second reason for Zasm is that Zydis Encoder being extremely low level which means you don't have things like labels, Zasm provides a high level class for assembling instructions and provides labels like an ordinary assembler would.

---

## Building[![](./docs/img/pin.svg)](#building)
Zasm uses CMake in combination with [cmkr](https://github.com/build-cpp/cmkr) to simplify the the maintenance of the CMakeLists.txt. Building should be as easy as using following commands from a terminal in the root directory:
```
cmake . -B build
cmake --build build --config Release
```
If you want to also build the tests use
```
cmake . -B build -DZASM_BUILD_TESTS=ON
```
---

## Design[![](./docs/img/pin.svg)](#design)

#### Program[![](./docs/img/pin.svg)](#program)
Program is the container that holds all the data and also serves as a doubly linked list. Instructions, labels, data, sections, etc. are stored as nodes which allows the user to remove/insert/re-order quite easily.

#### Assembler[![](./docs/img/pin.svg)](#assembler)
The Assembler class provides generated member functions to generate instructions/data/labels into the Program at the specified cursor position. To emit ```mov rax, -1``` the equivalent would be ```asssembler.mov(operands::rax, operands::Imm(-1));```

#### Serializer[![](./docs/img/pin.svg)](#serializer)
The Serializer class serializes the Program nodes into binary and stores the resulting state. After a successful serialization the user can query the resulting binary code and data such as the address of labels, relocation info, section data, etc.

#### Decoder[![](./docs/img/pin.svg)](#decoder)
Decodes binary data into the Instruction object which can be either directly used or stored in the Program.

---

## Examples[![](./docs/img/pin.svg)](#examples)

<details>
  <summary>Decode binary to Program</summary>
    
```cpp
using namespace zasm;
using namespace zasm::operands;

const uint64_t address = 0x00007FF6BC738ED4;
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
Serializer serializer;

// Decode all bytes.
size_t bytesDecoded = 0;
while (bytesDecoded < code.size())
{
	const auto curAddress = address + bytesDecoded;

	// Decode next instruction.
	auto decoderRes = decoder.decode(code.data() + bytesDecoded, code.size() - bytesDecoded, curAddress);
	if (!decoderRes)
	{
		std::cout << "Failed to decode at " << std::hex << curAddress << ", " << decoderRes.error() << "\n";
		return;
	}

	// Append in Program.
	const auto& instr = decoderRes.value();
	assembler.fromInstruction(instr);

	bytesDecoded += instr.getLength();
}

// Serialize nodes.
serializer.serialize(program, address);

// Dump output.
const auto codeDump = getHexDump(serializer.getCode(), serializer.getCodeSize());
std::cout << codeDump << "\n";
```
</details>
    
<details>
  <summary>Multiple sections</summary>
    
```cpp
using namespace zasm;
using namespace zasm::operands;

Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);
Assembler a(program);
Serializer serializer;

auto labelA = a.createLabel();
auto labelB = a.createLabel();
auto labelC = a.createLabel();

// First section
a.section(".text");
{
	a.lea(rax, qword_ptr(labelA));
	a.lea(rbx, qword_ptr(labelB));
	a.lea(rdx, qword_ptr(labelC));
}

// Second section.
a.section(".data", Section::Attribs::Data);
{
	a.bind(labelA);
	a.dq(0x123456789);
	a.bind(labelB);
	a.dq(0x987654321);
	a.bind(labelC);
	a.dq(0xABCDEF123);
}

auto res = serializer.serialize(program, 0x00400000);
assert(res == Error::None);

// Iterate all sections and print the info and the section data.
for (size_t i = 0; i < serializer.getSectionCount(); ++i)
{
	const auto* sect = serializer.getSectionInfo(i);
	const auto* sectionData = serializer.getCode() + sect->offset;
	const auto sectionSize = sect->physicalSize;

	std::cout << ".section " << sect->name << ", VA: 0x" << std::hex << sect->address << 
				 ", VSize: 0x" << sect->virtualSize << 
				 ", Raw: 0x" << sect->physicalSize << "\n";

	std::cout << getHexDump(sectionData, sectionSize) << "\n";
}
```
</details>
    
<details>
  <summary>Getting the address of Labels</summary>
    
```cpp
using namespace zasm;
using namespace zasm::operands;

Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);
Assembler a(program);
Serializer serializer;

auto labelA = a.createLabel();
auto labelB = a.createLabel();

// Default section align is 0x1000

// First section
a.section(".text");
{
	a.bind(labelA);
	a.nop();
}

// Second section.
a.section(".data", Section::Attribs::Data);
{
	a.bind(labelB);
	a.nop();
}

auto res = serializer.serialize(program, 0x00400000);
assert(res == Error::None);

const auto labelAddressA = serializer.getLabelAddress(labelA.getId());
assert(labelAddressA == 0x00400000);
const auto labelOffsetA = serializer.getLabelOffset(labelA.getId());
assert(labelOffsetA == 0x0);

const auto labelAddressB = serializer.getLabelAddress(labelB.getId());
assert(labelAddressB == 0x00401000);
const auto labelOffsetB = serializer.getLabelOffset(labelB.getId());
assert(labelOffsetB == 0x1);
```
</details>
    
More examples will follow over time.
    
---

<!-- markdownlint-enable -->
