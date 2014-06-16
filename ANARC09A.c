#include<stdio.h>
#include<stdlib.h>
int main()
{
char a[2000];
int count,i,t=1,j;
scanf("%s",a);
while(a[0]!='-')
	{
	count=0;j=0;

	for(i=0;a[i]!='\0';i++)
		{

		if(a[i]=='{')
			{count++;continue;}

		if(a[i]=='}' && count==0)
		{
			count=1;
			j++;	
			continue;
		}

		if(a[i]=='}')
			{count--;continue;}

		if(a[i]==' '){continue;}
		

		}

	printf("%d. %d\n",t,(abs(count/2))+j);
	t++;
	scanf("%s",a);
	}
return 0;
}
