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
   
    Figure& move(Figure &&other) noexcept; //* Move constructor
    Figure& operator=(const Figure &other); //* Copy constructor
    bool operator==(const Figure &other) const; //* Assignment operator
    
    virtual ~Trapezoid() = default;
private:
    Point points[4]; // bottom-left, top-left, top-right, bottom-right
};