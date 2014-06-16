#include<cstdio>
#include<algorithm>

using namespace std;

int a[2001][2001];
int v[2001];
int w[2001];

int main()
{
	int s,n,i,j;
	scanf("%d %d",&s,&n);

	for(i=1;i<=n;i++)	
	{
		scanf("%d",&w[i]);
		scanf("%d",&v[i]);
	}

	for(i=1;i<=s;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i<w[j])
				a[i][j]=a[i][j-1];
			else	
			{
				a[i][j]=max(a[i][j-1],v[j]+a[i-w[j]][j-1]);
			}

		}
	}

	/*for(i=0;i<=s;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/

	printf("%d\n",a[s][n]);
	return 0;
}
