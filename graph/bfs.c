/*
  Name: kriti
  Copyright: 
  Author: 
  Date: 04/04/13 12:00
  Description: bfs
*/  

#include<stdio.h>
#include<conio.h>
void bfs(int v,int isvisited[],int n);
//void dfs(int v,int isvisited[]);
#define MAX 1000
int arr[MAX][MAX];
main()
{
       int i;
       int v,e,a,b;
       
       scanf("%d%d",&v,&e);
       int isvisited[v];
       for(i=0;i<v;i++)
       isvisited[i]=0;
      // int arr[v+1][v+1];
       for(i=0;i<e;i++){
                        scanf("%d%d",&a,&b);            //building af adjacency list...
                        arr[a][0]++;
                        arr[b][0]++;
                        arr[a][arr[a][0]]=b;
                        arr[b][arr[b][0]]=a;
                        }
        //isvisited[0]=2;
        printf("0 ");
        bfs(0,isvisited,v);
        getch();
}
int queue[MAX];
int front=-1;rear=-1;
int deque(){
    return queue[front++];
}
void enque(int a){
     if(front)
     queue[++rear]=a;
     else
     {
         front++;
         queue[++rear]=a;
         }
         }
int count=0;
void bfs(int v,int isvisited[],int n){                    //bredth first search...
     int i;
     while(count<n){
                        count++;
                        isvisited[v]=2;
        for(i=1;i<=arr[v][0];i++){
                                  if(isvisited[arr[v][i]]==0){
                                  enque(arr[v][i]);
                                  printf("%d ",arr[v][i]);
                                  isvisited[arr[v][i]]=1;
                                  }
                                  }
        int t=deque();
        v=t;
        }
        
        }
        
                                                     
