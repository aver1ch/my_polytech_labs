#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <exception>

#include "printDeque.h"
#include "DLList.h"
#include "ForwardList.h"
#include "commandManager.h"
#include "evenOddSort.h"
#include "insertionSort.h"
#include "selectionSort.h"

int main(int argc, char* argv[])
{
  std::srand(std::time(nullptr));
  if (argc != 4)
  {
    std::cerr << "Not enough parameters" << '\n';
    return EXIT_FAILURE;
  }
  try
  {
    size_t sizeOfSeq = aristarkhov::sizeDetection(argv[3]);
    if (aristarkhov::intsOrFloatsSortDetection(argv[2]))
    {
      std::deque< int > seq1;
      aristarkhov::ForwardList< int > seq2;
      aristarkhov::DLList< int > seq3;
      for (size_t i = 0; i < sizeOfSeq; ++i)
      {
        int random_num = 1 + std::rand() / ((RAND_MAX + 1u) / 100);
        seq1.push_back(random_num);
        seq2.pushBack(random_num);
        seq3.push(random_num);
      }
      aristarkhov::selectionSort(seq3, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::selectionSort(seq2, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::insertionSort(seq1, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::insertionSort(seq3, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::evenOddSort(seq1, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::evenOddSort(seq2, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::evenOddSort(seq3, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::printDeque(seq1);
      std::cout << '\n';
      std::cout << seq2 << '\n';
      std::cout << seq3 << '\n';
      std::cout << seq2 << '\n';
      std::cout << seq3 << '\n';
      std::cout << seq2 << '\n';
      aristarkhov::printDeque(seq1);
      std::cout << '\n';
      std::cout << " ";
    }
    else if (!aristarkhov::intsOrFloatsSortDetection(argv[2]))
    {
      std::deque< float > seq1;
      aristarkhov::ForwardList< float > seq2;
      aristarkhov::DLList< float > seq3;
      for (size_t i = 0; i < sizeOfSeq; ++i)
      {
        float random_num = 1.0f + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / 99.0f));
        seq1.push_back(random_num);
        seq2.pushBack(random_num);
        seq3.push(random_num);
      }
      aristarkhov::selectionSort(seq3, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::selectionSort(seq2, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::insertionSort(seq1, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::insertionSort(seq3, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::evenOddSort(seq1, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::evenOddSort(seq2, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::evenOddSort(seq3, sizeOfSeq, aristarkhov::ascendingOrDescendingSortDetection(argv[1]));
      aristarkhov::printDeque(seq1);
      std::cout << '\n';
      std::cout << seq2 << '\n';
      std::cout << seq3 << '\n';
      std::cout << seq2 << '\n';
      std::cout << seq3 << '\n';
      std::cout << seq2 << '\n';
      aristarkhov::printDeque(seq1);
      std::cout << '\n';
      std::cout << " ";
    }
    else
    {
      std::cerr << "Error parameter" << '\n';
      return EXIT_FAILURE;
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
