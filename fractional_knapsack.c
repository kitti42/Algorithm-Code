#include<stdio.h>
#include<conio.h>
void swap(int a[],int i,int j);
main(){
       int n,wt,j,i;
       scanf("%d%d",&wt,&n);
       int v[n+1],w[n+1];
       int c;
      float value=0;
       for(i=0;i<n;i++){
                        scanf("%d%d",&w[i],&v[i]);
                        }
for(i=0;i<n-1;i++){
                   for(j=i+1;j<n;j++){
                                      if((float)w[i]/v[i]>(float)w[j]/v[j]){
                                      swap(w,i,j);
                                      swap(v,i,j);
                                      }
                                }}
i=0;   
while(wt>=0){if(wt-w[i]>=0){
             wt=wt-w[i];
             value=value+v[i];
              i++;
             }
             else{
             value=value+((wt*1.0/w[i])*v[i]);
             wt=-1;
             c=i;
             }
             
}
printf("%f",value);
getch();
}
void swap(int a[],int i,int j){
     int temp;
     temp=a[i];
     a[i]=a[j];
     a[j]=temp;
     }
     
