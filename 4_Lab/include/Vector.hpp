#pragma once
#include "./Figures/Figure.hpp"
#include "./Containers/Array.hpp"
#include <math.h>

template<typename T>
struct Vector{

    Vector(double = 0, double = 0);
    Vector(const point<T>&, const point<T>&);

    double operator*(const Vector&) const;
    bool operator==(const Vector&) const;

    T x;
    T y;

};
template<typename T>
bool convex(const Array<point<T>>&);
template<typename T>
double angle(const Vector<T>&, const Vector<T>&);
template<typename T>
double len(const Vector<T>&);

template<typename T>
Vector<T>::Vector(double _x, double _y): x(_x), y(_y){}

template<typename T>
Vector<T>::Vector(const point<T>& first, const point<T>& second){
    this->x = second.x - first.x;
    this->y = second.y - first.y;
}

template<typename T>
double Vector<T>::operator*(const Vector<T>& other) const {
    return this->x * other.x + this->y * other.y;
}

template<typename T>
double len(const Vector<T>& vec){
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

template<typename T>
double angle(const Vector<T>& first, const Vector<T>& second){
    return acos((first * second) / (len(first) * len(second)));
}

template<typename T>
bool convex(const Array<point<T>>& arr){
    
    for(size_t i = 0; i < arr.size(); ++i){
        int64_t b = i - 1, c = i + 1;
        if(b < 0) b = arr.size() - 1;
        if(c == arr.size()) c = 0;

        Vector vec1(arr[i], arr[b]);
        Vector vec2(arr[c], arr[i]);

        double product = vec1.x * vec2.y - vec1.y * vec2.x;

        if(product >= 0) return false;

    }
    
    return true;
}

template<typename T>
bool Vector<T>::operator==(const Vector<T>& other) const{
    return ((fabs(other.x - this->x) < 1e-2) && (fabs(this->y - other.y) < 1e-2));
}