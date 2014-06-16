/*
Breadtree is a kind of tree that produces bread. At its first year, a breadtree is only a node with a bread of weight 0 on this node which is also called zeronode. Every year after that, the weight of bread on each node of the tree will increase by 1, and another branch with a zeronode will grow at the end of each node. However, there is a limit of branches on each node. That is, when the number of branches of a node reaches the limit, there won't be any more branches, but the weight of its bread will still increase. What's more, a breadtree remains unchanged when the total weight of bread is larger than 1234567890.

Input

There are two integers N and K on each line. N is a positive integer fit in signed 32-bit integer. K is a non-negative integer fit in signed 32-bit integer. An N equals to 0 signals the end of input, which should not be processed.

Output

Output the total weight of bread on a breadtree with branches limit K in the N-th year in a line for each case.

Example

Input:
10000 0
101 1
10 2
1221 128
0 0


Output:
9999
5050
221
2147483647
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

int sumOfLastKElement(int *sum,int index,int k)
{
	int s=0;	

	while(index>=0 && k>0)
	{
		s+=sum[index];
		index--;
		k--;
	}

	return s;
}

int main()
{

int n,k,i,j;
unsigned long long cost;
bool flag;

while(true)
{
	cost=0;
	flag=false;
	cin>>n>>k;

	int *sum=(int *)malloc(sizeof(int) *n);

	if(n==0)
		break;

	sum[0]=1;
	cost=sum[0]*(n-1);
	
	int localsum,localn=n;

	for(i=1;i<n;i++)
	{
		/*if(flag)
		{
			cost+=localsum;
			continue;
		}
		*/

		localsum=sumOfLastKElement(sum,i-1,k);

		sum[i]=localsum;
		cost+=localsum*(n-1-i);
		if(cost>1234567890)
			break;
	}
	

	/*for(i=1;i<n;i++)
	{
		if(flag)
		{
			cost+=localsum;
			continue;
		}
		
		localsum=sumOfLastKElement(sum,i-1,k);

		if(((localsum)*(n-1-i)+cost)>1234567890)
		{
			flag=true;
			cost+=localsum;
			continue;
		}
		
		totalnode+=localsum;
		sum[i]=localsum;
		cost+=localsum*(n-1-i);
	}
	*/	
	cout<<cost<<"\n";
}
	return 0;
}
