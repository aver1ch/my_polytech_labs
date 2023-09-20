#include "sumcount.hpp"
#include "issum.hpp"
int sumCount(int preprevalue, int prevalue, int value)
{
  if (isSum(preprevalue, prevalue, value))
  {
    return 1;
  }
  return 0;
}
