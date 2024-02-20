#pragma once
#include <gtest/gtest.h>
#include "../../include/Figures/Trapezoid.hpp"
#include "../../include/Vector.hpp"
#define EPS 1e-7

TEST(Trapezoid, moveOperator){
    ASSERT_NO_THROW({
        Trapezoid<double> trap({
            point<double>(0, 0),
            point<double>(2, 2),
            point<double>(4, 2),
            point<double>(6, 0)
        });
        trap = Trapezoid<double>();
        ASSERT_TRUE(trap == Trapezoid<double>());
    });
}

TEST(Trapezoid, copyOperator){
    ASSERT_NO_THROW({
        Trapezoid<double> trap({
            point<double>(0, 0),
            point<double>(2, 2),
            point<double>(4, 2),
            point<double>(6, 0)
        });
        Trapezoid<double> trap2;
        trap = trap2;
        ASSERT_TRUE(trap == trap2);
    });
}

TEST(Trapezoid, simpleCenter){
    ASSERT_TRUE(Trapezoid<double>().center() == point<double>(1.5f, 0.5f));
}

TEST(Trapezoid, difCenter){
    Trapezoid<double> trap({
        point<double>(2, 0),
        point<double>(4, 2),
        point<double>(6, 2),
        point<double>(8, 0)
    });

    ASSERT_TRUE(trap.center() == point<double>(5, 1));
}

TEST(Trapezoid, difCenter2){
    Trapezoid<double> trap({
        point<double>(0, 0),
        point<double>(3, -1),
        point<double>(4, -4),
        point<double>(2, -6)
    });
    ASSERT_TRUE(trap.center() == point<double>(2.25, -2.75));
}

TEST(Trapezoid, simpleArea){
    ASSERT_TRUE(fabs(static_cast<double>(Trapezoid<double>()) - 2) <= EPS);
}

TEST(Trapezoid, difArea){
    Trapezoid<double> trap({
        point<double>(2, 0),
        point<double>(4, 2),
        point<double>(6, 2),
        point<double>(8, 0)
    });
    ASSERT_TRUE(fabs(static_cast<double>(trap) - 8) <= EPS);
}

TEST(Trapezoid, difArea2){
    Trapezoid<double> trap({
        point<double>(0, 0),
        point<double>(3, -1),
        point<double>(4, -4),
        point<double>(2, -6)
    });
    ASSERT_TRUE(fabs(static_cast<double>(trap) - 15*sin(angle(Vector<double>(point<double>(0,0), point<double>(3, -1)), Vector<double>(point<double>(0,0), point<double>(2, -6))))) <= EPS);
}