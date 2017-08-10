/*
   Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help Petya perform the comparison.
Input

Each of the first two lines contains a bought string. The strings' lengths range from 1 to 100 inclusive. It is guaranteed that the strings are of the same length and also consist of uppercase and lowercase Latin letters.
Output

If the first string is less than the second one, print "-1". If the second string is less than the first one, print "1". If the strings are equal, print "0". Note that the letters' case is not taken into consideration when the strings are compared.
*/
#include <bits/stdc++.h>
using namespace std;
//hate dpz
int main()
{
	char a[105],b[105];
	while(cin >> a >> b)
	{
		int flag=0;
		for(int i=0;i<strlen(a);i++)
		{
			a[i]=tolower(a[i]);
			b[i]=tolower(b[i]);
		}
		
		for(int i=0;i<strlen(a)&&flag==0;i++)
		{
			if(a[i]>b[i])
			{	
				cout << "1" << endl;
				flag=1;
			}
			if(a[i]<b[i])
			{
				cout << "-1" << endl;
				flag=1;
			}
		}
		if(flag==0&&(a[strlen(a)-1]==b[strlen(a)-1]))
			cout << "0" << endl;
	}
	return 0;
}
