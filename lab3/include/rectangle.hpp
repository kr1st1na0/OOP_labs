#pragma once

#include "point.hpp"
#include "figure.hpp"

class Rectangle : public Figure {
public:
    Rectangle() = default;
    Rectangle(Point &&p1, Point &p2, Point &p3, Point &p4);
    Rectangle(std::istream &is);

    void print(std::ostream &os) const;
    double square() const;
    Point center() const;

    Figure& move(Figure &&other) noexcept; //* Move constructor
    Figure& operator=(const Figure &other); //* Copy constructor
    bool operator==(const Figure &other) const; //* Assignment operator
    
    virtual ~Rectangle() = default;
private:
    Point points[4]; // bottom-left, top-left, top-right, bottom-right
};