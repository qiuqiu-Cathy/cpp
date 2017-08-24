#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[210];
    while(cin >> n)
    {
        for(int i=0;i<2*n;i++)
        {
            cin >> a[i];
        }
        sort(a,a+2*n);
        if(a[n-1]<a[n])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
