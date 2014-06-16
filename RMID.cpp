#include<cstdio>
#include<deque>

using namespace std;

int main()
{
	int n,minsize=0,maxsize=0;
	deque<int> min,max;
	
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		{
			min.clear();
			max.clear();
			minsize=0;
			maxsize=0;
			printf("\n");
			continue;
		}
		else if(n==-1)
		{
			printf("%d\n",min.back());
			min.pop_back();
			minsize--;
			if(maxsize>minsize)
			{
				min.push_back(max.front());
				minsize++;
				max.pop_front();
				maxsize--;
			}
		}
		else
		{
			max.push_back(n);
			maxsize++;
			if(maxsize>minsize)
			{
				min.push_back(max.front());
				minsize++;
				max.pop_front();
				maxsize--;
			}
		}
	}
	return 0;
}
