#pragma once
#include <vector>
#include <stdlib.h>

template<typename T, std::size_t SIZE = 1024>
class Allocator{
public:

    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef std::size_t size_type;

    Allocator();

    T* allocate(std::size_t);
    void deallocate(T*, std::size_t) {}
    void clear();

    void destroy(T*);
    template<typename V, typename... Args>
    void construct(V*, Args&&...);
    void increase(std::size_t = 1024);

    template<class U>
    struct rebind {
        using other = Allocator<U>;
    };

    ~Allocator();

private:

    std::vector<T*> blocks;
    size_t offset = 0;

};

template<typename T, std::size_t SIZE>
Allocator<T, SIZE>::Allocator(){
    T* memmory = reinterpret_cast<T*>(malloc(sizeof(T)*SIZE));

    for(size_t i = 0; i < SIZE; ++i){
        blocks.push_back(memmory++);
    }

    this->offset = 0;
}

template<typename T, std::size_t SIZE>
Allocator<T,SIZE>::~Allocator(){
    this->clear();
}

template<typename T, std::size_t SIZE>
T* Allocator<T, SIZE>::allocate(std::size_t n){
    if(n == 0) return nullptr;

    if(blocks.size() - this->offset < n){
        this->offset = this->blocks.size();
        this->increase(n > 1024 ? n : 1024);
    }
    
    auto tempIt = this->blocks.begin();
    for(size_t i = 0; i < this->offset; ++i) ++tempIt;

    T* result = (*tempIt);
    this->offset += n;

    return result;
}

template<typename T, std::size_t SIZE>
void Allocator<T, SIZE>::clear(){
    auto it = blocks.begin();

    auto tempIt = this->blocks.begin();
    for(size_t i = 0; i < this->offset; ++i) ++tempIt;

    while(it != tempIt){
        (*it)->~T();
        ++it;
    }
}

template<typename T, std::size_t SIZE>
void Allocator<T, SIZE>::destroy(T* destroyObj){
    destroyObj->~T();
}

template<typename T, std::size_t SIZE>
template<typename V, typename... Args>
void Allocator<T, SIZE>::construct(V* otherTypePtr, Args&&... args){
    new(otherTypePtr) V(std::forward<Args>(args)...);
}

template<typename T, std::size_t SIZE>
void Allocator<T, SIZE>::increase(std::size_t addSize){
    T* memmory = reinterpret_cast<T*>(malloc(sizeof(T)*addSize));

    for(size_t i = 0; i < addSize; ++i){
        blocks.push_back(memmory++);
    }
}
