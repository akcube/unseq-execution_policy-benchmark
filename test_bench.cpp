#include <benchmark/benchmark.h>
#include <hpx/iostream.hpp>
#include <hpx/hpx_main.hpp>

static void BM_my_test_function(benchmark::State& state) {

    // Perform setup here
    for (auto _ : state) {
        // This code gets timed

    }
}

// Register the function as a benchmark
BENCHMARK(BM_my_test_function);
// Run the benchmark
BENCHMARK_MAIN();