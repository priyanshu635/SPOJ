#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;

int a[8][8];

int main()
{
	char s1[8],s2[8];
	int l1,l2,i,j;

	scanf("%s",s1);
	scanf("%s",s2);

	l1=strlen(s1);
	l2=strlen(s2);

	for(i=1;i<=l1;i++)
	{
		for(j=1;j<=l2;j++)
		{
			if(s1[i-1]==s2[j-1])
				a[i][j]=a[i-1][j-1]+1;	
			else
				a[i][j]=max(a[i-1][j],a[i][j-1]);
		}
	}

	printf("%d\n",a[l1][l2]);
	return 0;
}
