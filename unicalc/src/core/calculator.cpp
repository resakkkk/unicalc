#include"calculator.h"
#include"tokenizer.h"
#include"rpn_calculator.h"
#include"rpn_converter.h"

double calculator::calculate(const std::string& expression) {
    auto tokens = tokenizer::tokenize(expression);
    auto rpn = RPNconverter::toRPN(tokens);
    return RPNcalculator::calculate(rpn);
}