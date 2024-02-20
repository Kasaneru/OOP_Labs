#pragma once

#include <initializer_list>
#include <iostream>

#include "Allocator.hpp"
#include "Iterator.hpp"

template <class T, class Alloc = Allocator<T>>
class Stack final {
  public:
    using size_type = std::size_t;
    using reference = T&;
    using const_reference = const T&;
    using iterator = Iterator<T>;
    using const_iterator = const Iterator<T>;

  private:
    Node<T>* _head;
    Node<T>* _tail;
    typename Alloc::template rebind<Node<T>>::other _alloc;
    size_type _size;

  public:
    Stack();
    Stack(const std::initializer_list<T>&);
    Stack(const Stack&);
    Stack(Stack&&) noexcept;

    Stack& operator=(const Stack&);
    Stack& operator=(Stack&&) noexcept;

    virtual ~Stack() noexcept;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    reference back();
    const_reference back() const;

    bool empty() const noexcept;
    size_type size() const noexcept;
    void clear();

    void push(const_reference);
    void pop();
};

template <class T, class Alloc>
Stack<T, Alloc>::Stack():
    _head(nullptr), _tail(nullptr), _size(0)
{
}

template <class T, class Alloc>
Stack<T, Alloc>::Stack(const std::initializer_list<T>& list) :
    _head(nullptr), _tail(nullptr), _size(0)
{
    for (const auto& element: list) {
        push(element);
    }
}

template <class T, class Alloc>
Stack<T, Alloc>::Stack(const Stack& other) :
    _head(nullptr), _tail(nullptr), _size(0)
{
    Node<T>* cur = other._head;
    while (cur != nullptr) {
        this->push(cur->_data);
    }
}

template <class T, class Alloc>
Stack<T, Alloc>::Stack(Stack<T, Alloc>&& other) noexcept
{
    this->_head = std::move(other._head);
    this->_tail = std::move(other._tail);
    this->_size = std::move(other._size);
}

template <class T, class Alloc>
Stack<T, Alloc>& Stack<T, Alloc>::operator=(const Stack<T, Alloc>& other)
{
    if (this == &other) return *this;
    
    this->clear();
    
    Node<T>* cur = other._head;
    while (cur != nullptr) {
        this->push(cur->_data);
    }

    return *this;
}

template <class T, class Alloc>
Stack<T, Alloc>& Stack<T, Alloc>::operator=(Stack<T, Alloc>&& other) noexcept
{
    if (this == &other) return *this;

    this->clear();

    this->_head = std::move(other._head);
    this->_tail = std::move(other._tail);
    this->_size = std::move(other._size);

    return *this;
}

template <class T, class Alloc>
Stack<T, Alloc>::~Stack() noexcept
{
    clear();
}

template <class T, class Alloc>
typename Stack<T, Alloc>::iterator Stack<T, Alloc>::begin() 
{
    return Iterator(_head);
}

template <class T, class Alloc>
typename Stack<T, Alloc>::iterator Stack<T, Alloc>::end() 
{
    return Iterator(_tail);
}

template <class T, class Alloc>
typename Stack<T, Alloc>::const_iterator Stack<T, Alloc>::begin() const
{
    return Iterator(_head);
}

template <class T, class Alloc>
typename Stack<T, Alloc>::const_iterator Stack<T, Alloc>::end() const
{
    return Iterator(_tail);
}

template <class T, class Alloc>
typename Stack<T, Alloc>::reference Stack<T, Alloc>::back()
{
    return _tail->_data;
}

template <class T, class Alloc>
typename Stack<T, Alloc>::const_reference Stack<T, Alloc>::back() const
{
    return _tail->_data;
}

template <class T, class Alloc>
bool Stack<T, Alloc>::empty() const noexcept
{
    return _size == 0;
}

template <class T, class Alloc>
typename Stack<T, Alloc>::size_type Stack<T, Alloc>::size() const noexcept
{
    return _size;
}

template <class T, class Alloc>
void Stack<T, Alloc>::clear() 
{
    while (!empty()) {
        pop();
    }
    _size = 0;
}

template <class T, class Alloc>
void Stack<T, Alloc>::push(const_reference __val)
{
    Node<T>* new_Node = _alloc.allocate(1);
    _alloc.construct(new_Node, __val);
    new_Node->_next = nullptr;

    if (!_head) {
        _head = _tail = new_Node;
    } else {
        _tail->_next = new_Node;
        _tail = new_Node;
    }
    ++_size;
}

template <class T, class Alloc>
void Stack<T, Alloc>::pop()
{
    if (_size == 0) return;
    if (_head->_next == nullptr) {
        _alloc.destroy(_head);
        _alloc.deallocate(_head, 1);
        _head = nullptr;
        _tail = nullptr;
        --_size;
        return;
    }

    Node<T>* sec_last = _head;
    while (sec_last->_next->_next != nullptr) {
        sec_last = sec_last->_next;
    }
    Node<T>* old_node = sec_last->_next;
    _alloc.destroy(old_node);
    _alloc.deallocate(old_node, 1);
    _tail = sec_last;
    _tail->_next = nullptr;
    
    if (!_head) {
        _tail = nullptr;
    }
    --_size;
}
