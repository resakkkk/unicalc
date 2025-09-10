#include"rpn_converter.h"
#include<stack>
#include<map>

using namespace std;

vector<token> RPNconverter::toRPN(const vector<token>& tokens) {
    vector<token> output;
    stack<token> ops;

    map<string, int> precedence = {
        {"+", 1}, {"-", 1},
        {"*", 2}, {"/", 2},
        {"^", 3}
    };

    for(const auto& token : tokens) {
        if(token.type == tokentype::NUMBER) {
            output.push_back(token);
        } else if(token.type == tokentype::OPERATOR) {
            while (!ops.empty() && ops.top().type == tokentype::OPERATOR && precedence[ops.top().value] >= precedence[token.value]) {
                output.push_back(ops.top());
                ops.pop();
            }
            ops.push(token);
        } else if(token.value == "(") {
            ops.push(token);
        } else if(token.value == ")") {
            while (!ops.empty() && ops.top().value != "(") {
                output.push_back(ops.top());
            }
            ops.pop();
        }
    }

    while(!ops.empty()) {
        output.push_back(ops.top());
        ops.pop();
    }

    return output;
}