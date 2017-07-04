//csl的xyz
/*
   csl的xyz跑了

   描述

   今天真是太糟糕了，csl的xyz跟着hh老板跑了。现在csl只能步行或者骑小黄车去追hh老板和xyz。现假设csl和hh老板在一维坐标轴上追赶，hh老板的宝马车没油了只能停在坐标轴的k处，而csl现在在坐标轴n处，每次可以步行走到n-1或者n+1的位置，但是小黄车的刹车坏了，每次只能让他走到n*2的地方。问最少需要几次csl能找到hh老板和xyz。
   输入

   输入有多组，每组有n，k两个整数， 0 <=n,k <= 1e5
   输出

   输出最少的移动次数
   样例输入1

   5 2

   样例输出1

   3
*/
#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
const int N=1e5+5;
struct Node 
{
	int x;
	int step;
};
int vis[N*2+5];
int bfs(int s,int t)
{
	memset(vis,0,sizeof(vis));
	Node st= {s,0};
	int step=0;
	queue<Node>q;
	q.push(st);
	while(!q.empty())
	{
	//	Node temp=
		Node temp =q.front();
		q.pop();
		if(temp.x==t)
			return temp.step;
		vis[temp.x]=1;
		for(int i=0;i<3;i++)
		{
			Node pos ={temp.x,temp.step};
			if(i==0)
			{
				pos.x++;
				pos.step++;
				if(vis[pos.x]||pos.x>N)
					continue;
				q.push(pos);
			}
			if(i==1)
			{
				pos.x--;
				pos.step++;
				if(vis[pos.x]||pos.x>N)
					continue;
				q.push(pos);
			}
			if(i==2)
			{
				pos.x=pos.x*2;
				pos.step++;
				if(vis[pos.x]||pos.x>N)
					continue;
				q.push(pos);
			}
			
		}


	}
	
	return -1;
}
int main()
{
	int n,k;
	while(cin >> n >> k)
	{
		cout << bfs(n,k) << endl;
	}
	return 0;
}
