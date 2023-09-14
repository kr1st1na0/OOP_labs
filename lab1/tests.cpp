#include <gtest/gtest.h>
#include "solve.hpp"

TEST(test1, brackets) {
    std::string s = "()";
    ASSERT_TRUE("true");
}

TEST(test2, brackets) {
    std::string s = ")(()))";
    ASSERT_TRUE("false");
}

TEST(test3, brackets) {
    std::string s = "(";
    ASSERT_TRUE("false");
}

TEST(test4, brackets) {
    std::string s = "(())((()())())";
    ASSERT_TRUE("true");
}

TEST(test5, brackets) {
    std::string s = ")";
    ASSERT_TRUE("false");
}

TEST(test6, brackets) {
    std::string s = "(((()";
    ASSERT_TRUE("false");
}

TEST(test7, brackets) {
    std::string s = "";
    ASSERT_TRUE("false");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}