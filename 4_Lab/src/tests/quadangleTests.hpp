#pragma once
#include <gtest/gtest.h>
#include "../../include/Figures/Quadangle.hpp"

TEST(Quadangle, defaultConstructor){
    ASSERT_NO_THROW(Quadangle<double>());
}

TEST(Quadangle, arrayConstructor){
    ASSERT_NO_THROW(Quadangle<double>(Array<point<double>>{
        point<double>(0, 0),
        point<double>(0, 1),
        point<double>(1, 1),
        point<double>(1, 0)
    }););
}

TEST(Quadangle, zeroArrayConstructor){
    ASSERT_ANY_THROW(Quadangle<double>(Array<point<double>>()));
}

TEST(Quadangle, moreArrayConstructor){
    ASSERT_ANY_THROW(Quadangle<double>(Array<point<double>>{
        point<double>(0, 0),
        point<double>(0, 1),
        point<double>(1, 1),
        point<double>(1, 0),
        point<double>(0, 0),
        point<double>(0, 1),
        point<double>(1, 1),
        point<double>(1, 0)
    }));
}

TEST(Quadangle, arrayZeroPointsConstructor){
    ASSERT_ANY_THROW(Quadangle<double>(Array<point<double>>({
        point<double>(0, 0),
        point<double>(0, 0),
        point<double>(0, 0),
        point<double>(0, 0)
    })););
}

TEST(Quadangle, arrayNonConvexConstructor){
    ASSERT_ANY_THROW(Quadangle<double>(Array<point<double>>({
        point<double>(0, 0),
        point<double>(0, 1),
        point<double>(1, -1),
        point<double>(-1, 0)
    })););
}

TEST(Quadangle, listConstructor){
    ASSERT_NO_THROW(Quadangle<double>({
        point<double>(0, 0),
        point<double>(0, 1),
        point<double>(1, 1),
        point<double>(1, 0)
    }));
}

TEST(Quadangle, zeroListConstructor){
    ASSERT_ANY_THROW(Quadangle<double>({}));
}

TEST(Quadangle, moreListConstructor){
    ASSERT_ANY_THROW(Quadangle<double>({
        point<double>(0, 0),
        point<double>(0, 1),
        point<double>(1, 1),
        point<double>(1, 0),
        point<double>(0, 0),
        point<double>(0, 1),
        point<double>(1, 1),
        point<double>(1, 0)
    }));
}

TEST(Quadnagle, listZeroPointsContcructor){
    ASSERT_ANY_THROW(Quadangle<double>({
        point<double>(0, 0),
        point<double>(0, 0),
        point<double>(0, 0),
        point<double>(0, 0)
    }););
}

TEST(Quadangle, listZeroConstuctor){
    ASSERT_ANY_THROW(Quadangle<double>({
        point<double>(0, 0),
        point<double>(0, 0),
        point<double>(0, 0),
        point<double>(0, 0)
    }));
}

TEST(Quadangle, listNonConvexConstructor){
    ASSERT_ANY_THROW(Quadangle<double>({
        point<double>(0, 0),
        point<double>(0, 1),
        point<double>(1, -1),
        point<double>(-1, 0)
    }));
}

TEST(Quadangle, copyConstructor){
    Quadangle<double> rect;
    ASSERT_NO_THROW(Quadangle<double>(rect););
}

TEST(Quadangle, moveConstructor){
    ASSERT_NO_THROW(Quadangle<double>(Quadangle<double>()));
}

TEST(Quadangle, simpleEqualsOperator){
    ASSERT_TRUE(Quadangle<double>() == Quadangle<double>());
}

TEST(Quadangle, difEqualsOperator){
    ASSERT_NO_THROW(
        Quadangle<double> quad1({
            point<double>(0, 0),
            point<double>(0, 2),
            point<double>(2, 2),
            point<double>(2, 0)
        });
        Quadangle<double> quad2({
            point<double>(0, 0),
            point<double>(0, 2),
            point<double>(2, 2),
            point<double>(2, 0)
        });
        ASSERT_TRUE(quad1 == quad2);
    );
}

TEST(Quadangle, simpleNonEquals){
    ASSERT_NO_THROW(
        Quadangle<double> quad({
            point<double>(0, 0),
            point<double>(0, 2),
            point<double>(2, 2),
            point<double>(2, 0)
        });
        ASSERT_FALSE(quad == Quadangle<double>());
    );
}

TEST(Quadangle, difNonEquals){
    ASSERT_NO_THROW(
        Quadangle<double> quad1({
            point<double>(0, 0),
            point<double>(0, 2),
            point<double>(2, 2),
            point<double>(2, 0)
        });
        Quadangle<double> quad2({
            point<double>(0, 0),
            point<double>(0, 4),
            point<double>(4, 4),
            point<double>(4, 0)
        });
        ASSERT_FALSE(quad1 == quad2);
    );
}