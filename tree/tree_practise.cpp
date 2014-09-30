/*
  Name: kriti
  Copyright: 
  Author: 
  Date: 10/08/13 15:13
  Description: tree: size of tree ; level order treversal in reverse order ;height of tree
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

void printInorder(node t)
{                                           /*inorder*/
   if(t!=NULL)
   {
      printInorder(t->left);
      printf("%d ",t->data);
      printInorder(t->right);
   }
}
//----------------------------------------------------------------------------

int size(node t)
{
   int temp=0,temp1=0;
   if(t->left)
   temp=size(t->left);
   if(t->right)
   temp1=size(t->right);
   return temp+temp1+1;
}
//----------------------------------------------------------------------------

void level(node t)
{
  list<node> que;
  que.push_back(t);
  vector<int> arr;
  while(que.empty()==false)
  {
     node temp=*(que.begin());
     arr.push_back(temp->data);
     que.pop_front();
     if(temp->left)
     que.push_back(temp->left);
     if(temp->right)
     que.push_back(temp->right);
  }  
  for(int i=arr.size()-1;i>=0;i--)
  printf("%d ",arr[i]);
  printf("\n");
}
//-----------------------------------------------------------------------------

int height(node t)
{
   int ht=0,ht1=0;
   if(t->left)
   ht=height(t->left);
   if(t->right)
   ht1=height(t->right);
   if(ht>ht1)
   return ht+1;
   else
   return ht1+1;
}
//----------------------------------------------------------------------------
 
int iterHeight(node t)
{
  int count=0;
  list<node> que;
  que.push_back(t);
  que.push_back(NULL);
  vector<int> arr;
  while(que.empty()==false)
  {
     node temp=*(que.begin());
     que.pop_front();
     if(temp==NULL)
     {
        count++;
        if(que.empty()==false)
        que.push_back(NULL);
     }
     else
     {
        if(temp->left)
        que.push_back(temp->left);
        if(temp->right)
        que.push_back(temp->right);
     }
  }  
  return count;
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
   printInorder(root);
   printf("\n");
   /*int b=size(root);
   printf("%d\n",b);
   level(root);
   printf("%d\n",height(root));
   printf("%d\n",iterHeight(root));*/
   getch();
}

