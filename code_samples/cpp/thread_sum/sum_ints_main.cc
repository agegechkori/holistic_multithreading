#include <cstdlib>
#include <iostream>
#include <functional>
#include <thread>

#include "sum_ints.h"

using holistic_multithreading::SingleThreadSum;
using holistic_multithreading::ThreadsSum;
using holistic_multithreading::MultithreadedSum;

int main(int argc, char* argv[]) {
  std::cout << "Number of CPUs as counted by C++ standard library: " << std::thread::hardware_concurrency() << std::endl;
  std::cout << "Single-thread sum is: " << SingleThreadSum(1, 45) << std::endl;
  std::cout << "Two-thread sum is: " << ThreadsSum(1, 45) << std::endl;
  std::cout << "Four-thread sum is: " << MultithreadedSum(1, 45, 4) << std::endl;
  return EXIT_SUCCESS;
}

