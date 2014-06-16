#include<cstdio>
#include<algorithm>

using namespace std;

int a[1001][32];

int main()
{
	int test,i,j,n;
	
	for(i=1;i<=1000;i++)
		a[i][1]=i;

	for(i=1;i<=1000;i++)
	{
		for(j=2;j<=31;j++)
		{
			if(i-j*j>=0)	
				a[i][j]=min(a[i-j*j][j]+1,a[i][j-1]);
			else
				a[i][j]=a[i][j-1];
		}
	}

	/*for(i=0;i<=20;i++)
	{
		for(j=0;j<=31;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	*/

	scanf("%d",&test);	
	while(test--)
	{
		scanf("%d",&n);
		printf("%d\n",a[n][31]);
	}
	return 0;
}
