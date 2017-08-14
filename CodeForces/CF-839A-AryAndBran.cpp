#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    int a[105];
    int cnt;
    while(cin >> n >> k)
    {
        cnt=0;
        for(int i=0;i<n;i++)
            cin >> a[i];
            x
      //  sort(a,a+n);
        int cur = 0;
        for(int i=0;i<n;i++)
        {
            cur += a[i];
            if(k > 0)
                cnt ++;
            k -= min(8,cur);
            cur -= min(8,cur);
        }
        if(k<=0)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }
}
