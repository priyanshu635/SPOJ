/*
Consider a table with 2 rows and 2N columns (a total of 4N cells). Each cell of the first row is coloured by one of the colours A, B, C, D such that there are no two adjacent cells of the same colour. You have to colour the second row using colours A, B, C, D such that:

• There are exactly N cells of each colour (A, B, C and D) in the table.

• There are no two adjacent cells of the same colour. (Adjacent cells share a vertical or a horizontal side.)

It is guaranteed that the solution, not necessarily unique, will always exist.

Input

[a natural number N ≤ 50000]

[a string of 2N letters from the set {A, B, C, D}, representing the first row of the table]

Output

[a string of 2N letters from the set {A, B, C, D}, representing the second row of the table]

Example

Input

1

CB

Output

AD

 

Input

2

ABAD 

Output

BCDC
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

bool aflag,bflag,cflag,dflag;

int main()
{
	int i,n,j;
	char lastchar='0';
	char ans[2];
	cin>>n;

	char *str=(char *)malloc(sizeof(char) * 2*n);

	cin>>str;
	
	for(i=0;i<2*n;i=i+2)
	{
		aflag=true,bflag=true,cflag=true,dflag=true;
		j=0;
		
		if(str[i]=='A' || str[i+1]=='A')
			aflag=false;
		if(str[i]=='B' || str[i+1]=='B')
			bflag=false;
		if(str[i]=='C' || str[i+1]=='C')
			cflag=false;
		if(str[i]=='D' || str[i+1]=='D')
			dflag=false;


		if(aflag)
			{
			ans[j]='A';j++;
			}
		if(bflag)
			{
			ans[j]='B';j++;
			}
		if(cflag)
			{
			ans[j]='C';j++;
			}
		if(dflag)
			{
			ans[j]='D';j++;
			}

		if(ans[0]==lastchar)
		{
			cout<<ans[1]<<ans[0];
			lastchar=ans[0];
		}
		else
		{
			cout<<ans[0]<<ans[1];
			lastchar=ans[1];
		}

	}	

	cout<<"\n";
	return 0;
}
