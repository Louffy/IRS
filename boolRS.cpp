#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<dirent.h>
#include<list>
#include<cstring>
#include<vector>
#include<sys/types.h>
using namespace std;
const int MAXS=100*1024*1024;
char buf[MAXS];
typedef struct document{
	string fname;
	string fcontent;
}doc;
vector<doc> docs;
void readallfile()
{
	struct dirent *pDirEntry=NULL;
	DIR *pDir=NULL;
	int len=50000000;
	FILE *fp;
	string dir="/home/zfx/input/";
	if((pDir=opendir("/home/zfx/input/"))==NULL)
	{
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
			cout<<dir<<endl;
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
				cout<<"Save : "<<pDirEntry->d_name<<endl;
			
			}
			dir="/home/zfx/input/";
			memset(buf,0,sizeof(buf));
		}
		closedir(pDir);
	}
//	cout<<docs[30].fcontent<<endl;
	cout<<docs[30].fname<<endl;
	cout<<docs[30].fcontent.length()<<endl;
	cout<<docs[42].fname<<endl;
	cout<<docs[42].fcontent.length()<<endl;
}
int main()
{
	map<string,int> index;
	index["hello"]=9;
	index["world"]=7;
	map<string,int>::iterator it=index.begin();
	while (it!=index.end())
	{
		cout<<it->first<<"   "<<it->second<<endl;
		it++;
	}
	readallfile();
}

