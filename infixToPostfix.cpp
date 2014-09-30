#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
using namespace std;
#define MAX 20
char stack[MAX];
int top=-1;
int precedence[255];
void push(char item)
{
	stack[++top]=item;
}

char pop()
{
	if(top==-1)
		return 'a';
	return stack[top--];
}
char peep()
{
	if(top==-1)
		return 'a';
	return stack[top];
}



int main()
{
	precedence[43]=1;
	precedence[45]=1;
	precedence[42]=2;
	precedence[47]=2;
	char str[20];
	gets(str);
	int i=0;
	while(i<strlen(str))
	{
		if(isdigit(str[i]))
		{
			int num=0;
			while(str[i]!=' '&&i<strlen(str))
			{
				num=num*10+(str[i]-'0');
				i++;
			}
			i++;
			cout<<num<<" ";
		}
		else if(str[i]==' ')
			i++;
		else
		{
			char a=peep();
			if(a=='a')
				push(str[i]);
			else
			{
				if(precedence[a]<precedence[str[i]])
					push(str[i]);
				else
				{
					while(precedence[peep()]>=precedence[str[i]])
						cout<<pop()<<" ";
					push(str[i]);
				}
			}
			i++;
		}
	}
	while(top!=-1)
		cout<<pop()<<" ";
}
