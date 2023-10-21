#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <algorithm>
#include <cstddef>

namespace aristarkhov
{
  template < typename T >
  void selectionSort(T& sequence, size_t size, bool ascending)
  {
    for (size_t i = 0; i < size - 1; i++)
    {
      size_t index = i;
      for (size_t j = i + 1; j < size; j++)
      {
        if (ascending)
        {
          if (sequence[j] < sequence[index])
          {
            index = j;
          }
        }
        else
        {
          if (sequence[j] > sequence[index])
          {
            index = j;
          }
        }
      }
      if (index != i)
      {
        std::swap(sequence[i], sequence[index]);
      }
    }
  }
}

#endif
