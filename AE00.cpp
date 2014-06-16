#include<iostream>
#include<cstdio>

using namespace std;

int factor(int n)
{
	int count=0,i;
	for(i=1;i*i<=n;i++)
		if(n%i==0)
			count++;
	return count;
}

int main()
{
	int n,count=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		count+=factor(i);
	printf("%d\n",count);
}


