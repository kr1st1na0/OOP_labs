#include "rhombus.hpp"

Rhombus::Rhombus(std::istream &is) {
    for (size_t i = 0; i < 4; i++) {
        is >> points[i];
    }
}

void Rhombus::print(std::ostream &os) const {
    for (const auto &p : points) {
        os << p << " ";
    }
    os << std::endl;
}

double Rhombus::square() const {
    double square = 0.0;

    double x1 = (points[2].getX() - points[0].getX()) * (points[2].getX() - points[0].getX());
    double y1 = (points[2].getY() - points[0].getY()) * (points[2].getY() - points[0].getY());
    double d1 = std::sqrt(x1 + y1);

    double x2 = (points[1].getX() - points[3].getX()) * (points[1].getX() - points[3].getX());
    double y2 = (points[1].getY() - points[3].getY()) * (points[1].getY() - points[3].getY());
    double d2 = std::sqrt(x2 + y2);

    square = d1 * d2 / 2;
    return floor(square * 100) / 100;
}

Point Rhombus::center() const {
    double x = 0.0;
    double y = 0.0;
    x = floor(((points[2].getX() + points[0].getX()) / 2) * 100) / 100;
    y = floor(((points[2].getY() + points[0].getY()) / 2) * 100) / 100; 
    return Point(x, y);
}

Rhombus::Rhombus(const Rhombus &other) {
    for (size_t i = 0; i < 4; i++) {
        points[i] = other.points[i];
    }
}

Rhombus::Rhombus(Rhombus &&other) noexcept {
    for (size_t i = 0; i < 4; i++) {
        points[i] = std::move(other.points[i]);
    }
}

bool Rhombus::operator==(const Rhombus &other) const {
    for (size_t i = 0; i < 4; i++) {
        if (points[i].getX() != other.points[i].getX() || points[i].getY() != other.points[i].getY()) {
            return 0;
        }
    }
    return 1;
}