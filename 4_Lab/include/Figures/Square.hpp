#pragma once
#include "Quadangle.hpp"

template<typename T>
class Square final: virtual public Quadangle<T>{
using dpoint = point<T>;
public:

    Square();
    Square(const Array<dpoint>&);
    Square(const std::initializer_list<dpoint>&);

    Square(const Square<T>&) noexcept;
    Square(Square<T>&&) noexcept;

    Square<T>& operator=(const Square<T>&);
    Square<T>& operator=(Square<T>&&);

    dpoint center() const override;
    operator double() const override;

protected:
    void squareCheck() const;
};

template<typename T>
Square<T>::Square(): Quadangle<T>(){}
template<typename T>
Square<T>::Square(const Array<point<T>>& arr): Quadangle<T>(arr){ squareCheck(); }
template<typename T>
Square<T>::Square(const std::initializer_list<point<T>>& list): Quadangle<T>(list){ squareCheck(); }
template<typename T>
Square<T>::Square(const Square<T>& rect)  noexcept : Quadangle<T>(rect){}
template<typename T>
Square<T>::Square(Square<T>&& temp)  noexcept : Quadangle<T>(temp){}

template<typename T>
point<T> Square<T>::center() const{
    point<T>& p1 = this->vertexes[0], p2 = this->vertexes[2];
    return point<T>((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

template<typename T>
Square<T>::operator double() const{
    Vector vec1(this->vertexes[0], this->vertexes[2]);
    Vector vec2(this->vertexes[1], this->vertexes[3]);
    return (len(vec1) * len(vec2)) / 2;
}

template<typename T>
void Square<T>::squareCheck() const{
    point<T>& p1 = this->vertexes[0], p2 = this->vertexes[1],
           p3 = this->vertexes[2], p4 = this->vertexes[3];
    Vector vec1(p1, p2), vec2(p2, p3), vec3(p4, p3), vec4(p1, p4);
    if(vec1 == vec3 && vec2 == vec4 && len(vec1) == len(vec2)){
        return;
    }
    else {
        throw std::logic_error("Figure is not square");
    }
}

template<typename T>
Square<T>& Square<T>::operator=(const Square<T>& other){
    this->vertexes = other.vertexes;
    return *this;
}

template<typename T>
Square<T>& Square<T>::operator=(Square<T>&& temp){
    this->vertexes.resize(0);
    this->vertexes = std::move(temp.vertexes);
    return *this;
}
