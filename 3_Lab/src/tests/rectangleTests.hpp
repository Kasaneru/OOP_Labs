#pragma once
#include "../../include/Figures/Rectangle.hpp"
#include <gtest/gtest.h>
#define EPS 1e-7

TEST(Rectangle, moveOperator){
    ASSERT_NO_THROW({
        Rectangle rect({
            point(0, 0),
            point(0, 2),
            point(2, 2),
            point(2, 0)
        });
        rect = Rectangle();
        ASSERT_TRUE(rect == Rectangle());
    });
}

TEST(Rectangle, copyOperator){
    ASSERT_NO_THROW({
        Rectangle rect({
            point(0, 0),
            point(0, 2),
            point(2, 2),
            point(2, 0)
        });
        Rectangle rect2;
        rect = rect2;
        ASSERT_TRUE(rect == rect2);
    });
}

TEST(Rectangle, simpleCenter){
    ASSERT_TRUE(Rectangle().center() == point(0.5f, 0.5f));
}

TEST(Rectangle, difCenter){
    Rectangle rect({
        point(4, 0),
        point(0, 4),
        point(2, 6),
        point(6, 2)
    });

    ASSERT_TRUE(rect.center() == point(3, 3));
}

TEST(Rectangle, difCenter2){
    Rectangle rect({
        point(0, 0),
        point(6, 1),
        point(7, -5),
        point(1, -6)
    });

    ASSERT_TRUE(rect.center() == point(3.5, -2.5));
}

TEST(Rectangle, simpleArea){
    ASSERT_TRUE(static_cast<double>(Rectangle()) == 1);
}

TEST(Rectangle, difArea){
    Rectangle rect({
        point(4, 0),
        point(0, 4),
        point(2, 6),
        point(6, 2)
    });
    ASSERT_TRUE(fabs(static_cast<double>(rect) - 16) <= EPS);
}

TEST(Rectangle, difArea2){
    Rectangle rect({
        point(0, 0),
        point(6, 1),
        point(7, -5),
        point(1, -6)
    });
    ASSERT_TRUE(fabs(static_cast<double>(rect) - 37) <= EPS);
}