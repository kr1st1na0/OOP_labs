#pragma once

#include "point.hpp"
#include "figure.hpp"

template <class T>
struct Trapezoid {
    std::array<point_t<T>, 4> points; // bottom-left, top-left, top-right, bottom-right
    Trapezoid(const point_t<T> &p1, const point_t<T> &p2, const point_t<T> &p3, const point_t<T> &p4);
    double square() const;
    point_t<T> center() const;
    void print(std::ostream &os) const;
}

template <class T>
Trapezoid::Trapezoid(const point_t<T> &p1, const point_t<T> &p2, const point_t<T> &p3, const point_t<T> &p4) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
}

template <class T>
double Trapezoid<T>::square() const {
    double square = 0;

    double x1 = (points[2].x - points[1].x) * (points[2].x - points[1].x);
    double y1 = (points[2].y - points[1].y) * (points[2].y - points[1].y);
    double a = std::sqrt(x1 + y1);

    double x2 = (points[3].x - points[0].x) * (points[3].x - points[0].x);
    double y2 = (points[3].y - points[0].y) * (points[3].y - points[0].y);
    double b = std::sqrt(x2 + y2);

    double h = std::fabs(points[1].y - points[0].y);
    square = h * (a + b) / 2;
    return floor(square * 100) / 100;
}

template <class T>
point_t<T> Trapezoid<T>::center() const {
    T x = 0;
    T y = 0;

    double x1 = (points[2].x - points[1].x) * (points[2].x - points[1].x);
    double y1 = (points[2].y - points[1].y) * (points[2].y - points[1].y);
    double a = std::sqrt(x1 + y1);

    double x2 = (points[3].x - points[0].x) * (points[3].x - points[0].x);
    double y2 = (points[3].y - points[0].y) * (points[3].y - points[0].y);
    double b = std::sqrt(x2 + y2);

    double h = points[1].y - points[0].y;
    double min = std::min(a, b); 
    double max = std::max(a, b);

    x = floor((h / 2) * 100) / 100;
    y = floor((((max + 2 * min) * h) / (3 * (min + max))) * 100) / 100;
    return {x, y};
}


template <class T>
void Trapezoid<T>::print(std::ostream &os) const {
    for (const auto &p : points) {
        os << p << " ";
    }
    os << std::endl;
}
    
    

    // Figure& move(Figure &&other) noexcept; //* Move constructor
    // Figure& operator=(const Figure &other); //* Copy constructor
    // bool operator==(const Figure &other) const; //* Assignment operator
    
