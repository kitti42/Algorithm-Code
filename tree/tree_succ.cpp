/*
  Name: kriti
  Copyright: 
  Author: 
  Date: 09/08/13 18:21
  Description: binary search tree successor
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//-----------------------------------------------------------------------------

typedef struct nodetype
{
   int data;
   struct nodetype *left,*right,*p;
}tree;
typedef tree *node;
node root=NULL;
//-----------------------------------------------------------------------------

node insert(int x,node t,node temp)        /*inserting a node*/
{                                
   if(t==NULL)
   {
      t=(node)malloc(sizeof(tree));
      t->data=x;
      t->left=NULL;
      t->right=NULL;
      t->p=temp;
   }
   else if(t!=NULL)
   {
      temp=t;
      if(x<t->data)
      t->left=insert(x,t->left,temp);
      else if(x>t->data)
      t->right=insert(x,t->right,temp);
   }
   return t;
}
//-----------------------------------------------------------------------------

node tree_min(node t)
{
   while(t->left!=NULL)
   t=t->left;
   return t;
}
//-----------------------------------------------------------------------------

node successor(node t,int x)
{
   while(t->data!=x)
   {
       if(t->data>x)
       t=t->left;
       else t=t->right;
   }
   if(t->right!=NULL)
   return tree_min(t->right);
   node y=t->p;
   while(y!=NULL&&t==y->right)
   {
      t=y;
      y=y->p;
   }
   return y;            
}
//----------------------------------------------------------------------------

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

main()
{
   int n,i,x,k,c=0;
   printf("how many elements u wana enter");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      scanf("%d",&x);
      root=insert(x,root,root);
   }
   //printInorder(root);
   int b=6;
   while(b--)
   {
      scanf("%d",&x);
      node h=successor(root,x);
      printf("%d\n",h->data);
   }
   getch();
}
