#include "../../include/Figures/Square.hpp"

Square::Square(): Quadangle(){}
Square::Square(const Array<point>& arr): Quadangle(arr){ squareCheck(); }
Square::Square(const std::initializer_list<point>& list): Quadangle(list){ squareCheck(); }
Square::Square(const Square& rect)  noexcept : Quadangle(rect){}
Square::Square(Square&& temp)  noexcept : Quadangle(temp){}

point Square::center() const{
    point& p1 = this->vertexes[0], p2 = this->vertexes[2];
    return point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

Square::operator double() const{
    Vector vec1(this->vertexes[0], this->vertexes[2]);
    Vector vec2(this->vertexes[1], this->vertexes[3]);
    return (len(vec1) * len(vec2)) / 2;
}

void Square::squareCheck() const{
    point& p1 = this->vertexes[0], p2 = this->vertexes[1],
           p3 = this->vertexes[2], p4 = this->vertexes[3];
    Vector vec1(p1, p2), vec2(p2, p3), vec3(p4, p3), vec4(p1, p4);
    if(vec1 == vec3 && vec2 == vec4 && len(vec1) == len(vec2) && angle(vec1, vec2) == (M_PI / 2)){
        return;
    }
    else {
        throw std::logic_error("Figure is not square");
    }
}

Square& Square::operator=(const Square& other){
    this->vertexes = other.vertexes;
    return *this;
}

Square& Square::operator=(Square&& temp){
    this->vertexes.resize(0);
    this->vertexes = std::move(temp.vertexes);
    return *this;
}
