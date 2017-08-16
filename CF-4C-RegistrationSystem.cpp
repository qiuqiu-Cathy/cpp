#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<string,int>m;
	string s;
	int n;
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			cin >> s;
			if(m[s])
				cout << s << m[s] << endl;
		   	else
				cout << "OK" << endl;
			m[s]++;	
		}	
	}
	return 0;
}
