#include<cstdio>

using namespace std;

bool dp[100][100];

int main()
{
	int n,i,j,leng,diff;
	scanf("%d",&n);
	char a[n+1];
	

	scanf("%s",a);

	for(i=0;i<n;i++)
		dp[i][i]=true;

	leng=1;
	diff=1;
	for(i=n-1;i>=1;i--)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]==a[j+diff])
			{
				if((diff>1 && dp[j+1][j+diff-1]) || diff==1)
				{
					dp[j][j+diff]=true;
					leng=diff+1;	
				}
			}
			
			//printf("%d%d ",j,j+diff);
		}
		diff++;
	}

	/*for(i=0;i<n;i++)	
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",dp[i][j]);
		
		}	
		printf("\n");
	}*/

	printf("%d\n",leng);
	return 0;
}
