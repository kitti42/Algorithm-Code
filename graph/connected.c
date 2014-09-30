#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
struct Node{
       int v;
       struct Node *next;
       int visited;
};
typedef struct Node Node;
void insert_after(Node *m,Node *n);
int find_unvisited(int n);
void dfs(int n);
Node *vertex[MAX];
 
 
int main()
{
    int test,v_n,e_n,source,dest,index,count=0,i;
    Node *source_n,*dest_n;
    scanf("%d",&test);
    while(test--)
    {
          scanf("%d",&v_n);
          for(i=0;i<v_n;++i)
          {
                            vertex[i]=(Node *)malloc(sizeof(Node));
                            vertex[i]->v=i;
                            vertex[i]->next=NULL;
                            vertex[i]->visited=0;
          }
          scanf("%d",&e_n);
            for(i=0;i<e_n;++i){
               scanf("%d %d",&source,&dest);
              // printf("here%d",i);
              source_n=(Node *)malloc(sizeof(Node));
              source_n->v=source;
              dest_n=(Node *)malloc(sizeof(Node));
              dest_n->v=dest;
                insert_after(vertex[source],dest_n);
                insert_after(vertex[dest],source_n);
 
            }
            /*+index=find_unvisited(v_n);*/
           /* while(index!=-1){*/
           count=0;
           for(i=0;i<v_n;++i)
           {
               if(vertex[i]->visited==0)
               {
                    ++count;
                dfs(i);
               }
           }
            printf("%d\n",count);
}
return 0;
}
 
void dfs(int n)
{
     Node *temp;
     vertex[n]->visited=1;
     for(temp=vertex[n]->next;temp;temp=temp->next)
     {
                                         if(vertex[temp->v]->visited!=1)
                                         {
                                             dfs(temp->v);
                                         }
 
     }
}
 
void insert_after(Node *m,Node *n)
{
     Node *temp;
     temp=m->next;
     m->next=n;
     n->next=temp;
}
