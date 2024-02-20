#pragma once
#include "Quadangle.hpp"

class Square final: virtual public Quadangle{
public:

    Square();
    Square(const Array<point>&);
    Square(const std::initializer_list<point>&);

    Square(const Square&) noexcept;
    Square(Square&&) noexcept;

    Square& operator=(const Square&);
    Square& operator=(Square&&);

    point center() const override;
    operator double() const override;

protected:
    void squareCheck() const;
};
