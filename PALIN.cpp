/*
A positive integer is called a palindrome if its representation in the decimal system is the same when read from left to right and from right to left. For a given positive integer K of not more than 1000000 digits, write the value of the smallest palindrome larger than K to output. Numbers are always displayed without leading zeros.

Input

The first line contains integer t, the number of test cases. Integers K are given in the next t lines.

Output

For each K, output the smallest palindrome larger than K.

Example

Input:
2
808
2133

Output:
818
2222
*/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
	int tc,i;
	cin>>tc;

	for(i=0;i<tc;i++)
	{
		string s;
		cin>>s;
		int  len=s.size();
		
		if(len%2==1)		//odd				
		{
			int j,k,l,r;
			int cl,cr;
			bool nine=false;

			if(s.at(len/2)=='9')
				nine=true;

			for(j=len/2-1,k=len/2+1;j>=0; j--,k++)
			{
				l=s.at(j)-48;
				r=s.at(k)-48;
				
				if(l==r  && l==9)
					continue;

				if(l==r)
					{
					nine=false;
					continue;
					}

				if(l<r)					//increment mid and then copy left to right
				{
					if(s.at(len/2)-48==9)		
					{	
						int index=len/2;
						while(s.at(index)-48==9)
						{
							s.at(index)='0';
							index--;
						}
						s.at(index)+=1;
						for(cl=len/2-1,cr=len/2+1;cl>=0;cl--,cr++)
							s.at(cr)=s.at(cl);
					}				
					else
					{
						s.at(len/2)+=1;
						for(cl=len/2-1,cr=len/2+1;cl>=0;cl--,cr++)
							s.at(cr)=s.at(cl);
					}
				
					break;
				}
		
				if(l>r)					//copy left to right
				{
					for(cl=len/2-1,cr=len/2+1;cl>=0;cl--,cr++)
							s.at(cr)=s.at(cl);
					break;
				}
		
				
			}
			if(j==-1)					//remaining testcases : 19991
			{
					if(nine)
					{
						s="1"+s;
					
						for(cl=1;cl<len;cl++)
							s.at(cl)='0';
						s.at(len)='1';
					}
					else if(nine==false && s.at(len/2)=='9')
					{
						int x,y;
						s.at(len/2)='0';
						x=len/2-1;
						y=len/2+1;
						while(s.at(x)=='9')
						{
							s.at(x)='0';
							s.at(y)='0';
							x--;
							y++;
						}
						s.at(x)+=1;
						s.at(y)+=1;
					}
					else
						s.at(len/2)+=1;
			}
		}
		else			//even				
		{
			int cl,cr,p,q;
			bool nine=false;
			const int m2=len/2;
			const int m1=m2-1;
			
			if(s.at(m1)!=s.at(m2))
			{
				if(s.at(m1)>s.at(m2))
					s.at(m2)=s.at(m1);
					
				if(s.at(m2)>s.at(m1))
					{
						s.at(m1)+=1;
						s.at(m2)=s.at(m1);
					}

				for(cl=m1-1,cr=m2+1;cl>=0;cl--,cr++)
					s.at(cr)=s.at(cl);
				
			}
			else
			{	
				if(s.at(m1)=='9')
					nine=true;
							
				for(cl=m1-1,cr=m2+1;cl>=0;cl--,cr++)
					{
						if(s.at(cr)==s.at(cl)  && s.at(cl)=='9')
							continue;
					
						if(s.at(cr)==s.at(cl))
							{
								nine=false;
								continue;
							}
						
						if(s.at(cl)<s.at(cr))				
						{
							if(s.at(m1)=='9')
							{
								s.at(m1)='0';
								s.at(m2)='0';
								p=m1-1;
								while(s.at(p)=='9')
								{
									s.at(p)='0';
									p--;
								}
								s.at(p)+=1;
							}
							else
							{		
								s.at(m1)+=1;
								s.at(m2)+=1;
							}
		
							for(p=m1-1,q=m2+1;p>=0;p--,q++)
								s.at(q)=s.at(p);
							break;
						}
						
						if(s.at(cl)>s.at(cr))
						{
							for(p=m1-1,q=m2+1;p>=0;p--,q++)
								s.at(q)=s.at(p);
							break;
	
						}
					}//for
				
				if(cl<0 && nine==true)			
					{
					s="1"+s;
					for(p=1;p<len;p++)
						s.at(p)='0';
					s.at(len)='1';
					}
			
				if(cl<0 && nine==false)
					{		
							if(s.at(m1)=='9')
							{	
								s.at(m1)='0';
								s.at(m2)='0';

								p=m1-1;
								q=m2+1;
								while(s.at(p)=='9' && s.at(q)=='9')
									{
									s.at(p)='0';
									s.at(q)='0';
									--p;
									++q;
									}

								s.at(p)+=1;
								for(p=m1-1,q=m2+1;p>=0;p--,q++)
									s.at(q)=s.at(p);
							}
							else
							{		
								s.at(m1)+=1;
								s.at(m2)+=1;			
							}
							
					}
			}
				
		}
		cout<<s<<"\n";
	}

	return 0;
}
