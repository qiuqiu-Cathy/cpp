/*
We all know a+b=c,but now there is a new rule in equations:
if a>b,then it's equal to [>c];
if a=b,then it's equal to [=c];
if a<b,then it's equal to [<c];
a sample:

1+1=[=2]
2+0=[>2]
0+2=[<2]
1+2=[<3]

and [>c] > [=c] > [<c].
For every [n],
[n+1] > [n] >[n-1].
Input
The input consists of T cases.The first line of the input contains only positive integer T (0<T<=100).Then follows the cases.Each case begins with a line containing exactly one integer N (0<N<=10000).Then there are N lines, each with two integers a and b (0<a,b<2^31-1).
Output
For each case, calculate each value of a+b(as a+b=[?]) and output a+b=[?] in descending order sorted by [?]. If there exists some pair of a,b whose order can not be determined by the rules above, output them with the order of the input. A blank line should be printed after each case.
Sample Input
2
5
1 5
5 1
3 3
4 5
5 6
5
1 6
6 1
2 4
4 2
3 3
Sample Output
5+6=[<11]
4+5=[<9]
5+1=[>6]
3+3=[=6]
1+5=[<6]

6+1=[>7]
1+6=[<7]
4+2=[>6]
3+3=[=6]
2+4=[<6]
*/
#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
struct fomular
{
    long long a,b,c;
    int level;
}f[10005];

bool cmp(fomular x,fomular y)
{
    if((x.c>y.c)||(x.c==y.c&&x.level>y.level))
        return true;
    return false;
}
int main()
{
    long long T,N;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%lld%lld",&f[i].a,&f[i].b);
            f[i].c=f[i].a+f[i].b;
            if(f[i].a>f[i].b)
                f[i].level=3;
            else if(f[i].a==f[i].b)
                f[i].level=2;
            else
                f[i].level=1;
        }
        stable_sort(f,f+N,cmp);//带有stable的函数可保证相等元素的原本相对次序在排序后保持不变。
        for(int i=0;i<N;i++)
        {
             if(f[i].level==3)
                printf("%lld+%lld=[>%lld]\n",f[i].a,f[i].b,f[i].c);
            if(f[i].level==2)
                printf("%lld+%lld=[=%lld]\n",f[i].a,f[i].b,f[i].c);
            if(f[i].level==1)
                printf("%lld+%lld=[<%lld]\n",f[i].a,f[i].b,f[i].c);
        }
        cout << endl;
    }
    return 0;
}
