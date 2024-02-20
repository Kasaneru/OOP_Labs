#include "../include/allocator.hpp"
#include <cstddef>
#include <new>

template<class T, size_t CHUNK_SZ>
Allocator<T, CHUNK_SZ>::Allocator() {
    static_assert(CHUNK_SZ > 0);
    _used_chunks.resize(CHUNK_SZ);
    _free_chunks.resize(CHUNK_SZ);
    
    for (size_t i = 0; i != CHUNK_SZ; ++i) {
        _free_chunks[i] = &(_used_chunks[i]);
    }
    _free_amount = CHUNK_SZ;
}

template<class T, size_t CHUNK_SZ>
Allocator<T, CHUNK_SZ>::~Allocator() noexcept {
    _used_chunks.clear();
    _free_chunks.clear();
}

template<class T, size_t CHUNK_SZ>
T* Allocator<T, CHUNK_SZ>::allocate(size_t sz) {
    if (sz == 0)
        return nullptr;

    if (sz > _free_amount) {
        throw std::bad_alloc();
    }

    _free_amount -= sz;
    return static_cast<T*>(_free_chunks[_free_amount]);
}

template<class T, size_t CHUNK_SZ>
void Allocator<T, CHUNK_SZ>::deallocate(T* _T, size_t sz) {
    if (_T == nullptr or sz == 0)
        return;
    
    if (_free_amount + sz > CHUNK_SZ) {
        throw std::bad_alloc();
    }

    for (size_t i = 0; i != sz; ++i) {
        _free_chunks[_free_amount + i] = _T + i;
    }
    
    _free_amount += sz;
}

template<class T, size_t CHUNK_SZ>
template <class T1, class... Args>
void Allocator<T, CHUNK_SZ>::construct(T1* _T, Args &&... _args) {
    new (_T) T1(std::forward<Args>(_args)...);
}

template<class T, size_t CHUNK_SZ>
void Allocator<T, CHUNK_SZ>::destroy(T* _T) {
    _T->~T();
}
