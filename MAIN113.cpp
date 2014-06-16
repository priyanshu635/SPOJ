#include<cstdio>
#include<map>
#include<vector>

using namespace std;

long long int a[29][9];				// 0-2	1-3....	28-30

map<int, vector<int> > mapping;

void fillMapping()
{
	int i=0;
	vector<int> v;

	//0
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	mapping.insert(pair<int, vector<int> >(i,v));
	i++;
	v.clear();

	//1
	v.push_back(3);
	v.push_back(4);
	mapping.insert(pair<int, vector<int> >(i,v));
	i++;
	v.clear();

	//2
	v.push_back(6);
	v.push_back(8);
	mapping.insert(pair<int, vector<int> >(i,v));
	i++;
	v.clear();

	//3
	v.push_back(0);
	v.push_back(1);
	mapping.insert(pair<int, vector<int> >(i,v));
	i++;
	v.clear();
	
	//4
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	mapping.insert(pair<int, vector<int> >(i,v));
	i++;
	v.clear();
	
	//5
	v.push_back(7);
	v.push_back(8);
	mapping.insert(pair<int, vector<int> >(i,v));
	i++;
	v.clear();

	//6
	v.push_back(0);
	v.push_back(2);
	mapping.insert(pair<int, vector<int> >(i,v));
	i++;
	v.clear();

	//7
	v.push_back(4);
	v.push_back(5);
	mapping.insert(pair<int, vector<int> >(i,v));
	i++;
	v.clear();

	//8
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	mapping.insert(pair<int, vector<int> >(i,v));
}

int main()
{
	int n,test,i,j;
	long long int result;
	vector<int> aux;

	fillMapping();

	


	for(i=0;i<9;i++)
		a[0][i]=1;

	for(i=1;i<=28;i++)
	{
		for(j=0;j<9;j++)
		{
			aux=mapping[j];
			for(vector<int>::iterator it=aux.begin();it!=aux.end();it++)
			{
				a[i][*it]+=a[i-1][j];
			}
		}
	}
	

	/*for(i=0;i<29;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%lld ",a[i][j]);
		}
		printf("\n");
	}
	*/

	scanf("%d",&test);	
	while(test--)
	{
		scanf("%d",&n);
		if(n==1)
			printf("3\n");
		else
		{	
			result=0;
			for(i=0;i<9;i++)			
				result+=a[n-2][i];
			printf("%lld\n",result);
		}
	}
	
	return 0;
}
