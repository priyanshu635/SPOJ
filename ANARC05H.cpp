#include<cstdio>
#include<string.h>

using namespace std;

char a[26];

int subGroup(int start, int end, int sum, int limit)
{
	int localsum=0,i,count=0;

	for(i=start;i<end;i++)
	{
		localsum+=(a[i]-'0');
		sum=sum-(a[i]-'0');
		if(localsum>=limit && sum>=localsum)
			count+=subGroup(i+1,end,sum,localsum)+1;
	}
	return count;
}

int main()
{
	int sum,i,j,count=1;
	scanf("%s",a);
	while(a[0]!='b')
	{
		sum=0;
		for(i=0;a[i]!='\0';i++)
			sum+=a[i]-'0';

		printf("%d. %d\n",count++,subGroup(0,i-1,sum,0)+1);	//start index, end index, sum, limit=-1 (initially)
		scanf("%s",a);
	}
	return 0;
}
