# Match compiler with HPX
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# Create project
cmake_minimum_required(VERSION 3.22.3)
project(UNSEQ_BENCH VERSION 1.0 DESCRIPTION "Benchmark setup for testing my unseq and par_unseq implementations in HPX" LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${UNSEQ_BENCH_BINARY_DIR}/bin/)

# Add test executable
add_executable(test_bench test_bench.cpp)

# Add HPX test executable
add_executable(hpx_test hpx_test.cpp)

# Find and link to benchmark library
find_package(benchmark REQUIRED)
target_link_libraries(test_bench benchmark::benchmark)

# Find and link to HPX library
find_package(HPX REQUIRED)
target_link_libraries(test_bench HPX::hpx HPX::wrap_main HPX::iostreams_component)
target_link_libraries(hpx_test HPX::hpx HPX::wrap_main HPX::iostreams_component)
