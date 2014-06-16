#include<iostream>
#include<cstdio>

using namespace std;

int reverse(int input)
{
	int i,no=0;
	while(input!=0)
	{
		i=input%10;
		no=no*10+i;
		input=input/10;
	}
	return no;
}

int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%d %d",&a,&b);
		printf("%d\n",reverse(reverse(a)+reverse(b)));
	}
}


