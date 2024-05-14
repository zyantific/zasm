#include <benchmark/benchmark.h>
#include <functional>
#include <zasm/testdata/x86/instructions.hpp>
#include <zasm/zasm.hpp>

namespace zasm::benchmarks
{
    static void BM_Assembler_EmitSingle_0_Operands(benchmark::State& state)
    {
        using namespace zasm::x86;

        Program program(MachineMode::AMD64);
        Assembler assembler(program);

        size_t numInstructions = 0;
        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);
            state.ResumeTiming();

            assembler.nop();

            numInstructions++;
        }

        state.counters["Instructions"] = benchmark::Counter(
            static_cast<double>(numInstructions), benchmark::Counter::kIsRate, benchmark::Counter::OneK::kIs1000);
    }
    BENCHMARK(BM_Assembler_EmitSingle_0_Operands)->Unit(benchmark::kMicrosecond);

    static void BM_Assembler_EmitSingle_1_Operands(benchmark::State& state)
    {
        using namespace zasm::x86;

        Program program(MachineMode::AMD64);
        Assembler assembler(program);

        size_t numInstructions = 0;
        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);
            state.ResumeTiming();

            assembler.push(rax);

            numInstructions++;
        }

        state.counters["Instructions"] = benchmark::Counter(
            static_cast<double>(numInstructions), benchmark::Counter::kIsRate, benchmark::Counter::OneK::kIs1000);
    }
    BENCHMARK(BM_Assembler_EmitSingle_1_Operands)->Unit(benchmark::kMicrosecond);

    static void BM_Assembler_EmitSingle_2_Operands(benchmark::State& state)
    {
        using namespace zasm::x86;

        Program program(MachineMode::AMD64);
        Assembler assembler(program);

        size_t numInstructions = 0;
        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);
            state.ResumeTiming();

            assembler.mov(rax, rax);

            numInstructions++;
        }

        state.counters["Instructions"] = benchmark::Counter(
            static_cast<double>(numInstructions), benchmark::Counter::kIsRate, benchmark::Counter::OneK::kIs1000);
    }
    BENCHMARK(BM_Assembler_EmitSingle_2_Operands)->Unit(benchmark::kMicrosecond);

    static void BM_Assembler_EmitSingle_3_Operands(benchmark::State& state)
    {
        using namespace zasm::x86;

        Program program(MachineMode::AMD64);
        Assembler assembler(program);

        size_t numInstructions = 0;
        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);
            state.ResumeTiming();

            assembler.rorx(rcx, rdx, Imm(1));

            numInstructions++;
        }

        state.counters["Instructions"] = benchmark::Counter(
            static_cast<double>(numInstructions), benchmark::Counter::kIsRate, benchmark::Counter::OneK::kIs1000);
    }
    BENCHMARK(BM_Assembler_EmitSingle_3_Operands)->Unit(benchmark::kMicrosecond);

    static void BM_Assembler_EmitAll(benchmark::State& state)
    {
        using namespace zasm::x86;

        Program program(MachineMode::AMD64);
        Assembler assembler(program);

        size_t numInstructions = 0;
        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);
            state.ResumeTiming();

            for (const auto& instr : zasm::tests::data::Instructions)
            {
                instr.emitter(assembler);
                numInstructions++;
            }
        }

        state.counters["Instructions"] = benchmark::Counter(
            static_cast<double>(numInstructions), benchmark::Counter::kIsRate, benchmark::Counter::OneK::kIs1000);
    }
    BENCHMARK(BM_Assembler_EmitAll)->Unit(benchmark::kMillisecond);

} // namespace zasm::benchmarks
