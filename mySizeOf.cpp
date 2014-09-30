#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<map>
#include<algorithm>
using namespace std;

#define size(type) ((char *)(&type+1)-(char *)(&type))
int main()
{
    int a;
    long long b;
	printf("%d %d\n",size(a),size(b));
}
