#include<cstdio>
#include<deque>
#include<algorithm>

using namespace std;

bool minHeap(int a,int b)
{
	return a>b;
}

int main()
{
	int n,t,minsize=0,maxsize=0;	
	deque<int> min,max;

/*	min.push_back(25);
	min.push_back(15);
	min.push_back(5);
	min.push_back(45);

	max.push_back(25);
	max.push_back(15);
	max.push_back(5);
	max.push_back(45);

	printf("%d %d\n",min.front(),max.front());
	
*/

	make_heap(min.begin(),min.end());		//this is max heap by default
	make_heap(max.begin(),max.end(),minHeap);	//this is min heap

//	printf("%d %d\n",min.front(),max.front());

	scanf("%d",&t);
	while(t--)
	{
		while(1)
		{
			scanf("%d",&n);
			if(n==0)
			{
				min.clear();
				max.clear();
				minsize=0;
				maxsize=0;
				break;
			}

			if(n==-1)
			{
				printf("%d\n",min.front());
				pop_heap (min.begin(),min.end());
				min.pop_back();
				minsize--;
				if(maxsize>minsize)
				{
					min.push_back(max.front());
					push_heap (min.begin(),min.end());
					minsize++;
					pop_heap(max.begin(),max.end(),minHeap);
					max.pop_back();
					maxsize--;
				}	
			}
			else
			{
				if(n<max.front())
				{
					min.push_back(n);
					push_heap(min.begin(),min.end());
					//printf("aabra:%d\n",min.front());					
					minsize++;
					if(minsize>maxsize+1)
					{
						/*printf("tx\n");
	
						deque<int>::iterator itm = max.begin();

						while (itm != max.end())
							printf("-%d-",*itm++);
						printf("\n");
*/
						//transfer one element from min to max
						max.push_back(min.front());
						push_heap(max.begin(),max.end(),minHeap);
						maxsize++;
						pop_heap(min.begin(),min.end());
						min.pop_back();
						minsize--;
						/*deque<int>::iterator it2 = max.begin();

						while (it2 != max.end())
							printf("-%d-",*it2++);
						printf("\n");
*/
						//printf("before:%d\n",min.front());
						//printf("bf size:%d\n",min.size());

						/*deque<int>::iterator it = min.begin();

						while (it != min.end())
							printf("-%d-",*it++);
						printf("\n");
*/
						
						//make_heap(min.begin(),min.end());				

						/*deque<int>::iterator it1 = min.begin();
						while (it1 != min.end())
							printf("-%d-",*it1++);
						printf("\n");
						printf("after:%d\n",min.front());
						*/
						//printf("af size:%d\n",min.size());
						
					}
				}
				else
				{
					max.push_back(n);
					push_heap(max.begin(),max.end(),minHeap);
					maxsize++;
					if(maxsize>minsize)
					{
						min.push_back(max.front());
						push_heap (min.begin(),min.end());
						minsize++;
						pop_heap(max.begin(),max.end(),minHeap);
						max.pop_back();
						maxsize--;
					}		
				}
			//	printf("after n:%d\n",n);
			//	printf("minF:%d\n",min.front());
			//	printf("maxF:%d\n\n",max.front());
			}
		}
	}
	return 0;
}
