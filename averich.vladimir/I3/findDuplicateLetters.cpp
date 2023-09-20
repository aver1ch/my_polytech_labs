#include "findDuplicateLetters.h"

#include <cctype>

bool findLetterInString(const char* c_string, char letter, bool ignoreLowerCase = true)
{
  if (ignoreLowerCase){
    letter = std::tolower(letter);
    while (*c_string) {
      if (std::tolower(*c_string) == letter) {
        return true;
      }
      ++c_string;
    }
  } else {
    while (*c_string) {
      if (*c_string == letter) {
        return true;
      }
    }
  }
  return false;
}

void sortString(char* c_string, size_t length)
{
  for (size_t i = 0; i < length - 1; i++) {
    for (size_t j = 0; j < length - i - 1; j++) {
      if (*(c_string + j) > *(c_string + j + 1)) {
        char temp = *(c_string + j);
        *(c_string + j) = *(c_string + j + 1);
        *(c_string + j + 1) = temp;
      }
    }
  }
}

void findDuplicateLetters(char* destination, const char* c_string_1, const char* c_string_2)
{
  size_t symbolsAdded = 0;
  while(*c_string_1) {
    char ch = std::tolower(*c_string_1);
    if (findLetterInString(c_string_2, ch)) {
      if (!findLetterInString(destination, ch)) {
        *(destination + symbolsAdded++) = ch;
      }
    }
    ++c_string_1;
  }
  if (symbolsAdded > 0) {
    sortString(destination, symbolsAdded);
  }
}
