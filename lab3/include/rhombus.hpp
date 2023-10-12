#pragma once

#include "point.hpp"
#include "figure.hpp"

class Rhombus : public Figure {
public:
    Rhombus() = default;
    Rhombus(std::istream &is);

    void print(std::ostream &os) const override;
    double square() const override;
    Point center() const override;
   
    Rhombus(const Rhombus &other); //* Copy constructor
    Rhombus(Rhombus &&other) noexcept; //* Move constructor
    bool operator==(const Rhombus &other) const; //* Assignment operator
    
    virtual ~Rhombus() = default;
private:
    Point points[4]; // left, top, right, bottom
};