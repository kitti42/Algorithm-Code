#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void create(int,int);
typedef struct nodetype{
        int data;
        struct nodetype *rlink,*dlink;
        }node;
        
        
typedef node *list;
list head;
list tail;
void printlist();
void insert(int n);
main(){
       list temp;
       temp=(list)malloc(sizeof(node));
       temp->data=0;
       temp->rlink=NULL;
       temp->dlink=NULL;
       head=temp;
       tail=temp;
       int a,b;
       scanf("%d%d",&a,&b);
while(a!=0||b!=0){
insert(a);
create(b,a);
scanf("%d%d",&a,&b);
}

getch();
}
void insert(int n){
     int p=0;
     list x=head;
     while(x!=NULL){
     if(x->data==n){
     p=1;
     break;
     } x=x->dlink;
     }
     if(p==0){
     list temp;
     temp=(list)malloc(sizeof(node));
     temp->data=n;
     temp->rlink=NULL; 
     temp->dlink=NULL;
     tail->dlink=temp; 
     tail=temp;
    }
}
void create(int n,int a){
     list x=head;
     while(x->data!=a){
     x=x->dlink;
     }
     list y=x;
     while(y->rlink!=NULL)
     y=y->rlink;
     list temp;
     temp=(list)malloc(sizeof(node));
     temp->data=n;
     temp->rlink=NULL;
     temp->dlink=NULL;
     y->rlink=temp;
     y=temp;
     }
 void printlist()
      {
                     head=head->dlink;
           while(head!=NULL){
           printf("%d ",head->data);
                            head=head->rlink;
                            }
                            printf("\n");
                            fflush(stdout);
                            }
     
     
 
                  
