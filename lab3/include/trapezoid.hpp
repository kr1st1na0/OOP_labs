#pragma once

#include "point.hpp"
#include "figure.hpp"

class Trapezoid : public Figure {
public:
    Trapezoid() = default;
    Trapezoid(std::istream &is);

    void print(std::ostream &os) const override;
    double square() const override;
    Point center() const override;
   
    Trapezoid(const Trapezoid &other); //* Copy constructor
    Trapezoid(Trapezoid &&other) noexcept; //* Move constructor
    bool operator==(const Trapezoid &other) const; //* Assignment operator
    
    virtual ~Trapezoid() = default;
private:
    Point points[4]; // bottom-left, top-left, top-right, bottom-right
};