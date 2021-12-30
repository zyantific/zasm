#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <zasm/zasm.hpp>

static std::string getHexDump(const uint8_t* buf, size_t len)
{
    std::string res;
    for (size_t i = 0; i < len; i++)
    {
        char temp[3]{};
        snprintf(temp, std::size(temp), "%02X", buf[i]);
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

            a.lea(rsp, qword_ptr(rsp, 0x50));
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

    a.push(Imm(0xC11));

    program.serialize(0x00007FF7B7D84DB0);

    const auto codeDump = getHexDump(program.getCode(), program.getCodeSize());
    std::cout << codeDump << "\n";
}

static void quickLeakTest()
{
    using namespace zasm;
    using namespace zasm::operands;

    constexpr uint8_t ConstData[128]{};

    for (int i = 0; i < 100000; i++)
    {
        // Program contains all the nodes and labels.
        Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);

        // Emitter
        Assembler a(program);

        a.push(Imm(0xC11));
        a.embed(ConstData, sizeof(ConstData));

        program.serialize(0x00007FF7B7D84DB0);
    }
}

static void decodeToAssembler()
{
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
}

static void sectionTest()
{
    using namespace zasm;
    using namespace zasm::operands;

    Program program(ZydisMachineMode::ZYDIS_MACHINE_MODE_LONG_64);
    Assembler a(program);

    auto labelA = a.createLabel();
    auto labelB = a.createLabel();
    auto labelC = a.createLabel();

    a.section(".text");
    {
        a.lea(rax, qword_ptr(labelA));
        a.lea(rbx, qword_ptr(labelB));
        a.lea(rdx, qword_ptr(labelC));
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

    auto res = program.serialize(0x00400000);
    assert(res == Error::None);

    for (size_t i = 0; i < program.getSectionCount(); ++i)
    {
        const auto* sect = program.getSectionInfo(i);

        std::cout << ".section " << sect->name << ", VA: 0x" << std::hex << sect->va << ", VSize: 0x" << sect->virtualSize
                  << ", Raw: 0x" << sect->physicalSize << "\n";

        const auto byteDump = getHexDump(sect->buffer, sect->physicalSize);
        std::cout << byteDump << "\n";
    }
}

int main()
{
    sectionTest();
    // quickLeakTest();
    // decodeToAssembler();
    // quickTest();
    //  measureSerializePerformance();

    return EXIT_SUCCESS;
}
