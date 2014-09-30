	/*to find articulation points in a graph*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int dfs(int v,int isvisited[],int num,int dfn[],int low[],int count);
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
      // int arr[v+1][v+1];
       for(i=0;i<e;i++){
                        scanf("%d%d",&a,&b);            //building af adjacency list...
                        arr[a][0]++;
                        arr[b][0]++;
                        arr[a][arr[a][0]]=b;
                        arr[b][arr[b][0]]=a;
                        }
        printf("\n%d\n",dfs(0,isvisited,0,dfn,low,0));
        getch();
        }
                        
int dfs(int v,int isvisited[],int num,int dfn[],int low[],int count)
{
	     //dfs search and printing in order...
     int i,child=0;
     //int count=0;
     dfn[v]=low[v]=num;
     isvisited[v]=1;
     int articulation=0;
     printf("%d ",v);
     for(i=1;i<=arr[v][0];i++)
	 {
     	if(isvisited[arr[v][i]]==0)
		{
     		child++;
     		count=dfs(arr[v][i],isvisited,++num,dfn,low,count);
     		low[v]=min(low[v],low[arr[v][i]]);                       //to chk backedge of desendants...
     		if(low[arr[v][i]]>=dfn[v])
     			articulation=1;
     	}
     	else
     		low[v]=min(low[v],dfn[arr[v][i]]);               //to chk backedge of itself....
     }
     if(dfn[v]==0)
	{
    	if(child>1)
        count++;
    }
    else if(articulation==1)
	{
           //printf("kit");
          count++;
          printf("%d ",count);
    }
    return count;
    // return count;
}

     
     
     
