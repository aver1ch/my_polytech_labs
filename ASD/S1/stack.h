#ifndef STACK_H
#define STACK_H

#include "queue.h"

namespace averich
{
  template < typename T >
  class Stack
  {
    public:
      bool is_empty() const
      {
        return queue.is_empty();
      }
      size_t get_size() const
      {
        return queue.get_size();
      }
      T& get_top()
      {
        return queue.get_front();
      }
      void push(T const& value)
      {
        queue.push_front(value);
      }
      void pop()
      {
        queue.pop_front();
      }
    private:
      Queue< T > queue;
  };
}

#endif
