/*
  Name: kriti & shagun
  Copyright: 
  Author: 
  Date: 10/08/13 01:06
  Description: iterative inorder traversal ,level order traversal , swapping left and right child
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<vector>
#include<list>
#include<iostream>
using namespace std;
//----------------------------------------------------------------------------

typedef struct nodetype
{
   int data;
   struct nodetype *left,*right;
}tree;
typedef tree *node;
node root=NULL;
//----------------------------------------------------------------------------

void swap(node root)
{
   node leftC=root->left;
   node rightC=root->right;
   root->left=rightC;
   root->right=leftC;
   if(root->left)
   swap(root->left);
   if(root->right)
   swap(root->right);
}
//----------------------------------------------------------------------------

void levelOrder(node root)
{
   list<node> que;
   que.push_back(root);
   while(1)
   {
      if(que.empty()==false)
      root=*que.begin();
      que.pop_front();
      if(root->left)
      que.push_back(root->left);
      if(root->right)
      que.push_back(root->right);
      printf("%d ",root->data);
      if(que.empty()==true)
      break;
   }
   printf("\n");
}   
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

template<class T> class stack
{
   private:
     vector<T> arr; 
      
   public:
       void push(T x)
      {
         arr.push_back(x);
      }
      T pop()
      {
         T temp=arr[arr.size()-1];
         arr.pop_back();
         return temp;
      }
      bool empty()
      {
         if(arr.empty())
         return true;
         return false;
      }   
};
//----------------------------------------------------------------------------- 

void inOrder(stack<node> arr,node root)
{
   for(;;)
   {
      for(;root!=NULL;root=root->left)
      {
         arr.push(root);
      }
      if(arr.empty()==false)
      root=arr.pop();
      if(root==NULL)
      break;
      printf("%d ",root->data);
      root=root->right;
   }
    printf("\n");
}   
//-----------------------------------------------------------------------------
    
int main()
{
   printf("how many elements u wana enter");
   int n,x;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
      scanf("%d",&x);
      root=insert(root,x);
   }
   stack<node> arr;
   inOrder(arr,root);
   levelOrder(root);
   swap(root);
   inOrder(arr,root);
   getch();
}

      
      
      
