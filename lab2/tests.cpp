#include <gtest/gtest.h>
#include "Octal.hpp"

TEST(test1, copy) {
    Octal num1("15");
    Octal num2(num1);
    ASSERT_TRUE(num1 == num2);
}

TEST(test2, assignment) {
    Octal num1({'1', '6', '4', '7'});
    Octal num2 = num1;
    ASSERT_TRUE(num1 == num2);
}

TEST(test3, equal1) {
    Octal num1("1234");
    Octal num2({'1', '2', '3', '4'});
    ASSERT_TRUE(num1 == num2);
}

TEST(test4, equal2) {
    Octal num1("1234");
    Octal num2({'2', '2', '3', '4'});
    ASSERT_FALSE(num1 == num2);
}

TEST(test5, not_equal1) {
    Octal num1("1234");
    Octal num2({'2', '4', '6', '4'});
    ASSERT_TRUE(num1 != num2);
}

TEST(test6, not_equal2) {
    Octal num1("7324");
    Octal num2({'7', '3', '2', '4'});
    ASSERT_FALSE(num1 != num2);
}

TEST(test7, less) {
    Octal num1("74");
    Octal num2({'1', '3', '2'});
    ASSERT_TRUE(num1 < num2);
}

TEST(test8, less_equal) {
    Octal num1("12554");
    Octal num2({'3', '5'});
    ASSERT_FALSE(num1 <= num2);
}

TEST(test9, more) {
    Octal num1("543");
    Octal num2({'7'});
    ASSERT_TRUE(num1 > num2);
}

TEST(test10, more_equal) {
    Octal num1("73");
    Octal num2({'7', '3'});
    ASSERT_TRUE(num1 >= num2);
}

TEST(test11, addition) {
    Octal num1("5");
    Octal num2({'1', '6'});
    ASSERT_TRUE((num1 + num2) == Octal("23"));
}

// TEST(test12, substraction) {
//     Octal num1("76");
//     Octal num2({'6'});
//     ASSERT_TRUE((num1 - num2) == Octal("70"));
// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}