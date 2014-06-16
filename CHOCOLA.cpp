#include<iostream>
#include<stdlib.h>

using namespace std;

void quickSort(int a[],int first,int last)
{
	int pivot,j,temp,i;	
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
	int testcases,i,j,n,m,cost,mcount,ncount;
	cin>>testcases;
	while(testcases--)
	{
		cost=0;
		ncount=1;
		mcount=1;

		cin>>m>>n;
		int *ma=(int *)malloc(sizeof(int)*(m-1));
		int *na=(int *)malloc(sizeof(int)*(n-1));
		for(i=0;i<m-1;i++)
			cin>>ma[i];
		for(i=0;i<n-1;i++)
			cin>>na[i];

		quickSort(ma,0,m-2);
		quickSort(na,0,n-2);

		/*for(i=0;i<m-1;i++)
			cout<<ma[i]<<" ";
		cout<<"\n";
		for(i=0;i<n-1;i++)
			cout<<na[i]<<" ";
		cout<<"\n";
		

		bool *mflag=(bool *)malloc(sizeof(bool)*(m-1));
		bool *nflag=(bool *)malloc(sizeof(bool)*(n-1));

		for(i=0;i<m-1;i++)
			mflag[i]=false;
		for(i=0;i<n-1;i++)
			nflag[i]=false;
		*/

		for(i=0,j=0;i<m-1 && j<n-1;)
		{
			if(ma[i]>na[j])
			{
			cost+=ma[i]*ncount;
			mcount++;
			i++;
			}
			else
			{
			cost+=na[j]*mcount;
			ncount++;
			j++;
			}
		}
		
		while(i<m-1)		
		{
		cost+=ma[i]*ncount;
		mcount++;
		i++;
		}
	
		while(j<n-1)
		{
		cost+=na[j]*mcount;
		ncount++;
		j++;
		}

		cout<<cost<<"\n";
	}
	return 0;
}
