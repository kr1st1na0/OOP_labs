#include "trapezoid.hpp"

Trapezoid::Trapezoid(std::istream &is) {
    for (size_t i = 0; i < 4; ++i) {
        is >> points[i];
    }
}

Trapezoid::Trapezoid(Point &p1, Point &p2, Point &p3, Point &p4) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
}

void Trapezoid::print(std::ostream &os) const {
    for (const auto &p : points) {
        os << p << " ";
    }
    os << std::endl;
}

double Trapezoid::square() const {
    double square = 0.0;

    double x1 = (points[2].getX() - points[1].getX()) * (points[2].getX() - points[1].getX());
    double y1 = (points[2].getY() - points[1].getY()) * (points[2].getY() - points[1].getY());
    double a = std::sqrt(x1 + y1);

    double x2 = (points[3].getX() - points[0].getX()) * (points[3].getX() - points[0].getX());
    double y2 = (points[3].getY() - points[0].getY()) * (points[3].getY() - points[0].getY());
    double b = std::sqrt(x2 + y2);

    double h = std::fabs(points[1].getY() - points[0].getY());
    square = h * (a + b) / 2;
    return floor(square * 100) / 100;
}

Point Trapezoid::center() const {
    double x = 0.0;
    double y = 0.0;

    double x1 = (points[2].getX() - points[1].getX()) * (points[2].getX() - points[1].getX());
    double y1 = (points[2].getY() - points[1].getY()) * (points[2].getY() - points[1].getY());
    double a = std::sqrt(x1 + y1);

    double x2 = (points[3].getX() - points[0].getX()) * (points[3].getX() - points[0].getX());
    double y2 = (points[3].getY() - points[0].getY()) * (points[3].getY() - points[0].getY());
    double b = std::sqrt(x2 + y2);

    double h = points[1].getY() - points[0].getY();
    double min = std::min(a, b); 
    double max = std::max(a, b);

    x = floor((h / 2) * 100) / 100;
    y = floor((((max + 2 * min) * h) / (3 * (min + max))) * 100) / 100;
    return Point(x, y);
}

Figure& Trapezoid::move(Figure &&other) noexcept {
    const Trapezoid *otherTrapezoid = dynamic_cast<const Trapezoid*>(&other);
    for (size_t i = 0; i < 4; ++i) {
        points[i] = std::move(otherTrapezoid->points[i]);
    }
    return *this;
}

Figure& Trapezoid::operator=(const Figure &other) {
    const Trapezoid *otherTrapezoid = dynamic_cast<const Trapezoid*>(&other);
    for (size_t i = 0; i < 4; ++i) {
        points[i] = otherTrapezoid->points[i];
    }
    return *this;
}

bool Trapezoid::operator==(const Figure &other) const {
    const Trapezoid *otherTrapezoid = dynamic_cast<const Trapezoid*>(&other);
    for (size_t i = 0; i < 4; ++i) {
        if (points[i].getX() != otherTrapezoid->points[i].getX() || points[i].getY() != otherTrapezoid->points[i].getY()) {
            return 0;
        }
    }
    return 1;
}