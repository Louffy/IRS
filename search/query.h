#ifndef QUERY_H
#define QUERY_H

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>

using namespace std;

enum Sign {
    SIGN_NULL,
    SIGN_AND,
    SIGN_OR,
    SIGN_NOT
};
class Query { 
public:
    Sign sign;     
    string token; 
    list<int> hit_docs;

private:
    vector<Query*> children; 

public:
    Query(Sign s);
    Query(string t);
    ~Query();

    void add(Query* n);
    unsigned size();
    void clear();
    Query* get(int i);
    list<int>& docs();
    void optimize(); 
    void dump();
};
#endif
