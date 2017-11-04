//MatricChain

#include <bits/stdc++.h>
using namespace std;
//thanks to tl~

int p[22];//n个矩阵A1，A2，…，An，的阶pi-1, pi, i=1, 2,...,n
int m[22][22]; //m[i][j] 表示Ai-Aj矩阵之间连乘最小的乘法次数
int s[22][22]; //m[i][j] 之间断开的最优位置s[i][j]

void MatrixChain(int * p, int n, int * * m,int * * s)
{
    for(int i = 1;i < n; i++)
        m[i][i] = 0;
    for(int r = 2;r <= n; r++)
        for(int i=1; i <= n-r+1; i++)
        {
            int j = i + r - 1;
            m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
            s[i][j]=i;//假设断开的最优位置是i
            for(int k=i+1;k<j;k++)
            {
                int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; //k作为断点比i更优
                if(t<m[i][j])
                {
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
        }
}

void Traceback(int i,int j,int **s,int flag) //打印出最优断点组成的表达式
{
    if(i==j)
        cout << "A" << i;  //如果i是断点则打印Ai
    else
    {
        flag++;
        if(flag!=1)
            cout <<"(";
        Traceback(i,s[i][j],s,flag);
        Traceback(s[i][j]+1,j,s,flag);
        if(flag!=1)
            cout << ")";
    }
}
int main()
{
    int T;
    int casenum;
    casenum=0;
    while(cin >> T)
    {
        casenum++;
        for(int i=0;i<=T;i++)
            cin >> p[i];
        int flag=0;

        int **m=new int*[22];
        for(int i=1;i<=T;i++)
            m[i]=new int[22];
        int **s=new int*[22];
        for(int i=1;i<=T;i++)
            s[i]=new int[22];

        MatrixChain(p,T,m,s);
        cout<<"Case "<<casenum<<endl;
        cout<<m[1][T]<<" ";
        Traceback(1,T,s,flag);
        cout<<endl;
    }
    return 0;
}



