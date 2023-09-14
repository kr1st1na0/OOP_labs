#include <iostream>
#include "solve.hpp"

int main() {

    std::string str;
    std::cin >> str;

    if (bracketsBalance(str)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }

    return 0;
}