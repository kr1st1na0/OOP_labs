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
   
    Figure& move(Figure &&other) noexcept; //* Move constructor
    Figure& operator=(const Figure &other); //* Copy constructor
    bool operator==(const Figure &other) const; //* Assignment operator
    
    virtual ~Rhombus() = default;
private:
    Point points[4]; // left, top, right, bottom
};