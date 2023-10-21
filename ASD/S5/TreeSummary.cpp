#include "TreeSummary.h"

namespace aristarkhov
{
  TreeSummary::TreeSummary() noexcept :
  	concat_(),
  	sum_()
  {}
  void TreeSummary::operator()(const std::pair< int, std::string >& stored)
  {
  	concat_(stored);
  	sum_(stored);
  }
  int TreeSummary::getKeySum() const noexcept
  {
  	return sum_.getResult();
  }
  const std::string& TreeSummary::getConcatValues() const noexcept
  {
  	return concat_.getResult();
  }
}
