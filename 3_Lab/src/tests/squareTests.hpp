#pragma once
#include <gtest/gtest.h>
#include "../../include/Figures/Square.hpp"
#define EPS 1e-7

TEST(Square, moveOperator){
    ASSERT_NO_THROW({
        Square sqr({
            point(0, 0),
            point(0, 2),
            point(2, 2),
            point(2, 0)
        });
        sqr = Square();
        ASSERT_TRUE(sqr == Square());
    });
}

TEST(Square, copyOperator){
    ASSERT_NO_THROW({
        Square sqr2({
            point(0, 0),
            point(0, 2),
            point(2, 2),
            point(2, 0)
        });
        Square sqr = sqr2;
        ASSERT_TRUE(sqr == sqr2);
    });
}

TEST(Square, simpleCenter){
    ASSERT_TRUE(Square().center() == point(0.5f, 0.5f));
}

TEST(Square, difCenter){
    Square sqr({
        point(2, 0),
        point(2, 2),
        point(4, 2),
        point(4, 0)
    });
    ASSERT_TRUE(sqr.center() == point(3, 1));
}

TEST(Square, difCenter2){
    Square sqr({
        point(0, 0),
        point(3, 1),
        point(6, 0),
        point(3, -1)
    });
    ASSERT_TRUE(sqr.center() == point(3, 0));
}

TEST(Square, simpleArea){
    ASSERT_TRUE(fabs((double)Square() - 1) <= EPS);
}

TEST(Square, difArea){
    Square sqr({
        point(2, 0),
        point(2, 2),
        point(4, 2),
        point(4, 0)
    });
    ASSERT_TRUE(fabs(static_cast<double>(sqr) - 4) <= EPS);
}

TEST(Square, difArea2){
    Square sqr({
        point(0, 0),
        point(3, 1),
        point(6, 0),
        point(3, -1)
    });
    ASSERT_TRUE(fabs(static_cast<double>(sqr) - 6) <= EPS);
}
