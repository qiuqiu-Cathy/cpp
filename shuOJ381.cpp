//青蛙的约会 应用扩展欧几里德
//坑点在m,n大小未知，要判断一下
#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
typedef long long LL;  
//typedef double DB;  
  
LL e_gcd(LL a,LL b,LL &x,LL &y)  //扩展欧几里德模板
{  	
   	if(b==0)  
	{  
	   	x=1;  
		y=0;  
	    return a;  
	}  
   	LL ans=e_gcd(b,a%b,x,y);  
   	LL temp=x;  
   	x=y;  
	y=temp-a/b*y;  
	return ans;  
} 
LL cal(LL a,LL b,LL c)    //ax+by=c
{  	
   	LL x,y;  
	LL gcd=e_gcd(a,b,x,y);  
	if(c%gcd!=0) 
		return -1;  
	x*=c/gcd;  
	b/=gcd;  
	if(b<0) b=-b;
		LL ans=x%b;  
	if(ans<=0) ans+=b;  
		return ans;  
} 



int main()
{
	LL x,y,m,n,L;
	while(cin >> x >> y >> m >> n >> L)
	{
		LL ans=cal(n-m,L,x-y);  //x+mt=(y+nt)+Lu  ->   (n-m)t+Lu=x-y(套用公式)
		if(ans==-1)
			cout << "Impossible" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}

