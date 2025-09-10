#include"unicalc/include/rpn_converter.h"
#include"unicalc/include/tokenizer.h"
#include<gtest/gtest.h>

TEST(RPNConverterTest, BasicConversion) {
    auto tokens = tokenizer::tokenize("2 + 3");
    auto rpn = RPNconverter::toRPN(tokens);
    
    ASSERT_EQ(rpn.size(), 3);
    EXPECT_EQ(rpn[0].value, "2");
    EXPECT_EQ(rpn[1].value, "3");
    EXPECT_EQ(rpn[2].value, "+");
}

TEST(RPNConverterTest, OperatorPrecedence) {
    auto tokens = tokenizer::tokenize("2 + 3 * 4");
    auto rpn = RPNconverter::toRPN(tokens);
    
    // Должно быть: 2 3 4 * +
    ASSERT_EQ(rpn.size(), 5);
    EXPECT_EQ(rpn[3].value, "*");
    EXPECT_EQ(rpn[4].value, "+");
}

TEST(RPNConverterTest, WithBrackets) {
    auto tokens = tokenizer::tokenize("(2 + 3) * 4");
    auto rpn = RPNconverter::toRPN(tokens);
    
    // Должно быть: 2 3 + 4 *
    ASSERT_EQ(rpn.size(), 5);
    EXPECT_EQ(rpn[2].value, "+");
    EXPECT_EQ(rpn[4].value, "*");
}