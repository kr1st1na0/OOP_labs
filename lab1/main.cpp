#include <iostream>
#include "solve.hpp"

int main() {

    std::string str;
    std::cin >> str;

    std::cout << bracketsBalance(str)<< std::endl;

    return 0;
}