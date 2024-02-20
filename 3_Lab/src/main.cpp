#include "../include/Figures/Rectangle.hpp"
#include "../include/Figures/Trapezoid.hpp"
#include "../include/Figures/Square.hpp"
#include "../include/Containers/FigureVector.hpp"

int main(){

    Rectangle rect, rect2;
    FigureVector vec;
    vec.push_back(&rect);
    vec.push_back(&rect);
    vec.push_back(&rect);
    vec.push_back(&rect);

    vec.outArea(); vec.outCenter();

    std::cout << vec.areaSum() << std::endl;

    return 0;
}
