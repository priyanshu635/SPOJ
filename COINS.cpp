#include<cstdio>

using namespace std;

long long a[10000001];

int const limit=10000000;

long long calculateSum(long long n)
{
	if(n<=limit)
		return a[n];
	return 	calculateSum(n/2)+calculateSum(n/3)+calculateSum(n/4);
}

int main()
{
	long long n,sum;
	
	a[0]=0;
	a[1]=1;
	a[2]=2;

	for(int i=3;i<=limit;i++)
	{
		sum=a[i/2]+a[i/3]+a[i/4];
		if(sum>i)
			a[i]=sum;
		else
			a[i]=i;
	}

	while(scanf("%lld",&n)!=EOF)
		printf("%lld\n",calculateSum(n));

	return 0;
}
