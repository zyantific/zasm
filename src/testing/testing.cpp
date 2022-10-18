#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <zasm/core/packed.hpp>
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

static void testPacked()
{
    using namespace zasm;

    {
        using OperandAccessPack = Packed<uint32_t, Operand::Visibility, 3>;

        OperandAccessPack pack{};

        pack.set(0, Operand::Visibility::Explicit);
        assert(pack.get(0) == Operand::Visibility::Explicit);
        assert(pack.get(1) == Operand::Visibility::Invalid);
        assert(pack.get(2) == Operand::Visibility::Invalid);
        assert(pack.get(3) == Operand::Visibility::Invalid);
        assert(pack.get(4) == Operand::Visibility::Invalid);
        assert(pack.get(5) == Operand::Visibility::Invalid);
        assert(pack.get(6) == Operand::Visibility::Invalid);
        assert(pack.get(7) == Operand::Visibility::Invalid);
        assert(pack.get(8) == Operand::Visibility::Invalid);
        assert(pack.get(9) == Operand::Visibility::Invalid);

        pack.set(4, Operand::Visibility::Explicit);
        assert(pack.get(0) == Operand::Visibility::Explicit);
        assert(pack.get(1) == Operand::Visibility::Invalid);
        assert(pack.get(2) == Operand::Visibility::Invalid);
        assert(pack.get(3) == Operand::Visibility::Invalid);
        assert(pack.get(4) == Operand::Visibility::Explicit);
        assert(pack.get(5) == Operand::Visibility::Invalid);
        assert(pack.get(6) == Operand::Visibility::Invalid);
        assert(pack.get(7) == Operand::Visibility::Invalid);
        assert(pack.get(8) == Operand::Visibility::Invalid);
        assert(pack.get(9) == Operand::Visibility::Invalid);
    }

    {
        using RegisterPack = Packed<uint32_t, Reg::Id, 10>;

        RegisterPack pack{ x86::rax.getId(), x86::rcx.getId() };

        assert(pack.get(0) == x86::rax.getId());
        assert(pack.get(1) == x86::rcx.getId());
    }
}

static void measureSerializePerformance()
{
    using namespace zasm;

    // Program contains all the nodes and labels.
    Program program(zasm::MachineMode::AMD64);

    // Emitter
    x86::Assembler a(program);

    // Append to end, this is the default when instancing Assembler.
    a.setCursor(program.getTail());

    constexpr auto kNumInstrGenerations = 1;
    constexpr auto kNumInstructions = 14;
    constexpr auto kSerializationIterations = 1'000'000;

    {
        for (int i = 0; i < kNumInstrGenerations; i++)
        {
            // Label names are optional.
            auto label1 = a.createLabel("testLabel1");
            auto label2 = a.createLabel("testLabel2");
            auto labelInt3 = a.createLabel("int3");

            a.mov(x86::rax, x86::rcx);
            a.xor_(x86::rax, Imm(1));
            a.jz(label1);
            a.xor_(x86::rcx, Imm(1));
            a.jmp(label2);
            // Reference label as absolute address.
            a.mov(x86::rax, labelInt3);
            a.bind(label1);
            a.nop();
            a.nop();
            a.nop();
            a.bind(labelInt3);
            a.int3();
            a.nop();
            a.mov(x86::rax, Imm(0xF00));
            a.bind(label2);
            a.nop();
            a.mov(x86::rax, Imm(0xBAD));

            a.lea(x86::rsp, x86::qword_ptr(x86::rsp, 0x50));
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
    zasm::Serializer serializer;
    for (size_t i = 0; i < kSerializationIterations; i++)
    {
        auto serializeStatus = serializer.serialize(program, 0x00007FF7B7D84DB0);
        if (serializeStatus != Error::None)
        {
            std::cout << "Encoder failure: " << zasm::getErrorName(serializeStatus) << "\n";
            return;
        }

        bytesWritten += serializer.getCodeSize();
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

    // Program contains all the nodes and labels.
    Program program(MachineMode::AMD64);

    // Emitter
    x86::Assembler a(program);

    a.push(Imm(0xC11));

    Serializer serializer;
    serializer.serialize(program, 0x00007FF7B7D84DB0);

    const auto codeDump = getHexDump(serializer.getCode(), serializer.getCodeSize());
    std::cout << codeDump << "\n";
}

static void quickLeakTest()
{
    using namespace zasm;

    constexpr uint8_t ConstData[128]{};

    for (int i = 0; i < 100000; i++)
    {
        // Program contains all the nodes and labels.
        Program program(MachineMode::AMD64);

        // Emitter
        x86::Assembler a(program);

        a.push(Imm(0xC11));
        a.embed(ConstData, sizeof(ConstData));

        Serializer serializer;
        serializer.serialize(program, 0x00007FF7B7D84DB0);
    }
}

static void decodeToAssembler()
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

        auto decoderRes = decoder.decode(code.data() + bytesDecoded, code.size() - bytesDecoded, curAddress);
        if (!decoderRes)
        {
            std::cout << "Failed to decode at " << std::hex << curAddress << ", " << getErrorName(decoderRes.error()) << "\n";
            return;
        }

        const auto& instr = decoderRes.value();
        if (auto res = assembler.emit(instr); res != zasm::Error::None)
        {
            std::cout << "Failed to emit instruction " << std::hex << curAddress << ", " << getErrorName(res) << "\n";
        }
        
        bytesDecoded += instr.getLength();
    }

    Serializer serializer;
    serializer.serialize(program, baseAddr);

    const auto codeDump = getHexDump(serializer.getCode(), serializer.getCodeSize());
    std::cout << codeDump << "\n";
}

static void sectionTest()
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

    Serializer serializer;

    auto res = serializer.serialize(program, 0x00400000);
    assert(res == Error::None);

    for (size_t i = 0; i < serializer.getSectionCount(); ++i)
    {
        const auto* sect = serializer.getSectionInfo(i);

        std::cout << ".section " << sect->name << ", VA: 0x" << std::hex << sect->address << ", VSize: 0x" << sect->virtualSize
                  << ", Raw: 0x" << sect->physicalSize << "\n";

        const auto byteDump = getHexDump(serializer.getCode() + sect->offset, sect->physicalSize);
        std::cout << byteDump << "\n";
    }
}

int main()
{
    decodeToAssembler();
    testPacked();
    sectionTest();
    // quickLeakTest();
    // quickTest();
    //  measureSerializePerformance();

    return EXIT_SUCCESS;
}
