/*
	Name: Kriti Dang
	Copyright: 
	Author: 
	Date: 16/12/13 21:01
	Description: Tries having Functions 
				1:insert
				2:search
*/

#include<iostream>
#define R 256
using namespace std;
//----------------------------------------------------


class trie
{
	private:
		
		struct node                          //A structure of a single node
		{
			int value;
			node *next[R];
			node *parent;
			
			node()
			{
				for(size_t i=0;i<R;i++)
				next[i]=NULL;
				parent=NULL;
				value=-1;
			}
		};
		
		node *root;
		
		node * _insert(node *x,string key,int val,int d)
		{
			if(x==NULL)
				x=new node;
			if(d==key.size())
			{
				x->value=val;
				return x;
			}
			char c=key[d];
			x->next[c]=_insert(x->next[c],key,val,d+1);
			return x;
		}
		
		node *_get(node *x,string key,int d)
		{
			if(x==NULL)
				return NULL;
			if(d==key.size())
				return x;
			char c=key[d];
			return _get(x->next[c],key,d+1);
		}
		
		node * _del(node *x,string key,int d)
		{
			if(d==key.size())
				return x;
			char c=key[d];
			return _del(x->next[c],key,d+1);
			size_t i;
			for(i=0;i<R;i++)
			{
				if(x->next[i]!=NULL)
				return x->next[i];
			}
			if(i==R)
			{
			delete x;}
		}
		
	public:
		
		trie()
		{
			root=NULL;
		}
		
		void insert(string key,int val)
		{
			root=_insert(root,key,val,0);
		}
	    
	    bool contains(string key)
	    {
	    	return get(key)!=-1;
	    }
	    
	    int get(string key)
	    {
	    	node *x=_get(root,key,0);
	    	if(x==NULL)
	    		return -1;
	    	return (int)x->value;
	    }
	    
	    void del(string key)                        //assuming that string to be deleted is present in trie...
		{
			_del(root,key,0);
		}
};
//-------------------------------------------------------------

int main()
{
	trie U;
	U.insert("kriti",1);
	U.insert("shobhit",2);
	string a;
	cin>>a;
	U.del(a);
	int n;
	cin>>n;
	while(n--)
	{
		cin>>a;
		cout<<U.contains(a)<<endl;
	}
}

