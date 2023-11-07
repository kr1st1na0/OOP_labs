#pragma once

#include "point.hpp"
#include "figure.hpp"

template <class T>
struct Rectangle {
    std::array<point_t<T>, 4> points; // bottom-left, top-left, top-right, bottom-right
    Rectangle(const point_t<T> &p1, const point_t<T> &p2, const point_t<T> &p3, const point_t<T> &p4);
    double square() const;
    point_t<T> center() const;
    void print(std::ostream &os) const;
}

template <class T>
Rectangle::Rectangle(const point_t<T> &p1, const point_t<T> &p2, const point_t<T> &p3, const point_t<T> &p4) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
}

template <class T>
double Rectangle<T>::square() const {
    double square = 0;

    double xLength = (points[1].x - points[0].x) * (points[1].x - points[0].x);
    double yLength = (points[1].y - points[0].y) * (points[1].y - points[0].y);
    double length = std::sqrt(xLength + yLength);

    double xWidth = (points[2].x - points[1].x) * (points[2].x - points[1].x);
    double yWidth = (points[2].y - points[1].y) * (points[2].y - points[1].y);
    double width = std::sqrt(xWidth + yWidth);

    square = length * width;
    return floor(square * 100) / 100;
}

template <class T>
point_t<T> Rectangle<T>::center() const {
    T x = 0;
    T y = 0;
    x = floor(((points[2].x + points[0].x) / 2) * 100) / 100;
    y = floor(((points[2].y + points[0].y) / 2) * 100) / 100; 
    return {x, y};
}


template <class T>
void Rectangle<T>::print(std::ostream &os) const {
    for (const auto &p : points) {
        os << p << " ";
    }
    os << std::endl;
}
    
    

    // Figure& move(Figure &&other) noexcept; //* Move constructor
    // Figure& operator=(const Figure &other); //* Copy constructor
    // bool operator==(const Figure &other) const; //* Assignment operator
