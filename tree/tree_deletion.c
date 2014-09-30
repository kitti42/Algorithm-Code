#include<stdio.h>
#include<stdlib.h>
//----------------------------------------------------------------------------
typedef struct nodetype
{
   int data;
   struct nodetype *left,*right,*p;
}tree;
typedef tree *node;
node root=NULL;
void transplant(node u,node v);
//----------------------------------------------------------------------------

node insert(int x,node t,node temp)
{                                 /*inserting a node*/
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

int search(int x,node t)
{
	if(t==NULL)
	return 0;
	else if(x==t->data)
	return 1;
	else if(x>t->data)
	return search(x,t->right);
	else if(x<t->data)
	return search(x,t->left);
}
//----------------------------------------------------------------------------

node tree_min(node t)
{                                        //tree minimum
   while(t->left!=NULL)
   t=t->left;
   return t;
}
//----------------------------------------------------------------------------

void del(node t,int x)
{                                       //deleting aha....
   while(t->data!=x)
   {
      if(t->data>x)
      t=t->left;
      else t=t->right;
   }
   if(t->left==NULL)
   transplant(t,t->right);
   else if(t->right==NULL)
   transplant(t,t->left);
   else
   {
      node y=tree_min(t->right);
      if(y->p!=t)
      {
         transplant(y,y->right);
         y->right=t->right;
         y->right->p=y;
      }
      transplant(t,y);
      y->left=t->left;
      y->left->p=y;
   }
}
//-----------------------------------------------------------------------------

void transplant(node u,node v)
{                              //transplant
   if(u->p==NULL)
   root=v;
   else if(u==u->p->left)
   u->p->left=v;
   else u->p->right=v;
   if(v!=NULL)
   v->p=u->p;
}   
//-----------------------------------------------------------------------------

void printpostorder(node t)
{                                                /*postorder traversal*/
   if(t!=NULL)
   {
      printpostorder(t->left);
      printpostorder(t->right);
      printf("%d ",t->data);
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
      root=insert(x,root,root);
   }
   printf("Deletion");
   scanf("%d",&x);
   del(root,x);
   printpostorder(root); 
   printf("Search");
   scanf("%d",&x);
   printf("%d\n",search(x,root)); 
   //scanf("%d",&x);
   //del(root,x);
   return 0;
                                //to show that deletion is nt commutative..haha....
}
       
