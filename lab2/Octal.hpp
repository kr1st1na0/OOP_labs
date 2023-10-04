#pragma once
#include <iostream>
#include <cstring>

class Octal {    
    public:
        Octal(); //* Default constructor
        size_t getSize() const;
        unsigned char* getNumber() const;

        Octal(const size_t &n, unsigned char t = 0); //* Fill constructor  
        Octal(const std::initializer_list<unsigned char> &t); //* Initializer list constructor  
        Octal(const std::string t); //* Copy string constructor
        Octal(const Octal& other); //* Copy constructor
        Octal(Octal&& other) noexcept; //* Move constructor
        std::ostream &print(std::ostream &os);

        //TODO:
        Octal operator=(const Octal other); //* Assignment operator (=)
        // Octal operator+(const Octal other) const; //* Addition operator (+)
        // Octal operator-(const Octal other) const; //* Substraction operator (-)
        // bool operator>(const Octal other) const; //* Greater operator (>)
        // bool operator<(const Octal other) const; //* Less operator (<)
        // bool operator==(const Octal other) const; //* Equal operator (==)

       ~Octal() noexcept; //* Destructor
    private:
        size_t size;
        unsigned char *number;
};