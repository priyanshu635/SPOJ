/*
Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.

 

The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.

 

This position has a penalty of 12.

 

Help Theodore write a program that calculates the penalty of the given position.

 

 

Input

 

The first line of the input file contains the number of test cases.

 

Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).

 

Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).

 

 

Output

 

For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.

 

 

Example

Input:
1
15 8 3
3 8
11 2
8 6

Output:
12
*/

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
			while(i<last && a[pivot]>=a[i])
				i++;
			while(j>first && a[pivot]<=a[j])
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
int test;	
cin>>test;

int x,y,n,i,j;
while(test--)
{
	cin>>x>>y>>n;
	
	int *xcord=(int *)malloc(sizeof(int)*(n+2));
	int *ycord=(int *)malloc(sizeof(int)*(n+2));

	for(i=0;i<n;i++)
		cin>>xcord[i]>>ycord[i];

	xcord[n]=0;
	ycord[n]=0;
	xcord[n+1]=x+1;
	ycord[n+1]=y+1;

	quickSort(xcord,0,n+1);
	quickSort(ycord,0,n+1);

	int max=0,sum,opt=-1;
	for(j=0;j<n+1;j++)		//y-cord
	{
		
		if(ycord[j+1]-ycord[j]-1<=opt)	//for optimization purpose
			continue;

		opt=(ycord[j+1]-ycord[j]-1);

		for(i=0;i<n+1;i++)	//x-cord
		{
			sum=(xcord[i+1]-xcord[i]-1)*(ycord[j+1]-ycord[j]-1);
			if(sum>max)
				max=sum;
		}
	}

	cout<<max<<"\n";
}
return 0;
}
