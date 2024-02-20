#pragma once
#include "Quadangle.hpp"

template<typename T>
class Rectangle final: virtual public Quadangle<T>{
using dpoint = point<T>;
public:

    Rectangle();
    Rectangle(const Array<dpoint>&);
    Rectangle(const std::initializer_list<dpoint>&);

    Rectangle(const Rectangle<T>&) noexcept;
    Rectangle(Rectangle<T>&&) noexcept;

    Rectangle<T>& operator=(const Rectangle<T>& rect);
    Rectangle<T>& operator=(Rectangle<T>&&);

    dpoint center() const override;
    operator double() const override;
    
protected:
    void rectCheck() const;
};

template<typename T>
Rectangle<T>::Rectangle(): Quadangle<T>(){}
template<typename T>
Rectangle<T>::Rectangle(const Array<point<T>>& arr): Quadangle<T>(arr){ rectCheck(); }
template<typename T>
Rectangle<T>::Rectangle(const std::initializer_list<point<T>>& list): Quadangle<T>(list){ rectCheck(); }
template<typename T>
Rectangle<T>::Rectangle(const Rectangle<T>& rect)  noexcept : Quadangle<T>(static_cast<Quadangle<T>>(rect)){}
template<typename T>
Rectangle<T>::Rectangle(Rectangle<T>&& temp)  noexcept : Quadangle<T>(static_cast<Quadangle<T>>(temp)){}

template<typename T>
Rectangle<T>::operator double() const{
    point<T>& p1 = this->vertexes[0], p2 = this->vertexes[1],
           p3 = this->vertexes[2];
    Vector vec1(p1, p2), vec2(p2, p3);
    return len(vec1) * len(vec2);
}

template<typename T>
point<T> Rectangle<T>::center() const{
    point<T>& p1 = this->vertexes[0], p2 = this->vertexes[2];
    return point<T>((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

template<typename T>
void Rectangle<T>::rectCheck() const{
    point<T>& p1 = this->vertexes[0], p2 = this->vertexes[1],
           p3 = this->vertexes[2], p4 = this->vertexes[3];
    Vector vec1(p1, p2), vec2(p2, p3), vec3(p3, p4), vec4(p4,p1);
    if(angle(vec1, vec2) == angle(vec3, vec4) && angle(vec1, vec2) == (M_PI / 2)){}
    else {
        throw std::logic_error("This figure does not a rectangle.");
    }
}

template<typename T>
Rectangle<T>& Rectangle<T>::operator=(const Rectangle<T>& other){
    this->vertexes = other.vertexes;
    return *this;
}

template<typename T>
Rectangle<T>& Rectangle<T>::operator=(Rectangle<T>&& temp){
    this->vertexes.resize(0);
    this->vertexes = std::move(temp.vertexes);
    return *this;
}