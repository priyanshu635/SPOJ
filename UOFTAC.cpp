#include<cstdio>
#include<iostream>

using namespace std;

char a[1001][1001];
int r,c,h,w,t;

void moveDown()
{
	if(r==h)
		return;

	if(a[r+1][c]=='S')
		return;

	if(a[r+1][c]=='D')
	{
		r=r+1;
		while(r<h && a[r+1][c]=='E')	
			r=r+1;		
	}
	else if(a[r+1][c]=='T')
	{
		t=t+1;
		a[r+1][c]='E';
		r=r+1;
		while(r<h && a[r+1][c]=='E')	
			r=r+1;		
	}
}

void moveRight()
{
	if(c+1==w)
		return;

	if(a[r][c+1]=='S')
		return;

	if(a[r][c+1]=='_')
	{
		c=c+1;
		while(r<h && a[r+1][c]=='E')	
			r=r+1;		
	}
	else if(a[r][c+1]=='D')
	{
		c=c+1;
		while(r<h && a[r+1][c]=='E')	
			r=r+1;		
	}
	else if(a[r][c+1]=='T')
	{
		t=t+1;
		a[r][c+1]='E';
		c=c+1;
		while(r<h && a[r+1][c]=='E')	
			r=r+1;		
	}
	else if(a[r][c+1]=='E')
	{
		c=c+1;
		while(r<h && a[r+1][c]=='E')	
			r=r+1;		
	}
}

void moveLeft()
{
	if(c==0)
		return;

	if(a[r][c-1]=='S')
		return;

	if(a[r][c-1]=='_')
	{
		c=c-1;
		while(r<h && a[r+1][c]=='E')	
			r=r+1;		
	}
	else if(a[r][c-1]=='D')
	{
		c=c-1;
		while(r<h && a[r+1][c]=='E')	
			r=r+1;		
	}
	else if(a[r][c-1]=='T')
	{
		t=t+1;
		a[r][c-1]='E';
		c=c-1;
		while(r<h && a[r+1][c]=='E')
			r=r+1;		
	}
	else if(a[r][c-1]=='E')
	{
		c=c-1;
		while(r<h && a[r+1][c]=='E')
			r=r+1;
	}
}


int main()
{
	int test,n,i;
	char move;
	//scanf("%d",&test);
	cin>>test;
	while(test--)
	{
		//scanf("%d %d %d",&h,&w,&n);
		cin>>h>>w>>n;
		r=0;c=0;
		t=0;

		for(i=0;i<w;i++)
			a[0][i]='_';

		a[0][i]='\0';

		for(i=1;i<=h;i++)
			cin>>a[i];
			//scanf("%s",a[i]);

		for(i=0;i<n;i++)
		{
			//scanf("%s",&move);
			cin>>move;
			switch(move)
			{
				case 'R' : moveRight();
						break;
				case 'D' : moveDown();
						break;
				case 'L' : moveLeft();
						break;
			}

		}

		cout<<t<<"\n";
		//printf("%d\n",t);
	}
	return 0;
}
