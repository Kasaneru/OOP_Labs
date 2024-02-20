#pragma once
#include "Figure.hpp"
#include "../Containers/Array.hpp"
#include "../Vector.hpp"

template<typename T>
class Quadangle;

template<typename J>
std::ostream& operator<<(std::ostream&, const Quadangle<J>&);

template<typename J>
std::istream& operator>>(std::istream&, Quadangle<J>&);

template<typename T>
class Quadangle : public Figure<T>{
using dpoint = point<T>;
template<typename J>
friend std::ostream& operator<<(std::ostream&, const Quadangle<J>&);
template<typename J>
friend std::istream& operator>>(std::istream&, Quadangle<J>&);
public:

    Quadangle();
    Quadangle(const Array<dpoint>&);
    Quadangle(const std::initializer_list<dpoint>&);

    Quadangle(const Quadangle&) noexcept;
    Quadangle(Quadangle&&) noexcept;

    Quadangle& operator=(const Quadangle&);
    Quadangle& operator=(Quadangle&&);
    bool operator==(const Quadangle&);

    dpoint center() const override{}
    operator double() const override{}

    ~Quadangle() = default;

protected:
    void check() const;
    Array<dpoint> vertexes;
};

template<typename T>
Quadangle<T>::Quadangle(){
    this->vertexes.push_back(point<T>(0,0)); this->vertexes.push_back(point<T>(0,1));
    this->vertexes.push_back(point<T>(1,1)); this->vertexes.push_back(point<T>(1,0));
}

template<typename T>
Quadangle<T>::Quadangle(const Array<point<T>>& array){
    this->vertexes = array;
    this->check();
}

template<typename T>
Quadangle<T>::Quadangle(const std::initializer_list<point<T>>& list){
    this->vertexes = Array<point<T>>(list);
    this->check();
}

template<typename T>
Quadangle<T>::Quadangle(const Quadangle& other) noexcept{
    this->vertexes = other.vertexes;
}

template<typename T>
Quadangle<T>::Quadangle(Quadangle&& temp) noexcept{
    this->vertexes = std::move(temp.vertexes);
}

template<typename T>
Quadangle<T>& Quadangle<T>::operator=(const Quadangle& other){
    this->vertexes = other.vertexes;
    return *this;
}

template<typename T>
Quadangle<T>& Quadangle<T>::operator=(Quadangle&& temp){
    this->vertexes.resize(0);
    this->vertexes = std::move(temp.vertexes);
    return *this;
}

template<typename T>
bool Quadangle<T>::operator==(const Quadangle<T>& other){
    return this->vertexes == other.vertexes;
}

template<typename T>
void Quadangle<T>::check() const{

    if(this->vertexes.size() != 4){
        throw std::logic_error("Cannot make quadangle with not 4 points.");
    }

    if(!convex(this->vertexes)){
        throw std::logic_error("Quadangle cannot be not convex figure.");
    }
}

template<typename J>
std::ostream& operator<<(std::ostream& stream, const Quadangle<J>& rect){
    for(size_t index = 0; index < 4; ++index){
        stream << rect.vertexes[index].x << '\t' << rect.vertexes[index].y << std::endl;
    }
    return stream;
}

template<typename J>
std::istream& operator>>(std::istream& stream, Quadangle<J>& rect){
    for(size_t index = 0; index < 4; ++index){
        for(size_t p = 0; p < 2; ++p){
            if(p == 0){
                stream >> rect.vertexes[index].x;
            }
            else{
                stream >> rect.vertexes[index].y;
            }
        }
    }
    return stream;
}