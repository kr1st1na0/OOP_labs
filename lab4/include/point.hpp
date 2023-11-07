#pragma once

#include <iostream>
#include <cmath>

template <class T>
struct point_t {
    T x;
    T y;
}

template <class T>
std::istream &operator>>(std::istream &is, Point &p) {
    is >> p.x >> p.y;
    return is;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Point &p){
	os << "(" << p.x << ";" << p.y << ")"; 
	return os;
}

template <class T>
T Point::distance(const point_t<T> &other) {
    return std::sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
}