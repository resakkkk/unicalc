#include"tokenizer.h"
#include<cctype>
#include<vector>

using namespace std;

vector<token> tokenizer::tokenize(const string& expression) {
    vector<token> tokens;
    string current;

    for(char c : expression) {
        if(isspace(c)) continue;

        if(isdigit(c) || c == '.') {
            current += c;
        } else {
            if(c == '(' || c == ')') {
                tokens.push_back({tokentype::BRACKET, string(1, c)});
            } else if (string("+-*/^").find(c) != string::npos) {
                tokens.push_back({tokentype::OPERATOR, string(1, c)});
            }
        }
    }

    if(!current.empty()) {
        tokens.push_back({tokentype::NUMBER, current});
    }

    return tokens;
}