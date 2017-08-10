#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,num;
	while(cin >> n)
	{
		num=n;
		int flag=0;
		while(n!=0)
		{
			a=n%10;
			n=n/10;
			if(a==4||a==7)
				continue;
			else 
				flag=1;
		}
		if(flag==0)
			cout << "YES" << endl;
		if(flag==1)
		{
			if(num%4==0||num%44==0||num%7==0||num%77==0||num%47==0)
				cout << "YES" << endl;
			else 
				cout << "NO" << endl;
		}
	}
	return 0;
}
