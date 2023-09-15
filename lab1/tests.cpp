#include <gtest/gtest.h>
#include "solve.hpp"

TEST(test1, brackets) {
    std::string s = "()";
    ASSERT_TRUE(bracketsBalance(s));
}

TEST(test2, brackets) {
    std::string s = ")(()))";
    ASSERT_FALSE(bracketsBalance(s));
}

TEST(test3, brackets) {
    std::string s = "(";
    ASSERT_FALSE(bracketsBalance(s));
}

TEST(test4, brackets) {
    std::string s = "(())((()())())";
    ASSERT_TRUE(bracketsBalance(s));
}

TEST(test5, brackets) {
    std::string s = ")";
    ASSERT_FALSE(bracketsBalance(s));
}

TEST(test6, brackets) {
    std::string s = "(((()";
    ASSERT_FALSE(bracketsBalance(s));
}

TEST(test7, brackets) {
    std::string s = "";
    ASSERT_TRUE(bracketsBalance(s));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}