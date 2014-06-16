#include<cstdio>

int a[1001][51];
int v[51];
int w[51];

int main()
{
	int s,n,i,j,t;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d",&s,&n);

		for(i=1;i<=n;i++)	
		{
			scanf("%d",&w[i]);
			scanf("%d",&v[i]);
		}

		for(i=0;i<=s;i++)
			a[i][0]=0;

		for(i=0;i<=n;i++)
			a[0][i]=0;

		for(i=1;i<=s;i++)
			for(j=1;j<=n;j++)
				if(i<w[j])
					a[i][j]=a[i][j-1];
				else	
					a[i][j]=(a[i][j-1]>v[j]+a[i-w[j]][j-1])?a[i][j-1]:v[j]+a[i-w[j]][j-1];

		/*for(i=0;i<=s;i++)
		{
			for(j=0;j<=n;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}*/

		printf("Hey stupid robber, you can get %d.\n",a[s][n]);
	}
	return 0;
}
