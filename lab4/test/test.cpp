#include <gtest/gtest.h>

#include "../include/figures.hpp"
#include <sstream>

TEST(rectangle, copy) {
    std::stringstream stream;
    stream << "0 4\n1 6\n9 0\n8 2\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (stream >> x >> y) {
        points.emplace_back(x, y);
    }
    Rectangle<double> r(points);
    Rectangle<double> r1;
    r1 = r;
    ASSERT_TRUE(r == r1);
}

TEST(rectangle, square) {
    std::stringstream stream;
    stream << "1 1\n1 3\n6 3\n6 1\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (stream >> x >> y) {
        points.emplace_back(x, y);
    }
    Rectangle<double> r(points);
    ASSERT_EQ(r.square(), 10.0);
}

TEST(rectangle, center) {
    std::stringstream stream;
    stream << "1 1\n1 3\n6 3\n6 1\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (stream >> x >> y) {
        points.emplace_back(x, y);
    }
    Rectangle<double> r(points);
    ASSERT_EQ(r.center().first, 2.5);
    ASSERT_EQ(r.center().second, 1.0);
}

TEST(rhombus, square) {
    std::stringstream stream;
    stream << "1 6\n4 10\n7 6\n4 2\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (stream >> x >> y) {
        points.emplace_back(x, y);
    }
    Rhombus<double> r(points);
    ASSERT_EQ(r.square(), 24.0);
}

TEST(rhombus, center) {
    std::stringstream stream;
    stream << "1 6\n4 10\n7 6\n4 2\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (stream >> x >> y) {
        points.emplace_back(x, y);
    }
    Rhombus<double> r(points);
    ASSERT_EQ(r.center().first, 3.0);
    ASSERT_EQ(r.center().second, 4.0);
}

TEST(trapezoid, square) {
    std::stringstream stream;
    stream << "1 1\n2 4\n4 4\n5 1\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (stream >> x >> y) {
        points.emplace_back(x, y);
    }
    Trapezoid<double> t(points);
    ASSERT_EQ(t.square(), 9.0);
}

TEST(trapezoid, center) {
    std::stringstream stream;
    stream << "1 1\n2 4\n4 4\n5 1\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (stream >> x >> y) {
        points.emplace_back(x, y);
    }
    Trapezoid<double> t(points);
    ASSERT_EQ(t.center().first, 3.0);
    ASSERT_EQ(t.center().second, 1.5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}