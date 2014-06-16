#include<cstdio>

using namespace std;

const int size=20;

int CalLCM(char a[])
{
	int i,count,j,result=1;
	int inta[size];
	bool done;
	
	for(i=0,count=0;a[i]!='\0';i++)
	{	
		if(a[i]=='Y')
		{
			inta[count]=i+1;
			count++;
		}
	}

	for(i=2;i<=20;)
	{
		done=false;
		for(j=0;j<count;j++)
		{
			if(inta[j]%i==0)
			{
				inta[j]=inta[j]/i;
				done=true;	
			}
		}
		if(!done)	
			i++;
		else
			result=result*i;
	}
	return result;
}

int main()
{
	char a[size];	
	int lcm;
	bool print;
	scanf("%s",a);
	while(a[0]!='*')
	{
		print=false;
		lcm=CalLCM(a);
		for(int i=0;a[i]!='\0';i++)
		{
			if(a[i]=='N' && lcm%(i+1)==0)
			{
				printf("-1\n");
				print=true;
				break;
			}
		}
		
		if(!print)
			printf("%d\n",lcm);
	
		scanf("%s",a);
	}
	return 0;
}
