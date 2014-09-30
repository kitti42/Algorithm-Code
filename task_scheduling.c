#include<stdio.h>
#include<conio.h>
void swap(int a[],int i,int j);
main(){
       int n,i,j,count=1,penalty=0;
       scanf("%d",&n);
       int d[n+1],p[n+1],a[n+1];
       for(i=0;i<n;i++){
       scanf("%d%d",&d[i],&p[i]);
       a[i]=0;
       }
for(i=0;i<n-1;i++){
                   for(j=i+1;j<n;j++){
                                      if(p[i]<p[j]){
                                      swap(p,i,j);
                                      swap(d,i,j);
                                      }
                                }}
for(i=0;i<n;i++){
                 if(a[d[i]-1]==0)
                 a[d[i]-1]=1;
                 else{
                      int m=0;
                      for(j=d[i]-2;j>=0;j--){
                      if(a[j]==0){
                      a[j]=1;
                      m=1;
                      break;
                      }}
                      if(m==0){
                               penalty=penalty+p[i];
                               }
                      }
                      }

printf("%d",penalty);
getch();
}
void swap(int a[],int i,int j){
     int temp;
     temp=a[i];
     a[i]=a[j];
     a[j]=temp;
     }
                                
