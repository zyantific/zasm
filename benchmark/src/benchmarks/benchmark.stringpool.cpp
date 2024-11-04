#include <benchmark/benchmark.h>
#include <random>
#include <zasm/core/stringpool.hpp>

namespace zasm::benchmarks
{
    static constexpr auto kTestSize = 500'000;
    static constexpr const char kChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    static const std::vector<std::string> kInputStrings = []() {
        std::vector<std::string> strings;

        std::mt19937 prng(42);
        for (int i = 0; i < kTestSize; ++i)
        {
            std::string str;
            for (size_t i = 0; i < 4 + (prng() % 24); ++i)
            {
                str.push_back(kChars[prng() % (sizeof(kChars) - 1)]);
            }
            strings.push_back(std::move(str));
        }
        return strings;
    }();

    static void BM_StringPool_Aquire(benchmark::State& state)
    {
        StringPool pool;
        for (auto _ : state)
        {
            for (auto i = 0; i < state.range(0); ++i)
            {
                const auto& str = kInputStrings[i];

                auto stringId = pool.aquire(str);
                benchmark::DoNotOptimize(stringId);
            }
        }
    }
    BENCHMARK(BM_StringPool_Aquire)->Range(0, kTestSize)->Unit(benchmark::kMillisecond);

    static void BM_StringPool_Release(benchmark::State& state)
    {
        StringPool pool;
        for (auto _ : state)
        {
            for (auto i = 0; i < state.range(0); ++i)
            {
                state.PauseTiming();
                const auto& str = kInputStrings[i];

                auto stringId = pool.aquire(str);
                state.ResumeTiming();

                auto refCount = pool.release(stringId);
                benchmark::DoNotOptimize(refCount);
            }
        }
    }
    BENCHMARK(BM_StringPool_Release)->Range(0, kTestSize)->Unit(benchmark::kMillisecond);

    static void BM_StringPool_Get(benchmark::State& state)
    {
        StringPool pool;
        for (auto _ : state)
        {
            for (auto i = 0; i < state.range(0); ++i)
            {
                state.PauseTiming();
                const auto& str = kInputStrings[i];

                auto stringId = pool.aquire(str);
                state.ResumeTiming();

                const char* res = pool.get(stringId);
                benchmark::DoNotOptimize(res);
            }
        }
    }
    BENCHMARK(BM_StringPool_Get)->Range(0, kTestSize)->Unit(benchmark::kMillisecond);

    static void BM_StringPool_GetLength(benchmark::State& state)
    {
        StringPool pool;
        for (auto _ : state)
        {
            for (auto i = 0; i < state.range(0); ++i)
            {
                state.PauseTiming();
                const auto& str = kInputStrings[i];

                auto stringId = pool.aquire(str);
                state.ResumeTiming();

                auto strLen = pool.getLength(stringId);
                benchmark::DoNotOptimize(strLen);
            }
        }
    }
    BENCHMARK(BM_StringPool_GetLength)->Range(0, kTestSize)->Unit(benchmark::kMillisecond);

} // namespace zasm::benchmarks
