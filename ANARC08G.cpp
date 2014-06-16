#include<cstdio>
#include<climits>

using namespace std;

int a[1000][1000];
int take[1000];
int give[1000];

void printMatrix(int n)
{
		for(int i=0;i<n;i++)	
		{	for(int j=0;j<n;j++)
			{
				printf("%d ",a[i][j]);
			}		printf("\n");
		}
		
}


int main()
{
	int n,i,j,tc=1,sum,origsum;
	scanf("%d",&n);	
	while(n!=0)
	{
		origsum=0;
		for(i=0;i<n;i++)	
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
				origsum+=a[i][j];
			}
		
		//printMatrix(n);

		for(i=0;i<n;i++)
		{
			sum=0;
			for(j=0;j<n;j++)
				sum+=a[i][j];
			give[i]=sum;
		}

		for(i=0;i<n;i++)
		{
			sum=0;
			for(j=0;j<n;j++)
				sum+=a[j][i];
			take[i]=sum;
		}

		/*for(i=0;i<n;i++)
		{
			printf("%d ",take[i]);
		}
		printf("\n");

		for(i=0;i<n;i++)
		{
			printf("%d ",give[i]);
		}
		printf("\n");
		*/

		sum=0;
		for(i=0;i<n;i++)
		{
			if(take[i]>give[i])		
				sum+=take[i]-give[i];
		}
		
		printf("%d. %d %d\n",tc++,origsum,sum);

		scanf("%d",&n);
	}
	return 0;
}
