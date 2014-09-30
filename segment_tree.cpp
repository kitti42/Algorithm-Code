#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class segment_tree
{
	private:
		vector<int> tree;
		
		bool _inRange(int nodeLeft,int nodeRight,int queryLeft,int queryRight)
		{
			if(nodeLeft>nodeRight || queryRight<nodeLeft || nodeRight<queryLeft)
				return false;
			return true;
		}
		
		void update(int nodeLeft,int nodeRight,int queryLeft,int queryRight,int node,int value)
		{
			if(!_inRange(nodeLeft,nodeRight,queryLeft,queryRight))
				return;
			if(nodeLeft==nodeRight)
				tree[node]= value;
			else
			{
				update(nodeLeft,(nodeLeft+nodeRight)/2,queryLeft,queryRight,node*2+1,value);
				update(((nodeLeft+nodeRight)/2)+1,nodeRight,queryLeft,queryRight,node*2+2,value);
				tree[node]=min(tree[node*2+1],tree[node*2+2]);
			}
		}
		
		int query(int nodeLeft,int nodeRight,int queryLeft,int queryRight,int node)
		{
			if(!_inRange(nodeLeft,nodeRight,queryLeft,queryRight))
				return INT_MAX;
			if(nodeLeft>=queryLeft && nodeRight<=queryRight) 
				return tree[node];
			else
				return min(query(nodeLeft,(nodeLeft+nodeRight)/2,queryLeft,queryRight,node*2+1),query(((nodeLeft+nodeRight)/2)+1,nodeRight,queryLeft,queryRight,node*2+2));
		}
	public:
		void assign(int n)
		{
			tree.resize(4*n,INT_MAX);
		}
		void update(int pos,int val)
		{
			update(0,tree.size()/4-1,pos,pos,0,val);//tree.size()/4 = n
		}
		int query(int low,int high)
		{
			return query(0,tree.size()/4-1,low,high,0);
		}
};

int main()
{
	int n;
	cin>>n;
	segment_tree T;
	T.assign(n);
	while(1)
	{
		int type,a,b,val;
		cin>>type;
		if(type)
		{
			cin>>a>>b;
			cout<<T.query(a,b);
		}
		else
		{
			cin>>a>>val;
			T.update(a,val);	
		}
	}
}
