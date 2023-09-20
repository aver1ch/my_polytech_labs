#include "parameters.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

Parameters readParameters(int argc, char* argv[])
{
  Parameters parameters;
  if (argc != 4) {
    throw std::invalid_argument("Incorrect number of arguments was given");
  }
  int taskNum = std::atoi(argv[1]);
  if (taskNum == 1) {
    parameters.task = Parameters::Task::First;
  } else if (taskNum == 2) {
    parameters.task = Parameters::Task::Second;
  } else {
    throw std::invalid_argument("Task's number is incorrect");
  }
  parameters.inputFileName = argv[2];
  std::fstream in(parameters.inputFileName);
  if (!in) {
    throw std::invalid_argument("Input file with given name doesn't exist");
  }
  parameters.outputFileName = argv[3];
  return parameters;
}
