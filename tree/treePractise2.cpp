/*
  Name: kriti
  Copyright: 
  Author: 
  Date: 11/08/13 17:18
  Description: tree vertical (column vise) sum ; zigZag treversal ; 
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

int sum[30]={0};
void verticalSum(node root,int col)
{
   sum[col]+=root->data;
   if(root->left)
   verticalSum(root->left,col-1);
   if(root->right)
   verticalSum(root->right,col+1);
}  
//-----------------------------------------------------------------------------

void zigZag(node t)
{
  int count=1;
  list<node> que;
  vector<node> arr;
  que.push_back(t);
  que.push_back(NULL);
  while(que.empty()==false)
  {
     node temp=*(que.begin());
     que.pop_front();
     if(temp==NULL)
     {
        count++;
        while(arr.empty()==false)
        {
           node temp1=arr[arr.size()-1];
           arr.pop_back();
           if(count%2!=0)
           {
              if(temp1->left)
              que.push_back(temp1->left);
              if(temp1->right)
              que.push_back(temp1->right);
           }
           else
           {
              if(temp1->right)
              que.push_back(temp1->right);
              if(temp1->left)
              que.push_back(temp1->left);
           } 
           if(que.empty()==false)
           que.push_back(NULL);
        }
     }
     else
     {
        printf("%d ",temp->data);
        arr.push_back(temp);
     }
  }  
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
   verticalSum(root,15);
   for(int i=0;i<30;i++)
   printf("%d ",sum[i]);
   printf("\n");
   zigZag(root);
   
   int z,y;
   cin>>z>>y;
   int min=root->data;
   lca(root,z,y,min);
   printf("\n%d\n",min);
   getch();
}
