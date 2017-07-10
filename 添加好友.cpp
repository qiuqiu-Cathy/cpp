//利用递归大数取模，递归模幂
/*
添加好友(“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛（重现赛）)
描述

Tony最近喜欢上了龙之谷游戏，所以他想叫上他的好友组建一个公会来一起享受这款游戏。

Tony一共有n个好友，他可以叫上任意k（1<=k<=n）个好友来组建公会，并且所有好友都会答应他的请求。问Tony一共可以有多少种方案组建这个公会？

只要不是完全相同的人组建的方案视为不同方案，并且Tony至少要叫上一个人。
输入

多组输入，每组一行，输入一个正整数n（1<=n<=1000000000）。
输出

每组输出一行，输出方案数。（对1000000007取膜）
样例输入1

2

样例输出1

3
*/
#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
long MOD;
int f(long p,long a)//利用递归求a^p%p 递归模幂a^p % MOD
{
	if(p==0)
		return 1;
	else
	{
		if(p%2==0)
		{
			p=p/2;
			return   ( (f(p,a)%MOD) * (f(p,a)%MOD) ) % MOD;
		}
		if(p%2==1)
		{
			p=p/2;
			return ( (f(p,a)%MOD) * (f(p,a)%MOD) * (a%MOD) ) % MOD;
		}
	}
}
int main()
{
	long n;
	int ans;//最后取到的余数
	int num;//真正的方案数
	while(scanf("%ld",&n)==1)
	{
		MOD=1000000007;
		printf("%d\n",f(n,2)-1);
	}
	return 0;
}
