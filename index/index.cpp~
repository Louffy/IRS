#include "index.h"
#include "../util/util.h"
#include<iostream>
using namespace std;
const string Index::datapath="../input/doc_data/";
const string Index::indexpath="../input/index_data/index.txt";
const string Index::fileidpath="../input/index_data/fileid.txt";
Index::Index()
{
}
Index::~Index()
{
}
void Index::genIndex()
{
	const char *spilt="[]\t\r\n ,()+-.|\"':?~!;";
	for(int i = 0;i < docs.size(); i++)
	{   
		cout<<i<<endl;
		//cout<<docs[0].fcontent.length()<<endl;
		char *str=(char *)malloc(docs[i].fcontent.length()+10);
		int position=0;
		if(str==NULL)
		{
			cout<<"malloc error!"<<endl;
			return;
		}
		//cout<<sizeof(str)<<endl;
		strcpy(str,docs[i].fcontent.c_str());
		char *str2=str;
		char *p=strtok(str,spilt);
		while(p)
		{
//			p=trim(p);
			string temp=p;
			temp=strtolow(temp);
			if(index.find(temp)==index.end())
			{
				vector<pos> pl;
				pos t;
				t.docid=i;
				t.position.push_back(position);
				pl.push_back(t);
				index.insert(pair<string,vector<pos> >(temp,pl));
			}
			else if(index.at(temp).back().docid!=i)
			{
				pos t;
				t.docid=i;
				t.position.push_back(position);
				index.at(temp).push_back(t);
			}
			else
			{
				index.at(temp).back().position.push_back(position);
			}
			//cout<<"--"<<p<<"--"<<endl;
			position+=(temp.length()+1);
			p=strtok(NULL,spilt);
		}
		free(str2);
	}
	//add the length of postings lists	
	for(map<string,vector<pos> >::iterator it=index.begin();it!=index.end();it++)
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
}
//see indexreader.cpp
/*void Index::genIndexFromFile()
{
	fstream inFile;
	fstream inIndex;
	string line,word;
	int iterm;
	inIndex.open(indexpath.c_str(),ios::in);
	inFile.open(fileidpath.c_str(),ios::in);
	if(!inFile || !inIndex)
	{
		cout<<"Index file not create, please run myindex!";
		return;
	}
	while(getline(inFile,line))
	{
		istringstream stream(line);
		stream>>iterm;
		stream>>word;
		docname[iterm]=word;
	}
	
	while(getline(inIndex,line))
	{
		istringstream stream(line);
		stream>>word;
		list<int> docid;
		while(stream>>iterm)
			docid.push_back(iterm);
		index[word]=docid;
	}
	
	inFile.close();
	inIndex.close();
		
}*/
void Index::writeIndexFile()
{
	ofstream wIndex(indexpath.c_str());
	ofstream wId(fileidpath.c_str());
	
	for(map<string,vector<pos> >::iterator it=index.begin();it!=index.end();it++)
	{
		wIndex<<it->first<<" "<<it->second.size()<<"\n";
		for(vector<pos>::iterator itv=it->second.begin();itv!=it->second.end();itv++)
		{
			wIndex<<itv->docid<<"\n";
			for(vector<int>::iterator itp=itv->position.begin();itp!=itv->position.end();itp++)
				wIndex<<*itp<<" ";
			wIndex<<"\n";
		}
	}
	for(int i=0;i<docs.size();i++)
	{
		wId<<i<<" "<<docs[i].fname<<"\n";
	}
	wId.close();
	wIndex.close();
}
void Index::readDocsFile()
{
	struct dirent *pDirEntry=NULL;
	DIR *pDir=NULL;
	int len=BUF;
	char buf[BUF+1];
	FILE *fp;
	string dir=datapath;
	
	if((pDir=opendir(dir.c_str()))==NULL)
	{
		cout<<dir<<endl;
		cout<<"open dir failed!"<<endl;
	}
	else
	{
		int i=1;
		
		while((pDirEntry=readdir(pDir))!=NULL)
		{
			if(!strcmp(pDirEntry->d_name,"..")||!strcmp(pDirEntry->d_name,"."))
				continue;
			cout<<i<<" Read OK : "<<pDirEntry->d_name<<endl;
			i++;
			dir=dir+pDirEntry->d_name;
		//	cout<<dir<<endl;
			if((fp=fopen(dir.c_str(),"r"))==NULL)
			{
				cout<<"open file error"<<endl;
			}
			else
			{
				fread(buf,1,len,fp);
		//		cout<<buf<<endl;
				fclose(fp);
				doc pdoc;
				pdoc.fname=pDirEntry->d_name;
				pdoc.fcontent=buf;
				docs.push_back(pdoc);
			//	cout<<"Save : "<<pDirEntry->d_name<<endl;
			
			}
			dir=datapath;
			memset(buf,0,sizeof(buf));
		}
		closedir(pDir);
	}
	cout<<"Read all files OK"<<endl;
//	cout<<docs[30].fcontent<<endl;
	
}


