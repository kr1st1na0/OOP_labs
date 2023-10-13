#pragma once

#include "point.hpp"
#include "figure.hpp"

class Trapezoid : public Figure {
public:
    Trapezoid() = default;
    Trapezoid(Point &p1, Point &p2, Point &p3, Point &p4);
    Trapezoid(std::istream &is);

    void print(std::ostream &os) const;
    double square() const;
    Point center() const;
   
    Trapezoid(const Trapezoid &other); //* Copy constructor
    Trapezoid(Trapezoid &&other) noexcept; //* Move constructor
    bool operator==(const Trapezoid &other) const; //* Assignment operator
    
    ~Trapezoid() = default;
private:
    Point points[4]; // bottom-left, top-left, top-right, bottom-right
};