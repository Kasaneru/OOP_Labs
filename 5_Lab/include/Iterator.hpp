#pragma once

#include <cstddef>
#include <iterator>

template <class T>
struct Node {
    T _data;
    Node* _next;
    Node(): _data(T()), _next(nullptr) {}
    Node(const T& value): _data(value), _next(nullptr) {}
    Node(const Node& other): _data(other._data), _next(other._next) {}
};

template <class T>
class Iterator final {
  public:
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    template <class T1, class _Alloc1>
    friend class Stack;

  private:
    Node<T>* _node;

  public:
    Iterator() = delete;
    Iterator(Node<T>*);
    virtual ~Iterator() = default;

    Iterator& operator++() noexcept;
    Iterator operator++(int) noexcept;

    reference operator*();
    pointer operator->();
    const_reference operator*() const;
    const_pointer operator->() const;

    bool operator==(const Iterator&) const noexcept;
    bool operator!=(const Iterator&) const noexcept;
};

template <class T>
Iterator<T>::Iterator(Node<T>* node) :
    _node(node)
{
}

template <class T>
Iterator<T>& Iterator<T>::operator++() noexcept
{
    _node = _node->_next;
    return *this;
}

template <class T>
Iterator<T> Iterator<T>::operator++(int) noexcept
{
    Iterator<T> tmp = *this;
    ++(*this);
    return tmp;
}

template <class T>
typename Iterator<T>::reference Iterator<T>::operator*()
{
    return _node->_data;
}

template <class T>
typename Iterator<T>::pointer Iterator<T>::operator->()
{
    return &(_node->_data);
}

template <class T>
typename Iterator<T>::const_reference Iterator<T>::operator*() const
{
    return _node->_data;
}

template <class T>
typename Iterator<T>::const_pointer Iterator<T>::operator->() const
{
    return &(_node->_data);
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T>& other) const noexcept
{
    return &this->_node == &other._node;
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const noexcept
{
    return &this->_node != &other._node;
}
