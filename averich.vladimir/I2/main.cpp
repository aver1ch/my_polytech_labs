#include <iostream>
#include <fstream>
#include <cstddef>
#include <limits>
#include <readthearray.hpp>
#include "sort.hpp"
#include "istriplet.hpp"
#include "randomdynarray.hpp"
#include "outputarray.hpp"
int main(int argc, char* argv[])
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (argc != 2)
  {
    std::cout << "Error: incorrect file name";
    return 1;
  }
  std::string fileName = argv[1];
  std::ifstream in(fileName);
  size_t sizeOfFileArray = 0;
  int defaultArray[10] = { -5, 2, 1, 3, 2, 1, -2, 1, -3, -4 };
  std::cout << "Count of triplets: " << isTriplet(defaultArray, 10) << " in the static array" << "\n";
  sort(defaultArray, 10);
  outputArray(std::cout, defaultArray, 10);
  std::cout << '\n';
  size_t sizeOfDynArray = 0;
  std::cout << "Enter size of dynamic array: ";
  std::cin >> sizeOfDynArray;
  if (!std::cin)
  {
    std::cout << "Error input" << '\n';
    return 2;
  }
  std::srand(time(nullptr));
  int* dynArray = new int[sizeOfDynArray];
  if (sizeOfDynArray > 0)
  {
    try
    {
      dynArray = randomDynArray(dynArray, sizeOfDynArray);
      std::cout << "Count of triplets: " << isTriplet(dynArray, sizeOfDynArray) << " in the dynamic array" << "\n";
      sort(dynArray, sizeOfDynArray);
      outputArray(std::cout, dynArray, sizeOfDynArray);
      std::cout << '\n';
      delete[] dynArray;
    }
    catch (const std::length_error& e)
    {
      std::cout << e.what() << "\n";
      delete[] dynArray;
      return 2;
    }
  }
  else
  {
    std::cout << "Error dynamic array" << "\n";
    delete[] dynArray;
  }
  in >> sizeOfFileArray;
  if (!in)
  {
    std::cout << "Error reading file" << "\n";
    return 1;
  }
  if (sizeOfFileArray > 0)
  {
    if (sizeOfFileArray < maxSize)
    {
      int* array = new int[sizeOfFileArray];
      readTheArray(in, sizeOfFileArray, array);
      if (!in)
      {
        std::cout << "Error reading file" << "\n";
        return 1;
      }
      try
      {
        std::cout << "Count of triplets: " << isTriplet(array, sizeOfFileArray) << " in the file array" << "\n";
        sort(array, sizeOfFileArray);
        outputArray(std::cout, array, sizeOfFileArray);
        std::cout << '\n';
        delete[] array;
      }
      catch (const std::length_error& e)
      {
        std::cout << e.what() << "\n";
        delete[] array;
        return 2;
      }
    }
  }
  return 0;
}
