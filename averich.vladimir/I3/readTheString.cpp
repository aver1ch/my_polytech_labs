#include "readTheString.h"
#include <cstring>
#include <iostream>

char* readTheString(std::istream& inp)
{
  size_t capacity = 11;
  size_t size = 0;
  char* cStr = nullptr;
  try {
    cStr = new char[capacity];
  } catch (const std::bad_alloc& e) {
    std::cerr << "Can't allocate memory" << '\n';
    throw;
  }
  char chInp = '\0';
  inp >> std::noskipws;
  for (inp >> chInp; (inp && chInp) && (chInp != '\n'); inp >> chInp) {
    if (size + 1 == capacity) {
      capacity = capacity + 10;
      char* dupStr = nullptr;
      try {
        dupStr = new char[capacity];
      } catch (const std::bad_alloc &e) {
        delete[] cStr;
        std::cerr << "Can't allocate memory" << '\n';
        throw;
      }
      cStr[size] = '\0';
      dupStr = strcpy(dupStr, cStr);
      delete[] cStr;
      cStr = dupStr;
    }
    cStr[size++] = chInp;
  }
  if (size == 0)
  {
    delete[] cStr;
    throw std::logic_error("Empty string");
  }
  cStr[size] = '\0';
  return cStr;
}
