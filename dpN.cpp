//counting the number of distinct subsequences in a string

#include<iostream>
#define MOD 1000000007
using namespace std;
//---------------------------------------

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int l=str.size();
		long long dp[l+2];
		int last[500];
		for(int i=0;i<500;i++)
			last[i]=0;
		dp[0]=1;
		for(int i=1;i<=l;i++)
		{
    		dp[i]=(dp[i-1]*2);
    		//dp[i]%=MOD;
    		if(last[str[i-1]]!=0)
				dp[i]=(dp[i]-dp[last[str[i-1]]-1]);
			dp[i]=(dp[i]%MOD+MOD)%MOD;
   			last[str[i-1]]=i;
		}
		cout<<dp[l]<<endl;
	}
} 
