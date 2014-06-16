/*
The Great Ball (5 points) Hogwarts has organized The Great Ball to welcome the schools participating in the Triwizard Tournament. The ball is being held in the Great Hall and The Weird Sisters have been called to play the band. The students drift in to dance and then go out when they get tired. Hagrid is stationed at the gate and is noting down the time at which people enter and leave the hall. At the end of the day, he wonders what the maximum number of dancers was during the course of the ball. For convenience, he writes down for each person entering, the number of minutes from the start of the ball at which the person entered and left. The door of the hall is narrow, so at any time, either one person can enter or one person can exit, but not both. For example, suppose the observations noted down by Hagrid are the following:
Serial No	Enters at	Leaves at
1	1	7
2	2	4
3	6	9
4	3	8
5	5	10
Each line denotes the entry time and exit time of one person. (The identity of the person is not important - the same person may enter and leave many times. For instance, in the example, it might well be that the entries and exits recorded at serial no. 2 & 5 refer to the same person). In this example, the maximum size of the dancers during the ball was 4. This was achieved between time 6 & 7. Hagrid is not good at Math so he requires your help. Your task is to read the list of entry and exit times and compute the maximum number of dancers during the ball.

Input

The first line is a single integer, T (1<=T<=100), which is the number of test cases. For each of the test case, the first line contains a single integer N, (1<=N<=100), the number of entries and exits recorded. This is followed by N lines. Each of these lines consists of two integers, separated by a space, describing the entry and exit time of that person. The entry and exit times are guaranteed to be distinct, and the entry time will be less than the exit time. The constraint on entry and exit times is 10000000.

Output

A total of T lines each of them containing a single integer, denoting the maximum number of dancers during the ball.

Example

Input:
1
5
1 7
2 4
6 9
3 8
5 10

Output:
4

*/

#include<iostream>

using namespace std;

void merge(int a[],int first,int mid, int last)
{
	int localfirst=first;
	int start=mid+1;
	int temp[100],i=0;

	while(first<=mid && start<=last)
	{	
		if(a[first]<a[start])
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

	for(int j=0;j<i;j++)
		a[localfirst+j]=temp[j];
}

void mergeSort(int a[],int first,int last)
{
	int mid;
	if(first<last)
	{
		mid=(first+last)/2;
		mergeSort(a,first,mid);
		mergeSort(a,mid+1,last);
		merge(a,first,mid,last);
	}
}


int main()
{
	
int testcases,t;

cin>>testcases;

for(t=0;t<testcases;t++)
{
	int entry[100],exit[100];
	int count=0,max=0,n,i,j;	
	
	cin>>n;
		
	for(i=0;i<n;i++)
		cin>>entry[i]>>exit[i];

	mergeSort(entry,0,n-1);
	mergeSort(exit,0,n-1);

	for(i=0,j=0; i<n && j<n ;)
	{
		if(entry[i]<exit[j])
		{
			count++;	
			i++;
		}
		else
		{
			count--;
			j++;
		}

		if(count>max)
			max=count;

	}

	cout<<max<<"\n";

	/*for(i=0;i<n;i++)
		cout<<entry[i]<<" ";

	for(i=0;i<n;i++)
		cout<<exit[i]<<" ";
	*/
}

return 0;
}
