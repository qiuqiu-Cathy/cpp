//brute force  greedy   implementation
#include <bits/stdc++.h>
using namespace std;
//thanks to tl~

int main()
{
    int n,k; //n rows   k groups
    int x1,x2,x4,a;//x4 4人连坐的情况。。。
    while(cin >> n >> k)
    {
        x1=x2=x4=0;
        while(k--)
        {
            cin >> a;
            if(a >= 4)
            {
                x4+=a/4;
                a=a-4*(a/4);
            }
            if(a>=2)
            {
                x2++;
                a-=2;
            }
            if(a)
                x1++;
        }
        int x=n*8-x1*2-x2*2-x4*4;
        if(x>=0&&x1+x4>=n-x)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
