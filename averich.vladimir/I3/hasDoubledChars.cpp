#include "hasDoubledChars.h"

bool hasDoubledChars(const char* c_string)
{
  if (!*c_string++) {
    return false;
  }
  while (*c_string) {
    if (*c_string == *(c_string - 1)) {
      return true;
    }
    ++c_string;
  }
  return false;
}
