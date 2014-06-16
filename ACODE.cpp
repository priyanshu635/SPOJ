#include<iostream>
#include<cstring>

using namespace std;

long long int decode(char s[])
{
	long long int i,n1,n2,len=strlen(s);
	long long int count=0;
	long long int last=1;
	long long int slast=1;
	int zero=0;		

	if(s[len-1]=='0')
	{	
		//s[len-1]='\0';
		//len--;
		zero=2;
	}

	if(len==1)
		return 1;

	for(i=len-2;i>=0;i--)
	{
		n1=s[i]-48;
		n2=s[i+1]-48;
	
		//if(n2==0 && i==len-2)
		//	{
		//		if(len==2)		
		//			count=1;
		//	zero=2;
		//	continue;
		//	}

		if(n1==0)	
			{
			zero=2;
			continue;
			}

		if(zero>0 || (n1>2) || (n1==2 && n2>6))
			{
				count=last;
				slast=last;
				if(zero>0)
					zero--;
			}
		else
			{
			count=last+slast;
			slast=last;
			last=count;
			}
		
	}
	return count;
}

int main()
{
	char s[5001];
	cin>>s;
	while(s[0]!='0')
	{
	cout<<decode(s)<<"\n";
	cin>>s;
	}
	return 0;
}
