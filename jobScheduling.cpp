#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct task
{
	int f,c,index;
}t;

inline int cmp(const void *a,const void *b)
{
	return ((struct task *)b)->c-((struct task *)a)->c;
}

int main()
{
	int n;
	cout<<"Enter no of jobs :";
	cin>>n;
	t arr[n+1];
	int time[100];
	for(int i=0;i<100;i++)
		time[i]=-1;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].f>>arr[i].c;
		arr[i].index=i;
	}
	qsort(arr,n,sizeof(t),cmp);
	for(int i=0;i<n;i++)
	
		cout<<arr[i].c<<" "<<arr[i].f<<endl;
	cout<<endl;
	int maxCost=0;
	for(int i=0;i<n;i++)
	{
		for(int j=arr[i].f;j>=0;j--)
		{
			if(time[j]==-1)
			{
				time[j]=arr[i].index;
				maxCost+=arr[i].c;
				break;
			}
		}
	}
	for(int i=0;i<100;i++)
	{
		if(time[i]!=-1)
			cout<<time[i]<<" ";
	}
	cout<<endl<<maxCost<<endl;
}
