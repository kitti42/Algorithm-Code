#include<stdio.h>
main()
{
      int a[10],b[10],e1,e2,x1,x2,t1[10],t2[10];
      int n,i;
      scanf("%d",&n);
      for(i=0;i<n;i++)
      scanf("%d",&a[i]);
      for(i=0;i<n;i++)
      scanf("%d",&b[i]);
      for(i=0;i<n-1;i++)
      scanf("%d",&t1[i]);
      for(i=0;i<n-1;i++)
      scanf("%d",&t2[i]);
      printf("Enter the e1,e2,x1,x2");
      scanf("%d%d%d%d",&e1,&e2,&x1,&x2);
      int f1[10],f2[10],l1[10],l2[10];
      f1[0]=e1+a[0];
      f2[0]=e2+b[0];
      printf("1\n");
      for(i=1;i<n;i++)
      {
                     if(f1[i-1]+a[i]<=f2[i-1]+t2[i-1]+a[i])
                     {
                                                           f1[i]=f1[i-1]+a[i];
                                                           l1[i]=1;
                     }
                     else
                     {
                         f1[i]=f2[i-1]+t2[i-1]+a[i];
                         l1[i]=2;
                     }
                     if(f2[i-1]+b[i]<=f1[i-1]+t1[i-1]+b[i])
                     {
                                                           f2[i]=f2[i-1]+b[i];
                                                           l2[i]=2;
                     }
                     else
                     {
                         f2[i]=f1[i-1]+t1[i-1]+b[i];
                         l2[i]=1;
                     }
      }
      int ff,ll;
      if(f1[n-1]+x1<=f2[n-1]+x2)
      {
                                ff=f1[n-1]+x1;
                                ll=1;
      }
      else
      {
          ff=f2[n-1]+x2;
          ll=2;
      }
      i=ll;
      int j;
      printf("line %d station %d\n",i,n-1);
      for(j=n-1;j>0;j--)
      {
                        if(i==1)
                        {
                                  i=l1[j];
                                printf("line %d station %d\n",i,j-1);
                        }
                        else
                        {
                            i=l2[j];
                            printf("line %d station %d\n",i,j-1);
                        }
      }
      printf("optimum cost is %d",ff);
      getch();
}
                                                              
