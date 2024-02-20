#include "Quadangle.hpp"

class Trapezoid final: virtual public Quadangle{
public:

    Trapezoid();
    Trapezoid(const Array<point>&);
    Trapezoid(const std::initializer_list<point>&);

    Trapezoid(const Trapezoid&) noexcept;
    Trapezoid(Trapezoid&&) noexcept;

    Trapezoid& operator=(const Trapezoid&);
    Trapezoid& operator=(Trapezoid&&);

    point center() const override;
    operator double() const override;

protected:
    void trapCheck() const;
};