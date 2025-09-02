#pragma once
#include"tokenizer.h"
#include<vector>

class RPNcalculator {
    static double calculate(const std::vector<token>& rpnTokens);
};