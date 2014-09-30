#include<stdio.h>
#include<conio.h>
#include<string.h>
char b[30][30];
int print_lcs(char s1[],int i,int j);
main()
{
      char s1[30],s2[30];
      int c[30][30];
      int m,n,i,j;
      gets(s1);
      gets(s2);
      m=strlen(s1);
      n=strlen(s2);
      for(i=0;i<=n;i++)
      c[0][i]=0;
      for(i=1;i<=m;i++)
      c[i][0]=0;
      for(i=1;i<=m;i++)
      {
                      for(j=1;j<=n;j++)
                      {
                                       if(s1[i-1]==s2[j-1])
                                       {
                                                       c[i][j]=c[i-1][j-1]+1;
                                                       b[i][j]='b';
                                       }
                                       else 
                                       {
                                            if(c[i][j-1]>c[i-1][j])
                                            {
                                                                   c[i][j]=c[i][j-1];
                                                                   b[i][j]='l';
                                            }
                                            else
                                            {
                                                                   c[i][j]=c[i-1][j];
                                                                   b[i][j]='u';
                                            }
                                       }
                      }
      }
      print_lcs(s1,m,n);
      getch();
}
int print_lcs(char s1[],int i,int j)
{
     if(i==0||j==0)
     return 0;
     if(b[i][j]=='b')
     {
                     print_lcs(s1,i-1,j-1);
                     printf("%c",s1[i-1]);
     }
     else if(b[i][j]=='l')
     {
          print_lcs(s1,i,j-1);
     }
     else
     print_lcs(s1,i-1,j);
}
     
     
     
                                                
                                                       
                                                       
                                      
      
