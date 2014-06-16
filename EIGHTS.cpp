#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;
int main()
{
	unsigned long long int k,test,temp,aux;
	scanf("%lld",&test);
	while(test--)
	{
		scanf("%lld",&k);
		temp=(k-1)/4;
		aux=k%4;
		if(aux==1)
			aux=192;
		else if(aux==2)
			aux=442;
		else if(aux==3)
			aux=692;
		else
			aux=942;
		if(temp!=0)
			printf("%lld%lld\n",temp,aux);	
		else
			printf("%lld\n",aux);	
	}
	return 0;
}
