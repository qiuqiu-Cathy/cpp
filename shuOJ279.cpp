#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
int main()
{
	int T,i,len,cnt; 
	cin >> T;
	char str[100];
	while(T--)
	{
		cin >> str;
		len=strlen(str);
		cnt=0;
		for(i=0;i<len-1;i++)
		{
			if(str[i]!=str[i+1])  //每次翻转异号处
				cnt++;
		}
		if(str[len-1]=='-') //如果-在最后一位则多翻转一次
			cnt++;
		cout << cnt << endl;
	}
	return 0;
}

