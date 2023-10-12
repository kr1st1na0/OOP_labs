#pragma once

#include <iostream>
#include <vector>

#include "point.hpp"

class Figure {
public:
    ~Figure() = default;
    virtual void print(std::ostream &os) const = 0;
    virtual double square() const = 0;
    virtual Point center() const = 0;
};