/*
sieve method to find the array without any 3 numbers being in A.P.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
  FILE *ptr;
  ptr=fopen("poo.txt","w");
  int c[2000],x[100001],i,j,k;
  for(i=0;i<=100000;i++)
  x[i]=1;
   c[0]=0;
   c[1]=1;
   i=1;
   j=1;
   while(j<=500)
   { 
   for(k=0;k<=j-1;k++)
   {
     x[2*i-c[k]]=0;
   }
   while(x[i]!=1)
   {
    i=i+1;
   }
   c[++j]=i;
   x[i]=0;
   }
for(i=0;i<500;i++){
fprintf(ptr,"%d,",c[i]);
printf("%d,",c[i]);
}
fclose(ptr);
getch();  
}  
  
  
