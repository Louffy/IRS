#ifndef UTIL_H
#define UTIL_H
#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<dirent.h>
#include<list>
#include<cstring>
#include<vector>
#include<sys/types.h>
#include<stdlib.h>
#include<algorithm>
#include<cctype>
#include<fstream>
#include<sstream>
#include<cmath>

using namespace std;
#define BUF 1024*1024
#define K 10
typedef struct document{
	string fname;
	string fcontent;
}doc;
typedef struct docposition{
	int docid;
	vector<int> position;
}pos;
char* trim(char *src);

string strtolow(string str);
void bool_not(list<int>&,vector<int>&,list<int>&);
void bool_and(list<int>&,list<int>&,list<int>&);
void bool_or(list<int>&,list<int>&,list<int>&);
void tokenspace(string str,vector<string> &tokens);
void positionintersect(vector<pos> &p1,vector<pos> &p2,vector<pos> &hits,int k);
void postolis(vector<pos> &v,list<int> &l);
void vectolis(vector<int> &v,list<int> &l);
int levenshteinDistance(string a,string b);
int minTri(int a,int b,int c);
#endif
