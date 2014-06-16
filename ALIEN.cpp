#include<cstdio>

using namespace std;

int main()
{
	long long testcases,at,bt,i;
	scanf("%lld",&testcases);
	while(testcases--)
	{
		scanf("%lld%lld",&at,&bt);
		long long *a=new long long[at];
		for(i=0;i<at;i++)
			scanf("%lld",&a[i]);
		
		long long minsum=0,start=-1,finallength=0,finalsum=0;
		for(i=0;i<at;i++)
		{
			minsum+=a[i];

			if(minsum>bt)
			{
				if(((i-1)-start)>finallength)
				{
					finallength=(i-1)-start;
					finalsum=minsum-a[i];
				}
				else if(((i-1)-start)==finallength)
				{
					if((minsum-a[i])<finalsum)
						finalsum=minsum-a[i];
				}

				minsum=minsum-a[start+1]-a[i];

				if(a[i]>bt)
				{
					minsum=0;
					start=i;
					continue;
				}

				i--;
				start++;
			}
			else if((i-start)>finallength)
			{
				finallength=i-start;
				finalsum=minsum;
			}
			else if((i-start)==finallength)
			{
				finallength=i-start;
				if(minsum<finalsum)				
					finalsum=minsum;
			}
		}

		printf("%lld %lld\n",finalsum,finallength);
	}
	return 0;
}
