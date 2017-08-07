//递推求解
/*
有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。请编程计算蜜蜂从蜂房a爬到蜂房b的可能路线数。
其中，蜂房的结构如下所示。

Input
输入数据的第一行是一个整数N,表示测试实例的个数，然后是N 行数据，每行包含两个整数a和b(0<a<b<50)。
Output
对于每个测试实例，请输出蜜蜂从蜂房a爬到蜂房b的可能路线数，每个实例的输出占一行。
Sample Input
2
1 2
3 6
Sample Output
1
3
*/
//1->2 1种
//1->3 2种
//1->4 3种
//1->5 5种
//类似斐波那契的一种递推关系。F(n)=F(n-1)+F(n-2)
#include <iostream>
using namespace std;
//thanks to tl~
long long F(int a,int b)
{
    int n=b-a;
    long long f[53];
    f[1]=1;
    f[2]=2;
    if(n>2)
    {
        for(int i=3;i<=n;i++)
            f[i]=f[i-2]+f[i-1];
    }
    return f[n];
}
int main()
{
    int a,b,N;
    cin >> N;
    while(N--)
    {
        cin >> a >> b;
        cout << F(a,b) << endl;
    }
    return 0;
}
