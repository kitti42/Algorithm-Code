/*
  Name: KRITI DANG
  Copyright: 
  Author: 
  Date: 03/08/13 17:40
  Description: STABLE MARRIAGE PROBLEM
*/

#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
//-----------------------------------------------------------------------------

int main()
{
    
   int t;
   scanf("%d",&t);
   while(t--)
   {
       
       int n;                       //number of man or woman
       scanf("%d",&n);
       int man[n+3][n+3],woman[n+3][n+3];     //preferrance of man and woman
       bool isMarriedM[n+3],isMarriedW[n+3];
       int Wman[n+3],Mwoman[n+3];   //wife of man & husband of woman
       int i,j,k;
       
       for(i=1;i<=n;i++)
       {
          scanf("%d",&k);
          for(j=0;j<n;j++)
          scanf("%d",&man[i][j]);
          man[i][n]=0;    
       }               
       for(i=1;i<=n;i++){
       scanf("%d",&k);
       for(j=0;j<n;j++)
       scanf("%d",&woman[i][j]);
       }
       
       for(i=1;i<=n;i++)
       {
          isMarriedM[i]=false;
          isMarriedW[i]=false;
       }
       isMarriedM[0]=true;
       int flag=1,temp;
       while(flag==1)
       {  
          flag=0;
          for(k=1;k<=n;k++)
          {
             if(isMarriedM[k]==false)
             {
               flag=1;
                break;
             } 
          } 
          if(flag==1)
          {   
             for(i=1;i<=n;i++)
             {
                 if(isMarriedM[i]==false)
                 {
                    temp=man[i][n];
                    man[i][n]++;
                    if(isMarriedW[man[i][temp]]==false)
                    {
                       isMarriedW[man[i][temp]]=true;
                       isMarriedM[i]=true;
                       Wman[i]=man[i][temp];
                       Mwoman[man[i][temp]]=i;
                    }
                    else 
                    {
                       for(j=0;j<n;j++)
                       {
                          if(woman[man[i][temp]][j]==i)
                          {
                             isMarriedM[Mwoman[man[i][temp]]]=false;
                             isMarriedM[i]=true;
                             Wman[i]=man[i][temp];
                             Mwoman[man[i][temp]]=i;
                             break;
                          }
                          else if(woman[man[i][temp]][j]==Mwoman[man[i][temp]])
                          {
                             i--;
                             break;
                          } 
                        }
                    }
                 }
             }
          }
       }
       
          for(i=1;i<=n;i++)
          printf("%d %d\n",i,Wman[i]);
   }
   getch();
   return 0;
}
             
                
             
       
       
       
      
      
