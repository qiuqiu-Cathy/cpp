/*
算法题2 最长公共子序列
发布时间: 2017年10月11日 12:56   时间限制: 1000ms   内存限制: 128M

描述
序列Z=<B，C，D，B>是序列X=<A，B，C，B，D，A，B>的子序列，相应的递增下标序列为<2，3，5，7>。

一般地，给定一个序列X=<x1,x2,…,xm>，则另一个序列Z=<z1,z2,…,zk>是X的子序列，是指存在一个严格递增的下标序列〈i1,i2,…,ik〉使得对于所有j=1,2,…,k使Z中第j个元素zj与X中第ij个元素相同。

给定2个序列X和Y，当另一序列Z既是X的子序列又是Y的子序列时，称Z是序列X和Y的公共子序列。

你的任务是：给定2个序列X、Y，求X和Y的最长公共子序列Z。

输入
输入文件中的第1行是一个正整数T，（0<T<=10），表示有T组测试数据。接下来是每组测试数据的描述，每组测试数据有3行。

测试数据的第1行有2个正整数m、n，中间用一个空格隔开，（0<m，n<50）；第2、3行是长度分别为m、n的2个序列X和Y，每个序列的元素间用一个空格隔开。序列中每个元素由字母、数字等构成。

输入直到文件结束。

输出
对输入中的每组测试数据，输出2行。先在一行上输出“Case #”，其中“#”是测试数据的组号（从1开始），再在第2行上输出这2个序列X、Y的最长公共子序列Z的长度。

样例输入1 复制
2
7 6
A B C B D A B
B D C A B A
8 9
b a a b a b a b
a b a b b a b b a
样例输出1
Case 1
4
Case 2
6
*/
#include<bits/stdc++.h>
using namespace std;


int dp[100][100];//dp[i][j] 表示 第一个序列从0到i第二个序列从0到j的子序列的最长公共子序列的长度
char x[100];
char y[100];
int main()
{
	int T;
	cin >> T;
	int ka = 0;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i = 0;i < n;i++)
			cin >> x[i];
		for(int j = 0;j < m;j++)
			cin >> y[j];
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				if(x[i] == y[j])
				{
					dp[i+1][j+1] = dp[i][j] + 1;
				}
				else
					dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
			}
		}
		cout << "Case " << ++ ka << endl;
		cout << dp[n][m] << endl;
	}
}
