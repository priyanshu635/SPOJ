#include<cstdio>
using namespace std;
int main()
{
	int test,x,y;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&x);
		scanf("%d",&y);

		if(x==y && y%2==0)
			printf("%d\n",2*x);
		else if(x==y && y%2==1)
			printf("%d\n",(x-1)*2+1);
		else if(x-2==y && y%2==0)
			printf("%d\n",y*2+2);
		else if(x-2==y && y%2!=0)
			printf("%d\n",y*2+1);
		else
			printf("No Number\n");
	}
	return 0;
}
