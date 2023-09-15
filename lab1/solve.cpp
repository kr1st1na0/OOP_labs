#include "solve.hpp"

bool bracketsBalance(std::string & str) {
    int count = 0;

    if (str == "") {
        return true;
    }

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {
            ++count; 
        } else if (str[i] == ')' && count) {
            --count;
        } else {
            return false;
        }
    }

    return !count;
}