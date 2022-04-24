#include <benchmark/benchmark.h>
#include <functional>
#include <testdata/instructions.hpp>
#include <zasm/zasm.hpp>

namespace zasm::benchmarks
{
    static void BM_Assembler_EmitSingle_0_Operands(benchmark::State& state)
    {
        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            state.ResumeTiming();

            Assembler assembler(program);
            assembler.nop();
        }
    }
    BENCHMARK(BM_Assembler_EmitSingle_0_Operands)->Unit(benchmark::kMicrosecond);

    static void BM_Assembler_EmitSingle_1_Operands(benchmark::State& state)
    {
        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            state.ResumeTiming();

            Assembler assembler(program);
            assembler.push(operands::rax);
        }
    }
    BENCHMARK(BM_Assembler_EmitSingle_1_Operands)->Unit(benchmark::kMicrosecond);

    static void BM_Assembler_EmitSingle_2_Operands(benchmark::State& state)
    {
        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            state.ResumeTiming();

            Assembler assembler(program);
            assembler.mov(operands::rax, operands::rax);
        }
    }
    BENCHMARK(BM_Assembler_EmitSingle_2_Operands)->Unit(benchmark::kMicrosecond);

    static void BM_Assembler_EmitSingle_3_Operands(benchmark::State& state)
    {
        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            state.ResumeTiming();

            Assembler assembler(program);
            assembler.rorx(operands::rcx, operands::rdx, operands::Imm(1));
        }
    }
    BENCHMARK(BM_Assembler_EmitSingle_3_Operands)->Unit(benchmark::kMicrosecond);

    static void BM_Assembler_EmitAll(benchmark::State& state)
    {
        Program program(ZYDIS_MACHINE_MODE_LONG_64);

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            state.ResumeTiming();

            Assembler assembler(program);
            for (const auto& instr : zasm::tests::data::Instructions)
            {
                instr.emitter(assembler);
            }
        }
    }
    BENCHMARK(BM_Assembler_EmitAll)->Unit(benchmark::kMicrosecond);



} // namespace zasm::benchmarks