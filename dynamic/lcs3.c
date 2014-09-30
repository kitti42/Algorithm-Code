#include<stdio.h>
#include<conio.h>
#include<string.h>
 int c[30];
int print_lcs(char s1[],int i,int j);
main()
{
      char s1[30],s2[30];
      int m,n,i,j;
      gets(s1);
      gets(s2);
      m=strlen(s1);
      n=strlen(s2);
      for(i=0;i<=m;i++)
      c[i]=0;
      for(i=1;i<=n;i++)
      {
                      for(j=1;j<=m;j++)
                      {
                                       if(s1[j-1]==s2[i-1])
                                       {
                                                       c[j]=c[j]+1;
                                       }
                                       else 
                                       {
                                            if(c[j-1]>c[j])
                                            {
                                                                   c[j]=c[j-1];
                                            }
                                       }
                      }
      }
      printf("%d",c[m]);
      getch();
}

     
     
     
                                                
                                                       
                                                       
                                      
      
