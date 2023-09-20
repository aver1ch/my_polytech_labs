#include "readthearray.hpp"
#include <iostream>
#include <cstddef>
#include <cctype>
std::istream& readTheArray(std::istream& in, size_t sizeOfFileArray, int* fileArray)
{
  for (size_t i = 0; i < sizeOfFileArray; i++)
  {
    in >> fileArray[i];
    if (!in)
    {
      return in;
    }
  }
  return in;
}
