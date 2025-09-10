#include<iostream>
#include"calculator.h"
#include"tokenizer.h"
#include"rpn_converter.h"

using namespace std;

int main() {
    string expr;
    cout << "enter expression: ";
    getline(cin, expr);

    try {
        cout << "=== DEBUG INFORMATION ===" << endl;
        auto tokens = tokenizer::tokenize(expr);
        cout << "tokens: ";
        for(const auto& token : tokens) {
            cout << "[" << token.value << "] ";
        }
        cout << endl;

        auto rpn = RPNconverter::toRPN(tokens);
        cout << "RPN: ";
        for(const auto& token : rpn) {
          cout << "[" << token.value << "] ";
        }
        cout << endl;

        double result = calculator::calculate(expr);
        cout << "result: " << result << endl;

    } catch(const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}
