#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	while(1)
	{
		if(a==0 && b==0 && c==0)
			break;
		if(b-a==c-b)
			printf("AP %d\n",c+c-b);
		else
			printf("GP %d\n",c*(b/a));
		scanf("%d%d%d",&a,&b,&c);
	}
}

