#pragma once
#include<vector>
#include<string>

using namespace std;

enum class tokentype {
    NUMBER,
    OPERATOR,
    BRACKET,
    FUNCTION
};

struct token {
    tokentype type;
    string value;
};

class tokenizer {
    public:
        static vector<token> tokenize(const string& expression);
};