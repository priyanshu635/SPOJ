#include<cstdio>
#include<map>
#include<set>

using namespace std;

int a[100000];	
int aux[100000];

int main()
{
	int n,i,j,max,leng;
	for(int t=0;t<10;t++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
	
		map<int,int> mapping;
		set<int> s;
		
		aux[0]=1;
		leng=0;
		for(i=1;i<n;i++)
		{
			max=0;
			for(j=i-1;j>=0;j--)
				if(a[i]>a[j] && aux[j]>max)
					max=aux[j];
			aux[i]=max+1;
			if(aux[i]>leng)
				leng=aux[i];
		}

		for(i=n-1;i>=0;i--)
		{
			if(aux[i]==leng)
			{
				mapping.insert(pair<int,int>(aux[i],a[i]));
				s.insert(a[i]);
			}
			else if(mapping.count(aux[i]+1)>0 && a[i]<mapping[aux[i]+1])
			{
				s.insert(a[i]);
				mapping.insert(pair<int,int>(aux[i],a[i]));
			}
		}

		printf("%d\n",s.size());
		for(set<int>::iterator it=s.begin();it!=s.end();it++)
			printf("%d ",*it);
		printf("\n");
	}
	return 0;
}
