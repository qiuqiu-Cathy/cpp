
#include <bits/stdc++.h>
using namespace std;

void Dijkstra(int n, int v, int dist[], int prev[], int **c,int maxint, int num[])
{
    //单源最短路径Dijkstra算法
    //dist[]记录当前每个顶点所对应的最短特殊路径长度
    //dist[i]表示当前从源到顶点i的最短特殊路径长度
    //prev[u]存储结点在最短路径中的前一个点

    bool s[100];//判断当前点是否在顶点集s中，一旦s包含所有点则记录完成
    for(int i=1;i<=n;i++)
    {
        dist[i]=c[v][i];//c[i][j]表示边(i,j)的权
        s[i]=false;
        if(dist[i]==maxint)
            prev[i]=0;
        else
            prev[i]=v;
        num[i]=1;
    }
    dist[v]=0;
    s[v]=true;

    //找出点i出发到顶点集s内结点的最短带权路径
    for(int i=1;i<n;i++)
    {
        int temp=maxint;
        int u=v;
        for(int j=1;j<=n;j++)
            if((!s[j])&&(dist[j]<temp))//判断结点j是否在s集合内，到顶点集s内的点的带权路径是否小于当前值
            {
                u=j;
                temp=dist[j];
            }
        s[u]=true;
        //更新结点i到j之间的最短路径，并记录
        for(int j=1;j<=n;j++)
        {
            if((!s[j])&&(c[u][j])<maxint)
            {
                int newdist=dist[u]+c[u][j];
                int newnum=num[u] + 1;
                if(newdist<dist[j])
                {
                    dist[j]=newdist;
                    prev[j]=u;
                }
                //如果最短路径相同，则保留经过结点数最少的情况
                else if((newdist==dist[j])&&(num[j]>newnum))
                {
                    num[j]=newnum;
                    prev[j]=u;
                }
            }
        }
    }
}

//打印最短路径
void Path(int s, int t, int prev[], int start)
{
    if(t!=s)
    {
        int nownode=t;
        t=prev[t];
        Path(s,t,prev,start);
        cout << "->" << nownode;
    }
    else cout << start;
}

int main()
{
    int n,casenum=0;
    while(cin >> n)
    {
        casenum++;
        int maxint=1e9;
        int **c=new int*[n+1];
        for(int i=1;i<=n;i++)
            c[i]=new int[n+1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                cin >> c[i][j];
                if(c[i][j]==-1)
                    c[i][j]=maxint;
            }
         int s,t;
         cin >> s >> t;
         int dist[n+1];
         int prev[n+1];
         int num[n+1];
         Dijkstra(n,s,dist,prev,c,maxint,num);
         cout << "Case " << casenum << endl;
         cout << "The least distance from " << s << "->" << t << " is " << dist[t] << ". " << endl;
         cout << "The path is " ;
         Path(s,t,prev,s);
    }
    return 0;
}

