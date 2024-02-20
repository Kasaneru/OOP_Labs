#pragma once
#include <iostream>
#include <string>
namespace lab2{

    class Hex{
    friend std::ostream& operator<<(std::ostream&, const Hex&);
    public:
        Hex();
        Hex(size_t, const unsigned char = '0');
        Hex(const std::initializer_list<unsigned char>&);
        Hex(const std::string&);
        Hex(const Hex&);
        Hex(Hex&&) noexcept;

        Hex operator+(const Hex&) const;
        Hex operator-(const Hex&) const;
        Hex operator=(const Hex&);
        Hex& operator+=(const Hex&);
        Hex& operator-=(const Hex&);

        bool operator==(const Hex&) const noexcept;
        bool operator!=(const Hex&) const noexcept;
        bool operator>(const Hex&) const noexcept;
        bool operator<(const Hex&) const noexcept;
        bool operator>=(const Hex&) const noexcept;
        bool operator<=(const Hex&) const noexcept;

        virtual ~Hex() noexcept;

    private:
        void increase_size();
        void reduce_size();

        unsigned char* array;
        size_t sz;
    };

}
