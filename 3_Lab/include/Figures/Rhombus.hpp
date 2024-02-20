#pragma once
#include "Quadangle.hpp"

class Rhombus final: virtual public Quadangle{
public:

    Rhombus();
    Rhombus(const Array<point>&);
    Rhombus(const std::initializer_list<point>&);

    Rhombus(const Rhombus&) noexcept;
    Rhombus(Rhombus&&) noexcept;

    Rhombus& operator=(const Rhombus&);
    Rhombus& operator=(Rhombus&&);

    point center() const override;
    operator double() const override;

protected:
    void rhombCheck() const;
};