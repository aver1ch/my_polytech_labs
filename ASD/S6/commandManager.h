#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <exception>
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>

namespace aristarkhov
{
  bool ascendingOrDescendingSortDetection(const char* argument);
  bool intsOrFloatsSortDetection(const char* argument);
  size_t sizeDetection(const char* argument);
}   

#endif
