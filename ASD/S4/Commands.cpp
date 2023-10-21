#include "Commands.h"

#include <iostream>

namespace
{
  const std::string EMPTY_MSG = "<EMPTY>";
  const std::string INVALID_MSG = "<INVALID COMMAND>";
  std::ostream& printEmpty(std::ostream& out)
  {
    return out << EMPTY_MSG;
  }
  std::ostream& printInvalid(std::ostream& out)
  {
    return out << INVALID_MSG;
  }
  void print(std::ostream& out, const aristarkhov::DictionariesT& dictionaries, const aristarkhov::ArgsListT& args)
  {
    if (args.getSize() != 1)
    {
      throw std::logic_error("Print should recieve exactly 1 argument");
    }
    const aristarkhov::ArgsListT::ConstIteratorT arg = args.getBegin();
    const aristarkhov::DictionaryT& dictToActWith = dictionaries[*arg];
    std::string result = *arg;
    if (dictToActWith.isEmpty())
    {
      printEmpty(out) << '\n';
      return;
    }
    for (aristarkhov::DictionaryT::ConstIterator it = dictToActWith.getBegin(); it != dictToActWith.getEnd(); ++it)
    {
      result += ' ';
      result += std::to_string(it->first);
      result += ' ';
      result += it->second;
    }
    out << result << '\n';
  }
  void complement(aristarkhov::DictionariesT& dictionaries, const aristarkhov::ArgsListT& args)
  {
    if (args.getSize() != 3)
    {
      throw std::logic_error("Complement should recieve exactly 3 arguments");
    }
    aristarkhov::ArgsListT::ConstIteratorT arg = args.getBegin();
    const aristarkhov::StrT name = *arg;
    aristarkhov::DictionaryT result{};
    ++arg;
    const aristarkhov::DictionaryT& first = dictionaries[*arg];
    ++arg;
    const aristarkhov::DictionaryT& second = dictionaries[*arg];
    for (aristarkhov::DictionaryT::ConstIterator it = first.getBegin(); it != first.getEnd(); ++it)
    {
      if (second.find(it->first) == second.getEnd())
      {
        result.insert(it->first, it->second);
      }
    }
    dictionaries.pop(name);
    dictionaries.insert(name, result);
  }
  void intersect(aristarkhov::DictionariesT& dictionaries, const aristarkhov::ArgsListT& args)
  {
    if (args.getSize() != 3)
    {
      throw std::logic_error("Intersect should recieve exactly 3 arguments");
    }
    aristarkhov::ArgsListT::ConstIteratorT arg = args.getBegin();
    const aristarkhov::StrT name = *arg;
    aristarkhov::DictionaryT result{};
    ++arg;
    const aristarkhov::DictionaryT& first = dictionaries[*arg];
    ++arg;
    const aristarkhov::DictionaryT& second = dictionaries[*arg];
    for (aristarkhov::DictionaryT::ConstIterator it = first.getBegin(); it != first.getEnd(); ++it)
    {
      if (second.find(it->first) != second.getEnd())
      {
        result.insert(it->first, it->second);
      }
    }
    dictionaries.pop(name);
    dictionaries.insert(name, result);
  }
  void unionize(aristarkhov::DictionariesT& dictionaries, const aristarkhov::ArgsListT& args)
  {
    if (args.getSize() != 3)
    {
      throw std::logic_error("Union should recieve exactly 3 argumens");
    }
    aristarkhov::ArgsListT::ConstIteratorT arg = args.getBegin();
    const aristarkhov::StrT name = *arg;
    aristarkhov::DictionaryT result{};
    ++arg;
    const aristarkhov::DictionaryT& first = dictionaries[*arg];
    ++arg;
    const aristarkhov::DictionaryT& second = dictionaries[*arg];
    for (aristarkhov::DictionaryT::ConstIterator it = first.getBegin(); it != first.getEnd(); ++it)
    {
      result.insert(it->first, it->second);
    }
    for (aristarkhov::DictionaryT::ConstIterator it = second.getBegin(); it != second.getEnd(); ++it)
    {
      if (result.find(it->first) == result.getEnd())
      {
        result.insert(it->first, it->second);
      }
    }
    dictionaries.pop(name);
    dictionaries.insert(name, result);
  }
}
aristarkhov::Commands::Commands(DictionariesT& dict, std::ostream& out) :
  dict_(dict),
  commands_({ {"complement", complement}, {"intersect", intersect}, {"union", unionize} }),
  out_(out)
{}
void aristarkhov::Commands::call(const StrT& commandName, const ArgsListT& args) const noexcept
{
  try
  {
    if (commandName == "print")
    {
      print(out_, dict_, args);
    }
    else
    {
      commands_[commandName](dict_, args);
    }
  }
  catch (...)
  {
    printInvalid(out_) << '\n';
  }
}
