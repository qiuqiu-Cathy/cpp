/*
输入一行数字，如果我们把这行数字中的‘5’都看成空格，那么就得到一行用空格分割的若干非负整数（可能有些整数以‘0’开头，这些头部的‘0’应该被忽略掉，除非这个整数就是由若干个‘0’组成的，这时这个整数就是0）。

你的任务是：对这些分割得到的整数，依从小到大的顺序排序输出。

Input
输入包含多组测试用例，每组输入数据只有一行数字（数字之间没有空格），这行数字的长度不大于1000。

输入数据保证：分割得到的非负整数不会大于100000000；输入数据不可能全由‘5’组成。
Output
对于每个测试用例，输出分割得到的整数排序的结果，相邻的两个整数之间用一个空格分开，每组输出占一行。
Sample Input
0051231232050775
Sample Output
0 77 12312320
*/
#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
int main()
{
    char s[1005];
    int num[1005];
    while(cin >> s)
    {
        memset(num,0,sizeof(num));
        int t=0;
        int len=strlen(s);
        int flag=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]!='5')
            {
                num[t]=num[t]*10+s[i]-'0';
                flag=1;
            }
            else if(flag==1)
            {
                t++;//当前是字符‘5’，需要下一个容器来存放数字
                flag=0;//排除多个5相连的情况
            }
            if(s[i]!='5'&&s[i+1]=='\0')
                t++;
        }
        sort(num,num+t);
        for(int i=0;i<t-1;i++)
            cout << num[i] << " ";
        cout << num[t-1] << endl;
    }
    return 0;
}
