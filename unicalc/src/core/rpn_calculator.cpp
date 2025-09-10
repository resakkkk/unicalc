#include"rpn_calculator.h"
#include<cmath>
#include<stdexcept>
#include<stack>

using namespace std;

double RPNcalculator::calculate(const vector<token>& rpntokens) {
    stack<double> values;

    for(const auto& token : rpntokens) {
        if(token.type == tokentype::NUMBER) {
            values.push(stod(token.value));
        } else {

            if(values.size()<2) {
                throw runtime_error("not enough operands for operator: " + token.value);
            }

            double b = values.top(); values.pop();
            double a = values.top(); values.pop();

            switch(token.value[0]) {
                case '+': values.push(a+b); break;
                case '-': values.push(a-b); break;
                case '*': values.push(a*b); break;
                case '/':
                    if(b==0) throw runtime_error("Division by zero");
                    values.push(a/b);
                    break;
                case '^': values.push(pow(a,b)); break;
            }
        }
    }

    return values.top();
}