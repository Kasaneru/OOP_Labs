#pragma once
#include "Quadangle.hpp"

class Rectangle final: virtual public Quadangle{
public:

    Rectangle();
    Rectangle(const Array<point>&);
    Rectangle(const std::initializer_list<point>&);

    Rectangle(const Rectangle&) noexcept;
    Rectangle(Rectangle&&) noexcept;

    Rectangle& operator=(const Rectangle& rect);
    Rectangle& operator=(Rectangle&&);

    point center() const override;
    operator double() const override;
    
protected:
    void rectCheck() const;
};