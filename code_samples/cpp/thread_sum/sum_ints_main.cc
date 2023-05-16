#include <cstdlib>
#include <iostream>
#include <functional>
#include <thread>

#include "sum_ints.h"

using holistic_multithreading::ThreadsSum;
using holistic_multithreading::MultithreadedSum;

int main(int argc, char* argv[]) {
  std::cout << "Sum is: " << ThreadsSum(1, 45) << std::endl;
  std::cout << "Sum is: " << MultithreadedSum(1, 45, 4) << std::endl;
  return EXIT_SUCCESS;
}

