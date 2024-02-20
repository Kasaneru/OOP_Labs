#include "../../include/Figures/Rectangle.hpp"

Rectangle::Rectangle(): Quadangle(){}
Rectangle::Rectangle(const Array<point>& arr): Quadangle(arr){ rectCheck(); }
Rectangle::Rectangle(const std::initializer_list<point>& list): Quadangle(list){ rectCheck(); }
Rectangle::Rectangle(const Rectangle& rect)  noexcept : Quadangle(static_cast<Quadangle>(rect)){}
Rectangle::Rectangle(Rectangle&& temp)  noexcept : Quadangle(static_cast<Quadangle>(temp)){}

Rectangle::operator double() const{
    point& p1 = this->vertexes[0], p2 = this->vertexes[1],
           p3 = this->vertexes[2];
    Vector vec1(p1, p2), vec2(p2, p3);
    return len(vec1) * len(vec2);
}

point Rectangle::center() const{
    point& p1 = this->vertexes[0], p2 = this->vertexes[2];
    return point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

void Rectangle::rectCheck() const{
    point& p1 = this->vertexes[0], p2 = this->vertexes[1],
           p3 = this->vertexes[2], p4 = this->vertexes[3];
    Vector vec1(p1, p2), vec2(p2, p3), vec3(p3, p4), vec4(p4,p1);
    if(angle(vec1, vec2) == angle(vec3, vec4) && angle(vec1, vec2) == (M_PI / 2)){}
    else {
        throw std::logic_error("This figure does not a rectangle.");
    }
}

Rectangle& Rectangle::operator=(const Rectangle& other){
    this->vertexes = other.vertexes;
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& temp){
    this->vertexes.resize(0);
    this->vertexes = std::move(temp.vertexes);
    return *this;
}