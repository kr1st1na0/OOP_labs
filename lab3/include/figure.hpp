#pragma once

#include <iostream>
#include <vector>

#include "point.hpp"

class Figure {
public:
    virtual Figure& move(Figure &&other) noexcept = 0; //* Move constructor
    virtual Figure& operator=(const Figure &other) = 0; //* Copy constructor
    virtual bool operator==(const Figure &other) const = 0; //* Equal operator (==)

    virtual void print(std::ostream &os) const = 0;
    virtual double square() const = 0;
    virtual Point center() const = 0;

    virtual ~Figure() = default;
};