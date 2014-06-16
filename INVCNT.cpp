#include<iostream>

using namespace std;

long long int merge(long long int a[],long long  int lowi,long long  int mid,long long  int highi)
{
	long long int b[200000];
	long long int i,j,k;
	long long int count=0;

	for(i=lowi,j=mid+1,k=lowi; i<=mid && j<=highi;)
	{
		if(a[i]>a[j])
		{
			b[k]=a[j];
			k++;
			j++;
			count+=mid-i+1;
		}
		else 
		{	
			b[k]=a[i];
			i++;
			k++;
		}
	}

	if(i>mid)
	{
		while(j<=highi)			
		{
			b[k]=a[j];
			k++;
			j++;
		}

	}
	
	if(j>highi)
	{
		while(i<=mid)
		{
			b[k]=a[i];
			k++;
			i++;
		}
	}

	
	for(k=lowi;k<=highi;k++)
		a[k]=b[k];

	return count;
}

long long int specialPair(long long int a[],long long int lowi,long long int highi)
{
	long long int left=0,right=0,mid,count=0;

	if(lowi<highi)
	{
		mid= (lowi+highi)/2;
		left=specialPair(a,lowi,mid);
		right=specialPair(a,mid+1,highi);
		count=merge(a,lowi,mid,highi);
	}

	return left+right+count;
}

int main()
{

long long int tc,i,j,n;
long long int a[200000];

cin>>tc;

for(i=0;i<tc;i++)
{
	cin>>n;
	for(j=0;j<n;j++)
		cin>>a[j];

	cout<<specialPair(a,0,n-1)<<"\n";
}

return 0;
}
