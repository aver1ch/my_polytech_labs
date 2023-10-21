#ifndef PRINTDEQUE_H
#define PRINTDEQUE_H

#include <deque>
#include <iostream>
#include <ForwardList.h>
#include "DLList.h"
namespace aristarkhov
{
  template < typename T >
  void printDeque(const std::deque< T >& deque)
  {
    for (auto it = deque.begin(); it != deque.end(); ++it)
    {
      if (it != deque.begin())
      {
        std::cout << " ";
      }
      std::cout << *it;
    }
  }
}

#endif
