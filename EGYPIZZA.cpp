#include<cstdio>
#include<cmath>

int main()
{
	int n,i,half=0,fourth=0,third=0,count=0,temp;
	char amount[3];
	
	scanf("%d",&n);	
	
	while(n--)
	{
		scanf("%s",amount);

		if(amount[0]=='1' && amount[2]=='2')
			half++;
		else if(amount[0]=='1' && amount[2]=='4')
			fourth++;
		else if(amount[0]=='3' && amount[2]=='4')
			third++;
	}

	count=third;
	fourth=fourth-third;
	if(half>0)
	{
		if(half%2==0)
			count=count+half/2;
		else
		{
			count=count+((half-1)/2)+1;
			fourth=fourth-2;
		}
	}

	if(fourth>0)
	{
		if(fourth%4==0)
			count+=fourth/4;
		else
			count+=(fourth/4)+1;;
	}

	printf("%d\n",count+1);

	return 0;
}
