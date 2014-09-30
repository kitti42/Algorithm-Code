#include<stdio.h>
#include<conio.h>
void heapify(int a[],int,int);
main(){
int n,i,j;
scanf("%d",&n);
int a[n+1];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=n/2-1;i>=0;i--){
heapify(a,i,n);
}
for(i=0;i<n;i++)
printf("%d ",a[i]);
getch();
}

void heapify(int a[],int i,int n){
int l,r,largest,temp;
l=2*i+1;
r=2*i+2;
if(l<n&&a[l]>a[i])
largest=l;
else largest=i;
if(r<n&&a[r]>a[largest])
largest=r;
if(largest!=i){
               temp=a[i];
               a[i]=a[largest];
               a[largest]=temp;
               heapify(a,largest,n);
               }
           }
               
       
