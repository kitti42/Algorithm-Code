#include<iostream>
#define MAX 30
using namespace std;
//----------------------------------------------------


template<class T,class hash,size_t R>class trie
{
	private:
		
		struct node                          //A structure of a single node
		{
			T value;
			node *child[R];
			node *parent;
			
			node()
			{
				for(size_t i=0;i<R;i++)
				child[i]=NULL;
				parent=NULL;
			}
		};
		
		node *root;
		
	public:
		
		trie()
		{
			root=NULL;
		}
		
		template<class iterator> void insert(iterator begin,iterator end,T val)
		{
			if(root==NULL)
			{
				root=new node;
			}
			node *current=root;
			
			while(begin!=end)
			{
				size_t t=hash(*begin);
				if(current->child[t]==NULL)
				{
					current->child[t]=new node;
					current->child[t]->parent=current;
				}
				
				current=current->child[t];
				begin++;
			}
			
			current->value=val;
		}
		 
		T & operator[](char *a)                        //while inserting element like a["kitti"]=25 , the adress of loctation gets returned
		                                                 //  which stores the value 25, else its value gets returned.
		{
			if(root==NULL)
			{
				root=new node;
			}
			node *current=root;
			
			while(*a)
			{
				size_t t=hash(*a);
				if(current->child[t]==NULL)
				{
					current->child[t]=new node;
					current->child[t]->parent=current;
				}
				
				current=current->child[t];
				a++;
			}
			
			return current->value;   
		}
};
//-------------------------------------------------------------

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		trie<node>U;
		int n;
		cin>>n;
		
		U.clear();
		int a[n+1];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		U.insert(a[0]);
		
	}
}

