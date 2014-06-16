#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
	int test,n,temp,i,sum;
	vector<int> men;
	vector<int> women;
	scanf("%d",&test);	
	while(test--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			men.push_back(temp);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			women.push_back(temp);
		}

		sort(men.begin(),men.end());
		sort(women.begin(),women.end());

		for(i=0;i<n;i++)
			sum+=men[i]*women[i];

		printf("%d\n",sum);
		
		men.clear();
		women.clear();
	}	
	return 0;
}
