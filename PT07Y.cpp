#include<cstdio>
#include<map>
#include<vector>
#include<stack>

using namespace std;

bool visited[10001];
map<int, vector<int> > graph;
stack<int> s;

bool DFS()
{
	int temp;	
	bool twice;
	while(!s.empty())
	{
		temp=s.top();
		s.pop();
		twice=false;
		//printf("temp %d\n",temp);
		//printf("visit %d %d %d\n",visited[1],visited[2],visited[3]);
		for(vector<int>::iterator it=graph[temp].begin();it!=graph[temp].end();it++)
		{
			if(twice && visited[*it])
			{	
				//printf("1\n");
				return false;
			}
			if(visited[*it])
			{
				//printf("2\n");
				twice=true;
			}
			else	
			{
				//printf("--%d ",*it);
				s.push(*it);
				visited[*it]=true;
			}
		}
	}
	return true;
}

int main()
{
	int n,m,i,a,b;
	scanf("%d",&n);
	scanf("%d",&m);

	for(i=1;i<=n;i++)
	{
		vector<int> v;
		graph.insert(pair<int, vector<int> >(i,v));
	}

	for(i=1;i<=m;i++)
	{
		scanf("%d",&a);
		scanf("%d",&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	if(n-1!=m)
	{
		printf("NO\n");
		return 0;
	}

	
	/*for(map<int, vector<int> >::iterator it=graph.begin();it!=graph.end();it++)
	{
		printf("%d\n",it->first);
		vector<int> v = it->second;
		for(vector<int>::iterator itr=v.begin();itr!=v.end();itr++)
			printf("%d ",*itr);
		printf("\n\n");
	}*/
	



		s.push(a);
		visited[a]=true;
		if(DFS())
			printf("YES\n");
		else
			printf("NO\n");


	return 0;
}
