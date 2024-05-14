#include <benchmark/benchmark.h>
#include <functional>
#include <zasm/testdata/x86/instructions.hpp>
#include <zasm/x86/meta.hpp>
#include <zasm/zasm.hpp>

namespace zasm::benchmarks
{
    static void BM_InstructionInfo(benchmark::State& state)
    {
        using namespace zasm::x86;

        Program program(MachineMode::AMD64);
        Assembler assembler(program);

        size_t numInstructions = 0;

        for (auto s : state)
        {
            const auto count = std::size(tests::data::Instructions);
            for (size_t i = 0; i < count; i++)
            {
                state.PauseTiming();

                program.clear();
                assembler.setCursor(nullptr);

                const auto& instrData = tests::data::Instructions[i];
                instrData.emitter(assembler);

                const auto& instr = assembler.getCursor()->get<Instruction>();
                state.ResumeTiming();

                const auto instrInfo = instr.getDetail(program.getMode());
                benchmark::DoNotOptimize(instrInfo);
            }

            numInstructions += count;
        }

        state.counters["InstructionInfos"] = benchmark::Counter(
            static_cast<double>(numInstructions), benchmark::Counter::kIsRate, benchmark::Counter::OneK::kIs1000);
    }
    BENCHMARK(BM_InstructionInfo)->Unit(benchmark::kMillisecond);

} // namespace zasm::benchmarks
