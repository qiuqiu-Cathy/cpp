#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[55];
	while(cin >> s)
	{
		int cnt1=0;
		int cnt2=0;
		int l=strlen(s);
		for(int i=0;i<l;i++)
		{
			if(s[i]=='4')
				cnt1++;
			if(s[i]=='7')
				cnt2++;
		}
		if(cnt1>cnt2)
			cout << "4" << endl;
		if(cnt2>cnt1)
			cout << "7" << endl;
		if(cnt1==cnt2&&cnt1!=0)
			cout << "4" << endl;
	   	if(cnt1==0&&cnt2==0)
			cout << "-1" << endl;	
	}
	return 0;
}
