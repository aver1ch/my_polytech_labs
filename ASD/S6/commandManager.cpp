#include "commandManager.h"

namespace aristarkhov
{
  bool ascendingOrDescendingSortDetection(const char* argument)
  {
    if (argument == nullptr)
    {
      throw std::logic_error("First parameter is null");
    }
    const char* ascending = "ascending";
    const char* descending = "descending";
    if (std::strcmp(argument, ascending) == 0)
    {
      return true;
    }
    else if (std::strcmp(argument, descending) == 0)
    {
      return false;
    }
    else
    {
      throw std::logic_error("Irregular first parameter");
    }
  }
  bool intsOrFloatsSortDetection(const char* argument)
  {
    if (argument == nullptr)
    {
      throw std::logic_error("Second parameter is null");
    }
    const char* ints = "ints";
    const char* floats = "floats";
    if (std::strcmp(argument, ints) == 0)
    {
      return true;
    }
    else if (std::strcmp(argument, floats) == 0)
    {
      return false;
    }
    else
    {
      throw std::logic_error("Irregular second parameter");
    }
  }
  size_t sizeDetection(const char* argument)
  {
    if (argument == nullptr)
    {
      throw std::invalid_argument("Argument for size detection is null");
    }
    try
    {
      int num = std::stoi(argument);
      if (num <= 0)
      {
        throw std::invalid_argument("Size of sequences is zero or negative");
      }
      return static_cast<size_t>(num);
    }
    catch (const std::invalid_argument& e)
    {
      throw std::invalid_argument("Conversion error: " + std::string(argument) + " is not a number");
    }
    catch (const std::out_of_range& e)
    {
      throw std::out_of_range("Conversion error: " + std::string(argument) + " is out of range of int");
    }
  }
};
