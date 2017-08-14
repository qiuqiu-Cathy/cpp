#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	char f[105][105];
	int b,r,g;
	int f1=0,f2=0;
	while(cin >> n >> m)
	{
		b=0;
		r=0;
		g=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin >> f[i][j];
				if(f[i][j]=='B')
					b++;
				if(f[i][j]=='G')
					g++;
				if(f[i][j]=='R')
					r++;
			}
		if(b==g&&g==r)
		{
			for(int i=0;i<n-1;i++)
				if(f[i][0]!=f[i+1][0])
					f1=1;
			for(int i=0;i<m-1;i++)
				if(f[0][i]!=f[0][i+1])
					f2=1;
			if(f1+f2<2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}
