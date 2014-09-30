#include<stdio.h>
#include<conio.h>
int partition(int a[],int p,int r);
void quicksort(int a[],int p,int r);
main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n+1];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	getch();
}

void quicksort(int a[],int p,int r)
{
     int q;
     if(p<r)
	 {
    	q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
int partition(int a[],int p,int r)
{
     int i,j,temp;
     int x=a[r];
     i=p-1;
     for(j=p;j<=r-1;j++)
	 {
        if(a[j]<=x)
		{
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
     temp=a[i+1];
     a[i+1]=a[r];
     a[r]=temp;
     return i+1;
}
     
             
