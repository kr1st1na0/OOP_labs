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

    Rectangle(const Rectangle &other); //* Copy constructor
    Rectangle(Rectangle &&other) noexcept; //* Move constructor
    bool operator==(const Rectangle &other) const; //* Assignment operator
    
    ~Rectangle() = default;
private:
    Point points[4]; // bottom-left, top-left, top-right, bottom-right
};