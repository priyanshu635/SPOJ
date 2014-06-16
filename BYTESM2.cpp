#include<cstdio>
#include<climits>
#include<algorithm>

using namespace std;

int main()
{
	int test,m,n,maxi,i,j,sum;
	int a[100][100];
	int dp[100][100];
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&a[i][j]);

		maxi=INT_MIN;
		for(i=0;i<m;i++)
		{
			dp[0][i]=a[0][i];
			if(dp[0][i]>maxi)
				maxi=dp[0][i];
		}
	
		
		for(i=1;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				sum=dp[i-1][j];
				if(j-1>=0)
					sum=max(dp[i-1][j-1],sum);
				if(j+1<m)
					sum=max(sum,dp[i-1][j+1]);
				
				dp[i][j]=sum+a[i][j];
				if(dp[i][j]>maxi)
					maxi=dp[i][j];
			}
		}

		/*for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}*/

		printf("%d\n",maxi);
	}
	return 0;
}
