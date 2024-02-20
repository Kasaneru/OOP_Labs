#pragma once
#include <gtest/gtest.h>
#include "../../include/Figures/Square.hpp"
#define EPS 1e-7

TEST(Square, moveOperator){
    ASSERT_NO_THROW({
        Square<double> square({
            point<double>(0, 0),
            point<double>(0, 2),
            point<double>(2, 2),
            point<double>(2, 0)
        });
        square = Square<double>();
        ASSERT_TRUE(square == Square<double>());
    });
}

TEST(Square, copyOperator){
    ASSERT_NO_THROW({
        Square<double> square2({
            point<double>(0, 0),
            point<double>(0, 2),
            point<double>(2, 2),
            point<double>(2, 0)
        });
        Square<double> square = square2;
        ASSERT_TRUE(square == square2);
    });
}

TEST(Square, simpleCenter){
    ASSERT_TRUE(Square<double>().center() == point<double>(0.5f, 0.5f));
}

TEST(Square, difCenter){
    Square<double> square({
        point<double>(2, 0),
        point<double>(2, 2),
        point<double>(4, 2),
        point<double>(4, 0)
    });
    ASSERT_TRUE(square.center() == point<double>(3, 1));
}

TEST(Square, difCenter2){
    Square<double> square({
        point<double>(0, 0),
        point<double>(3, 1),
        point<double>(6, 0),
        point<double>(3, -1)
    });
    ASSERT_TRUE(square.center() == point<double>(3, 0));
}

TEST(Square, simpleArea){
    ASSERT_TRUE(fabs((double)Square<double>() - 1) <= EPS);
}

TEST(Square, difArea){
    Square<double> square({
        point<double>(2, 0),
        point<double>(2, 2),
        point<double>(4, 2),
        point<double>(4, 0)
    });
    ASSERT_TRUE(fabs(static_cast<double>(square) - 4) <= EPS);
}

TEST(Square, difArea2){
    Square<double> square({
        point<double>(0, 0),
        point<double>(3, 1),
        point<double>(6, 0),
        point<double>(3, -1)
    });
    ASSERT_TRUE(fabs(static_cast<double>(square) - 6) <= EPS);
}
