/*
Pappu was doing the work of his math class about three days but he is tired of make operations a lot and he should deliver his task tomorrow. His math’s teacher gives two numbers a and b. The problem consist in find the last digit of the potency of base a and index b. Help Pappu with his problem. You are given two integer numbers: the base a (number of digits d, such that 1<=d<=1000) and the index b (0 <= b <= 922*10^15). You
have to find the last digit of a^b.

                                                         Input
The first line of input contains an integer t, the number of test cases (t <= 30). t test cases follow. For
each test case will appear a and b separated by space.

                                                         Output
For each test case output an integer per line representing the result.

Example
Input:
3
3 10
6 2
150 53
Output:
9
6
0
*/

#include<iostream>

using namespace std;


int power(int a,unsigned long long int b)
{
	if(b==0)
		return 1;

	if(a==0)
		return 0;

	int answer=a;
	b--;
	while(b>0)
	{
	if(b%2!=0)
		answer=(answer*a)%10;
	a=(a*a)%10;
	b=b/2;
	}
	
	return answer%10;
}

int main()
{
	unsigned long long int b;
	int t,i,a,j;
	char s[1000];
	cin>>t;
	for(i=0;i<t;i++)
	{
	cin>>s>>b;
	for(j=0;s[j]!='\0';j++);		
	a=s[j-1]-'0';		
	cout<<power(a,b)<<"\n";
	}
	return 0;
}
