#ifndef DLLIST_H
#define DLLIST_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <node.h>

namespace aristarkhov
{
  template < typename T >
  class DLList
  {
  public:
    typedef T value_type;
    DLList();
    ~DLList();
    DLList(const DLList& obj);
    DLList(DLList&& obj);
    DLList< T >& operator=(const DLList< T >& obj);
    DLList< T >& operator=(DLList< T >&& obj);
    T& operator[](size_t index);
    T& operator[](size_t index) const;
    friend std::ostream& operator<<(std::ostream& os, const DLList< T >& obj)
    {
      Node< T >* temp = obj.head_;
      for (size_t i = 0; i < obj.getSize(); ++i)
      {
        os << temp->data;
        if (i != obj.getSize() - 1)
        {
          os << " ";
        }
        temp = temp->next;
      }
      return os;
    }
    template < typename U >
    friend bool operator<(const DLList< U >& obj1, const U& obj2);
    template < typename U >
    friend bool operator>(const DLList< U >& obj1, const U& obj2);
    bool isEmpty() const;
    void push(const T& rhs);
    void pop();
    size_t getSize() const;
  private:
    size_t size;
    Node< T >* head_;
    Node< T >* tail_;
  };
  template < typename T >
  DLList< T >::DLList(const DLList< T >& obj)
  {
    size = obj.size;
    head_ = obj.head_;
    tail_ = obj.tail_;
  }
  template < typename T >
  DLList< T >::DLList(DLList< T >&& obj)
  {
    size = obj.size;
    head_ = obj.head_;
    tail_ = obj.tail_;
    obj.size = 0;
    obj.head_ = nullptr;
    obj.tail_ = nullptr;
  }
  template < typename T >
  DLList< T >& DLList< T >::operator=(const DLList< T >& obj)
  {
    DLList< T > temp(obj);
    std::swap(temp, *this);
    return *this;
  }
  template < typename T >
  DLList< T >& DLList< T >::operator=(DLList< T >&& obj)
  {
    DLList< T > temp(obj);
    std::swap(temp, *this);
    return *this;
  }
  template < typename T >
  size_t DLList< T >::getSize() const
  {
    return size;
  }
  template < typename U >
  bool operator<(const DLList< U >& obj1, const U& obj2)
  {
    return obj1 < obj2;
  }
  template < typename U >
  bool operator>(const DLList< U >& obj1, const U& obj2)
  {
    return obj1 > obj2;
  }
  template < typename T >
  T& DLList< T >::operator[](size_t index)
  {
    size_t i = 0;
    if (index >= size)
    {
      return head_->data;
    }
    Node< T >* temp = head_;
    while (i++ < index)
    {
      temp = temp->next;
    }
    return temp->data;
  }
  template < typename T >
  T& DLList< T >::operator[](size_t index) const
  {
    size_t i = 0;
    if (index >= size)
    {
      return head_->data;
    }
    Node< T >* temp = head_;
    while (i++ < index)
    {
      temp = temp->next;
    }
    return temp->data;
  }
  template < typename T >
  void DLList< T >::pop()
  {
    --size;
    if (isEmpty())
    {
      throw std::underflow_error("No value in queue");
    }
    else if (tail_ == head_)
    {
      delete tail_;
      tail_ = head_ = nullptr;
    }
    else
    {
      Node< T >* temp = head_->next;
      delete head_;
      head_ = temp;
    }
  }
  template < typename T >
  void DLList< T >::push(const T& rhs)
  {
    ++size;
    if (isEmpty())
    {
      head_ = tail_ = new Node< T >{rhs, nullptr};
    }
    else
    {
      tail_->next = new Node< T >{rhs, nullptr};
      tail_ = tail_->next;
    }
  }
  template < typename T >
  DLList< T >::DLList():
    size(0),
    head_(nullptr),
    tail_(nullptr)
  {
  }
  template < typename T >
  DLList< T >::~DLList()
  {
    clear(head_);
  }
  template < typename T >
  bool DLList< T >::isEmpty() const
  {
    return head_ == nullptr;
  }
};

#endif
