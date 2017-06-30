//感觉这道题被我水过去了没用并查集。。。。不存在的最后还是得乖乖校对并查集的标程写代码，气哭
/*
   拉拉帮，结结派
   描述

   武林，当然有拉帮结派，帮派之间还有吞并现象。那么两个人见面，常常要问，咱俩是自己人吗？你需要做的就是快速回答这个问题。
   武林中共有 N 个人，编号分别为 1~N，有 M 条命令，两种格式：
   1 x y：编号为 x 和 y 的两个人所在的帮派合并了；
   2 x y：请回答编号为 x 和 y 的两个人是否是自己人。

   开始的时候，没有人属于同一个帮派。
   输入

   第一行包含两个整数 N, M，表示有 N 个人和 M 条命令。
   接下来 M 行每行包含 3 个整数：t x y，表示一种命令。

   0 < N, M < 1e5
   0 < t < 3
   0 < x, y < N + 1 且 x 不等于 y

   输出

   对于每条第二种命令，输出 "Yes" 或 "No"。

   样例输入1

   3 4
   2 1 2
   1 1 2
   2 1 2
   2 2 3

   样例输出1

   No
   Yes
   No


*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int father[N];  //父亲结点
void init(int n)                       //初始化
{
	for(int i=0;i<n;i++)
		father[i]=i;
}
int find(int i)                       //利用递归寻找某点的父亲结点
{
	if(father[i]!=i)
		father[i]=find(father[i]);
	return father[i];//利用递归
}
void merge(int a,int b)                //合并操作
{
	a=find(a);
	b=find(b);
	if(a!=b)
		father[a]=b;
}
int main()
{
	int n,m,c,d,t;
	while(cin >> n >> m)
	{
		init(n);
		while(m--)
		{
			cin >> t >> c >> d;
			if(t==1)
				merge(c,d);
			if(t==2)
			{
				if(find(c)==find(d))
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
		}
	}
	return 0;
}
/*int main()
{	
	int n,m,t,i;
	for(i=0;i<N;i++)
	{
		a[i]=i;
	}
	while(cin >> n >> m)
	{
		while(m--)
		{
			int c,d;//记录需比较的帮派的序号
			cin >> t >> c >> d;
			if(t==1)
			{
				a[d-1]=a[c-1];
			}
			if(t==2)
			{
				if(a[c-1]==a[d-1])
					cout << "Yes" << endl;
				else
					cout << "No"  << endl;
			}
		}
		for(i=0;i<n;i++)
			a[i]=i;
	}
	return 0;
}*/

