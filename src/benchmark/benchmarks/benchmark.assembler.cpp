#include <benchmark/benchmark.h>
#include <functional>
#include <testdata/instructions.hpp>
#include <zasm/zasm.hpp>

namespace zasm::benchmarks
{
    static void BM_Assembler_EmitSingle_0_Operands(benchmark::State& state)
    {
        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);
            state.ResumeTiming();

            assembler.nop();

            state.counters["Instructions"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
        }
    }
    BENCHMARK(BM_Assembler_EmitSingle_0_Operands)->Unit(benchmark::kMicrosecond);

    static void BM_Assembler_EmitSingle_1_Operands(benchmark::State& state)
    {
        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);
            state.ResumeTiming();

            assembler.push(operands::rax);

            state.counters["Instructions"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
        }
    }
    BENCHMARK(BM_Assembler_EmitSingle_1_Operands)->Unit(benchmark::kMicrosecond);

    static void BM_Assembler_EmitSingle_2_Operands(benchmark::State& state)
    {
        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);
            state.ResumeTiming();

            assembler.mov(operands::rax, operands::rax);

            state.counters["Instructions"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
        }
    }
    BENCHMARK(BM_Assembler_EmitSingle_2_Operands)->Unit(benchmark::kMicrosecond);

    static void BM_Assembler_EmitSingle_3_Operands(benchmark::State& state)
    {
        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);
            state.ResumeTiming();

            assembler.rorx(operands::rcx, operands::rdx, operands::Imm(1));

            state.counters["Instructions"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
        }
    }
    BENCHMARK(BM_Assembler_EmitSingle_3_Operands)->Unit(benchmark::kMicrosecond);

    static void BM_Assembler_EmitAll(benchmark::State& state)
    {
        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);
            state.ResumeTiming();

            for (const auto& instr : zasm::tests::data::Instructions)
            {
                instr.emitter(assembler);

            }

            state.counters["Instructions"] = benchmark::Counter(std::size(zasm::tests::data::Instructions), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
        }
    }
    BENCHMARK(BM_Assembler_EmitAll)->Unit(benchmark::kMicrosecond);

} // namespace zasm::benchmarks