#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include "arccos.h"

int main()
{
  double lowInterval = -1.0;
  double highInterval = 1.0;
  double absError = 1e-6;
  double interValStep = 0.05;
  int numberMax = 100;
  std::cin >> absError >> numberMax >> lowInterval >> highInterval >> interValStep;
  if (!std::cin) {
    std::cerr << "Incorrect parameters" << '\n';
    return EXIT_FAILURE;
  }
  while (lowInterval <= highInterval) {
    try {
      std::cout << "x=(" << std::setw(8) << std::setprecision(3) << lowInterval
                << "), our=" << std::setw(10) << std::setprecision(8) << arccos(lowInterval, absError, numberMax)
                << "), lib=" << std::setw(10) << std::setprecision(8) << std::acos(lowInterval)
                << '\n';
      lowInterval += interValStep;
    } catch (std::runtime_error const& e) {
      std::cerr << e.what() << '\n';
      return EXIT_FAILURE; // ?
    } catch (std::invalid_argument const& e) {
      std::cerr << e.what() << '\n';
      return EXIT_FAILURE; // ?
    }
  }
  return EXIT_SUCCESS;
}
