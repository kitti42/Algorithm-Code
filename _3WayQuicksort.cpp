#include<iostream>
#include<string>
using namespace std;
//-----------------------------------------------------

void swap(string a[],int b,int c)
{
	string temp;
	temp=a[b];
	a[b]=a[c];
	a[c]=temp;
}
//------------------------------------------------------

void sort(string a[],int low,int high,int d)
{
	if(low>=high)
	return;
	int lt=low;
	int gt=high;
	int v=a[low][d];
	int i=low+1;
	
	while(i<=gt)
	{
		int t=a[i][d];
		
		if(t<v)
		swap(a,lt++,i++);
		
		else if(v<t)
		swap(a,i,gt--);
		
		else
		i++;
	}
	
	sort(a,low,lt-1,d);
	if(v>=0)
	sort(a,lt,gt,d+1);
	sort(a,gt+1,high,d);
}
//-----------------------------------------------------

int main()
{
	int n;
	cin>>n;
	string a[n+1];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	sort(a,0,n-1,0);
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}

