#include<cstdio>
#include<algorithm>

using namespace std;

struct node 
{	
	int h;
	int b;
	int l;
}type[90];

int h[90];

bool sortFunct(node n1, node n2)
{
	return n1.b*n1.l>n2.b*n2.l;
}


int main()
{
	int n,p,q,r,max,i,j,maxheight;
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&p,&q,&r);
			
			//first box
			type[i*3+0].h=p;
			if(q>r)
			{
				type[i*3+0].b=q;
				type[i*3+0].l=r;
			}
			else 
			{		
				type[i*3+0].b=r;
				type[i*3+0].l=q;
			}

			//second box
			type[i*3+1].h=q;
			if(p>r)
			{
				type[i*3+1].b=p;
				type[i*3+1].l=r;
			}	
			else 
			{
				type[i*3+1].b=r;
				type[i*3+1].l=p;
			}

			//third box
			type[i*3+2].h=r;
			if(p>q)
			{
				type[i*3+2].b=p;
				type[i*3+2].l=q;
			}
			else 
			{
				type[i*3+2].b=q;
				type[i*3+2].l=p;
			}
		}
		
		/*for(i=0;i<n;i++)
		{
			printf("%d %d %d\n",type[i*3+0].h,type[i*3+0].l,type[i*3+0].b);
			printf("%d %d %d\n",type[i*3+1].h,type[i*3+1].l,type[i*3+1].b);
			printf("%d %d %d\n",type[i*3+2].h,type[i*3+2].l,type[i*3+2].b);
		}*/

		sort(type,type+3*n,sortFunct);
	
		/*for(i=0;i<n;i++)
		{
			printf("%d %d %d\n",type[i*3+0].h,type[i*3+0].l,type[i*3+0].b);
			printf("%d %d %d\n",type[i*3+1].h,type[i*3+1].l,type[i*3+1].b);
			printf("%d %d %d\n",type[i*3+2].h,type[i*3+2].l,type[i*3+2].b);
		}*/

		h[0]=type[0].h;
		maxheight=h[0];
		for(i=1;i<n*3;i++)
		{
			max=0;
			for(j=i-1;j>=0;j--)
			{
				if(type[j].l>type[i].l && type[j].b>type[i].b && h[j]>max)
					max=h[j];
			}
			h[i]=max+type[i].h;
			if(h[i]>maxheight)
				maxheight=h[i];
		}
		
		printf("%d\n",maxheight);
		scanf("%d",&n);
	}
	return 0;
}

