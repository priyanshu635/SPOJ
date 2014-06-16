#include<cstdio>
#include<vector>
#include <algorithm>

using namespace std;

int main()
{
	int test,n,m,D,i,temp;
	bool result;
	vector<int> health;
	scanf("%d",&test);	
	while(test--)	
	{	
		scanf("%d%d%d",&n,&m,&D);
		result =true;
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			health.push_back(temp);
		}		
		
		make_heap(health.begin(),health.end());

		for(i=0;i<m;i++)
		{
			if(health.front()>D)
			{
				temp=health.front()-D;
				pop_heap (health.begin(),health.end());
				health.pop_back();
				health.push_back(temp);
				push_heap (health.begin(),health.end());
			}
			else
			{
				result=false;
				break;
			}
		}

		if(result)	
			printf("YES\n");	
		else
			printf("NO\n");	

		health.clear();
	}
	return 0;
}
