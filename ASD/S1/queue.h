#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include <stdexcept>

namespace averich
{
  template < typename T >
  class Queue
  {
    public:
      Queue() : head_(nullptr), tail_(nullptr), size_(0)
      {}
      Queue(const Queue& other):
        Queue()
      {
        const Node< T >* ptr = other.head_;
        while (ptr)
        {
          push_back(ptr->value);
          ptr = ptr->next;
        }
      }
      ~Queue()
      {
        while (!is_empty())
        {
          pop_front();
        }
      }
      T& get_front()
      {
        safetyCheck();
        return head_->value;
      }
      void push_front(T const& value)
      {
        if (is_empty())
        {
          createFirst(value);
        }
        else
        {
          Node< T >* temp = new Node< T >{value, head_, nullptr};
          head_->previous = temp;
          head_ = temp;
          ++size_;
        }
      }
      T& get_back() const
      {
        safetyCheck();
        return tail_->value;
      }
      void push_back(T const& value)
      {
        if (is_empty())
        {
          createFirst(value);
        }
        else
        {
          Node< T >* temp = new Node< T >{value, nullptr, tail_};
          tail_->next = temp;
          tail_ = temp;
          ++size_;
        }
      }
      bool is_empty() const
      {
        return size_ == 0;
      }
      size_t get_size() const
      {
        return size_;
      }
      void pop_front()
      {
        safetyCheck();
        Node< T >* nextNode = head_->next;
        if (nextNode)
        {
          nextNode->previous = nullptr;
        }
        delete head_;
        head_ = nextNode;
        --size_;
      }
      void pop_back()
      {
        safetyCheck();
        Node< T >* previousNode = tail_->previous;
        if (previousNode)
        {
          previousNode->next = nullptr;
        }
        delete tail_;
        tail_ = previousNode;
        --size_;
      }
    private:
      template < typename D >
      struct Node
      {
        D value;
        Node* next;
        Node* previous;
      };
      void createFirst(T const& value)
      {
        head_ = tail_ = new Node< T >{value, nullptr, nullptr};
        ++size_;
      }
      void safetyCheck() const
      {
        if (is_empty())
        {
          throw std::runtime_error("Operation isn't allowed: is empty");
        }
      }
      Node< T >* head_;
      Node< T >* tail_;
      size_t size_;
  };
}

#endif
