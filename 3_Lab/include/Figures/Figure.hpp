#pragma once
#include <iostream>

struct point{
public:
    point(double _x = 0, double _y = 0): x(_x), y(_y){}

    bool operator==(const point& other) const{
        return this->x == other.x && this->y == other.y;
    }
    bool operator!=(const point& other) const{
        return !(*this == other);
    }

    double x;
    double y;
};


class Figure{
public:

    virtual point center() const = 0;
    virtual operator double() const = 0;

    virtual ~Figure() {}
};