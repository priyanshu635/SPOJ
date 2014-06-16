#include<cstdio>

using namespace std;

int main()
{
	int n,sum,i;
	scanf("%d",&n);	
	while(n!=0)
	{
		sum=0;
		for(i=1;i<=n;i++)	
			sum+=(n-(i-1))*(n-(i-1));
		printf("%d\n",sum);
		scanf("%d",&n);	
	}
	return 0;
}
