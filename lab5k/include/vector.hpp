#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "allocator.hpp"
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <climits>
#include <stdexcept>

template<typename T, class Allocator = std::allocator<T>>
class Vector {
protected:
    T* arr;
    size_t sz;
    size_t cap;
    Allocator alloc;

public:
    Vector();
    Vector(const Vector& other);
    // Vector(const std::initializer_list<T>& init);

    // void reserve(size_t new_cap);
    // void resize(size_t new_sz, const T& value = T());

    // void push_back(const T& value);
    // template<typename... Args>
    // void emplace_back(const Args& ...args); 
    // void pop_back();
    // 
    // T& at(size_t idx);
    // T& front();
    // T& back();
    // bool empty();
    // size_t size() const;
    // size_t capacity() const;

    // T& operator[](size_t idx) const;
    // bool operator==(const Vector<T>& other_vector);
    // bool operator!=(const Vector<T>& other_vector);

    // void shrink_to_fit();
    void clear();
    ~Vector();
};

template<typename T, class Allocator>
Vector<T, Allocator>::Vector() {
    arr = alloc.allocate(1);
    sz = 0;
    cap = 1;
}

template<typename T, class Allocator>
Vector<T, Allocator>::Vector(const Vector<T, Allocator>& other) {
    sz = other.sz;
    cap = other.cap;
    T* new_arr = alloc.allocate(cap);
    std::copy(other.arr, other.arr + other.sz, new_arr);
    arr = new_arr;
}

// template<typename T, class Allocator>
// Vector<T, Allocator>::Vector(const std::initializer_list<T>& init) {
//     T* new_arr = reinterpret_cast<T*>(new char[init.size() * sizeof(T)]);
//     try {
//         std::uninitialized_copy(init.begin(), init.end(), new_arr);
//     } catch (...) {
//         delete[] reinterpret_cast<char*>(new_arr);
//         throw;
//     }
//     arr = new_arr;
//     cap = init.size();
//     sz = init.size();
// }
// 
// template<typename T, class Allocator>
// void Vector<T, Allocator>::reserve(size_t new_cap) {
//     if (new_cap > UINT_MAX) {
//         throw std::range_error("Capacity overflow!");
//     }
//     if (new_cap < cap) {
//         return;
//     }
//     T* new_arr = reinterpret_cast<T*>(new char[new_cap * sizeof(T)]);
//     try {
//         std::uninitialized_copy(arr, arr+sz, new_arr);
//     } catch (...) {
//         delete[] reinterpret_cast<char*>(new_arr);
//         throw;
//     }
//     for (size_t i = 0; i < sz; ++i) {
//         arr[i].~T();
//     }
//     delete[] reinterpret_cast<char*>(arr);
//     arr = new_arr;
//     cap = new_cap;
// }
// 
// template<typename T, class Allocator>
// void Vector<T, Allocator>::resize(size_t new_sz, const T& value) {
//     if (new_sz > UINT_MAX) {
//         throw std::range_error("Capacity overflow!");
//     }
//     if (new_sz > cap) {
//         reserve(new_sz);
//     }
//     if (new_sz < sz) {
//         for (size_t i = new_sz; i < sz; ++i) {
//             arr[i].~T();
//         }
//     }
//     if (new_sz > sz) {
//         for (size_t i = sz; i < new_sz; ++i) {
//             new(arr + i) T(value);
//         }
//     }
//     sz = new_sz;
// }
// 
// template<typename T>
// void Vector<T>::push_back(const T& value) {
//     if (sz == cap) {
//         reserve(cap * 2);
//     }
//     new(arr + sz) T(value);
//     ++sz;
// }
// 
// template<typename T>
// template<typename... Args>
// void Vector<T>::emplace_back(const Args& ...args) {
//     if (sz == cap) {
//         reserve(cap * 2);
//     }
//     new(arr + sz) T(args...);
//     ++sz;
// }
// 
// template<typename T>
// void Vector<T>::pop_back() {
//     if (sz == 0)
//         return;
//     --sz;
//     arr[sz].~T();
// }
// 
// template<typename T>
// T& Vector<T>::at(size_t idx) {
//     if (idx >= sz) 
//         throw std::out_of_range("Index out of range");
//     return arr[idx];
// }
// 
// template<typename T>
// T& Vector<T>::front() {
//     return arr[0];
// }
// 
// template<typename T>
// T& Vector<T>::back() {
//     return arr[sz-1];
// }
// 
// template<typename T>
// bool Vector<T>::empty() {
//     return sz == 0;
// }
// 
// template<typename T>
// size_t Vector<T>::size() const {
//     return sz;
// }
// 
// template<typename T>
// size_t Vector<T>::capacity() const {
//     return cap;
// }
// 
// template<typename T>
// T& Vector<T>::operator[](size_t idx) const{
//     return arr[idx];
// }
// 
// template<typename T>
// bool Vector<T>::operator==(const Vector<T> &other_vector) {
//     if (sz != other_vector.sz)
//         return false;
//     for (size_t i = 0; i < sz; ++i) {
//         if (arr[i] != other_vector.arr[i])
//             return false;
//     } 
//     return true;
// }
// 
// template<typename T>
// bool Vector<T>::operator!=(const Vector<T> &other_vector) {
//     return !operator==(other_vector);
// }
// 
// template<typename T>
// void Vector<T>::shrink_to_fit() {
//     for (size_t i = sz; i < cap; ++i) {
//         arr[i].~T();
//     }
//     cap = sz;
//     if (cap == 0) {
//         cap = 1;
//     }
// }
// 
template<typename T, class Allocator>
void Vector<T, Allocator>::clear() {
    for (size_t i = 0; i < cap; ++i) {
        arr[i].~T();
    }
    sz = 0;
}

template<typename T, class Allocator>
Vector<T, Allocator>::~Vector() {
    clear();
    delete[] reinterpret_cast<char*>(arr);
}

#endif // VECTOR_HPP
