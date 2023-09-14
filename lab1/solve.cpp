#include "solve.hpp"

bool bracketsBalance(std::string & str) {
    bool flag = true;
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

    if (flag && !count) {
        return true;
    } else {
        return false;
    }
}