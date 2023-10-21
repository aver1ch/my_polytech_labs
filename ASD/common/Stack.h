#ifndef STACK_H
#define STACK_H
#include <stdexcept>

#include "node.h"

namespace aristarkhov
{
  template < typename T >
  class Stack
  {
  public:
    Stack();
    Stack(const Stack< T >&);
    Stack(const Stack< T >&&);
    ~Stack();
    void push(const T&);
    T& getTop();
    const T& getTop() const;
    void pop();
    bool isEmpty() const;
    void putIn(const T& instance);
    void popOut();
    const T& getLast() const;
  private:
    Node< T >* head;
  };
}

template < typename T >
void aristarkhov::Stack< T >::putIn(const T& instance)
{
  push(instance);
}

template < typename T >
void aristarkhov::Stack< T >::popOut()
{
  pop();
}

template < typename T >
const T& aristarkhov::Stack< T >::getLast() const
{
    if (head == nullptr)
    {
        throw std::runtime_error("Stack is empty");
    }
    Node< T >* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    return temp->data;
}

template < typename T >
aristarkhov::Stack< T >::Stack() :
  head(nullptr)
{
}

template < typename T >
aristarkhov::Stack< T >::Stack(const Stack< T >& other)
{
  const Node< T >* ptr = other.head;
  while (ptr)
  {
    push(ptr->data);
    ptr = ptr->next;
  }
}

template < typename T >
aristarkhov::Stack< T >::Stack(const Stack< T >&& other)
{
  other.head = nullptr;
  other.size = 0;
}

template < typename T >
aristarkhov::Stack< T >::~Stack()
{
  clear(head);
}

template < typename T >
void aristarkhov::Stack< T >::push(const T& rhs)
{
  Node< T >* newTop = new Node< T >;
  newTop->data = rhs;
  newTop->next = head;
  head = newTop;
}

template < typename T >
T& aristarkhov::Stack< T >::getTop()
{
  if (isEmpty())
  {
    throw std::out_of_range("Stack is empty");
  }
  return head->data;
}

template < typename T >
const T& aristarkhov::Stack< T >::getTop() const
{
  if (isEmpty())
  {
    throw std::out_of_range("Stack is empty");
  }
  return head->data;
}

template < typename T >
void aristarkhov::Stack< T >::pop()
{
  if (isEmpty())
  {
    throw std::out_of_range("Stack is empty");
  }
  Node< T >* temp = head->next;
  delete head;
  head = temp;
}

template < typename T >
bool aristarkhov::Stack< T >::isEmpty() const
{
  return head == nullptr;
}

#endif
