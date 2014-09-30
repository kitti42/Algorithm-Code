/*
	Name: EDIT DISTANCE 
	Author: kriti dang
	Date: 13/04/14 23:08
	Description: DYnamic
*/

#include<iostream>
#include<algorithm>
int dp[2010][2010];
using namespace std;
//--------------------------------

bool match(char a,char b)
{
	if(a==b)
		return 0;
	else return 1;
}
//--------------------------------

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,t;
		cin>>s>>t;
		int l,m;
		l=s.size();
		m=t.size();
		
		int operation[4];
		
		for(int i=0;i<=l;i++)
			dp[i][0]=i;
		
		for(int i=0;i<=m;i++)
			dp[0][i]=i;
			
		for(int i=1;i<=l;i++)
		{
			for(int j=1;j<=m;j++)
			{
				operation[0]=dp[i-1][j-1]+match(s[i-1],t[j-1]);
				operation[1]=dp[i][j-1]+1; 
				operation[2]=dp[i-1][j]+1;
				
				dp[i][j]=min(operation[0],min(operation[1],operation[2]));
			}
			
		}
		cout<<dp[l][m]<<endl;
	}
}
