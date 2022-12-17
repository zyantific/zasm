## Project Status
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/ZehMatt/zasm/blob/master/LICENSE)
[![CMake](https://github.com/zyantific/zasm/actions/workflows/build.yml/badge.svg)](https://github.com/ZehMatt/zasm/actions/workflows/build.yml)
[![Gitter](https://badges.gitter.im/zyantific/zyan-disassembler-engine.svg)](https://gitter.im/zyantific/zydis?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=body_badge)
[![Discord](https://img.shields.io/discord/390136917779415060.svg?logo=discord&label=Discord)](https://discord.zyantific.com/)

## Introduction

**Zasm** provides a very flexible and lightweight library to manipulate and generate x86-64 code using Zydis as the backend. Zasm stores everything as nodes such as instructions, data, labels, sections, etc. which provides a way to easily manipulate/transform the code before serializing it into binary. The API is inspired by AsmJit so if you have used AsmJit before this should feel very familiar.

---

## Table of contents
1. [Motivation](#motivation)
2. [Building](#building)
5. [Design](#design)
   - [Program](#program)
   - [Assembler](#assembler)
   - [Serializer](#serializer)
   - [Decoder](#decoder)
6. [Examples](#examples)

---

## Motivation

Some of my projects were using Zydis and AsmJit where instructions where were first decoded with Zydis and then put into AsmJit's Builder to allow processing/analysing of the instructions/branches before re-encoding/relocating the modified code, there are a couple of downsides to this approach which will be explained further down. Zydis recently introduced a way to use the same structures/data it already has to encode instructions which lead to Zasm. This library aims to be a higher level assembler/decoder which can be used for various things like the previously mentioned example.

A strong difference between Zasm and AsmJit is the focus on accurate instruction data such as operand access, hidden register use, correct CPU flags all of which can be either missing or wrong in AsmJit with some exceptions of course, AsmJit aims to a friendly way to generate code on the fly for lets say scripting or high performance computing. Zasm is not trying to replace AsmJit in any way, it has different goals.

The second reason for Zasm is that Zydis Encoder being extremely low level which means you don't have things like labels, Zasm provides a high level class for assembling instructions and provides labels like an ordinary assembler would.

---

## Building
Zasm uses CMake in combination with [cmkr](https://github.com/build-cpp/cmkr) to simplify the maintenance of the CMakeLists.txt. Building should be as easy as using following commands from a terminal in the root directory:
```
cmake . -B build
cmake --build build --config Release
```
If you want to also build the tests use
```
cmake . -B build -DZASM_BUILD_TESTS=ON
```
---

## Design

#### Program[![](./docs/img/pin.svg)](#program)
Program is the container that holds all the data and also serves as a doubly linked list. Instructions, labels, data, sections, etc. are stored as nodes which allows the user to remove/insert/re-order quite easily.

#### Assembler[![](./docs/img/pin.svg)](#assembler)
The Assembler class provides generated member functions to generate instructions/data/labels into the Program at the specified cursor position. To emit ```mov rax, -1``` the equivalent would be ```asssembler.mov(operands::rax, operands::Imm(-1));```

#### Serializer[![](./docs/img/pin.svg)](#serializer)
The Serializer class serializes the Program nodes into binary and stores the resulting state. After a successful serialization the user can query the resulting binary code and data such as the address of labels, relocation info, section data, etc.

#### Decoder[![](./docs/img/pin.svg)](#decoder)
Decodes binary data into the Instruction object which can be either directly used or stored in the Program.

---

## Examples
The project provides a few basic examples that can be found [here](https://github.com/zyantific/zasm/tree/master/examples). There are also various tests for almost everything zasm provides, if there is an something missing checkout the tests first, they provide also good examples. If you still have questions you can contact us via Discord.

---

<!-- markdownlint-enable -->
