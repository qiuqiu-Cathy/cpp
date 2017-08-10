#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num,a,b,cur,ans;
    while(cin >> num)
    {
        cur=ans=0;
        while(num--)
        {
            cin >> a ;
            cur=cur-a;
            if(cur>ans)
                ans=cur;
            cin >> b;
            cur=cur+b;
            if(cur>ans)
                ans=cur;
        }
        cout << ans << endl;
    }
    return 0;
}
