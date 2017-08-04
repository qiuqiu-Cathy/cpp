/*
*****典型的决策dp求最值*****
dp[i]的意思是到第i+1个人时可以取到的最小值,数组下标从0开始
每个位置有两种决策一种是买单人的一种是买双人的

第一行输入一个整数N，表示买票的情况数
之后每种情况都会有三行数据，第一行表示该种情况有几个人买票
第二行表示每个人买单人票所用的时间
第三行表示每相邻的两个人之间买双人票所用的时间
最后求出从08:00:00am开始买票能买到票的最短时间
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

int dp[2002];//在main函数外面可以开更大空间的数组
//dp[i]的意思是到第i+1个人时可以取到的最小值,数组下标从0开始

int main()
{
    int n,s,m,h,num,single[2002],dble[2002],i;
    //n为剧的场数  s,m,h记录的秒，分，时  num记录的是每场剧买票的人
    //singel[i] 第i+1个人买票所花费的时间
    //dble[i] 第i个人和前一个人买双人票所花费的时间
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
