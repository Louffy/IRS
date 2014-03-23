#include "parser.h"
#include "query.h"
#include"../search/search.h"
Parser::Parser() {
    token = "";
    content = "";
    upto = 0;
    root = NULL;
}
Parser::~Parser() {
}

string Parser::next_token() {
	//cout<<"next_token"<<endl;
    string &c = content;
    int cur, sz = c.size();

    while (upto < sz && (c[upto] == ' ' || c[upto] == '\t'))
        upto++;

    if (upto >= sz)
        return "";

    if (upto < sz && (c[upto] == '(' || c[upto] == ')'))
        return c.substr(upto++,1);

    cur = upto;
    while (upto < sz && isalnum(c[upto]))
        upto++;
	//cout<<c.substr(cur, upto-cur)<<endl;
    return c.substr(cur, upto-cur);
}

void Parser::match(string s) {
	//cout<<"match"<<endl;
    if (!token.compare(s)) {
        token = next_token();
    } else {
        cerr<<"expect:'"<<s<<"' but got:'"<<token<<"'"<<endl;
        exit(1);
    }
}

Query* Parser::S() {
	//cout<<"S: "<<endl;
    Query* ret;
    if (!token.compare("(")) {
        match("(");
        ret = E();
        match(")");
    } else if (!token.compare("NOT")) {
    	//cout<<"S: not"<<endl;
        match("NOT");
        ret = new Query(SIGN_NOT);
        if (!token.compare("(")) {
            match("(");
            ret->add(E());
            match(")");
        } else {
            ret->add(new Query(token));
            token = next_token();
        }
    } else {
        ret = new Query(token);
        token = next_token();
    }
    return ret;
}

Query* Parser::T() {
	//cout<<"T: and"<<endl;
    Query* par = new Query(SIGN_AND);
    par->add(S());
    while (!token.compare("AND")) {
        match("AND");
        par->add(S());
    }
    if (par->size() == 1) {
    //cout<<"clear T"<<endl;
        Query* ret = par->get(0);
        par->clear();
        delete par;
        return ret;
    }
    return par;
}

Query* Parser::E() {
	//cout<<"E: or"<<endl;
    Query* par = new Query(SIGN_OR);
    par->add(T());
    while (!token.compare("OR")) {
        match("OR");
        par->add(T());
    }
    if (par->size() == 1) {
    	//cout<<"clear E"<<endl;
        Query* ret = par->get(0);
        par->clear();
        delete par;
        return ret;
    }
    return par;
}

Query* Parser::parse(string str) {
	//cout<<"parse"<<endl;
    upto = 0;
    content = str;
   
    token = next_token();
    //cout<<token<<endl;
    
    root = E();
   
    root->token = str;
    
    return root;
}


/*int main()
{
	Parser p;
	//IndexReader in;
    //in.genIndexFromFile();
    //Search s;
    string query;
	//while (getline(cin,query)) {
        Query* q=p.parse("brutus OR caesar AND calpurnia");
        cout<<"------"<<endl;
        cout<<q->sign<<" "<<q->token<<endl;
        for(int i=0;i<q->size();i++)
        {
        	Query* s=q->get(i);
        	cout<<s->sign<<" "<<s->token<<endl;
        	for(int j=0;j<s->size();j++)
        	{
        		Query* p=s->get(j);
        		cout<<p->sign<<" "<<p->token<<endl;
        		for(int k=0;k<p->size();k++)
        		{
        			Query* r=p->get(j);
        			cout<<r->sign<<" "<<r->token<<endl;
        		}
        	}
        }
    	//s.search(q,in);
    	//s.show(q,in);
		delete q;
    //}
}*/
