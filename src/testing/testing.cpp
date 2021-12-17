#include <chrono>
#include <iostream>
#include <zasm/assembler.hpp>
#include <zasm/decoder.hpp>
#include <zasm/program.hpp>

static std::string hexDump(const uint8_t* buf, size_t len)
{
    std::string res;
    for (size_t i = 0; i < len; i++)
    {
        char temp[3]{};
        sprintf_s(temp, "%02X", buf[i]);
        if (!res.empty())
            res += " ";
        res += temp;
    }
    return res;
}

static void measureSerializePerformance()
{
    using namespace zasm;

    // Program contains all the nodes and labels.
    Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);

    // Emitter
    Assembler a(program);

    // Append to end, this is the default when instancing Assembler.
    a.setCursor(program.getTail());

    constexpr auto kNumInstrGenerations = 1;
    constexpr auto kNumInstructions = 14;
    constexpr auto kSerializationIterations = 1'000'000;

    {
        using namespace operands;
        for (int i = 0; i < kNumInstrGenerations; i++)
        {
            // Label names are optional.
            auto label1 = a.createLabel("testLabel1");
            auto label2 = a.createLabel("testLabel2");
            auto labelInt3 = a.createLabel("int3");

            a.mov(rax, rcx);
            a.xor_(rax, Imm(1));
            a.jz(label1);
            a.xor_(rcx, Imm(1));
            a.jmp(label2);
            // Reference label as absolute address.
            a.mov(rax, labelInt3);
            a.bind(label1);
            a.nop();
            a.nop();
            a.nop();
            a.bind(labelInt3);
            a.int3();
            a.nop();
            a.mov(rax, Imm(0xF00));
            a.bind(label2);
            a.nop();
            a.mov(rax, Imm(0xBAD));
        }

        // Embedding data.
        a.db(0x1C);
        a.dw(0xF031);
        a.dd(0xDEADBEEF);
        a.dq(0xBADC0FEB4B3F000ULL);
        const auto str = "hello world string";
        a.embed(str, strlen(str) + 1);
    }

    size_t bytesWritten = 0;
    size_t numIterations = 1;

    auto tsBegin = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < kSerializationIterations; i++)
    {
        auto serializeStatus = program.serialize(0x00007FF7B7D84DB0);
        if (serializeStatus != Error::None)
        {
            std::cout << "Encoder failure: " << zasm::getErrorName(serializeStatus) << "\n";
            return;
        }

        bytesWritten += program.getCodeSize();
    }
    auto tsEnd = std::chrono::high_resolution_clock::now();

    auto elapsedCount = std::chrono::duration_cast<std::chrono::microseconds>(tsEnd - tsBegin).count();
    auto elapsedSecs = (double)elapsedCount / 1000000.0;
    auto bytesPerSec = (double)bytesWritten / elapsedSecs;
    auto numInstr = kNumInstrGenerations * kSerializationIterations * kNumInstructions;

    std::cout << std::setprecision(8) << "Wrote " << numInstr << " instructions, " << bytesWritten << " bytes in "
              << (elapsedSecs * 1000.0) << " ms, " << bytesPerSec << " bytes per sec\n";

    // auto hexBytes = hexDump(program.getCode(), program.getCodeSize());
    // std::cout << "Dump: " << hexBytes << std::endl;
}

static void quickTest()
{
    using namespace zasm;
    using namespace zasm::operands;

    // Program contains all the nodes and labels.
    Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);

    // Emitter
    Assembler a(program);

    a.vshufps(zmm1, k0, zmm1, zmm25, Imm(171));

    program.serialize(0x00007FF7B7D84DB0);
}

int main()
{
    quickTest();
    //measureSerializePerformance();

    return EXIT_SUCCESS;
}
