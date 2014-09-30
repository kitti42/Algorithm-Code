#include<bits/stdc++.h>
using namespace std;


bool func(int a)
{
	return !(a%2);
}
int main()

{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	stable_partition(a,a+10,func);
	for(int i=0;i<10;i++)
		cout<<a[i];
}
