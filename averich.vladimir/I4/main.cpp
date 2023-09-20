#include "task.h"

#include <iostream>

int main(int argc, char* argv[])
{
  try {
    performTask(readParameters(argc, argv));
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
