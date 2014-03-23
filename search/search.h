#ifndef SEARCH_H
#define SEARCH_H
#include<iostream>
#include"indexreader.h"
#include"query.h"
#include"../util/util.h"
#include"parser.h"
using namespace std;
class Search{
	public :
		Search();
		~Search();
		void search(Query *q,IndexReader index,vector<vector<string> > &s);
		void show(Query* q,IndexReader index,vector<vector<string> > s);
		string spellCorrect(IndexReader index,string str);
		void proximitysearch(IndexReader index,vector<string> &str,list<int> &l);
};
#endif
