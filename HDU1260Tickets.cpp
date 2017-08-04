/*
*****���͵ľ���dp����ֵ*****
dp[i]����˼�ǵ���i+1����ʱ����ȡ������Сֵ,�����±��0��ʼ
ÿ��λ�������־���һ�������˵�һ������˫�˵�

��һ������һ������N����ʾ��Ʊ�������
֮��ÿ������������������ݣ���һ�б�ʾ��������м�������Ʊ
�ڶ��б�ʾÿ��������Ʊ���õ�ʱ��
�����б�ʾÿ���ڵ�������֮����˫��Ʊ���õ�ʱ��
��������08:00:00am��ʼ��Ʊ����Ʊ�����ʱ��
*/
/*
Jesus, what a great movie! Thousands of people are rushing to the cinema. However, this is really a tuff time for Joe who sells the film tickets. He is wandering when could he go back home as early as possible.
A good approach, reducing the total time of tickets selling, is let adjacent people buy tickets together. As the restriction of the Ticket Seller Machine, Joe can sell a single ticket or two adjacent tickets at a time.
Since you are the great JESUS, you know exactly how much time needed for every person to buy a single ticket or two tickets for him/her. Could you so kind to tell poor Joe at what time could he go back home as early as possible? If so, I guess Joe would full of appreciation for your help.
Input
There are N(1<=N<=10) different scenarios, each scenario consists of 3 lines:
1) An integer K(1<=K<=2000) representing the total number of people;
2) K integer numbers(0s<=Si<=25s) representing the time consumed to buy a ticket for each person;
3) (K-1) integer numbers(0s<=Di<=50s) representing the time needed for two adjacent people to buy two tickets together.
Output
For every scenario, please tell Joe at what time could he go back home as early as possible. Every day Joe started his work at 08:00:00 am. The format of time is HH:MM:SS am|pm.
Sample Input
2
2
20 25
40
1
8
Sample Output
08:00:40 am
08:00:08 am
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//thanks to tl~

int dp[2002];//��main����������Կ�����ռ������
//dp[i]����˼�ǵ���i+1����ʱ����ȡ������Сֵ,�����±��0��ʼ

int main()
{
    int n,s,m,h,num,single[2002],dble[2002],i;
    //nΪ��ĳ���  s,m,h��¼���룬�֣�ʱ  num��¼����ÿ������Ʊ����
    //singel[i] ��i+1������Ʊ�����ѵ�ʱ��
    //dble[i] ��i���˺�ǰһ������˫��Ʊ�����ѵ�ʱ��
    cin >> n;
    while(n--)
    {
        memset(single,0,sizeof(single));
        memset(dble,0,sizeof(dble));
        memset(dp,0,sizeof(dp));
        cin >> num;
        for(i=0;i<num;i++)
            cin >> single[i];
        for(i=1;i<num;i++)
            cin >> dble[i];
        for(i=0;i<num;i++)
        {
            if(i==0)
                dp[i]=single[i];
            else if(i==1)
                dp[i]=min(dp[i-1]+single[i],dble[i]);
            else
                dp[i]=min(dp[i-1]+single[i],dp[i-2]+dble[i]);
        }
        int ans=dp[num-1];
        s=ans%60;
        m=(ans/60)%60;
        h=8+(ans/60)/60;
        if(h<12)
            printf("%02d:%02d:%02d am\n", h, m, s);
		else
			printf("%02d:%02d:%02d pm\n", h - 12, m, s);
    }
    return 0;
}
