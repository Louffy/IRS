#include"../search/search.h"
int main()
{
	Parser p;
	IndexReader in;
    in.genIndexFromFile();
    Search s;
    string query;
	while (getline(cin,query)) {
        Query* q=p.parse(query);
        //cout<<"------"<<endl;
        //cout<<q->sign<<" "<<q->token<<endl;
        /*for(int i=0;i<q->size();i++)
        {
        	Query* s=q->get(i);
        	//cout<<s->sign<<" "<<s->token<<endl;
        	for(int j=0;j<s->size();j++)
        	{
        		Query* p=s->get(j);
        	//	cout<<p->sign<<" "<<p->token<<endl;
        	}
        }*/
        vector<vector<string> > l;
    	s.search(q,in,l);
    	s.show(q,in,l);
		delete q;
    }
}
