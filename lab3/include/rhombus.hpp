#pragma once

#include "point.hpp"
#include "figure.hpp"

class Rhombus : public Figure {
public:
    Rhombus() = default;
    Rhombus(Point &p1, Point &p2, Point &p3, Point &p4);
    Rhombus(std::istream &is);

    void print(std::ostream &os) const;
    double square() const;
    Point center() const;
   
    Rhombus(const Rhombus &other); //* Copy constructor
    Rhombus(Rhombus &&other) noexcept; //* Move constructor
    bool operator==(const Rhombus &other) const; //* Assignment operator
    
    virtual ~Rhombus() = default;
private:
    Point points[4]; // left, top, right, bottom
};