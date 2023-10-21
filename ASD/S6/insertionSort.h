#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <cstddef>

namespace aristarkhov
{
  template < typename T > 
  void insertionSort(T& sequence, size_t size, bool ascending)
  {
    using ValueType = typename T::value_type;
    for (size_t i = 1; i < size; ++i)
    {
      ValueType key = sequence[i];
      int j = static_cast< int >(i) - 1;
      if (ascending)
      {
        while (j >= 0 && sequence[static_cast< size_t >(j)] > key)
        {
          sequence[static_cast< size_t >(j) + 1] = sequence[static_cast< size_t >(j)];
          --j;
        }
      }
      else
      {
        while (j >= 0 && sequence[static_cast< size_t >(j)] < key)
        {
          sequence[static_cast< size_t >(j) + 1] = sequence[static_cast< size_t >(j)];
          --j;
        }
      }
      sequence[static_cast< size_t >(j) + 1] = key;
    }
  }
}

#endif
