/*
  Name: kriti
  Copyright: 
  Author: 
  Date: 10/04/13 4:00
  Description: dfs
*/  

#include<stdio.h>
#include<conio.h>
void dfs(int v,int isvisited[]);
#define MAX 1000
//-------------------------------------------------------------------------

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
       for(i=0;i<e;i++)
	   {
            scanf("%d%d",&a,&b);            //building af adjacency list...
            arr[a][0]++;
            arr[b][0]++;
            arr[a][arr[a][0]]=b;
            arr[b][arr[b][0]]=a;
       }
       dfs(0,isvisited);
       getch();
}
                        
void dfs(int v,int isvisited[])
{                                                   //dfs search and printing in order...
     int i;
     isvisited[v]=1;
     printf("%d ",v);
     for(i=1;i<=arr[v][0];i++)
	 {
     	if(isvisited[arr[v][i]]==0)
     	dfs(arr[v][i],isvisited);
     }
}
     
     
     
