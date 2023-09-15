#include <gtest/gtest.h>
#include "solve.hpp"

TEST(test1, brackets) {
    std::string s = "()";
    ASSERT_TRUE(bracketsBalance(s) == true);
}

TEST(test2, brackets) {
    std::string s = ")(()))";
    ASSERT_TRUE(bracketsBalance(s) == false);
}

TEST(test3, brackets) {
    std::string s = "(";
    ASSERT_TRUE(bracketsBalance(s) == false);
}

TEST(test4, brackets) {
    std::string s = "(())((()())())";
    ASSERT_TRUE(bracketsBalance(s) == true);
}

TEST(test5, brackets) {
    std::string s = ")";
    ASSERT_TRUE(bracketsBalance(s) == false);
}

TEST(test6, brackets) {
    std::string s = "(((()";
    ASSERT_TRUE(bracketsBalance(s) == false);
}

TEST(test7, brackets) {
    std::string s = "";
    ASSERT_TRUE(bracketsBalance(s) == true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}