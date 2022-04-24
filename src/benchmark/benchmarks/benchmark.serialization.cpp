#include <benchmark/benchmark.h>
#include <functional>
#include <testdata/instructions.hpp>
#include <zasm/zasm.hpp>

namespace zasm::benchmarks
{
    static void BM_Serialization(benchmark::State& state)
    {
        Program program(ZYDIS_MACHINE_MODE_LONG_64);
        Assembler assembler(program);

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);

            // Fill in N instructions.
            zasm::Label label;

            for (int64_t i = 0; i < state.range(0); ++i)
            {
                // NOTE: We may specify more instructions than available in the collection, wrap around.
                const auto& instr = tests::data::Instructions[i % std::size(tests::data::Instructions)];
                instr.emitter(assembler);

                // Generate every 128 instructions a new instruction using a label.
                if (i % 128 == 0)
                {
                    if (label.isValid())
                    {
                        assembler.lea(operands::rax, operands::qword_ptr(label));
                    }
                    label = assembler.createLabel();
                    assembler.bind(label);
                }
            }

            state.ResumeTiming();

            program.serialize(0x00400000);

            state.counters["BytesEncoded"] = benchmark::Counter(program.getCodeSize(), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1024);
            state.counters["Instructions"] = benchmark::Counter(state.range(0), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
        }
    }
    BENCHMARK(BM_Serialization)->Unit(benchmark::kMillisecond)->RangeMultiplier(2)->Range(4096, 8 << 18);

} // namespace zasm::benchmarks