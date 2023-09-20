#include <fstream>
#include <iostream>

#include "circle.hpp"
#include "commands.hpp"
#include "compositeshape.hpp"
#include "diamond.hpp"
#include "rectangle.hpp"
#include "tokenizer.hpp"

void pushFigure(const std::string& line, averich::CompositeShape& compositeShape);
void executeCommand(const std::string& string, averich::CompositeShape& compositeShape);

int main(int argc, const char* argv[])
{
  std::istream* inputStream;
  std::ifstream ifstream;
  if (argc == 2)
  {
    ifstream.open(argv[1]);
    inputStream = &ifstream;
  }
  else
  {
    inputStream = &std::cin;
  }
  averich::CompositeShape shapes;
  bool scaleExecuted = false;
  while (*inputStream)
  {
    std::string line, entity;
    std::getline(*inputStream, line);
    if (line.empty())
    {
      continue;
    }
    averich::Tokenizer tokenizer(line);
    tokenizer >> entity;
    try
    {
      if (averich::isFigure(entity))
      {
        pushFigure(line, shapes);
      }
      else if (averich::isCommand(entity))
      {
        executeCommand(line, shapes);
        if (entity == averich::Commands::scale)
        {
          scaleExecuted = true;
        }
      }
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return EXIT_FAILURE;
    }
  }
  if (!scaleExecuted)
  {
    std::cerr << "Scale command wasn't executed" << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

void pushFigure(const std::string& line, averich::CompositeShape& compositeShape)
{
  double x, y, x2, y2, x3, y3, radius;
  averich::Tokenizer tokenizer(line);
  std::string figure;
  tokenizer >> figure;
  try
  {
    if (figure == averich::Figures::diamond)
    {
      tokenizer >> x >> y >> x2 >> y2 >> x3 >> y3;
      if (tokenizer)
      {
        compositeShape.push_back(new averich::Diamond{{x, y}, {x2, y2}, {x3, y3}});
      }
    }
    else if (figure == averich::Figures::circle)
    {
      tokenizer >> x >> y >> radius;
      if (tokenizer)
      {
        compositeShape.push_back(new averich::Circle{{x, y}, radius});
      }
    }
    else if (figure == averich::Figures::rectangle)
    {
      tokenizer >> x >> y >> x2 >> y2;
      if (tokenizer)
      {
        compositeShape.push_back(new averich::Rectangle{{x, y}, {x2, y2}});
      }
    }
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
  }
}

void executeCommand(const std::string& string, averich::CompositeShape& compositeShape)
{
  averich::Tokenizer tokenizer(string);
  std::string commandName;
  tokenizer >> commandName;
  if (commandName == averich::Commands::scale)
  {
    double x, y, scale;
    tokenizer >> x >> y >> scale;
    if (tokenizer && scale > 0.0)
    {
      if (compositeShape.empty())
      {
        throw std::runtime_error("Nothing to scale");
      }
      std::cout << compositeShape << '\n';
      compositeShape.scale(averich::point_t{x, y}, scale);
      std::cout << compositeShape << '\n';
    }
    else
    {
      throw std::invalid_argument("Scale command has negative coeff or insufficient parameters");
    }
  }
}
