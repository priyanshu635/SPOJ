#include<cstdio>
#include<stack>

using namespace std;

int priority(char ch)
{
	
	
	switch(ch)
	{
		case '+':	return 5;
		case '-':	return 4;
		case '*':	return 3;
		case '/':	return 2;
		case '^':	return 1;
		default	:	return 6;
	}
}

void infixToPostfix(char *input,char *output)
{
	stack<char> s;
	int i,oc=0;
	for(i=0;input[i]!='\0';i++)
	{
		if(input[i]>='a' && input[i]<='z')
		{
			output[oc++]=input[i];
			continue;
		}

		if(input[i]=='(')
		{
			s.push(input[i]);
			continue;
		}	

		if(input[i]==')')
		{
			while(s.top()!='(')
			{
				output[oc++]=s.top();
				s.pop();
			}

			s.pop();	//to remove (
			continue;
		}

		
		// it means is an operator
		if(s.empty())
		{
			s.push(input[i]);
		}
		else
		{
			while(s.top()!='(' && priority(s.top())>=priority(input[i]))
			{
				output[oc++]=s.top();
				s.pop();
			}	
			s.push(input[i]);
		}
	}

	while(!s.empty())
	{
		output[oc++]=s.top();
		s.pop();
	}


	output[oc]='\0';
}

int main()
{
	int test;	
	char input[400];
	char output[400];
	scanf("%d",&test);	
	while(test--)
	{
		scanf("%s",input);
		infixToPostfix(input,output);	
		printf("%s\n",output);
	}
	return 0;
}
