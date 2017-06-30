//csl的帽色判定
/* 描述

   最近csl喜欢上了帽子，所以他买了很多，有绿色的，绿色的，绿色的，毕竟csl非常喜欢AC。当然除了绿色的还有其他很多颜色。今天听了弘弘的并查集讲座，现在他希望用并查集做个统计，想知道任意两顶帽子颜色是不是相同的，但是他的帽子太多了，只能求助与神秘的程序员老王来解决了。但是老王是个浮夸的人，于是他找了你来帮忙。
   输入

   多组输入，第一行输入n个人,m个查询。接着有n行，每行有一个数表示第i个帽子的颜色。接下来有m行，每行两个数字a，b表示询问标号为a，b的帽子颜色是否相同。标号从0开始。n < 1e5,m < 1e5。帽子颜色保证在int范围内
   输出

   对每次查询，如果相同输出yes，
   样例输入1

   2 1
   100000
   1234
   0 1

   样例输出1

   no


*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int clo[N];
//thanks to tl~
int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		for(int i=0;i<n;i++)
		{
			cin >> clo[i];
		}
		while(m--)
		{
			int a,b;
			cin >> a >> b;
			if(clo[a]==clo[b])
				cout << "yes" << endl;
			else
				cout << "no" << endl; 
		}
	}
	return 0;
}

