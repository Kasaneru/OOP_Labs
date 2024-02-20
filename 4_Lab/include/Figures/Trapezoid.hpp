#pragma once
#include "Quadangle.hpp"

template<typename T>
class Trapezoid final: virtual public Quadangle<T>{
using dpoint = point<T>;
public:

    Trapezoid();
    Trapezoid(const Array<dpoint>&);
    Trapezoid(const std::initializer_list<dpoint>&);

    Trapezoid(const Trapezoid<T>&) noexcept;
    Trapezoid(Trapezoid<T>&&) noexcept;

    Trapezoid<T>& operator=(const Trapezoid<T>&);
    Trapezoid<T>& operator=(Trapezoid<T>&&);

    dpoint center() const override;
    operator double() const override;

protected:
    void trapCheck() const;
};

template<typename T>
Trapezoid<T>::Trapezoid(): Quadangle<T>(Array<point<T>>{point<T>(0, 0), point<T>(1, 1), point<T>(2, 1), point<T>(3, 0)}){}
template<typename T>
Trapezoid<T>::Trapezoid(const Array<point<T>>& arr): Quadangle<T>(arr){ trapCheck(); }
template<typename T>
Trapezoid<T>::Trapezoid(const std::initializer_list<point<T>>& list): Quadangle<T>(list){ trapCheck(); }
template<typename T>
Trapezoid<T>::Trapezoid(const Trapezoid<T>& rect)  noexcept : Quadangle<T>(rect){}
template<typename T>
Trapezoid<T>::Trapezoid(Trapezoid<T>&& temp)  noexcept : Quadangle<T>(temp){}

template<typename T>
Trapezoid<T>::operator double() const{
    Vector vec1(this->vertexes[0], this->vertexes[2]);
    Vector vec2(this->vertexes[1], this->vertexes[3]);
    return (len(vec1) * len(vec2) * sin(angle(vec1, vec2))) / 2;
}

template<typename T>
point<T> Trapezoid<T>::center() const{
    double x = 0;
    double y = 0;
    for(size_t index = 0; index < 4; ++index){
        x += this->vertexes[index].x;
        y += this->vertexes[index].y;
    }
    return point<T>(x/4, y/4);
}

template<typename T>
void Trapezoid<T>::trapCheck() const {
    point<T>& p1 = this->vertexes[0], p2 = this->vertexes[1],
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

template<typename T>
Trapezoid<T>& Trapezoid<T>::operator=(const Trapezoid<T>& other){
    this->vertexes = other.vertexes;
    return *this;
}

template<typename T>
Trapezoid<T>& Trapezoid<T>::operator=(Trapezoid<T>&& temp){
    this->vertexes.resize(0);
    this->vertexes = std::move(temp.vertexes);
    return *this;
}