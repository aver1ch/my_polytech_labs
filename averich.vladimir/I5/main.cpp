#include "isexpression.h"
#include <iostream>

int main()
{
  std::string str;
  std::cin >> str;
  if (str.empty()) {
    std::cerr << "String is empty" << '\n';
    return EXIT_FAILURE;
  }
  std::cout << std::boolalpha << isExpression(str.c_str()) << "\n";
  return EXIT_SUCCESS;
}
