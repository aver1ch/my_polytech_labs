#include "GetWord.h"

namespace aristarkhov
{
  GetWord::GetWord(const std::string& source) :
    ref(source),
    wordBegin(source.begin())
  {}
  bool GetWord::ended()
  {
    while (*wordBegin == ' ')
    {
      ++wordBegin;
    }
    return wordBegin == ref.end();
  }
  std::string GetWord::get()
  {
    while (*wordBegin == ' ')
    {
      ++wordBegin;
    }
    std::string result;
    for (std::string::const_iterator it = wordBegin; (*it != ' ') && (it != ref.end()); ++it)
    {
      result += *it;
    }
    return result;
  }
  void GetWord::toNext()
  {
    while (*wordBegin == ' ')
    {
      ++wordBegin;
    }
    while ((*wordBegin != ' ') && (wordBegin != ref.end()))
    {
      ++wordBegin;
    }
  }
}
