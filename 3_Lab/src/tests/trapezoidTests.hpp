#pragma once
#include <gtest/gtest.h>
#include "../../include/Figures/Trapezoid.hpp"
#include "../../include/Vector.hpp"
#define EPS 1e-7

TEST(Trapezoid, moveOperator){
    ASSERT_NO_THROW({
        Trapezoid trap({
            point(0, 0),
            point(2, 2),
            point(4, 2),
            point(6, 0)
        });
        trap = Trapezoid();
        ASSERT_TRUE(trap == Trapezoid());
    });
}

TEST(Trapezoid, copyOperator){
    ASSERT_NO_THROW({
        Trapezoid trap({
            point(0, 0),
            point(2, 2),
            point(4, 2),
            point(6, 0)
        });
        Trapezoid trap2;
        trap = trap2;
        ASSERT_TRUE(trap == trap2);
    });
}

TEST(Trapezoid, simpleCenter){
    ASSERT_TRUE(Trapezoid().center() == point(1.5f, 0.5f));
}

TEST(Trapezoid, difCenter){
    Trapezoid trap({
        point(2, 0),
        point(4, 2),
        point(6, 2),
        point(8, 0)
    });

    ASSERT_TRUE(trap.center() == point(5, 1));
}

TEST(Trapezoid, difCenter2){
    Trapezoid trap({
        point(0, 0),
        point(3, -1),
        point(4, -4),
        point(2, -6)
    });
    ASSERT_TRUE(trap.center() == point(2.25, -2.75));
}

TEST(Trapezoid, simpleArea){
    ASSERT_TRUE(fabs(static_cast<double>(Trapezoid()) - 2) <= EPS);
}

TEST(Trapezoid, difArea){
    Trapezoid trap({
        point(2, 0),
        point(4, 2),
        point(6, 2),
        point(8, 0)
    });
    ASSERT_TRUE(fabs(static_cast<double>(trap) - 8) <= EPS);
}

TEST(Trapezoid, difArea2){
    Trapezoid trap({
        point(0, 0),
        point(3, -1),
        point(4, -4),
        point(2, -6)
    });
    ASSERT_TRUE(fabs(static_cast<double>(trap) - 15*sin(angle(Vector(point(0,0), point(3, -1)), Vector(point(0,0), point(2, -6))))) <= EPS);
}