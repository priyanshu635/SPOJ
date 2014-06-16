#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
	char a[1001];
	int i,fSmall,fCap;
	while(1)
	{
		if(scanf("%s",a)==EOF)
			break;

		fSmall=0;fCap=0;
		for(i=0;a[i]!='\0';i++)
		{
			if(i%2==0)
			{
				if(a[i]>=65 && a[i]<=90)
					fSmall++;	
				else
					fCap++;
			}
			else if(i%2!=0)
			{
				if(a[i]>=65 && a[i]<=90)
					fCap++;
				else	
					fSmall++;
			}
		}
		printf("%d\n",min(fCap,fSmall));
	}
	return 0;
}
