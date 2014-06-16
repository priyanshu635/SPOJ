#include<cstdio>

using namespace std;

int main()
{
	long long m,sum,max;
	int a[300000],n,i,start,end;
		
	scanf("%d %lld",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	i=0;
	while(a[i]>m)
		i++;
	max=a[i];
	sum=a[i];
	for(start=0,end=1;end<n;)
	{
		if(sum+a[end]<=m)
		{
			sum=sum+a[end];
			end++;
			if(max<sum)
				max=sum;
		}
		else
		{
			sum=sum-a[start];
			start++;
		}
	}
	printf("%lld\n",max);
	return 0;
}
