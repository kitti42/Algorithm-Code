#include<iostream>
#include<vector>
using namespace std;
//------------------------------------------------

vector<int> table;                 //to store the ans..:)
vector<int> check;                   //to check kaun kitni baar aa skta h...
int n;	
int sum=0;                        //to check the constrain,sum of all value==n

bool solve(int currentColumn=0)
{
	/*for(int i=0;i<n;i++)
		cout<<table[i]<<" ";
	cout<<endl;
	
	for(int i=0;i<n;i++)
		cout<<check[i]<<" ";
	cout<<endl;*/
	if(currentColumn==n)
	{
		for(int i=0;i<n;i++)
			if(check[i]!=0)
				return false;
		return true;
	}
	
	for(int i=0;i<n;i++)
	{
		if(sum+i>n)
		{
			//cout<<currentColumn<<endl;
			return false;
		}
		
		if(i<currentColumn && check[i]<=0)
			continue;
		table[currentColumn]=i;
		check[i]--;
		check[currentColumn]+=i;
		sum+=i;
		if(solve(currentColumn+1)==false)
		{
			sum-=i;
			table[currentColumn]=-1;
			check[i]++;
			check[currentColumn]-=i;
		}
		else
			return true;		
	}
	return false;
}
int main()
{
	cin>>n;
	check.assign(n,0);
	table.assign(n,-1);
	solve();
	
	for(int i=0;i<n;i++)
		cout<<table[i]<<endl;
}
