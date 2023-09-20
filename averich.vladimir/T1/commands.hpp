#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>

namespace averich
{
  namespace Figures
  {
    static const std::string diamond = "DIAMOND";
    static const std::string circle = "CIRCLE";
    static const std::string rectangle = "RECTANGLE";
    static const std::string allFigures[] = {diamond, circle, rectangle};
  }
  namespace Commands
  {
    static const std::string scale = "SCALE";
    static const std::string allCommands[] = {scale};
  }
  bool isCommand(const std::string& command);
  bool isFigure(const std::string& figure);
}

#endif
