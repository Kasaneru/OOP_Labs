#include "../include/Hex.hpp"
#include <stdexcept>

size_t max(size_t x, size_t y){
    if(x > y) return x;
    return y;
}

size_t min(size_t x, size_t y){
    if(x < y) return x;
    return y;
}

namespace lab2{

    Hex::Hex(): sz(1){
        this->array = new unsigned char[this->sz];
        new(this->array + 0) unsigned char('0');
    }

    Hex::Hex(size_t size, unsigned char data): sz(size){

        if(this->sz == 0){
            throw std::logic_error("Cannot create empty number");
        }

        if((data < '0') ||
           (data > 'F') || 
           (data > '9' && data < 'A')){
            
            throw std::logic_error(std::to_string(data));

        }

        this->array = new unsigned char[this->sz];
        for(size_t index = 0; index < this->sz; ++index){
            new(this->array + index) unsigned char(data);
        }
    }

    Hex::Hex(const std::initializer_list<unsigned char>& list){
        
        if(list.size() == 0){
            throw std::logic_error("Cannot create empty number.");
        }
        
        size_t size = 1;
        size_t current = 0;
        for(unsigned char x : list){

            if((x < '0') ||
               (x > 'F') || 
               (x > '9' && x < 'A')){
            
                throw std::logic_error("Uncorrect number (digit is nor 0-12).");

            }

            if(x != '0' && size == 1){
                size = list.size() - current;   
            }
            ++current;
        }

        this->sz = size;
        this->array = new unsigned char[this->sz];
        current = 0;
        for(unsigned char x : list){
            new(this->array + (this->sz - current - 1)) unsigned char(x);
            ++current;
            if(current == this->sz){
                break;
            }
        }
    }

    Hex::Hex(const std::string& str){
        
        if(str.size() == 0){
            throw std::logic_error("Cannot create empty number.");
        }

        size_t size = 1;
        size_t current = 0;
        for(unsigned char x : str){

            if((x < '0') ||
               (x > 'F') || 
               (x > '9' && x < 'A')){

                throw std::logic_error("Uncorrect number (digit is nor 0-12).");

            }

            if(x != '0' && size == 1){
                size = str.size() - current;   
            }
            ++current;
        }

        this->sz = size;
        this->array = new unsigned char[this->sz];
        current = 0;
        for(unsigned char x : str){
            new(this->array + (this->sz - current - 1)) unsigned char(x);
            ++current;
            if(current == this->sz){
                break;
            }
        }
    }

    Hex::Hex(const Hex& other){
        this->sz = other.sz;
        this->array = new unsigned char[this->sz];
        for(size_t index = 0; index < this->sz; ++index){
            new(this->array + index) unsigned char(other.array[index]);
        }
    }

    Hex::Hex(Hex&& temp) noexcept{
        this->array = temp.array;
        temp.array = nullptr;
        this->sz = temp.sz;
    }

    bool Hex::operator==(const Hex& other) const noexcept{
        if(this->sz != other.sz){
            return false;
        }
        for(size_t index = 0; index < this->sz; ++index){
            if(this->array[index] != other.array[index]){
                return false;
            }
        }
        return true;
    }

    Hex Hex::operator+(const Hex& other) const{
        bool additional = 0;
        size_t num;
        Hex returnHex(max(other.sz, this->sz));
        unsigned char *smaller, *bigger;
        if(other.sz > this->sz){
            bigger = other.array;
            smaller = this->array;
        }
        else{
            bigger = this->array;
            smaller = other.array;
        }
        for(size_t index = 0; index < max(other.sz, this->sz); ++index){
            num = 0;
            if(index < min(other.sz, this->sz)){
                num += smaller[index] - '0';
                if(num > 9){
                    num += smaller[index] - 'A' - num + 10;
                }
            }

            if(bigger[index] > '9'){
                num += bigger[index] - 'A' + 10 + additional;
            }
            else{
                num += bigger[index] - '0' + additional;
            }

            if(num > 15){
                additional = 1;
                num -= 16;
            }
            else{
                additional = 0;
            }

            switch(num){
                case(15):
                    returnHex.array[index] = 'F';
                    break;
                case(14):
                    returnHex.array[index] = 'E';
                    break;
                case(13):
                    returnHex.array[index] = 'D';
                    break;
                case(12):
                    returnHex.array[index] = 'C';
                    break;
                case(11):
                    returnHex.array[index] = 'B';
                    break;
                case(10):
                    returnHex.array[index] = 'A';
                    break;
                default:
                    returnHex.array[index] = num + '0';
            }
        }
        if(additional){
            returnHex.increase_size();
        }
        return returnHex;
    }

