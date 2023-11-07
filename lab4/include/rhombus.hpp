#pragma once

#include "point.hpp"
#include "figure.hpp"

template <class T>
struct Rhombus {
    std::array<point_t<T>, 4> points; // left, top, right, bottom
    Rhombus(const point_t<T> &p1, const point_t<T> &p2, const point_t<T> &p3, const point_t<T> &p4);
    double square() const;
    point_t<T> center() const;
    void print(std::ostream &os) const;
}

template <class T>
Rhombus::Rhombus(const point_t<T> &p1, const point_t<T> &p2, const point_t<T> &p3, const point_t<T> &p4) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
}

template <class T>
double Rhombus<T>::square() const {
    double square = 0;

    double x1 = (points[2].x - points[0].x) * (points[2].x - points[0].x);
    double y1 = (points[2].y - points[0].y) * (points[2].y - points[0].y);
    double d1 = std::sqrt(x1 + y1);

    double x2 = (points[1].x - points[3].x) * (points[1].x - points[3].x);
    double y2 = (points[1].y - points[3].y) * (points[1].y - points[3].y);
    double d2 = std::sqrt(x2 + y2);

    square = d1 * d2 / 2;
    return floor(square * 100) / 100;
}

template <class T>
point_t<T> Rhombus<T>::center() const {
    T x = 0;
    T y = 0;
    x = floor(((points[2].x + points[0].x) / 2) * 100) / 100;
    y = floor(((points[2].y + points[0].y) / 2) * 100) / 100; 
    return {x, y};
}


template <class T>
void Rhombus<T>::print(std::ostream &os) const {
    for (const auto &p : points) {
        os << p << " ";
    }
    os << std::endl;
}
    
    

    // Figure& move(Figure &&other) noexcept; //* Move constructor
    // Figure& operator=(const Figure &other); //* Copy constructor
    // bool operator==(const Figure &other) const; //* Assignment operator
    
