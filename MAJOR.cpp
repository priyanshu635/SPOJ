#include<cstdio>

using namespace std;

int main()
{
	int test,n,i,count,element;
	int a[1000001];
	scanf("%d",&test);	
	while(test--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);

		element=a[0];
		count=1;	
		for(i=1;i<n;i++)
		{
			if(a[i]==element)			
				count++;
			else if(count==0)
			{
				element=a[i];	
				count++;
			}
			else
				count--;
	
		}


		count=0;
		for(i=0;i<n;i++)
		{
			if(a[i]==element)
				count++;
		}

		if(count>n/2)
			printf("YES %d\n",element);
		else
			printf("NO\n");

	}
	return 0;
}
