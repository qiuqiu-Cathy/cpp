//����С������������ ��kruscal�е�����
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
// thanks to tl~
//ƨƨ���ģ��23333

const int N = 1e5 + 5;

struct Edge
{
	int u, v, d;
	int del, intree;
	int equal;
	bool operator < (const Edge &rhs) const
	{
		return d < rhs.d;
	}
} edge[N * 2];
int fa[N];
int n, m;
int first;
void init()
{
	for (int i = 0; i < N; i++)
		fa[i] = i;
}
int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (fa[a] != fa[b])
		fa[a] = b;
}
int kruskal() //��һ����С������
{
	init();
	int ans = 0;
	/*for (int i = 0; i < m; i++)
	{
		if (edge[i].del)
			continue;
		int u = edge[i].u , v = edge[i].v;
		if (find(u) != find(v))
		{
			ans += edge[i].d;
			if (first)
				edge[i].intree = 1;
			merge(u, v);
		}
	}
	*/
	//����С�����������бߵĳ���
	for(int i=0;i<m;i++)
    {
        int u=edge[i].u,v=edge[i].v;
        if(find(u)!=find(v))
        {
            ans=max(ans,edge[i].d);
            merge(u,v);
        }
    }
    //����������⣬����С��������ıߵĳ���
	return ans;
}
/*
int unique_MST() // �ж��������Ƿ�Ψһ����Ψһ ����-1��Ȼ������С����������ֵ
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			if (i != j && edge[i].d == edge[j].d)
				edge[i].equal = edge[j].equal = 1;
	first = 1;
	int Min = kruskal();
	first = 0;
	for (int i = 0; i < m; i++)
	{
		if (edge[i].intree && edge[i].equal)
		{
			edge[i].del = 1;
			int cur_ans = kruskal();
			if (cur_ans == Min)
				return -1;
			edge[i].del = 0;
		}
	}
	return Min;
}
*/
int main()
{
	/*int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		memset(edge, 0, sizeof(edge)); // ����ʼ����Ż����
		for (int i = 0; i < m; i++)
			cin >> edge[i].u >> edge[i].v >> edge[i].d;
		sort(edge, edge + n);
		int res = unique_MST(); //�Ȱ�ֵȡ���� ��Ҫ��ε��øо���T
		if (res != -1)
			cout << res << endl;
		else
			cout << "Not Unique!" << endl;
	}
	*/
	int T;//T cases
	scanf("%d",&T);
	while(T--)
    {
        scanf("%d",&n);// n villages
        memset(edge,0,sizeof(edge));
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int x;
                scanf("%d",&x);
                if(i==j)
                    continue;
                edge[cnt].u=i;
                edge[cnt].v=j;
                edge[cnt].d=x;
                cnt++;
            }
        }
        m=cnt;
        sort(edge,edge+m);
        printf("%d\n",kruskal());
    }
    return 0;
}
