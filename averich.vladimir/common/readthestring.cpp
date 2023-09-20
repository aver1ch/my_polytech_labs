#include "readthestring.hpp"
#include <stdexcept>
#include <iostream>
#include <limits>
#include <cstddef>
#include <extendthestring.hpp>

char* readTheString(std::istream& inputString, size_t& inSize, size_t increaseCapacity)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;
  inputString >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      if (capacity == maxSize)
      {
        delete[] cstring;
        throw std::runtime_error("Size more than max");
      }
      if (maxSize - increaseCapacity <= capacity)
      {
        capacity = maxSize;
      }
      else
      {
        capacity += increaseCapacity;
      }
      try
      {
        char* newString = extendTheString(cstring, size, capacity);
        delete[] cstring;
        cstring = newString;
      }
      catch (...)
      {
        delete[] cstring;
        throw;
      }
    }
    inputString >> cstring[size];
  }
  while (inputString && cstring[size++] != '\n');
  if (!inputString && !size)
  {
    delete[] cstring;
    throw std::runtime_error("Input error");
  }
  cstring[size - 1] = '\0';
  inSize = size;
  return cstring;
}
