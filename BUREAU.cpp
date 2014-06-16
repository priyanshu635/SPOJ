#include<cstdio>

using namespace std;

int main()
{
	int test,n,count,i,no;
	int natu[100001];
	int law[100001];
	char type[10];
	scanf("%d",&test);	
	while(test--)
	{
		scanf("%d",&n);
		count=n;
		for(i=1;i<=n;i++)
		{
			scanf("%s",type);
			if(type[0]=='d')
				law[i]=-1;
			else
			{
				scanf("%d",&no);
				law[i]=no;
			}

		}

		for(i=1;i<=n;i++)
			natu[i]=i;
		
		for(i=n;i>0;i--)
		{
			if(law[i]>0)
			{
				if(natu[law[i]]>0)
				{
					natu[law[i]]=-1;
					count--;
				}
				if(law[law[i]]>0)
					law[law[i]]=-1;
			}
		}
	
		printf("%d\n",count);
		for(i=1;i<=n;i++)
			if(natu[i]>0)
				printf("%d ",natu[i]);
		printf("\n");
	}
	return 0;
}
