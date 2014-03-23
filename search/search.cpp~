#include"search.h"
Search::Search() {
}
Search::~Search() {
}
void Search::search(Query *q,IndexReader myindex,vector<vector<string> > &s) {
    if (q->sign == SIGN_NULL) {
        string t= q->token;
        //cout<<"==="<<t<<endl;
        int tid;
        t=strtolow(t);
        list<int> l;
        vector<string> tokens;
        tokenspace(t,tokens);
        proximitysearch(myindex,tokens,l);
        s.push_back(tokens);
        q->docs()=l;
        return;
    }
    for (unsigned i=0; i<q->size(); i++) {
        search(q->get(i),myindex,s);
    }
    q->optimize();
	list<int> temp;
    switch(q->sign) {
    case SIGN_NOT:
        bool_not(q->docs(),myindex.alldoc, q->get(0)->docs()); 
        break;
    case SIGN_AND:
    	//cout<<q->docs().size()<<" "<<q->get(0)->docs().size()<<endl;
        bool_or(temp,q->docs(), q->get(0)->docs());
        q->docs()=temp;
        for (unsigned i=1; i<q->size(); i++) {
            bool_and(temp,q->docs(), q->get(i)->docs());
            q->docs()=temp;
        }
        break;
    case SIGN_OR:
        for (unsigned i=0; i<q->size(); i++) {
            bool_or(temp,q->docs(), q->get(i)->docs());
            q->docs()=temp;
        }
        break;
    default:
        break;
    }
}
void Search::proximitysearch(IndexReader myindex,vector<string> &tokens,list<int> &l){
		
        if (myindex.index.find(tokens[0]) == myindex.index.end())
        	tokens[0]=spellCorrect(myindex,tokens[0]);
        vector<pos> p1=myindex.index[tokens[0]];	
        if(tokens.size()==1)
        {
        	postolis(p1,l);
        }
        else{
        	for(int i=1;i<tokens.size();i++)
        	{
        		if (myindex.index.find(tokens[i]) == myindex.index.end())
        			tokens[i]=spellCorrect(myindex,tokens[i]);
        		vector<pos> p2=myindex.index[tokens[i]];
        		vector<pos> p3;
        		positionintersect(p1,p2,p3,K);
        		p1=p3;
        	}
        	postolis(p1,l);
        }
}
string Search::spellCorrect(IndexReader myindex,string str)
{
	int min=100;//large distance
	string replace;
	for(map<string,vector<pos> >::iterator it=myindex.index.begin();it!=myindex.index.end();it++)
	{
		if(levenshteinDistance(it->first,str)<min)
		{
			replace=it->first;
			min=levenshteinDistance(it->first,str);
		}
	}
	//cout<<str<<" "<<replace<<" "<<min<<endl;
	return replace;
}
void Search::show(Query* q,IndexReader index,vector<vector<string> > s) 
{
	
    cout << "query: " << q->token << endl;
    cout<<"Spell correction: ";
    for(vector<vector<string> >::iterator it = s.begin();it!=s.end();it++)
    {
    	for(vector<string>::iterator its=it->begin();its!=it->end();its++)
    		cout<<*its<<" ";
    }
    cout<<endl;
    
    cout << "hit: " << q->docs().size() << endl;
  
    for (list<int>::iterator it=q->docs().begin(); it!=q->docs().end(); it++) {
        cout<<*it<<" "<<index.docname[*it]<< endl;
    }
    cout <<"----------------------------------"<< endl;
}

