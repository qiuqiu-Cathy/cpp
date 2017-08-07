/*
Excel���Զ�һ���¼������ָ���������������д����ʵ�����ƹ��ܡ�
Input
��������������ɲ���������ÿ�����������ĵ�1�а����������� N (<=100000) �� C������ N �Ǽ�¼��������C ��ָ��������кš������� N
�У�ÿ�а���һ��ѧ����¼��ÿ��ѧ����¼��ѧ�ţ�6λ���֣�ͬ�������û���ظ���ѧ�ţ���������������8λ�Ҳ������ո���ַ��������ɼ���������[0, 100]�ڵ���������ɣ�ÿ����Ŀ����1���ո������������ N=0 ʱ��ȫ�������������Ӧ�Ľ����Ҫ�����
Output
��ÿ�������������������1�С�Case i:�������� i �ǲ��������ı�ţ���1��ʼ��������� N ���������Ҫ�������Ľ���������� C=1 ʱ����ѧ�ŵ������򣻵� C=2ʱ���������ķǵݼ��ֵ������򣻵� C=3
ʱ�����ɼ��ķǵݼ����򡣵�����ѧ��������ͬ����������ͬ�ɼ�ʱ�������ǵ�ѧ�ŵ�������
Sample Input
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
0 0
Sample Output
Case 1:
000001 Zoe 60
000007 James 85
000010 Amy 90
Case 2:
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Case 3:
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
*/
#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
struct item
{
    int num;
    string name;
    int score;
} I[100005];
bool cmp1(item x,item y)
{
    return x.num<y.num;
}
bool cmp2(item x,item y)
{
    if(x.name==y.name)
        return x.num < y.num;
    else
        return x.name< y.name;
}
bool cmp3(item x,item y)
{
    if(x.score==y.score)
        return x.num < y.num;
    else
        return x.score < y.score;
}
int main()
{
    int N,C,casenum=0;
    while(cin >> N >> C)
    {
        if(N==0)
            break;
        else
        {
        casenum++;
        for(int i=0;i<N;i++)
            cin >> I[i].num >> I[i].name >> I[i].score;
        if(C==1)
            sort(I,I+N,cmp1);
        if(C==2)
            sort(I,I+N,cmp2);
        if(C==3)
            sort(I,I+N,cmp3);
        cout << "Case " << casenum << ":" << endl;
        for(int i=0;i<N;i++)
        {
            printf("%06d ",I[i].num);
            cout << I[i].name <<" " << I[i].score << endl;
        }
        }
    }
    return 0;
}
