//利用了组合数学 上海大学暑期训练 contest7.27
/*
     M * N的方格，一个机器人从左上走到右下，只能向右或向下走。有多少种不同的走法？由于方法数量可能很大，只需要输出Mod 10^9 + 7的结果。
Input
    第1行，2个数M,N，中间用空格隔开。（2 <= m,n <= 1000)
Output
    输出走法的数量。
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

void ex_gcd(LL a, LL b, LL &d, LL &x, LL &y) //扩展欧几里得（辗转相除法）
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

    //乘法逆元 ax = 1(mod m)
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
//上面那个做法是对的，但是，我，两个答案都看不懂。感觉下面这个是一个神奇的模板，因为另外一道“瞬间移动”也是可以用这道题的模板来做的
//我也不造啊，心情复杂，心好累啊。。。。。。。。。
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
