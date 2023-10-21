#include <fstream>
#include <iostream>

#include "expressionevaluator.h"
#include "stack.h"

int main(int argc, const char* argv[])
{
  std::ifstream ifstream;
  std::istream& istream = (argc == 2) ? (ifstream.open(argv[1]), ifstream) : std::cin;
  averich::Stack< int64_t > stackOfResults;
  while (istream)
  {
    std::string string;
    std::getline(istream, string);
    if (string.empty())
    {
      continue;
    }
    try
    {
      stackOfResults.push(averich::evaluateExpression(string));
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return EXIT_FAILURE;
    }
  }
  if (!stackOfResults.is_empty())
  {
    std::cout << stackOfResults.get_top();
    stackOfResults.pop();
    while (stackOfResults.get_size())
    {
      std::cout << ' ' << stackOfResults.get_top();
      stackOfResults.pop();
    }
  }
  std::cout << '\n';
  return EXIT_SUCCESS;
}
