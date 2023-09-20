#include <iostream>

#include "readTheString.h"
#include "hasDoubledChars.h"
#include "findDuplicateLetters.h"

int main()
{
  char* inputString = nullptr;
  try {
    inputString = readTheString(std::cin);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }
  char* resultOfDuplicateTestString = nullptr;
  try {
    resultOfDuplicateTestString = new char[LettersInEnglishAlphabet + 1];
  } catch (const std::bad_alloc& e) {
    std::cerr << "Can't allocate memory" << '\n';
    delete [] inputString;
    return EXIT_FAILURE;
  }
  for (size_t i = 0; i < LettersInEnglishAlphabet + 1; ++i) {
    *(resultOfDuplicateTestString + i) = '\0';
  }
  const char predifinedString[] = "abZ";
  findDuplicateLetters(resultOfDuplicateTestString, inputString, predifinedString);
  std::cout << "All chars of cstring: " << resultOfDuplicateTestString << '\n';
  std::cout << "Repeating chars: " << std::boolalpha << hasDoubledChars(inputString) << '\n';
  delete[] resultOfDuplicateTestString;
  delete[] inputString;
  return EXIT_SUCCESS;
}
