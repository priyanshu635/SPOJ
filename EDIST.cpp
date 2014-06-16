#include<cstdio>
#include<algorithm>

using namespace std;

int dp[2001][2001];

int main()
{
	int test,i,j;
	char a[2001],b[2001];	
	scanf("%d",&test);

	for(i=0;i<2001;i++)
	{	
		dp[0][i]=i;
		dp[i][0]=i;
	}

	while(test--)
	{
		scanf("%s",a);
		scanf("%s",b);

		for(i=0;a[i]!='\0';i++)
		{
			for(j=0;b[j]!='\0';j++)
			{
				if(a[i]==b[j])
					dp[i+1][j+1]=dp[i][j];
				else
					dp[i+1][j+1]=min(min(dp[i][j],dp[i+1][j]),dp[i][j+1])+1;
			}
		}
		printf("%d\n",dp[i][j]);		
	}	
	return 0;
}
