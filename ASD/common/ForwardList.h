#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <stdexcept>
#include <algorithm>
#include <cstddef>
#include <iostream>

namespace aristarkhov
{
    template < typename T >
    class ForwardList
    {
    public:
      struct ForwardListNode
      {
        explicit ForwardListNode(const T& toStore) :
          stored(toStore),
          tail(nullptr)
        {}
        ~ForwardListNode()
        {
          delete tail;
        }
        T stored;
        ForwardListNode* tail;
      };
      class ConstForwardListIterator;
      class ForwardListIterator : public std::iterator< std::forward_iterator_tag, T >
      {
      public:
        ForwardListIterator(const ForwardListIterator& instance) noexcept = default;
        ~ForwardListIterator() = default;
        ForwardListIterator& operator=(const ForwardListIterator& instance) noexcept
        {
          isBeforeLst_ = instance.isBeforeLst_;
          lst_ = instance.lst_;
          return *this;
        };
        T* operator->() const noexcept
        {
          return std::addressof(lst_->stored);
        }
        T& operator*() const noexcept
        {
          return lst_->stored;
        }
        ForwardListIterator& operator++() noexcept
        {
          if (!isBeforeLst_)
          {
            lst_ = lst_->tail;
          }
          else
          {
            isBeforeLst_ = false;
          }
          return *this;
        }
        bool operator==(const ForwardListIterator& it) const noexcept
        {
          return lst_ == it.lst_ && isBeforeLst_ == it.isBeforeLst_;
        }
        bool operator==(const ConstForwardListIterator& it) const noexcept
        {
          return lst_ == it.getNode() && isBeforeLst_ == it.isBefore();
        }
        bool operator!=(const ForwardListIterator& it) const noexcept
        {
          return !(*this == it);
        }
        bool operator!=(const ConstForwardListIterator& it) const noexcept
        {
          return !(*this == it);
        }
        bool isBefore() const noexcept
        {
          return isBeforeLst_;
        }
        const ForwardListNode* getNode() const noexcept
        {
          return lst_;
        }
      private:
        ForwardListIterator(ForwardListNode* lst, bool isBefore) noexcept :
          isBeforeLst_(isBefore),
          lst_(lst)
        {}
        friend ForwardList;
        bool isBeforeLst_;
        ForwardListNode* lst_;
      };
      class ConstForwardListIterator : public std::iterator< std::forward_iterator_tag, T >
      {
      public:
        ConstForwardListIterator(const ForwardListNode* lst, bool isBefore) noexcept :
          isBeforeLst_(isBefore),
          lst_(lst)
        {}
        ConstForwardListIterator(const ConstForwardListIterator& instance) noexcept = default;
        ConstForwardListIterator(const ForwardListIterator& instance) noexcept
        {
          lst_ = instance.getNode();
          isBeforeLst_ = instance.isBefore();
        }
        ~ConstForwardListIterator() = default;
        ConstForwardListIterator& operator=(const ConstForwardListIterator& instance) noexcept
        {
          lst_ = instance.lst_;
          isBeforeLst_ = instance.isBeforeLst_;
          return *this;
        }
        const T* operator->() const noexcept
        {
          return std::addressof(lst_->stored);
        }
        const T& operator*() const noexcept
        {
          return lst_->stored;
        }
        ConstForwardListIterator& operator++() noexcept
        {
          if (!isBeforeLst_)
          {
            lst_ = lst_->tail;
          }
          else
          {
            isBeforeLst_ = false;
          }
          return *this;
        }
        bool operator==(const ConstForwardListIterator& it) const noexcept
        {
          return lst_ == it.getNode() && isBeforeLst_ == it.isBefore();
        }
        bool operator==(const ForwardListIterator& it) const noexcept
        {
          return lst_ == it.getNode() && isBeforeLst_ == it.isBefore();
        }
        bool operator!=(const ConstForwardListIterator& it) const noexcept
        {
          return !(*this == it);
        }
        bool operator!=(const ForwardListIterator& it) const noexcept
        {
          return !(*this == it);
        }
        bool isBefore() const noexcept
        {
          return isBeforeLst_;
        }
        const ForwardListNode* getNode() const noexcept
        {
          return lst_;
        }
      private:
        bool isBeforeLst_;
        const ForwardListNode* lst_;
      };
      using ConstIteratorT = ConstForwardListIterator;
      using IteratorT = ForwardListIterator;
      ForwardList() noexcept :
        tail_(nullptr)
      {}
      ~ForwardList()
      {
        delete tail_;
      }
      bool isEmpty() const noexcept
      {
        return !tail_;
      }
      IteratorT getBegin() noexcept
      {
        return IteratorT{ tail_, false };
      }
      IteratorT getBeforeBegin() noexcept
      {
        return IteratorT{ tail_, true };
      }
      IteratorT getEnd() noexcept
      {
        return IteratorT{ nullptr, false };
      }
      ConstIteratorT getBegin() const noexcept
      {
        return ConstIteratorT{ tail_, false };
      }
      ConstIteratorT getBeforeBegin() const noexcept
      {
        return ConstIteratorT{ tail_, true };
      }
      ConstIteratorT getEnd() const noexcept
      {
        return ConstIteratorT{ nullptr, false };
      }
      size_t getSize() const noexcept
      {
        size_t result = 0;
        for (ConstIteratorT it = getBegin(); it != getEnd(); ++it)
        {
          ++result;
        }
        return result;
      }
      void clear() noexcept
      {
        if (tail_)
        {
          tail_->~ForwardList();
          delete tail_;
        }
      }
      void insertAfter(IteratorT pos, const T& object)
      {
        if (!tail_)
        {
          tail_ = new ForwardListNode{ object };
          return;
        }
        ForwardListNode* newNode = nullptr;
        try
        {
          newNode = new ForwardListNode(object);
        }
        catch (...)
        {
          delete newNode;
          throw;
        }

        if (pos.isBefore())
        {
          newNode->tail = this->tail_;
          this->tail_ = newNode;
        }
        else
        {
          newNode->tail = pos.lst_->tail;
          pos.lst_->tail = newNode;
        }
      }
      void eraseAfter(IteratorT pos) noexcept
      {
        if (pos.lst_->tail)
        {
          ForwardListNode* toDelete = nullptr;
          if (pos.isBefore())
          {
            toDelete = pos.lst_;
            tail_ = toDelete->tail;
          }
          else
          {
            toDelete = pos.lst_->tail;
            pos.lst_->tail = toDelete->tail;
          }
          toDelete->tail = nullptr;
          delete toDelete;
        }
      }
      void pushBack(const T& object)
      {
        if (!tail_)
        {
          tail_ = new ForwardListNode{ object };
          return;
        }
        IteratorT it = getBegin();
        while (it.lst_->tail)
        {
          ++it;
        }
        it.lst_->tail = new ForwardListNode{ object };
      }
      void popBack() noexcept
      {
        IteratorT it = getBegin();
        while (it.lst_->tail_)
        {
          it++;
        }
        delete it.lst_;
      }
      void swap(ForwardList< T >& instance) noexcept
      {
        std::swap(tail_, instance.tail_);
      }
      friend std::ostream& operator<<(std::ostream& os, const ForwardList< T >& obj)
      {
        ConstIteratorT it = obj.getBegin();
        if (it != obj.getEnd())
        {
          os << *it;
          ++it;
        }
        for (; it != obj.getEnd(); ++it)
        {
          os << " " << *it;
        }
        return os;
      }
      T& operator[](size_t index)
      {
        if (index >= getSize())
        {
          return tail_->stored;
        }
        IteratorT temp = getBegin();
        size_t counter = 0;
        for (IteratorT it = temp; it != getEnd(); ++it)
        {
          if (counter == index)
          {
            return *it;
          }
          ++counter;
        }
        return *temp;
      }
      const T& operator[](size_t index) const
      {
        if (index >= getSize())
        {
          return tail_->stored;
        }
        ConstIteratorT temp = getBegin();
        size_t counter = 0;
        for (ConstIteratorT it = temp; it != getEnd(); ++it)
        {
          if (counter == index)
          {
            return *it;
          }
          ++counter;
        }
        return *temp;
      }
    private:
      ForwardListNode* tail_;
    };
    template < typename U >
    bool operator<(const ForwardList< U >& obj1, const U& obj2)
    {
      return obj1 < obj2;
    }
    template < typename U >
    bool operator>(const ForwardList< U >& obj1, const U& obj2)
    {
      return obj1 > obj2;
    }
}
#endif
