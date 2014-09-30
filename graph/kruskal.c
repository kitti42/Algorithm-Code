/*
  Name: kriti
  Copyright: 
  Author: 
  Date: 15/05/13 9:00
  Description: kruskal
*/  


/*
kruskal's algorithm
-------------------------
1)sort edges in order of length
2)for i<- 1 to m
if {e[i]} union tree doent have a cycle
T<-T U {e[i]}s410`x
3)return T

*/

#include<stdio.h>
#include<conio.h>
void dfs(int v,int isvisited[]);
void heapify(int a[],int,int,int x[],int y[]);
void heapsort(int a[],int n,int x[],int y[]);
void make_set(int a);
void uni(int x,int y);
void link(int x,int y);
int find_set(int x);

int t[1000],m[1000];
main()
{
	int i;
    int v,e;
    scanf("%d%d",&v,&e);
    int sum=0,x[v+1],y[v+1],w[v+1];
    for(i=0;i<v;i++)
	{ 
       make_set(i);
    }
       
    for(i=0;i<e;i++)
    {
    	scanf("%d%d%d",&x[i],&y[i],&w[i]);   
    }
                        
    for(i=e/2-1;i>=0;i--)
	{                          //sorting
    	heapify(w,i,e,x,y);
	}
	heapsort(w,e,x,y);

	for(i=0;i<e;i++)
	{
		if(find_set(t[x[i]])!=find_set(t[y[i]]))
		{
			sum=sum+w[i];
			printf("%d\n",sum);
			uni(t[x[i]],t[y[i]]);
		}
	}
 	getch();
}

//------------------------------------------------------------------------------------
void make_set(int a)
{
	t[a]=a;
    m[a]=0;
}

//------------------------------------------------------------------------------------     
void uni(int x,int y)
{
	link(find_set(x),find_set(y));
}
     
//------------------------------------------------------------------------------------
void link(int x,int y)
{
	if(m[x]>m[y])
    	t[y]=t[x];
    else
        t[x]=t[y];
    if(m[x]==m[y])
        m[y]++;
}

//-------------------------------------------------------------------------------------
int find_set(int x)
{
	if(t[x]!=x)
	{
    	t[x]=t[t[x]];               //path compression
        find_set(t[x]);
    }
    return x;
}
             
//--------------------------------------------------------------------------------------
void heapsort(int a[],int n,int x[],int y[])
{
	int i,temp;
    for(i=n-1;i>=0;i--)
	{
 		temp=a[0];
		a[0]=a[i];
		a[i]=temp;

		temp=x[0];
		x[0]=x[i];
		x[i]=temp;

		temp=y[0];
		y[0]=y[i];
		y[i]=temp;
		heapify(a,0,i,x,y);
	}
}

//-----------------------------------------------------------------------------------------
void heapify(int a[],int i,int n,int x[],int y[])
{
	int l,r,largest,temp;
	l=2*i+1;
	r=2*i+2;
	if(l<n&&a[l]>a[i])
		largest=l;
	else largest=i;
	if(r<n&&a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
    	temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
               
        temp=x[i];
        x[i]=x[largest];
        x[largest]=temp;
               
        temp=y[i];
        y[i]=y[largest];
        y[largest]=temp;
               
		heapify(a,largest,n,x,y);
    }
}
               
     
     
     

