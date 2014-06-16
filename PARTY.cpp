#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int s,n,i,j,temp;
	int a[501][501];
	int wa[501][501];
	int v[101];
	int w[101];

	while(1)
	{
		scanf("%d %d",&s,&n);

		if(s==0 && n==0)
			break;

		for(i=0;i<=s;i++)	
		{
			a[0][i]=0;
			wa[0][i]=0;
		}

		for(i=0;i<=n;i++)
		{	
			a[0][i]=0;
			wa[0][i]=0;
		}

		for(i=1;i<=n;i++)	
		{
			scanf("%d",&w[i]);
			scanf("%d",&v[i]);
		}
			
		for(j=1;j<=n;j++)
		{
			for(i=1;i<=s;i++)
			{
				if(i<w[j])
				{
					a[j%2][i]=a[(j-1)%2][i];
					wa[j%2][i]=wa[(j-1)%2][i];
				}
				else
				{
					temp=v[j]+a[(j-1)%2][i-w[j]];
					if(temp>a[(j-1)%2][i])
					{
						a[j%2][i]=temp;
						wa[j%2][i]=wa[(j-1)%2][i-w[j]]+w[j];
					}
					else if(temp==a[(j-1)%2][i])
					{
						wa[j%2][i]=(wa[(j-1)%2][i]>wa[(j-1)%2][i-w[j]]+w[j])?wa[(j-1)%2][i-w[j]]+w[j]:wa[(j-1)%2][i];
						a[j%2][i]=a[(j-1)%2][i];
					}
					else
					{
						a[j%2][i]=a[(j-1)%2][i];
						wa[j%2][i]=wa[(j-1)%2][i];
					}
				}
			}
		}
		
		printf("%d %d\n",wa[n%2][s],a[n%2][s]);
	}

	return 0;
}
