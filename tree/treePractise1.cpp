/*
  Name: kriti
  Copyright: 
  Author: 
  Date: 10/08/13 16:11
  Description: number of leaf nodes ; full nodes ; half nodes ; maximum level sum
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<list>
#include<vector>
#include<iostream>
using namespace std;
//-----------------------------------------------------------------------------

typedef struct nodetype
{
   int data;
   struct nodetype *left,*right,*p;
}tree;
typedef tree *node;
node root=NULL;
//-----------------------------------------------------------------------------

node insert(node t,int x)
{
   if(t==NULL)
   {
      node temp;
      temp=(node)malloc(sizeof(tree));
      temp->data=x;
      temp->left=temp->right=NULL;
      t=temp;
   }
   else
   {
      if(x<t->data)
      {
         node temp=insert(t->left,x);
         t->left=temp;
      }             
      else if(x>t->data)
      {
         node temp=insert(t->right,x);
         t->right=temp;
      }
   }
   return t;
}
//-----------------------------------------------------------------------------

int leaf(node t)
{
   int count=0,count1=0;
   if(t->left==NULL && t->right==NULL)
   return 1;
   if(t->left!=NULL)
   count=leaf(t->left);
   if(t->right!=NULL)
   count1=leaf(t->right);
   return count+count1;
}
//-----------------------------------------------------------------------------

int full(node t)
{
   int count=0,count1=0;
   if(t->left!=NULL)
   count=full(t->left);
   if(t->right!=NULL)
   count1=full(t->right);
   if(t->left!=NULL && t->right!=NULL)
   return count+count1+1;
   return count+count1;
}
//-----------------------------------------------------------------------------

int half(node t)
{
   int count=0,count1=0;
   if(t->left!=NULL)
   count=half(t->left);
   if(t->right!=NULL)
   count1=half(t->right);
   if((t->left!=NULL && t->right==NULL)||(t->left==NULL && t->right!=NULL))
   return count+count1+1;
   return count+count1;
}
//-----------------------------------------------------------------------------

void maxSumLevel(node t)
{
  int count=0;
  list<node> que;
  que.push_back(t);
  que.push_back(NULL);
  vector<int> arr;
  int sum=0,max=0,level;
  while(que.empty()==false)
  {
     node temp=*(que.begin());
     que.pop_front();
     if(temp==NULL)
     {
        count++;
        if(sum>max)
        {
           max=sum;
           level=count;
        }
        sum=0;
        if(que.empty()==false)
        que.push_back(NULL);
     }
     else
     {
        sum+=(temp->data);
        if(temp->left)
        que.push_back(temp->left);
        if(temp->right)
        que.push_back(temp->right);
     }
  }  
  printf("level: %d , max sum : %d\n",level,max);
}
//-----------------------------------------------------------------------------

main()
{
   int n,i,x,k,c=0;
   printf("how many elements u wana enter");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      scanf("%d",&x);
      root=insert(root,x);
   }
   printf("%d\n",leaf(root));
   printf("%d\n",full(root));
   printf("%d\n",half(root));
   maxSumLevel(root);
   getch();
}

