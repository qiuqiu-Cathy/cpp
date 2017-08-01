//���鼯
/*
���������������ද��A,B,C�������ද���ʳ������������Ȥ�Ļ��Ρ�A��B�� B��C��C��A��
����N�������1��N��š�ÿ�����ﶼ��A,B,C�е�һ�֣��������ǲ���֪������������һ�֡�
����������˵������N�����������ɵ�ʳ������ϵ����������
��һ��˵����"1 X Y"����ʾX��Y��ͬ�ࡣ
�ڶ���˵����"2 X Y"����ʾX��Y��
���˶�N���������������˵����һ���һ���˵��K�仰����K�仰�е�����ģ��е��Ǽٵġ���һ�仰������������֮һʱ����仰���Ǽٻ�����������滰��
1�� ��ǰ�Ļ���ǰ���ĳЩ��Ļ���ͻ�����Ǽٻ���
2�� ��ǰ�Ļ���X��Y��N�󣬾��Ǽٻ���
3�� ��ǰ�Ļ���ʾX��X�����Ǽٻ���
��������Ǹ��ݸ�����N��1 <= N <= 50,000����K�仰��0 <= K <= 100,000��������ٻ���������
Input
��һ������������N��K����һ���ո�ָ���
����K��ÿ�������������� D��X��Y������֮����һ���ո����������D��ʾ˵�������ࡣ
��D=1�����ʾX��Y��ͬ�ࡣ
��D=2�����ʾX��Y��
Output
ֻ��һ����������ʾ�ٻ�����Ŀ��
Sample Input
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
Sample Output
3
*/
#include <iostream>
#include <cstdio>
using namespace std;
const int N=50005;

int father[N],son[N],n;

int ffind(int x)
{
    if(x!=father[x])
    {
        int fx=ffind(father[x]);
        son[x]=(son[x]+son[father[x]])%3;
        father[x]=fx;
    }
    return father[x];
}

bool Union(int d,int x,int y)
{
    int fx=ffind(x),fy=ffind(y);
    if(fx==fy)
    {
        if((son[y]-son[x]+3)%3!=d)
            return 1;
        else
            return 0;
    }
    father[fy]=fx;
    son[fy]=(son[x]-son[y]+d+3)%3;
    return 0;
}
int main()
{
    int k,ans,i,d,x,y;
    scanf("%d%d",&n,&k);
    ans=0;
    for(i=1;i<=n;i++)
    {
        father[i]=i;
        son[i]=0;
    }
    while(k--)
    {
        scanf("%d%d%d",&d,&x,&y);
        if(x>n||y>n||(x==y&&d==2))
        {
            ans++;
            continue;
        }
        if(Union(d-1,x,y))
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}

