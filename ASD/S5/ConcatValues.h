#ifndef CONCAT_VALUES_H
#define CONCAT_VALUES_H

#include <string>
#include <utility>

namespace aristarkhov
{
  class ConcatValues
  {
  public:
    ConcatValues() noexcept;
    void operator()(const std::pair< int, std::string >& stored);
    const std::string& getResult() const noexcept;
  private:
    std::string result;
  };
}

#endif
