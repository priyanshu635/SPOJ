#include<cstdio>

using namespace std;

int main()
{
	int test,n,result=0;
	scanf("%d",&test);	
	while(test--)
	{
		scanf("%d",&n);
		result=result^n;
	}
	printf("%d\n",result);
	return 0;
}
