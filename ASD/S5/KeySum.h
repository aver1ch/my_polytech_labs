#ifndef KEY_SUM_H
#define KEY_SUM_H

#include <utility>
#include <string>

namespace aristarkhov
{
  class KeySum
  {
    public:
      KeySum() noexcept;
      void operator()(const std::pair< int, std::string >& stored);
      int getResult() const noexcept;
    private:
      int result_;
  };
}

#endif
