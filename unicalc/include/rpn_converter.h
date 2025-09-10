#pragma once
#include"tokenizer.h"
#include<vector>
#include<stack>

class RPNconverter {
    public:
        static std::vector<token> toRPN(const std::vector<token>& tokens);
};