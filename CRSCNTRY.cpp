#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int dp[2001][2001];

int LCS(vector<int> a, vector<int> b)
{
	int i,j;
	for(i=0;i<a.size();i++)
	{
		for(j=0;j<b.size();j++)
		{
			if(a[i]==b[j])
				dp[i+1][j+1]=dp[i][j]+1;
			else
				dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
		}
	}
	return dp[i][j];
}

int main()
{
	int test,n,maxi,count;
	scanf("%d",&test);
	while(test--)
	{
		vector<int> a;
		vector<int> b;
		maxi=0;count=0;
		while(1)
		{
			scanf("%d",&n);
			if(n==0)
				break;
			a.push_back(n);
		}
	
		while(1)
		{
			while(1)
			{
				scanf("%d",&n);
				if(n==0)
					break;
				b.push_back(n);
			}

			if(b.size()==0)
				break;
		
			count=LCS(a,b);
			if(count>maxi)
				maxi=count;
			b.clear();
		}
		printf("%d\n",maxi);
	}
	return 0;
}
