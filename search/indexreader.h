#ifndef INDEXREADER_H
#define INDEXREADER_H
#include"../util/util.h"

#include"../index/index.h"
#define BUF 1024*1024
using namespace std;


class IndexReader {
	public:
		
		static const string indexpath;
		static const string fileidpath;
		IndexReader();
		~IndexReader();
		void genIndexFromFile();
		
		vector<int> alldoc; //all doc
		map<int,string> docname; //doc id and name
		map<string,vector<pos> > index; //index :term - postings list
};
#endif
