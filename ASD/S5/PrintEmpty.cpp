#include "PrintEmpty.h"

#include <iostream>

namespace
{
  const char* const EMPTY = "<EMPTY>";
}

std::ostream& aristarkhov::printEmpty(std::ostream& os)
{
  return os << EMPTY;
}
