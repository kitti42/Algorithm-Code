#include<stdio.h>
#include<conio.h>
void swap(int a[],int i,int j);
main(){
       int n,i,j,k;
       scanf("%d",&n);
       int s[n+1],c[n+1],a[n+1],b[n+1];
       for(i=0;i<n;i++){
                        scanf("%d%d",&s[i],&c[i]);
                        }
       for(i=0;i<n-1;i++){
                          for(j=i+1;j<n;j++){ 
                                             if(c[i]>c[j]){
                                                           swap(c,i,j);
                                                           swap(s,i,j);
                                                           }
                                             }
                          }
                          for(i=0;i<n;i++){
                        printf("%d %d\n",s[i],c[i]);
                        }
       i=0,k=0;
       while(i<n){
                  j=i+1;
                  a[k]=s[i];
                  b[k++]=c[i];
                  while(c[i]>s[j]&&j<n)
                  j++;
                  i=j;
                  }
                  for(i=0;i<k;i++)
                  printf("%d %d\n",a[i],b[i]);
                  getch();
                  }
                  void swap(int a[],int i,int j)
                  {
                       int temp=a[i];
                       a[i]=a[j];
                       a[j]=temp;
                  }
                         
                         
                         
                      
                  
                  
                                                           
                                                           
