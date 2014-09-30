#include<iostream>
#include<conio.h>
using namespace std;
int t[1000];
//-----------------------------------------------------------------------------

void failure(string w,int n)
{
	int pos=2,cnd=0;
	t[0]=-1;
	t[1]=0;
	while(pos<n)
	{
		if(w[pos-1]==w[cnd])
		{
			cnd+=1;
			t[pos]=cnd;
			pos+=1;
		}
		else if(cnd>0)
		{
			cnd=t[cnd];
		}
		else
		{
			t[pos]=0;
			pos+=1;
		}
	}
}		
//-----------------------------------------------------------------------------

int kmp(string S,string W,int m,int n)
{
	int j=0,i=0;
 while(j+i<m)
	{
  if(W[i]==S[j + i])
  {
    if(i==n-1)
    return j;
    i=i+1;
		}
  else
  {
   j=j+i-t[i];
   if(t[i]>-1)
   i=t[i];
   else
   i=0;
		}
	}
	return -1;
}
//-----------------------------------------------------------------------------
	
int main()
{
	string a,b;
	cin>>a>>b;
	int m,n;
	m=a.length();
	n=b.length();
	failure(b,n);
	cout<<kmp(a,b,m,n);
	getch();
	return 0;
}
	
