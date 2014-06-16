#include<cstdio>
#include<algorithm>

using namespace std;

struct Distance
{
	int left;
	int right;
}plank[10010];
	
bool mySortFunction(struct Distance d1, struct Distance d2)
{
	return d1.left<d2.left;
}

int main()
{
	int test,n,i,r,count;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		count=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&plank[i].left);
			scanf("%d",&plank[i].right);
		}

		sort(plank,plank+n,mySortFunction);

		/*for(i=0;i<n;i++)
			printf("%d %d\n",plank[i].left,plank[i].right);
		*/
	
		r=plank[0].right;
		count++;
		for(i=1;i<n;i++)
		{
			if(plank[i].left>r)
			{
				count++;
				r=plank[i].right;
			}
			else
			{
				r=min(r,plank[i].right);
			}
		}
		
		printf("%d\n",count);
	}
	return 0;
}
