#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int a[100];
bool dp[100001][101];

int main()
{
	int test,n,i,j,sum,res;
	scanf("%d",&test);

	for(i=0;i<=100;i++)
		dp[0][i]=true;

	for(i=1;i<=100000;i++)
		dp[i][0]=false;


	while(test--)
	{
		scanf("%d",&n);
		sum=0;
		res=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}

		for(i=1;i<=sum;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i<a[j-1])
					dp[i][j]=dp[i][j-1];
				else
					dp[i][j]=dp[i][j-1]||dp[i-a[j-1]][j-1];
			}
			if(dp[i][n])
				res+=i;	
		}
					
		/*for(i=0;i<=sum;i++)
		{
			for(j=0;j<=n;j++)
			{
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}*/

		printf("%d\n",res);
	
	}
	
	return 0;
}
