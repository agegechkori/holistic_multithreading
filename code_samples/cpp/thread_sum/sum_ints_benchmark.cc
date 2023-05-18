#include "sum_ints.h"
#include <benchmark/benchmark.h>
#include <thread>

void DoSomething() {}

static void BM_ThreadsSum(benchmark::State &state) {
  for (auto _ : state)
    holistic_multithreading::ThreadsSum(1, 1000000000);
}
// Register the function as a benchmark
BENCHMARK(BM_ThreadsSum)->UseRealTime();

static void BM_MultithreadedSum(benchmark::State &state) {
  for (auto _ : state)
    holistic_multithreading::MultithreadedSum(1, 1000000000, 4);
}
// Register the function as a benchmark
BENCHMARK(BM_MultithreadedSum)->UseRealTime();

static void BM_SingleThreadSum(benchmark::State &state) {
  for (auto _ : state)
    holistic_multithreading::SingleThreadSum(1, 1000000000);
}
// Register the function as a benchmark
BENCHMARK(BM_SingleThreadSum);

static void BM_ThreadCreation(benchmark::State &state) {
  for (auto _ : state) {
    std::thread t(DoSomething);
    t.join();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_ThreadCreation);

BENCHMARK_MAIN();
