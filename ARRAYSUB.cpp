#include<cstdio>
#include<deque>

using namespace std;

int main()
{
	int n,a[1000000],k,i;
	deque<int> deq;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);

	for(i=0;i<k;i++)
	{
		while(!deq.empty() && a[deq.back()]<a[i])
			deq.pop_back();
		deq.push_back(i);
	}
	printf("%d ",a[deq.front()]);

	for(i=k;i<n;i++)
	{
		while(!deq.empty() && deq.front()<=i-k)
			deq.pop_front();
		
		while(!deq.empty() && a[deq.back()]<a[i])
			deq.pop_back();

		deq.push_back(i);

		printf("%d ",a[deq.front()]);
	}
	printf("\n");

	return 0;
}
