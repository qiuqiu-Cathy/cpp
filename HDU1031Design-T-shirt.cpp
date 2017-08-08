/*
Soon after he decided to design a T-shirt for our Algorithm Board on Free-City BBS, XKA found that he was trapped by all kinds of suggestions from everyone on the board. It is indeed a mission-impossible to have everybody perfectly satisfied. So he took a poll to collect people's opinions. Here are what he obtained: N people voted for M design elements (such as the ACM-ICPC logo, big names in computer science, well-known graphs, etc.). Everyone assigned each element a number of satisfaction. However, XKA can only put K (<=M) elements into his design. He needs you to pick for him the K elements such that the total number of satisfaction is maximized.
Input
The input consists of multiple test cases. For each case, the first line contains three positive integers N, M and K where N is the number of people, M is the number of design elements, and K is the number of elements XKA will put into his design. Then N lines follow, each contains M numbers. The j-th number in the i-th line represents the i-th person's satisfaction on the j-th element.
Output
For each test case, print in one line the indices of the K elements you would suggest XKA to take into consideration so that the total number of satisfaction is maximized. If there are more than one solutions, you must output the one with minimal indices. The indices start from 1 and must be printed in non-increasing order. There must be exactly one space between two adjacent indices, and no extra space at the end of the line.
Sample Input
3 6 4
2 2.5 5 1 3 4
5 1 3.5 2 2 2
1 1 1 1 1 10
3 3 2
1 2 3
2 3 1
3 1 2
Sample Output
6 5 3 1
2 1
*/
#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
struct shirt
{
    int num;
    double mark;
    bool operator < (const shirt &rhs) const
    {
        return mark > rhs.mark ||(mark == rhs.mark &&num < rhs.num);   //利用重载运算符提速防止T
    }
}T[1000],temp;
/*bool cmp1(shirt x,shirt y)
{
    return x.mark > y.mark;
}
bool cmp2(shirt x,shirt y)
{
    return x.num <y.num;
}
*/
int main()
{
    int n,m,k;
    double mmark;
    while(scanf("%d%d%d",&n,&m,&k) == 3)
    {
        memset(T,0,sizeof(T));
        for(int i =0 ;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                double x;
                scanf("%lf",&x);
                T[j].mark += x;
                T[j].num = j+1;
            }
        }
        sort(T,T+m);
        vector<int>tar;
        for(int i=k-1;i>=0;i--)
        {
            tar.push_back(T[i].num);
        }
        sort(tar.begin(),tar.end());//将结构体中数据从小到大排列
        reverse(tar.begin(),tar.end());//将排序得出的递增序列变成从大到小排列
        for(int i = 0;i<k;i++)
        {
            if(i)
                cout <<" ";
            cout <<tar[i];
        }
        cout <<endl;
    }
    return 0;
}
