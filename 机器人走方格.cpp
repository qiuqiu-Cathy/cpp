//�����������ѧ �Ϻ���ѧ����ѵ�� contest7.27
/*
     M * N�ķ���һ�������˴������ߵ����£�ֻ�����һ������ߡ��ж����ֲ�ͬ���߷������ڷ����������ܴܺ�ֻ��Ҫ���Mod 10^9 + 7�Ľ����
Input
    ��1�У�2����M,N���м��ÿո��������2 <= m,n <= 1000)
Output
    ����߷���������
Sample Input

    2 3

Sample Output

    3
*/
//C(m-1+n-1,m-1)=(m-1+n-1)!/((m-1)!*(n-1)!)
/*#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;

void ex_gcd(LL a, LL b, LL &d, LL &x, LL &y) //��չŷ����ã�շת�������
{
    if(b==0)
    {
        x = 1;
        y = 0 ;
        d = a;
        return ;
    }
        ex_gcd(b, a%b, d, y, x);
        y -= x*(a/b);
}

    //�˷���Ԫ ax = 1(mod m)
LL inverse(LL a, LL m)
{
    LL x, y, d;
    ex_gcd( a, m, d, x, y);
    if(d!=1)
        return 0;
    return (x%m + m)%m;
}


LL comb(LL m, LL n)
{
    LL t1 =1, t2=1;
    for(LL i = n-m+1 ; i<=n ; ++i)
        t1 = t1*i%mod;
    for(LL i = 1 ; i<=m ; ++i)
        t2 = t2*i%mod;
    return t1*inverse(t2, mod)%mod;
}

int main()
{
    int a, b;
    cin>> a >> b;
    cout<<comb(max(a-1, b-1), a+b-2)%mod<<endl;
    return 0;
}
*/
//�����Ǹ������ǶԵģ����ǣ��ң������𰸶����������о����������һ�������ģ�壬��Ϊ����һ����˲���ƶ���Ҳ�ǿ�����������ģ��������
//��Ҳ���찡�����鸴�ӣ��ĺ��۰�������������������
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long LL;
const int p = 1e9 + 7;
LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
        return ans;
}

LL C(LL n, LL m)
{
    if(m > n)
        return 0;
    LL ans = 1;
    for(int i=1; i<=m; i++)
    {
        LL a = (n + i - m) % p;
        LL b = i % p;
        ans = ans * (a * quick_mod(b, p-2) % p) % p;
    }
    return ans;
}

LL Lucas(LL n, LL m)
{
    if(m == 0)
        return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main()
{
    int k, T, n, m;
    scanf("%d%d", &n, &m);
    printf("%I64d\n", C(n+m-2, m-1));
    return 0;
}
