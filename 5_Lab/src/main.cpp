#include "../include/Allocator.hpp"
#include <map>
#include <iostream>
#include "../include/Stack.hpp"

int main(){

    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> mp;
    int fact = 1;
    for(size_t i = 0; i < 10; ++i){
        fact *= i > 1 ? i : 1;
        mp[i] = fact;
    }

    for(std::pair<int, int> pr : mp){
        std::cout << pr.first << ' ' << pr.second << std::endl;
    }

    Stack<int> stk;

    for(size_t i = 0; i < 20; ++i){
        stk.push(i);
    }

    while (!stk.empty()) {
        std::cout << stk.back() << ' ';
        stk.pop();
    }

    return 0;
}
