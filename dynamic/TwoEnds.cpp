
#include<iostream>
#include<algorithm>
using namespace std;
//--------------------------------

int table[1010][1010];

int mem(int arr[],int n)
{
	int start;
	for(int i=0,j=1;i<n-1;i++,j++)
		table[i][j]=max(arr[i],arr[j]);
	
		
	for(int i=0,j=2;i<n-2;i++,j++)
	{
		if(arr[i+1]>arr[i] && arr[i+1]>arr[j])
			table[i][j]=arr[i]+arr[j];
			
		else
			table[i][j]=max(arr[i],max(arr[i+1],arr[j]))+min(arr[i],min(arr[i+1],arr[j]));
	}
	
	for(start=3;start<n;start++)
	{
		for(int i=0;i<n;i++)
		{
			int j=i+start;
			if(j<n){
			if(arr[j-1]>arr[i])
				table[i][j]=table[i][j-2]+arr[j];
			else
				table[i][j]=table[i+1][j-1]+arr[j];
				
			if(arr[i+1]>=arr[j])
				table[i][j]=max(table[i][j],table[i+2][j]+arr[i]);
			else
				table[i][j]=max(table[i][j],table[i+1][j-1]+arr[i]);
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int count=1;
	while(n!=0)
	{
		int arr[n+1];
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
				table[i][j]=-1;
		}
		
		mem(arr,n);
		cout<<"In game "<<count<<", the greedy strategy might lose by as many as ";
		cout<<2*table[0][n-1]-sum<<" points."<<endl;
		count++;
		cin>>n;
	}
}
