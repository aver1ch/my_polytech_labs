#include "randomdynarray.hpp"
int* randomDynArray(int* dynArray, size_t sizeOfDynArray)
{
  for (size_t i = 0; i < sizeOfDynArray; i++)
  {
    dynArray[i] = 1 + std::rand() % 9;
  }
  return dynArray;
}
