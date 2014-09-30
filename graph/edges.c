/*to classify edges as forward,back,tree or cross in directed graph*/

#include<stdio.h>
#include<conio.h>
void dfs(int v,int isvisited[]);
#define MAX 1000
int arr[MAX][MAX];
int start[MAX];
int end[MAX];
int time=0;
main(){
       int i,j;
       int v,e,a,b;
       
       scanf("%d%d",&v,&e);
       int isvisited[v];
       for(i=0;i<v;i++)
       isvisited[i]=0;
       for(i=0;i<e;i++)
       {
          scanf("%d%d",&a,&b);            //building af adjacency list...
          arr[a][0]++;
          arr[a][arr[a][0]]=b;
       }
        for(i=0;i<v;i++)
        {
           if(isvisited[i]==0)
           {
              dfs(i,isvisited);
           }
        }
        for(i=0;i<v;i++)
        {
           for(j=1;j<=arr[i][0];j++)
           {
              if(start[i]<start[arr[i][j]]&&end[arr[i][j]]<end[i])
              printf("%d %d : tree edge\n",i,arr[i][j]);
              else if(start[i]>start[arr[i][j]]&&end[arr[i][j]]>end[i])
              printf("%d %d : back edge\n",i,arr[i][j]);
              else if(end[i]<start[arr[i][j]])
              printf("%d %d : cross edge\n",i,arr[i][j]);
           }
        }
        getch();
        }                           
void dfs(int v,int isvisited[])                             //dfs search and printing in order...
{                                               
     int i;
     isvisited[v]=1;
     time=time+1;
     start[v]=time;
     for(i=1;i<=arr[v][0];i++)
     {
        if(isvisited[arr[v][i]]==0)
        {  
           dfs(arr[v][i],isvisited);
        }
     }
     isvisited[v]=2;
     time=time+1;
     end[v]=time;
}
     
     
