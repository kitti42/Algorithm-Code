/*
	Name: KRiti Dang
	Copyright: 
	Author: 
	Date: 13/12/13 20:25
	Description: Ternary Search tries implementation
*/
#include<iostream>
using namespace std;
//--------------------------------------------------------

class TST
{
	private:
		
		struct node
		{		
			int val;
			char c;
			node *parent;
			node *left,*right,*middle;
				
			public:
				
				node()
				{
					left=NULL;
					right=NULL;
					middle=NULL;
					parent=NULL;
					val=-1;
					c=NULL;
				}
		};
		node *root=new node;
	
		node * _get(string key,node *x,int d)
		{
			if(x==NULL)
				return NULL;
			if(x->c>key[d])
				return _get(key,x->left,d);
			else if(x->c<key[d])
				return _get(key,x->right,d);
			else if(d<key.size()-1)
				return _get(key,x->middle,d+1);
			else 
				return x;
		}
	     
	    int get(string key)
	    {
	    	node * x=_get(key,root,0);
	    	if(x==NULL)
	    		return -1;
	    	else if(x->val==-1)
	    		return -1;
	    	else return x->val;
	    }
		
		node * _insert(string s,node *x,node * p,int value,int d)
		{
			if(x==NULL)
			{
				x=new node;
				x->c=s[d];
				if(x!=root)	
					x->parent=p;
			}
			if(x->c<s[d])
			{
				x->right=_insert(s,x->right,x,value,d);
			}
			else if(x->c>s[d])
			{
				x->left=_insert(s,x->left,x,value,d);
			}
			else if(d<s.size()-1)
			{
				x->middle=_insert(s,x->middle,x,value,d+1);
			}
			else
				x->val=value;
			return x;
		}
		
	public:
		
		bool isString(string s)
		{
			return get(s)!=-1;
		}
		
		void insert(string s,int value)
		{
			root= _insert(s,root,root,value,0);
		}
};

//---------------------------------------------------------------

int main()
{
	TST a;
	a.insert("kriti",1);
	a.insert("paras",2);
	string s="paras";
	cout<<a.isString(s);
}
