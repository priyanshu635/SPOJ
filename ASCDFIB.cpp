/*
John is trying to learn the Fibonacci sequence. This is what he has learned so far. The first two terms of the sequence are f(1) = 0 and f(2) = 1.  The next term f(n) is then calculated by adding the previous two terms f(n-1) and f(n-2). Therefore,

f(1) = 0

f(2) = 1

f(3) = f(2) + f(1) = 1 + 0 = 1

f(4) = f(3) + f(2) = 1 + 1 = 2

f(5) = f(4) + f(3) = 2 + 1 = 3

f(6) = f(5) + f(4) = 3 + 2 = 5

After calculating this for a while, John realized that the values are becoming too big. In order to keep the values small, John changed his algorithm. Instead of calculating f(n) = f(n-1)+f(n-2), he decided he will calculate f(n) = ( f(n-1)+f(n-2) ) % 10^5.

Now John wants to do some research on his new modified Fibonacci sequence. He will give you an integer A (A<=10^5) and an integer B (B<=10^6). You have to output all the terms from f(A) to f(A+B) in ascending order (non-decreasing order). But printing so many numbers is too much of a hassle. So, if there are more than 100 terms in the output, then only print the first 100.

Input

The first line contains an integer T (T<=100), which is the number of test cases. 
Each test case contains two positive integers A and B as mentioned before.

Output

For each test case, print case number (Check sample output) and then print the terms from f(A)  to f(A+B) in ascending order (non-decreasing order). If there are more than 100 terms in the output, then only print the first 100.

Example

Input:
3
1 3
3 3
100 1

Output:

Case 1: 0 1 1 2
Case 2: 1 2 3 5
Case 3: 15075 69026
*/

#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int matrix[1100001];

int getVal(int n)
{
	if(matrix[n]!=-1)
		return matrix[n];

	int a[2][2]={{1,1},{1,0}};
	int answer[2][2]={{1,1},{1,0}};
	int w,x,y,z,tempn=n;

	n--;
	while(n>0)
	{	
		if(n%2!=0)
		{
			w=(((long long)answer[0][0]*(long long)a[0][0])%100000+((long long)answer[0][1]*(long long)a[1][0])%100000)%100000;
			x=(((long long)answer[0][0]*(long long)a[0][1])%100000+((long long)answer[0][1]*(long long)a[1][1])%100000)%100000;
			y=(((long long)answer[1][0]*(long long)a[0][0])%100000+((long long)answer[1][1]*(long long)a[1][0])%100000)%100000;
			z=(((long long)answer[1][0]*(long long)a[0][1])%100000+((long long)answer[1][1]*(long long)a[1][1])%100000)%100000;
			answer[0][0]=w;
			answer[0][1]=x;
			answer[1][0]=y;
			answer[1][1]=z;
		}

	w=(((long long)a[0][0]*(long long)a[0][0])%100000+((long long)a[0][1]*(long long)a[1][0])%100000)%100000;
	x=(((long long)a[0][0]*(long long)a[0][1])%100000+((long long)a[0][1]*(long long)a[1][1])%100000)%100000;
	y=(((long long)a[1][0]*(long long)a[0][0])%100000+((long long)a[1][1]*(long long)a[1][0])%100000)%100000;
	z=(((long long)a[1][0]*(long long)a[0][1])%100000+((long long)a[1][1]*(long long)a[1][1])%100000)%100000;	
	a[0][0]=w;
	a[0][1]=x;
	a[1][0]=y;
	a[1][1]=z;

	n=n/2;
	}

	matrix[tempn]=answer[0][1];

	return matrix[tempn];
}


int main()
{
	int test,t,a,b,i,j,k,swap;
	int first,second,third;

	for(i=0;i<1100000;i++)
		matrix[i]=-1;
	matrix[0]=0;
	matrix[1]=1;
	matrix[2]=1;

	cin>>test;
	for(t=0;t<test;t++)
	{
		cin>>a>>b;
		a--;
		int *temp=(int *)malloc((sizeof(int))*(b+2));
		int count=0;		
		
		for(i=a;i<=a+b;i++)
			temp[i-a]=getVal(i);

		partial_sort(temp, temp+100, temp+b+1);

		cout<<"Case "<<t+1<<": ";
		for(i=0,k=0;i<b+1 && k<100;i++,k++)
			cout<<temp[i]<<" ";
		cout<<"\n";

	}	
	return 0;
}
