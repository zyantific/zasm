#include <benchmark/benchmark.h>
#include <functional>
#include <zasm/testdata/x86/instructions.hpp>
#include <zasm/zasm.hpp>

namespace zasm::benchmarks
{
    static void BM_SerializationBasic(benchmark::State& state)
    {
        using namespace zasm::x86;

        Program program(MachineMode::AMD64);
        Assembler assembler(program);
        Serializer serializer;

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);

            // Fill in N instructions.
            zasm::Label label;

            const auto count = std::size(tests::data::Instructions);
            for (int64_t i = 0; i < count; ++i)
            {
                // NOTE: We may specify more instructions than available in the collection, wrap around.
                const auto& instr = tests::data::Instructions[i];
                instr.emitter(assembler);

                // Generate every 128 instructions a new instruction using a label.
                if (i % 128 == 0)
                {
                    if (label.isValid())
                    {
                        assembler.lea(rax, qword_ptr(label));
                    }
                    label = assembler.createLabel();
                    assembler.bind(label);
                }
            }

            state.ResumeTiming();

            serializer.serialize(program, 0x00400000);

            state.counters["BytesEncoded"] = benchmark::Counter(
                static_cast<double>(serializer.getCodeSize()), benchmark::Counter::kIsIterationInvariantRate,
                benchmark::Counter::OneK::kIs1024);
            state.counters["Instructions"] = benchmark::Counter(
                static_cast<double>(count), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
        }
    }
    BENCHMARK(BM_SerializationBasic)->Unit(benchmark::kMillisecond);

    template<int64_t TLabelStep> static void BM_SerializationWithLabels(benchmark::State& state)
    {
        using namespace zasm::x86;

        Program program(MachineMode::AMD64);
        Assembler assembler(program);
        Serializer serializer;

        size_t numBytesEncoded = 0;
        size_t numInstructions = 0;

        for (auto _ : state)
        {
            state.PauseTiming();
            program.clear();
            assembler.setCursor(nullptr);

            // Fill in N instructions.
            zasm::Label label;

            const auto count = std::size(tests::data::Instructions);
            for (int64_t i = 0; i < count; ++i)
            {
                // NOTE: We may specify more instructions than available in the collection, wrap around.
                const auto& instr = tests::data::Instructions[i];
                instr.emitter(assembler);

                // Generate every 128 instructions a new instruction using a label.
                if (i % TLabelStep == 0)
                {
                    if (label.isValid())
                    {
                        assembler.lea(rax, qword_ptr(label));
                    }
                    label = assembler.createLabel();
                    assembler.bind(label);
                }
            }

            state.ResumeTiming();

            serializer.serialize(program, 0x00400000);

            numBytesEncoded += serializer.getCodeSize();
            numInstructions += count;
        }

        state.counters["BytesEncoded"] = benchmark::Counter(
            static_cast<double>(numBytesEncoded), benchmark::Counter::kIsRate, benchmark::Counter::OneK::kIs1024);

        state.counters["Instructions"] = benchmark::Counter(
            static_cast<double>(numInstructions), benchmark::Counter::kIsRate, benchmark::Counter::OneK::kIs1000);
    }
    BENCHMARK_TEMPLATE(BM_SerializationWithLabels, 128)->Unit(benchmark::kMillisecond);

    BENCHMARK_TEMPLATE(BM_SerializationWithLabels, 64)->Unit(benchmark::kMillisecond);

    BENCHMARK_TEMPLATE(BM_SerializationWithLabels, 32)->Unit(benchmark::kMillisecond);

} // namespace zasm::benchmarks
