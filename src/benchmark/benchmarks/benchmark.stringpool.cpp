#include <benchmark/benchmark.h>
#include <zasm/core/stringpool.hpp>

namespace zasm::benchmarks
{
    static const std::string TestStrings[] = { "hello", "world", "longer string", "even longer string",
                                               "even longer longer string" };

    static void BM_StringPool_Aquire(benchmark::State& state)
    {
        StringPool pool;
        for (auto _ : state)
        {
            const auto& str = TestStrings[state.range(0)];

            auto stringId = pool.aquire(str);
            benchmark::DoNotOptimize(stringId);
        }
    }
    BENCHMARK(BM_StringPool_Aquire)->DenseRange(0, std::size(TestStrings) - 1);

    static void BM_StringPool_Release(benchmark::State& state)
    {
        StringPool pool;
        for (auto _ : state)
        {
            state.PauseTiming();
            const auto& str = TestStrings[state.range(0)];

            auto stringId = pool.aquire(str);
            state.ResumeTiming();

            auto refCount = pool.release(stringId);
            benchmark::DoNotOptimize(refCount);
        }
    }
    BENCHMARK(BM_StringPool_Release)->DenseRange(0, std::size(TestStrings) - 1);

    static void BM_StringPool_Get(benchmark::State& state)
    {
        StringPool pool;
        for (auto _ : state)
        {
            state.PauseTiming();
            const auto& str = TestStrings[state.range(0)];

            auto stringId = pool.aquire(str);
            state.ResumeTiming();

            const char* res = pool.get(stringId);
            benchmark::DoNotOptimize(res);
        }
    }
    BENCHMARK(BM_StringPool_Get)->DenseRange(0, std::size(TestStrings) - 1);

    static void BM_StringPool_GetLength(benchmark::State& state)
    {
        StringPool pool;
        for (auto _ : state)
        {
            state.PauseTiming();
            const auto& str = TestStrings[state.range(0)];

            auto stringId = pool.aquire(str);
            state.ResumeTiming();

            auto strLen = pool.getLength(stringId);
            benchmark::DoNotOptimize(strLen);
        }
    }
    BENCHMARK(BM_StringPool_GetLength)->DenseRange(0, std::size(TestStrings) - 1);

} // namespace zasm::benchmarks
