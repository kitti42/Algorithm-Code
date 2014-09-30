/*code: kriti dang 
partition an array into 2 parts of same sum*/


#include<stdio.h>
#include<conio.h>
main(){
       int n,i,j,c=0;
       scanf("%d",&n);
       int a[n+1],sum=0;
for(i=0;i<n;i++){
                 scanf("%d",&a[i]);
                 sum=sum+a[i];
                 }
if(sum%2==0){
             int t=sum/2;
             int p[n+1][t+1];
             for(i=0;i<n;i++)
             for(j=0;j<t+1;j++)
             p[i][j]=0;
             for(i=0;i<n;i++){ 
             for(j=1;j<t+1;j++){
                                if(j==a[i])
                                p[i][j]=1;
                                else if(i>0&&(p[i-1][j]==1||(p[i-1][j-a[i]]==1&&j-a[i]>0)))
                                p[i][j]=1;
             if(j==t&&p[i][j]==1){
                                  c=1;
                                  break;
                                  }
                                  }
             if(c==1){                                          
                      printf("YES\n");
                      break;
                      }
                      }if(c==0)
printf("NO\n");
             }
else printf("NO\n");

/*for(i=0;i<n+1;i++){
             for(j=0;j<t+1;j++){
                                printf("%d ",p[i][j]);
                                }
                                printf("\n");
                                }*/
getch();

}
