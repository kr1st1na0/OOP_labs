#include <gtest/gtest.h>
#include "point.hpp"
#include "figure.hpp"
#include "rectangle.hpp"
#include "rhombus.hpp"
#include "trapezoid.hpp"
#include <sstream>

TEST(rectangle, copy) {
    std::stringstream stream;
    stream << "0 4\n1 6\n9 0\n8 2\n";
    Rectangle r(stream);
    Rectangle r1(r);
    ASSERT_TRUE(r == r1);
}

TEST(rectangle1, square) {
    std::stringstream stream;
    stream << "-5 -4\n-5 3\n2 3\n2 -4\n";
    Rectangle r(stream);
    ASSERT_EQ(r.square(), 49.00);
}

TEST(rectangle2, square) {
    std::stringstream stream;
    stream << "0 4\n1 6\n9 2\n8 0\n";
    Rectangle r(stream);
    ASSERT_EQ(r.square(), 20.00);
}

TEST(rectangle, center) {
    std::stringstream stream;
    stream << "2 -2\n2 2\n4 2\n4 -2\n";
    Rectangle r(stream);
    ASSERT_EQ(r.center().getX(), 3.00);
    ASSERT_EQ(r.center().getY(), 0.00);
}

TEST(rectangle, points) {
    Point p1 = {-5, -4};
    Point p2 = {-5, 3};
    Point p3 = {2, 3};
    Point p4 = {2, -4};
    Rectangle r(p1, p2, p3, p4);
    ASSERT_EQ(r.square(), 49.00);
}

TEST(rhombus, copy) {
    std::stringstream stream;
    stream << "7 6\n10 7\n9 4\n6 3\n";
    Rhombus r(stream);
    Rhombus r1(r);
    ASSERT_TRUE(r == r1);
}

TEST(rhombus1, square) {
    std::stringstream stream;
    stream << "1 6\n4 10\n7 6\n4 2\n";
    Rhombus r(stream);
    ASSERT_EQ(r.square(), 24.00);
}

TEST(rhombus2, square) {
    std::stringstream stream;
    stream << "2 5\n6 6\n5 2\n1 1\n";
    Rhombus r(stream);
    ASSERT_EQ(r.square(), 15.00);
}

TEST(rhombus1, center) {
    std::stringstream stream;
    stream << "7 6\n10 7\n9 4\n6 3\n";
    Rhombus r(stream);
    ASSERT_EQ(r.center().getX(), 8.00);
    ASSERT_EQ(r.center().getY(), 5.00);
}

TEST(rhombus2, center) {
    std::stringstream stream;
    stream << "0 2\n-2 6\n2 4\n4 0\n";
    Rhombus r(stream);
    ASSERT_EQ(r.center().getX(), 1.00);
    ASSERT_EQ(r.center().getY(), 3.00);
}

TEST(trapezoid, copy) {
    std::stringstream stream;
    stream << "0 4\n1 6\n9 0\n8 2\n";
    Trapezoid t(stream);
    Trapezoid t1(t);
    ASSERT_TRUE(t == t1);
}

TEST(trapezoid1, square) {
    std::stringstream stream;
    stream << "1 1\n4 7\n8 7\n10 1\n";
    Trapezoid t(stream);
    ASSERT_EQ(t.square(), 39.00);
}

TEST(trapezoid2, square) {
    std::stringstream stream;
    stream << "1 8\n4 4\n6 4\n5 8\n";
    Trapezoid t(stream);
    ASSERT_EQ(t.square(), 12);
}

TEST(trapezoid, center) {
    std::stringstream stream;
    stream << "1 1\n4 7\n8 7\n10 1\n";
    Trapezoid t(stream);
    ASSERT_EQ(t.center().getX(), 3.00);
    ASSERT_EQ(t.center().getY(), 2.61);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}