    Hex& Hex::operator+=(const Hex& other){
        Hex temp = *this + other;
        this->sz = temp.sz;
        this->array = temp.array;
        temp.array = nullptr;
        
        return *this;
    }

    Hex Hex::operator-(const Hex& other) const{
        if(*this < other){
            throw std::logic_error("Cannot make number below zero.");
        }
        if(*this == other){
            return Hex();
        }

        bool additional = 0;
        bool nextAdditional = 0;
        size_t num;
        Hex returnHex(this->sz);
        for(size_t index = 0; index < this->sz; ++index){
            if(this->array[index] - '9' > 0){
                num = this->array[index] - 'A' + 10;
            }
            else {
                num = this->array[index] - '0';
            }

            if(index < other.sz){
                size_t num2;
                if(other.array[index] - '9' > 0){
                    num2 = other.array[index] - 'A' + 10;
                }
                else{
                    num2 = other.array[index] - '0';
                }

                if(num2 > num){
                    nextAdditional = 1;
                    num += 16;
                }
                    num -= num2;
            }

            if(additional){
                if(num == 0){
                    num += 15;
                    nextAdditional = 1;
                }
                else{
                    --num;
                }
            }

            additional = nextAdditional;
            nextAdditional = 0;

            switch(num){
                case(15):
                    returnHex.array[index] = 'F';
                    break;
                case(14):
                    returnHex.array[index] = 'E';
                    break;
                case(13):
                    returnHex.array[index] = 'D';
                    break;
                case(12):
                    returnHex.array[index] = 'C';
                    break;
                case(11):
                    returnHex.array[index] = 'B';
                    break;
                case(10):
                    returnHex.array[index] = 'A';
                    break;
                default:
                    returnHex.array[index] = num + '0';
            }
        }

        returnHex.reduce_size();
        return returnHex;
    }

    Hex& Hex::operator-=(const Hex& other){
        Hex temp = *this - other;
        delete this->array;
        this->array = temp.array;
        temp.array = nullptr;
        this->sz = temp.sz;
        return *this;
    }

    Hex Hex::operator=(const Hex& other){
        delete this->array;
        this->sz = other.sz;
        this->array = new unsigned char[this->sz];
        for(size_t index = 0; index < this->sz; ++index){
            new(this->array + index) unsigned char(other.array[index]);
        }
        return *this;
    }

    bool Hex::operator!=(const Hex& other) const noexcept{
        return !(*this == other);
    }

    bool Hex::operator<(const Hex& other) const noexcept{
        if(this->sz < other.sz){
            return true;
        }
        else if(this->sz > other.sz){
            return false;
        }

        for(int64_t index = this->sz - 1; index >= 0; --index){
            if(this->array[index] > other.array[index]){
                return false;
            }
            if(this->array[index] < other.array[index]){
                return true;
            }
        }
        return false;
    }

    bool Hex::operator<=(const Hex& other) const noexcept{
        if(this->sz < other.sz){
            return true;
        }
        else if(this->sz > other.sz){
            return false;
        }

        for(int64_t index = this->sz - 1; index >= 0; --index){
            if(this->array[index] > other.array[index]){
                return false;
            }
            if(this->array[index] < other.array[index]){
                return true;
            }
        }
        return true;
    }

    bool Hex::operator>(const Hex& other) const noexcept{
        return !(*this <= other);
    }

    bool Hex::operator>=(const Hex& other) const noexcept{
        return !(*this < other);
    }

    void Hex::increase_size(){
        ++this->sz;
        unsigned char* temp = new unsigned char[this->sz];
        for(size_t index = 0; index < this->sz - 1; ++index){
            new(temp + index) unsigned char(this->array[index]);
        }
        delete this->array;
        this->array = temp;
        this->array[this->sz - 1] = '1';
    }

    void Hex::reduce_size(){

        if(this->array[this->sz - 1] != '0' || this->sz == 1){
            return;
        }
        --this->sz;
        unsigned char* temp = new unsigned char[this->sz];
        for(size_t index = 0; index < this->sz; ++index){
            new(temp + index) unsigned char(this->array[index]);
        }
        delete this->array;
        this->array = temp;
    }

    Hex::~Hex(){
        delete this->array;
        this->array = nullptr;
        this->sz = 0;
    }

}

std::ostream& lab2::operator<<(std::ostream& stream, const lab2::Hex& num){
    for(int64_t currentNum = num.sz - 1; currentNum >= 0; --currentNum){
        stream << num.array[currentNum];
    }
    return stream;
}
