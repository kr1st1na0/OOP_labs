#pragma once

#include "point.hpp"
#include "figure.hpp"

class Rectangle : public Figure {
public:
    Rectangle() = default;
    Rectangle(std::istream &is);

    void print(std::ostream &os) const override;
    double square() const override;
    Point center() const override;
   
    Rectangle(const Rectangle &other); //* Copy constructor
    Rectangle(Rectangle &&other) noexcept; //* Move constructor
    bool operator==(const Rectangle &other) const; //* Assignment operator
    
    virtual ~Rectangle() = default;
private:
    Point points[4]; // bottom-left, top-left, top-right, bottom-right
};