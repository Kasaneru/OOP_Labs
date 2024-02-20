#pragma once
#include <gtest/gtest.h>
#include "../../include/Allocator.hpp"

TEST(Allocator, defaultConstructor){
    ASSERT_NO_THROW({
        Allocator<int> alloc;
    });
}

/*TEST(Allocator, zeroConstructor){
    ASSERT_NO_THROW({Allocator<int, 0> alloc;});
}

TEST(Allocator, bigSizedConstructor){
    ASSERT_NO_THROW({Allocator<int, 100000> alloc;});
}*/

TEST(Allocator, clear){
    ASSERT_NO_THROW({
        Allocator<int> alloc;
        alloc.clear();
    });
}

TEST(Allocator, destroy){
    ASSERT_NO_THROW({
        int a;
        Allocator<int> alloc;
        alloc.destroy(&a);
    });
}

TEST(Allocator, increase){
    ASSERT_NO_THROW({
        Allocator<int> alloc;
        alloc.increase();
    });
}

TEST(Allocator, increaseBigSized){
    ASSERT_NO_THROW({
        Allocator<int> alloc;
        alloc.increase(500000);
    });
}