/*
***��ķ���ģ�Nimm Game��****�������Ѹ����ɸ���Ʒ��������������ĳһ��ȡ��������Ʒ��
�涨ÿ������ȡһ�������߲��ޣ����ȡ���ߵ�ʤ��������ķ���ģ������������ؽ��ۣ�
�ã�a��b��c����ʾÿ��ʯ����Ŀ�����a^b^c==0��(^���ǰ�λ�������)�ͳ����־�����������ƣ���ô����һ���䡣��
e.g.
���һ��4����
��.һ��2����һ��2����������
����������ȡ��һ�ѣ�ȡ1������2��������Ϊ��ٻ��ķ�������ƣ���
�˾�����������ơ���ʱ2^3=(10)^(10)=(00)=0��

��Ŀ��

Here is a simple game. In this game, there are several piles of matches and two players. The two player play in turn. In each turn, one can choose a pile and take away arbitrary number of matches from the pile (Of course the number of matches, which is taken away, cannot be zero and cannot be larger than the number of matches in the chosen pile). If after a player��s turn, there is no match left, the player is the winner. Suppose that the two players are all very clear. Your job is to tell whether the player who plays first can win the game or not.
Input
The input consists of several lines, and in each line there is a test case. At the beginning of a line, there is an integer M (1 <= M <=20), which is the number of piles. Then comes M positive integers, which are not larger than 10000000. These M integers represent the number of matches in each pile.
Output
For each test case, output "Yes" in a single line, if the player who play first will win, otherwise output "No".
Sample Input
2 45 45
3 3 6 9
Sample Output
No
Yes
*/
#include <iostream>
using namespace std;
//thanks to tl~
int main()
{
    int M,ans;
    int num[20];
    while(cin >> M)
    {
        ans=0;
        for(int i=0;i<M;i++)
        {
            cin >> num[i];
            ans=ans^num[i];
        }
        if(ans==0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
