#pragma once
#include "Array.hpp"
#include "../Figures/Figure.hpp"

template<typename T>
class FigureVector: public Array<Figure<T>*>{
public:

    void outCenter(){
        for(size_t i = 0; i < this->sz; ++i) 
            std::cout << this->arr[i]->center().x << ' ' << this->arr[i]->center().y << std::endl;
    }

    void outArea(){
        for(size_t i = 0; i < this->sz; ++i) 
            std::cout << static_cast<double>(*(this->arr[i])) << std::endl;
    }

    size_t areaSum() {
        size_t sum = 0;
        for(size_t i = 0; i < this->sz; ++i) 
            sum += (double)(*this->arr[i]);
        return sum;
    }
    
};