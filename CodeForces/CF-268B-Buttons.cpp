//S = n + (n-1) + (n-2) * 2 + (n - 3) * 3 ...
//需要推出数学公式
//(n-1)*1 确定第一个button的按键次数
//(n-2)*2 确定第二个button的按键次数 ，带上第一个已经正确判断的按键所以是×2
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	long long ans;
	while(cin >> n)
	{
		ans=n;
		for(int i=1;i<n;i++)
		{
			ans+=(n-i)*i;
		}
		cout << ans << endl;
	}
	return 0;
}
