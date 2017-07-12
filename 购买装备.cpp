//二分 最小值最大化  （最大值最小化类似）
/*
购买装备

描述

最近盛大的一款游戏传奇世界极其火爆。游戏玩家John，想购买游戏中的装备。已知游戏的商店里有n件装备，第i件装备具有属性值ai，购买需要花费bi个金币。John想去购买这些装备，但是账号中只有m个金币，John是个很贪婪的家伙，他想购买尽可能多的装备。并且在保证购买到最多件装备的情况下，他还想让他所购买的装备当中拥有最小属性值的装备的属性值尽可能大。
输入

输入测试组数T，每组数据第一行输入整数n(1<=n<=100000)和m(1<=m<=109), 接下来有n行，第i行有两个数ai, bi(1<=ai,bi<=10000).
输出

对于每组数据，输出两个数字，第一个数字代表John最多可以购买的装备数，第二个数代表在John购买最多件装备的前提下，所购买的装备当中拥有最小属性值的装备的最大属性值(输入数据保证至少可以购买一件装备)
样例输入1

1
2 4
3 2
2 3

样例输出1

1 3
   */
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;//件数
int m;//金币数
struct Node
{
	int value,price;
};
bool cmp(Node a,Node b)
{
	return a.price<b.price;
}
bool check(int mid)
{

}

int search(int l,int r,int tar)
{
	int mid;
	int ans=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid+1,ans = max(ans,mid);
		else
			r=mid-1;
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	Node a[N];
	int need;//所能买到的最大装备数
	int cnt,money;
	while(T--)
	{
		need=cnt=0;
		cin >> n >> m;
		for(int i=0;i<n;i++)
			cin >> a[i].value >> a[i].price;
		sort(a,a+n,cmp);//通过cmp的条件来将a[1]到a[n]排序
		int tar = 0;
		for(int i=0;i<n;i++) // 求出我能买到的最多装备数
		{
			if(a[i].value < tar)
				continue;
			if(a[i].price<=m)
			{
				cnt++;
				m=m-a[i].price;
			}
			else 
				break;
		}
		need=cnt;
	}

}
