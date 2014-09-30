/*
  Name: kriti
  Copyright: 
  Author: 
  Date: 08/08/13 23:52
  Description: inserting all even at beginnig
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
   list x,y;
   x=head->link;
   y=head;
   while(x!=NULL)
   {
      if(x->data%2==0)
      { 
         y->link=x->link;
         x->link=head;
         head=x;
         x=y->link;
      }
      else
      {
      x=x->link;
      y=y->link;
      }
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
   
      
   
   


 
