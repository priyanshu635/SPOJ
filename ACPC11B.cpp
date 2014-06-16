#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <cstdio>
#include <climits>

using namespace std;

int main () {
	
	int t,n1,n2,i,j,max;
	
	scanf("%d",&t);
	while(t--)
	{
		max=INT_MAX;
		scanf("%d",&n1);
		int *a1=(int *)malloc(sizeof(int)*n1);
		for(i=0;i<n1;i++)
			scanf("%d",&a1[i]);

		scanf("%d",&n2);
		int *a2=(int *)malloc(sizeof(int)*n2);
		for(i=0;i<n2;i++)
			scanf("%d",&a2[i]);
		
/*		cout<<"input array\n";
		for(i=0;i<n1;i++)
			cout<<a1[i]<<" ";
		cout<<"\n";

		for(i=0;i<n2;i++)
			cout<<a2[i]<<" ";
		cout<<"\n";
*/
		vector<int> v1 (a1, a1+n1);
		vector<int> v2 (a2, a2+n2);

/*		cout<<"before sort\n";
		for(i=0;i<v1.size();i++)
			cout<<v1.at(i)<<" ";
		cout<<"\n";

		for(i=0;i<v2.size();i++)
			cout<<v2.at(i)<<" ";
		cout<<"\n";
*/
		sort (v1.begin(), v1.end());         		
		sort (v2.begin(), v2.end());         

/*		cout<<"after sort\n";
		for(i=0;i<v1.size();i++)
			cout<<v1.at(i)<<" ";
		cout<<"\n";

		for(i=0;i<v2.size();i++)
			cout<<v2.at(i)<<" ";
		cout<<"\n";
*/
		for(i=0,j=0;i<n1&&j<n2;)
		{
			if(v1.at(i)<v2.at(j))
			{
				if(max>v2.at(j)-v1.at(i))
					max=v2.at(j)-v1.at(i);
				i++;
			}
			else if(v1.at(i)>v2.at(j))
			{
				if(max>v1.at(i)-v2.at(j))
					max=v1.at(i)-v2.at(j);
				j++;
			}
			else
			{
				max=0;
				break;
			}
		}
		printf("%d\n",max);

	}

 return 0;
}
