//����ѵ�� 8/4 DP����仯ϵ��
//�����˳���ԭ����emmm���찡
/*
"OK, you are not too bad, em... But you can never pass the next test." feng5166 says.

"I will tell you an odd number N, and then N integers. There will be a special integer among them, you have to tell me which integer is the special one after I tell you all the integers." feng5166 says.

"But what is the characteristic of the special integer?" Ignatius asks.

"The integer will appear at least (N+1)/2 times. If you can't find the right integer, I will kill the Princess, and you will be my dinner, too. Hahahaha....." feng5166 says.

Can you find the special integer for Ignatius?
Input
The input contains several test cases. Each test case contains two lines. The first line consists of an odd integer N(1<=N<=999999) which indicate the number of the integers feng5166 will tell our hero. The second line contains the N integers. The input is terminated by the end of file.
Output
For each test case, you have to output only one line which contains the special number you have found.
Sample Input
5
1 3 2 3 3
11
1 1 1 1 1 5 5 5 5 5 5
7
1 1 1 1 1 1 1
Sample Output
3
5
1
*/
#include <cstdio>
#include <string.h>
using namespace std;
int main()
{
    int N, num[50000], ans,n;
    while(scanf("%d",&N) != EOF)
    {
        memset(num, 0, sizeof(num));
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&n);
            num[n]++;
            if(num[n] >= (N + 1) / 2)
                ans = n;
        }
        printf("%d\n",ans);
    }
    return 0;
}

