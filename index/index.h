#ifndef INDEX_H
#define INDEX_H
#include"../util/util.h"
using namespace std;


class Index {
	public:
		static const string datapath;
		static const string indexpath;
		static const string fileidpath;
		Index();
		~Index();
		void readDocsFile();
		void writeIndexFile();
		void genIndex();
		//void genIndexFromFile();
		
		vector<doc> docs; //docs info
		map<int,string> docname; //doc id and name
		map<string,vector<pos> > index; //index :term - postings list
};
#endif
