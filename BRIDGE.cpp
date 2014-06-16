#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<climits>

using namespace std;

struct bridge
{
	int x;
	int y;
}array[1000];

int aux[1000];

int mysort(bridge p1,bridge p2)
{
	if(p1.x<p2.x)
		return 1;
	if(p1.x==p2.x && p1.y<p2.y)
		return 1;
	return 0;
}

int lis(int n)
{
	int i,j,max,retval=1;
	aux[0]=1;
	for(i=1;i<n;i++)
	{
		max=0;
		for(j=i-1;j>=0;j--)
		{
			if(array[i].y>=array[j].y && max<aux[j])
				max=aux[j];
		}		
		aux[i]=max+1;
		if(retval<aux[i])
			retval=aux[i];
	}
	return retval;
}

int main()
{
	int test,n,i;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);

		for(i=0;i<n;i++)
			scanf("%d",&array[i].x);
		for(i=0;i<n;i++)
			scanf("%d",&array[i].y);

		sort(array,array+n,mysort);

		printf("%d\n",lis(n));
	}
	return 0;
}
