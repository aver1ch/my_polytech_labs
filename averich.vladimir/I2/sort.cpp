#include "sort.hpp"
int* sort(int* array, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size - 1 - i; j++)
    {
      if (array[j] > array[j + 1])
      {
        std::swap(array[j], array[j + 1]);
      }
    }
  }
  return array;
}
