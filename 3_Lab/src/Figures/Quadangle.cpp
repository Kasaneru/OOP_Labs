#include "../../include/Figures/Quadangle.hpp"

Quadangle::Quadangle(){
    this->vertexes.push_back(point(0,0)); this->vertexes.push_back(point(0,1));
    this->vertexes.push_back(point(1,1)); this->vertexes.push_back(point(1,0));
}

Quadangle::Quadangle(const Array<point>& array){
    this->vertexes = array;
    this->check();
}

Quadangle::Quadangle(const std::initializer_list<point>& list){
    this->vertexes = Array<point>(list);
    this->check();
}

Quadangle::Quadangle(const Quadangle& other) noexcept{
    this->vertexes = other.vertexes;
}

Quadangle::Quadangle(Quadangle&& temp) noexcept{
    this->vertexes = std::move(temp.vertexes);
}

Quadangle& Quadangle::operator=(const Quadangle& other){
    this->vertexes = other.vertexes;
    return *this;
}

Quadangle& Quadangle::operator=(Quadangle&& temp){
    this->vertexes.resize(0);
    this->vertexes = std::move(temp.vertexes);
    return *this;
}

bool Quadangle::operator==(const Quadangle& other){
    return this->vertexes == other.vertexes;
}

void Quadangle::check() const{

    if(this->vertexes.size() != 4){
        throw std::logic_error("Cannot make quadangle with not 4 points.");
    }

    if(!convex(this->vertexes)){
        throw std::logic_error("Quadangle cannot be not convex figure.");
    }
}

std::ostream& operator<<(std::ostream& stream, const Quadangle& rect){
    for(size_t index = 0; index < 4; ++index){
        stream << rect.vertexes[index].x << '\t' << rect.vertexes[index].y << std::endl;
    }
    return stream;
}

std::istream& operator>>(std::istream& stream, Quadangle& rect){
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