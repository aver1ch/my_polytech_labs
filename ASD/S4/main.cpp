#include <fstream>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>

#include <GetWord.h>
#include <Dictionary.h>

#include "Commands.h"

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cerr << "No filename passed\n";
    return 1;
  }
  try
  {
    using StrT = std::string;
    using DictionariesT = aristarkhov::Dictionary< StrT, aristarkhov::Dictionary< int, StrT > >;
    DictionariesT dictionaries{};
    {
      std::ifstream input(argv[1]);
      if (!input.is_open())
      {
        std::cerr << "File was not opened\n";
        return 1;
      }
      StrT buf;
      while (std::getline(input, buf))
      {
        if (buf.empty())
        {
          continue;
        }
        aristarkhov::GetWord getWord{ buf };
        const StrT name = getWord.get();
        DictionariesT::Iterator currentToInsert = dictionaries.insert(name, {});
        getWord.toNext();
        while (!getWord.ended())
        {
          const int dictCode = std::stoi(getWord.get());
          getWord.toNext();
          const StrT dictContainment = getWord.get();
          getWord.toNext();
          currentToInsert->second.insert(dictCode, dictContainment);
        }
      }
    }
    aristarkhov::Commands commands{ dictionaries, std::cout };
    StrT buf;
    while (std::getline(std::cin, buf))
    {
      if (buf.empty())
      {
        continue;
      }
      aristarkhov::GetWord getWord{ buf };
      const StrT commandName = getWord.get();
      getWord.toNext();
      aristarkhov::ArgsListT args;
      while (!getWord.ended())
      {
        const StrT arg = getWord.get();
        getWord.toNext();
        args.pushBack(arg);
      }
      commands.call(commandName, args);
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}
