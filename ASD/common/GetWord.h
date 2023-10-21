#ifndef GET_WORD_H
#define GET_WORD_H

#include <string>

namespace aristarkhov
{
  class GetWord
  {
  public:
    explicit GetWord(const std::string& source);
    ~GetWord() = default;
    bool ended();
    std::string get();
    void toNext();
    const std::string& ref;
  private:
    std::string::const_iterator wordBegin;
  };
}

#endif
