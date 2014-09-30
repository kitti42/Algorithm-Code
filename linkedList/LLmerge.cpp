/*
  Name: kriti
  Copyright: 
  Author: 
  Date: 07/08/13 23:53
  Description: linked list merging
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

void merge(list &head,list &head1)
{
   list x,y,z;
   x=head;
   y=head1;
   if(head1->data<head->data)
   head=head1;
   while(x!=NULL && y!=NULL)
   {
      if(x->data<y->data)
      {
         if((x->link==NULL)||(x->link!=NULL && x->link->data>y->data))
         {
            z=x->link;
            x->link=y;
            x=z;
         }
         else
         {
             x=x->link;
         }
      }
      else
      {
         if((y->link==NULL)||(y->link!=NULL && y->link->data>x->data))
         {
            z=y->link;
            y->link=x;
            y=z;
         }
         else
         {
             y=y->link;
         }
      }
   }
}
//-----------------------------------------------------------------------------
      
int main()
{
   list head,tail,temp;
   list head2,tail2;
   head=tail=NULL;
   head2=tail2=NULL;
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
      
      scanf("%d",&n);
      tail2=(list)malloc(sizeof(node));
      scanf("%d",&a);
      tail2->data=a;
      tail2->link=NULL;
      head2=tail2;
      n--;
      while(n--)
      {
         temp=(list)malloc(sizeof(node));
         scanf("%d",&a);
         temp->data=a;
         temp->link=NULL;
         tail2->link=temp;
         tail2=temp;
      }
      printlist(head);
      printf("\n");
      printlist(head2);
      printf("\n");
      merge(head,head2);
      printlist(head);
   getch();
}
   
      
   
   


 
