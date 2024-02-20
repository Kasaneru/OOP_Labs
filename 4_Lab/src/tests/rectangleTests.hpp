#pragma once
#include "../../include/Figures/Rectangle.hpp"
#include <gtest/gtest.h>
#define EPS 1e-7

TEST(Rectangle, moveOperator){
    ASSERT_NO_THROW({
        Rectangle<double> rect({
            point<double>(0, 0),
            point<double>(0, 2),
            point<double>(2, 2),
            point<double>(2, 0)
        });
        rect = Rectangle<double>();
        ASSERT_TRUE(rect == Rectangle<double>());
    });
}

TEST(Rectangle, copyOperator){
    ASSERT_NO_THROW({
        Rectangle<double> rect({
            point<double>(0, 0),
            point<double>(0, 2),
            point<double>(2, 2),
            point<double>(2, 0)
        });
        Rectangle<double> rect2;
        rect = rect2;
        ASSERT_TRUE(rect == rect2);
    });
}

TEST(Rectangle, simpleCenter){
    ASSERT_TRUE(Rectangle<double>().center() == point<double>(0.5f, 0.5f));
}

TEST(Rectangle, difCenter){
    Rectangle<double> rect({
        point<double>(4, 0),
        point<double>(0, 4),
        point<double>(2, 6),
        point<double>(6, 2)
    });

    ASSERT_TRUE(rect.center() == point<double>(3, 3));
}

TEST(Rectangle, difCenter2){
    Rectangle<double> rect({
        point<double>(0, 0),
        point<double>(6, 1),
        point<double>(7, -5),
        point<double>(1, -6)
    });

    ASSERT_TRUE(rect.center() == point<double>(3.5, -2.5));
}

TEST(Rectangle, simpleArea){
    ASSERT_TRUE(static_cast<double>(Rectangle<double>()) == 1);
}

TEST(Rectangle, difArea){
    Rectangle<double> rect({
        point<double>(4, 0),
        point<double>(0, 4),
        point<double>(2, 6),
        point<double>(6, 2)
    });
    ASSERT_TRUE(fabs(static_cast<double>(rect) - 16) <= EPS);
}

TEST(Rectangle, difArea2){
    Rectangle<double> rect({
        point<double>(0, 0),
        point<double>(6, 1),
        point<double>(7, -5),
        point<double>(1, -6)
    });
    ASSERT_TRUE(fabs(static_cast<double>(rect) - 37) <= EPS);
}