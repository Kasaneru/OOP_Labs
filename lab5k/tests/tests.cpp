#include <gtest/gtest.h>

#include "../include/allocator.hpp"
#include "../src/allocator.cpp"
#include "../include/vector.hpp"

TEST(AllocatorTestSet, allocateTest) {
    Allocator<int, 2> allocator;

    int* pint = allocator.allocate(1);

    EXPECT_NE(pint, nullptr);
    EXPECT_THROW(allocator.allocate(999999), std::bad_alloc);

    allocator.deallocate(pint, 1);
}

TEST(constructor, def_constructor) {
    Vector<int> a;
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
