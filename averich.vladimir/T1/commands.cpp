#include "commands.hpp"

namespace averich
{
  bool isCommand(const std::string& command)
  {
    for (const std::string& name : Commands::allCommands)
    {
      if (name == command)
      {
        return true;
      }
    }
    return false;
  }
  bool isFigure(const std::string& figure)
  {
    for (const std::string& name : Figures::allFigures)
    {
      if (name == figure)
      {
        return true;
      }
    }
    return false;
  }
}
