#include "rectangle.hpp"

Rectangle::Rectangle(std::istream &is) {
    for (size_t i = 0; i < 4; i++) {
        is >> points[i];
    }
}

void Rectangle::print(std::ostream &os) const {
    for (const auto &p : points) {
        os << p << " ";
    }
    os << std::endl;
}

double Rectangle::square() const {
    double square = 0.0;

    double xLength = (points[1].getX() - points[0].getX()) * (points[1].getX() - points[0].getX());
    double yLength = (points[1].getY() - points[0].getY()) * (points[1].getY() - points[0].getY());
    double length = std::sqrt(xLength + yLength);

    double xWidth = (points[2].getX() - points[1].getX()) * (points[2].getX() - points[1].getX());
    double yWidth = (points[2].getY() - points[1].getY()) * (points[2].getY() - points[1].getY());
    double width = std::sqrt(xWidth + yWidth);

    square = length * width;
    return floor(square * 100) / 100;
}

Point Rectangle::center() const {
    double x = 0.0;
    double y = 0.0;
    x = floor(((points[2].getX() + points[0].getX()) / 2) * 100) / 100;
    y = floor(((points[2].getY() + points[0].getY()) / 2) * 100) / 100; 
    return Point(x, y);
}

Rectangle::Rectangle(const Rectangle &other) {
    for (size_t i = 0; i < 4; i++) {
        points[i] = other.points[i];
    }
}

Rectangle::Rectangle(Rectangle &&other) noexcept {
    for (size_t i = 0; i < 4; i++) {
        points[i] = std::move(other.points[i]);
    }
}

bool Rectangle::operator==(const Rectangle &other) const {
    for (size_t i = 0; i < 4; i++) {
        if (points[i].getX() != other.points[i].getX() || points[i].getY() != other.points[i].getY()) {
            return 0;
        }
    }
    return 1;
}