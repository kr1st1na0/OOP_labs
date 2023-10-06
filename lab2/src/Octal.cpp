#include "Octal.hpp"

bool isOctal(const char &c) {
    return (c >= '0' && c <= '7');
}

Octal::Octal() : size(0), number{nullptr} {}

size_t Octal::getSize() const { return size; }

unsigned char* Octal::getNumber() const { return number; }

Octal::Octal(const size_t &n, unsigned char t) {
    // std::cout << "Fill constructor" << std::endl;
    number = new unsigned char[n];
    for (size_t i = 0; i < n; i++)
        number[i] = t;
    size = n;  
}

Octal::Octal(const std::initializer_list<unsigned char> &t) {
    // std::cout << "Initializer list constructor" << std::endl;
    number = new unsigned char[t.size()];
    size = t.size();
    size_t i{size};
    for (unsigned char c : t) {
        if (!isOctal(c)) { 
            throw std::logic_error("Octal digit can't be 8 or more");
        }
        number[--i] = c;
    }
}

Octal::Octal(const std::string t) {
    // std::cout << "Copy string constructor" << std::endl;
    size  = t.size();
    number = new unsigned char[size];
    for(size_t i = size - 1, j = 0; i >= 0, j < size; i--, j++) {
        if (!isOctal(t[i])) { 
            throw std::logic_error("Octal digit can't be 8 or more");
        }
        number[i] = t[j];
    }
}

Octal::Octal(const Octal &other) {
    // std::cout << "Copy constructor" << std::endl;
    size  = other.size;
    number = new unsigned char[size];
    for(size_t i = 0; i < size; i++) {
        number[i] = other.number[i];
    }
}

Octal::Octal(Octal &&other) noexcept {
    // std::cout << "Move constructor" << std::endl;
    size = other.size;
    number = other.number;
    other.size = 0;
    other.number = nullptr;
}

Octal Octal::operator=(const Octal &other) {
    if (&other != this) {
        delete[] number;
        size = other.size;
        number = new unsigned char[size];
        for (size_t i = 0; i < size; i++) {
            number[i] = other.number[i];
        }
    }
    return *this;
}

Octal Octal::operator+(const Octal &other) const {
    size_t resultSize = std::max(other.size, size) + 1;
    std::string result(resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++) {
        int d1 = (i < size) ? (number[i] - '0') : 0;
        int d2 = (i < other.size) ? (other.number[i] - '0') : 0;

        int sum = d1 + d2 + carry;
        result[i] = (sum % 8) + '0';
        carry = sum / 8;
    }
    if (carry > 0) {
        result[resultSize - 1] = carry + '0';
    }
    if (result[resultSize - 1] == '0'){
        result.erase(resultSize - 1, 1);
    }
    std::reverse(result.begin(), result.end());
    return Octal(result);
}

Octal Octal::operator-(const Octal &other) const {
    if (*this < other) { throw std::logic_error("Difference can't be negative"); }
    size_t resultSize = std::max(other.size, size) + 1;
    std::string result(resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++) {
        int d1 = (i < size) ? (number[i] - '0') : 0;
        int d2 = (i < other.size) ? (other.number[i] - '0') : 0;

        int diff = d1 - d2 - carry;
        if (diff < 0) {
            diff += 8;
            carry = 1;
        } else {
            carry = 0;
        }
        result[i] = diff + '0';
    }
    if (result[resultSize - 1] == '0'){
        result.erase(resultSize - 1, 1);
    }
    std::reverse(result.begin(), result.end());
    return Octal(result);
}

bool Octal::operator==(const Octal &other) const {
    if (size != other.size) { return 0; }
    for (size_t i = 0; i < size; i++) {
        if (number[i] != other.number[i]) {
            return 0;
        }
    }
    return 1;
}

bool Octal::operator!=(const Octal &other) const {
    if (*this == other) { return 0; }
    return 1;
 }

bool Octal::operator<(const Octal &other) const {
    if (&other == this) { return 0; }
    if (size < other.size) { return 1; }
    else if (size > other.size) { return 0; }
    else {
        for (size_t i = size; i--;) {
            if (number[i] < other.number[i]) { return 1; }
            else if (number[i] > other.number[i]) { return 0; }
        }
    }
    return 0;
}

bool Octal::operator<=(const Octal &other) const {
    if (*this > other) { return 0; }
    return 1;
}

bool Octal::operator>(const Octal other) const {
    if (*this < other || *this == other) { return 0; }
    return 1;
}

bool Octal::operator>=(const Octal other) const {
    if (*this < other) { return 0; }
    return 1;
}

std::ostream& Octal::print(std::ostream &os) {
    for (size_t i = size; i--;) {
        os << number[i];
    }
    return os;
}

Octal::~Octal() noexcept {
    if (size > 0) {
        size = 0;
        delete[] number;
        number = nullptr;
    }
}