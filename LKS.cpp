#include<cstdio>

int a[2][2000001];

int main()
{
	int s,n,i,j,temp;
	int v[501];
	int w[501];

	scanf("%d %d",&s,&n);

	for(i=1;i<=n;i++)	
	{
		scanf("%d",&v[i]);
		scanf("%d",&w[i]);
	}

	for(j=1;j<=n;j++)
	{
		for(i=1;i<=s;i++)
		{
			if(i<w[j])
				a[j%2][i]=a[(j-1)%2][i];
			else
			{
				temp=v[j]+a[(j-1)%2][i-w[j]];
				a[j%2][i]=(temp>a[(j-1)%2][i])?temp:a[(j-1)%2][i];
			}

		}
	}

	printf("%d\n",a[n%2][s]);
	return 0;
}
