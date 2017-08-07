//�������
/*
��һֻ����ѵ�����۷�ֻ�������Ҳ����ڵķ䷿�����ܷ������С����̼����۷�ӷ䷿a�����䷿b�Ŀ���·������
���У��䷿�Ľṹ������ʾ��

Input
�������ݵĵ�һ����һ������N,��ʾ����ʵ���ĸ�����Ȼ����N �����ݣ�ÿ�а�����������a��b(0<a<b<50)��
Output
����ÿ������ʵ����������۷�ӷ䷿a�����䷿b�Ŀ���·������ÿ��ʵ�������ռһ�С�
Sample Input
2
1 2
3 6
Sample Output
1
3
*/
//1->2 1��
//1->3 2��
//1->4 3��
//1->5 5��
//����쳲�������һ�ֵ��ƹ�ϵ��F(n)=F(n-1)+F(n-2)
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
