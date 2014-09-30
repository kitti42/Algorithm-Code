#include<iostream>
#include<cstdlib>
#define MAX 9999
using namespace std;
//--------------------------------------------------------

typedef struct T                                       //structure of treap
{
	int key;
	int priority;
	struct T *left,*right,*parent;
}
treap;
typedef treap *node;
node root=NULL;
//--------------------------------------------------------
 
void rotate(node y,node x)                             //rotation while inserting
{
	if(x!=NULL && y->priority<x->priority)
	{
		y->parent=x->parent;
		if(x->parent!=NULL && x==x->parent->left)
		x->parent->left=y;
		else if(x->parent!=NULL && x==x->parent->right)
		x->parent->right=y;
		if(x->left==y)
		{
			x->left=y->right;
			y->right->parent=x;
			y->right=x;
			x->parent=y;
		}
		else if(x->right==y)
		{
			x->right=y->left;
			y->left->parent=x;
			y->left=x;
			x->parent=y;
		}
		rotate(y,y->parent);
	}
	return;
}
//---------------------------------------------------------

void change(node x,node y)
{
		y->parent=x->parent;
		if(x->parent!=NULL && x==x->parent->left)
		x->parent->left=y;
		else if(x->parent!=NULL && x==x->parent->right)
		x->parent->right=y;
		if(x->left==y)
		{
		
			x->left=y->right;
			if(y->right!=NULL)
			y->right->parent=x;
			y->right=x;
			x->parent=y;
		}
		else if(x->right==y)
		{
			x->right=y->left;
			if(y->left!=NULL)
			y->left->parent=x;
			y->left=x;
			x->parent=y;
		}
	return;
}
//----------------------------------------------------------------

void rotate1(node z)
{
	if(z->left==NULL && z->right==NULL)
	{
		if(z==z->parent->left)
		z->parent->left=NULL;
		else if(z==z->parent->right)
		z->parent->right=NULL;
		return;
	}
	else if(z->left==NULL)
	change(z,z->right);
	else if(z->right==NULL)
	change(z,z->left);
	else
	{	
		if(z->left->priority<z->right->priority)
		change(z,z->left);
		else if(z->right->priority<z->left->priority)
		change(z,z->right);
	}
	rotate1(z);
}
//---------------------------------------------------------

node insert(node temp,node t,int k,int pri)                     //inserting a node
{
	if(temp==NULL)
	{
		temp=(node)malloc(sizeof(treap));
		temp->key=k;
		temp->priority=pri;
		temp->left=temp->right=NULL;
		temp->parent=t;
		rotate(temp,t);
	}
	else if(temp!=NULL)
	{
		t=temp;
		if(k<temp->key)
		{
			temp->left=insert(temp->left,t,k,pri);
		}	
		else if(k>temp->key)
		{
			temp->right=insert(temp->right,t,k,pri);
		}
	}
	return temp;
}
//--------------------------------------------------------------------------

void printinorder(node t)
{                                            
   if(t!=NULL)
   {
      printinorder(t->left);
      cout<<t->key<<" ";
      printinorder(t->right);
   }
}
//---------------------------------------------------------------------------

void del(node z)                                        //deleting a node
{
	z->priority=MAX;
	rotate1(z);
}
//---------------------------------------------------------------------------

int main()
{
		root=insert(root,root,10,1);
		root=insert(root,root,5,3);
		root=insert(root,root,13,6);
		del(root->left);
		printinorder(root);
		cout<<endl;
}
