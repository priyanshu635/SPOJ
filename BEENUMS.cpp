#include<cstdio>

using namespace std;

int a[100000];

bool binarySearch(int l,int u,int m)
{
	int c=0,mid;
	while(l<=u)
	{
	        mid=(l+u)/2;
		if(m==a[mid])
		{
 			c=1;
			break;
         	}
         	else if(m<a[mid])
            		u=mid-1;
         	else
             		l=mid+1;
    	}
	return c;
}

int main()
{
	int i,count=1,n;	
	a[0]=count;
	for(i=1;;i++)
	{
		count=3*i*i+3*i+1;
		if(count>1000000000)
			break;
		a[i]=count;
	}
	//0 to i-1
	
	scanf("%d",&n);
	while(n!=-1)
	{
		if(binarySearch(0,i-1,n))
			printf("Y\n");
		else
			printf("N\n");
		scanf("%d",&n);
	}
	
	return 0;
}
