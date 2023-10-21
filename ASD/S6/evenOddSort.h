#ifndef EVENODDSORT_H
#define EVENODDSORT_H

#include <algorithm>
#include <cstddef>

namespace aristarkhov
{
  template < typename T >
  void evenOddSort(T& sequence, size_t size, bool ascending)
  {
    bool sorted = false;
    while (!sorted)
    {
      sorted = true;
      for (size_t i = 0; i < size - 1; i += 2)
      {
        if ((ascending && sequence[i] > sequence[i + 1]) || (!ascending && sequence[i] < sequence[i + 1]))
        {
          std::swap(sequence[i], sequence[i + 1]);
          sorted = false;
        }
      }
      for (size_t i = 1; i < size - 1; i += 2)
      {
        if ((ascending && sequence[i] > sequence[i + 1]) || (!ascending && sequence[i] < sequence[i + 1]))
        {
          std::swap(sequence[i], sequence[i + 1]);
          sorted = false;
        }
      }
    }
  }
}

#endif
