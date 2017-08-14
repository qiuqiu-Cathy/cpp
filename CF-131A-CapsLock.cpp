#include <bits/stdc++.h>
using namespace std;
//thanks to tzz
int main()
{
	string s;
	int flag;
	char c[102];
	while(cin >> s)
	{
		memset(c,0,sizeof(c));
		flag=0;
		c[0]=toupper(s[0]);

		if(c[0]==s[0])//首字母大写 HTTP
		{
			c[0]=tolower(c[0]);
			for(int i=1;i<s.length();i++)
			{
				c[i]=tolower(s[i]);
				if(c[i]==s[i])
				{
					flag=1; //不符
				}
			}
			if(flag==1)
				cout << s << endl;
			if(!flag)
				cout << c << endl;
		}
		else if(c[0]!=s[0]) //首字母小写
		{
			for(int i=1;i<s.length();i++)
			{
				c[i]=tolower(s[i]);
				if(c[i]==s[i])
				{
					flag=1;
				}
			}
			if(flag==1)
				cout << s << endl;
			if(!flag)
				cout << c << endl;
		}
	}
	return 0;
}
