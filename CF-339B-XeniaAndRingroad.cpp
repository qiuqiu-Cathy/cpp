//只能走顺时针的环形路
#include <bits/stdc++.h>
using  namespace std;
//thanks to tl~
int main()
{
	long long n,m;
	long long a[100005];
	long long cur,last;
	long long ans;
	while(cin >> n >> m )
	{
		last=1;
		ans=0;
		while(m--)
		{
			cin >> cur;
			if(cur>=last)
				ans=ans+cur-last;
			else
				ans=ans+n-(last-cur);
			last=cur;
		}
		cout << ans << endl;
	}
	return 0;
}

