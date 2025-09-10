#include"unicalc/include/tokenizer.h"
#include<gtest/gtest.h>

TEST(TokenizerTest, BasicOperations) {
    auto tokens = tokenizer::tokenize("2 + 3 * 4");
    ASSERT_EQ(tokens.size(), 5);
    EXPECT_EQ(tokens[0].value, "2");
    EXPECT_EQ(tokens[1].value, "+");
    EXPECT_EQ(tokens[2].value, "3");
    EXPECT_EQ(tokens[3].value, "*");
    EXPECT_EQ(tokens[4].value, "4");
}

TEST(TokenizerTest, WithBrackets) {
    auto tokens = tokenizer::tokenize("(2 + 3) * 4");
    ASSERT_EQ(tokens.size(), 7);
    EXPECT_EQ(tokens[0].value, "(");
    EXPECT_EQ(tokens[3].value, ")");
}

TEST(TokenizerTest, DecimalNumbers) {
    auto tokens = tokenizer::tokenize("3.14 * 2.5");
    ASSERT_EQ(tokens.size(), 3);
    EXPECT_EQ(tokens[0].value, "3.14");
    EXPECT_EQ(tokens[2].value, "2.5");
}

TEST(TokenizerTest, IgnoresSpaces) {
    auto tokens = tokenizer::tokenize("  2  +  3  ");
    ASSERT_EQ(tokens.size(), 3);
    EXPECT_EQ(tokens[0].value, "2");
    EXPECT_EQ(tokens[1].value, "+");
    EXPECT_EQ(tokens[2].value, "3");
}