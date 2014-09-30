#include<stdio.h>
#include<conio.h>
main()
{
       int n,wt,j;
       scanf("%d%d",&wt,&n);
       int v[n+1],w[n+1],i;
       int c[n+1][wt];
       for(i=1;i<=n;i++)
	   {
            scanf("%d%d",&w[i],&v[i]);
       }
       for(i=0;i<=wt;i++)
       c[0][i]=0;
		for(i=1;i<=n;i++)
		{
			c[i][0]=0;
			for(j=1;j<=wt;j++)
			{
                if(w[i]<=j)
				{
                    if((v[i]+c[i-1][j-w[i]])>(c[i-1][j]))
                    c[i][j]=v[i]+c[i-1][j-w[i]];
                    else
                    c[i][j]=c[i-1][j];
                }
                else
				{
                    c[i][j]=c[i-1][j];
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=wt;j++)
            printf("%d %d %d\n",i,j,c[i][j]);
        }
		printf("%d",c[n][wt]);
}
                        
                                
                                
                                 
                                 
                                                   
                                     
                        
       
       

       
