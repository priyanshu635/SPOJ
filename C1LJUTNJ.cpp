/*
Children in a kindergarten have received a large sack containing M candies. It has been decided that the candies are to be distributed among N children.

Each child has stated the number of candies that it wants. If a child isn’t given the amount of candy it wants, it will get angry. In fact it’ll get angrier for each candy it is deprived of. Some speculate that it’s anger will be equal to the square of the number of candy it is deprived of. For instance, if Mirko states that he wants 32 candies but receives only 29, he would be missing 3 candies, so his anger would be equal to 9.

Unfortunately, there is an insufficient amount of candy to satisfy all children. Therefore, the candies should be distributed in such a way that the sum of the children’s anger is minimal.

Input

The first line contains two integers, M (1 ≤ M ≤ 2.10^9) and N (1 ≤ N ≤ 100 000).

The following N lines contain integers (one per line) which represent the wishes of the children. Those numbers are all strictly less than 2.10^9, and their sum always exceeds M.

Output

The first and only line of output must contain the minimum sum of the children’s anger.

Note: The test cases will ensure that the result fits in a 64-bit unsigned integer: int64 in Pascal, long long in C/C++, long in Java.

Example

Input:
5 3 
1 
3 
2
Output:
1

Input:
10 4
4
5
2
3

Output:
4
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

void merge(long long a[],long long first,long long mid,long long last)
{
	long long localfirst=first;
	long long start=mid+1;
	long long temp[100],i=0;

	while(first<=mid && start<=last)
	{	
		if(a[first]>a[start])
		{
			temp[i]=a[first];
			i++;
			first++;
		}
		else
		{
			temp[i]=a[start];
			i++;
			start++;
		}
	}

	while(first<=mid)
	{
		temp[i]=a[first];
		i++;
		first++;
	}

	while(start<=last)
	{
		temp[i]=a[start];
		start++;
		i++;
	}

	for(long long j=0;j<i;j++)
		a[localfirst+j]=temp[j];
}

void mergeSort(long long a[],long long first,long long last)
{
	long long mid;
	if(first<last)
	{
		mid=(first+last)/2;
		mergeSort(a,first,mid);
		mergeSort(a,mid+1,last);
		merge(a,first,mid,last);
	}
}


void quickSort(long long a[],long long first,long long last)
{
	long long pivot,j,temp,i;	
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
	
		while(i<j)	
		{
			while(i<last && a[pivot]<=a[i])
				i++;
			while(j>first && a[pivot]>=a[j])
				j--;
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	
		temp=a[pivot];	
		a[pivot]=a[j];
		a[j]=temp;

		quickSort(a,first,j-1);
		quickSort(a,j+1,last);
	}
}



int main()
{
	long long m,n,i,j,diff,ans=0,q,rem;
	cin>>m>>n;

	long long *a=(long long *)malloc(sizeof(long long)*n);
	//long long a[100000];

	for(i=0;i<n;i++)
		cin>>a[i];
	
	quickSort(a,0,n-1);

	//for(i=0;i<n;i++)
	//	cout<<a[i]<<"\n";

	for(i=0;i<n-1;i++)
	{
		diff=a[i]-a[i+1];
		if(diff*(i+1)<=m)
			m-=diff*(i+1);
		else
			break;
	}

	if(i<n-1)
	{
		for(j=i+1;j<n;j++)
			ans=ans+(a[j]*a[j]);	
	}
	
	q=m/(i+1);
	rem=m-q*(i+1);

	for(long long k=0;k<=i;k++)
	{
		if(rem>k)
			ans=ans+(a[i]-q-1)*(a[i]-q-1);
		else
			ans=ans+(a[i]-q)*(a[i]-q);	
	}

	free(a);

	cout<<ans<<"\n";
}
