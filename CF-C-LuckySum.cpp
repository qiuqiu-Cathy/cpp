#include <bits/stdc++.h>
using namespace std;
long long next(long long n)
{
	int cnt=0，a[12]=0;
	long long num=n,nn=n;
	long ans=0;
	while(n!=0)
	{
		n=n/10;
		cnt++;
	}
	for(int i=1;i<=cnt;i++)
	{
		a[i]=num%10;
		num=num/10;
	}
	if(a[cnt]<4)
		for(int i=0;i<cnt;i++)
			ans=ans*10+4;
	if(a[cnt]>4&&a[cnt]<7)
	{
		ans=7;
		for(int i=0;i<cnt-1;i++)
			ans=ans*10+4;
	}
	if(a[cnt]>7)
		for(int i=0;i<=cnt;i++)
			ans=ans*10+4;
	if(a[cnt]==4||a[cnt]==7)
	{
		int flag=0;
		int j;
		for(int i=cnt-1;i>=1;i--)
			if(a[i]!=4||a[i]!=7)
			{
				flag=1;
				j=i;
			}
		if(flag==0)
			ans=nn;
		if(flag==1)
		{
			int x;
			x=10*j;
			long long tans;
			tans=(nn/x)*x;
			if(a[j]<4)
			
		}
			 
	}

	return ans;
}
int main()
{
	long long l,r,sum;
	while(cin >> l >> r)
	{
		sum=0;
		for(int i=l;i<=r;i++)
			sum=sum+next(i);
		cout << sum << endl;
	}
	return 0;
}
