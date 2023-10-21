#ifndef NODE_H
#define NODE_H

namespace aristarkhov
{
  template < typename T >
  struct Node
  {
    T data;
    Node< T >* next;
    Node< T >* previous;
  };
  template < typename T > void clear(Node< T >* head)
  {
    while (head)
    {
      Node< T >* temp = head->next;
      delete head;
      head = temp;
      }
    head = nullptr;
  }
}

#endif
