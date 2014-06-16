#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<iostream>
#include<cstring>

using namespace std;

struct node
{
	int from;
	int to;
	int cost;
};

int sortFunctn(node n1,node n2)
{
	return n1.cost>n2.cost;
}

int MSTPrims(map<int,vector<node> > graph,int n)
{
	int cost=0,count;
	int *finish=(int *)malloc(sizeof(int)*n);
		
	for(int i=0;i<n;i++)
		finish[i]=0;
	
	vector<node> mincost;
	node temp;

	//fixing first node.. make count 1.. finish true.. inserting edges into heap
	count=1;
	for(vector<node>::iterator it=graph[1].begin(); it!=graph[1].end();it++)
		mincost.push_back(*it);
	finish[1-1]=1;

	make_heap(mincost.begin(),mincost.end(),sortFunctn);

	while(count<n)
	{
		temp=mincost.front();
		pop_heap(mincost.begin(),mincost.end(),sortFunctn);
		mincost.pop_back();

		if(finish[temp.from-1]==1 && finish[temp.to-1]==1)
			continue;

		if(finish[temp.from-1]==0)
		{
			cost=cost+temp.cost;
			finish[temp.from-1]=1;
			count++;
			for(vector<node>::iterator it=graph[temp.from].begin(); it!=graph[temp.from].end();it++)
			{
				mincost.push_back(*it);
				push_heap (mincost.begin(),mincost.end(),sortFunctn);
			}
			continue;
		}

		if(finish[temp.to-1]==0)
		{
			cost=cost+temp.cost;
			finish[temp.to-1]=1;
			count++;
			for(vector<node>::iterator it=graph[temp.to].begin(); it!=graph[temp.to].end();it++)
			{
				mincost.push_back(*it);
				push_heap (mincost.begin(),mincost.end(),sortFunctn);
			}
			continue;
		}
	}

	return cost;
}

int main()
{
	int test,p,m,n,i,to,from,cost;
	
	scanf("%d",&test);
	while(test--)
	{
		map<int,vector<node> > graph;
		struct node temp;

		scanf("%d",&p);
		scanf("%d",&n);
		scanf("%d",&m);
	
		//adjacency list
		for(i=0;i<m;i++)
		{
			scanf("%d",&from);
			scanf("%d",&to);
			scanf("%d",&cost);
			
			temp.to=to;
			temp.cost=cost;
			temp.from=from;
			if(graph.count(from)>0)
				graph[from].push_back(temp);
			else
			{
				vector<node> v;
				v.push_back(temp);
				graph.insert(pair<int,vector<node> >(from,v));
			}
					
			temp.from=to;	
			temp.to=from;
			temp.cost=cost;
			if(graph.count(to)>0)
				graph[to].push_back(temp);
			else
			{
				vector<node> v;
				v.push_back(temp);
				graph.insert(pair<int,vector<node> >(to,v));
			}
		}

		//printing adjacecny list
		/*for (map<int,vector<node> >::iterator it=graph.begin(); it!=graph.end(); ++it)
 			{	
				cout << it->first << "\n";
				vector<node> ve=it->second;
				for(int l=0;l<ve.size();l++)
					cout<<ve[l].from<<" "<<ve[l].to<<" "<<ve[l].cost<<"\n";
			}
		*/
		
		printf("%d\n",MSTPrims(graph,n)*p);	//minimum cost multiply cost of pave
	}

	return 0;
}
