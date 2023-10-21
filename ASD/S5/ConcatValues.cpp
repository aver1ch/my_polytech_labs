#include "ConcatValues.h"

namespace aristarkhov
{
  ConcatValues::ConcatValues() noexcept :
    result()
  {}
  void ConcatValues::operator()(const std::pair< int, std::string >& stored)
  {
    if (!result.empty())
    {
      result += ' ';
    }
    result += stored.second;
  }
  const std::string& ConcatValues::getResult() const noexcept
  {
    return result;
  }
}
