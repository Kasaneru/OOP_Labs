#include "../include/Hex.hpp"

int main(){

    lab2::Hex temp1("000");
    lab2::Hex temp2("000");
    lab2::Hex temp3("000");

    std::cout << "Enter a Hex number:" << std::endl;
    std::string str;
    getline(std::cin, str);
    lab2::Hex num(str);

    std::cout << "Your number is : " << num << std::endl;

    std::cout << "Enter second number" << std::endl;

    getline(std::cin, str);
    lab2::Hex num2(str);
    
    std::cout << num << '+' << num2 << '=' << num + num2 << std::endl;
    if(num > num2){
        std::cout << num << '-' << num2 << '=' << num - num2 << std::endl;
    }
    else{
        std::cout << num2 << '-' << num << '=' << num2 - num << std::endl;
    }

    return 0;
}
