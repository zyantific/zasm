#include "examples.common.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>

#if _WIN32
#    include <windows.h>
#else

#endif

static void* allocatePage(std::size_t codeSize)
{
#ifdef _WIN32
    return VirtualAlloc(0, codeSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
#else
    // TODO: mmap for Linux.
    return nullptr;
#endif
}

static void freePage(void* p)
{
#ifdef _WIN32
    VirtualFree(p, 0, MEM_RELEASE);
#else
    // TODO: munmap for Linux.
#endif
}

// Calculate the estimated code size of the Program.
static std::size_t estimateCodeSize(const zasm::Program& program)
{
    std::size_t size = 0;
    for (auto* node = program.getHead(); node != nullptr; node = node->getNext())
    {
        if (auto* nodeData = node->getIf<zasm::Data>(); nodeData != nullptr)
        {
            size += nodeData->getTotalSize();
        }
        else if (auto* nodeInstr = node->getIf<zasm::Instruction>(); nodeInstr != nullptr)
        {
            const auto& instrInfo = nodeInstr->getDetail(program.getMode());
            if (instrInfo.hasValue())
            {
                size += instrInfo->getLength();
            }
            else
            {
                std::cout << "Error: Unable to get instruction info\n";
            }
        }
        else if (auto* nodeEmbeddedLabel = node->getIf<zasm::EmbeddedLabel>(); nodeEmbeddedLabel != nullptr)
        {
            const auto bitSize = nodeEmbeddedLabel->getSize();
            if (bitSize == zasm::BitSize::_32)
                size += 4;
            if (bitSize == zasm::BitSize::_64)
                size += 8;
        }
    }
    return size;
}

// Create fastcall function to add two inputs together.
struct AddFunctionGenerator
{
#if _WIN64
#    define FASTCALL_CONV
#elif _WIN32
#    define FASTCALL_CONV __fastcall
#else
#    define FASTCALL_CONV __attribute__((fastcall))
#endif

    using FunctionType = std::uintptr_t(FASTCALL_CONV*)(std::uintptr_t a, std::uintptr_t b);

    static void generate(zasm::Label labelFunc, zasm::Program& program)
    {
        using namespace zasm;

        x86::Assembler a(program);

#if _WIN32
#    ifdef _WIN64
        const auto arg0 = x86::rcx;
        const auto arg1 = x86::rdx;
#    else
        const auto arg0 = x86::ecx;
        const auto arg1 = x86::edx;
#    endif
#else
        const auto arg0 = x86::rdi;
        const auto arg1 = x86::rsi;
#endif

        // The function.
        a.bind(labelFunc);
        a.mov(x86::rax, arg0);
        a.add(x86::rax, arg1);
        a.ret();
    }
};

int main()
{
    using namespace zasm;

    Program program(MachineMode::AMD64);

    // Generate function into program.
    auto labelFunc = program.createLabel("add");

    AddFunctionGenerator::generate(labelFunc, program);

    // Estimate the current size and allocate a page.
    const auto requiredSize = estimateCodeSize(program);

    void* pCodePage = allocatePage(requiredSize);
    if (pCodePage == nullptr)
    {
        std::cerr << "Failed to allocate page with " << requiredSize << " bytes.\n";
        return EXIT_FAILURE;
    }

    // Serialize program.
    Serializer serializer;
    if (auto err = serializer.serialize(program, reinterpret_cast<int64_t>(pCodePage)); err != zasm::ErrorCode::None)
    {
        std::cout << "Serialization failure: " << err.getErrorName() << "\n";
        return EXIT_FAILURE;
    }

    // Copy code to page.
    std::memcpy(pCodePage, serializer.getCode(), serializer.getCodeSize());

    // Get the function address.
    const auto funcAddress = serializer.getLabelAddress(labelFunc.getId());
    assert(funcAddress != -1);
    const auto adderFunc = reinterpret_cast<AddFunctionGenerator::FunctionType>(funcAddress);

    // Calling the function, doing some additions:
    {
        auto res = adderFunc(0x8000u, 0x8000u);
        assert(res == 0x8000u + 0x8000u);
    }
    {
        auto res = adderFunc(0x16000u, 0x16000u);
        assert(res == 0x16000u + 0x16000u);
    }

    // Release page
    freePage(pCodePage);
}
