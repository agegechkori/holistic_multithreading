#include "sum_ints.h"
#include <benchmark/benchmark.h>
#include <cstdint>
#include <thread>

namespace holistic_multithreading {
namespace {

constexpr int64_t kStartRange = 1'000;
constexpr int64_t kEndRange = 1'000'000'000;
constexpr int64_t kRangeMultiplier = 1'000;

void DoSomething() {}

static void BM_ThreadsSum(benchmark::State &state) {
  for (auto _ : state)
    holistic_multithreading::ThreadsSum(1, state.range(0));
}
// Register the function as a benchmark
BENCHMARK(BM_ThreadsSum)
    ->RangeMultiplier(kRangeMultiplier)
    ->Range(kStartRange, kEndRange)
    ->UseRealTime();

static void BM_MultithreadedSum(benchmark::State &state) {
  for (auto _ : state)
    holistic_multithreading::MultithreadedSum(1, state.range(0), 8);
}
// Register the function as a benchmark
BENCHMARK(BM_MultithreadedSum)
    ->RangeMultiplier(kRangeMultiplier)
    ->Range(kStartRange, kEndRange)
    ->UseRealTime();

static void BM_SingleThreadSum(benchmark::State &state) {
  for (auto _ : state)
    holistic_multithreading::SingleThreadSum(1, state.range(0));
}
// Register the function as a benchmark
BENCHMARK(BM_SingleThreadSum)
    ->RangeMultiplier(kRangeMultiplier)
    ->Range(kStartRange, kEndRange)
    ->UseRealTime();

static void BM_ThreadCreation(benchmark::State &state) {
  for (auto _ : state) {
    std::thread t(DoSomething);
    t.join();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_ThreadCreation)->UseRealTime();

} // namespace
} // namespace holistic_multithreading

BENCHMARK_MAIN();
