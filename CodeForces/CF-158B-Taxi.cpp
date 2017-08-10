/*
the children need if all members of each group should ride in the same taxi
*/
//greedy
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,num,a,b,c,d,ans;

    while(cin >> n)
    {
        ans=0;
        a=b=c=d=0;
        while(n--)
        {
            cin >> num;
            if(num==1)
                a++;
            if(num==2)
                b++;
            if(num==3)
                c++;
            if(num==4)
                d++;
        }
        ans=ans+d;
        if(a>=c&&(a-c+2*b)%4==0)
            ans=ans+c+(a-c+2*b)/4;
        else if(a>=c&&(a-c+2*b)%4!=0)
            ans=ans+c+(a-c+2*b)/4+1;
        else if(a<c && (2*b)%4==0 )
            ans=ans+c+(2*b)/4;
        else if(a<c && (2*b)%4!=0)
            ans=ans+c+(2*b)/4+1;
        cout << ans << endl;
    }
    return 0;
}
