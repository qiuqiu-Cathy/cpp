#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,l;
    int a[1002];
    double aa,b,c;
    while(cin >> n >> l)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        aa=max(a[0],l-a[n-1]);
        b=abs(a[0]-a[1])/2.0;
        for(int i=0;i<n-1;i++)
            if(abs(a[i]-a[i+1])/2.0>b)
                b=abs(a[i]-a[i+1])/2.0;
        c=max(aa,b);
        printf("%.10f\n",c);
    }
    return 0;
}
