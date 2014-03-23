#include"indexreader.h"
const string IndexReader::indexpath="./input/index_data/index.txt";
const string IndexReader::fileidpath="./input/index_data/fileid.txt";
IndexReader::IndexReader()
{
}
IndexReader::~IndexReader()
{
}
void IndexReader::genIndexFromFile()
{
	fstream inFile;
	fstream inIndex;
	string line,word;
	int iterm,iterm2;
	inIndex.open(indexpath.c_str(),ios::in);
	inFile.open(fileidpath.c_str(),ios::in);
	if(!inFile || !inIndex)
	{
		cout<<"Index file has not created, please run myindex!";
		exit(0);
	}
	while(getline(inFile,line))
	{
		istringstream stream(line);
		stream>>iterm;
		stream>>word;
		alldoc.push_back(iterm);
		//cout<<alldoc.back()<<endl;
		docname[iterm]=word;
	}
	for(map<int,string>::iterator it=docname.begin();it!=docname.end();it++)
	{
		//cout<<it->first<<" "<<it->second<<endl;
	}
	while(getline(inIndex,line))
	{
		istringstream stream(line);
		stream>>word;
		stream>>iterm;
		vector<pos> pl;
		for(int i=0;i<iterm;i++)
		{
			pos p;
			getline(inIndex,line);
			istringstream stream2(line);
			stream2>>p.docid;
			getline(inIndex,line);
			istringstream stream3(line);
			while(stream3>>iterm2)
				p.position.push_back(iterm2);
			pl.push_back(p);
		}
		index[word]=pl;
	}
	inFile.close();
	inIndex.close();
	/*for(map<string,vector<pos> >::iterator it=index.begin();it!=index.end();it++)
	{
		cout<<it->first<<endl;
		for(int i=0;i<it->second.size();i++)
		{
			pos p=it->second[i];
			cout<<p.docid<<": ";
			for(int j=0;j<p.position.size();j++)
				cout<<p.position[j]<<" ";
			cout<<endl;
		}
	}
		*/
}

