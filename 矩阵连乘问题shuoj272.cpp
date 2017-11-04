/*
算法题1 矩阵连乘问题
发布时间: 2017年10月11日 12:56   时间限制: 1000ms   内存限制: 128M

描述
给定n个矩阵A1，A2，…，An，其中，Ai与Aj+1是可乘的，i=1，2，…，n-1。

你的任务是要确定矩阵连乘的运算次序，使计算这n个矩阵的连乘积A1A2…An时总的元素乘法次数达到最少。

例如：3个矩阵A1，A2，A3，阶分别为10×100、100×5、5×50，计算连乘积A1A2A3时按（A1A2）A3所需的元素乘法次数达到最少，为7500次。

输入
测试数据有若干组，每组测试数据有2行。

每组测试数据的第1行是一个整数n，（0<n<20），第2行是n+1个正整数p0、p1、p2、…、pn，这些整数不超过100，相邻两个整数之间空一格，他们表示n个矩阵A1，A2，…，An，的阶pi-1´pi，i=1，2，…，n。

输入直到文件结束。

输出
对输入中的每组测试数据，输出2行。先在一行上输出“Case #”，其中“#”是测试数据的组号（从1开始），再在第2行上输出计算这n个矩阵的连乘积A1A2…An时最少的总的元素乘法次数，再空一格，接着在同一行上输出矩阵连乘的添括号形式。

注意：最外层括号应去掉。

样例输入1 复制
3
10 100 5 50
4
50 10 40 30 5
样例输出1
Case 1
7500 (A1A2)A3
Case 2
10500 A1(A2(A3A4))
*/
#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int a[50];
int dp[50][50];
int pos[50][50];
string tran(int x)
{
	string s = "";
	x ++;
	while (x)
	{
		s += '0' + x % 10;
		x /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}
vector<string>v;
void dfs(int l, int r)
{
	if (l == r)
	{
		v.push_back("A" + tran(l));
		return;
	}
	else
	{
		v.push_back("(");
		dfs(l, pos[l][r]);
		dfs(pos[l][r] + 1, r);
		v.push_back(")");
	}
}
int main()
{
	int n;
	int ka = 0;
	while (cin >> n)
	{
		for (int i = 0; i <= n; i++)
			cin >> a[i];
		cout << "Case " << ++ ka << endl;
		if (n == 1)
		{
			cout << 0 << " A1" << endl;
			continue;
		}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				dp[i][j] = 1e9;
		for (int i = 0; i <= n; i++)
			dp[i][i] = 0;
		// for (int i = 0; i < n - 1; i++)
		// {
		// 	dp[i][i + 1] = a[i] * a[i + 1] * a[i + 2]; // i row i + 1 row
		// 	//i k k + 1 j a[i] * a[k + 1] * a[r + 1]
		// }
		for (int i = 2; i <= n; i++)
		{
			for (int l = 0, r = l + i - 1; r < n; l ++, r ++)
			{
				dp[l][r] = dp[l][l] + dp[l + 1][r] + a[l] * a[l + 1] * a[r + 1];
				pos[l][r] = l;
				for (int k = l + 1; k <= r; k++)
				{
					int temp = dp[l][k] + dp[k + 1][r] + a[l] * a[k + 1] * a[r + 1];
					if (temp < dp[l][r])
					{
						dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + a[l] * a[k + 1] * a[r + 1]);
						pos[l][r] = k;
					}
				}
			}
		}
		cout << dp[0][n - 1] << " ";
		v.clear();
		dfs(0, n - 1);
		for (int i = 1; i < v.size() - 1; i++)
			cout << v[i];
		cout << endl;
	}
}
