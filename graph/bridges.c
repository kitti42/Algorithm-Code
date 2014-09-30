/*to find bridges in a graph*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void dfs(int u,int v,int num,int dfn[],int low[],int count);
#define MAX 3005
int arr[MAX][MAX];

int min(int a,int b){
    return a<b?a:b;
}
main(){
       int i;
       int v,e,a,b;
       
       scanf("%d%d",&v,&e);
       int isvisited[v];
       for(i=0;i<v;i++)
       isvisited[i]=0;
       
       int dfn[v+1],low[v+1];
       for(i=0;i<v;i++){
                        dfn[i]=-1;
                        low[i]=-1;
                        }
      // int arr[v+1][v+1];
       for(i=0;i<e;i++){
                        scanf("%d%d",&a,&b);            //building af adjacency list...
                        arr[a][0]++;
                        arr[b][0]++;
                        arr[a][arr[a][0]]=b;
                        arr[b][arr[b][0]]=a;
                        }
     dfs(0,0,0,dfn,low,0);
        getch();
        }
                        
void dfs(int u,int v,int num,int dfn[],int low[],int count){   
     int i;
     
     dfn[v]=low[v]=num;
     
     for(i=1;i<=arr[v][0];i++){
     if(dfn[arr[v][i]]==-1){
                            
     dfs(v, arr[v][i],++num,dfn,low,count);
     low[v]=min(low[v],low[arr[v][i]]);
     if(low[arr[v][i]]==dfn[arr[v][i]])                    //check backedge of descendants of v....
     printf("the egde from %d to %d is a bridge",v,arr[v][i]);
     }
     else if(arr[v][i]!=u)                             //chk backedge of v itself thats nt its parent dats u u ve maintained u..:P
     low[v]=min(low[v],dfn[arr[v][i]]);
     }
     }

     
     

