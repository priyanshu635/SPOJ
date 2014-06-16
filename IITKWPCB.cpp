#include<cstdio>

long long int gcd_slow(long long int num1, long long int num2)
{
	while(num1!=num2)
	{
		if(num1>num2)
			num1-=num2;
		else
			num2-=num1;
	}
	return num1;
}

long long gcd(long long a,long long b) {
	if(b==0)
		return a;
	if(a==b)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int test;
	long long n,i,half,count;
	bool prime;
	scanf("%d",&test);

	while(test--)
	{

		scanf("%lld",&n);
		for(long long i=n/2; i>0; i--) {
			if(gcd(n,i)==1) {
				printf("%lld\n",i);
				break;
			}
		}

		/*scanf("%lld",&n);

		half=n/2;
		while(half>1)
		{
			count=0;
			for(i=2;i*i<=half;i++)
			{
				if(half%i==0)
				{
					count++;
					if(n%i==0)
						break;
				}
			}	

			if(count==0 && n%half!=0)
				break;

			if(i*i>half && count>0)
				break;

			half--;
		}
		printf("%lld\n",half);
		*/
	}
	return 0;
}
