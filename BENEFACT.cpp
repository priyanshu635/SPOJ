/*


Another chapter of the municipal chronicles of a well known unbelievable lordly major town (if this town is not well known to you, you might want to solve problem CSTREET first) tells us the following story:
Once upon a time the citizens of the unbelievable lordly major town decided to elect a major. At that time this was a very new idea and election campaigns were completely unknown. But of course several citizens wanted to become major and it didn't took long for them to find out, that promising nice things that never will become real tends to be useful in such a situation. One candidate to be elected as a major was Ivo sometimes called the benefactor because of his valuable gifts to the unbelievably lordly major towns citizens.
One day before the election day Ivo the benefactor made a promise to the citizens of the town. In case of his victory in the elections he would ensure that on one of the paved streets of the town street lamps would be erected and that he would pay that with his own money. As thrifty as the citizens of the unbelievable lordly major town were, they elected him and one day after the elections they presented him their decision which street should have street lamps. Of course they chose not only the longest of all streets but renamed several streets so that a very long street in the town existed.
Can you find how long this street was? To be more specific, the situation is as follows. You are presented a list of all paved streets in the unbelievable lordly major town. As you might remember from problem CSTREET in the town the streets are paved in a way that between every two points of interest in the town exactly one paved connection exists. Your task is to find the longest distance that exists between any two places of interest in the city.
Input

The first line of input contains the number of testcases t.
The first line of each testcase contains the number of places (2 <=n<=50000) in the town. Each street is given at one line by two places (1<=a,b<=n) and the length of the street (0<=l<20000).
Output

For each testcase output one line which contains the maximum length of the longest street in the city.
Example

Input:
1
6
1 2 3
2 3 4 
2 6 2
6 4 6
6 5 5

Output:

12


*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>

using namespace std;

struct node
{
	int nodeno;
	int weight;
};

vector < vector < struct node *> > v;
vector<bool> visited;
int maxdia=0;

int diameterTree(int i)
{
	int firstmax=0,secondmax=0,temp=0;
	visited[i]=true;
	
	for (vector<struct node *>::iterator it = v[i].begin() ; it != v[i].end(); ++it)
	{
		if(!visited[(*it)->nodeno])
			{
			temp=diameterTree((*it)->nodeno)+(*it)->weight;	
			}
		else
			continue;
		
		if(firstmax<temp)
		{
			secondmax=firstmax;
			firstmax=temp;			
		}
		else if(secondmax<temp)
			secondmax=temp;
	
	}
	
	if(firstmax+secondmax>maxdia)	
		maxdia=firstmax+secondmax;

	return firstmax;
}

int main()
{
	int tc,i,n,j,n1,n2,w;
	scanf("%d",&tc);

	for(i=0;i<tc;i++)
	{
		maxdia=0;
		scanf("%d",&n);	
		v.resize(n+1);
		visited.resize(n+1);
		for(j=1;j<n;j++)
		{
			struct node *temp1=(struct node *)malloc(sizeof(struct node));
			struct node *temp2=(struct node *)malloc(sizeof(struct node));
			scanf("%d",&n1);
			scanf("%d",&n2);
			scanf("%d",&w);

			temp1->nodeno=n2;
			temp1->weight=w;
			v[n1].push_back(temp1);

			temp2->nodeno=n1;	
			temp2->weight=w;
			v[n2].push_back(temp2);
		}

		diameterTree(1);
		printf("%d\n",maxdia);
		v.clear();
		visited.clear();
	}
}
