#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1000000007;
int main()
{
   int T,a,b,c,n;
	 ull sum=0;
	 cin >> T;
	 while(T--)
	 {
	 	cin >> a >> b >> c >> n;
	 	sum = 1ULL;
	 	priority_queue < int , vector<int>, less <int> > Left;
	 	priority_queue < int , vector<int>, greater <int> > Right;
	 	Left.push(1);
 		int ls=Left.size();
 		int rs=Right.size();
	 	for(int i=2;i<=n;i++)
	 	{
	 		int m=Left.top();
	 		ull r=1ULL*a*m + 1ULL*b*i + c;
	 		//cout << r << ' ' << m << ' ' << i << ' ' << ls << ' '<< rs << endl;
	 		if(r>=mod) 
	 			r = r % mod;
	 		sum+=r;
	 		if(m>r){
	 			Left.push(r); ls++;
	 		}else{
	 			Right.push(r); rs++;
	 		}
	 		while(ls > rs+1){
	 			Right.push(Left.top()); Left.pop();
	 			ls--; rs++;
	 		}
	 		while(rs > ls){
	 			Left.push(Right.top()); Right.pop();
	 			rs--; ls++;
	 		}
	 	}
	 	cout << sum << endl ;
	 	
	 }
	 
	 return 0;
}
