#include <benchmark/benchmark.h>
#include <functional>
#include <testdata/instructions.hpp>
#include <zasm/formatter/formatter.hpp>
#include <zasm/zasm.hpp>

namespace zasm::benchmarks
{
    static void BM_Formatter_Program(benchmark::State& state)
    {
        using namespace zasm::x86;

        Program program(MachineMode::AMD64);
        Assembler assembler(program);

        // Create large enough program to contain 1~ million nodes.
        for (size_t i = 0; i < 1'000'000 / std::size(zasm::tests::data::Instructions); i++)
        {
            for (const auto& instr : zasm::tests::data::Instructions)
            {
                instr.emitter(assembler);
            }
        }

        for (auto _ : state)
        {
            auto res = formatter::toString(program);
            benchmark::DoNotOptimize(res);

            state.counters["PrintedNodes"] = benchmark::Counter(
                static_cast<double>(program.size()), benchmark::Counter::kIsIterationInvariantRate,
                benchmark::Counter::OneK::kIs1000);
        }
    }
    BENCHMARK(BM_Formatter_Program)->Unit(benchmark::kMillisecond);

} // namespace zasm::benchmarks
