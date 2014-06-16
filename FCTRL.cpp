#include<cstdio>

using namespace std;
int main()
{
	int test,j;
	long long int count,n,i;
	long long a[14];	//values filled from 1 to 12

	for(i=1,j=0;j<=13;j++,i=i*5)
		a[j]=i;

	scanf("%d",&test);
	while(test--)
	{
		count=0;
		scanf("%lld",&n);

		
		for(i=1;a[i]<=n;i++)
		{
			count+=n/a[i];
		}		

		printf("%lld\n",count);
	}
	return 0;
}
