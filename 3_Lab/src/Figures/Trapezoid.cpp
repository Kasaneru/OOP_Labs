#include "../../include/Figures/Trapezoid.hpp"

Trapezoid::Trapezoid(): Quadangle(Array<point>{point(0, 0), point(1, 1), point(2, 1), point(3, 0)}){}
Trapezoid::Trapezoid(const Array<point>& arr): Quadangle(arr){ trapCheck(); }
Trapezoid::Trapezoid(const std::initializer_list<point>& list): Quadangle(list){ trapCheck(); }
Trapezoid::Trapezoid(const Trapezoid& rect)  noexcept : Quadangle(rect){}
Trapezoid::Trapezoid(Trapezoid&& temp)  noexcept : Quadangle(temp){}

Trapezoid::operator double() const{
    Vector vec1(this->vertexes[0], this->vertexes[2]);
    Vector vec2(this->vertexes[1], this->vertexes[3]);
    return (len(vec1) * len(vec2) * sin(angle(vec1, vec2))) / 2;
}

point Trapezoid::center() const{
    double x = 0;
    double y = 0;
    for(size_t index = 0; index < 4; ++index){
        x += this->vertexes[index].x;
        y += this->vertexes[index].y;
    }
    return point(x/4, y/4);
}

void Trapezoid::trapCheck() const {
    point& p1 = this->vertexes[0], p2 = this->vertexes[1],
           p3 = this->vertexes[2], p4 = this->vertexes[3];
    Vector vec1(p1, p2), vec2(p2, p3), vec3(p4, p3), vec4(p1, p4);
    vec1.x /= len(vec1); vec1.y /= len(vec1);
    vec2.x /= len(vec2); vec2.y /= len(vec2);
    vec3.x /= len(vec3); vec3.y /= len(vec3);
    vec4.x /= len(vec4); vec4.y /= len(vec4);
    if(vec1 == vec3 && vec2 == vec4){
        std::cout << vec3.x - vec1.x << '\t' << vec2.x - vec4.x << std::endl;
        throw std::logic_error("Trapezoid cannot have two parallel lines");
    }
    if(vec1 == vec3){
        return;
    }
    if(vec2 == vec4){
        return;
    }
    throw std::logic_error("This figure is not trapezoid.");
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other){
    this->vertexes = other.vertexes;
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& temp){
    this->vertexes.resize(0);
    this->vertexes = std::move(temp.vertexes);
    return *this;
}