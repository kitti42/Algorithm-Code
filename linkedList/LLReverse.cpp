 /*
  Name: kriti
  Copyright: 
  Author: 
  Date: 07/08/13 21:00
  Description: linked list reverse
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

void reverse(list &head)
{
   list x,y,z;
   x=head;
   y=x->link;
   z=x;
   head->link=NULL;
   while(y!=NULL)
   {
      z=y->link;
      y->link=x;
      x=y;
      y=z;
   }
   head=x;
}  
   
//----------------------------------------------------------------------------   
      
int main()
{
   list head,tail,temp;
   head=tail=NULL;
   char ch;
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
      reverse(head);
      printlist(head);
   getch();
}
   
      
   
   


 
