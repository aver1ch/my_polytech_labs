#include "outputarray.hpp"

std::ostream& outputArray(std::ostream& out, int* array, size_t size)
{
  for (size_t i = 0; i < size - 1; i++)
  {
    out << array[i] << " ";
    if (!out)
    {
      return out;
    }
  }
  out << array[size - 1];
  return out;
}
