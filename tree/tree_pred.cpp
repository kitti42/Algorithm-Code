/*
  Name: kriti
  Copyright: 
  Author: 
  Date: 09/08/13 18:50
  Description: tree predecessor
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//----------------------------------------------------------------------------

typedef struct nodetype
{
   int data;
   struct nodetype *left,*right,*p;
}tree;
typedef tree *node;
node root=NULL;
//-----------------------------------------------------------------------------

node insert(int x,node t,node temp)       /*inserting a node*/
{                                
     if(t==NULL)
     {
         t=(node)malloc(sizeof(tree));
         t->data=x;
         t->left=t->right=NULL;
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

node tree_max(node t)
{
   while(t->right!=NULL)
   t=t->right;
   return t;
}
//-----------------------------------------------------------------------------

node predecessor(node t,int x)
{
   while(t->data!=x)
   {
      if(t->data>x)
      t=t->left;
      else t=t->right;
   }
   
   if(t->left!=NULL)
   return tree_max(t->left);
   node y=t->p;
   while(y!=NULL&&t==y->left)
   {
      t=y;
      y=y->p;
   }
   return y;            
}
//----------------------------------------------------------------------------

main()
{
   int n,i,x,k,c=0;
   printf("how many elements u wana enter\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      scanf("%d",&x);
      root=insert(x,root,root);
   }
   int b=6;
   while(b--)
   {
      scanf("%d",&x);
      node h=predecessor(root,x);
      printf("%d\n",h->data);
   }
   getch();
}
