#pragma once

#include "figure.hpp"

template <typename T>
class Rectangle : public Figure<T> {
public:
    std::vector<std::pair<T, T> > points; // bottom-left, top-left, top-right, bottom-right

    Rectangle() {
        points.resize(4, {0, 0});
    }

    Rectangle(const std::vector<std::pair<T, T> > &v) : points(v) {
        if (v.size() != 4) {
            throw std::logic_error("Rectangle must have 4 points");
        }
    }

    T square() const {
        T length = points[1].second - points[0].second;
        T width = points[2].first - points[1].first;
        T square = length * width;
        return square;
    }

    typename Figure<T>::point center() const {
        T x = (points[2].first - points[1].first) / 2;
        T y = (points[1].second - points[0].second) / 2;
        return {x, y};
    }

    Rectangle& operator=(const Rectangle<T> &other) {
        points = other.points;
        return *this;
    }

    Rectangle& operator=(Rectangle<T> &&other) {
        points = std::move(other.points);
        return *this;
    }

    bool operator==(const Rectangle &other) const {
        for (size_t i = 0; i < 4; ++i) {
            if (points[i] != other.points[i]) {
                return 0;
            }
        }
        return 1;
    }

    operator double() const override;

    ~Rectangle() = default;
};

template <typename T>
std::istream &operator>>(std::istream &is, Rectangle<T> &r) {
    for (size_t i = 0; i < 4; ++i) {
        is >> r.points[i].first >> r.points[i].second;
    }
    return is;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Rectangle<T> &r) {
    for (size_t i = 0; i < 4; ++i) {
        os << "(" << r.points[i].first << ";" << r.points[i].second << ")"; 
    }
    return os;
}

template <typename T>
inline Rectangle<T>::operator double() const {
    return static_cast<double>(this->square());
}
