#include "KeySum.h"

namespace aristarkhov
{
  KeySum::KeySum() noexcept :
  	result_(0)
  {}
  void KeySum::operator()(const std::pair< int, std::string >& stored)
  {
  	result_ += stored.first;
  }
  int KeySum::getResult() const noexcept
  {
  	return result_;
  }
}