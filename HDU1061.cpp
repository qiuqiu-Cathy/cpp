//快速幂
#include <iostream>
#include <cstdio>
using namespace std;
//thanks to tl~

long  MOD;
int f(long p,long a)//利用递归求快速幂 a^p%MOD
{
	if(p==0)
		return 1;
	
	long long res = f(p/2,a);
	res = res *res % MOD;
	if(p % 2)
		res = res * a % MOD;
	return res;
}
int main()
{
	int T;
	long N;
	cin >> T;
	MOD=10;
	while(T--)
	{
		cin >> N;
		cout << f(N,N) << endl;	
	}
	return 0;
}
