#ifndef TREE_SUMMARY_H
#define TREE_SUMMARY_H

#include <utility>
#include <string>

#include "ConcatValues.h"
#include "KeySum.h"

namespace aristarkhov
{
  class TreeSummary
  {
  public:
    TreeSummary() noexcept;
    void operator()(const std::pair< int, std::string >& stored);
    int getKeySum() const noexcept;
    const std::string& getConcatValues() const noexcept;
  private:
    ConcatValues concat_;
    KeySum sum_;
  };
}

#endif
