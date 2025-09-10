#include"unicalc/include/rpn_calculator.h"
#include"unicalc/include/tokenizer.h"
#include"unicalc/include/rpn_converter.h"
#include<gtest/gtest.h>

TEST(RPNCalculatorTest, BasicOperations) {
    auto tokens = tokenizer::tokenize("2 3 +");
    auto result = RPNcalculator::calculate(tokens);
    EXPECT_DOUBLE_EQ(result, 5.0);
}

TEST(RPNCalculatorTest, ComplexExpression) {
    auto tokens = tokenizer::tokenize("2 3 4 * +"); // 2 + 3 * 4
    auto result = RPNcalculator::calculate(tokens);
    EXPECT_DOUBLE_EQ(result, 14.0);
}

TEST(RPNCalculatorTest, DivisionByZero) {
    auto tokens = tokenizer::tokenize("5 0 /");
    EXPECT_THROW(RPNcalculator::calculate(tokens), std::runtime_error);
}

TEST(RPNCalculatorTest, PowerOperation) {
    auto tokens = tokenizer::tokenize("2 3 ^"); // 2^3
    auto result = RPNcalculator::calculate(tokens);
    EXPECT_DOUBLE_EQ(result, 8.0);
}