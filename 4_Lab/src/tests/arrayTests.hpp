#pragma once
#include <gtest/gtest.h>
#include "../../include/Containers/Array.hpp"

TEST(Array, defaultConstructor){
    ASSERT_NO_THROW(Array<int> arr;);
}

TEST(Array, sizeConstuctor){
    ASSERT_NO_THROW(Array<int> arr(10););
}

TEST(Array, bigSizeConstructor){
    ASSERT_NO_THROW(Array<int> arr(1000000, 1););
}

TEST(Array, zeroConstructor){
    ASSERT_NO_THROW(Array<int> arr(0););
}

TEST(Array, listConstructor){
    ASSERT_NO_THROW(Array<int> arr({1, 2, 3, 4, 5, 6}););
}

TEST(Array, zeroListConsructor){
    ASSERT_NO_THROW(Array<int> arr({}););
}

TEST(Array, copyConstructor){
    Array<int> arr1({1,2,3,4,5});
    ASSERT_NO_THROW(
        Array<int> arr2(arr1);
        ASSERT_TRUE(arr1 == arr2);
    );   
}

TEST(Array, copyZeroConstructor){
    Array<int> arr1({});
    ASSERT_NO_THROW(
        Array<int> arr2(arr1);
        ASSERT_TRUE(arr1 == arr2);
    );
}

TEST(Array, moveConstructor){
    ASSERT_NO_THROW(
        Array<int> arr(Array<int>({1,2,3,4,5}));
        Array<int> arr2({1, 2, 3, 4, 5});
        ASSERT_TRUE(arr == arr2);
    );
}

TEST(Array, moveZeroConstructor){
    ASSERT_NO_THROW(
        Array<int> arr(Array<int>({}));
        Array<int> arr2;
        ASSERT_TRUE(arr == arr2);
    );
}

TEST(Array, copyOperator){
    Array<int> arr1({1,2,3,4,5});
    Array<int> arr2({23,4,2,13,3});
    ASSERT_NO_THROW({
        arr1 = arr2;
        ASSERT_TRUE(arr1 == arr2);
    });
}

TEST(Array, moveOperator){
    Array<int> arr1({23,1,424,1});
    ASSERT_NO_THROW({
        arr1 = Array<int>({1,2,34,5,6});
        ASSERT_TRUE(arr1 == Array<int>({1, 2, 34, 5, 6}));
    });
}

TEST(Array, pushBack){
    Array<int> arr;
    ASSERT_NO_THROW(arr.push_back(1););
    ASSERT_TRUE(arr == Array<int>({1}));
    ASSERT_TRUE(arr.size() == 1);
}

TEST(Array, bigSizePushBack){
    Array<int> arr;
    ASSERT_NO_THROW({
        for(size_t _ = 0; _ < 100000; ++_){
            arr.push_back(1);
        }
        ASSERT_TRUE(arr.size() == 100000);
    });
}

TEST(Array, popBack){
    Array<int> arr(1);
    ASSERT_NO_THROW(arr.pop_back(););
    ASSERT_TRUE(arr == Array<int>());
    ASSERT_TRUE(arr.size() == 0);
}

TEST(Array, bigSizePopBack){
    Array<int> arr(100000);
    ASSERT_NO_THROW({
        for(size_t _ = 0; _ < 100000; ++_){
            arr.pop_back();
        }
    });
    ASSERT_TRUE(arr.size() == 0);
}

TEST(Array, zeroSizePopBack){
    Array<int> arr;
    ASSERT_NO_THROW(arr.pop_back(););
}

TEST(Array, zeroSize){
    ASSERT_TRUE(Array<int>().size() == 0);
}

TEST(Array, size){
    ASSERT_TRUE(Array<int>({1,2,3,4,56,5}).size() == 6);
}

TEST(Array, pushBackSize){
    Array<int> arr;
    for(size_t _ = 0; _ < 100000; ++_){
        arr.push_back(1);
    }
    ASSERT_TRUE(arr.size() == 100000);
}

TEST(Array, operatorAt){
    ASSERT_TRUE(Array<int>({1,2,3,4})[2] == 3);
}

/*TEST(Array, outOfBordersAt){
    ASSERT_ANY_THROW(Array<int>({1,2,3}).at(-1););
    ASSERT_ANY_THROW(Array<int>({1,2,3}).at(4););
}*/

TEST(Array, back){
    ASSERT_TRUE(Array<int>({1,2,3,4}).back() == 4);
}

TEST(Array, zeroSizeBack){
    ASSERT_ANY_THROW(Array<int>().back(););
}

TEST(Array, bigSizeEquals){
    Array<int> arr1, arr2;
    for(size_t i = 0; i < 100000; ++i){
        arr1.push_back(i*8%56 + i); arr2.push_back(i*8%56 + i);
    }
    ASSERT_TRUE(arr1 == arr2);
}

TEST(Array, bigSizedNotEquals){
    Array<int> arr1, arr2;
    for(size_t i = 0; i < 100000; ++i){
        arr1.push_back(i*8%56 + i); arr2.push_back(i*7%56 + i);
    }
    ASSERT_FALSE(arr1 == arr2);
}

TEST(Array, resizeIncrease){
    Array<int> arr(50000);
    ASSERT_NO_THROW(arr.resize(100000););
}

TEST(Array, resizeZeroDown){
    Array<int> arr(50000);
    ASSERT_NO_THROW(arr.resize(0););
}

TEST(Array, reserveIncrease){
    Array<int> arr(5000);
    ASSERT_NO_THROW(arr.reserve(100000););
}

TEST(Array, reserveOnDown){
    Array<int> arr(5000);
    ASSERT_NO_THROW(arr.reserve(0););
}

TEST(Array, del){
    Array<int> arr;
    for(size_t index = 0; index < 10000; ++index){
        arr.push_back(index);
    }
    arr.del(0);
    ASSERT_TRUE(arr[0] == 1);
}

TEST(Array, delMidle){
    Array<int> arr({1, 2, 3, 4, 5, 6});
    arr.del(3);
    ASSERT_TRUE(arr == Array<int>({1, 2, 3, 5, 6}));
}

TEST(Array, delOutOfBorders){
    Array<int> arr({1});
    ASSERT_ANY_THROW(arr.del(2));
    ASSERT_ANY_THROW(arr.del(-1));
}