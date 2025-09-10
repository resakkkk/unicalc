#pragma once
#include"tokenizer.h"
#include<vector>
#include<stack>

class RPNcalculator {
    public:
        static double calculate(const std::vector<token>& rpntokens);
};