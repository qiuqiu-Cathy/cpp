#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
//thanks to tl~
const int N=30005;
int father[N];
int n;

void init()
{
    for(int i=0;i<n;i++)
        father[i]=i;
}

int find(int x)
{
    if(x!=father[x])
        father[x]=find(father[x]);
    return father[x];
}

void merge(int x,int y)
{
    x=find(x);
    y=find(y);
    if(father[x]!=father[y])
        father[x]=father[y];
}

int main()
{
    int m; //  m:×éÊý
    while((cin >> n >> m)&&(n+m))
    {
        init();
        for(int i=0;i<m;i++)
        {
            int cnt;
            cin >> cnt;
            int a;
            cin >> a;
            for(int j=1;j<cnt;j++)
            {
                int b;
                cin >> b;
                if(find(a)!=find(b))
                    merge(a,b);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(find(0)==find(i))
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
