#include <bits/stdc++.h>
using namespace std;

vector<int>tar;

int main()
{
    string s;
    while(cin >> s)
    {
        for(int i = 0;i<s.length();i++)
            if(s[i] != '+')
                tar.push_back(s[i]- '0');
        sort(tar.begin(),tar.end());
        for(int i = 0 ;i<tar.size()-1;i++)
            cout <<tar[i] << "+";
        cout << tar[tar.size()-1] << endl;
    }
    return 0;
}
