 /*
  Name: kriti
  Copyright: 
  Author: 
  Date: 07/08/13 21:00
  Description: linked list implementation
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

void del(int a,list &head,list &tail)
{
   list x,y;
   x=head;
   y=head;
   if(head->data==a)
   head=head->link;
   else
   {
      while(y!=tail)
      {
      if(x==head)
      x=x->link;
      else
      {
         x=x->link;
         y=y->link;
      }
      if(x->data==a)
      {
         if(x==tail)
         {
            tail=y;
            tail->link=NULL;
         }
         else
         y->link=x->link;
         break;
      }
      }
    }
}
//----------------------------------------------------------------------------   
      
int main()
{
   list head,tail,temp;
   head=tail=NULL;
   char ch;
   int a;
   printf("u wana enter elements??");
   scanf("%c",&ch);
   fflush(stdin);
   if(ch=='y')
   {
      tail=(list)malloc(sizeof(node));
      scanf("%d",&a);
      tail->data=a;
      tail->link=NULL;
      head=tail;
      printf("u wana enter more elements??");
      fflush(stdin);
      scanf("%c",&ch);
      while(ch=='y')
      {
         temp=(list)malloc(sizeof(node));
         scanf("%d",&a);
         temp->data=a;
         temp->link=NULL;
         tail->link=temp;
         tail=temp;
         printf("u wana enter more elements??");
         fflush(stdin);
         scanf("%c",&ch);
      }
   }
   printlist(head);
   printf("enter the element u wana delete");
   scanf("%d",&a);
   del(a,head,tail);
   printlist(head);
   getch();
}
   
      
   
   


 
