#pragma once
#include <gtest/gtest.h>
#include "../../include/Vector.hpp"

TEST(Vector, defaultConstructor){
    ASSERT_NO_THROW(Vector(););
}


TEST(Vector, oneParameterConstructor){
    ASSERT_NO_THROW(Vector(1));
}

TEST(Vector, fullParameterConstructor){
    ASSERT_NO_THROW(Vector(1, 1));
}

TEST(Vector, pointsConstructor){
    point p1(1, 1);
    point p2(1, 1);
    ASSERT_NO_THROW(
        Vector vec(p1, p2);
        ASSERT_TRUE(vec == Vector());
    );
}

TEST(Vector, multiplicateOperator){
    Vector vec(1, 0.5);
    ASSERT_NO_THROW(
        ASSERT_TRUE((Vector(1, 1)*Vector(0, 1)) == 1);
    );
}

TEST(Vector, zeroMultiplication){
    Vector vec(1, 1);
    ASSERT_NO_THROW(
        ASSERT_TRUE((Vector()*Vector(1,1)) == 0);
    );
}

TEST(Vector, minusMultiplication){
    Vector vec(1, 1);
    ASSERT_NO_THROW(
        ASSERT_TRUE((Vector(1, 1)*Vector(-1, -1)) == -2);
    );
}

TEST(Vector, simpleEquals){
    Vector vec(0, 0);
    ASSERT_TRUE(vec == Vector());
}

TEST(Vector, difEquals){
    Vector vec(5, 10);
    Vector vec2(5, 10);
    ASSERT_TRUE(vec == vec2);
}

TEST(Vector, dontEquals){
    Vector vec(1, 2);
    Vector vec2(5, 10);
    ASSERT_FALSE(vec == vec2);
}

TEST(angle, nintyDegries){
    ASSERT_NO_THROW(
        ASSERT_TRUE(angle(Vector(1, 0), Vector(0, 1)) == (M_PI / 2));
    );
}

TEST(angle, sixtyDegries){
    ASSERT_NO_THROW(
        ASSERT_TRUE(angle(Vector(1, 0), Vector(0.5, sqrt(3)/2)) == (M_PI / 3));
    );
}

TEST(angle, thirdtyDegries){
    ASSERT_NO_THROW(
        ASSERT_DOUBLE_EQ(angle(Vector(1, 0), Vector(sqrt(3)/2, 0.5)), (M_PI / 6));
    );
}

TEST(len, zeroVector){
    ASSERT_TRUE(len(Vector()) == 0);
}

TEST(len, simlpeVector){
    ASSERT_TRUE(len(Vector(1, 0)) == 1);
}

TEST(len, difVector){
    ASSERT_TRUE(len(Vector(3, 4)) == 5);
}

TEST(point, defaultConstructor){
    ASSERT_NO_THROW(point());
}

TEST(point, oneParameterCOnstructor){
    ASSERT_NO_THROW(point(1));
}

TEST(point, fullConstructor){
    ASSERT_NO_THROW(point(1, 1));
}