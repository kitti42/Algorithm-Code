#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define min(a,b) a<b?a:b
int cmp(const void*x,const void*y)
{
	return *(int*)x - *(int*)y;
}
inline int compare(const void *a,const void *b)
{
	return ((struct data *)a)->l-((struct data *)b)->l;
}
main(){
	/*int a[5]={5,6,9,7,1};
	qsort(a,5,sizeof(int),cmp);
	for(int i=0;i<5;i++)
		cout<<a[i]<<endl;*/
		int k=min(4,3);
		cout<<k;
}
//qsort(starting pointer,length,sizeof(),cmp);
