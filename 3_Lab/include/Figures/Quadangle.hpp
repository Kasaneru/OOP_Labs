#pragma once
#include "Figure.hpp"
#include "../Containers/Array.hpp"
#include "../Vector.hpp"

class Quadangle;

std::ostream& operator<<(std::ostream&, const Quadangle&);
std::istream& operator>>(std::istream&, Quadangle&);

class Quadangle : public Figure{
friend std::ostream& operator<<(std::ostream&, const Quadangle&);
friend std::istream& operator>>(std::istream&, Quadangle&);
public:

    Quadangle();
    Quadangle(const Array<point>&);
    Quadangle(const std::initializer_list<point>&);

    Quadangle(const Quadangle&) noexcept;
    Quadangle(Quadangle&&) noexcept;

    Quadangle& operator=(const Quadangle&);
    Quadangle& operator=(Quadangle&&);
    bool operator==(const Quadangle&);

    point center() const override{}
    operator double() const override{}

    ~Quadangle() = default;

protected:
    void check() const;
    Array<point> vertexes;
};