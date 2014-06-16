#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int f,s,g,u,d;
	int ele,uele,dele,count;

	scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);

	bool visited[f+1];
	memset(visited,0,sizeof(bool)*(f+1));	//setting all vales false...

	queue<int> q;
	q.push(s);
	q.push(0);
	count=0;
	visited[s]=true;
	while(!q.empty())
	{
		ele=q.front();
		q.pop();
		if(ele==0)
		{
			count++;
			if(q.size()>0)
				q.push(0);
			continue;
		}
		if(ele==g)
			break;
		uele=ele+u;
		dele=ele-d;

		if(dele>=1 && !visited[dele])
		{
			q.push(dele);
			visited[dele]=true;
			
		}
		if(uele<=f && !visited[uele])
		{
				q.push(uele);
				visited[uele]=true;
		}
	}

	if(q.empty())
		printf("use the stairs\n");
	else
		printf("%d\n",count);

	return 0;
}
