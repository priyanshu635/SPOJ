#include<cstdio>

using namespace std;

int josephus(int n,int k)
{
	int pos=1,i;
	for(i=2;i<=n;i++)
	{
		pos=(pos+k-1)%i+1;
	}
	return pos;
}

int main()
{
	int n,d;
	while(1)
	{
		scanf("%d%d",&n,&d);	
		if(n==0 && d==0)
			break;

		printf("%d %d %d\n",n,d,josephus(n,d));
	}
	return 0;
}
