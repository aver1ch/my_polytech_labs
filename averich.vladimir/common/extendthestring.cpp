#include "extendthestring.hpp"
#include <limits>
#include <stdexcept>
#include <cstddef>
char* extendTheString(char* cstring, size_t& size, size_t& capacity)
{
  char* newstring = new char[capacity];
  char* j = newstring;
  for (const char* i = cstring; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  return newstring;
}
