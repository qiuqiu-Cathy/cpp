//DF S的应用
/*
 csl的暴走
 描述

 csl今天生气了，他不知不觉走到了一棵树的根上。csl很想走远一点，但是这棵树的深度是固定的，他非常的苦恼，于是他掏出了他的水果233，打了个电话问你，你能帮他编个程算一算嘛？设每两个树上的节点之间距离为1，树根始终为0号点。
 输入

 多组输入。第一行一个正整数n，0 < n < 1e5,接下来有n-1行，每行两个正整数u,v, 0 <= u,v < n,表示u,v之间有一条通路。保证输入合法。
 输出

 输出一个正整数dis
 样例输入1

 2
 0 1

 样例输出1

 1


 */
#include<bits/stdc++.h>
using namespace std;
//thanks to tl
const int N=1e5+5;
vector<int>graph[N];
void init() //清空图的信息
{
	for(int i=0;i<N;i++)
	{
		graph[i].clear();
	}
}
int visit[N];
int Max=0;
void dfs(int u,int d) //遍历每个结点的最大深度,求出图深度，即图中所有结点的最大深度
{	
	visit[u]=1;
	Max=max(d,Max);
	for(int i=0;i<graph[u].size();i++)
	{
		int v=graph[u][i];
		if(visit[v])
			continue;
		dfs(v,d+1);
	}
}
int main()
{
	int V,u,v;//V表示顶点个数
	while(cin >> V)
	{
		init();
		memset(visit,0,sizeof(visit));
		Max=0;
		for(int i=0;i<V-1;i++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u); //建立无向图边之间的联系		
		}
		dfs(0,0);
		cout << Max << endl;

	}
}
