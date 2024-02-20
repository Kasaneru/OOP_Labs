#pragma once
#include "./Figures/Figure.hpp"
#include "./Containers/Array.hpp"
#include <math.h>

struct Vector{

    Vector(double = 0, double = 0);
    Vector(const point&, const point&);

    double operator*(const Vector&) const;
    bool operator==(const Vector&) const;

    double x;
    double y;

};

bool convex(const Array<point>&);

double angle(const Vector&, const Vector&);
double len(const Vector&);