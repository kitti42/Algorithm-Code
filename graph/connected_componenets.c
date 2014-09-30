/*to find connected componenets in a graph*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int dfs(int v,int isvisited[],int num,int dfn[]);
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
       
       int dfn[v+1];
      // int arr[v+1][v+1];
       for(i=0;i<e;i++){
                        scanf("%d%d",&a,&b);  
                        a--;b--;          //if vertices are from 1 to v....nt if 0 to n-1
                        arr[a][0]++;
                        arr[b][0]++;
                        arr[a][arr[a][0]]=b;
                        arr[b][arr[b][0]]=a;
                        }
       int count=0;
       for(i=0;i<v;i++){
       if(isvisited[i]==0){
       count++;
       dfs(i,isvisited,0,dfn);
       }
       }
       printf("%d\n",count);
        getch();
        }
                        
int dfs(int v,int isvisited[],int num,int dfn[]){     //dfs search...
     int i;
     dfn[v]=num;
     isvisited[v]=1;
     for(i=1;i<=arr[v][0];i++){
     if(isvisited[arr[v][i]]==0)
     dfs(arr[v][i],isvisited,++num,dfn);                          
     }
     }

     
     
     
