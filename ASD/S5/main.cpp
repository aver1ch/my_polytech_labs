#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <cstring>

#include <Dictionary.h>
#include <GetWord.h>

#include "TreeSummary.h"
#include "PrintEmpty.h"

int main(int argc, char** argv)
{
  if (argc != 3)
  {
    std::cerr << "Not enough arguments passed\n";
    return 1;
  }
  try
  {
    using MethodT = aristarkhov::TreeSummary(aristarkhov::Dictionary< int, std::string >::*)(aristarkhov::TreeSummary) const;
    using DictionaryT = aristarkhov::Dictionary< int, std::string >;
    const aristarkhov::Dictionary< std::string, MethodT> modes
    {
      {"ascending", &DictionaryT::traverseLR< aristarkhov::TreeSummary >},
      {"descending", &DictionaryT::traverseRL< aristarkhov::TreeSummary >},
      {"breadth", &DictionaryT::traverseBreadth< aristarkhov::TreeSummary >}
    };
    const MethodT method = modes[argv[1]];
    aristarkhov::Dictionary< int, std::string > dict;
    {
      std::ifstream input(argv[2]);
      if (!input.is_open())
      {
        std::cerr << "File was not opened\n";
        return 1;
      }
      std::string buf;
      std::getline(input, buf);
      aristarkhov::GetWord getWord{ buf };
      while (!getWord.ended())
      {
        const int key = std::stoi(getWord.get());
        getWord.toNext();
        const std::string value = getWord.get();
        getWord.toNext();
        dict.insert(key, value);
      }
    }
    aristarkhov::TreeSummary f = (dict.*method)({});
    if (f.getConcatValues().empty())
    {
      aristarkhov::printEmpty(std::cout);
    }
    else
    {
      std::cout << f.getKeySum() << ' ' << f.getConcatValues();
    }
    std::cout << '\n';
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}
