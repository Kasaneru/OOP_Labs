#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <cstddef>
#include <cstdint>
#include <vector>

template<class T, size_t CHUNK_SZ = 1024>
class Allocator {
private:
    std::vector<T> _used_chunks;
    std::vector<void*> _free_chunks;
    size_t _free_amount;

public:
    Allocator();

    T* allocate(size_t);
    void deallocate(T*, size_t);

    template <class T1, class... Args>
    void construct(T1*, Args&&...);

    void destroy(T*);

    virtual ~Allocator() noexcept;
};

#endif // ALLOCATOR_HPP

