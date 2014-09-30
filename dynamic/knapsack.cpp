#include<stdio.h>
#include<conio.h>
int table[100][100];
int weight;
int knapsack(int i,int n,int weight,int val[],int w[]);
main()
{
      int n,i,j;
      scanf("%d",&n);
      printf("enter weight of sack");
      scanf("%d",&weight);
      int val[n],w[n];
      for(i=0;i<weight+1;i++)
      for(j=0;j<n+1;j++)
      table[i][j]=0;
      for(i=0;i<n;i++)
      scanf("%d%d",&w[i],&val[i]);
      int value=knapsack(0,n,weight,val,w);
      printf("weight is %d\n",weight);
      for(i=0;i<weight+1;i++)
      {
                           for(j=0;j<n+1;j++)
                           printf("%d %d %d     ",i,j,table[i][j]);
                           printf("\n");
      }
      getch();
}
int knapsack(int i,int n,int weight,int val[],int w[])
{
    printf("1");
     if(i>n){
             table[weight][i]=0;
     return table[weight][i];}
     else
     {
         if(weight<w[i])
         {
                        if(table[weight][i+1]==0)
                        {
                                                 table[weight][i+1]=knapsack(i+1,n,weight,val,w);
                                                 return table[weight][i+1];
                        }
         }
         else
         {
             if(table[weight][i+1]==0)
             {
                                      table[weight][i+1]=knapsack(i+1,n,weight,val,w);
             }
             if(table[weight-w[i]][i+1]==0)
             {
                                           
                                           table[weight-w[i]][i+1]=knapsack(i+1,n,weight-w[i],val,w);
             }
             if(table[weight][i+1]>val[i]+table[weight-w[i]][i+1])
                                           return table[weight][i+1];
             else
                                           return val[i]+table[weight-w[i]][i+1];
         }
     }
} 
                                           
                                           
                        
     
                                                                
                     
      
