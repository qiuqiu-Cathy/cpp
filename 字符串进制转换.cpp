//将字母转换成相应的数字 将10进制转成2-9进制的转换
//十进制转换为任意进制的源码
/*
   字符串进制转换

   描述

   Claire Redfield在龙之谷游戏的一次任务中获得了一个上了锁的宝箱，上面刻了一串由小写字母构成的字符串A和一个数字m。

   经过Claire长时间研究，他发现密码是和a，m有关的。字符串A相当于一个26进制的数字，a相当于0，b相当于1…….z相当于25。然后要将这个26进制的数转化成m进制那就是这个宝箱的密码。

   Claire觉得这个太简单了所以要你帮她完成。
   输入

   多组输入，每组一行，输入一个字符串A和一个正整数m。
   字符串长度<=10，2<=m<=9。
   输出

   每组输出一行答案，如题意。
   样例输入1

   b 2

   样例输出1

   1

 */
#include <bits/stdc++.h>
using namespace std;
//thanks to tl ~
//thanks to csl

void print(long long num,int m)
{
	if(!num)
		return;
	print(num/m,m);
	printf("%lld",num%m);
}    // from csl

int main()
{
	string s;//代表一串26进制的数字
	int m;//储存需要转换的进制
	long long Num;//将26进制转换成为10进制的数
	while(cin >> s >> m)
	{
	
		if(s=="a")
		{
			cout << '0' << endl;
			continue;
		}
		Num=0;
		int l=s.size();
		for(int i=0;i<l;i++)
			Num = Num * 26 + s[i] - 'a'; //将字符串->26进制数->10进制数

		//十进制转换为任意进制的源码
	/*	int cnt = 0;
		while(Num!=0)//数制转换，结果存入数组s[j]
		{
			num[cnt++] = Num % m;
			Num /= m;
		}
		for(int k=cnt-1;k>=0;k--)//将结果逆序输出
		{
			cout << num[k];
		}
	*/
		print(Num,m);
		cout << endl;
	}
	return 0;
}




