#include"unicalc/include/calculator.h"
#include<gtest/gtest.h>

TEST(calculatortest, IntegrationTest) {
    EXPECT_DOUBLE_EQ(calculator::calculate("2 + 3"), 5.0);
    EXPECT_DOUBLE_EQ(calculator::calculate("2 + 3 * 4"), 14.0);
    EXPECT_DOUBLE_EQ(calculator::calculate("(2 + 3) * 4"), 20.0);
    EXPECT_DOUBLE_EQ(calculator::calculate("2 ^ 3 + 1"), 9.0);
}

TEST(calculatortest, InvalidExpression) {
    EXPECT_THROW(calculator::calculate("2 + "), std::runtime_error);
    EXPECT_THROW(calculator::calculate("2 + * 3"), std::runtime_error);
}