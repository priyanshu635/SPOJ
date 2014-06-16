#include<cstdio>
#include<string.h>

using namespace std;

bool dp[100][100];
char a[101];

int main()
{
	int n,i,j,diff,t,s,e;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		for(i=0;a[i]!='\0';i++)
			dp[i][i]=true;

		diff=1;
		n=strlen(a);
		s=0;e=0;
		for(i=n-1;i>=1;i--)
		{
			for(j=0;j<i;j++)
			{
				if(a[j]==a[j+diff])
				{
					if((diff>1 && dp[j+1][j+diff-1]) || diff==1)
					{
						dp[j][j+diff]=true;
						if((e-s)<diff)
						{
							s=j;e=j+diff;
						}
					}
				}
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

		for(i=s;i<=e;i++)
			printf("%c",a[i]);	
		printf("\n");
	}
	
	return 0;
}



//jai.jaiswal@iprusales.com
//jai9839969636@gmail.com
