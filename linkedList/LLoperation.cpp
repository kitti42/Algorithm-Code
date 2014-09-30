/*
  Name: kriti
  Copyright: 
  Author: 
  Date: 08/08/13 23:51
  Description: linked list swapping 2-2 pairs..:P
*/



#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
//-----------------------------------------------------------------------------

typedef struct ntype
{
   int data;
   struct ntype *link;
}node;
typedef node *list;
//-----------------------------------------------------------------------------

void printlist(list head)
{
   while(head!=NULL)
   {
      printf("%d ",head->data);
      head=head->link;
   }
}
//-----------------------------------------------------------------------------

void operation(list &head)
{
   list x,y,z;
   x=head;
   y=x->link;
   head=y;
   while(x!=NULL && y!=NULL)
   {
      z=y->link;
      y->link=x;
      if(z!=NULL && z->link!=NULL)
      x->link=z->link;
      else
      x->link=z;
      x=z;
      if(x!=NULL)
      y=x->link;
   }
}
//-----------------------------------------------------------------------------
      
int main()
{
   list head,tail,temp;
   head=tail=NULL;
   int a;
   int n;
   scanf("%d",&n);
   
      tail=(list)malloc(sizeof(node));
      scanf("%d",&a);
      tail->data=a;
      tail->link=NULL;
      head=tail;
      n--;
      while(n--)
      {
         temp=(list)malloc(sizeof(node));
         scanf("%d",&a);
         temp->data=a;
         temp->link=NULL;
         tail->link=temp;
         tail=temp;
      }
      
      printlist(head);
      printf("\n");
      operation(head);
      printlist(head);
   getch();
}
   
      
   
   


 
