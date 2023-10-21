#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

#include "node.h"

namespace aristarkhov
{
  template < typename T >
  class Queue
  {
  public:
    Queue();
    Queue(const Queue< T >&);
    Queue(Queue< T >&&);
    ~Queue();
    void push(const T&);
    const T& getTop() const;
    T& getTop();
    void pop();
    bool isEmpty() const;
    void putIn(const T& instance);
    void popOut();
    const T& getLast() const;
  private:
    Node< T >* head;
    Node< T >* tail;
  };
}

template < typename T >
void aristarkhov::Queue< T >::putIn(const T& instance)
{
  push(instance);
}

template < typename T >
void aristarkhov::Queue< T >::popOut()
{
  pop();
}

template < typename T >
const T& aristarkhov::Queue< T >::getLast() const
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
aristarkhov::Queue< T >::Queue() :
  head(nullptr),
  tail(nullptr)
{
}

template < typename T >
aristarkhov::Queue< T >::Queue(const Queue< T >& other) : Queue()
{
  const Node< T >* ptr = other.head;
  while (ptr)
  {
    push(ptr->data);
    ptr = ptr->next;
  }
}

template < typename T >
aristarkhov::Queue< T >::Queue(Queue< T >&& other) :
  head(other.head),
  tail(other.tail)
{
  head = nullptr;
  tail = nullptr;
}

template < typename T >
aristarkhov::Queue< T >::~Queue()
{
  clear(head);
}

template < typename T >
void aristarkhov::Queue< T >::push(const T& rhs)
{
  if (isEmpty())
  {
    head = tail = new Node< T >{ rhs, nullptr };
  }
  else
  {
    tail->next = new Node< T >{ rhs, nullptr };
    tail = tail->next;
  }
}

template < typename T >
const T& aristarkhov::Queue< T >::getTop() const
{
  if (isEmpty())
  {
    throw std::out_of_range("Queue is empty");
  }
  return head->data;
}

template < typename T >
T& aristarkhov::Queue< T >::getTop()
{
  if (isEmpty())
  {
    throw std::out_of_range("Queue is empty");
  }
  return head->data;
}

template < typename T >
void aristarkhov::Queue< T >::pop()
{
  if (isEmpty())
  {
    throw std::underflow_error("No value in queue");
  }
  else if (tail == head)
  {
    delete tail;
    tail = head = nullptr;
  }
  else
  {
    Node< T >* temp = head->next;
    delete head;
    head = temp;
  }
}

template < typename T >
bool aristarkhov::Queue< T >::isEmpty() const
{
  return head == nullptr;
}

#endif
