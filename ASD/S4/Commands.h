#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <iostream>
#include <Dictionary.h>
#include <ForwardList.h>

namespace aristarkhov
{
  using StrT = std::string;
  using DictionaryT = aristarkhov::Dictionary< int, StrT >;
  using DictionariesT = aristarkhov::Dictionary< StrT, DictionaryT >;
  using ArgsListT = aristarkhov::ForwardList< StrT >;
  using CommandsDictT = Dictionary< StrT, void (*)(DictionariesT&, const ArgsListT&) >;
  class Commands
  {
  public:
    explicit Commands(DictionariesT& dict, std::ostream& out);
    void call(const StrT& commandName, const ArgsListT& args) const noexcept;
  private:
    DictionariesT& dict_;
    CommandsDictT commands_;
    std::ostream& out_;
  };
}
#endif
