#include "arccos.h"

double arccos(double x, double absError, int iterationMax)
{
  const double pi = 3.14;
  if (x < -1.0 || x > 1.0) {
    throw std::invalid_argument("arccos(double, double, int) => x must be inside [-1.0; 1.0]");
  }
  double result = 0;
  double term = x;
  int n = 0;
  while (n < iterationMax) {
    result += term;
    term *= (x * x * (2 * n + 1) / ((2 * n + 2) * (n + 1) * (n + 1) * (2 * n + 3)));
    if (std::abs(term) < absError) {
      break;
    }
    n++;
  }
  if (std::abs(term) > absError) {
    throw std::runtime_error("Can't achieve required accuracy");
  }
  return pi / 2.0 - result;
}
