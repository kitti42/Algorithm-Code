/*bfs to calculate shortest dist. from apoint to othrs...*/

#include<stdio.h>
#include<conio.h>
void bfs(int v,int isvisited[],int n);
#define MAX 1000
int arr[MAX][MAX];
int bfn[MAX]={31527};
main(){
       int i;
       int v,e,a,b;
       
       scanf("%d%d",&v,&e);
       int isvisited[v];
       for(i=0;i<v;i++){
       isvisited[i]=0;
       arr[i][0]=0;
       }
      // int arr[v+1][v+1];
       for(i=0;i<e;i++){
                        scanf("%d%d",&a,&b);            //building af adjacency list...
                        arr[a][0]++;
                        arr[b][0]++;
                        arr[a][arr[a][0]]=b;
                        arr[b][arr[b][0]]=a;
                        }
        //isvisited[0]=2;
        //printf("0 ");
        scanf("%d",&a);                //the point from which u want shortest dist ol other points...
         bfs(a,isvisited,v);
         printf("\n");
         for(i=0;i<v;i++)                 //priting shortest dist...
         printf("%d ",bfn[i]);
        getch();
        }
int queue[MAX];
int front=-1;rear=-1;
int deque(){
    return queue[front++];
}
void enque(int a){
     if(front!=-1)
     queue[++rear]=a;
     else
     {
         front++;
         queue[++rear]=a;
         }
         }
void bfs(int v,int isvisited[],int n){                    //bredth first search...with shortest dist. from a pt...
     int i,j,count=0;
     while(count<n){ 
                        count++;
                        isvisited[v]=2;
        for(i=1;i<=arr[v][0];i++){
                                  if(isvisited[arr[v][i]]==0){
                                  enque(arr[v][i]);
                                  bfn[arr[v][i]]=bfn[v]+1;
                                  isvisited[arr[v][i]]=1;
                                  }
                                  }
        int t=deque();
        v=t;
        }
        
        }
        
                                                     
