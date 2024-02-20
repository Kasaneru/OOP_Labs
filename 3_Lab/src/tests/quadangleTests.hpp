#pragma once
#include <gtest/gtest.h>
#include "../../include/Figures/Quadangle.hpp"

TEST(Quadangle, defaultConstructor){
    ASSERT_NO_THROW(Quadangle());
}

TEST(Quadangle, arrayConstructor){
    ASSERT_NO_THROW(Quadangle(Array<point>{
        point(0, 0),
        point(0, 1),
        point(1, 1),
        point(1, 0)
    }););
}

TEST(Quadangle, zeroArrayConstructor){
    ASSERT_ANY_THROW(Quadangle(Array<point>()));
}

TEST(Quadangle, moreArrayConstructor){
    ASSERT_ANY_THROW(Quadangle(Array<point>{
        point(0, 0),
        point(0, 1),
        point(1, 1),
        point(1, 0),
        point(0, 0),
        point(0, 1),
        point(1, 1),
        point(1, 0)
    }));
}

TEST(Quadangle, arrayZeroPointsConstructor){
    ASSERT_ANY_THROW(Quadangle(Array<point>({
        point(0, 0),
        point(0, 0),
        point(0, 0),
        point(0, 0)
    })););
}

TEST(Quadangle, arrayNonConvexConstructor){
    ASSERT_ANY_THROW(Quadangle(Array<point>({
        point(0, 0),
        point(0, 1),
        point(1, -1),
        point(-1, 0)
    })););
}

TEST(Quadangle, listConstructor){
    ASSERT_NO_THROW(Quadangle({
        point(0, 0),
        point(0, 1),
        point(1, 1),
        point(1, 0)
    }));
}

TEST(Quadangle, zeroListConstructor){
    ASSERT_ANY_THROW(Quadangle({}));
}

TEST(Quadangle, moreListConstructor){
    ASSERT_ANY_THROW(Quadangle({
        point(0, 0),
        point(0, 1),
        point(1, 1),
        point(1, 0),
        point(0, 0),
        point(0, 1),
        point(1, 1),
        point(1, 0)
    }));
}

TEST(Quadnagle, listZeroPointsContcructor){
    ASSERT_ANY_THROW(Quadangle({
        point(0, 0),
        point(0, 0),
        point(0, 0),
        point(0, 0)
    }););
}

TEST(Quadangle, listZeroConstuctor){
    ASSERT_ANY_THROW(Quadangle({
        point(0, 0),
        point(0, 0),
        point(0, 0),
        point(0, 0)
    }));
}

TEST(Quadangle, listNonConvexConstructor){
    ASSERT_ANY_THROW(Quadangle({
        point(0, 0),
        point(0, 1),
        point(1, -1),
        point(-1, 0)
    }));
}

TEST(Quadangle, copyConstructor){
    Quadangle rect;
    ASSERT_NO_THROW(Quadangle(rect););
}

TEST(Quadangle, moveConstructor){
    ASSERT_NO_THROW(Quadangle(Quadangle()));
}

TEST(Quadangle, simpleEqualsOperator){
    ASSERT_TRUE(Quadangle() == Quadangle());
}

TEST(Quadangle, difEqualsOperator){
    ASSERT_NO_THROW(
        Quadangle quad1({
            point(0, 0),
            point(0, 2),
            point(2, 2),
            point(2, 0)
        });
        Quadangle quad2({
            point(0, 0),
            point(0, 2),
            point(2, 2),
            point(2, 0)
        });
        ASSERT_TRUE(quad1 == quad2);
    );
}

TEST(Quadangle, simpleNonEquals){
    ASSERT_NO_THROW(
        Quadangle quad({
            point(0, 0),
            point(0, 2),
            point(2, 2),
            point(2, 0)
        });
        ASSERT_FALSE(quad == Quadangle());
    );
}

TEST(Quadangle, difNonEquals){
    ASSERT_NO_THROW(
        Quadangle quad1({
            point(0, 0),
            point(0, 2),
            point(2, 2),
            point(2, 0)
        });
        Quadangle quad2({
            point(0, 0),
            point(0, 4),
            point(4, 4),
            point(4, 0)
        });
        ASSERT_FALSE(quad1 == quad2);
    );
}