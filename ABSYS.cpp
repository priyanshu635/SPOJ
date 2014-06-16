#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

int strToInt(char *a)
{
	int n=1,no=0,i=0;
	while(a[i]!='\0')
	{
		if(a[i]>='0' && a[i]<='9')
		{
			no=no*10+a[i]-48;
			i++;
		}
		else 
			return -1;
	}

	return no;
}

int main()
{
	int t,b[3],i;
	scanf("%d",&t);
	
	char a[100];
	char *token;
	gets(a);
	while(t--)
	{
		gets(a);
		gets(a);
		i=0;
		token = strtok (a,"+= ");
		while (token != NULL)
		{
			b[i]=strToInt(token);
			i++;
			token = strtok (NULL, "+= ");
		}

		if(b[0]==-1)
			printf("%d + %d = %d\n",b[2]-b[1],b[1],b[2]);
		else if(b[1]==-1)
			printf("%d + %d = %d\n",b[0],b[2]-b[0],b[2]);
		else if(b[2]==-1)
			printf("%d + %d = %d\n",b[0],b[1],b[0]+b[1]);
		else
			printf("%d + %d = %d\n",b[0],b[1],b[2]);
	}
}
