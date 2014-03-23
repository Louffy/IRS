#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "query.h"

using namespace std;
class Parser {
public:
    Parser();
    ~Parser();
    Query * parse(string str);
    Query* E();
    Query* T();
    Query* S();
    string next_token();
    void match(string str);
    string content;
    string token; 
    int upto;
    Query* root;
};

#endif
