/*
You are given an unweighted, undirected tree. Write a program to output the length of the longest path (from one node to another) in that tree. The length of a path in this case is number of edges we traverse from source to destination.

Input

The first line of the input file contains one integer N --- number of nodes in the tree (0 < N <= 10000). Next N-1 lines contain N-1 edges of that tree --- Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u,v <= N).

Output

Print the length of the longest path on one line.

Example

Input:
3
1 2
2 3

Output:
2
*/

#include<iostream>
#include<vector>

using namespace std;

vector<bool> visited;
vector<vector<int> > list;

int maxdia=0;

int treeDiameter(int vertex)
{
	int firstmax=0,secondmax=0,temp;
	visited[vertex]=true;

	for(vector<int>::iterator it = list[vertex].begin() ; it != list[vertex].end(); ++it)
	{
		if(visited[*it])
			continue;
		
		temp=treeDiameter(*it)+1;
		if(temp>firstmax)
		{
			secondmax=firstmax;
			firstmax=temp;
		}
		else if(temp>secondmax)
		{
			secondmax=temp;			
		}
	}

	if(firstmax+secondmax>maxdia)
		{
			maxdia=firstmax+secondmax;		
		}
	
	return firstmax;
}


int main()
{
	int n,i,u,v;
	cin>>n;

	visited.resize(n);
	list.resize(n);
	
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		u--;
		v--;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	treeDiameter(0);

	cout<<maxdia<<"\n";
	return 0;
}
