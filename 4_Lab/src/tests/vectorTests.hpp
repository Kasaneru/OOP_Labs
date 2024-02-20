#pragma once
#include <gtest/gtest.h>
#include "../../include/Vector.hpp"

TEST(Vector, defaultConstructor){
    ASSERT_NO_THROW(Vector<double>(););
}


TEST(Vector, oneParameterConstructor){
    ASSERT_NO_THROW(Vector<double>(1));
}

TEST(Vector, fullParameterConstructor){
    ASSERT_NO_THROW(Vector<double>(1, 1));
}

TEST(Vector, pointsConstructor){
    point<double> p1(1, 1);
    point<double> p2(1, 1);
    ASSERT_NO_THROW(
        Vector<double> vec(p1, p2);
        ASSERT_TRUE(vec == Vector<double>());
    );
}

TEST(Vector, multiplicateOperator){
    Vector<double> vec(1, 0.5);
    ASSERT_NO_THROW(
        ASSERT_TRUE((Vector<double>(1, 1)*Vector<double>(0, 1)) == 1);
    );
}

TEST(Vector, zeroMultiplication){
    Vector<double> vec(1, 1);
    ASSERT_NO_THROW(
        ASSERT_TRUE((Vector<double>()*Vector<double>(1,1)) == 0);
    );
}

TEST(Vector, minusMultiplication){
    Vector<double> vec(1, 1);
    ASSERT_NO_THROW(
        ASSERT_TRUE((Vector<double>(1, 1)*Vector<double>(-1, -1)) == -2);
    );
}

TEST(Vector, simpleEquals){
    Vector<double> vec(0, 0);
    ASSERT_TRUE(vec == Vector<double>());
}

TEST(Vector, difEquals){
    Vector<double> vec(5, 10);
    Vector<double> vec2(5, 10);
    ASSERT_TRUE(vec == vec2);
}

TEST(Vector, dontEquals){
    Vector<double> vec(1, 2);
    Vector<double> vec2(5, 10);
    ASSERT_FALSE(vec == vec2);
}

TEST(angle, nintyDegries){
    ASSERT_NO_THROW(
        ASSERT_TRUE(angle(Vector<double>(1, 0), Vector<double>(0, 1)) == (M_PI / 2));
    );
}

TEST(angle, sixtyDegries){
    ASSERT_NO_THROW(
        ASSERT_TRUE(angle(Vector<double>(1, 0), Vector<double>(0.5, sqrt(3)/2)) == (M_PI / 3));
    );
}

TEST(angle, thirdtyDegries){
    ASSERT_NO_THROW(
        ASSERT_DOUBLE_EQ(angle(Vector<double>(1, 0), Vector<double>(sqrt(3)/2, 0.5)), (M_PI / 6));
    );
}

TEST(len, zeroVector){
    ASSERT_TRUE(len(Vector<double>()) == 0);
}

TEST(len, simlpeVector){
    ASSERT_TRUE(len(Vector<double>(1, 0)) == 1);
}

TEST(len, difVector){
    ASSERT_TRUE(len(Vector<double>(3, 4)) == 5);
}

TEST(point, defaultConstructor){
    ASSERT_NO_THROW(point<double>());
}

TEST(point, oneParameterCOnstructor){
    ASSERT_NO_THROW(point<double>(1));
}

TEST(point, fullConstructor){
    ASSERT_NO_THROW(point<double>(1, 1));
}