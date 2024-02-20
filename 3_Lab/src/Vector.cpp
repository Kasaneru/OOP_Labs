#include "../include/Vector.hpp"

Vector::Vector(double _x, double _y): x(_x), y(_y){}

Vector::Vector(const point& first, const point& second){
    this->x = second.x - first.x;
    this->y = second.y - first.y;
}

double Vector::operator*(const Vector& other) const {
    return this->x * other.x + this->y * other.y;
}

double len(const Vector& vec){
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

double angle(const Vector& first, const Vector& second){
    return acos((first * second) / (len(first) * len(second)));
}

bool convex(const Array<point>& arr){
    
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

bool Vector::operator==(const Vector& other) const{
    return ((fabs(other.x - this->x) < 1e-2) && (fabs(this->y - other.y) < 1e-2));
}