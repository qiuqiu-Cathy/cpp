#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin >> s)
    {
        int flag=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='H'||s[i]=='Q'||s[i]=='9')
                flag=1;
        }
        if(!flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
